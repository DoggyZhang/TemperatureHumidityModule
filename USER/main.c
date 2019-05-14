#include "delay.h"
#include "sys.h"
#include "usart.h"	 
#include "dht11.h" 	
#include "stdio.h"
#include "string.h"
#include "m5310.h" 
#include "adc.h" 
 int main(void)
 {
  u16 adcx;	
  u16 temp;	 
  char string1[80];
  char ShiDu[80];
  char string2[80];
  char WenDu[80]; 	 
	u8 temperature;  	    
	u8 humidity;    	   
	delay_init();	    	 //延时函数初始化	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(9600);	 	//串口初始化为115200
	delay_ms(500);
	 M5310A_USART_init(9600); 
	 delay_ms(500);
   M5310_init();
//	Adc_Init();		  		//ADC初始化	 
	while(1)
	{	 

//    adcx=Get_Adc_Average(ADC_Channel_1,10);	
//		printf("adcx=%d\r\n",adcx);	
//    temp=adcx*(480.0/4096);	
//    printf("temp=%d\r\n",temp);		
		DHT11_Read_Data(&temperature,&humidity);	//读取温湿度值					    
	 	delay_ms(500);
	  printf("温度：%d\r\n",temperature);
		delay_ms(500);
	  printf("湿度：%d\r\n",humidity);
		
//		memset(string1,0,sizeof(string1));
//		memset(ShiDu,0,sizeof(ShiDu));
//		strcpy(ShiDu,"AT+MIPLNOTIFY=0,0,3304,0,5700,4,4,");
//		sprintf(string1,"\"%d\",0,0\r\n",humidity);
//		strcat(ShiDu,string1);
//		delay_ms(100);
//		M5310A_SendCmd(ShiDu,"OK");
//		
//		memset(string2,0,sizeof(string2));
//		memset(WenDu,0,sizeof(WenDu));
//		strcpy(WenDu,"AT+MIPLNOTIFY=0,0,3303,0,5700,4,4,");
//		sprintf(string2,"\"%d\",0,0\r\n",temperature);
//		strcat(WenDu,string2);
//		delay_ms(100);
//		M5310A_SendCmd(WenDu,"OK");
		
		memset(string1,0,sizeof(string1));
		memset(ShiDu,0,sizeof(ShiDu));
		strcpy(ShiDu,"AT+NSOSD=0,1,");
		sprintf(string1,"%2d\r\n",humidity);
		strcat(ShiDu,string1);
		delay_ms(100);
		M5310A_SendCmd(ShiDu,"OK");
	
		memset(string2,0,sizeof(string2));
		memset(WenDu,0,sizeof(WenDu));
		strcpy(WenDu,"AT+NSOSD=1,1,");
		sprintf(string2,"%2d\r\n",temperature);
		strcat(WenDu,string2);
		delay_ms(100);
		M5310A_SendCmd(WenDu,"OK");
	
//M5310A_SendCmd("AT+NSOSD=0,1,99\r\n","OK");
//        delay_ms(500);  
//	printf("获取9成功\r\n");
//   
	}
}




