
#include "KOLOS_Repeater.h"

uint8_t tx_pin = 4;
uint8_t rx_pin = 3;
uint8_t tr_pin = 5;

SoftwareSerial ss = SoftwareSerial(rx_pin, tx_pin);

void krbegin()
{
    Serial.begin(9600);
    ss.begin(9600);
    // setting relays to off (they are inverse)

    pinMode(tr_pin, OUTPUT);
    pinMode(rx_pin, INPUT);
    pinMode(tx_pin, OUTPUT);
    // tr pin is high for transmit and low for receive
    digitalWrite(tr_pin, LOW);


}

void krloop()
{
    if(Serial.available())
    {
        String msg = Serial.readStringUntil('\n');
        Serial.print("We got string: ");
        Serial.println(msg);
        Serial.println("Now we are trying to transmit it through rs485 line");
        // send
        digitalWrite(tr_pin, HIGH);
        ss.println(msg);
        delay(10);
        digitalWrite(tr_pin, LOW);

        Serial.println("Wait for resp");
        while(!ss.available()){}  // wait for response

        String res = ss.readStringUntil('\n');
        Serial.print("We got string: ");
        Serial.println(res);
    }

}