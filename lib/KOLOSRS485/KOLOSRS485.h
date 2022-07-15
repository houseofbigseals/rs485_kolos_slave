#ifndef clot_protocol_h
#define clot_protocol_h

#include <stdint.h>
#include <Arduino.h>
#include <SoftwareSerial.h>

/*

protocol is very simple
we want to send and receive data as arduino hal strings

it is half-duplex protocol
slave never calls first, it is waiting master msg
after master msg received, slave answers and then 


*/

class RS485MasterMessage
{
    /*
    structure of master message:
    'ABCDEF\n'  , where
    A - first byte, everytime 'A'
    B - slave addr, any char symbol
    C - command to slave, any char symbol
    D - command argument 1, any char symbol
    E - command argument 2, any char symbol
    F - end symbol, everytime 'F'

    if something in master msg is not needed, set 'N' to that place

    so for example A130NF\n is command for slave 1
    to set relay 3 to state 0
    */

};

class RS485SlaveResponse
{
    /*
    structure of slave response is simple: echo and answer
    echo - is repeating same command, answer can be any arduino string ends with '\n'
    */

};


class RS485Handler
{
    public:
    SoftwareSerial ss;
    RS485Handler(SoftwareSerial ss_);
    uint8_t* parse_master_msg(RS485MasterMessage* m);
    RS485SlaveResponse* create_slave_resp();


};

#endif