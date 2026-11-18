const int TRIG_PIN = 10;
const int ECHO_PIN = 9;
const int LED_PIN = 13;
const int THRESHOLD_CM = 20; //Led turns on below this distance 

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure how long the echo pin stays HIGH (timeout 30 ms)
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.println("No echo");
    digitalWrite(LED_PIN, LOW);
  }else {
    float distanceCm = duration * 0.0343 / 2;
    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
    digitalWrite(LED_PIN, distanceCm < THRESHOLD_CM ? HIGH : LOW);
  }
  delay(100);
}
