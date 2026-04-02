#pragma once
#pragma message "Keybore is our new Keyboard!"

#include <Arduino.h>
#include <HID-Project.h>
#include <HID-Settings.h>

// -- KEYPRESSES GOES HERE --
inline void keyborePress(uint8_t keycode)
{
    switch (keycode)
    {
    case 0:
        Keyboard.press(KEY_RESERVED);
        break;
    case 1:
        Keyboard.press(KEY_ERROR_ROLLOVER);
        break;
    case 2:
        Keyboard.press(KEY_POST_FAIL);
        break;
    case 3:
        Keyboard.press(KEY_ERROR_UNDEFINED);
        break;
    case 4:
        Keyboard.press(KEY_A);
        break;
    case 5:
        Keyboard.press(KEY_B);
        break;
    case 6:
        Keyboard.press(KEY_C);
        break;
    case 7:
        Keyboard.press(KEY_D);
        break;
    case 8:
        Keyboard.press(KEY_E);
        break;
    case 9:
        Keyboard.press(KEY_F);
        break;
    case 10:
        Keyboard.press(KEY_G);
        break;
    case 11:
        Keyboard.press(KEY_H);
        break;
    case 12:
        Keyboard.press(KEY_I);
        break;
    case 13:
        Keyboard.press(KEY_J);
        break;
    case 14:
        Keyboard.press(KEY_K);
        break;
    case 15:
        Keyboard.press(KEY_L);
        break;
    case 16:
        Keyboard.press(KEY_M);
        break;
    case 17:
        Keyboard.press(KEY_N);
        break;
    case 18:
        Keyboard.press(KEY_O);
        break;
    case 19:
        Keyboard.press(KEY_P);
        break;
    case 20:
        Keyboard.press(KEY_Q);
        break;
    case 21:
        Keyboard.press(KEY_R);
        break;
    case 22:
        Keyboard.press(KEY_S);
        break;
    case 23:
        Keyboard.press(KEY_T);
        break;
    case 24:
        Keyboard.press(KEY_U);
        break;
    case 25:
        Keyboard.press(KEY_V);
        break;
    case 26:
        Keyboard.press(KEY_W);
        break;
    case 27:
        Keyboard.press(KEY_X);
        break;
    case 28:
        Keyboard.press(KEY_Y);
        break;
    case 29:
        Keyboard.press(KEY_Z);
        break;
    case 30:
        Keyboard.press(KEY_1);
        break;
    case 31:
        Keyboard.press(KEY_2);
        break;
    case 32:
        Keyboard.press(KEY_3);
        break;
    case 33:
        Keyboard.press(KEY_4);
        break;
    case 34:
        Keyboard.press(KEY_5);
        break;
    case 35:
        Keyboard.press(KEY_6);
        break;
    case 36:
        Keyboard.press(KEY_7);
        break;
    case 37:
        Keyboard.press(KEY_8);
        break;
    case 38:
        Keyboard.press(KEY_9);
        break;
    case 39:
        Keyboard.press(KEY_0);
        break;
    case 40:
        Keyboard.press(KEY_ENTER);
        break;
    case 41:
        Keyboard.press(KEY_ESC);
        break;
    case 42:
        Keyboard.press(KEY_BACKSPACE);
        break;
    case 43:
        Keyboard.press(KEY_TAB);
        break;
    case 44:
        Keyboard.press(KEY_SPACE);
        break;
    case 45:
        Keyboard.press(KEY_MINUS);
        break;
    case 46:
        Keyboard.press(KEY_EQUAL);
        break;
    case 47:
        Keyboard.press(KEY_LEFT_BRACE);
        break;
    case 48:
        Keyboard.press(KEY_RIGHT_BRACE);
        break;
    case 49:
        Keyboard.press(KEY_BACKSLASH);
        break;
    // Special case for LEFT ALT key interfering with code for Consumer MUTE
    case 50:
        Keyboard.press(KEY_LEFT_ALT);
        break;
    case 51:
        Keyboard.press(KEY_SEMICOLON);
        break;
    case 52:
        Keyboard.press(KEY_QUOTE);
        break;
    case 53:
        Keyboard.press(KEY_TILDE);
        break;
    case 54:
        Keyboard.press(KEY_COMMA);
        break;
    case 55:
        Keyboard.press(KEY_PERIOD);
        break;
    case 56:
        Keyboard.press(KEY_SLASH);
        break;
    case 57:
        Keyboard.press(KEY_CAPS_LOCK);
        break;
    case 58:
        Keyboard.press(KEY_F1);
        break;
    case 59:
        Keyboard.press(KEY_F2);
        break;
    case 60:
        Keyboard.press(KEY_F3);
        break;
    case 61:
        Keyboard.press(KEY_F4);
        break;
    case 62:
        Keyboard.press(KEY_F5);
        break;
    case 63:
        Keyboard.press(KEY_F6);
        break;
    case 64:
        Keyboard.press(KEY_F7);
        break;
    case 65:
        Keyboard.press(KEY_F8);
        break;
    case 66:
        Keyboard.press(KEY_F9);
        break;
    case 67:
        Keyboard.press(KEY_F10);
        break;
    case 68:
        Keyboard.press(KEY_F11);
        break;
    case 69:
        Keyboard.press(KEY_F12);
        break;
    case 70:
        Keyboard.press(KEY_PRINTSCREEN);
        break;
    case 71:
        Keyboard.press(KEY_SCROLL_LOCK);
        break;
    case 72:
        Keyboard.press(KEY_PAUSE);
        break;
    case 73:
        Keyboard.press(KEY_INSERT);
        break;
    case 74:
        Keyboard.press(KEY_HOME);
        break;
    case 75:
        Keyboard.press(KEY_PAGE_UP);
        break;
    case 76:
        Keyboard.press(KEY_DELETE);
        break;
    case 77:
        Keyboard.press(KEY_END);
        break;
    case 78:
        Keyboard.press(KEY_PAGE_DOWN);
        break;
    case 79:
        Keyboard.press(KEY_RIGHT_ARROW);
        break;
    case 80:
        Keyboard.press(KEY_LEFT_ARROW);
        break;
    case 81:
        Keyboard.press(KEY_DOWN_ARROW);
        break;
    case 82:
        Keyboard.press(KEY_UP_ARROW);
        break;
    case 83:
        Keyboard.press(KEY_NUM_LOCK);
        break;
    case 84:
        Keyboard.press(KEYPAD_DIVIDE);
        break;
    case 85:
        Keyboard.press(KEYPAD_MULTIPLY);
        break;
    case 86:
        Keyboard.press(KEYPAD_SUBTRACT);
        break;
    case 87:
        Keyboard.press(KEYPAD_ADD);
        break;
    case 88:
        Keyboard.press(KEYPAD_ENTER);
        break;
    case 89:
        Keyboard.press(KEYPAD_1);
        break;
    case 90:
        Keyboard.press(KEYPAD_2);
        break;
    case 91:
        Keyboard.press(KEYPAD_3);
        break;
    case 92:
        Keyboard.press(KEYPAD_4);
        break;
    case 93:
        Keyboard.press(KEYPAD_5);
        break;
    case 94:
        Keyboard.press(KEYPAD_6);
        break;
    case 95:
        Keyboard.press(KEYPAD_7);
        break;
    case 96:
        Keyboard.press(KEYPAD_8);
        break;
    case 97:
        Keyboard.press(KEYPAD_9);
        break;
    case 98:
        Keyboard.press(KEYPAD_0);
        break;
    case 99:
        Keyboard.press(KEYPAD_DOT);
        break;
    case 100:
        Keyboard.press(KEY_NON_US);
        break;
    case 101:
        Keyboard.press(KEY_APPLICATION);
        break;
    case 102:
        Keyboard.press(KEY_POWER);
        break;
    case 103:
        Keyboard.press(KEY_PAD_EQUALS);
        break;
    case 104:
        Keyboard.press(KEY_F13);
        break;
    case 105:
        Keyboard.press(KEY_F14);
        break;
    case 106:
        Keyboard.press(KEY_F15);
        break;
    case 107:
        Keyboard.press(KEY_F16);
        break;
    case 108:
        Keyboard.press(KEY_F17);
        break;
    case 109:
        Keyboard.press(KEY_F18);
        break;
    case 110:
        Keyboard.press(KEY_F19);
        break;
    case 111:
        Keyboard.press(KEY_F20);
        break;
    case 112:
        Keyboard.press(KEY_F21);
        break;
    case 113:
        Keyboard.press(KEY_F22);
        break;
    case 114:
        Keyboard.press(KEY_F23);
        break;
    case 115:
        Keyboard.press(KEY_F24);
        break;
    case 116:
        Keyboard.press(KEY_EXECUTE);
        break;
    case 117:
        Keyboard.press(KEY_HELP);
        break;
    case 118:
        Keyboard.press(KEY_MENU2);
        break;
    case 119:
        Keyboard.press(KEY_SELECT);
        break;
    case 120:
        Keyboard.press(KEY_STOP);
        break;
    case 121:
        Keyboard.press(KEY_AGAIN);
        break;
    case 122:
        Keyboard.press(KEY_UNDO);
        break;
    case 123:
        Keyboard.press(KEY_CUT);
        break;
    case 124:
        Keyboard.press(KEY_COPY);
        break;
    case 125:
        Keyboard.press(KEY_PASTE);
        break;
    case 126:
        Keyboard.press(KEY_FIND);
        break;
    case 127:
        Keyboard.press(KEY_VOLUME_MUTE);
        break;
    case 128:
        Keyboard.press(KEY_VOLUME_UP);
        break;
    case 129:
        Keyboard.press(KEY_VOLUME_DOWN);
        break;
    case 130:
        Keyboard.press(KEY_LOCKING_CAPS_LOCK);
        break;
    case 131:
        Keyboard.press(KEY_LOCKING_NUM_LOCK);
        break;
    case 132:
        Keyboard.press(KEY_LOCKING_SCROLL_LOCK);
        break;
    case 133:
        Keyboard.press(KEYPAD_COMMA);
        break;
    case 134:
        Keyboard.press(KEYPAD_EQUAL_SIGN);
        break;
    case 135:
        Keyboard.press(KEY_INTERNATIONAL1);
        break;
    case 136:
        Keyboard.press(KEY_INTERNATIONAL2);
        break;
    case 137:
        Keyboard.press(KEY_INTERNATIONAL3);
        break;
    case 138:
        Keyboard.press(KEY_INTERNATIONAL4);
        break;
    case 139:
        Keyboard.press(KEY_INTERNATIONAL5);
        break;
    case 140:
        Keyboard.press(KEY_INTERNATIONAL6);
        break;
    case 141:
        Keyboard.press(KEY_INTERNATIONAL7);
        break;
    case 142:
        Keyboard.press(KEY_INTERNATIONAL8);
        break;
    case 143:
        Keyboard.press(KEY_INTERNATIONAL9);
        break;
    case 144:
        Keyboard.press(KEY_LANG1);
        break;
    case 145:
        Keyboard.press(KEY_LANG2);
        break;
    case 146:
        Keyboard.press(KEY_LANG3);
        break;
    case 147:
        Keyboard.press(KEY_LANG4);
        break;
    case 148:
        Keyboard.press(KEY_LANG5);
        break;
    case 149:
        Keyboard.press(KEY_LANG6);
        break;
    case 150:
        Keyboard.press(KEY_LANG7);
        break;
    case 151:
        Keyboard.press(KEY_LANG8);
        break;
    case 152:
        Keyboard.press(KEY_LANG9);
        break;
    case 153:
        Keyboard.press(KEY_ALTERNATE_ERASE);
        break;
    case 154:
        Keyboard.press(KEY_SYSREQ_ATTENTION);
        break;
    case 155:
        Keyboard.press(KEY_CANCEL);
        break;
    case 156:
        Keyboard.press(KEY_CLEAR);
        break;
    case 157:
        Keyboard.press(KEY_PRIOR);
        break;
    case 158:
        Keyboard.press(KEY_RETURN2);
        break;
    case 159:
        Keyboard.press(KEY_SEPARATOR);
        break;
    case 160:
        Keyboard.press(KEY_OUT);
        break;
    case 161:
        Keyboard.press(KEY_OPER);
        break;
    case 162:
        Keyboard.press(KEY_CLEAR_AGAIN);
        break;
    case 163:
        Keyboard.press(KEY_CRSEL_PROPS);
        break;
    case 164:
        Keyboard.press(KEY_EXSEL);
        break;
    // -- Reserved  165 - 175 (0xA5 - 0xAF) --
    /*
    case 165:
        Keyboard.press();
        break;
    case 166:
        Keyboard.press();
        break;
    case 167:
        Keyboard.press();
        break;
    case 168:
        Keyboard.press();
        break;
    case 169:
        Keyboard.press();
        break;
    case 170:
        Keyboard.press();
        break;
    case 171:
        Keyboard.press();
        break;
    case 172:
        Keyboard.press();
        break;
    case 173:
        Keyboard.press();
        break;
    case 174:
        Keyboard.press();
        break;
    case 175:
        Keyboard.press();
        break;
    */

    // -- Unused    176 - 220 (0xB0 - 0xDC) --
    /*
    case 176:
        Keyboard.press(KEY_PAD_00);
        break;
    case 177:
        Keyboard.press(KEY_PAD_000);
        break;
    case 178:
        Keyboard.press(KEY_THOUSANDS_SEPARATOR);
        break;
    case 179:
        Keyboard.press(KEY_DECIMAL_SEPARATOR);
        break;
    case 180:
        Keyboard.press(KEY_CURRENCY_UNIT);
        break;
    case 181:
        Keyboard.press(KEY_CURRENCY_SUB_UNIT);
        break;
    case 182:
        Keyboard.press(KEYPAD_LEFT_BRACE);
        break;
    case 183:
        Keyboard.press(KEYPAD_RIGHT_BRACE);
        break;
    case 184:
        Keyboard.press(KEYPAD_LEFT_CURLY_BRACE);
        break;
    case 185:
        Keyboard.press(KEYPAD_RIGHT_CURLY_BRACE);
        break;
    case 186:
        Keyboard.press(KEYPAD_TAB);
        break;
    case 187:
        Keyboard.press(KEYPAD_BACKSPACE);
        break;
    case 188:
        Keyboard.press(KEYPAD_A);
        break;
    case 189:
        Keyboard.press(KEYPAD_B);
        break;
    case 190:
        Keyboard.press(KEYPAD_C);
        break;
    case 191:
        Keyboard.press(KEYPAD_D);
        break;
    case 192:
        Keyboard.press(KEYPAD_E);
        break;
    case 193:
        Keyboard.press(KEYPAD_F);
        break;
    case 194:
        Keyboard.press(KEYPAD_XOR);
        break;
    case 195:
        Keyboard.press(KEYPAD_CARET);
        break;
    case 196:
        Keyboard.press(KEYPAD_PERCENT);
        break;
    case 197:
        Keyboard.press(KEYPAD_LESS_THAN);
        break;
    case 198:
        Keyboard.press(KEYPAD_GREATER_THAN);
        break;
    case 199:
        Keyboard.press(KEYPAD_AMPERSAND);
        break;
    case 200:
        Keyboard.press();
        break;
    case 201:
        Keyboard.press();
        break;
    case 202:
        Keyboard.press();
        break;
    case 203:
        Keyboard.press();
        break;
    case 204:
        Keyboard.press();
        break;
    case 205:
        Keyboard.press();
        break;
    case 206:
        Keyboard.press();
        break;
    case 207:
        Keyboard.press();
        break;
    case 208:
        Keyboard.press();
        break;
    case 209:
        Keyboard.press();
        break;
    case 210:
        Keyboard.press();
        break;
    case 211:
        Keyboard.press();
        break;
    case 212:
        Keyboard.press();
        break;
    case 213:
        Keyboard.press();
        break;
    case 214:
        Keyboard.press();
        break;
    case 215:
        Keyboard.press();
        break;
    case 216:
        Keyboard.press();
        break;
    case 217:
        Keyboard.press();
        break;
    case 218:
        Keyboard.press();
        break;
    case 219:
        Keyboard.press();
        break;
    case 220:
        Keyboard.press();
        break;
    */

    // -- Reserved  221 - 223 (0xDD - 0xDE) --
    /*
    case 221:
        Keyboard.press();
        break;
    case 222:
        Keyboard.press();
        break;
    case 223:
        Keyboard.press();
        break;
        */
    case 224:
        Keyboard.press(KEY_LEFT_CTRL);
        break;
    case 225:
        Keyboard.press(KEY_LEFT_SHIFT);
        break;
    case 226:
        Keyboard.press(KEY_LEFT_ALT);
        break;
    case 227:
        Keyboard.press(KEY_LEFT_GUI);
        break;
    case 228:
        Keyboard.press(KEY_RIGHT_CTRL);
        break;
    case 229:
        Keyboard.press(KEY_RIGHT_SHIFT);
        break;
    case 230:
        Keyboard.press(KEY_RIGHT_ALT);
        break;
    case 231:
        Keyboard.press(KEY_RIGHT_GUI);
        break;
    // -- Discontinued --
    /*
    case 232:
        Keyboard.press();
        break;
    case 233:
        Keyboard.press();
        break;
    case 234:
        Keyboard.press();
        break;
    case 235:
        Keyboard.press();
        break;
    case 236:
        Keyboard.press();
        break;
    case 237:
        Keyboard.press();
        break;
    case 238:
        Keyboard.press();
        break;
    case 239:
        Keyboard.press();
        break;
    case 240:
        Keyboard.press();
        break;
    case 241:
        Keyboard.press();
        break;
    case 242:
        Keyboard.press();
        break;
    case 243:
        Keyboard.press();
        break;
    case 244:
        Keyboard.press();
        break;
    case 245:
        Keyboard.press();
        break;
    case 246:
        Keyboard.press();
        break;
    case 247:
        Keyboard.press();
        break;
    case 248:
        Keyboard.press();
        break;
    case 249:
        Keyboard.press();
        break;
    case 250:
        Keyboard.press();
        break;
    case 251:
        Keyboard.press();
        break;
    case 252:
        Keyboard.press();
        break;
    case 253:
        Keyboard.press();
        break;
    case 254:
        Keyboard.press();
        break;
    case 255:
        Keyboard.press();
        break;
    case 256:
        Keyboard.press();
        break;
    case 257:
        Keyboard.press();
        break;
    case 258:
        Keyboard.press();
        break;
    case 259:
        Keyboard.press();
        break;
    case 260:
        Keyboard.press();
        break;
    case 261:
        Keyboard.press();
        break;
    case 262:
        Keyboard.press();
        break;
    case 263:
        Keyboard.press();
        break;
    case 264:
        Keyboard.press();
        break;
    case 265:
        Keyboard.press();
        break;
    case 266:
        Keyboard.press();
        break;
    case 267:
        Keyboard.press();
        break;
    case 268:
        Keyboard.press();
        break;
    case 269:
        Keyboard.press();
        break;
    case 270:
        Keyboard.press();
        break;
    case 271:
        Keyboard.press();
        break;
    case 272:
        Keyboard.press();
        break;
    case 273:
        Keyboard.press();
        break;
    case 274:
        Keyboard.press();
        break;
    case 275:
        Keyboard.press();
        break;
    case 276:
        Keyboard.press();
        break;
    case 277:
        Keyboard.press();
        break;
    case 278:
        Keyboard.press();
        break;
    case 279:
        Keyboard.press();
        break;
    case 280:
        Keyboard.press();
        break;
    case 281:
        Keyboard.press();
        break;
    case 282:
        Keyboard.press();
        break;
    case 283:
        Keyboard.press();
        break;
    case 284:
        Keyboard.press();
        break;
    case 285:
        Keyboard.press();
        break;
    case 286:
        Keyboard.press();
        break;
    case 287:
        Keyboard.press();
        break;
    case 288:
        Keyboard.press();
        break;
    case 289:
        Keyboard.press();
        break;
    case 290:
        Keyboard.press();
        break;
    case 291:
        Keyboard.press();
        break;
    case 292:
        Keyboard.press();
        break;
    case 293:
        Keyboard.press();
        break;
    */
    default:
        // Handle unknown key
        break;
    }
}

