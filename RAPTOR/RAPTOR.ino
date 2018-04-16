#include <Servo.h>

#define SERVO_PIN 6
#define SERVO_STOP 90
#define SERVO_SWITCH 3

#define SOLENOID_PIN 5
#define SOLENOID_SWITCH 6

#define TEMP_PIN 4

Servo servo;

void setup() {
  servo.attach(6);
  pinMode(SERVO_SWITCH, INPUT);
  pinMode(SOLENOID_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  getTemperature();
  servoTest(1000);
  solenoidTest(200);
  delay(5000);
}

/*
 * getTemperature will use the appropriate ADC reading to calculate temperature and print it to the SD card.
 */
void getTemperature(void){
  int read_adc = analogRead(TEMP_PIN);                        // save reading
  
  float voltage = (0.000502512562*read_adc - 0.095979899);    //converts the adc reading into an actual voltage based off of slope.
  float resistance = (3.3*10000)/(3.3 - voltage) - 10000;     //Need to convert our voltage reading into the resistance across the thermistor. To find this we use 3.3(R1)/(3.3-vadc) - R1
  float a_const = 0.003354016;                                //A value for the NTCLE100E3103HT1 in the Steinhart-Hart equation (T = 1/(A + Bln(resistance) + Dln^3(resistance))
  float b_const = 0.000256985;                                //B value
  float d_const = 0.00000006383091;                           //D value.
  float temperature = 1/(a_const+ b_const*log(resistance/10000) + d_const*log(resistance/10000)*log(resistance/10000)*log(resistance/10000)); //Steinhart-Hart to find temperature then return it.  
  Serial.write("temp = %d", temperature);
}

/*
 * servoTest will send a write to the servo to test it, upon which a physical switch will activate a pin if it is hit.
 * The function will monitor this pin, and record to the SD card whether it is hit within the duration given.
 */
void servoTest(int duration){
  int milli = 0;
  boolean switch_hit = false;
  
  servo.write(SERVO_STOP);
  servo.write(180);                                         // Start the servo
  
  while(!switch_hit && milli < duration){                   // Until the limit switch for the servo is hit, or we have waited for duration in milliseconds.
    switch_hit = digitalRead(SERVO_SWITCH);                 // Read in the digital value of the SERVO_SWITCH pins
    delay(1);
    i++;                                                    // Increment i every 1 millisecond
  }
  servo.write(SERVO_STOP);

  if(switch_hit){                                           // If the switch has been hit
    Serial.write("Motor switch hit, took %d milliseconds.\n", milli);
  }
  else{
    Serial.write("!!!MOTOR SWITCH NOT HIT!!!!\n");
  }
}

/*
 * solenoidTest will send a write to the servo to test it, upon which a physical switch will activate a pin if it is hit.
 * The function will monitor this pin, and record to the SD card whether it is hit within the duration given.
 */
void solenoidTest(int duration){
  int milli = 0;
  boolean switch_hit = false;
  
  digitalWrite(SOLENOID_PIN, HIGH);                        // Start the solenoid
  
  while(!switch_hit && milli < duration){                  // Until the limit switch for the solenoid is hit, or we have waited for duration in milliseconds.
    switch_hit = digitalRead(SOLENOID_SWITCH);             // Read in the digital value of the SERVO_SWITCH pins
    delay(1);
    i++;                                                   // Increment i every 1 millisecond
  }
  digitalWrite(SOLENOID_PIN, LOW);

  if(switch_hit){                                          // If the switch has been hit
    Serial.write("Solenoid switch hit, took %d milliseconds.\n", milli);
  }
  else{
    Serial.write("!!!SOLENOID SWITCH NOT HIT!!!!\n");
  }
}

