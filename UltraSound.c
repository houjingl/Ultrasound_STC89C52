#include <regx52.h>

sbit Echo = P2^0;
sbit Trig = P2^1;

void UltraSound_Init(){ //using Timer0 for wave detect
	TMOD &= 0xF0;
	TMOD |= 0x01;
	
	TR0 = 0;
	TF0 = 0;

	TL0 = 0x00;	
	TH0 = 0x00;
	
	ET0 = 1;
	EA = 1;
	
	Trig = 0;
	Echo = 0;
	
}

void UltraSound_SendWave(){
	unsigned char i;
	for (i = 0; i < 20; i++){
		Trig = 1;
	}
	Trig = 0;
}

unsigned int UltraSound_MeasureDistance(){
	unsigned int Distance = 0;
	while(Echo == 0); //wait for ECHO to be lifted to high
	TR0 = 1;
	while(Echo);
	TR0 = 0;
	Distance = (TL0 + TH0 * 256) *1.7 /100; //in cm
	TL0 = 0x00;
	TH0 = 0x00;
	return Distance;
}
	