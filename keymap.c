#include "ergodox.h"
#include "debug.h"
#include "process_tap_dance.h"
#include "action_layer.h"
#include "mousekey.h"
#include "version.h"

#define _______         KC_TRNS
#define XXXXXXX         KC_NO



enum {
    L_BASE,      // default layer
    L_CODE,       // navigation
    L_NAV,       // navigation
 //   L_WIN,       // Windows
    L_SYS,      // system
};

// custom keycodes
enum {
    C_PLACEHOLDER = SAFE_RANGE, // can always be here
    C_ESC_TILDE,
    C_VRSN,

    C_WH_START,
    C_WH_U      = C_WH_START,
    C_WH_D,
    C_WH_L,
    C_WH_R,
};

// custom tap dance
enum {
    CT_LSFT,
    CT_RSFT,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc~  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   BS   |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  | Home |           | PgUp |   Y  |   U  |   I  |   O  |   P  |    \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCtl  |A/LCtl|   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;/RCtl|    '   |
 * |--------+------+------+------+------+------|  End |           | PgDn |------+------+------+------+------+--------|
 * |  LSft  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  RSft  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | ~LNav| LSft |                                       |~LCode| ~LNav|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ~LSys|      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space| 英数 |------|       |------| かな | Enter|
 *                                 |      | /LGui| LAlt |       | RAlt | /RGui|      |
 *                                 `--------------------'       `--------------------'
 */
[L_BASE] = KEYMAP(
        // left hand
        C_ESC_TILDE,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       XXXXXXX,
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_HOME,
        KC_LCTL, LCTL_T(KC_A),      KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_END,
        XXXXXXX,        XXXXXXX,    XXXXXXX,    MO(L_NAV), KC_LSFT,
                                                                        MO(L_SYS),  XXXXXXX,
                                                                                    XXXXXXX,
                                                            KC_SPC,     LGUI_T(KC_LANG2),   KC_LALT,
        // right hand
        XXXXXXX,        KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_PGUP,        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
                        KC_H,       KC_J,       KC_K,       KC_L,       RCTL_T(KC_SCLN),KC_QUOT,
        KC_PGDN,        KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                    MO(L_CODE), MO(L_NAV),  XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,        XXXXXXX,
        XXXXXXX,
        KC_RALT,        RGUI_T(KC_LANG1),   KC_ENT
    ),

/* Keymap 1: Code Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    `   |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |   Del  |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   {  |   }  |   _  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   [  |   ]  |   -  |   =  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_CODE] = KEYMAP(
       // left hand
       KC_GRV,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,
       _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
       _______, _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
       _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
       XXXXXXX, XXXXXXX,    XXXXXXX,    _______,    _______,
                                                                _______,    _______,
                                                                            _______,
                                                    _______,    _______,    _______,
       // right hand
       KC_F12,  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL,
       _______, XXXXXXX,    S(KC_LBRC), S(KC_RBRC), S(KC_MINS), S(KC_EQL),  XXXXXXX,
                XXXXXXX,    KC_LBRC,    KC_RBRC,    KC_MINS,    KC_EQL,     XXXXXXX,
       _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,
                            _______,    _______,    _______,    _______,    _______,
       _______, _______,
       _______,
       _______, _______,    _______
),

/* Keymap 2: Navigation Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |   Del  |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  MsU |      |      |      |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | BtnL |  MsL |  MsD |  MsR | BtnR |------|           |------|      | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  WhD |  WhU |  WhR |  WhL |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Power|      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_NAV] = KEYMAP(
       // left hand
       KC_GRV,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F11,
       _______, XXXXXXX,    XXXXXXX,    KC_MS_U,    XXXXXXX,    XXXXXXX,    _______,
       _______, KC_BTN1,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_BTN2,
       _______, C_WH_D,     C_WH_U,     C_WH_R,     C_WH_L,     XXXXXXX,    _______,
       XXXXXXX, XXXXXXX,    XXXXXXX,    _______,    _______,
                                                                _______,    _______,
                                                                            _______,
                                                    _______,    _______,    _______,
       // right hand
       KC_F12,  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL,
       _______, XXXXXXX,    XXXXXXX,    KC_UP,      XXXXXXX,    XXXXXXX,    XXXXXXX,
                XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   XXXXXXX,    XXXXXXX,
       _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            _______,    _______,    _______,    _______,    _______,
       KC_POWER, _______,
       _______,
       _______, _______,    _______
),


/* Keymap 3: System Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Version|      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Reset|      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
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


/* Keymap:  layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */


const uint16_t PROGMEM fn_actions[] = {
};


qk_tap_dance_action_t   tap_dance_actions[] = {
    [CT_LSFT]       = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [CT_RSFT]       = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
};


uint8_t last_layer;

// 前回の更新時間
uint32_t last_updated_time;

#define MOUSE_KEY_START     KC_MS_UP

// マウスキーを長押しし始めた時刻
uint32_t last_mouse_key_time;
// 押下中のマウスキーの組み合わせ
uint32_t mouse_key_flags;


#define MOUSE_WHEEL_KEY_START           KC_WH_U
#define NUM_OF_MOUSE_WHEEL_KEY          4

// 次にマウスホイールキーを有効にする時間
uint32_t next_mouse_wheel_key_time;
// 押下中のマウスホイールキーの組み合わせ
uint32_t mouse_wheel_key_flags;
uint32_t mouse_wheel_key_interval;

#define MOUSE_WHEEL_KEY_INTERVAL        70
#define MOUSE_WHEEL_KEY_INTERVAL_MIN    50


// 更新間隔 (50fps)
#define UPDATE_INTERVAL (1000 / 50)

#define LED_BRIGHTNESS  120
#define NUM_LED         3

uint8_t led_brightness[ NUM_LED ];



static uint32_t    get_mouse_key_flag( uint16_t keycode ) {
    return 1 << (keycode - MOUSE_KEY_START);
}

static uint32_t    get_mouse_wheel_key_flag( uint16_t keycode ) {
    return 1 << (keycode - C_WH_START);
}

// 50Hz で呼ばれます
static void fixed_update(void) {
    uint32_t now = timer_read32();
    uint8_t layer = biton32(layer_state);

    // レイヤーの切り替わりを検知
    if (layer != last_layer) {
        // レイヤーが切り替わったらフラグを消す
        if (layer != L_NAV) {
            mouse_key_flags         = 0;
            mouse_wheel_key_flags   = 0;
        }
    }

    // モディファイアキーを検知 (レイヤーの変更も含む) 
    int oneshot_mods = get_oneshot_mods();
    int mods = keyboard_report->mods;
    if ( (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) || mods || oneshot_mods || layer != 0 ) {
        led_brightness[ 2 ] = LED_BRIGHTNESS;
    }

    // マウスキーの加速
    if (mouse_key_flags != 0) {
        uint32_t dt = now - last_mouse_key_time;
        float r = dt / (1000 * 1.0f);       // 1000ms * sec
        r = r * r;
        if (r > 1.0f) {
            r = 1.0f;
        }
        uint8_t n = (uint8_t)(MOUSEKEY_MAX_SPEED * 2 + 7 * r);
        mk_max_speed        = n;

        led_brightness[ 0 ] = (uint8_t)(LED_BRIGHTNESS * r);
    }

    // マウスホイールをオートリピート
    if ( mouse_wheel_key_flags != 0 ) {
        // 指定時間を経過していればキーを送信
        if ( now >= next_mouse_wheel_key_time ) {
            // 次回
            next_mouse_wheel_key_time   += mouse_wheel_key_interval;

            // マウスキーとホイールとが競合しちゃうけど同時に操作はしないと思う
            mousekey_clear();
            for ( int i = 0; i < NUM_OF_MOUSE_WHEEL_KEY; ++i ) {
                if ( 0 == ( mouse_wheel_key_flags & ( 0x01 << i ) ) ) {
                    continue;
                }
                uint8_t keycode = ( uint8_t )( MOUSE_WHEEL_KEY_START + i );
                mousekey_on( keycode );
                mousekey_send();
                mousekey_off( keycode );
                mousekey_send();
            }
            float r = 1.0f - ( mouse_wheel_key_interval - MOUSE_WHEEL_KEY_INTERVAL_MIN ) / ( MOUSE_WHEEL_KEY_INTERVAL - MOUSE_WHEEL_KEY_INTERVAL_MIN );
            led_brightness[ 0 ] = (uint8_t)(LED_BRIGHTNESS * r);

            // だんだん加速する
            mouse_wheel_key_interval    = MAX( mouse_wheel_key_interval * 5 / 6, MOUSE_WHEEL_KEY_INTERVAL_MIN );
        }
    }

    // LED をフェードアウト
    uint32_t dec = 10;      // フェーデアウト速度
    for (uint8_t i = 0; i < NUM_LED; ++i) {
        if (led_brightness[ i ] > 0) {
            ergodox_right_led_on(i + 1);
            if (led_brightness[ i ] > dec) {
                led_brightness[ i ] -= dec;
            } else {
                led_brightness[ i ] = 0;
            }
            ergodox_right_led_set(i + 1, led_brightness[ i ]);
        } else {
            ergodox_right_led_off(i + 1);
        }
    }

    last_layer      = layer;

    return;
}



// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    uint32_t now = timer_read32();
    last_mouse_key_time = now;
    last_updated_time   = now;
    last_layer = biton32(layer_state);

    mouse_key_flags         = 0;
    mouse_wheel_key_flags   = 0;

    mk_max_speed            = MOUSEKEY_MAX_SPEED;

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
            int oneshot_shift = get_oneshot_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
            int shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
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
    case C_WH_U ... C_WH_R:
        if (record->event.pressed) {
            // 初回
            if (mouse_wheel_key_flags == 0) {
                next_mouse_wheel_key_time   = now;
                mouse_wheel_key_interval    = MOUSE_WHEEL_KEY_INTERVAL;
            }
            mouse_wheel_key_flags     |= get_mouse_wheel_key_flag( keycode );
        } else {
            mouse_wheel_key_flags     &= ~get_mouse_wheel_key_flag( keycode );
            // 終了
            if (mouse_wheel_key_flags == 0) {
            }
        }
        break;
    case KC_MS_UP ... KC_MS_RIGHT:
    //case KC_MS_WH_UP ... KC_MS_WH_RIGHT:
        if (record->event.pressed) {
            // 初回
            if (mouse_key_flags == 0) {
                last_mouse_key_time = now;
            }
            mouse_key_flags     |= get_mouse_key_flag( keycode );
        } else {
            mouse_key_flags     &= ~get_mouse_key_flag( keycode );
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



