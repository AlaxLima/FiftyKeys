#include <HID-Project.h>
#include <HID-Settings.h>

#include "KeyLookupSwitch.h"


const uint8_t KEY_FUNCTION = 255; // Custom FN key to be used for other purposes, max value of uint8_t is 255

uint8_t layer = 0; // For global FN key, overwrite capability


const uint8_t layerCount = 2;
const uint8_t rowCount = 9;
const uint8_t columnCount = 6;

const uint8_t KeyMap[layerCount][rowCount][columnCount] = {
  {
    {KEY_ESC, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T},
    {KEY_TAB, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G},
    {KEY_LEFT_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B},
    {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_RESERVED, KEY_RIGHT_ALT, KEY_LEFT_ARROW, KEY_SPACE},
    {KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_RESERVED},
    {KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_QUOTE},
    {KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, KEY_RESERVED},
    {KEY_DELETE, KEY_RESERVED, KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_DOWN_ARROW, KEY_UP_ARROW},
    {KEY_ENTER, MEDIA_PLAY_PAUSE, KEY_BACKSPACE, KEY_BACKSLASH, KEY_RIGHT_ARROW, KEY_FUNCTION}
  },
  {
    {KEY_TILDE, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5},
    {KEY_CAPS_LOCK, KEY_F1, KEY_F3, KEY_F5, KEY_F7, KEY_F9},
    {KEY_LEFT_SHIFT, KEY_F2, KEY_F4, KEY_F6, KEY_F8, KEY_F10},
    {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_RESERVED, KEY_RIGHT_ALT, MEDIA_PREVIOUS, MEDIA_VOLUME_MUTE},
    {KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_RESERVED},
    {KEY_F11, KEY_RESERVED, KEY_RESERVED, KEY_RESERVED, KEY_RESERVED, KEY_RESERVED},
    {KEY_F12, KEY_RESERVED, CONSUMER_BRIGHTNESS_DOWN, CONSUMER_BRIGHTNESS_UP, KEY_INSERT, KEY_RESERVED},
    {KEY_DELETE, KEY_RESERVED, KEY_MINUS, KEY_EQUAL, MEDIA_VOLUME_DOWN, MEDIA_VOLUME_UP},
    {KEY_ENTER, MEDIA_VOLUME_MUTE, KEY_RESERVED, KEY_RESERVED, MEDIA_NEXT, KEY_FUNCTION}
  }
};

bool keyStates[rowCount][columnCount] = {false}; // Row-major key state matrix


// -- Macros for Direct Port Control --
#define SetLow(reg, bit) (*(reg) &= ~(1 << (bit)))
#define SetHigh(reg, bit) (*(reg) |= (1 << (bit)))

// One inline macro
// Active-low because INPUT_PULLUP
#define PullupRead(idx) (!(*(colPortRegs[idx]) & _BV(colBits[idx])))

// Keyboard pinout
// Direct port:       C6 D4 D1 D0 D7 E6 B5 B4 B1
uint8_t rowPins[9] = {5, 4, 2, 3, 6, 7, 9, 8, 14};
uint8_t colPins[6] = {A0, A1, A2, 10, 15, 16};

// Row pin port pointers
volatile uint8_t *const rowPortRegs[9] = {
    &PORTC, &PORTD, &PORTD, &PORTD, &PORTD, &PORTE, &PORTB, &PORTB, &PORTB};
const uint8_t rowBits[9] = {6, 4, 1, 0, 7, 6, 5, 4, 3};

volatile uint8_t *const colPortRegs[6] = {
    &PINF, &PINF, &PINF, &PINB, &PINB, &PINB};
const uint8_t colBits[6] = {7, 6, 5, 6, 1, 2};

