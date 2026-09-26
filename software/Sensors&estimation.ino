struct rawData {
    uint8_t SVno, fixType
    int16_t pDop
    float ax, ay, az, gx, gy, gz;
    int32_t GPSAltitude;
    float pressure, BaroAltitude, temperature;
};

struct EstimatedData {
  float pitch, roll, yaw, accelMagnitude;
  float latitude, longitude;
  float altitude, BatteryVoltage, verticalVelocity;
};

void readIMU(){
    IMU.getAGT();
    rawData.ax = IMU.accX(); 
    rawData.ay = IMU.accY(); 
    rawData.az = IMU.accZ();
    rawData.gx = IMU.gyrX();
    rawData.gy = IMU.gyrY();
    rawData.gz = IMU.gyrZ();
    EstimatedData.accelMagnitude = sqrt(
        rawData.ax * rawData.ax +
        rawData.ay * rawData.ay +
        rawData.az * rawData.az       
    );
}
void readBaro(){
    if (BARO.performReading()) {
        rawData.Baroaltitude = BARO.readAltitude(pressureRef_Hpa);
        rawData.pressure = BARO.pressure / 100.0f;
        rawData.temperature = BARO.temperature;

    }
}
void findBattVoltage(){
    
}

SFE_UBLOX_GNSS_SERIAL GPS;
#define GPSSerial Serial4 

void findEstimated(){


}