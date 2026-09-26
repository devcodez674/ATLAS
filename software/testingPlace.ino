
if (GPS.getPVT()){
  EstimatedData.latitude = GPS.getLatitude() / 1e7;
  EstimatedData.longitude = GPS.getLongitude() / 1e7;
  rawData.GPSAltitude = GPS.getAltitudeMSL();
  rawData.SVno = GPS.getSV();
  rawData.fixType = GPS.getFixType();
  rawData.pDop = GPS.getPdop();

}

bool preFlightCheck(){
  digitalWrite(imuCs, LOW);
  IMUwhoami();
  digitalWrite(imuCs, HIGH);
  digitalWrite(baroCs, LOW);
  BAROwhoami();
  digitalWrite(baroCs, HIGH);
  


  if (BARO.performReading()) {
    pressureRef_Hpa = BARO.pressure / 100.0f;
  }
  return false;
}