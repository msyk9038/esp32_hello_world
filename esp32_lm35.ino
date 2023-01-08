const float Vcc = 3.3;
const int ANALOG_MAX = 4096;
const int analogPin = 34;
const int delayTime = 1000;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  int reading = analogRead(analogPin);
  float voltage = ((long)reading * Vcc * 1000) / ANALOG_MAX;
  float temp = voltage / 10; // +10mV/degree_Celsius
  Serial.print(temp);
  Serial.println(" degree_Celsius.");
  delay(delayTime);
}
