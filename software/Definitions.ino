
#include <SPI.h>
#include <math.h>
#include <ICM42688.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP3XX.h>
#include <SPIMemory.h>
#include <Servo.h>
#include <SparkFun_u-blox_GNSS_v3.h>

volatile bool imuReady = false;
volatile bool baroReady = false;

namespace Pins {
    constexpr uint8_t flashCs = ;
    constexpr uint8_t imuCs = ;
    constexpr uint8_t baroCs = ;
    constexpr uint8_t imuInt = ;
    constexpr uint8_t baroInt = ;
    constexpr uint8_t servo1Pin = ;
    constexpr uint8_t servo2Pin = ;
    constexpr uint8_t servo3Pin = ;
    constexpr uint8_t servo4Pin = ;
    constexpr uint8_t buzzPin = ;
    constexpr uint8_t ledRpin = ;
    constexpr uint8_t ledGpin = ;
    constexpr uint8_t ledBpin = ;
    constexpr uint8_t armPin = ;
    constexpr uint8_t testPin = ;
    constexpr uint8_t pyroarmPin = ;
    constexpr uint8_t battSense = ;
    constexpr uint8_t pyro1 = ;
    constexpr uint8_t pyro2 = ;
    constexpr uint8_t pyroCont1 = ;
    constexpr uint8_t pyroCont2 = ;

};


