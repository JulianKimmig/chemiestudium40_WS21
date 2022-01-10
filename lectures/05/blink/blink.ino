#define LEDPIN 2

void setup() {
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  digitalWrite(LEDPIN, LOW);
  delay(1000);
  digitalWrite(LEDPIN, HIGH);
  Serial.println(0);
  delay(2000);

}
