#include "main.h"

PID_Type MX={0,0,0,0,0,0,0,0,0,0};
PID_Type MY={0,0,0,0,0,0,0,0,0,0};

extern PID_Type* Motor_X;
extern PID_Type* Motor_Y;

void All_Init(void)
{
	Motor_X=&MX;
	Motor_Y=&MY;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);    
	LED_Configuration();																//LED初始化
	TIM2_Configuration();	
  TIM5_Configuration(1000,83);
	Usart2_Init(115200);																//串口2初始化
	PWM_Configuration();																//PWM初始化
	GPIO_Configuration();																//GPIO初始化
	//Para_ResetToFactorySetup();													//从flash读取保存的参数
	//PID_Para_Init();																		//PID初始化
	I2c_Soft_Init();																		//iic初始化
	Delay_ms(200);																			//mpu6050初始化之前必要延时
	MPU6050_Init(20); 																	//mpu6050初始化，低通频率20Hz
	Delay_ms(100);																			//磁力计初始化前的延时
	ak8975_ok = !(ANO_AK8975_Run());										//磁力计初始化
	//TIM5_Start();																				//ControlLoop开始
}



