#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NAVI 2 // navigation
#define MDIA 3 // media keys

#define KC_XXXX KC_NO

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `~   |   1! |   2@ |   3# |   4$ |   5% | XXXX |           | XXXX |   6^ |   7& |   8* |   9( |   0) | Back   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Home |           | PgUp |   Y  |   U  |   I  |   O  |   P  |   \|   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;:   | Enter  |
 * |--------+------+------+------+------+------| End  |           | PgDn |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,< |   .> | /?   |RShift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Mdia | Meh  |Hyper |Super | Alt  |                                       | Alt  |Super |Hyper | Meh  | Mdia |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | XXXX | XXXX |       | XXXX | XXXX |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | XXXX |       | XXXX |        |      |
 *                                 |Space | Symb |------|       |------|  Navi  | Symb |
 *                                 |      |      | Back |       | Ins  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,        KC_2,        KC_3,        KC_4,   KC_5,    KC_XXXX,
        KC_TAB,         KC_Q,        KC_W,        KC_E,        KC_R,   KC_T,    KC_HOME,
        CTL_T(KC_ESC),  KC_A,        KC_S,        KC_D,        KC_F,   KC_G,   
        KC_LSFT,        KC_Z,        KC_X,        KC_C,        KC_V,   KC_B,    KC_END,
        MO(MDIA),       MEH_T(KC_NO),ALL_T(KC_NO),KC_LGUI,     KC_LALT,
                                                                       KC_XXXX,KC_XXXX,
                                                                               KC_XXXX,
                                                               KC_SPC,MO(SYMB),KC_BSPC,
        // right hand
        KC_XXXX,   KC_6,      KC_7,    KC_8,        KC_9,        KC_0,        KC_BSPC,
        KC_PGUP,   KC_Y,      KC_U,    KC_I,        KC_O,        KC_P,        KC_BSLS,
                   KC_H,      KC_J,    KC_K,        KC_L,        KC_SCLN,     KC_ENT,
        KC_PGDN,   KC_N,      KC_M,    KC_COMM,     KC_DOT,      KC_SLSH,     KC_RSFT,
                              KC_RALT, KC_RGUI,     ALL_T(KC_NO),MEH_T(KC_NO),MO(MDIA),
        KC_XXXX,   KC_XXXX,
        KC_XXXX,
        KC_INS,    MO(NAVI),  MO(SYMB)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  XXXX   |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  | F11  | F12  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   #  |  $   |   %  | XXXX |           | XXXX |   ^  |   &  |   *  |  -_  |  =+  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  (   |   )  |   [  |   ]  |   $  |------|           |------|   0  |   1  |   2  |   3  |   4  |   '"   |
 * |---------+------+------+------+------+------| XXXX |           | XXXX |------+------+------+------+------+--------|
 * |         |  <   |   >  |   {  |   }  |   0  |      |           |      |   5  |   6  |   7  |   8  |   9  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | XXXX  |      |      |      |      |                                       |      |      |      |      | XXXX |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_XXXX,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS,KC_EXLM,KC_AT,  KC_HASH,KC_DLR,KC_PERC,KC_XXXX,
       KC_TRNS,KC_LPRN,KC_RPRN,KC_LBRC,KC_RBRC,KC_DLR,
       KC_TRNS,KC_LT,  KC_GT,KC_LCBR,KC_RCBR,KC_0,KC_XXXX,
       KC_XXXX,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_TRNS,
       KC_XXXX, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_MINS,  KC_EQL,  KC_TRNS,
                KC_0,    KC_1,     KC_2,     KC_3,     KC_4,    KC_QUOT,
       KC_XXXX, KC_5,    KC_6,     KC_7,     KC_8,     KC_9,    KC_TRNS,
                         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_XXXX,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Navigation Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  XXXX   |      |      |      |      |      | XXXX |           | XXXX |      |      |      |      |      | XXXX   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         | XXXX | XXXX | MsUp | XXXX | XXXX |MsWhUp|           | XXXX | MsLf | MsDn | MsUp | MsRg | XXXX | Tab    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | XXXX |MsLeft| MsDn |MsRght| XXXX |------|           |------| Left | Down |  Up  | Right| XXXX |Ctrl/Esc|
 * |---------+------+------+------+------+------|MsWhDn|           | XXXX |------+------+------+------+------+--------|
 * |         | XXXX | XXXX | XXXX | XXXX | XXXX |      |           |      | End  | PgDn | PgUp | Home | XXXX | Shift  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | XXXX  |      |      |      |      |                                       |      |      |      |      | XXXX |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |MsBtn1|MsBtn2|------|       |------|      |      |
 *                                 |      |      |MsBtn3|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Navigation
[NAVI] = LAYOUT_ergodox(
       // left hand
       KC_XXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_XXXX,
       KC_TRNS, KC_XXXX, KC_XXXX, KC_MS_U, KC_XXXX,    KC_XXXX,   KC_MS_WH_UP,
       KC_TRNS, KC_XXXX, KC_MS_LEFT, KC_MS_D, KC_MS_RIGHT,      KC_RIGHT,
       KC_TRNS, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX,    KC_XXXX,   KC_MS_WH_DOWN,
       KC_XXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS,    KC_TRNS,
                                                       KC_TRNS,
                                           KC_MS_BTN1, KC_MS_BTN2,KC_MS_BTN3,
       // right hand
       KC_XXXX,        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_XXXX,
       KC_MS_WH_UP,    KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R, KC_XXXX,KC_TRNS,
                       KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,KC_XXXX,KC_TRNS,
       KC_MS_WH_DOWN,  KC_END, KC_PGDN,KC_PGUP,KC_HOME, KC_XXXX,KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_XXXX,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
),
/* Keymap 3: Media
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | XXXX   | F1   | F2   | F3   | F4   | F5   | F6   |           | F7   | F8   | F9   | F10  | F11  | F12  | XXXX   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |           | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | XXXX | XXXX | XXXX | XXXX | XXXX |------|           |------| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX   |
 * |--------+------+------+------+------+------| XXXX |           | XXXX |------+------+------+------+------+--------|
 * |        | XXXX | XXXX | XXXX | XXXX | XXXX |      |           |      | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | XXXX |      |      |      |      |                                       |      |      |      |      | XXXX |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VRSN | EPRM |       | Prev | Next |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | XXXX |       |VolUp |      |      |
 *                                 | XXXX | XXXX |------|       |------| Mute | Play |
 *                                 |      |      | XXXX |       |VolDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA, MOUSE, FUNCTION
[MDIA] = LAYOUT_ergodox(
       KC_XXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX,
       KC_TRNS, KC_XXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_XXXX,
       KC_TRNS, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX,
       KC_XXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           VRSN,    EPRM,
                                                    KC_XXXX,
                                  KC_XXXX, KC_XXXX, KC_XXXX,
    // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_XXXX,
       KC_XXXX,  KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX,
                 KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX,
       KC_XXXX,  KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX, KC_XXXX,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_XXXX,
       KC_MPRV, KC_MNXT,
       KC_VOLU,
       KC_VOLD, KC_MUTE, KC_MPLY
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
