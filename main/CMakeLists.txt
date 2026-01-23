

cmake_minimum_required(VERSION 3.16)

set(
    app_sources
    "main.cpp"
    "rtos.cpp"
)

set(
    app_include_dirs
    "."
    "")

set(
    app_requires
    esp_lcd_gc9107
    button
    cmake_utilities
    coremark
    esp_lv_fs
    esp_lvgl_port
    esp_mmap_assets
    fmt
    freertos-cpp
    littlefs
    lvgl
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
    esp_lcd
    console
)

set(
    my_components
    filesystem-v003
    one-cli-v005
    onebutton-v001
)

idf_component_register(
    SRCS
    ${app_sources}
    INCLUDE_DIRS
    ${app_include_dirs}
    REQUIRES
    ${app_requires} ${my_components}
    PRIV_REQUIRES
    ${app_priv_requires}
    WHOLE_ARCHIVE
)

add_compile_options(
   -Wno-error
)
