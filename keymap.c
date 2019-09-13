#include "xd60.h"
#define MOUSEKEY_DELAY             16
#define MOUSEKEY_INTERVAL          0
#define MOUSEKEY_MAX_SPEED         7
#define MOUSEKEY_TIME_TO_MAX       60
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#define ____ KC_TRNS

enum unicode_names {
    BANG,
    IRONY,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* 0: Base Layer
 * .----------------------------------------------------------------.
 * |GrEsc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | \ | Bksp |  Escape on tap, tilde with shift
 * |----------------------------------------------------------------|
 * | Tab  | Q | W | E | R | T | Y | U | I | O | P | [ | ] |    \    |
 * |----------------------------------------------------------------|
 * |CL/CTRL | A | S | D | F | G | H | J | K | L | ; | ' | Enter/CTRL|  Caps - CapsLock on Tap, CTRL on hold, Same with return
 * |----------------------------------------------------------------|
 * |   Shift  | Z | X | C | V | B | N | M | , | . |Shft/Slsh| ↑ |LC |  Right Shift - Shift on hold, Slash on tap, Left click
 * |----------------------------------------------------------------|
 * | LCtrl | LGUI | LAlt |    Space/FN      | RAlt |Ctrl| ← | ↓ | → |
 * '----------------------------------------------------------------'
 */
  LAYOUT_all(
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_NO,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      CTL_T(KC_NO), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO, CTL_T(KC_ENT),    \
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_NO, RSFT_T(KC_SLSH), KC_UP,  KC_MS_BTN1,      \
      KC_LCTL, KC_LGUI, KC_LALT,                          LT(2, KC_SPC),                       KC_RALT, KC_RCTL,     KC_LEFT, KC_DOWN,  KC_RIGHT),

/* 1: Mac Layer
 * .----------------------------------------------------------------.
 * |GrEsc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | \ | Bksp |  Escape on tap, tilde with shift
 * |----------------------------------------------------------------|
 * | Tab  | Q | W | E | R | T | Y | U | I | O | P | [ | ] |    \    |
 * |----------------------------------------------------------------|
 * |CL/CTRL | A | S | D | F | G | H | J | K | L | ; | ' | Enter/CTRL|  Caps - CapsLock on Tap, CTRL on hold, Same with return
 * |----------------------------------------------------------------|
 * |   Shift  | Z | X | C | V | B | N | M | , | . |Shft/Slsh| ↑ |LC |  Right Shift - Shift on hold, Slash on tap, Left click
 * |----------------------------------------------------------------|
 * | LCtrl | Optn | Cmnd |    Space/FN      | RAlt |Ctrl| ← | ↓ | → |
 * '----------------------------------------------------------------'
 */
  LAYOUT_all(
      KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_NO,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      CTL_T(KC_NO), KC_A,    KC_S,    KC_D,   X(BANG),   X(IRONY),   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,      KC_TRNS,    \
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_NO, RSFT_T(KC_SLSH), KC_UP,  KC_MS_BTN1,      \
      KC_LCTL, KC_LALT, KC_LGUI,                          KC_TRNS,                       KC_RALT, KC_RCTL,     KC_LEFT, KC_DOWN,  KC_RIGHT),

/* 2: Function Layer
 * .----------------------------------------------------------------.
 * | `   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12| \ | Del  |
 * |----------------------------------------------------------------|
 * |  Esc |LC |MU |RC | * | T | Y | U | ↑ | O | P | [ | ] | BL_STEP |  Left Click, Mouse Up, Right Click, * programming mode/RESET, BackLight Adj
 * |----------------------------------------------------------------|
 * |CL/CTRL |ML |MD |MR | F | G | ← | ↑ | ↓ | → | ; | ' |   Enter   |  Mouse Left, Mouse Down, Mouse Right - Mouse movements, Arrow keys
 * |----------------------------------------------------------------|
 * |   Shift  | Z | ! | ? | V | B | N | M | , | . |Shft/Slsh|PU |RC |  Underglow (!) toggle on/off (?) cycle modes, Right Click
 * |----------------------------------------------------------------|
 * | LCtrl | WIN  | LAlt |    Space/FN      | RAlt |Ctrl|HM |PD |END|  Arrow cluster Home, PageUp, PageDown, End
 * '----------------------------------------------------------------'
 */
  LAYOUT_all(
      KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,   KC_F14,    \
      KC_ESC,   KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2, RESET,KC_NO,KC_CALC,KC_NO,  KC_NO, KC_NO,   KC_PSCR, KC_SLCK,  KC_MPLY,           BL_STEP,    \
      CTL_T(KC_CAPS),   KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,X(BANG), X(IRONY), KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT,   KC_HOME, KC_PGUP,  KC_NO,             KC_TRNS,    \
      //CTL_T(KC_NO), KC_A,    KC_S,    KC_D,   X(BANG),   X(IRONY),   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,      KC_TRNS,    
      KC_LSFT, KC_NO,   KC_NO,   RGB_TOG,  RGB_MOD,KC_NO,  KC_NO,  KC_VOLD,KC_VOLU,KC_KP_MINUS, KC_KP_PLUS,  KC_RSFT,  KC_RSFT, KC_PGUP,  TG(1),      \
      KC_LCTL, F(0), KC_LALT,                          KC_TRNS,                          KC_RGUI, F(0),     KC_HOME, KC_PGDOWN,KC_END),
};


// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

uint32_t layer_state_set_user(uint32_t state) {
	switch (biton32(state)) {
		case 0:
			rgblight_setrgb(0x00, 0xAA, 0xAA); // Cyan on layer 0
			break;
		case 1:
			rgblight_setrgb(0xAA, 0xAA, 0xAA); // White on layer 1
			break;
		case 2:
			rgblight_setrgb(0xFF, 0x00, 0xFF); // Purple on FN layer
			break;
	}
	return state;
}

/* vim: set nowrap:  */
