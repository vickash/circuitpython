/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

// Micropython setup

#define MICROPY_HW_BOARD_NAME       "Arduino Nano ESP32"
#define MICROPY_HW_MCU_NAME         "ESP32S3"

// Status LED
#define CIRCUITPY_RGB_STATUS_INVERTED_PWM
#define CIRCUITPY_RGB_STATUS_R (&pin_GPIO46)
#define CIRCUITPY_RGB_STATUS_G (&pin_GPIO0)
#define CIRCUITPY_RGB_STATUS_B (&pin_GPIO45)

#define MICROPY_HW_LED_STATUS (&pin_GPIO13)

#if QSPI_FLASH_FILESYSTEM
#define MICROPY_QSPI_DATA0 (&pin_GPIO32)
#define MICROPY_QSPI_DATA1 (&pin_GPIO31)
#define MICROPY_QSPI_DATA2 (&pin_GPIO28)
#define MICROPY_QSPI_DATA3 (&pin_GPIO27)
#define MICROPY_QSPI_SCK   (&pin_GPIO30)
#define MICROPY_QSPI_CS    (&pin_GPIO29)
#endif

#define DEFAULT_I2C_BUS_SCL (&pin_GPIO12)
#define DEFAULT_I2C_BUS_SDA (&pin_GPIO11)

#define DEFAULT_SPI_BUS_SCK (&pin_GPIO48)
#define DEFAULT_SPI_BUS_MOSI (&pin_GPIO38)
#define DEFAULT_SPI_BUS_MISO (&pin_GPIO47)

#define DEFAULT_UART_BUS_RX (&pin_GPIO44)
#define DEFAULT_UART_BUS_TX (&pin_GPIO43)