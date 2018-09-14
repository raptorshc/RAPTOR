bool bmpUpdate(void){
  // Temperature measurement
  char status = bmp.startTemperature();
  delay(status);
  status = bmp.getTemperature(bmp_data.temperature);

  // If temperature succeeded, pressure measurement
  if(status){
    status = bmp.startPressure(3);
    delay(status);
    status = bmp.getPressure(bmp_data.pressure, bmp_data.temperature);

    // If pressure succeeded, calculate altitude
    if(status){
      bmp_data.altitude = bmp.altitude(bmp_data.pressure, bmp_data.baseline);
    }
    else return false;
  }
  else return false;
}