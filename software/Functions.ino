void initPins(){
    Serial.begin(115200);

  // --- SPI Chip Select Pins (Outputs) ---
  pinMode(Pins::flashCs, OUTPUT);
  pinMode(Pins::imuCs, OUTPUT);
  pinMode(Pins::baroCs, OUTPUT);

  // --- Servo Control Pins (Outputs) ---
  pinMode(Pins::servo1Pin, OUTPUT);
  pinMode(Pins::servo2Pin, OUTPUT);
  pinMode(Pins::servo3Pin, OUTPUT);
  pinMode(Pins::servo4Pin, OUTPUT);

  // --- Indicators & Peripherals (Outputs) ---
  pinMode(Pins::buzzPin, OUTPUT);
  pinMode(Pins::ledRpin, OUTPUT);
  pinMode(Pins::ledGpin, OUTPUT);
  pinMode(Pins::ledBpin, OUTPUT);

  // --- Control & Arming Pins (Inputs - assuming buttons/switches) ---
  pinMode(Pins::armPin, INPUT_PULLUP);
  pinMode(Pins::pyroarmPin, INPUT_PULLUP);
  pinMode(Pins::testPin, INPUT_PULLUP);

  // --- Pyrotechnic Channels & Continuity (Outputs & Inputs) ---
  pinMode(Pins::pyroarmPin, OUTPUT); // If this acts as a power gate/control signal output instead of a switch, set to OUTPUT
  pinMode(Pins::pyro1, OUTPUT);
  pinMode(Pins::pyro2, OUTPUT);
  pinMode(Pins::pyroCont1, INPUT_PULLUP);
  pinMode(Pins::pyroCont2, INPUT_PULLUP);

  // --- Analog Sensor Sense (Input) ---
  pinMode(Pins::battSense, INPUT);
   
  // --Interupts--
  attachInterrupt(digitalPinToInterrupt(Pins::imuInt), imuDataReady, RISING);
  attachInterrupt(digitalPinToInterrupt(Pins::baroInt), baroDataReady, RISING);
}
initPeripherals(){
  myGNSS.setUART1Output(COM_TYPE_UBX);
  myGNSS.saveConfigSelective(VAL_CFG_SUBSEC_IOPORT);
  myGNSS.setNavigationFrequency(1);
   
  BARO.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  BARO.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  BARO.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);

}

//safety functions
IMUwhoami(){
  setBank(0);

  uint8_t id;

  if (readRegisters(UB0_REG_WHO_AM_I, 1, &id) < 0) {
    Serial.println("WHO_AM_I read failed!");
    return 0xFF;
  }

  Serial.print("WHO_AM_I: 0x");
  Serial.println(id, HEX);
  return id;
}

BAROwhoami() {
  uint8_t id;

if (readRegisters(0x00, 1, &id) < 0) {
    Serial.println("BMP388 CHIP_ID read failed!");
    return -1;
}

Serial.print("BMP388 CHIP_ID: 0x");
Serial.println(id, HEX);

if (id != 0x50) {
    Serial.println("BMP388: WRONG DEVICE");
    return -2;
}

Serial.println("BMP388: OK");
}