inline void keyboreRelease(uint8_t keycode)
{
    switch (keycode)
    {
    case 0:
        Keyboard.release(KEY_RESERVED);
        break;
    case 1:
        Keyboard.release(KEY_ERROR_ROLLOVER);
        break;
    case 2:
        Keyboard.release(KEY_POST_FAIL);
        break;
    case 3:
        Keyboard.release(KEY_ERROR_UNDEFINED);
        break;
    case 4:
        Keyboard.release(KEY_A);
        break;
    case 5:
        Keyboard.release(KEY_B);
        break;
    case 6:
        Keyboard.release(KEY_C);
        break;
    case 7:
        Keyboard.release(KEY_D);
        break;
    case 8:
        Keyboard.release(KEY_E);
        break;
    case 9:
        Keyboard.release(KEY_F);
        break;
    case 10:
        Keyboard.release(KEY_G);
        break;
    case 11:
        Keyboard.release(KEY_H);
        break;
    case 12:
        Keyboard.release(KEY_I);
        break;
    case 13:
        Keyboard.release(KEY_J);
        break;
    case 14:
        Keyboard.release(KEY_K);
        break;
    case 15:
        Keyboard.release(KEY_L);
        break;
    case 16:
        Keyboard.release(KEY_M);
        break;
    case 17:
        Keyboard.release(KEY_N);
        break;
    case 18:
        Keyboard.release(KEY_O);
        break;
    case 19:
        Keyboard.release(KEY_P);
        break;
    case 20:
        Keyboard.release(KEY_Q);
        break;
    case 21:
        Keyboard.release(KEY_R);
        break;
    case 22:
        Keyboard.release(KEY_S);
        break;
    case 23:
        Keyboard.release(KEY_T);
        break;
    case 24:
        Keyboard.release(KEY_U);
        break;
    case 25:
        Keyboard.release(KEY_V);
        break;
    case 26:
        Keyboard.release(KEY_W);
        break;
    case 27:
        Keyboard.release(KEY_X);
        break;
    case 28:
        Keyboard.release(KEY_Y);
        break;
    case 29:
        Keyboard.release(KEY_Z);
        break;
    case 30:
        Keyboard.release(KEY_1);
        break;
    case 31:
        Keyboard.release(KEY_2);
        break;
    case 32:
        Keyboard.release(KEY_3);
        break;
    case 33:
        Keyboard.release(KEY_4);
        break;
    case 34:
        Keyboard.release(KEY_5);
        break;
    case 35:
        Keyboard.release(KEY_6);
        break;
    case 36:
        Keyboard.release(KEY_7);
        break;
    case 37:
        Keyboard.release(KEY_8);
        break;
    case 38:
        Keyboard.release(KEY_9);
        break;
    case 39:
        Keyboard.release(KEY_0);
        break;
    case 40:
        Keyboard.release(KEY_ENTER);
        break;
    case 41:
        Keyboard.release(KEY_ESC);
        break;
    case 42:
        Keyboard.release(KEY_BACKSPACE);
        break;
    case 43:
        Keyboard.release(KEY_TAB);
        break;
    case 44:
        Keyboard.release(KEY_SPACE);
        break;
    case 45:
        Keyboard.release(KEY_MINUS);
        break;
    case 46:
        Keyboard.release(KEY_EQUAL);
        break;
    case 47:
        Keyboard.release(KEY_LEFT_BRACE);
        break;
    case 48:
        Keyboard.release(KEY_RIGHT_BRACE);
        break;
    case 49:
        Keyboard.release(KEY_BACKSLASH);
        break;
        // Special case for LEFT ALT key interfering with code for Consumer MUTE
    case 50:
        Keyboard.release(KEY_LEFT_ALT);
        break;
    case 51:
        Keyboard.release(KEY_SEMICOLON);
        break;
    case 52:
        Keyboard.release(KEY_QUOTE);
        break;
    case 53:
        Keyboard.release(KEY_TILDE);
        break;
    case 54:
        Keyboard.release(KEY_COMMA);
        break;
    case 55:
        Keyboard.release(KEY_PERIOD);
        break;
    case 56:
        Keyboard.release(KEY_SLASH);
        break;
    case 57:
        Keyboard.release(KEY_CAPS_LOCK);
        break;
    case 58:
        Keyboard.release(KEY_F1);
        break;
    case 59:
        Keyboard.release(KEY_F2);
        break;
    case 60:
        Keyboard.release(KEY_F3);
        break;
    case 61:
        Keyboard.release(KEY_F4);
        break;
    case 62:
        Keyboard.release(KEY_F5);
        break;
    case 63:
        Keyboard.release(KEY_F6);
        break;
    case 64:
        Keyboard.release(KEY_F7);
        break;
    case 65:
        Keyboard.release(KEY_F8);
        break;
    case 66:
        Keyboard.release(KEY_F9);
        break;
    case 67:
        Keyboard.release(KEY_F10);
        break;
    case 68:
        Keyboard.release(KEY_F11);
        break;
    case 69:
        Keyboard.release(KEY_F12);
        break;
    case 70:
        Keyboard.release(KEY_PRINTSCREEN);
        break;
    case 71:
        Keyboard.release(KEY_SCROLL_LOCK);
        break;
    case 72:
        Keyboard.release(KEY_PAUSE);
        break;
    case 73:
        Keyboard.release(KEY_INSERT);
        break;
    case 74:
        Keyboard.release(KEY_HOME);
        break;
    case 75:
        Keyboard.release(KEY_PAGE_UP);
        break;
    case 76:
        Keyboard.release(KEY_DELETE);
        break;
    case 77:
        Keyboard.release(KEY_END);
        break;
    case 78:
        Keyboard.release(KEY_PAGE_DOWN);
        break;
    case 79:
        Keyboard.release(KEY_RIGHT_ARROW);
        break;
    case 80:
        Keyboard.release(KEY_LEFT_ARROW);
        break;
    case 81:
        Keyboard.release(KEY_DOWN_ARROW);
        break;
    case 82:
        Keyboard.release(KEY_UP_ARROW);
        break;
    case 83:
        Keyboard.release(KEY_NUM_LOCK);
        break;
    case 84:
        Keyboard.release(KEYPAD_DIVIDE);
        break;
    case 85:
        Keyboard.release(KEYPAD_MULTIPLY);
        break;
    case 86:
        Keyboard.release(KEYPAD_SUBTRACT);
        break;
    case 87:
        Keyboard.release(KEYPAD_ADD);
        break;
    case 88:
        Keyboard.release(KEYPAD_ENTER);
        break;
    case 89:
        Keyboard.release(KEYPAD_1);
        break;
    case 90:
        Keyboard.release(KEYPAD_2);
        break;
    case 91:
        Keyboard.release(KEYPAD_3);
        break;
    case 92:
        Keyboard.release(KEYPAD_4);
        break;
    case 93:
        Keyboard.release(KEYPAD_5);
        break;
    case 94:
        Keyboard.release(KEYPAD_6);
        break;
    case 95:
        Keyboard.release(KEYPAD_7);
        break;
    case 96:
        Keyboard.release(KEYPAD_8);
        break;
    case 97:
        Keyboard.release(KEYPAD_9);
        break;
    case 98:
        Keyboard.release(KEYPAD_0);
        break;
    case 99:
        Keyboard.release(KEYPAD_DOT);
        break;
    case 100:
        Keyboard.release(KEY_NON_US);
        break;
    case 101:
        Keyboard.release(KEY_APPLICATION);
        break;
    case 102:
        Keyboard.release(KEY_POWER);
        break;
    case 103:
        Keyboard.release(KEY_PAD_EQUALS);
        break;
    case 104:
        Keyboard.release(KEY_F13);
        break;
    case 105:
        Keyboard.release(KEY_F14);
        break;
    case 106:
        Keyboard.release(KEY_F15);
        break;
    case 107:
        Keyboard.release(KEY_F16);
        break;
    case 108:
        Keyboard.release(KEY_F17);
        break;
    case 109:
        Keyboard.release(KEY_F18);
        break;
    case 110:
        Keyboard.release(KEY_F19);
        break;
    case 111:
        Keyboard.release(KEY_F20);
        break;
    case 112:
        Keyboard.release(KEY_F21);
        break;
    case 113:
        Keyboard.release(KEY_F22);
        break;
    case 114:
        Keyboard.release(KEY_F23);
        break;
    case 115:
        Keyboard.release(KEY_F24);
        break;
    case 116:
        Keyboard.release(KEY_EXECUTE);
        break;
    case 117:
        Keyboard.release(KEY_HELP);
        break;
    case 118:
        Keyboard.release(KEY_MENU2);
        break;
    case 119:
        Keyboard.release(KEY_SELECT);
        break;
    case 120:
        Keyboard.release(KEY_STOP);
        break;
    case 121:
        Keyboard.release(KEY_AGAIN);
        break;
    case 122:
        Keyboard.release(KEY_UNDO);
        break;
    case 123:
        Keyboard.release(KEY_CUT);
        break;
    case 124:
        Keyboard.release(KEY_COPY);
        break;
    case 125:
        Keyboard.release(KEY_PASTE);
        break;
    case 126:
        Keyboard.release(KEY_FIND);
        break;
    case 127:
        Keyboard.release(KEY_VOLUME_MUTE);
        break;
    case 128:
        Keyboard.release(KEY_VOLUME_UP);
        break;
    case 129:
        Keyboard.release(KEY_VOLUME_DOWN);
        break;
    case 130:
        Keyboard.release(KEY_LOCKING_CAPS_LOCK);
        break;
    case 131:
        Keyboard.release(KEY_LOCKING_NUM_LOCK);
        break;
    case 132:
        Keyboard.release(KEY_LOCKING_SCROLL_LOCK);
        break;
    case 133:
        Keyboard.release(KEYPAD_COMMA);
        break;
    case 134:
        Keyboard.release(KEYPAD_EQUAL_SIGN);
        break;
    case 135:
        Keyboard.release(KEY_INTERNATIONAL1);
        break;
    case 136:
        Keyboard.release(KEY_INTERNATIONAL2);
        break;
    case 137:
        Keyboard.release(KEY_INTERNATIONAL3);
        break;
    case 138:
        Keyboard.release(KEY_INTERNATIONAL4);
        break;
    case 139:
        Keyboard.release(KEY_INTERNATIONAL5);
        break;
    case 140:
        Keyboard.release(KEY_INTERNATIONAL6);
        break;
    case 141:
        Keyboard.release(KEY_INTERNATIONAL7);
        break;
    case 142:
        Keyboard.release(KEY_INTERNATIONAL8);
        break;
    case 143:
        Keyboard.release(KEY_INTERNATIONAL9);
        break;
    case 144:
        Keyboard.release(KEY_LANG1);
        break;
    case 145:
        Keyboard.release(KEY_LANG2);
        break;
    case 146:
        Keyboard.release(KEY_LANG3);
        break;
    case 147:
        Keyboard.release(KEY_LANG4);
        break;
    case 148:
        Keyboard.release(KEY_LANG5);
        break;
    case 149:
        Keyboard.release(KEY_LANG6);
        break;
    case 150:
        Keyboard.release(KEY_LANG7);
        break;
    case 151:
        Keyboard.release(KEY_LANG8);
        break;
    case 152:
        Keyboard.release(KEY_LANG9);
        break;
    case 153:
        Keyboard.release(KEY_ALTERNATE_ERASE);
        break;
    case 154:
        Keyboard.release(KEY_SYSREQ_ATTENTION);
        break;
    case 155:
        Keyboard.release(KEY_CANCEL);
        break;
    case 156:
        Keyboard.release(KEY_CLEAR);
        break;
    case 157:
        Keyboard.release(KEY_PRIOR);
        break;
    case 158:
        Keyboard.release(KEY_RETURN2);
        break;
    case 159:
        Keyboard.release(KEY_SEPARATOR);
        break;
    case 160:
        Keyboard.release(KEY_OUT);
        break;
    case 161:
        Keyboard.release(KEY_OPER);
        break;
    case 162:
        Keyboard.release(KEY_CLEAR_AGAIN);
        break;
    case 163:
        Keyboard.release(KEY_CRSEL_PROPS);
        break;
    case 164:
        Keyboard.release(KEY_EXSEL);
        break;
    // -- Reserved  165 - 175 (0xA5 - 0xAF) --
    /*
    case 165:
        Keyboard.release();
        break;
    case 166:
        Keyboard.release();
        break;
    case 167:
        Keyboard.release();
        break;
    case 168:
        Keyboard.release();
        break;
    case 169:
        Keyboard.release();
        break;
    case 170:
        Keyboard.release();
        break;
    case 171:
        Keyboard.release();
        break;
    case 172:
        Keyboard.release();
        break;
    case 173:
        Keyboard.release();
        break;
    case 174:
        Keyboard.release();
        break;
    case 175:
        Keyboard.release();
        break;
    */

    // -- Unused    176 - 220 (0xB0 - 0xDC) --
    /*
    case 176:
        Keyboard.release(KEY_PAD_00);
        break;
    case 177:
        Keyboard.release(KEY_PAD_000);
        break;
    case 178:
        Keyboard.release(KEY_THOUSANDS_SEPARATOR);
        break;
    case 179:
        Keyboard.release(KEY_DECIMAL_SEPARATOR);
        break;
    case 180:
        Keyboard.release(KEY_CURRENCY_UNIT);
        break;
    case 181:
        Keyboard.release(KEY_CURRENCY_SUB_UNIT);
        break;
    case 182:
        Keyboard.release(KEYPAD_LEFT_BRACE);
        break;
    case 183:
        Keyboard.release(KEYPAD_RIGHT_BRACE);
        break;
    case 184:
        Keyboard.release(KEYPAD_LEFT_CURLY_BRACE);
        break;
    case 185:
        Keyboard.release(KEYPAD_RIGHT_CURLY_BRACE);
        break;
    case 186:
        Keyboard.release(KEYPAD_TAB);
        break;
    case 187:
        Keyboard.release(KEYPAD_BACKSPACE);
        break;
    case 188:
        Keyboard.release(KEYPAD_A);
        break;
    case 189:
        Keyboard.release(KEYPAD_B);
        break;
    case 190:
        Keyboard.release(KEYPAD_C);
        break;
    case 191:
        Keyboard.release(KEYPAD_D);
        break;
    case 192:
        Keyboard.release(KEYPAD_E);
        break;
    case 193:
        Keyboard.release(KEYPAD_F);
        break;
    case 194:
        Keyboard.release(KEYPAD_XOR);
        break;
    case 195:
        Keyboard.release(KEYPAD_CARET);
        break;
    case 196:
        Keyboard.release(KEYPAD_PERCENT);
        break;
    case 197:
        Keyboard.release(KEYPAD_LESS_THAN);
        break;
    case 198:
        Keyboard.release(KEYPAD_GREATER_THAN);
        break;
    case 199:
        Keyboard.release(KEYPAD_AMPERSAND);
        break;
    case 200:
        Keyboard.release();
        break;
    case 201:
        Keyboard.release();
        break;
    case 202:
        Keyboard.release();
        break;
    case 203:
        Keyboard.release();
        break;
    case 204:
        Keyboard.release();
        break;
    case 205:
        Keyboard.release();
        break;
    case 206:
        Keyboard.release();
        break;
    case 207:
        Keyboard.release();
        break;
    case 208:
        Keyboard.release();
        break;
    case 209:
        Keyboard.release();
        break;
    case 210:
        Keyboard.release();
        break;
    case 211:
        Keyboard.release();
        break;
    case 212:
        Keyboard.release();
        break;
    case 213:
        Keyboard.release();
        break;
    case 214:
        Keyboard.release();
        break;
    case 215:
        Keyboard.release();
        break;
    case 216:
        Keyboard.release();
        break;
    case 217:
        Keyboard.release();
        break;
    case 218:
        Keyboard.release();
        break;
    case 219:
        Keyboard.release();
        break;
    case 220:
        Keyboard.release();
        break;
    */

    // -- Reserved  221 - 223 (0xDD  0xDF) --
    /*
    case 221:
        Keyboard.release();
        break;
    case 222:
        Keyboard.release();
        break;
    case 223:
        Keyboard.release();
        break;
    */
    case 224:
        Keyboard.release(KEY_LEFT_CTRL);
        break;
    case 225:
        Keyboard.release(KEY_LEFT_SHIFT);
        break;
    case 226:
        Keyboard.release(KEY_LEFT_ALT);
        break;
    case 227:
        Keyboard.release(KEY_LEFT_GUI);
        break;
    case 228:
        Keyboard.release(KEY_RIGHT_CTRL);
        break;
    case 229:
        Keyboard.release(KEY_RIGHT_SHIFT);
        break;
    case 230:
        Keyboard.release(KEY_RIGHT_ALT);
        break;
    case 231:
        Keyboard.release(KEY_RIGHT_GUI);
        break;
    // -- Discontinued --
    /*
    case 235:
        Keyboard.release();
        break;
    case 236:
        Keyboard.release();
        break;
    case 237:
        Keyboard.release();
        break;
    case 238:
        Keyboard.release();
        break;
    case 239:
        Keyboard.release();
        break;
    case 240:
        Keyboard.release();
        break;
    case 241:
        Keyboard.release();
        break;
    case 242:
        Keyboard.release();
        break;
    case 243:
        Keyboard.release();
        break;
    case 244:
        Keyboard.release();
        break;
    case 245:
        Keyboard.release();
        break;
    case 246:
        Keyboard.release();
        break;
    case 247:
        Keyboard.release();
        break;
    case 248:
        Keyboard.release();
        break;
    case 249:
        Keyboard.release();
        break;
    case 250:
        Keyboard.release();
        break;
    case 251:
        Keyboard.release();
        break;
    case 252:
        Keyboard.release();
        break;
    case 253:
        Keyboard.release();
        break;
    case 254:
        Keyboard.release();
        break;
    */
    default:
        // Handle unknown key
        break;
    }
}

