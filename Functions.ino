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

