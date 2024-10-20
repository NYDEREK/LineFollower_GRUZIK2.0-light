/*
 * SimpleParser.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Szymon
 */


#include "main.h"
#include "usart.h"
#include "string.h"
#include "stdio.h"
#include "RingBuffer.h"
#include "stdlib.h"
#include "SimpleParser.h"
#include "Line_Follower.h"
char My_Name[32] = "GRUZIK2.0";

void Parser_TakeLine(RingBuffer_t *Buf, uint8_t *ReceivedData)
{
	uint8_t Tmp;
	uint8_t i = 0;
	do
	{
		RB_Read(Buf, &Tmp);

		if(Tmp == ENDLINE)
		{
			ReceivedData[i] = 0;

		}

		else
		{
			ReceivedData[i] = Tmp;
		}
		i++;

	} while(Tmp != ENDLINE);

}

static void kp_change(LineFollower_t *LF)
{
	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0 && strlen(ParsePointer) < 32)
	{
		LF->Kp = atof(ParsePointer);
	}

}
static void kd_change(LineFollower_t *LF)
{
	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0 && strlen(ParsePointer) < 32)
	{
		LF->Kd = atof(ParsePointer);
	}
}
static void Base_speed_change(LineFollower_t *LF)
{
	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0 && strlen(ParsePointer) < 32)
	{
		LF->Base_speed_R = atof(ParsePointer);
		LF->Base_speed_L = atof(ParsePointer);
	}
}

