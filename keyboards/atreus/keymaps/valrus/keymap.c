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

enum {
	TD_LBRACKET_ACTIONS,
	TD_RBRACKET_ACTIONS,
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_LBRACKET_ACTIONS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LBRACKET, ACTIONS),
	[TD_RBRACKET_ACTIONS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RBRACKET, ACTIONS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT(
KC_Q, KC_W, KC_E, KC_R, KC_T,           KC_Y, KC_U, KC_I, KC_O, KC_P,
MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LSFT, KC_F), KC_G,           KC_QUOTE, MT(MOD_LSFT, KC_H), MT(MOD_LGUI, KC_J), MT(MOD_LALT, KC_K), MT(MOD_LCTL, KC_L),
KC_Z, KC_X, KC_C, KC_V, KC_B,           KC_SLASH, KC_N, KC_M, KC_COMMA, KC_DOT,
KC_GRAVE, TD(TD_LBRACKET_ACTIONS), TG(NUMERIC), LT(SYMBOLS, KC_TAB), MT(MOD_LGUI, KC_BSPACE), MT(MOD_LCTL, KC_ESCAPE), MT(MOD_LGUI, KC_ENTER), MT(MOD_LSFT, KC_SPACE), LT(SYMBOLS, KC_TAB), TG(NUMERIC), TD(TD_RBRACKET_ACTIONS), LCTL(KC_F3)), 

[SYMBOLS] = LAYOUT(
KC_EXCLAIM, KC_CIRCUMFLEX, KC_HASH, KC_PLUS, KC_PERCENT,           KC_PIPE, KC_AMPERSAND, KC_ASTERISK, KC_DOLLAR, KC_QUESTION,
KC_AT, KC_SCOLON, KC_COLON, KC_MINUS, KC_EQUAL,           KC_GRAVE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
KC_LEFT_ANGLE_BRACKET, KC_LEFT_CURLY_BRACE, KC_LBRACKET, KC_LEFT_PAREN, KC_TILDE,           KC_BSLASH, KC_RIGHT_PAREN, KC_RBRACKET, KC_RIGHT_CURLY_BRACE, KC_RIGHT_ANGLE_BRACKET,
___, ___, ___, ___, KC_DELETE, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_UNDERSCORE, ___, ___, ___, ___), 

[ACTIONS] = LAYOUT(
___, KC_MS_UP, ___, ___, ___,           ___, ___, ___, ___, ___,
KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, ___, ___,           ___, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,
___, ___, ___, ___, RESET,           ___, ___, ___, ___, ___,
___, ___, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN4, KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, ___, ___), 

[NUMERIC] = LAYOUT(
KC_1, KC_2, KC_3, KC_4, KC_5,           KC_6, KC_7, KC_8, KC_9, KC_0,
___, ___, ___, ___, ___,           ___, KC_4, KC_5, KC_6, ___,
___, ___, ___, ___, ___,           ___, KC_1, KC_2, KC_3, ___,
___, ___, ___, ___, ___, ___, ___, ___, KC_0, ___, KC_DOT, ___), 

[GAMING] = LAYOUT(
___, KC_W, ___, ___, ___,           ___, ___, ___, ___, ___,
KC_A, KC_S, KC_D, ___, ___,           ___, KC_H, KC_J, KC_K, KC_L,
___, ___, ___, ___, ___,           ___, ___, ___, ___, ___,
___, ___, ___, KC_LCTL, KC_SPACE, KC_ESCAPE, KC_ENTER, KC_SPACE, KC_LCTL, ___, ___, ___), 

[CAPS] = LAYOUT(
LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T),           LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I), LSFT(KC_O), LSFT(KC_P),
LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G),           ___, LSFT(KC_H), LSFT(KC_J), LSFT(KC_K), LSFT(KC_L),
LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B),           ___, LSFT(KC_N), LSFT(KC_M), ___, ___,
___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___)
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

