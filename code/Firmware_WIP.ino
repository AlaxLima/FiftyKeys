#include <HID-Project.h>
#include <HID-Settings.h>

#include "KeyLookupSwitch.h"
// #include "BoardConf.h"

/*
// 2 parallel arrays in flash
#define ENTRY(name, code) const char name##_str[] PROGMEM = #name;
KEY_LIST
#undef ENTRY

struct KeyPair { const char* str; uint8_t code; };

#define ENTRY(name, code) { name##_str, code },
const KeyPair keyTable[] PROGMEM = {
  KEY_LIST
};
#undef ENTRY


// Runtime string converter
const uint8_t keyCount = sizeof(keyTable) / sizeof(keyTable[0]);

uint8_t resolveKey(const char* alias) {
  for (uint8_t i = 0; i < keyCount; i++) {
    const char* p = (const char*)pgm_read_ptr(&keyTable[i].str);
    if (strcmp_P(alias, p) == 0) {
      return pgm_read_byte(&keyTable[i].code);
    }
  }
  return 0;                // fall-back “no key”
}
*/

// #define NO_KEY 0x00 // KEY_RESERVED is a predefined option instead of this
const uint8_t KEY_FUNCTION = 255; // Custom FN key to be used for other purposes, max value of uint8_t is 255
const uint8_t KEY_REMAPPED_LEFT_ALT = 50;

const uint8_t MACRO_01 = 235;
const uint8_t MACRO_02 = 236;
const uint8_t MACRO_03 = 237;
const uint8_t MACRO_04 = 238;
const uint8_t MACRO_05 = 239;
const uint8_t MACRO_06 = 240;
const uint8_t MACRO_07 = 241;
const uint8_t MACRO_08 = 242;
const uint8_t MACRO_09 = 243;
const uint8_t MACRO_10 = 244;

const uint8_t layerCount = 2;
const uint8_t rowCount = 9;
const uint8_t columnCount = 6;

bool keyStates[rowCount][columnCount] = {false}; // Row-major key state matrix

const uint8_t KeyMap[layerCount][rowCount][columnCount] = {
    {{KEY_ESC, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T},
     {KEY_TAB, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G},
     {KEY_LEFT_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B},
     {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_RESERVED, KEY_REMAPPED_LEFT_ALT, KEY_LEFT_ARROW, KEY_SPACE},
     {KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_RESERVED},
     {KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_QUOTE},
     {KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, KEY_RESERVED},
     {KEY_BACKSLASH, KEY_RESERVED, KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_DOWN_ARROW, KEY_UP_ARROW},
     {KEY_ENTER, MEDIA_PLAY_PAUSE, KEY_BACKSPACE, KEY_DELETE, KEY_RIGHT_ARROW, KEY_FUNCTION}},
    {{KEY_TILDE, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5},
     {KEY_CAPS_LOCK, KEY_F1, KEY_F3, KEY_F5, KEY_F7, KEY_F9},
     {KEY_LEFT_SHIFT, KEY_F2, KEY_F4, KEY_F6, KEY_F8, KEY_F10},
     {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_RESERVED, KEY_RIGHT_ALT, MEDIA_PREVIOUS, MEDIA_VOLUME_MUTE},
     {KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_RESERVED},
     {KEY_F11, KEY_RESERVED, KEY_RESERVED, MACRO_03, MACRO_05, MACRO_06},
     {KEY_F12, MACRO_02, CONSUMER_BRIGHTNESS_DOWN, CONSUMER_BRIGHTNESS_UP, KEY_INSERT, KEY_RESERVED},
     {KEY_DELETE, KEY_RESERVED, KEY_MINUS, KEY_EQUAL, MEDIA_VOLUME_DOWN, MEDIA_VOLUME_UP},
     {KEY_ENTER, MEDIA_VOLUME_MUTE, KEY_RESERVED, MACRO_04, MEDIA_NEXT, KEY_FUNCTION}}};

/*
const uint8_t L1KeyMapRow0[6] = {KEY_ESC, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T};
const uint8_t L1KeyMapRow1[6] = {KEY_TAB, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G};
const uint8_t L1KeyMapRow2[6] = {KEY_LEFT_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B};
const uint8_t L1KeyMapRow3[6] = {KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_RESERVED, KEY_RIGHT_ALT, KEY_LEFT_ARROW, KEY_SPACE};
const uint8_t L1KeyMapRow4[6] = {KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_RESERVED};
const uint8_t L1KeyMapRow5[6] = {KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_QUOTE};
const uint8_t L1KeyMapRow6[6] = {KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, KEY_RESERVED};
const uint8_t L1KeyMapRow7[6] = {KEY_DELETE, KEY_RESERVED, KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_DOWN_ARROW, KEY_UP_ARROW};
const uint8_t L1KeyMapRow8[6] = {KEY_ENTER, MEDIA_PLAY_PAUSE, KEY_BACKSPACE, KEY_BACKSLASH, KEY_RIGHT_ARROW, KEY_FUNCTION};

const uint8_t *L1KeyMap[9] = {
    L1KeyMapRow0,
    L1KeyMapRow1,
    L1KeyMapRow2,
    L1KeyMapRow3,
    L1KeyMapRow4,
    L1KeyMapRow5,
    L1KeyMapRow6,
    L1KeyMapRow7,
    L1KeyMapRow8,
};
*/