static void Max_speed_change(LineFollower_t *LF)
{
	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0 && strlen(ParsePointer) < 32)
	{
		LF->Max_speed_R = atof(ParsePointer);
		LF->Max_speed_L = atof(ParsePointer);
	}
}
static void Sharp_bend_speed_right_change(LineFollower_t *LF)
{
	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0 && strlen(ParsePointer) < 32)
	{
	LF->Sharp_bend_speed_right = atof(ParsePointer);
	}
}
static void Sharp_bend_speed_left_change(LineFollower_t *LF)
{
	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0 && strlen(ParsePointer) < 32)
	{
	LF->Sharp_bend_speed_left = atof(ParsePointer);
	}
}
static void Bend_speed_right_change(LineFollower_t *LF)
{
	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0 && strlen(ParsePointer) < 32)
	{
	LF->Bend_speed_right = atof(ParsePointer);
	}
}
static void Bend_speed_left_change(LineFollower_t *LF)
{
	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0 && strlen(ParsePointer) < 32)
	{
	LF->Bend_speed_left = atof(ParsePointer);
	}
}
static void App_Controll(char RxData, LineFollower_t *LineFollower)
{
	/*Stop robot*/
	if(RxData == 'N')
	{
		/*Stop GRUZIK2.0 and turn off the LED*/
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

		/*Send battery percentage*/
		//SN_UART_Send(&huart1, "%.1f \r \n" ,battery_procentage_raw);

	}
	/*Start robot*/
	if (RxData == 'Y')
	{

//		/*Time mode*/
//		if(Is_time_mode)
//		{
//			/*Change mode to mode 2 for Start_time*/
//			RxData = Mode_Change(mode_1);
//			HAL_UART_RxCpltCallback(&huart1);
//
//			/*Start waiting for mode change*/
//			__HAL_TIM_SET_COUNTER(&htim1, Start_time);
//		}
//
//		/*Do Battery measurement before start*/
//		Battery_ADC_measurement();

		/*Start GRUZIK2.0 and turn on the LED*/
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	}
	/*LOW mode*/
	if(RxData == 'a')
	{
		LineFollower->Base_speed_R = 150;
		LineFollower->Base_speed_L = 150;
		LineFollower->Max_speed_L = 130;
		LineFollower->Max_speed_R = 130;
		LineFollower->Sharp_bend_speed_right=-115;
		LineFollower->Sharp_bend_speed_left=120;
		LineFollower->Bend_speed_right=-76;
		LineFollower->Bend_speed_left=125;
		LineFollower->Kp = 0.02;//0.02 //0.009
		LineFollower->Kd = 165;
	}
	/*LOW+ mode*/
	if(RxData == 'd')
	{
		LineFollower->Base_speed_R = 165;
		LineFollower->Base_speed_L = 165;
		LineFollower->Max_speed_L = 130;
		LineFollower->Max_speed_R = 130;
		LineFollower->Sharp_bend_speed_right=-120;
		LineFollower->Sharp_bend_speed_left=125;
		LineFollower->Bend_speed_right=-76;
		LineFollower->Bend_speed_left=125;
		LineFollower->Kp = 0.04;//0.4
		LineFollower->Kd = 75;
	}
	/*Medium mode*/
	if(RxData == 'b')
	{
		LineFollower->Base_speed_R = 175;
		LineFollower->Base_speed_L = 175;
		LineFollower->Max_speed_L = 135;
		LineFollower->Max_speed_R = 135;
		LineFollower->Sharp_bend_speed_right = -120;
		LineFollower->Sharp_bend_speed_left = 125;
		LineFollower->Bend_speed_right = -76;
		LineFollower->Bend_speed_left = 125;
		LineFollower->Kp = 0.03;//0.03
		LineFollower->Kd = 70;
	}
	/*Medium+ mode*/
	if(RxData == 'e')
	{
		LineFollower->Base_speed_R = 190;
		LineFollower->Base_speed_L = 190;
		LineFollower->Max_speed_L = 145;
		LineFollower->Max_speed_R = 145;
		LineFollower->Sharp_bend_speed_right = -100;
		LineFollower->Sharp_bend_speed_left = 100;
		LineFollower->Bend_speed_right = -76;
		LineFollower->Bend_speed_left = 125;
		LineFollower->Kp = 0.03;//0.03
		LineFollower->Kd = 70;
	}
	/*HIGH mode*/
	if(RxData == 'c')
	{
		LineFollower->Base_speed_R = 225;
		LineFollower->Base_speed_L = 225;
		LineFollower->Max_speed_L = 150;
		LineFollower->Max_speed_R = 150;
		LineFollower->Sharp_bend_speed_right = -73;
		LineFollower->Sharp_bend_speed_left = 78;
		LineFollower->Bend_speed_right = -76;
		LineFollower->Bend_speed_left = 125;
		LineFollower->Kp = 0.04;//0.04
		LineFollower->Kd = 75;
	}
	/*HIGH+ mode*/
	if(RxData == 'f')
	{
		LineFollower->Base_speed_R = 250;
		LineFollower->Base_speed_L = 250;
		LineFollower->Max_speed_L = 160;
		LineFollower->Max_speed_R = 160;
		LineFollower->Sharp_bend_speed_right = -65;
		LineFollower->Sharp_bend_speed_left = 70;
		LineFollower->Bend_speed_right=-76;
		LineFollower->Bend_speed_left=125;
		LineFollower->Kp = 0.04;
		LineFollower->Kd=75;
	}
	/*TRUBO mode*/
	if(RxData == 'i')
	{
		LineFollower->Base_speed_R = 270;
		LineFollower->Base_speed_L = 270;
		LineFollower->Max_speed_L = 150;
		LineFollower->Max_speed_R = 150;
		LineFollower->Sharp_bend_speed_right = -65;
		LineFollower->Sharp_bend_speed_left = 70;
		LineFollower->Bend_speed_right = -76;
		LineFollower->Bend_speed_left = 130;
		LineFollower->Kp = 0.045;
		LineFollower->Kd = 75;
	}
	/*TRUBO+ mode*/
	if(RxData == 'j')
	{
	   LineFollower->Base_speed_R = 295;
	   LineFollower->Base_speed_L = 295;
	   LineFollower->Max_speed_L = 165;
	   LineFollower->Max_speed_R = 165;
	   LineFollower->Sharp_bend_speed_right = -70;
	   LineFollower->Sharp_bend_speed_left = 73;
	   LineFollower->Bend_speed_right = -76;
	   LineFollower->Bend_speed_left = 130;
	   LineFollower->Kp = 0.05;
	   LineFollower->Kd = 80;
	}
	/*ULTRA mode*/
	if(RxData == 'k')
	{
		LineFollower->Base_speed_R = 315;
		LineFollower->Base_speed_L = 315;
		LineFollower->Max_speed_L = 168;
		LineFollower->Max_speed_R = 168;
		LineFollower->Sharp_bend_speed_right = -70;
		LineFollower->Sharp_bend_speed_left = 73;
		LineFollower->Bend_speed_right = -76;
		LineFollower->Bend_speed_left = 128;
		LineFollower->Kp = 0.067;
		LineFollower->Kd = 95;
	 }
	 /*ULTRA+ mode*/
	 if(RxData == 'l')
	 {
		LineFollower->Base_speed_R = 102;
		LineFollower->Base_speed_L = 102;
		LineFollower->Max_speed_L = 155;
		LineFollower->Max_speed_R = 155;
		LineFollower->Sharp_bend_speed_right = -90;
		LineFollower->Sharp_bend_speed_left = 185;
		LineFollower->Bend_speed_right = -50;
		LineFollower->Bend_speed_left = 100;
		LineFollower->Kp = 0.02;
		LineFollower->Kd = 350;
	  }
	  /*EXTREME mode*/
	  if(RxData == 'm')
	  {
		 LineFollower->Base_speed_R = 107;
		 LineFollower->Base_speed_L = 107;
		 LineFollower->Max_speed_L = 159;
		 LineFollower->Max_speed_R = 159;
		 LineFollower->Sharp_bend_speed_right = -90;
		 LineFollower->Sharp_bend_speed_left = 185;
		 LineFollower->Bend_speed_right = -50;
		 LineFollower->Bend_speed_left = 100;
		 LineFollower->Kp = 0.02;
		 LineFollower->Kd = 350;
	  }

 	  /*EXTREME+ mode*/
 	  if(RxData == 'n')
 	  {
 	    LineFollower->Base_speed_R = 116;
 	    LineFollower->Base_speed_L = 116;
 	    LineFollower->Max_speed_L = 167;
 	  	LineFollower->Max_speed_R = 167;
 	 	LineFollower->Sharp_bend_speed_right = -96;
 		LineFollower->Sharp_bend_speed_left = 185;
 		LineFollower->Bend_speed_right = -50;
 		LineFollower->Bend_speed_left = 100;
 		LineFollower->Kp = 0.02;
 		LineFollower->Kd = 350;
 	  }
 	  /*SPECIAL mode*/
 	  if(RxData == 'h')
 	  {
 	    LineFollower->Base_speed_R = 123;
 	    LineFollower->Base_speed_L = 123;
 	    LineFollower->Max_speed_L = 172;
 	    LineFollower->Max_speed_R = 172;
 	 	LineFollower->Sharp_bend_speed_right = -90;
 		LineFollower->Sharp_bend_speed_left = 185;
 		LineFollower->Bend_speed_right = -50;
 		LineFollower->Bend_speed_left = 100;
 		LineFollower->Kp = 0.02;
 		LineFollower->Kd = 350;
 	  }
 	  /*RA-1-final-slower*/
 	  if(RxData == 'o')
 	  {
 	    LineFollower->Base_speed_R = 143;
 	    LineFollower->Base_speed_L = 143;
 	   	LineFollower->Max_speed_L = 182;
 	  	LineFollower->Max_speed_R = 182;
 	  	LineFollower->Sharp_bend_speed_right = -76;
 		LineFollower->Sharp_bend_speed_left = 90;
 		LineFollower->Bend_speed_right = -50;
 		LineFollower->Bend_speed_left = 100;
 		LineFollower->Kp = 0.02;
 		LineFollower->Kd = 350;
 	   }
 	   /*RA-2-eliminations-faster*/
 	   if(RxData == 'u')
 	   {
 	     LineFollower->Base_speed_R = 153;
 	     LineFollower->Base_speed_L = 153;
 	     LineFollower->Max_speed_L = 187;
 	   	 LineFollower->Max_speed_R = 187;
 	  	 LineFollower->Sharp_bend_speed_right = -76;
 	 	 LineFollower->Sharp_bend_speed_left = 90;
 	 	 LineFollower->Bend_speed_right = -50;
 	 	 LineFollower->Bend_speed_left = 100;
 	 	 LineFollower->Kp = 0.02;
 	 	 LineFollower->Kd = 350;
 	   }
 	  /*Gruzik2.1 Robo Comp 2024r 1*/
 	  if(RxData == 'p')
 	  {
 		 LineFollower->Base_speed_R = 143;
 		 LineFollower->Base_speed_L = 143;
 		 LineFollower->Max_speed_L = 182;
 		 LineFollower->Max_speed_R = 182;
 		 LineFollower->Sharp_bend_speed_right = -76;
 		 LineFollower->Sharp_bend_speed_left = 90;
 		 LineFollower->Bend_speed_right = -40;//40
 		 LineFollower->Bend_speed_left = 110;
 		 LineFollower->Kp = 0.02;
 		 LineFollower->Kd = 350;
 	  }
 	  /*Gruzik2.1 Robo Comp 2024 2*/
 	  if(RxData == 'r')
 	  {
 		 LineFollower->Base_speed_R = 153;
 		 LineFollower->Base_speed_L = 153;
 		 LineFollower->Max_speed_L = 187;
 		 LineFollower->Max_speed_R = 187;
 		 LineFollower->Sharp_bend_speed_right = -76;
 		 LineFollower->Sharp_bend_speed_left = 90;
 		 LineFollower->Bend_speed_right = -40;//40
 		 LineFollower->Bend_speed_left = 110;
 		 LineFollower->Kp = 0.02;
 		 LineFollower->Kd = 350;
 	   }
}

