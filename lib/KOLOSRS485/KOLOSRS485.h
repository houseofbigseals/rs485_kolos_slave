#ifndef kolos_485_h
#define kolos_485_h

#include <stdint.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

/*

protocol is very simple
we want to send and receive data as arduino hal strings

it is half-duplex protocol
slave never calls first, it is waiting master msg
after master msg received, slave answers and then 


*/



void kbegin();
void kloop();

/*

class RS485Handler
{
    public:
    SoftwareSerial* ss;
    RS485Handler(SoftwareSerial* ss_);
    uint8_t* parse_master_msg(RS485MasterMessage* m);
    RS485SlaveResponse* create_slave_resp();
    

};
*/

#endif