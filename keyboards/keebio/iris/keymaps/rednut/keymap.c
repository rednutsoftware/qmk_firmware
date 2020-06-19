#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

//#define _USE_QWERTY

enum custom_layers {
  _L_REDNUT = 0,
#ifdef _USE_QWERTY
  _L_QWERTY,
#endif
  _L_LOWER,
  _L_RAISE,
  _L_ADJUST,
  _L_GAME,
};

enum custom_keycodes {
  _K_REDNUT = SAFE_RANGE,
  _K_QWERTY,
  _K_GAME,
  _K_LOWER,
  _K_RAISE,
  _K_ADJUST,
  _K_MACRO1,
  _K_MACRO2,
  _K_MACRO3,
  _K_MACRO4,
};

#define KC_RDNT DF(_L_REDNUT)
#define KC_QWER DF(_L_QWERTY)
#define KC_GAME DF(_L_GAME)

#define KC_LOWE _K_LOWER
#define KC_RAIS _K_RAISE

#define KC_MCR1 _K_MACRO1
#define KC_MCR2 _K_MACRO2
#define KC_MCR3 _K_MACRO3
#define KC_MCR4 _K_MACRO4

#define KC_     KC_TRNS
#define KC_xxxx KC_NO


#define KC_RST  RESET

#define KC_cTAB LCTL_T(KC_TAB)

#define KC_aHNK LALT_T(KC_HENK)
#define KC_cSPC LCTL_T(KC_SPACE)
#define KC_lDEL LT(_L_LOWER, KC_DELETE)

#define KC_rBS  LT(_L_RAISE, KC_BSPC)
#define KC_sENT LSFT_T(KC_ENTER)
#define KC_wMHN LGUI_T(KC_MHEN)

#define KC_CAD  LCTL(LALT(KC_DEL))

#include "macro_str.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Rednut Base Layout (modified Eucalyn)
  [_L_REDNUT] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     ESC , Q  , W  , E  ,COMM,DOT ,              M  , R  , D  , Y  , P  ,BSLS,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     cTAB, A  , O  , U  , I  ,SCLN,              G  , T  , K  , S  , N  ,QUOT,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
     LSFT, Z  , X  , C  , V  , F  ,xxxx,   xxxx, B  , H  , J  , L  ,SLSH,EQL ,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         aHNK,cSPC,lDEL,   rBS ,sENT,wMHN
                      //+----+----+----+  +----+----+----+
  ),

  // LOWER
  [_L_LOWER] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     GRV ,EXLM, AT ,HASH,DLR ,PERC,             CIRC,AMPR,ASTR,LPRN,RPRN,PIPE,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     LCTL, 1  , 2  , 3  , 4  , 5  ,              6  , 7  , 8  , 9  , 0  ,MINS,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
     LSFT,xxxx, X  ,xxxx,xxxx,xxxx,xxxx,   xxxx,xxxx,UNDS,COMM,DOT ,QUES,PLUS,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         LALT,LCTL,LOWE,   RAIS,LSFT,LGUI 
                      //+----+----+----+  +----+----+----+
  ),

  // RAISE
  [_L_RAISE] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     GRV , F1 , F2 , F3 , F4 , F5 ,             xxxx,xxxx,xxxx,LCBR,RCBR,VOLU,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     LCTL, F6 , F7 , F8 , F9 ,F10 ,             PSCR,xxxx, UP ,LBRC,RBRC,VOLD,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
     LSFT,F11 ,F12 ,xxxx,xxxx,xxxx,xxxx,   xxxx,HOME,LEFT,DOWN,RGHT,END ,MUTE,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         LALT,LCTL,LOWE,   RAIS,LSFT,LGUI 
                      //+----+----+----+  +----+----+----+
  ),

  // ADJUST (LOWER + RAISE)
  [_L_ADJUST] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     RST ,xxxx,xxxx,xxxx,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,CAD ,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     GAME,xxxx,xxxx,xxxx,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
     RDNT,xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,   xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         MCR1,MCR2,LOWE,   RAIS,MCR3,MCR4 
                      //+----+----+----+  +----+----+----+
  ),

#ifdef _USE_QWERTY
  // default base (modified)
  [_L_QWERTY] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     GRV , 1  , 2  , 3  , 4  , 5  ,              6  , 7  , 8  , 9  , 0  ,MINS,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     ESC , Q  , W  , E  , R  , T  ,              Y  , U  , I  , O  , P  ,BSLS,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     cTAB, A  , S  , D  , F  , G  ,              H  , J  , K  , L  ,SCLN,QUOT,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
     LSFT, Z  , X  , C  , V  , B  ,LBRC,   RBRC, N  , M  ,COMM,DOT ,SLSH,EQL ,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         aHNK,cSPC,lDEL,   rBS ,sENT,wMHN
                      //+----+----+----+  +----+----+----+
  ),
#endif

  // GAME
  [_L_GAME] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     GRV ,xxxx,xxxx, S  ,xxxx,xxxx,             xxxx,xxxx, UP ,xxxx,xxxx,VOLU,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     GAME,xxxx, A  , S  , X  ,xxxx,             xxxx,LEFT, UP ,RGHT,xxxx,VOLD,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
     RDNT,xxxx, A  , Z  , X  ,xxxx,xxxx,   xxxx,xxxx,LEFT,DOWN,RGHT,xxxx,MUTE,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         RSFT, Q  ,xxxx,   xxxx, W  ,ENT 
                      //+----+----+----+  +----+----+----+
  ),

};

#define CASE_LAYER( X ) \
    case _K_##X: \
      if (record->event.pressed) { \
        layer_on(_L_##X); \
        update_tri_layer(_L_LOWER, _L_RAISE, _L_ADJUST); \
      } else { \
        layer_off(_L_##X); \
        update_tri_layer(_L_LOWER, _L_RAISE, _L_ADJUST); \
      } \
      return false

#define CASE_MACRO( M ) \
    case _K_MACRO##M: \
      if (record->event.pressed) { \
        SEND_STRING(MACRO##M##_STR); \
      } \
      return false

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    CASE_LAYER( LOWER );

    CASE_LAYER( RAISE );

    CASE_MACRO( 1 );

    CASE_MACRO( 2 );

    CASE_MACRO( 3 );

    CASE_MACRO( 4 );
  }

  return true;
}
