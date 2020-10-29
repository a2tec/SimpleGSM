/* 
* @title	GSM
* @description	Minimalist library for SIM800/900 ... A/B ... etc
* @author 	Luiz Carlos Admertides <luiz@a2tec.com.br>
* @date		29/10/2020 (dd/mm/yyyy) 08:00
*/

#ifndef Gsm_h
#define Gsm_h

#include "Arduino.h"

class GSM {

public:
	void begin(String pin);
	void beginGPRS();
	void sms(String number, String msg);
	String web(String ip, String adress);
	String sendAT(String cmd, String wait, int time);
	void simpleAT(String cmd);
	String simpleRead();
	String parse(String s, String search);
private:
	boolean testPin();
	String sendCTR(boolean gprs);
	void serialFlush();
};

#endif
