  if (myGNSS.getPVT()) {
    Serial.print("Lat: ");
    Serial.print(myGNSS.getLatitude() / 1e7);
    Serial.print("  Lon: ");
    Serial.print(myGNSS.getLongitude() / 1e7);
    Serial.print("  Alt: ");
    Serial.println(myGNSS.getAltitudeMSL());
  }