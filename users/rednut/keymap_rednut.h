// #include QMK_KEYBOARD_H (should be done in including source)

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
	_L_QWERTY,
	_L_GAME,
};

enum custom_keycodes {
	_K_REDNUT = SAFE_RANGE,
	_K_GAME,
	_K_LOWER,
	_K_RAISE,
	_K_ADJUST,
	_K_RGBRST,
	_K_MACRO1,
	_K_MACRO2,
	_K_MACRO3,
	_K_MACRO4,
};

#define KC_RDNT		DF(_L_REDNUT)
#define KC_QWER		DF(_L_QWERTY)
#define KC_GAME		DF(_L_GAME)

#define KC_LOWE		_K_LOWER
#define KC_RAIS		_K_RAISE

#define KC_MCR1		_K_MACRO1
#define KC_MCR2		_K_MACRO2
#define KC_MCR3		_K_MACRO3
#define KC_MCR4		_K_MACRO4

#define KC_			KC_TRNS
#define KC_xxxx		KC_NO
#define KC_xxxxx	KC_NO

#define KC_RST		RESET

#define KC_RRST		_K_RGBRST
#define KC_RTOG		RGB_TOG
#define KC_RHUI		RGB_HUI
#define KC_RHUD		RGB_HUD
#define KC_RSAI		RGB_SAI
#define KC_RSAD		RGB_SAD
#define KC_RVAI		RGB_VAI
#define KC_RVAD		RGB_VAD
#define KC_RMOD		RGB_MOD

#define KC_BTOG		BL_TOGG
#define KC_BLI		BL_INC
#define KC_BLD		BL_DEC
#define KC_BRTG		BL_BRTG

#define KC_cTAB		LCTL_T(KC_TAB)

#define KC_aHNK		LALT_T(KC_HENK)
#define KC_cSPC		LCTL_T(KC_SPACE)
#define KC_lDEL		LT(_L_LOWER, KC_DELETE)

#define KC_rBS		LT(_L_RAISE, KC_BSPC)
#define KC_sENT		LSFT_T(KC_ENTER)
#define KC_wMHN		LGUI_T(KC_MHEN)

#define KC_CAD		LCTL(LALT(KC_DEL))

#include "macro_str.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Rednut Base Layout (modified Eucalyn)
	[ _L_REDNUT ] = LAYOUT_kc(
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		ESC , Q  , W  , E  ,COMM,DOT ,              M  , R  , D  , Y  , P  ,BSLS,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		cTAB, A  , O  , U  , I  ,SCLN,              G  , T  , K  , S  , N  ,QUOT,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		LSFT, Z  , X  , C  , V  , F  ,              B  , H  , J  , L  ,SLSH,EQL ,
		//--+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
		/*               */ aHNK,cSPC,lDEL,   rBS ,sENT,wMHN
		//                 +----+----+----+  +----+----+----+
		),

	// LOWER
	[ _L_LOWER ] = LAYOUT_kc(
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		GRV ,EXLM, AT ,HASH,DLR ,PERC,             CIRC,AMPR,ASTR,LPRN,RPRN,PIPE,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		LCTL, 1  , 2  , 3  , 4  , 5  ,              6  , 7  , 8  , 9  , 0  ,MINS,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		LSFT,xxxx, X  ,xxxx,xxxx,xxxx,             xxxx,UNDS,COMM,DOT ,QUES,PLUS,
		//--+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
		/*               */ LALT,LCTL,LOWE,   RAIS,LSFT,LGUI
		//                 +----+----+----+  +----+----+----+
		),

	// RAISE
	[ _L_RAISE ] = LAYOUT_kc(
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		GRV , F1 , F2 , F3 , F4 , F5 ,             xxxx,xxxx,xxxx,LCBR,RCBR,VOLU,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		LCTL, F6 , F7 , F8 , F9 ,F10 ,             PSCR,xxxx, UP ,LBRC,RBRC,VOLD,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		LSFT,F11 ,F12 ,xxxx,xxxx,xxxx,             HOME,LEFT,DOWN,RGHT,END ,MUTE,
		//--+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
		/*               */ LALT,LCTL,LOWE,   RAIS,LSFT,LGUI
		//                 +----+----+----+  +----+----+----+
		),

	// ADJUST (LOWER + RAISE)
	[ _L_ADJUST ] = LAYOUT_kc(
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		RST ,RRST,xxxx,xxxx,xxxx,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,CAD ,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		GAME,RTOG,RHUI,RSAI,RVAI,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		RDNT,RMOD,RHUD,RSAD,RVAD,xxxx,             xxxx,xxxx,xxxx,xxxx,xxxx,xxxx,
		//--+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
		/*               */ MCR1,MCR2,LOWE,   RAIS,MCR3,MCR4
		//                 +----+----+----+  +----+----+----+
		),

	// GAME
	[ _L_GAME ] = LAYOUT_kc(
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		GRV ,xxxx,xxxx, S  ,xxxx,xxxx,             xxxx,xxxx, UP ,xxxx,xxxx,VOLU,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		GAME,xxxx, A  , S  , X  ,xxxx,             xxxx,LEFT, UP ,RGHT,xxxx,VOLD,
		//--+----+----+----+----+----+            +----+----+----+----+----+----+
		RDNT,xxxx, A  , Z  , X  ,xxxx,             xxxx,LEFT,DOWN,RGHT,xxxx,MUTE,
		//--+----+----+----+----+----+----+  +----+----+----+----+----+----+----+
		/*               */ RSFT, Q  ,xxxx,   xxxx, W  ,ENT
		//                 +----+----+----+  +----+----+----+
		),
};

