# esp32s2-ulp-riscv-blinky

This is an ESP-IDF example application that toggles an LED using the
[ESP32-S2 ULP-RISC-V coprocessor][1] in deep sleep.

## Installation

	$ git clone --recurse-submodules https://github.com/bitmandu/esp32s2-ulp-riscv-blinky.git

This application depends on [ulp_gpio][2], which is included
automatically when `--recurse-submodules` is used.

## Configuration

	$ idf.py set-target esp32s2
	$ idf.py menuconfig

In the `Component config` > `ESP32S2-specific` menu check:

- Enable Ultra Low Power (ULP) Coprocessor
- Enable RISC-V as ULP coprocessor

In the `esp32s2-ulp-riscv-blinky` menu:

- Update the GPIO pin for the LED

## Output

	$ idf.py build flash monitor
	...
	I (269) esp32s2-ulp-riscv-blinky: GPIO_NUM 12 => RTC GPIO_NUM 12
	I (269) esp32s2-ulp-riscv-blinky: sleepy time...

The main CPU enters deep sleep mode, and the ULP-RISC-V coprocessor
toggles the GPIO pin (default GPIO12).

## License

[MIT](LICENSE)


[1]: https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-guides/ulp-risc-v.html
[2]: https://github.com/bitmandu/ulp_gpio/
