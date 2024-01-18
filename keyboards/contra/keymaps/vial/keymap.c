#include QMK_KEYBOARD_H

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  BASE = SAFE_RANGE,
  LOWER = LT(_LOWER, KC_SPACE),
  RAISE = MO(_RAISE),
  TCONTROL = LCTL_T(KC_TAB),
  TSHIFT = RSFT_T(KC_ENTER)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base
   * ,-----------------------------------------------------------------------------------.
   * |   Q  |   W  |   F  |   P  |   B  |      |      |   J  |   L  |   U  |   Y  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |OST-A |ALTT-R|CTLT-S|SHFT-T|   G  |      |      |   M  |SHFT-N|CTLT-E|ALTT-I|OST-O |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |   Z  |   X  |   C  |   D  |   V  |      |      |   K  |   H  |   ,  |   .  |   '  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |LOWER |TCTRL |      |      |TSHFT |RAISE |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_BASE] = LAYOUT_ortho_4x12(
    KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,     KC_NO, KC_NO, KC_J,   KC_L,         KC_U,         KC_Z,         KC_BSPACE,
    LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,     KC_NO, KC_NO, KC_M,   RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O),
    KC_Y,         KC_X,         KC_C,         KC_D,         KC_V,     KC_NO, KC_NO, KC_K,   KC_H,         KC_COMMA,     KC_DOT,       LSFT(KC_1),
    KC_NO,        KC_NO,        KC_NO,        LOWER,        TCONTROL, KC_NO, KC_NO, TSHIFT, RAISE,        KC_NO,        KC_NO,        KC_NO
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |  ESC |  DEL |      |      |      |      |      |      |      |   Ú  |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | LEFT |  UP  | DOWN | RIGHT|      |      |      |      |SHFT-Á|CTLT-É|ALTT-Í|OST-Ó |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12(
    KC_ESCAPE, KC_DEL,  _______, _______,  _______, KC_NO, KC_NO, _______, _______,          KC_RBRACKET,       _______,                 _______,
    KC_LEFT,   KC_UP,   KC_DOWN, KC_RIGHT, _______, KC_NO, KC_NO, _______, RSFT_T(KC_QUOTE), RCTL_T(KC_SCOLON), LALT_T(KC_NONUS_BSLASH), LGUI_T(KC_EQUAL),
    _______,   _______, _______, _______,  _______, KC_NO, KC_NO, _______, _______,          _______,           _______,                 _______,
    KC_NO,     KC_NO,   KC_NO,   _______,  _______, KC_NO, KC_NO, _______, _______,          KC_NO,             KC_NO,                   KC_NO
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |      |      |      |      |  7   |  8   |  9   |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |  F5  |  F6  |  F7  |  F8  |      |      |      |      |  4   |  5   |  6   |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |  F9  |  F10 |  F11 |  F12 |      |      |      |  0   |  1   |  2   |  3   |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12(
    KC_F1, KC_F2,  KC_F3,  KC_F4,   _______, KC_NO, KC_NO, _______,  KC_7,    KC_8,  KC_9,  _______,
    KC_F5, KC_F6,  KC_F7,  KC_F8,   _______, KC_NO, KC_NO, _______,  KC_4,    KC_5,  KC_6,  _______,
    KC_F9, KC_F10, KC_F11, KC_F12,  _______, KC_NO, KC_NO, KC_GRAVE, KC_1,    KC_2,  KC_3,  _______,
    KC_NO, KC_NO,  KC_NO,  _______, _______, KC_NO, KC_NO, _______,  _______, KC_NO, KC_NO, KC_NO
  ),

  /* Adjust
   * ,-----------------------------------------------------------------------------------.
   * |      | Reset|      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_ortho_4x12(
    _______, QK_BOOT, _______, _______, _______, KC_NO, KC_NO, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_NO, KC_NO, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_NO, KC_NO, _______, _______, _______, _______, _______,
    KC_NO,   KC_NO,   KC_NO,   _______, _______, KC_NO, KC_NO, _______, _______, KC_NO,   KC_NO,   KC_NO
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      //return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      //return false;
      break;
  }
  return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
        case RAISE:
		case TCONTROL:
		case TSHIFT:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

