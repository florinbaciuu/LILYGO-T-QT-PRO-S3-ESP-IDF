#pragma once


#define BASE_PATH "/spiflash"

/******************************
 *    INTERNAL MMC DEFINES
 *****************************/
#define FAT_PARTITION_LABEL "fatfs"
#define FAT_MOUNT_PATH "/fatfs"

/******************************
 *    INTERNAL SPIFFS DEFINES
 *****************************/
#define SPIFFS_PARTITION_LABEL "spiffs"
#define SPIFFS_MOUNT_PATH "/spiffs"

/******************************
 *    INTERNAL littlefs DEFINES
 *****************************/
#define LITTLEFS_PARTITION_LABEL "littlefs"
#define LITTLEFS_MOUNT_PATH "/littlefs"

//-------------------------

/******************************
 *      SD MMC DEFINES
 *****************************/
#define PIN_NUM_MISO  16
#define PIN_NUM_MOSI  17
#define PIN_NUM_CLK   14
#define PIN_NUM_CS    21

#define SDMMC_CLK_PIN  14 // SD_CLK
#define SDMMC_CMD_PIN  17 // SD_MOSI // 45 
#define SDMMC_D0_PIN   16 // SD_MISO // 46
#define SDMMC_D1_PIN   18
#define SDMMC_D2_PIN   15
#define SDMMC_D3_PIN   21 // SD_CS


//---
#define SD_FREQ_DEFAULT 20000   /*!< SD/MMC Default speed (limited by clock divider) */
#define SD_FREQ_HIGHSPEED 40000 /*!< SD High speed (limited by clock divider) */

#define SD_MOUNT_LABEL "sdcard"
#define SD_MOUNT_PATH "/sdcard"

#define SDMMC_SYSTEM
//#define SPISD_SYSTEM


//-------------------------

/**
 * @brief Default sdmmc_host_t structure initializer for SDMMC peripheral
 *
 * Uses SDMMC peripheral, with 4-bit mode enabled, and max frequency set to 20MHz
 */
#define SDMMC_HOST_DEF()                                                                                                                                 \
    {                                                                                                                                                    \
        .flags                  = SDMMC_HOST_FLAG_8BIT | SDMMC_HOST_FLAG_4BIT | SDMMC_HOST_FLAG_1BIT | SDMMC_HOST_FLAG_DDR | SDMMC_HOST_FLAG_DEINIT_ARG, \
        .slot                   = SDMMC_HOST_SLOT_1,                                                                                                     \
        .max_freq_khz           = SDMMC_FREQ_DEFAULT,                                                                                                    \
        .io_voltage             = 3.3f,                                                                                                                  \
        .driver_strength        = SDMMC_DRIVER_STRENGTH_B,                                                                                               \
        .current_limit          = SDMMC_CURRENT_LIMIT_200MA,                                                                                             \
        .init                   = &sdmmc_host_init,                                                                                                      \
        .set_bus_width          = &sdmmc_host_set_bus_width,                                                                                             \
        .get_bus_width          = &sdmmc_host_get_slot_width,                                                                                            \
        .set_bus_ddr_mode       = &sdmmc_host_set_bus_ddr_mode,                                                                                          \
        .set_card_clk           = &sdmmc_host_set_card_clk,                                                                                              \
        .set_cclk_always_on     = &sdmmc_host_set_cclk_always_on,                                                                                        \
        .do_transaction         = &sdmmc_host_do_transaction,                                                                                            \
        .deinit_p               = &sdmmc_host_deinit_slot,                                                                                               \
        .io_int_enable          = sdmmc_host_io_int_enable,                                                                                              \
        .io_int_wait            = sdmmc_host_io_int_wait,                                                                                                \
        .command_timeout_ms     = 0,                                                                                                                     \
        .get_real_freq          = &sdmmc_host_get_real_freq,                                                                                             \
        .input_delay_phase      = SDMMC_DELAY_PHASE_0,                                                                                                   \
        .set_input_delay        = &sdmmc_host_set_input_delay,                                                                                           \
        .dma_aligned_buffer     = NULL,                                                                                                                  \
        .pwr_ctrl_handle        = NULL,                                                                                                                  \
        .get_dma_info           = NULL,                                                                                                                  \
        .check_buffer_alignment = &sdmmc_host_check_buffer_alignment,                                                                                    \
        .is_slot_set_to_uhs1    = &sdmmc_host_is_slot_set_to_uhs1,                                                                                       \
    }
//-------------------------
#define SDMMC_HOST_DEFAULT_flo() {\
    .flags = SDMMC_HOST_FLAG_8BIT | \
             SDMMC_HOST_FLAG_4BIT | \
             SDMMC_HOST_FLAG_1BIT | \
             SDMMC_HOST_FLAG_DDR  | \
             SDMMC_HOST_FLAG_DEINIT_ARG, \
    .slot = SDMMC_HOST_SLOT_1, \
    .max_freq_khz = SDMMC_FREQ_DEFAULT, \
    .io_voltage = 3.3f, \
    .driver_strength = SDMMC_DRIVER_STRENGTH_B, \
    .current_limit = SDMMC_CURRENT_LIMIT_200MA, \
    .init = &sdmmc_host_init, \
    .set_bus_width = &sdmmc_host_set_bus_width, \
    .get_bus_width = &sdmmc_host_get_slot_width, \
    .set_bus_ddr_mode = &sdmmc_host_set_bus_ddr_mode, \
    .set_card_clk = &sdmmc_host_set_card_clk, \
    .set_cclk_always_on = &sdmmc_host_set_cclk_always_on, \
    .do_transaction = &sdmmc_host_do_transaction, \
    .deinit_p = &sdmmc_host_deinit_slot, \
    .io_int_enable = sdmmc_host_io_int_enable, \
    .io_int_wait = sdmmc_host_io_int_wait, \
    .command_timeout_ms = 0, \
    .get_real_freq = &sdmmc_host_get_real_freq, \
    .input_delay_phase = SDMMC_DELAY_PHASE_0, \
    .set_input_delay = &sdmmc_host_set_input_delay, \
    .dma_aligned_buffer = NULL, \
    .pwr_ctrl_handle = NULL, \
    .get_dma_info = NULL, \
    .check_buffer_alignment = &sdmmc_host_check_buffer_alignment, \
    .is_slot_set_to_uhs1 = &sdmmc_host_is_slot_set_to_uhs1, \
}
//-------------------------
#define GPIO_NO (-1)
#define SDMMC_NO_CD GPIO_NO  ///< indicates that card detect line is not used
#define SDMMC_NO_WP GPIO_NO  ///< indicates that write protect line is not used

#define SDMMC_SLOT_CONFIG_DEF()  \
    {                            \
        .clk   = SDMMC_CLK_PIN,  \
        .cmd   = SDMMC_CMD_PIN,   \
        .d0    = SDMMC_D0_PIN, \
        .d1    = SDMMC_D1_PIN,        \
        .d2    = SDMMC_D2_PIN,        \
        .d3    = SDMMC_D3_PIN,        \
        .d4    = GPIO_NO,        \
        .d5    = GPIO_NO,        \
        .d6    = GPIO_NO,        \
        .d7    = GPIO_NO,        \
        .cd    = SDMMC_NO_CD,    \
        .wp    = SDMMC_NO_WP,    \
        .width = 4,              \
        .flags = 0,              \
    }
//-------------------------