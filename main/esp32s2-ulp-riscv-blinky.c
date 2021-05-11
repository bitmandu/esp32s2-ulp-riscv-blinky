/**
 * @file esp32s2-ulp-riscv-blinky.c
 *
 * Blink a LED using the ULP-RISC-V coprocessor.
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/rtc_io.h"
#include "esp32s2/ulp_riscv.h"
#include "esp_log.h"
#include "esp_sleep.h"

#include "ulp_main.h"

static const char *TAG = "esp32s2-ulp-riscv-blinky";

extern const uint8_t bin_start[] asm("_binary_ulp_main_bin_start");
extern const uint8_t bin_end[] asm("_binary_ulp_main_bin_end");

static void blinky_ulp_init(gpio_num_t gpio_num)
{
    ESP_ERROR_CHECK(ulp_riscv_load_binary(bin_start, bin_end - bin_start));

    /* set RTC GPIO corresponding to GPIO */
    ulp_pin = rtc_io_number_get(gpio_num);
    ESP_LOGI(TAG, "GPIO_NUM %d => RTC GPIO_NUM %d", gpio_num, ulp_pin);

    ulp_count = 0;

    /* wakeup ULP to toggle LED every 500 ms */
    ulp_set_wakeup_period(0, 500000);

    ESP_ERROR_CHECK(ulp_riscv_run());
}

void app_main(void)
{
    blinky_ulp_init(CONFIG_GPIO_NUM);

    ESP_LOGI(TAG, "sleepy time...");
    esp_deep_sleep_start();
}
