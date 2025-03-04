#include <regx52.h>
#include "lcd1602.h"
#include "delay.h"
#include "Ultrasound.h"


void main(){
	unsigned int Distance;
	UltraSound_Init();
	LCD_Init();
	LCD_ShowString(1,1,"Distance:");
	LCD_ShowString(2,5,"cm");
	while(1){
		UltraSound_SendWave();
		Distance = UltraSound_MeasureDistance();
		LCD_ShowNum(2,1,Distance,3);
		delay(600);
	}
}


	