uint8_t layer = 0; // For global FN key, overwrite capability
bool activeFlag = 1;

// -- Macros for Direct Port Control --

// Predessor macros that did not worked with the arrays
// #define DirectHIGH(port, pin) (PORT##port |= (1 << pin))
// #define DirectLOW(port, pin) ((PORT##port) &= ~(1 << (pin)))

// This is more likely preferred
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
void initialTimer1()
{
    cli(); // Disable interrupts
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B |= (1 << WGM12);              // CTC mode
    TCCR1B |= (1 << CS11) | (1 << CS10); // Prescaler 64
    OCR1A = 999;                         // (16MHz / 64 / Hz) - 1
    TIMSK1 |= (1 << OCIE1A);             // Enable compare interrupt

    // !!!! DO NOT DELETE OR BOARD WILL CORRUPT !!!!
    sei(); // Enable interrupts
}

void setup()
{
    // Initialize ISR modules
    initialTimer1();

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
        // digitalWrite(colPins[c], HIGH); //No need for conventional pinMode declaration
    }
    // Keyboard.begin();
    Consumer.begin();
    // currentLayer = 1;
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
/*
void readingRow0()
{
    for (int c = 0; c < 6; c++)
    {
        bool colRead = PullupRead(c); // = 1 when pressed
        // const char *alias = L1KeyMapRow1[c];
        // uint8_t code = resolveKey(alias);

        if (colRead && !keyStates[0][c]) // was not pressed before
        {
            keyStates[0][c] = true;
            keyTypeLookup(1, L1KeyMap[0][c]);
            coordinateDiagnostics(keyStates[0][c], 0, c, L1KeyMap[0][c]);
        }
        else if (!colRead && keyStates[0][c]) // was pressed, now released
        {
            keyTypeLookup(0, L1KeyMap[0][c]);
            keyStates[0][c] = false;
            coordinateDiagnostics(keyStates[0][c], 0, c, L1KeyMap[0][c]);
        }
    }
}
*/

/*
void readingRows(uint8_t row) // First try
{
    for (int c = 0; c < 6; c++)
    {
        bool colRead = PullupRead(c); // = 1 when pressed
        // const char *alias = L1KeyMapRow1[c];
        // uint8_t code = resolveKey(alias);

        if (colRead && !keyStates[row][c]) // was not pressed before
        {
            keyStates[row][c] = true;
            keyTypeLookup(1, L1KeyMap[row][c]);
            coordinateDiagnostics(keyStates[row][c], 0, c, L1KeyMap[row][c]);
        }
        else if (!colRead && keyStates[row][c]) // was pressed, now released
        {
            keyTypeLookup(0, L1KeyMap[row][c]);
            coordinateDiagnostics(keyStates[row][c], 1, c, L1KeyMap[row][c]);
            break;
            keyStates[row][c] = false;
        }
    }
}
*/

void readingRows(uint8_t row)
{
    for (int col = 0; col < columnCount; col++)
    {
        bool colRead = PullupRead(col); // active low
        uint8_t key = KeyMap[layer][row][col];

        if (key == KEY_RESERVED)
            continue;

        if (colRead && !keyStates[row][col])
        {
            keyStates[row][col] = true;
            activeFlag = 1;

            if (key == KEY_FUNCTION)
            {
                layer = 1;
                Keyboard.releaseAll();
            }
            else if (isMacroKeycode(key))
            {
                MacroRun(key);
            }
            else
            {
                keyTypeLookup(1, key);
            }
            // coordinateDiagnostics(keyStates[row][col], row, col, key);
        }
        else if (!colRead && keyStates[row][col])
        {
            keyStates[row][col] = false;
            activeFlag = 0;

            if (key == KEY_FUNCTION)
            {
                layer = 0;
                Keyboard.releaseAll();
            }
            else if (!isMacroKeycode(key)) // Don't "release" macro
            {
                keyTypeLookup(0, key);
            }
            // coordinateDiagnostics(keyStates[row][col], row, col, key);
        }
    }
}