inline void consumeristPress(uint8_t keycode)
{
    switch (keycode)
    {
    case 48:
        Consumer.write(CONSUMER_POWER);
        Consumer.release(CONSUMER_POWER);
        break;
    case 49:
        Consumer.write(CONSUMER_SLEEP);
        Consumer.release(CONSUMER_SLEEP);
        break;
    case 111:
        Consumer.write(CONSUMER_BRIGHTNESS_UP);
        Consumer.release(CONSUMER_BRIGHTNESS_UP);
        break;
    case 112:
        Consumer.write(CONSUMER_BRIGHTNESS_DOWN);
        Consumer.release(CONSUMER_BRIGHTNESS_DOWN);
        break;
    case 178:
        Consumer.write(MEDIA_RECORD);
        Consumer.release(MEDIA_RECORD);
        break;
    case 179:
        Consumer.write(MEDIA_FAST_FORWARD);
        Consumer.release(MEDIA_FAST_FORWARD);
        break;
    case 180:
        Consumer.write(MEDIA_REWIND);
        Consumer.release(MEDIA_REWIND);
        break;
    case 181:
        Consumer.write(MEDIA_NEXT);
        Consumer.release(MEDIA_NEXT);
        break;
    case 182:
        Consumer.write(MEDIA_PREVIOUS);
        Consumer.release(MEDIA_PREVIOUS);
        break;
    case 183:
        Consumer.write(MEDIA_STOP);
        Consumer.release(MEDIA_STOP);
        break;
    case 185:
        Consumer.write(MEDIA_PAUSE);
        Consumer.release(MEDIA_PAUSE);
        break;
    case 205:
        Consumer.write(MEDIA_PLAY_PAUSE);
        Consumer.release(MEDIA_PLAY_PAUSE);
        break;
    case 226:
        // Consumer.press(MEDIA_VOLUME_MUTE);
        Consumer.write(MEDIA_VOLUME_MUTE);
        Consumer.release(MEDIA_VOLUME_MUTE);
        break;
    case 233:
        Consumer.write(MEDIA_VOLUME_UP);
        Consumer.release(MEDIA_VOLUME_UP);
        break;
    case 234:
        Consumer.write(MEDIA_VOLUME_DOWN);
        Consumer.release(MEDIA_VOLUME_DOWN);
        break;
    default:
        // Handle unknown key
        break;
    }
}

