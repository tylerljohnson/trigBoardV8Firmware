
void initBme() {
    if (!bme.begin()) {
        Serial.println(F("Could not find a valid BME280 sensor, check wiring, address, sensor ID!"));
        Serial.print(F("SensorID was: 0x")); Serial.println(bme.sensorID(),16);
    }
    newBmeData=false;
}

void bmeMeasure() {
  temperature = (bme.readTemperature() * 1.8) + 32; // convert to F
  pressure = bme.readPressure() / 3386.39; // convert to inches
  humidity = bme.readHumidity();
  newBmeData=true;
}
