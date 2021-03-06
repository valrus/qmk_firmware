#include QMK_KEYBOARD_H
#include "version.h"

#define ___ KC_TRNS
#define _X_ KC_NO

enum layer_codes {
	BASE,
	SYMBOLS,
	ACTIONS,
	NUMERIC,
	GAMING,
	CAPS,
};

enum custom_keycodes {
	EPRM = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox(
KC_F19,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  TG(NUMERIC),
 _X_, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_EQUAL,
 MT(MOD_LCTL, KC_ESCAPE), MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), KC_G,
 _X_, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HYPR,
 TG(ACTIONS), KC_GRAVE, KC_LBRACKET, TG(NUMERIC), LT(SYMBOLS, KC_TAB),
                          KC_F19, KC_HOME,
                               KC_END,
                     MT(MOD_LGUI, KC_BSPACE), MT(MOD_LCTL, KC_ESCAPE), TG(NUMERIC),

 TG(NUMERIC),  KC_6,  KC_7, KC_8, KC_9, KC_0, _X_,
 KC_MINUS, KC_Y, KC_U, KC_I, KC_O, KC_P, _X_,
      KC_QUOTE, MT(MOD_LSFT, KC_H), MT(MOD_LGUI, KC_J), MT(MOD_LALT, KC_K), MT(MOD_LCTL, KC_L), _X_,
 KC_MEH, KC_SLASH, KC_N, KC_M, KC_COMMA, KC_DOT, _X_,
           LT(SYMBOLS, KC_TAB), TG(NUMERIC), KC_RBRACKET, LCTL(KC_F3), TG(GAMING),
                          KC_PGUP, KC_F18,
                               KC_PGDOWN,
                     TG(CAPS), MT(MOD_LGUI, KC_ENTER), MT(MOD_LSFT, KC_SPACE)), 

[SYMBOLS] = LAYOUT_ergodox(
___,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  ___,
 ___, KC_EXCLAIM, KC_CIRCUMFLEX, KC_HASH, KC_PLUS, KC_PERCENT, KC_PLUS,
 ___, KC_AT, KC_SCOLON, KC_COLON, KC_MINUS, KC_EQUAL,
 ___, KC_LEFT_ANGLE_BRACKET, KC_LEFT_CURLY_BRACE, KC_LBRACKET, KC_LEFT_PAREN, KC_TILDE, ___,
 ___, ___, ___, ___, ___,
                          ___, ___,
                               ___,
                     KC_DELETE, KC_LEFT_PAREN, ___,

 ___,  KC_F6,  KC_F7, KC_F8, KC_F9, KC_F10, KC_DELETE,
 KC_PIPE, KC_PIPE, KC_AMPERSAND, KC_ASTERISK, KC_DOLLAR, KC_QUESTION, ___,
      KC_GRAVE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, ___,
 ___, KC_BSLASH, KC_RIGHT_PAREN, KC_RBRACKET, KC_RIGHT_CURLY_BRACE, KC_RIGHT_ANGLE_BRACKET, ___,
           ___, ___, ___, ___, ___,
                          ___, ___,
                               ___,
                     ___, KC_RIGHT_PAREN, KC_UNDERSCORE), 

[ACTIONS] = LAYOUT_ergodox(
KC_F14,  KC_BRIGHTNESS_DOWN,  KC_BRIGHTNESS_UP,  ___,  ___,  ___,  ___,
 KC_F13, ___, KC_MS_UP, ___, ___, ___, ___,
 KC_F12, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, ___, ___,
 KC_F11, ___, ___, ___, ___, ___, ___,
 ___, ___, ___, KC_MS_BTN2, KC_MS_BTN1,
                          RGB_MOD, RGB_HUI,
                               RGB_HUD,
                     KC_MS_BTN3, KC_MS_BTN4, ___,

 RESET,  ___,  ___, ___, ___, ___, KC_F18,
 ___, ___, ___, ___, ___, ___, KC_F17,
      ___, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_F16,
 ___, ___, ___, ___, ___, ___, KC_F15,
           KC_MS_BTN1, KC_MS_BTN2, ___, ___, ___,
                          RGB_VAI, RGB_TOG,
                               RGB_VAD,
                     RGB_MOD, KC_MS_BTN4, KC_MS_BTN3), 

[NUMERIC] = LAYOUT_ergodox(
___,  ___,  ___,  ___,  ___,  ___,  ___,
 ___, KC_1, KC_2, KC_3, KC_4, KC_5, ___,
 ___, ___, ___, ___, ___, ___,
 ___, ___, ___, ___, ___, ___, ___,
 ___, ___, ___, ___, ___,
                          ___, ___,
                               ___,
                     ___, ___, ___,

 ___,  ___,  ___, ___, ___, ___, ___,
 ___, KC_6, KC_7, KC_8, KC_9, KC_0, ___,
      ___, KC_4, KC_5, KC_6, ___, ___,
 ___, ___, KC_1, KC_2, KC_3, ___, ___,
           KC_0, ___, KC_DOT, ___, ___,
                          ___, ___,
                               ___,
                     ___, ___, ___), 

[GAMING] = LAYOUT_ergodox(
___,  ___,  ___,  ___,  ___,  ___,  ___,
 ___, ___, KC_W, ___, ___, ___, ___,
 ___, KC_A, KC_S, KC_D, ___, ___,
 ___, ___, ___, ___, ___, ___, ___,
 ___, ___, ___, ___, KC_LCTL,
                          ___, ___,
                               ___,
                     KC_SPACE, KC_ESCAPE, ___,

 ___,  ___,  ___, ___, ___, ___, ___,
 ___, ___, ___, ___, ___, ___, ___,
      ___, KC_H, KC_J, KC_K, KC_L, ___,
 ___, ___, ___, ___, ___, ___, ___,
           KC_LCTL, ___, ___, ___, ___,
                          ___, ___,
                               ___,
                     ___, KC_ENTER, KC_SPACE), 

[CAPS] = LAYOUT_ergodox(
___,  ___,  ___,  ___,  ___,  ___,  ___,
 ___, LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T), ___,
 ___, LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G),
 ___, LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), ___,
 ___, ___, ___, ___, ___,
                          ___, ___,
                               ___,
                     ___, ___, ___,

 ___,  ___,  ___, ___, ___, ___, ___,
 ___, LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I), LSFT(KC_O), LSFT(KC_P), ___,
      ___, LSFT(KC_H), LSFT(KC_J), LSFT(KC_K), LSFT(KC_L), ___,
 ___, ___, LSFT(KC_N), LSFT(KC_M), ___, ___, ___,
           ___, ___, ___, ___, ___,
                          ___, ___,
                               ___,
                     ___, ___, ___)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
		case EPRM:
			eeconfig_init();
			return false;
		}
	}
	return true;
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

layer_state_t layer_state_set_user(layer_state_t state) {
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();

	uint8_t layer = biton32(state);
	switch(layer) {
		case BASE:
			break;
		case SYMBOLS:
			ergodox_right_led_2_on();
			break;
		case ACTIONS:
			ergodox_right_led_2_on();
			break;
		case NUMERIC:
			ergodox_right_led_1_on();
			ergodox_right_led_3_on();
			break;
		case GAMING:
			ergodox_right_led_1_on();
			ergodox_right_led_2_on();
			ergodox_right_led_3_on();
			break;
		case CAPS:
			ergodox_right_led_3_on();
			break;
	}
	return state;
};

