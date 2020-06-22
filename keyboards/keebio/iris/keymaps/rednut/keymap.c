#include QMK_KEYBOARD_H

// redefine LAYOUT_kc (disable 1st row and LT4/RT4)
#undef LAYOUT_kc
#define LAYOUT_kc( \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,           R30, R31, R32, R33, R34, R35, \
                        LT1, LT2, LT3, RT3, RT2, RT1 \
    ) \
    LAYOUT( \
        KC_xxxxx, KC_xxxxx, KC_xxxxx, KC_xxxxx, KC_xxxxx, KC_xxxxx,                     KC_xxxxx, KC_xxxxx, KC_xxxxx, KC_xxxxx, KC_xxxxx, KC_xxxxx, \
        KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,                     KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
        KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25,                     KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
        KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_xxxxx, KC_xxxxx, KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35, \
                                                KC_##LT1, KC_##LT2, KC_##LT3, KC_##RT3, KC_##RT2, KC_##RT1 \
    )

#include "keymap_rednut.h"
