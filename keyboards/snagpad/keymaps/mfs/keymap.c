#include QMK_KEYBOARD_H

enum snagpad_layers {
    _HEXPAD,
    _FUNCTIONS,
    _MACROS,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_HEXPAD] = LAYOUT_ortho_5x4(
        KC_C, KC_D, KC_E, KC_F,
        KC_8, KC_9, KC_A, KC_B,
        KC_4, KC_5, KC_6, KC_7,
        KC_0, KC_1, KC_2, KC_3,
        KC_BSPACE, MO(_ADJUST), MO(_ADJUST), KC_ENTER
    ),

    [_FUNCTIONS] = LAYOUT_ortho_5x4(
        KC_F1, KC_F2, KC_F3, KC_F4,
        KC_F5, KC_F6, KC_F7, KC_F8,
        KC_F9, KC_F10, KC_F11, KC_F12,
        KC_F13, KC_F14, KC_F15, KC_F16,
        KC_TRNS, MO(_ADJUST), MO(_ADJUST), KC_TRNS
    ),

    [_MACROS] = LAYOUT_ortho_5x4(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, MO(_ADJUST), MO(_ADJUST), KC_TRNS
    ),

    [_ADJUST] = LAYOUT_ortho_5x4(
        DF(_HEXPAD), DF(_FUNCTIONS), DF(_MACROS), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

