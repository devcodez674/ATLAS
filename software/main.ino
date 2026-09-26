Adafruit_BMP3XX BARO;
ICM42688 IMU(SPI, 11);
Servo servoFin1;
Servo servoFin2;
Servo servoFin3;
Servo servoFin4;

void setup(){
    Serial.begin(115200);
    while (!Serial);
    GPSSerial.begin(38400);
    if (GPS.begin(GPSSerial) == false) {
        errorWarn();
        while(1);
    }
    initPins(); 
}

void loop(){
if(imuReady){
    readIMU();
}
if(baroReady){
    readBaro();
}
}