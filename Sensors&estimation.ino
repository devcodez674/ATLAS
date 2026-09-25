struct rawData {
    float ax, ay, az, gx, gy, gz;
    float pressure, altitude, temperature;
};

struct EstimatedData {
  float pitch, roll, yaw, accelMagnitude;
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
    baroData.altitude = BARO.readAltitude(SeaLevelPressure_HPA);
    baroData.pressure = BARO.pressure / 100.0f;
    baroData.temperature = BARO.temperature;

}
void findBattVoltage(){
    
}

SFE_UBLOX_GNSS_SERIAL GPS;
#define GPSSerial Serial4 

void findEstimated(){


}