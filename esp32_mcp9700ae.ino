const float Vcc = 3.3;
const int ANALOG_MAX = 4096;
const int analogPin = 34;
const int delayTime = 1000;
const int stock_rotation_term = 10;
float stock_data[stock_rotation_term];
int stock_rotation_number = 0;
bool enough_data_flag = false;

float moving_average(float data) {
  stock_rotation_number ++;
  if (stock_rotation_number >= stock_rotation_term) {
    stock_rotation_number = 0;
    enough_data_flag = true;
  }
  stock_data[stock_rotation_number] = data;
  float result = 0;
  for (int i=0; i < stock_rotation_term; i++) {
    result += stock_data[i];
  }
  result = result / stock_rotation_term;
  
  if (enough_data_flag) {
    // Serial.print("moving ave: ");
    return result;
  } else {
    // Serial.print("real data: ");
    return data;
  }
}

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
  float temp = (voltage - 500) / 10; // +10mV/degree_Celsius
  temp = moving_average(temp);
  Serial.println(temp);
  // Serial.println(" degree_Celsius.");
  delay(delayTime);
}