int RGB_current_mode;

void persistent_default_layer_set( uint16_t default_layer )
{
	eeconfig_update_default_layer( default_layer );
	default_layer_set( default_layer );
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB( uint8_t layer1, uint8_t layer2, uint8_t layer3 )
{
	if ( IS_LAYER_ON( layer1 ) && IS_LAYER_ON( layer2 ) )
	{
#ifdef RGBLIGHT_ENABLE
		rgblight_mode( RGB_current_mode );
#endif
		layer_on( layer3 );
	}
	else
	{
		layer_off( layer3 );
	}
}

void matrix_init_user( void )
{
#ifdef RGBLIGHT_ENABLE
	RGB_current_mode = rgblight_config.mode;
#endif
	//SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
	iota_gfx_init( !has_usb() );   // turns on the display
#endif
}

// SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_logo( void );
void set_keylog( uint16_t keycode, keyrecord_t *record );
const char *read_keylog( void );
const char *read_keylogs( void );

#define S_STR_UNKNOWN	"UNKNOWN"

static char s_layer_state_str[ 24 ];
static const char *read_layer_state( void )
{
	const char *str_dl;
	const char *str_l;

#define TMP_CASE( layer, dst ) \
  case _L_##layer : \
	dst = #layer ; \
	break

	// default layer
	switch ( get_highest_layer( default_layer_state ) )
	{
		TMP_CASE( REDNUT, str_dl );
		TMP_CASE( GAME, str_dl );
		TMP_CASE( QWERTY, str_dl );

	  default:
		str_dl = S_STR_UNKNOWN;
	}

	// layer
	switch ( get_highest_layer( layer_state ) )
	{
		TMP_CASE( LOWER, str_l );
		TMP_CASE( RAISE, str_l );
		TMP_CASE( ADJUST, str_l );

	  default:
		if ( layer_state == 0 )
		{
			str_l = NULL;
		}
		else
		{
			str_l = S_STR_UNKNOWN;
		}
	}
#undef TMP_CASE

	if ( str_l == NULL )
	{
		snprintf( s_layer_state_str, sizeof( s_layer_state_str ),
				  "Layer: %s", str_dl );
	}
	else
	{
		snprintf( s_layer_state_str, sizeof( s_layer_state_str ),
				  "Layer: %s[%s]", str_dl, str_l );
	}

	return s_layer_state_str;
}

#ifdef RGBLIGHT_ENABLE
static char s_rgb_info_str[ 24 ];
static const char *read_rgb_info( void )
{
	if ( rgblight_config.enable )
	{
		snprintf( s_rgb_info_str, sizeof( s_rgb_info_str ),
				  "LED%02d h%03d s%03d v%03d",
				  rgblight_config.mode,
				  rgblight_config.hue,
				  rgblight_config.sat,
				  rgblight_config.val);
	}
	else
	{
		strcpy( s_rgb_info_str, "LED OFF" );
	}
	return s_rgb_info_str;
}
#endif

static char s_host_led_state_str[ 24 ];
static const char *read_host_led_state( void )
{
	uint8_t leds;

	leds = host_keyboard_leds();
	snprintf( s_host_led_state_str, sizeof( s_host_led_state_str ),
			  "%s %s %s",
			 ( leds & ( 1 << USB_LED_NUM_LOCK ) ) ? "[NUM]" : " num ",
			 ( leds & ( 1 << USB_LED_CAPS_LOCK ) ) ? "[CAPS]" : " caps ",
			 ( leds & ( 1 << USB_LED_SCROLL_LOCK ) ) ? "[SCLK]" : " sclk " );

	return s_host_led_state_str;
}

// const char *read_mode_icon(bool swap);
// const char *read_timelog(void);
// void set_timelog(void);

void matrix_scan_user( void )
{
	iota_gfx_task();
}

void matrix_render_user( struct CharacterMatrix *matrix )
{
	if ( is_master )
	{
		// If you want to change the display of OLED, you need to change here
		matrix_write_ln( matrix, read_layer_state() );
		matrix_write_ln( matrix, read_host_led_state() );
		matrix_write_ln( matrix, read_keylog() );
	} else {
#ifdef RGBLIGHT_ENABLE
		matrix_write_ln( matrix, read_rgb_info() );
#else
		matrix_write( matrix, read_logo() );
#endif
	}
}

void matrix_update( struct CharacterMatrix *dest,
					const struct CharacterMatrix *source )
{
	if ( memcmp( dest->display, source->display, sizeof( dest->display ) ) )
	{
		memcpy( dest->display, source->display, sizeof( dest->display ) );
		dest->dirty = true;
	}
}

void iota_gfx_task_user( void )
{
	struct CharacterMatrix matrix;

	matrix_clear( &matrix );
	matrix_render_user( &matrix );
	matrix_update( &display, &matrix );
}
#endif //SSD1306OLED

bool process_record_user( uint16_t keycode, keyrecord_t *record )
{
	if ( record->event.pressed )
	{
#ifdef SSD1306OLED
		set_keylog( keycode, record );
		// set_timelog();
#endif
	}

	switch ( keycode )
	{

#define CASE_LAYER( X ) \
  case _K_##X: \
	if ( record->event.pressed ) \
	{ \
		layer_on( _L_##X ); \
		update_tri_layer_RGB( _L_LOWER, _L_RAISE, _L_ADJUST ); \
	} \
	else \
	{ \
		layer_off(_L_##X); \
		update_tri_layer_RGB( _L_LOWER, _L_RAISE, _L_ADJUST ); \
	} \
	return false

#define CASE_MACRO( M ) \
  case _K_MACRO##M: \
	if ( record->event.pressed ) \
	{ \
		SEND_STRING( MACRO##M##_STR ); \
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
		if ( record->event.pressed )
		{
			rgblight_mode( RGB_current_mode );
			rgblight_step();
			RGB_current_mode = rgblight_config.mode;
		}
#endif
		return false;

	  case _K_RGBRST:
#ifdef RGBLIGHT_ENABLE
		if ( record->event.pressed )
		{
			eeconfig_update_rgblight_default();
			rgblight_enable();
			RGB_current_mode = rgblight_config.mode;
		}
#endif
		break;
	}

#undef CASE_LAYER
#undef CASE_MACRO

	return true;
}
