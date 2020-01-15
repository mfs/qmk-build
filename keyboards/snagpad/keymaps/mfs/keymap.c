#include QMK_KEYBOARD_H

// flip layout to 5 across by 4 down
// cable on the left
#define LAYOUT_ortho_4x5( \
    K00, K01, K02, K03, K04, \
    K10, K11, K12, K13, K14, \
    K20, K21, K22, K23, K24, \
    K30, K31, K32, K33, K34 \
) { \
    { K30,   K20,   K10,   K00 }, \
    { K31,   K21,   K11,   K01 }, \
    { K32,   K22,   K12,   K02 }, \
    { K33,   K23,   K13,   K03 }, \
    { K34,   K24,   K14,   K04 } \
}

#define SECENT LT(_SECONDARY, KC_PENT)

enum snagpad_layers {
    _PRIMARY,
    _SECONDARY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_PRIMARY] = LAYOUT_ortho_4x5(
        KC_P7, KC_P8,   KC_P9,  KC_PMNS, KC_PPLS,
        KC_P4, KC_P5,   KC_P6,  KC_PSLS, KC_PAST,
        KC_P1, KC_P2,   KC_P3,  KC_F5,   KC_F6,
        KC_P0, KC_PDOT, SECENT, KC_F7,   KC_F8
    ),

    [_SECONDARY] = LAYOUT_ortho_4x5(
        KC_TRNS, KC_TRNS, RESET,   KC_F1,   KC_F2,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

