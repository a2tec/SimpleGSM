/**
* Arduino - Gsm driver
* 
* GSM.cpp
* 
* implementation of the SIM's modem.
* 
* @author Luiz Carlos Admertides <luiz@a2tec.com.br>
*/

#include "Arduino.h"
#include "Gsm.h"

/* PUBLIC FUNCTIONS */

void SIM900::begin(String pin)
{
	Serial1.begin(9600);

	simpleAT("ATE0");
	sendAT("ATZ", "OK", 500);
	sendAT("AT", "OK", 1000);
	if(testPin() == 0){
		sendAT("AT+CPIN="+pin, "OK", 2000);
	}

	sendAT("AT+CGREG?", "+CGREG: 0,5", 1000);
	sendAT("AT+IFC=1,1","OK", 500);
	sendAT("AT+CMGF=1", "OK", 500);
	sendAT("AT+CLIP=1", "OK", 500);
	sendAT("AT+COLP=1", "OK", 2000);
}

void SIM900::beginGPRS()
{
	sendAT("AT+CGATT=1", "OK", 500);
	sendAT("AT+CGDCONT=1,\"IP\",\"APN\"", "OK", 500);
	sendAT("AT+CSTT=\"free\",\"\",\"\"", "OK", 500);
	simpleAT("AT+CIICR");
	delay(2000);
	simpleAT("AT+CIFSR");
	delay(1000);
	sendAT("AT+CIPHEAD=1", "OK", 1000);
}

void SIM900::sms(String number, String msg)
{
	simpleAT("AT+CMGS=\""+number+"\"");
	delay(1000);
