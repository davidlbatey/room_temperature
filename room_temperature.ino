/*
  Temperature visualization.
*/

const int TEMPERATURE_PIN = 0;
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float voltage, degrees_c;
  
  voltage   = get_voltage(TEMPERATURE_PIN);
  degrees_c = (voltage - 0.5) * 100.0;
  
  set_light(degrees_c);
  
  
  Serial.print("Degrees: ");
  Serial.println(degrees_c);
  
  delay(2500);
}

float get_voltage(int pin) {
  return (analogRead(pin) * 0.004882814);
}

void set_light(float temperature){
  if (temperature > 25.0){
    digitalWrite(RED_PIN,  HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN,  LOW);
  } else if (temperature < 20.0){
    digitalWrite(RED_PIN,   LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
  } else {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
  }
}