static void Mode_change(LineFollower_t *LF)
{
	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0 && strlen(ParsePointer) < 2)
	{
		App_Controll(ParsePointer[0], LF);
	}
}
void Parser_Parse(uint8_t *ReceivedData, LineFollower_t *LineFollower)
{
	char *ParsePointer = strtok((char*)ReceivedData, "=");

	if(!strcmp("Kp",ParsePointer))
	{
		kp_change(LineFollower);
	}
	else if(!strcmp("Kd",ParsePointer))
	{
		kd_change(LineFollower);
	}
	else if(!strcmp("Base_speed",ParsePointer))
	{
		Base_speed_change(LineFollower);
	}
	else if(!strcmp("Max_speed",ParsePointer))
	{
		Max_speed_change(LineFollower);
	}
	else if(!strcmp("Sharp_bend_speed_right",ParsePointer))
	{
		Sharp_bend_speed_right_change(LineFollower);
	}
	else if(!strcmp("Sharp_bend_speed_left",ParsePointer))
	{
		Sharp_bend_speed_left_change(LineFollower);
	}
	else if(!strcmp("Bend_speed_right",ParsePointer))
	{
		Bend_speed_right_change(LineFollower);
	}
	else if(!strcmp("Bend_speed_left",ParsePointer))
	{
		Bend_speed_left_change(LineFollower);
	}
	else if(!strcmp("Mode",ParsePointer))
	{
		Mode_change(LineFollower);
	}
}