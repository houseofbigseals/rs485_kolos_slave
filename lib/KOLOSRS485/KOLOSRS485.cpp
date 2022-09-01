#include "KOLOSRS485.h"

// rs485
uint8_t tx_pin = 10;
uint8_t rx_pin = 9;
SoftwareSerial ss(rx_pin, tx_pin); // RX, TX
int tr_pin = 11;

// timers
unsigned long interval = 1000;
unsigned long previousMillis = 0; 

// devs
const int devs_num = 2;
String* devices[devs_num];



// relays
int relay6_pin = 7;

void kbegin()
{


    // setting relays to off (they are inverse)
    pinMode(relay6_pin, OUTPUT);
    pinMode(tr_pin, OUTPUT);
    pinMode(rx_pin, INPUT);
    pinMode(tx_pin, OUTPUT);
    // tr pin is high for transmit and low for receive
    digitalWrite(relay6_pin, HIGH);
    digitalWrite(tr_pin, LOW);
    ss.begin(9600);

}

void kloop()
{

    
    if (ss.available() > 0) 
    {
    String msg = ss.readStringUntil('\n');
    delay(10);
    digitalWrite(tr_pin, HIGH);
    //delay(1000);
    String res = "response_" + msg;
    ss.println(res);
    delay(10);
    //delay(100);
    digitalWrite(tr_pin, LOW);
    //ss.flush();
    }
        
    
    /*
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) 
    {
        previousMillis = currentMillis;
        // and do the job


            //String msg = ss.readStringUntil('\n');
            digitalWrite(tr_pin, HIGH);
            
            ss.println("you are gay");
            digitalWrite(tr_pin, LOW);

    }
    */

}

