//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.H
// @Project       test3.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2267M-104F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains all function prototypes and macros for 
//                the MAIN module.
//
//----------------------------------------------------------------------------
// @Date          2018/11/1 16:59:43
//
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,1)

// USER CODE END



#ifndef _MAIN_H_
#define _MAIN_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************
#define KEIL

#define SEG(func) (unsigned int)(((unsigned long)((void (far*)(void))func) >> 16))
#define SOF(func) (unsigned int)(((void (far *) (void))func))

// USER CODE BEGIN (MAIN_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************


void MAIN_vUnlockProtecReg(void);

void MAIN_vLockProtecReg(void);

// USER CODE BEGIN (MAIN_Header,8)

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,9)

// USER CODE END


//****************************************************************************
// @Project Includes
//****************************************************************************

#include <Intrins.h>

#include  "XC22xxMREGS.H"
#include  "SCS.H"

#include  "IO.H"
#include  "GPT1.H"
#include  "GPT2.H"
#include  "ADC1.H"
#include  "CAN.H"

// USER CODE BEGIN (MAIN_Header,10)
 #include "math.h"
 #include "GetDealData.h"

#define DriveReadyLed		 P10_OUT_P4 //待驶指示灯
#define BreakLed      		 P0_OUT_P5  //刹车
#define Beep 			     P10_OUT_P3 //鸣笛
#define StartButton			 P7_IN_P2   //启动按钮检测 ，输入高为0
#define SafetyLoopDetection  P7_IN_P1	//安全回路检测，输入高为0
#define McBTB  				 P6_IN_P1	//电机控制器准备就绪检测 ，输入高为0


extern ubyte can1_send2[8]; //VCU向电机控制器发送转矩或转速指令
	 

extern int gear,gearWeight;
// USER CODE END


#endif  // ifndef _MAIN_H_
