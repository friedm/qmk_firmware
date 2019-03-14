/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define SYMB MO(_LOWER)
#define NAVI MO(_RAISE)

#define KC_XXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------------------------------------------------------------------------------.
 * |   `    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * |        |      | Alt  |Super |Spc/Nv|Alt/Tb| Back |Symb  | Ins  |      |      |      |
 * `-------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
         KC_GRV,    KC_Q,    KC_W,    KC_E,            KC_R,         KC_T,     KC_Y, KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  CTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,            KC_F,         KC_G,     KC_H, KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,            KC_V,         KC_B,     KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
        KC_XXXX, KC_XXXX, KC_LALT, KC_LGUI, LT(NAVI,KC_SPC), ALT_T(KC_TAB), KC_BSPC, SYMB,  KC_INS, KC_XXXX, KC_XXXX, KC_XXXX
),


/* Lower (Symb)
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   _  |   -  |   =  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  <   |  (   |   '  |  )   |   >  |  0   |   1  |  2   |   3  |   4  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  [   |  {   |   "  |  }   |   ]  |  5   |   6  |  7   |   8  |   9  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_UNDS,    KC_MINS, KC_EQL, KC_PLUS,
  _______, KC_LT,   KC_LPRN, KC_QUOT, KC_RPRN, KC_GT,   KC_0,    KC_1,       KC_2,       KC_3,    KC_4,   KC_PIPE,
  _______,  KC_LBRC, KC_LCBR, KC_DQT,  KC_RCBR, KC_RBRC, KC_5,    KC_6,       KC_7,       KC_8,    KC_9,  KC_ASTR,
  _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______,_______
),

/* Raise (Navi)
 * ,-----------------------------------------------------------------------------------.
 * |      | XXXX | XXXX | MsUp | XXXX |MsWhUp|MsWhLf|MSWhDn|MsWhUp|MsWhRg| XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | XXXX | MsLf | MsDn | MsRg |MsWhDn| Left | Down |  Up  |Right | XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | XXXX |MsBtn1|MsBtn2|MsBtn3| XXXX | Home | PgDn | PgUp | End  | XXXX |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  _______, KC_XXXX,    KC_XXXX,   KC_MS_UP,     KC_XXXX,  KC_MS_WH_UP,KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_UP,KC_MS_WH_RIGHT,KC_XXXX,_______,
  _______, KC_XXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,KC_MS_WH_DOWN,      KC_LEFT,      KC_DOWN,      KC_UP,      KC_RIGHT,KC_XXXX,_______,
  _______, KC_XXXX, KC_MS_BTN1, KC_MS_BTN2,  KC_MS_BTN3,      KC_XXXX,      KC_HOME,      KC_PGDN,    KC_PGUP,        KC_END,KC_XXXX,_______,
  _______, _______,    _______,    _______,     _______,      _______,      _______,      _______,    _______,       _______,_______,_______
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |AGNorm|Qwerty|      |      |      |      | F9   | F10  | F11  | F12  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F1   | F2   | F3   | F4   |      |      | F5   | F6   | F7   | F8   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Mute | Prev | Vol- | Vol+ | Next | Play |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Reset|      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
  _______, AG_NORM,  QWERTY, _______, _______, _______, _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______, _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
  _______, _______, _______, _______, _______, KC_MUTE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, _______,
  RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_planck_grid(
  KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, NAVI,    KC_SPC,  KC_SPC,  SYMB,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
  BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, NAVI,    KC_SPC,  KC_SPC,  SYMB,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
)};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case SYMB:
    case NAVI:
      return false;
    default:
      return true;
  }
}
