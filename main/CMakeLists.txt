# CMakeLists.txt

idf_component_register(SRCS "esp32s2-ulp-riscv-blinky.c"
  INCLUDE_DIRS "ulp_gpio/include"
  PRIV_REQUIRES ulp riscv driver)

set(ulp_app_name ulp_${COMPONENT_NAME})
set(ulp_srcs "ulp_gpio/ulp_gpio.c" "ulp/main.c")
set(ulp_dep_srcs "esp32s2-ulp-riscv-blinky.c")

ulp_embed_binary(${ulp_app_name} "${ulp_srcs}" "${ulp_dep_srcs}")