const uint8_t macroCount = 20; // Adjust depends on Memory limit

const uint8_t MacroMap[macroCount][20]{
    {1, KEY_RIGHT_CTRL, 1, KEY_RIGHT_SHIFT, 1, KEY_ESC, 0, KEY_ESC, 0, KEY_RIGHT_SHIFT, 0, KEY_RIGHT_CTRL},
    {1, KEY_LEFT_GUI, 1, KEY_TAB, 0, KEY_TAB, 0, KEY_LEFT_GUI},
    {1, KEY_LEFT_GUI, 1, KEY_L, 0, KEY_L, 0, KEY_LEFT_GUI},
    {1, KEY_LEFT_GUI, 1, KEY_A, 0, KEY_A, 0, KEY_LEFT_GUI},
    {1, KEY_RIGHT_CTRL, 1, KEY_RIGHT_GUI, 1, KEY_LEFT_ARROW, 0, KEY_LEFT_ARROW, 0, KEY_RIGHT_GUI, 0, KEY_RIGHT_CTRL},
    {1, KEY_RIGHT_CTRL, 1, KEY_RIGHT_GUI, 1, KEY_RIGHT_ARROW, 0, KEY_RIGHT_ARROW, 0, KEY_RIGHT_GUI, 0, KEY_RIGHT_CTRL}
};

