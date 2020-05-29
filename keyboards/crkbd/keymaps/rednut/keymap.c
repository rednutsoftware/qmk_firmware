#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _L_REDNUT = 0,
  _L_LOWER,
  _L_RAISE,
  _L_ADJUST,
};

enum custom_keycodes {
  _K_LOWER = SAFE_RANGE,
  _K_RAISE,
  _K_ADJUST,
  _K_RGBRST,
  _K_MACRO1,
  _K_MACRO2,
  _K_MACRO3,
  _K_MACRO4,
};

#define KC_LOWE  _K_LOWER
#define KC_RAIS  _K_RAISE

#define KC_MCR1  _K_MACRO1
#define KC_MCR2  _K_MACRO2
#define KC_MCR3  _K_MACRO3
#define KC_MCR4  _K_MACRO4

#define KC_      KC_TRNS
#define KC_xxxx  KC_NO

#define KC_RST   RESET

#define KC_LRST  _K_RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD

#define KC_cTAB LCTL_T(KC_TAB)

#define KC_aHNK  LALT_T(KC_HENK)
#define KC_cSPC  LCTL_T(KC_SPACE)
#define KC_lDEL  LT(_L_LOWER, KC_DELETE)

#define KC_rBS   LT(_L_RAISE, KC_BSPC)
#define KC_sENT  LSFT_T(KC_ENTER)
#define KC_wMHN  LGUI_T(KC_MHEN)

#define KC_CAD   LCTL(LALT(KC_DEL))

#include "macro_str.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Rednut Base Layout (modified Eucalyn)
  [_L_REDNUT] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     ESC , Q  , W  , E  ,COMM,DOT ,              M  , R  , D  , Y  , P  ,BSLS,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     cTAB, A  , O  , U  , I  ,SCLN,              G  , T  , K  , S  , N  ,QUOT,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     LSFT, Z  , X  , C  , V  , F  ,              B  , H  , J  , L  ,SLSH,EQL ,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         aHNK,cSPC,lDEL,   rBS ,sENT,wMHN
                      //+----+----+----+  +----+----+----+
  ),

  // LOWER
  [_L_LOWER] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     GRV ,EXLM, AT ,HASH,DLR ,PERC,             CIRC,AMPR,ASTR,LPRN,RPRN,PIPE,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     LCTL, 1  , 2  , 3  , 4  , 5  ,              6  , 7  , 8  , 9  , 0  ,MINS,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     LSFT,xxxx, X  ,xxxx,xxxx,xxxx,             xxxx,UNDS,COMM,DOT ,QUES,PLUS,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         LALT,LCTL,LOWE,   RAIS,LSFT,LGUI 
                      //+----+----+----+  +----+----+----+
  ),

  // RAISE
  [_L_RAISE] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     GRV , F1 , F2 , F3 , F4 , F5 ,             xxxx,xxxx,xxxx,LCBR,RCBR,VOLU,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     LCTL, F6 , F7 , F8 , F9 ,F10 ,             PSCR,xxxx, UP ,LBRC,RBRC,VOLD,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     LSFT,F11 ,F12 ,xxxx,xxxx,xxxx,             HOME,LEFT,DOWN,RGHT,END ,MUTE,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         LALT,LCTL,LOWE,   RAIS,LSFT,LGUI 
                      //+----+----+----+  +----+----+----+
  ),

  // ADJUST (LOWER + RAISE)
  [_L_ADJUST] = LAYOUT_kc(
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     RST ,LRST,xxxx,xxxx,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,CAD ,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     LTOG,LHUI,LSAI,LVAI,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
  //+----+----+----+----+----+----+            +----+----+----+----+----+----+
     LMOD,LHUD,LSAD,LVAD,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
  //+----+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
                         MCR1,MCR2,LOWE,   RAIS,MCR3,MCR4 
                      //+----+----+----+  +----+----+----+
  ),

};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
#ifdef RGBLIGHT_ENABLE
    rgblight_mode(RGB_current_mode);
#endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
#endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
  iota_gfx_init(!has_usb());   // turns on the display
#endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {

#define CASE_LAYER( X ) \
    case _K_##X: \
      if (record->event.pressed) { \
        layer_on(_L_##X); \
        update_tri_layer_RGB(_L_LOWER, _L_RAISE, _L_ADJUST); \
      } else { \
        layer_off(_L_##X); \
        update_tri_layer_RGB(_L_LOWER, _L_RAISE, _L_ADJUST); \
      } \
      return false

#define CASE_MACRO( M ) \
    case _K_MACRO##M: \
      if (record->event.pressed) { \
        SEND_STRING(MACRO##M##_STR); \
      } \
      return false

    CASE_LAYER( LOWER );

    CASE_LAYER( RAISE );

    CASE_MACRO( 1 );

    CASE_MACRO( 2 );

    CASE_MACRO( 3 );

    CASE_MACRO( 4 );

    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case _K_RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
