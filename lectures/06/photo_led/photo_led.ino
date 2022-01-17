#define ANALOG_IN A0 // dfine a name ANALOG_IN, which is replaced in the whole program during compilation with A0
#define LEDPIN 2
//int analog_in=A0; (( analog in can also be created as a true variable, wich will the be referenced during runtime 
// define is better suitable for constants that never change

int analog_val; // 0-1023 (10 byte analog to digital wandler, kann also 2**10 Werete Auflösen)
int min_val=1024;
int max_val=0;

//run once
void setup() {
  Serial.begin(9600);   // start serial communication with 9600 bits/s 
  pinMode(ANALOG_IN,INPUT); // sets analog pin as input
  pinMode(LEDPIN, OUTPUT);
}

//run forever
void loop() {
  analog_val=analogRead(ANALOG_IN); // set the value of the variable to the reading of the pin
  write_data("abs_light",analog_val);
  if(analog_val>max_val){
    max_val = analog_val;
    }
  if(analog_val<min_val){
    min_val = analog_val;
    }
  
  
  if(min_val<max_val){
    analog_val = map(analog_val, min_val, max_val, 0, 255);
    analogWrite(LEDPIN, 255-analog_val);
  }

  write_data("rel_light",analog_val); //print out the value
  Serial.println();
  delay(50); //wait fpr 50 ms
}

//for custom plotter
void write_data2(char* name,int value){ 
  Serial.print("#d name=");
  Serial.print(name);
  Serial.print(" value=");
  Serial.print(value);
  Serial.print(" type=");
  Serial.print("int");
  Serial.println();
  }

//for arduino ide plotter
void write_data(char* name,int value){
  Serial.print(name);
  Serial.print(":");
  Serial.print(value);
  Serial.print(",");
  }