// -- STATUS CHECK --
inline void keyboreStatus(bool upDown, uint8_t keycode)
{
    switch (upDown)
    {
    case 1:
        keyborePress(keycode);
        break;
    case 0:
        keyboreRelease(keycode);
        break;
    default:
        break;
    }
}

inline void consumeristStatus(bool upDown, uint8_t keycode)
{
    switch (upDown)
    {
    case 1:
        consumeristPress(keycode);
        break;
    case 0:
        break;
    default:
        break;
    }
}

const uint8_t consumerKeycodes[] = {
    111, 112,
    178, 179, 180, 181,
    182, 183, 185, 205,
    226, 233, 234};



// Identify whether use Consumer or Keyboard, as well as to press or release
inline void keyTypeLookup(bool upDown, uint8_t keycode)
{
    bool isConsumer = false;
    for (uint8_t c = 0; c < sizeof(consumerKeycodes) / sizeof(consumerKeycodes[0]); c++)
    {
        if (keycode == consumerKeycodes[c])
        {
            isConsumer = true;
            break;
        }
    }
    if (isConsumer)
    {
        consumeristStatus(upDown, keycode);
    }
    else
    {
        keyboreStatus(upDown, keycode);
    }
}

inline bool isMacroKeycode(uint8_t keycode)
{
    return (keycode >= 235 && keycode <= 254);
}