// TimerInterrupt initalize
void setupTimer1()
{
    cli(); // Disable interrupts
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B |= (1 << WGM12);              // CTC mode
    TCCR1B |= (1 << CS11) | (1 << CS10); // Prescaler 64
    OCR1A = 499;                         // (16MHz / 64 / Hz) - 1
    TIMSK1 |= (1 << OCIE1A);             // Enable compare interrupt
    sei();                               // Enable interrupts
}

void setup()
{
    // Initialize the timer1 module
    setupTimer1();

    Serial.begin(9600);

    // Rows initialization
    for (int r = 0; r < 9; r++)
    {
        pinMode(rowPins[r], OUTPUT);
        digitalWrite(rowPins[r], HIGH);
    }

    // Columns initialization
    for (int c = 0; c < 6; c++)
    {
        pinMode(colPins[c], INPUT_PULLUP);
    }
    Consumer.begin();
}

void coordinateDiagnostics(bool keyState, uint8_t outputRow, uint8_t outputCol, uint8_t outputKeycode)
{
    switch (keyState)
    {
    case 1:
        Serial.println("");
        Serial.println("[PRESSING]");
        Serial.print("Row ");
        Serial.print(outputRow);
        Serial.print(" column ");
        Serial.print(outputCol);
        Serial.print(" - Keycode ");
        Serial.println(outputKeycode);
        break;
    case 0:
        Serial.println("");
        Serial.println("[RELEASING]");
        Serial.print("Row ");
        Serial.print(outputRow);
        Serial.print(" column ");
        Serial.print(outputCol);
        Serial.print(" - Keycode ");
        Serial.println(outputKeycode);
        break;
    }
}

uint8_t layerSwitch(uint8_t keycode)
{
    switch (keycode)
    {
    case 255:
        return 2;
        break;
    default:
        return 1;
        break;
    }
}

void readingRows(uint8_t row) {
  for (int col = 0; col < columnCount; col++) {
    bool colRead = PullupRead(col); // active low
    uint8_t key = KeyMap[layer][row][col];

    if (key == KEY_RESERVED) continue;

    if (colRead && !keyStates[row][col]) {
      keyStates[row][col] = true;

      if (key == KEY_FUNCTION) {
        layer = 1;
        Keyboard.releaseAll();
      } else {
        keyTypeLookup(1, key);
      }
      coordinateDiagnostics(keyStates[row][col], row, col, key);
    } else if (!colRead && keyStates[row][col]) {
      keyStates[row][col] = false;

      if (key == KEY_FUNCTION) {
        layer = 0;
        Keyboard.releaseAll();
      } else {
        keyTypeLookup(0, key);
      }
      coordinateDiagnostics(keyStates[row][col], row, col, key);
    }
  }
}

// Column reading
void chosenReadingRow(uint8_t activeRow)
{
    readingRows(activeRow);
}

inline void driveRow(uint8_t activeRow)
{
    for (uint8_t r = 0; r < 9; r++)
    {
        if (r == activeRow)
            SetLow(rowPortRegs[r], rowBits[r]); // selected row LOW
        else
            SetHigh(rowPortRegs[r], rowBits[r]); // others HIGH
    }
}

ISR(TIMER1_COMPA_vect)
{
    static uint8_t row = 0;
    driveRow(row);
    readingRows(row);
    row = (row + 1) % 9;
}

/* ─── RESERVED VOID LOOP, TESTING ONLY ───  */
void loop()
{
}

/* ─── STORAGE AND MEMORY TRACKING ─── */
// update 1     (built a repetitive structure)      : 5142B     space, 246B mem
// update 2     (w/ direct port macros)             : 5392B     space, 273B mem
// update 3     (added ISR timer1 scan loop)        : 6112B     space, 313B mem
// update 4     (done scan, column switch)          : 7352B     space, 363B mem
// update 4.1   (Keymap swapped char* w/ uint8_t)   : 7192B     space, 407B mem
// update 5     (L1 finished, .h lookup file)       : 11960B    space, 495B mem
// Update 5.1   (Keymap on 3D array)                : 12054B    space, 550B mem
