/**
 * @file main.c
 *
 * Blinky stuff running on the ULP-RISC-V.
 */

#include "ulp_riscv/ulp_riscv.h"
#include "ulp_riscv/ulp_riscv_utils.h"

#include "soc/rtc_io_reg.h"

#include "ulp_gpio.h"

volatile int pin;
volatile uint32_t count;

int main(void)
{
    ulp_gpio_init(pin);
    ulp_gpio_set_direction(pin, ULP_GPIO_MODE_OUTPUT_ONLY);
    ulp_gpio_hold_dis(pin);

    if (count % 2) {
        ulp_gpio_set_level(pin, 1);
    } else {
        ulp_gpio_set_level(pin, 0);
    }

    ++count;
    ulp_gpio_hold_en(pin); // hold GPIO level during sleep

    return 0;
}
