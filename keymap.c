#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"
#include "version.h"
#include "mousekey.h"


enum layers {
    L_BASE,      // default layer
    L_FUNC,      // symbols
 //   L_WIN,       // for Windows
    L_SYS,      // system
};

#define _______ KC_TRNS

enum custom_keycodes {
    C_PLACEHOLDER = SAFE_RANGE, // can always be here
    C_ESC_TILDE,
    C_VRSN,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc ~  |   1  |   2  |   3  |   4  |   5  |      |           |   =  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| 英数 |           | かな |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | LAlt |  ~L1 |                                       | ~L1  |   [  |   ]  | RAlt |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  ~L2 |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|Backsp|------|       |------| RGui |Enter |
 *                                 |/LGui |ace   |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[L_BASE] = KEYMAP(  // layer 0 : default
        // left hand
        C_ESC_TILDE,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       _______,
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       _______,
        KC_LCTL,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LANG2,
        _______,        _______,    _______,    KC_LALT,    MO(L_FUNC),
                                                                        MO(L_SYS),  _______,
                                                                                    _______,
                                                        GUI_T(KC_SPC),  KC_BSPC,    _______,
        // right hand
        KC_EQL,         KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
        _______,        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
                        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LANG1,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                    MO(L_FUNC), KC_LBRC,    KC_RBRC,    KC_RALT,    _______,
        _______,        _______,
        _______,
        _______,        KC_RGUI,    KC_ENT
    ),

/* Keymap 1: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    '   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | BTNL |  MSU | BTNR |  WHD |      |           |      |      | HOME |  UP  | PGUP |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MACCL0|  MSL |  MSD |  MSR |  WHU |------|           |------|      | LEFT | DOWN | RIGHT|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  WHR |  WHL |      |      |           |      |      |  END |      | PGDN |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// FUNCTION
[L_FUNC] = KEYMAP(
       // left hand
       KC_GRV,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      _______,
       _______, _______,    KC_MS_BTN1, KC_MS_U,    KC_MS_BTN2, KC_MS_WH_DOWN, _______,
       _______, KC_MS_ACCEL0, KC_MS_L,  KC_MS_D,    KC_MS_R,    KC_MS_WH_UP,
       _______, _______,    _______, KC_MS_WH_RIGHT, KC_MS_WH_LEFT, _______, _______,
       _______, _______,    _______,    _______,    _______,
                                                    _______,    _______,
                                                                _______,
                                        _______,    _______,    _______,
       // right hand
       _______, KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
       _______, _______,    KC_HOME,    KC_UP,      KC_PGUP,    _______,    _______,
                _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,
       _______, _______,    KC_END,     _______,    KC_PGDN,    _______,    _______,
                            _______,    _______,    _______,    _______,    _______,
       _______, _______,
       _______,
       _______, _______,    _______
),


/* Keymap 2: System Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Version|      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RESET|      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYSTEM
[L_SYS] = KEYMAP(
       // left hand
       C_VRSN,  _______,    _______,    _______,    _______,    _______,    _______,
       _______, _______,    _______,    _______,    _______,    _______,    _______,
       _______, _______,    _______,    _______,    _______,    _______,
       _______, _______,    _______,    _______,    _______,    _______,    _______,
         RESET, _______,    _______,    _______,    _______,
                                        _______,    _______,
                                                    _______,
                            _______,    _______,    _______,
       // right hand
       _______, _______,    _______,    _______,    _______,    _______,    _______,
       _______, _______,    _______,    _______,    _______,    _______,    _______,
                _______,    _______,    _______,    _______,    _______,    _______,
       _______, _______,    _______,    _______,    _______,    _______,    _______,
                            _______,    _______,    _______,    _______,    _______,
       _______, _______,
       _______,
       _______, _______,    _______
),
};

const uint16_t PROGMEM fn_actions[] = {
};



// 前回の更新時間
uint32_t last_updated_time;

#define MOUSE_KEY_START     KC_MS_UP

// マウスキーを長押しし始めた時刻
uint32_t last_mouse_key_time;
// 押下中のマウスキーの組み合わせ
uint32_t mouse_key_flags;



// 更新間隔 (50fps)
#define UPDATE_INTERVAL 1000 / 50

#define LED_BRIGHTNESS  120
#define NUM_LED         3

uint8_t led_brightness[ NUM_LED ];



// 50Hz で呼ばれます
static void fixed_update(void) {
    uint32_t now = timer_read32();

    // LED をフェードアウト
    uint32_t dec = 10;
    for (uint8_t i = 0; i < NUM_LED; ++i) {
        if (led_brightness[ i ] > 0) {
            if (led_brightness[ i ] > dec) {
                ergodox_right_led_set(i + 1, led_brightness[ i ]);
                led_brightness[ i ] -= dec;
            } else {
                ergodox_right_led_off(i + 1);
            }
        }
    }

    // マウスキーの加速
    if (mouse_key_flags != 0) {
        uint32_t dt = now - last_mouse_key_time;
        float r = dt / (1000 * 2.0f);       // 1000ms * sec
        r = r * r;
        if (r > 1.0f) {
            r = 1.0f;
        }
        uint8_t n = (uint8_t)(MOUSEKEY_MAX_SPEED + 30 * r);
        mk_max_speed        = n;

        led_brightness[ 0 ] = (uint8_t)(LED_BRIGHTNESS * r);
        ergodox_right_led_on(0 + 1);
    }

    return;
}



// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    uint32_t now = timer_read32();
    last_mouse_key_time = now;
    last_updated_time   = now;

    mouse_key_flags     = 0;
    mk_max_speed        = MOUSEKEY_MAX_SPEED;
    mk_wheel_max_speed  = 1;

    for (int i = 0; i < NUM_LED; ++i) {
        led_brightness[ i ] = 0;
    }
}


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        led_brightness[ 1 ] = LED_BRIGHTNESS;
        ergodox_right_led_on(1 + 1);
    }

    uint32_t now = timer_read32();

    switch (keycode) {
    case C_VRSN:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        return false;
    case C_ESC_TILDE:
        if (record->event.pressed) {
            // なぜか has_oneshot_mods_timed_out() が未定義エラーになる
            //int oneshot = ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out());
            int oneshot_shift = get_oneshot_mods() & MOD_BIT(KC_LSFT);
            int shift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            // SHIFT を押していたらチルダ ~
            if (shift || oneshot_shift) {
                clear_oneshot_mods();
                // !shift の場合、つまり oneshot mods の場合は自前でシフトを押して後で戻す
                if (!shift) {
                    register_code(KC_LSFT);
                }

                // SHIFT + ` = ~
                register_code(KC_GRV);
                unregister_code(KC_GRV);

                if (!shift) {
                    unregister_code(KC_LSFT);
                }
            } else { // SHIFT を押していなければ ESC
                register_code(KC_ESC);
                unregister_code(KC_ESC);
            }
        }
        return false;
    case KC_MS_UP ... KC_MS_RIGHT:
    //case KC_MS_WH_UP ... KC_MS_WH_RIGHT:
        if (record->event.pressed) {
            // 初回
            if (mouse_key_flags == 0) {
                last_mouse_key_time = now;
            }
            mouse_key_flags     |= 1 << (keycode - MOUSE_KEY_START);
        } else {
            mouse_key_flags     &= ~(1 << (keycode - MOUSE_KEY_START));
            // 終了
            if (mouse_key_flags == 0) {
                mk_max_speed        = MOUSEKEY_MAX_SPEED;
            }
        }
        break;
    }

    return true;
}


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint32_t t = timer_read32();
    if (t < last_updated_time) {
        // カウンターのオーバーフロー時のごまかし
        last_updated_time   = t;
    } else {
        uint32_t td = t - last_updated_time;
        if (td >= UPDATE_INTERVAL) {
            fixed_update();
            last_updated_time += UPDATE_INTERVAL;
        }
    }
}



