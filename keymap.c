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

#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_norwegian.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TAB_LSFT MT(MOD_LSFT, KC_TAB)
#define CPS_LSFT MT(MOD_LSFT, KC_CAPSLOCK)
#define DOT_RSFT MT(MOD_RSFT, KC_DOT)

#define LPRN S(KC_8)
#define LBRK S(A(KC_8))
#define LBRC A(KC_8)
#define RPRN S(KC_9)
#define RBRK S(A(KC_9))
#define RBRC A(KC_9)

// Disable light in middle of 2U position
#ifdef RGB_MATRIX_H
void rgb_matrix_indicators_user(void) {
  rgb_matrix_set_color(42, 0, 0, 0);
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | '    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Å  | Entr |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tb/S |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   Ø  |   Æ  |   ,  | ./Rs |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Cp/S | Ctrl | Alt  | Cmd  |  Lwr |    Space    |  Rse | Left | Down |  Up  | Rght |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_planck_grid(
    KC_GRV,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    NO_AA,   KC_ENT,
    TAB_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  NO_OSLH, NO_AE,   KC_COMM, DOT_RSFT,
    CPS_LSFT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |      |   #  |   &  |      |   {  |   ´  |   =  |   }  |      |   |  |   +  |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   %  |   !  |   <  |   (  |   *  |   @  |   )  |   >  |   /  |   -  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |   $  |   ?  |      |   [  |   `  |   "  |   ]  |      |   \  |   ~  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid(
    _______, KC_HASH, S(KC_6),    _______, LBRK,    KC_EQL,    S(KC_0), RBRK,    _______,    A(KC_7),    KC_MINS,       _______,
    _______, KC_PERC, KC_EXLM,    KC_NUBS, LPRN,    NO_ASTR,   KC_BSLS, RPRN,    S(KC_NUBS), S(KC_7),    KC_SLSH,       _______,
    _______, KC_DLR,  S(KC_MINS), _______, LBRC,    S(KC_EQL), S(KC_2), RBRC,    _______,    S(A(KC_7)), ALGR(KC_RBRC), _______,
    _______, _______, _______,    _______, _______, _______,   _______, _______, KC_MNXT,    KC_VOLD,    KC_VOLU,       KC_MPLY
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   0  |   1  |   2  |   3  |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   4  |   5  |   6  |      |      | Left | Down |  Up  | Rght |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |   7  |   8  |   9  |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Prev | Bri- | Bri+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_planck_grid(
    KC_0,    KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, KC_4,    KC_5,    KC_6,    _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
    _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_SLCK,  KC_PAUS, KC_MPLY
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * | Reset|      |      |      |      |      |      |      |      |      |      |  Del |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_grid(
    RESET,   DEBUG,   RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,  KC_F1,  KC_F2,  KC_F3,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  KC_F4,  KC_F5,  KC_F6,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, KC_F7,  KC_F8,  KC_F9,
    _______, _______, _______, _______, _______, RGB_TOG, RGB_TOG, _______, _______,  KC_F10, KC_F11, KC_F12
  )

};

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
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
