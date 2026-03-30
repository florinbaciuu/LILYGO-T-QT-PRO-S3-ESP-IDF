
# ==================================== #
set(hello_cmd_srcs # Se adauga modulul hello
    "modules/hello_cmd/hello_cmd.c")
set(hello_cmd_includes
    "modules/hello_cmd")
# ==================================== #
set(restart_srcs # Se adauga restart
    "modules/restart_cmd/restart_cmd.c")
set(restart_includes "modules/restart_cmd")
# ==================================== #
set(tasks_srcs # Se adauga task info
    "modules/tasks_cmd/tasks_cmd.c")
set(tasks_includes
    "modules/tasks_cmd")
# ==================================== #
set(uptime_srcs # Se adauga uptime
    "modules/uptime_cmd/uptime_cmd.c")
set(uptime_includes
    "modules/uptime_cmd")
# ==================================== #
# ==================================== #
# ==================================== #
# ==================================== #
# ==================================== #
# ==================================== #

# ------------------------------ #

# Aduna toate modulele intr-un singur #
set(modules_srcs
    ${hello_cmd_srcs}
    ${restart_srcs}
    ${tasks_srcs}
    ${uptime_srcs}
)
## ------------------
set(modules_includes
    ${hello_cmd_includes}
    ${restart_includes}
    ${tasks_includes}
    ${uptime_includes}
)
## ------------------
set(modules_priv_includes
    ${hello_cmd_includes}
    ${restart_includes}
    ${tasks_includes}
    ${uptime_includes}
)
## ------------------

# ------------------------------- #

idf_component_register(
    SRCS
    "src/cli.c"
    "src/init.c"
    "src/config.c"
    ${modules_srcs}
    ## ------------------
    INCLUDE_DIRS
    "include"
    "modules"
    "src"
    "."
    ${modules_includes}
    ## ------------------
    PRIV_INCLUDE_DIRS
    ${modules_priv_includes}
    ## ------------------
    REQUIRES
    perfmon
    esp_common
    driver
    console
    log

    ## ------------------
    PRIV_REQUIRES
    perfmon
    esp_timer
    driver
    freertos
    console
    esp_hw_support
    spi_flash
    esp_system
    heap
    esp_common
    esp_psram
    esp_hw_support
    nvs_flash
    esp_wifi
    esp_driver_usb_serial_jtag
)



# ------------------------------- #

set( # Asta adaug-o separat:
    KCONFIG_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/Kconfig"
)

# ------------------------------- #

# dezactivează tratarea warningurilor ca erori pentru componenta asta
target_compile_options( ${COMPONENT_LIB} PRIVATE -Wno-error -Wno-error=type-limits -Wno-unused-variable -Wno-unused-function -Wno-error=cpp )
set_source_files_properties(
    src/init.c src/one-cli.c
    PROPERTIES COMPILE_FLAGS "-Wno-error=cpp -Wno-error"
)

# ==================== #
# modules/cli/CMakeLists.txt
