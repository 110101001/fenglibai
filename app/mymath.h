/***
*mymath.h
*
*       
*
*Purpose:
*       This file defined the functions and variables used by users
*       to fast computation the result of trigonometric functions and
*       the square root.
****/
#include "stm32f4xx.h"

#ifndef __MYMATH_H__
#define __MYMATH_H__

#define REAL   float
#define TAN_MAP_RES     0.003921569f     /* (smallest non-zero value in table) */
#define RAD_PER_DEG     0.017453293f
#define TAN_MAP_SIZE    256
#define MY_PPPIII   3.14159f
#define MY_PPPIII_HALF   1.570796f

#define my_3_norm(x,y,z) (my_sqrt(my_pow((x)) + my_pow((y)) + my_pow((z))))
#define my_2_norm(x,y) (my_sqrt(my_pow((x)) + my_pow((y))))

#define my_pow(a) ((a)*(a))
#define safe_div(numerator,denominator,safe_value) ( (denominator == 0) ? (safe_value) : ((numerator)/(denominator)) )
#define ABS(x) ( (x)>0?(x):-(x) )
#define LIMIT( x,min,max ) ( (x) < (min)  ? (min) : ( (x) > (max) ? (max) : (x) ) )
#define _MIN(a, b) ((a) < (b) ? (a) : (b))
#define _MAX(a, b) ((a) > (b) ? (a) : (b))

#define my_pow_2_curve(in,a,max) (((1.0f - (a)) + (a) *ABS((in) / (max))) * in)
	
float my_abs(float f);
REAL fast_atan2(REAL y, REAL x);
//float my_pow(float a);
float my_sqrt(float number);
double mx_sin(double rad);
double my_sin(double rad);
float my_cos(double rad);
float my_deathzoom(float x,float ,float zoom);
float my_deathzoom_2(float x,float ,float zoom);

float my_deadzone_p(float x,float zone);
float my_deadzone_n(float x,float zone);

float To_180_degrees(float x);
double To_180_degrees_db(double x);
//float my_pow_2_curve(float in,float a,float max);
//float safe_div(float numerator ,float denominator,float sv);
float linear_interpolation_5(float range[5],float interpolation[5],float in);//range 必须从小到大

typedef struct
{
	float kp;
	float kd;
	float ki;
	float kdamp;

}pid_t;

typedef struct 
{
  float x;
	float y;
	float z;
}xyz_f_t;

typedef struct 
{
  s16 x;
	s16 y;
	s16 z;

}xyz_s16_t;


typedef union
{
	uint8_t raw_data[64];
	struct
	{
		xyz_f_t Accel;
		xyz_f_t Gyro;
		xyz_f_t Mag;
		xyz_f_t vec_3d_cali;
		uint32_t mpu_flag;
		float Acc_Temperature;
		float Gyro_Temperature;
	}Offset;
}sensor_setup_t; //__attribute__((packed)) 

typedef  struct{
pid_t roll;
pid_t pitch;	
pid_t yaw;	
 }pid_group_t;

typedef union
{
 uint8_t raw_data[192];
 struct
 {
	 pid_group_t ctrl1;
	 pid_group_t ctrl2;
 /////////////////////
	 pid_t hc_sp;
	 pid_t hc_height;
	 pid_t ctrl3;
	 pid_t ctrl4;
 	  
 }groups;

}pid_setup_t;

#endif