// Column reading
void chosenReadingRow(uint8_t activeRow)
{
    /*
    switch (activeRow)
    {
    case 0:
        readingRows(0);
        break;
    case 1:
        readingRows(1);
        break;
    case 2:
        readingRows(2);
        break;
    case 3:
        readingRows(3);
        break;
    case 4:
        readingRows(4);
        break;
    case 5:
        readingRows(5);
        break;
    case 6:
        readingRows(6);
        break;
    case 7:
        readingRows(7);
        break;
    case 8:
        readingRows(activeRow);
        break;
    }
    */
    readingRows(activeRow);

    /*

    for (int c = 0; c < 6; c++)
    {
        bool colRead = PullupRead(c); // true = key is pressed

        // const char *alias = L1KeyMapRow1[c];
        // uint8_t code = resolveKey(alias);

        if (colRead && !keyStates[0][c]) // was not pressed before
        {
            //Keyboard.press(code); // replace with your key map later
            keyStates[activeRow][c] = true;
            keyborePress(L1KeyMap[activeRow][c]);
            Serial.print("Pressed row ");
            Serial.print(activeRow);
            Serial.print(" column ");
            Serial.println(c);
        }
        else if (!colRead && keyStates[0][c]) // was pressed, now released
        {
            keyboreRelease(L1KeyMap[activeRow][c]);
            keyStates[activeRow][c] = false;
            Serial.print("Released row ");
            Serial.print(activeRow);
            Serial.print(" column ");
            Serial.println(c);
            Serial.print("Key code is ");
            Serial.println(L1KeyMap[activeRow][c]);
        }
    }
    */
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
    driveRow(row); // set the lines
    // chosenReadingRow(row); // read ONLY ONCE
    readingRows(row);
    row = (row + 1) % 9; // next row next tick
}

/* ─── VOID LOOP USED FOR IDLING COUNT ─── */
void adjustTimer1(int status, uint16_t OCR1A_tickrate)
{
    switch (status)
    {
    case -1:
        cli(); // Disable interrupts
        TCCR1B |= (1 << CS11) | (1 << CS10);
        TIMSK1 |= (1 << OCIE1A);
        OCR1A = OCR1A_tickrate;
        sei(); // Enable interrupts
        break;
    case 1:
        cli();
        OCR1A = OCR1A_tickrate;
        TCCR1B &= ~(1 << CS10); // Clear CS10
        TCCR1B &= ~(1 << CS11); // Clear CS11
        TCCR1B &= ~(1 << CS12); // Clear CS12
        TIMSK1 &= ~(1 << OCIE1A);
        sei();
        break;
    case 0:
        cli();
        OCR1A = OCR1A_tickrate;
        sei();
        break;
    }

    /*
    Adjustments:
    - Shutdown:     1 + 62499
    - Startup:      -1 + ACTIVE mode value
    - Change:       0 + IDLE mode value
    */
}

const uint16_t SLEEP_TIMEOUT = 100;

uint8_t ACTIVE_RATE = 499;
uint8_t SLEEP_RATE = 62499; // No need anyway

bool sleepLock = 0;
bool openAllRows = 0;

void loop()
{
    while (!sleepLock)
    {
        for (uint16_t t = 0; t < SLEEP_TIMEOUT + 1; t++)
        {
            if (activeFlag)
            {
                // Serial.println("Hewoo :3");
                // adjustTimer1(0, ACTIVE_RATE);
                break;
            }
            switch (t)
            {
            case SLEEP_TIMEOUT:
                adjustTimer1(1, SLEEP_RATE);
                Serial.println("--zzz--zzz-");
                sleepLock = 1;
                openAllRows = 1;
            default:
                break;
            }
            // Serial.println();
            delay(100);
        }
    }
    while (sleepLock)
    {
        if (openAllRows)
        {
            for (uint8_t r = 0; r < rowCount; r++)
            {
                SetLow(rowPortRegs[r], rowBits[r]);
            }
            openAllRows = 0;
        }
        uint8_t sumCol = PullupRead(0) + PullupRead(1) + PullupRead(2) + PullupRead(3) + PullupRead(4) + PullupRead(5);
        if (sumCol > 0)
        {
            adjustTimer1(-1, ACTIVE_RATE);
            Serial.println("Good meowning~ nya~ :3");
            activeFlag = 1;
            sleepLock = 0; // Wake the board up
            break;
        }
        delay(50);
    }
}

/* ─── STORAGE AND MEMORY TRACKING ─── */
// update 1     (built a repetitive structure)      : 5142B     space, 246B mem
// update 2     (w/ direct port macros)             : 5392B     space, 273B mem
// update 3     (added ISR timer1 scan loop)        : 6112B     space, 313B mem
// update 4     (done scan, column switch)          : 7352B     space, 363B mem
// update 6     (Keymap swapped char* w/ uint8_t)   : 7192B     space, 407B mem
// update 7     (L1 finished, .h lookup file)       : 11960B    space, 495B mem
// Update 8     (Keymap on 3D array)                : 12054B    space, 550B mem
// Update 9     (Final polishing)
