

cmake_minimum_required(VERSION 3.16)

set(
    app_sources
    "app_main.cpp"
    "rtos.cpp"
)

set(
    app_include_dirs
    "."
    "")

set(
    app_requires
    esp_lcd_gc9107
    coremark
    esp-file-iterator
    esp_mmap_assets
    fmt
    esp_lcd_touch
    esp_lcd_touch_xpt2046
    lvgl
    esp_lvgl_port
    esp_lv_decoder
    esp_emote_gfx
    esp_new_jpeg
    esp_lv_fs
    button
    esp-lib-utils
    littlefs
    xz
    zlib
    libpng
    coremark
    extended_vfs
    esp_tinyusb
    esp_schedule
    #esp_cli 
    #esp_cli_commands
    #esp_linenoise #dezactiveaza neaparat console componenta din IDF
    argtable3
)

set(
    app_priv_requires
    ${app_requires}
    cmake_utilities
    esp_bootloader_format
    nvs_flash
    esp_wifi
    esp_rom
    driver
    fatfs
    spi_flash
    esp_driver_usb_serial_jtag
    esp_system
    heap
    esp_common
    esp_psram
    esp_hw_support
    esp_rom
    esp_wifi
    esp_lcd
    console
    #console #pentru ca linenoise
)

set(
    my_components_add
    esp_lcd_gc9107
    
    filesystem-v003
    one-cli-v005
)

idf_component_register(
    SRCS
    ${app_sources}
    INCLUDE_DIRS
    ${app_include_dirs}
    REQUIRES
    ${app_requires} ${my_components_add}
    PRIV_REQUIRES
    ${app_priv_requires}
    WHOLE_ARCHIVE
)