/*const uint8_t macroKeycodes[] = {
    235, 236, 237, 238, 239,
    240, 241, 242, 243, 244};
*/

inline void MacroRun(uint8_t macroCode)
{
    uint8_t MacroArrayRow;
    bool found = false;
    for (uint8_t c = 0; c < macroCount; c++)
    {
        switch (macroCode)
        {
        case 235:
            MacroArrayRow = 0;
            break;
        case 236:
            MacroArrayRow = 1;
            break;
        case 237:
            MacroArrayRow = 2;
            break;
        case 238:
            MacroArrayRow = 3;
            break;
        case 239:
            MacroArrayRow = 4;
            break;
        case 240:
            MacroArrayRow = 5;
            break;
        case 241:
            MacroArrayRow = 6;
            break;
        case 242:
            MacroArrayRow = 7;
            break;
        case 243:
            MacroArrayRow = 8;
            break;
        case 244:
            MacroArrayRow = 9;
            break;
        default:
            return;
        }
    }
    for (uint8_t m = 0; m < 100; m += 2)
    {
        keyTypeLookup(MacroMap[MacroArrayRow][m], MacroMap[MacroArrayRow][m + 1]);
        if (MacroMap[MacroArrayRow][m + 1] == 0)
        {
            break;
        }
    }
}