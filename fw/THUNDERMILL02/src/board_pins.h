/*
  THUNDERMILL02 - board pin map
  ATmega1284P @ 16 MHz, MightyCore "standard" pinout.

  Pin names use MightyCore PIN_Pxn macros (port-accurate, map to the
  Arduino digital pin numbers of the "standard" variant).
*/

#ifndef THUNDERMILL02_BOARD_PINS_H
#define THUNDERMILL02_BOARD_PINS_H

#include <Arduino.h>

// ---------------------------------------------------------------------------
// Status LED
// ---------------------------------------------------------------------------
static const uint8_t PIN_LED1 = PIN_PD5;   // status LED

// ---------------------------------------------------------------------------
// Timing / acquisition signals
// ---------------------------------------------------------------------------
static const uint8_t PIN_PERIOD_SIGNAL = PIN_PB2;   // optical gate / period detector (input, INT2, rising edge)
static const uint8_t PIN_ADC_CONV      = PIN_PB0;   // conversion trigger for ADC

// ---------------------------------------------------------------------------
// Motor controller
// ---------------------------------------------------------------------------
static const uint8_t PIN_MOTOR_PWM   = PIN_PB3;     // motor PWM (output)
static const uint8_t PIN_MOTOR_BRAKE = PIN_PA3;     // motor brake (output)
static const uint8_t PIN_MOTOR_SLEEP = PIN_PA4;     // motor sleep (output)
static const uint8_t PIN_MOTOR_DIR   = PIN_PA2;     // motor direction (output)
static const uint8_t PIN_MOTOR_FAULT = PIN_PD2;     // motor fault (input, active low)
static const uint8_t PIN_MOTOR_FG    = PIN_PD6;     // motor FG / tacho (input)

// ---------------------------------------------------------------------------
// RS485
// ---------------------------------------------------------------------------
static const uint8_t PIN_RS485_IN = PIN_PD4;        // RS485 input / receiver enable

// ---------------------------------------------------------------------------
// SHT31 hygrometer (I2C on the hardware TWI unit)
//   PC0 = SCL, PC1 = SDA  -> used implicitly by the Wire library
// ---------------------------------------------------------------------------
static const uint8_t PIN_HYGROMETER_ALERT = PIN_PD3;   // SHT31 ALERT (input)
static const uint8_t SHT31_I2C_ADDR        = 0x44;     // ADDR pin low (0x45 if high)

// ---------------------------------------------------------------------------
// Serial number EEPROM (I2C, shares the bus with the SHT31)
//   AT24CS64-SSHM: the factory-programmed 128-bit serial number lives in a
//   separate read-only block (device type 1011b -> 0x58 with A2..A0 = 0,
//   the EEPROM array itself is at 0x50). The block starts at word address
//   0x0800; any other address returns undefined data (datasheet DS20006296).
// ---------------------------------------------------------------------------
static const uint8_t  EEPROM_I2C_ADDR = 0x58;     // serial number block
static const uint16_t EEPROM_SN_REG   = 0x0800;   // first byte of the serial number
static const uint8_t  EEPROM_SN_LEN   = 16;       // bytes read from the EEPROM

// ---------------------------------------------------------------------------
// SPI (hardware SPI unit)
//   Note: PB4 = SS. In SPI master mode keep PB4 as OUTPUT (driven high) or it
//   must stay high, otherwise the SPI hardware reverts to slave mode.
// ---------------------------------------------------------------------------
static const uint8_t SPI_SS_PIN   = PIN_PB4;
static const uint8_t SPI_MOSI_PIN = PIN_PB5;
static const uint8_t SPI_MISO_PIN = PIN_PB6;
static const uint8_t SPI_SCK_PIN  = PIN_PB7;

#endif // THUNDERMILL02_BOARD_PINS_H
