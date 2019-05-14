#include "m5310.h"
#include "sys.h"
#include "string.h"
#include "usart.h"
#include "delay.h"

char M5310A_buffer[250];

short M5310A_cnt = 0, M5310A_cntPre = 0;

//==========================================================
//	�������ƣ�	M5310_Clear
//
//	�������ܣ�	��ջ���
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����		
//==========================================================
void M5310A_Clear(void)
{
	memset(M5310A_buffer, 0, sizeof(M5310A_buffer));
	M5310A_cnt = 0;
}

//==========================================================
//	�������ƣ�	M5310_init
//
//	�������ܣ�	���Գ�ʼ��
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����		
//==========================================================
//   AT+CGSN=1;��ѯIMEI��
//   AT+CIMI;  ��ѯIMSI��
void M5310_init(void)
{   
  
//    M5310A_SendCmd("AT+CGATT=1\r\n","OK");
//        delay_ms(500);
//          delay_ms(500);  
//	  printf("��ȡ1�ɹ�\r\n");
//    
//    M5310A_SendCmd("AT+CSCON=1\r\n","OK");
//        delay_ms(500);
//	       delay_ms(500);
//	  printf("��ȡ2�ɹ�\r\n");	
//    delay_ms(500);
//    
//    M5310A_SendCmd("AT+CEREG=1\r\n","OK");       
//        delay_ms(500); 
//	  printf("��ȡ3�ɹ�\r\n");
//		delay_ms(500);
//    delay_ms(500);
//    
//    M5310A_SendCmd("AT+MIPLCREATE=49,130031F10003F2002304001100000000000000123138332E3233302E34302E34303A35363833000131F30008C000000000,0,49,0\r\n","+MIPLCREATE:0");   
//        delay_ms(500);
//        delay_ms(500);
//        delay_ms(500);	
//	  printf("ע���豸�ɹ�\r\n");
//    delay_ms(500);
//		delay_ms(500);
//		 delay_ms(500);
//    M5310A_SendCmd("AT+MIPLADDOBJ=0,3304,1,\"1\",1,0\r\n","OK");
//			delay_ms(500);
//			 delay_ms(500);
//		M5310A_SendCmd("AT+MIPLADDOBJ=0,3303,1,\"1\",1,0\r\n","OK");
//			delay_ms(500);
//			 delay_ms(500);
//  	printf("����\r\n");     
//    delay_ms(500); 
//   delay_ms(500);		
//	  M5310A_SendCmd("AT+MIPLNOTIFY=0,0,3304,0,5700,4,4,\"28.9\",0,0\r\n","OK");
//			delay_ms(500);
//			 delay_ms(500);
//	  M5310A_SendCmd("AT+MIPLNOTIFY=0,0,3303,0,5700,4,4,\"28.9\",0,0\r\n","OK");
//			delay_ms(500);
//			 delay_ms(500);
//    	printf("����Դ\r\n");      
//       delay_ms(500); 	
//	    printf("�������ʳɹ�\r\n");
//			 delay_ms(500);
//			  delay_ms(500);
//	  M5310A_SendCmd("AT+MIPLOPEN=0,3000,30\r\n","+MIPLEVENT:0,6");
//    delay_ms(500); 
//    delay_ms(500);
//    delay_ms(500);
//	  printf("������ƽ̨�ɹ�\r\n");	 

   while(M5310A_SendCmd("AT+CGATT=1\r\n","OK"))
        delay_ms(500);  
	printf("��ȡ1�ɹ�\r\n");
    delay_ms(500);
    
    while(M5310A_SendCmd("AT+CSCON=1\r\n","OK"))
        delay_ms(500);
	printf("��ȡ2�ɹ�\r\n");	
    delay_ms(500);
    
    while(M5310A_SendCmd("AT+CEREG=1\r\n","OK"))        
        delay_ms(500); 
	printf("��ȡ3�ɹ�\r\n");
    delay_ms(500);
    
//    while(M5310A_SendCmd("AT+CGATT?\r\n","+CGATT:1"))        
//        delay_ms(500);
//	printf("��ȡ4�ɹ�\r\n");	
//    delay_ms(500);
//    
//    while(M5310A_SendCmd("AT+CEREG?\r\n","+CEREG:1,1"))        
//        delay_ms(500);  
//	printf("��ȡ5�ɹ�\r\n");
//    delay_ms(500);
//    
//    while(M5310A_SendCmd("AT+CSCON?\r\n","+CSCON:1,1"))       
//        delay_ms(500);
//	printf("��ȡ6�ɹ�\r\n");
//    delay_ms(500);
    while(M5310A_SendCmd("AT+NSOCR=\"STREAM\",6,0,1\r\n","OK"))
        delay_ms(500);  
	printf("��ȡ7�ɹ�\r\n");
    delay_ms(500);
		while(M5310A_SendCmd("AT+NSOCR=\"STREAM\",6,0,1\r\n","OK"))
        delay_ms(500);  
	printf("��ȡ8�ɹ�\r\n");
    delay_ms(500);
		
		
		 while(M5310A_SendCmd("AT+NSOCO=0,112.74.36.137,8080\r\n","OK"))
        delay_ms(500);  
	printf("��ȡ8�ɹ�\r\n");
    delay_ms(500);
		 		
		 while(M5310A_SendCmd("AT+NSOCO=1,112.74.36.137,8080\r\n","OK"))
        delay_ms(500);  
	printf("��ȡ8�ɹ�\r\n");
    delay_ms(500);
		 
//    while(M5310A_SendCmd("AT+NPING=\"www.baidu.com\"\r\n","+NPING:"))       
//        delay_ms(500);
//	printf("�����ɹ�\r\n");
//    delay_ms(500);
//    
//    while(M5310A_SendCmd("AT+MIPLCREATE=49,130031F10003F2002304001100000000000000123138332E3233302E34302E34303A35363833000131F30008C000000000,0,49,0\r\n","+MIPLCREATE:0"))    
//        delay_ms(500); 
//	printf("ע���豸�ɹ�\r\n");
//    delay_ms(500);
//    
//    while(M5310A_SendCmd("AT+MIPLADDOBJ=0,3304,1,\"1\",1,0\r\n","OK"))       
//        delay_ms(500);
//	printf("�������ʳɹ�\r\n");
//    delay_ms(500);
//    
//    while(M5310A_SendCmd("AT+MIPLADDOBJ=0,3300,1,\"1\",1,0\r\n","OK"))       
//        delay_ms(500); 
//	printf("����Ѫ���ɹ�\r\n");
//    delay_ms(500);
//    
//    while(M5310A_SendCmd("AT+MIPLADDOBJ=0,3303,1,\"1\",1,0\r\n","OK"))       
//        delay_ms(500); 
//	printf("�����¶ȳɹ�\r\n");
//    delay_ms(500);
//    
////AT+MIPLNOTIFY=0,0,3304,0,5700,4,4,"21",0,0

//		
//		
//    while(M5310A_SendCmd("AT+MIPLOPEN=0,3000,30\r\n","+MIPLEVENT:0,6"))       
//        delay_ms(500);  
//	printf("������ƽ̨�ɹ�\r\n");	
//    delay_ms(500);  


				
}
//==========================================================
//	�������ƣ�	M5310_USART_init
//
//	�������ܣ�	��ʼ��M5310-A
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����		
//==========================================================
void M5310A_USART_init(u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    //PB10 TX
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//PB11 RX
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);  
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	
	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART3, &USART_InitStructure);
	
	  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART3, ENABLE);
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	
  	USART_ClearFlag(USART3, USART_FLAG_TC);
    
    M5310A_Clear();
}
//==========================================================
//	�������ƣ�	M5310A_WaitRecive
//
//	�������ܣ�	�ȴ��������
//
//	��ڲ�����	��
//
//	���ز�����	0-�������		1-���ճ�ʱδ���
//
//	˵����		ѭ�����ü���Ƿ�������
//==========================================================
_Bool M5310A_WaitRecive(void)
{
	if(M5310A_cnt == 0) 						//������ռ���Ϊ0 ��˵��û�д��ڽ��������У�����ֱ����������������
		return 1;		
	if(M5310A_cnt == M5310A_cntPre)				//�����һ�ε�ֵ�������ͬ����˵���������
	{
		M5310A_cnt = 0;							//��0���ռ���			
		return 0;								//���ؽ�����ɱ�־
	}		
	M5310A_cntPre = M5310A_cnt;					//��Ϊ��ͬ	
	return 1;								    //���ؽ���δ��ɱ�־
}
//==========================================================
//	�������ƣ�	M5310A_SendCmd
//
//	�������ܣ�	��������
//
//	��ڲ�����	cmd������
//				res����Ҫ���ķ���ָ��
//
//	���ز�����	0-�ɹ�	1-ʧ��
//
//	˵����		
//==========================================================
_Bool M5310A_SendCmd(char *cmd, char *res)
{
    unsigned char timeOut = 200;
	Usart_SendString(USART3, (unsigned char *)cmd, strlen((const char *)cmd));	   
    M5310A_Clear();
	while(timeOut--)
	{
		if(M5310A_WaitRecive() == 0)	
		{
			if(strstr((const char *)M5310A_buffer, res) != NULL)	
			{
				M5310A_Clear();								
				return 0;
			}
		}		
		delay_ms(15);
	}
	return 1;
}
//==========================================================
//	�������ƣ�	Usart_SendString
//
//	�������ܣ�	�����ַ�
//
//	��ڲ�����	str���ַ�
//				len������
//
//	���ز�����	��
//
//	˵����		
//==========================================================
void Usart_SendString(USART_TypeDef *USARTx, unsigned char *str, unsigned short len)
{
	unsigned short count = 0;
	for(; count < len; count++)
	{
		USART_SendData(USARTx, *str++);								
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);		
	}
}
//==========================================================
//	�������ƣ�	USART3_IRQHandler
//
//	�������ܣ�	����2�շ��ж�
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����		
//==========================================================
void USART3_IRQHandler(void)
{
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET) //�����ж�
	{
		if(M5310A_cnt >= sizeof(M5310A_buffer))	
            M5310A_cnt = 0;
		M5310A_buffer[M5310A_cnt++] = USART_ReceiveData(USART3);		
		USART_ClearFlag(USART3, USART_FLAG_RXNE);
	}
}
