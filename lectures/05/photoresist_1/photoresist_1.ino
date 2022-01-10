#define ANALOG_IN A0 // dfine a name ANALOG_IN, which is replaced in the whole program during compilation with A0
//int analog_in=A0; (( analog in can also be created as a true variable, wich will the be referenced during runtime 
// define is better suitable for constants that never change

int analog_val; // 0-1023 (10 byte analog to digital wandler, kann also 2**10 Werete Auflösen)

//run once
void setup() {
  Serial.begin(9600);   // start serial communication with 9600 bits/s 
  pinMode(ANALOG_IN,INPUT); // sets analog pin as input
}

//run forever
void loop() {
  analog_val=analogRead(ANALOG_IN); // set the value of the variable to the reading of the pin
  Serial.println(analog_val); //print out the value
  delay(50); //wait fpr 50 ms
}
