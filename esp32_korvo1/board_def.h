/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2021 <ESPRESSIF SYSTEMS (SHANGHAI) CO., LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _AUDIO_BOARD_DEFINITION_H_
#define _AUDIO_BOARD_DEFINITION_H_

/**
 * @brief LED Function Definition
 */
#define FUNC_SYS_LEN_EN           (0)

/**
 * @brief SDCARD Function Definition
 */
#define FUNC_SDCARD_EN             (1)
#define SDCARD_OPEN_FILE_NUM_MAX    1
#define SDCARD_INTR_GPIO            -1
#define SDCARD_PWR_CTRL             -1

#define ESP_SD_PIN_CLK              GPIO_NUM_5
#define ESP_SD_PIN_CMD              GPIO_NUM_18
#define ESP_SD_PIN_D0               GPIO_NUM_21
#define ESP_SD_PIN_D1               -1
#define ESP_SD_PIN_D2               -1
#define ESP_SD_PIN_D3               GPIO_NUM_23
#define ESP_SD_PIN_D4               -1
#define ESP_SD_PIN_D5               -1
#define ESP_SD_PIN_D6               -1
#define ESP_SD_PIN_D7               -1
#define ESP_SD_PIN_CD               -1
#define ESP_SD_PIN_WP               -1


/**
 * @brief Audio Codec Chip Function Definition
 */
#define FUNC_AUDIO_CODEC_EN         (1)
#define ES8311_MCLK_SOURCE          (1)   /* 0 From MCLK of esp32   1 From BCLK */
#define HEADPHONE_DETECT            (-1)
#define PA_ENABLE_GPIO              GPIO_NUM_12
#define CODEC_I2S_PORT              (0)
#define CODEC_ADC_I2S_PORT          (1)
#define CODEC_ADC_BITS_PER_SAMPLE   I2S_BITS_PER_SAMPLE_32BIT
#define CODEC_ADC_SAMPLE_RATE       (16000)
#define RECORD_HARDWARE_AEC         (true)
#define BOARD_PA_GAIN               (6) /* Power amplifier gain defined by board (dB) */

extern audio_hal_func_t AUDIO_CODEC_ES8311_DEFAULT_HANDLE;
extern audio_hal_func_t AUDIO_CODEC_ES7210_DEFAULT_HANDLE;

#define AUDIO_CODEC_ES8311_CONFIG(){                    \
        .adc_input  = AUDIO_HAL_ADC_INPUT_ALL,          \
        .dac_output = AUDIO_HAL_DAC_OUTPUT_LINE2,         \
        .codec_mode = AUDIO_HAL_CODEC_MODE_DECODE,        \
        .i2s_iface = {                                  \
            .mode = AUDIO_HAL_MODE_SLAVE,               \
            .fmt = AUDIO_HAL_I2S_NORMAL,                \
            .samples = AUDIO_HAL_16K_SAMPLES,           \
            .bits = AUDIO_HAL_BIT_LENGTH_16BITS,        \
        },                                              \
};
#define AUDIO_CODEC_ES7210_CONFIG(){                    \
        .adc_input  = AUDIO_HAL_ADC_INPUT_ALL,          \
        .dac_output = AUDIO_HAL_DAC_OUTPUT_ALL,         \
        .codec_mode = AUDIO_HAL_CODEC_MODE_ENCODE,      \
        .i2s_iface = {                                  \
            .mode = AUDIO_HAL_MODE_SLAVE,              \
            .fmt = AUDIO_HAL_I2S_NORMAL,                \
            .samples = AUDIO_HAL_16K_SAMPLES,           \
            .bits = AUDIO_HAL_BIT_LENGTH_32BITS,        \
        },                                              \
};

/**
 * @brief Define ADC Buttons
 */
 #define INPUT_BUTOP_ID           ADC1_CHANNEL_3

// Define thresholds for button detection in ADC values
#define VOL_UP_THRESHOLD_LOW     420
#define VOL_UP_THRESHOLD_HIGH    520
#define VOL_DOWN_THRESHOLD_LOW   950
#define VOL_DOWN_THRESHOLD_HIGH  1080
#define SET_THRESHOLD_LOW        1250
#define SET_THRESHOLD_HIGH       1400
#define PLAY_THRESHOLD_LOW       1900
#define PLAY_THRESHOLD_HIGH      2100
#define MODE_THRESHOLD_LOW       2300
#define MODE_THRESHOLD_HIGH      2600
#define REC_THRESHOLD_LOW        2750
#define REC_THRESHOLD_HIGH       3250

 

/**
 * @brief Button Function Definition
 */
#define FUNC_BUTTON_EN              (1)
#define INPUT_KEY_NUM               6
#define BUTTON_VOLUP_ID             0
#define BUTTON_VOLDOWN_ID           1
#define BUTTON_SET_ID               2
#define BUTTON_PLAY_ID              3
#define BUTTON_MODE_ID              4
#define BUTTON_REC_ID               5

#define INPUT_KEY_DEFAULT_INFO() {                      \
     {                                                  \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_REC,               \
        .act_id = BUTTON_REC_ID,                        \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_MUTE,              \
        .act_id = BUTTON_MODE_ID,                       \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_SET,               \
        .act_id = BUTTON_SET_ID,                        \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_PLAY,              \
        .act_id = BUTTON_PLAY_ID,                       \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_VOLUP,             \
        .act_id = BUTTON_VOLUP_ID,                      \
    },                                                  \
    {                                                   \
        .type = PERIPH_ID_ADC_BTN,                      \
        .user_id = INPUT_KEY_USER_ID_VOLDOWN,           \
        .act_id = BUTTON_VOLDOWN_ID,                    \
    }                                                   \
}

#endif
