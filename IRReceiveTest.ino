/*
 * Copyright 2013 Marcus Kempe
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Listening for IR-commands.");
  irrecv.enableIRIn(); // Start the receiver
  pinMode(3, OUTPUT);  
  pinMode(2, OUTPUT);  
}
boolean led1state = false;
boolean led2state = false;
void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    switch(results.value){
      case 0xFF629D: //On
        Serial.println("On/Off");        
        break;
      case 0xFFC23D: //+
        Serial.println("+");
        digitalWrite(3, led2state = !led2state);
        break;
      case 0xFF906F: //-
        Serial.println("-");
        digitalWrite(2, led1state = !led1state);
        break;
      case 0xFF9867: //100
        Serial.println("100");
        break;
      case 0xFF7A85: //75
        Serial.println("75");
        break;
      case 0xFF30CF: //50
        Serial.println("50");
        break;
      case 0xFF38C7: //25
        Serial.println("25");
        break;
      default:
        break;
    }
    irrecv.resume(); // Receive the next value
  }
}
