//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.C
// @Project       test3.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2267M-104F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          2018/11/1 16:59:43
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (MAIN_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (MAIN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void MAIN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2018/11/1
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

ubyte can1_send2[8]={0xa0,0x73,0x00,0x00,0x02,0x02,0x00,0x00}; //VCU向电机控制器发送转矩或转速指令
 	/*
    百分比	10%   20%   30%	   40%		50% 	60% 	70% 	80% 	90% 	99%	
		加权值	33	  65	98	   130		163		192		228		261		294		327
	*/
 int gear=1,gearWeight=1;

// USER CODE END

void MAIN_vInit(void)
{

  SCS_ErrorType Error;

  // USER CODE BEGIN (Init,2)

  // USER CODE END

  //   globally disable interrupts
  PSW_IEN        =  0;          

  ///  -----------------------------------------------------------------------
  ///  Configuration of the System Clock:
  ///  -----------------------------------------------------------------------
  ///  - VCO clock used, input clock is connected
  ///  - input frequency is 8.00 MHz
  ///  - configured system frequency is 80.00 MHz
  ///  - system clock is 80.00MHz

  MAIN_vUnlockProtecReg();     // unlock write security

  // initialize CCU6 timer T13 for SCS driver
  SCS_InitTimer();

  // perform transition from base mode to normal operating mode
  Error = SCS_GoFromBaseToNormalMode();

  // restore CCU6 timer used by SCS driver
  SCS_RestoreTimer();

  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------

  //   initializes the Parallel Ports
  IO_vInit();

  //   initializes the General Purpose Timer Unit (GPT1)
  GPT1_vInit();

  //   initializes the General Purpose Timer Unit (GPT2)
  GPT2_vInit();

  //   initializes the Analog / Digital Converter (ADC1)
  ADC1_vInit();

  //   initializes the MultiCAN Module (CAN)
  CAN_vInit();


  //   -----------------------------------------------------------------------
  //   Initialization of the Bank Select registers:
  //   -----------------------------------------------------------------------


  // USER CODE BEGIN (Init,3)

  // USER CODE END

  MAIN_vLockProtecReg();       // lock write security

  //   globally enable interrupts
  PSW_IEN        =  1;          

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vUnlockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to write one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2018/11/1
//
//****************************************************************************

// USER CODE BEGIN (UnlockProtecReg,1)

// USER CODE END

void MAIN_vUnlockProtecReg(void)
{

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1
    SCU_SLC = 0x96FF;                   // command 2
    SCU_SLC = 0x0000;                   // command 3

} //  End of function MAIN_vUnlockProtecReg


//****************************************************************************
// @Function      void MAIN_vLockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to lock one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2018/11/1
//
//****************************************************************************

// USER CODE BEGIN (LockProtecReg,1)

// USER CODE END

void MAIN_vLockProtecReg(void)
{

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1
    SCU_SLC = 0x96FF;                   // command 2
    SCU_SLC = 0x1800;                   // command 3;
    SCU_SLC = 0x8EFF;                   // command 4

} //  End of function MAIN_vLockProtecReg


//****************************************************************************
// @Function      void main(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2018/11/1
//
//****************************************************************************

// USER CODE BEGIN (Main,1)

// USER CODE END

void main(void)
{
  // USER CODE BEGIN (Main,2)

  // USER CODE END

  MAIN_vInit();

  // USER CODE BEGIN (Main,3)
  	/*
		百分比	10%   20%   30%	   40%		50% 	60% 	70% 	80% 	90% 	99%	
		加权值	33	  65	98	   130		163		192		228		261		294		327
	*/
 	   if(P5_IN_P10==1&&P5_IN_P11==1&&P5_IN_P13==1&&P5_IN_P15==1) {gear=1; gearWeight=2;}  //20%
  else if(P5_IN_P10==0&&P5_IN_P11==1&&P5_IN_P13==1&&P5_IN_P15==1) {gear=2; gearWeight=4;} //40%
  else if(P5_IN_P10==1&&P5_IN_P11==0&&P5_IN_P13==1&&P5_IN_P15==1) {gear=3; gearWeight=6;} //60%
  else if(P5_IN_P10==1&&P5_IN_P11==1&&P5_IN_P13==0&&P5_IN_P15==1) {gear=4; gearWeight=8;} //70%
  else if(P5_IN_P10==1&&P5_IN_P11==1&&P5_IN_P13==1&&P5_IN_P15==0) {gear=5; gearWeight=9;} //80%
  else if(P5_IN_P10==0&&P5_IN_P11==0&&P5_IN_P13==0&&P5_IN_P15==0) {gear=6; gearWeight=10;} //99%
  
  else {gear=1; gearWeight=2;}
  
  // USER CODE END

  while(1)
  {

   // USER CODE BEGIN (Main,4)


	  // P10_OUT_P4=1;
	 
//	if(P7_IN_P2 == 0){
//		P0_OUT_P5 = 1;		   		//高边开关2 待驶指示灯亮
//		P10_OUT_P3 = 1;				//高边开关1	 鸣笛开
//	 }
//	 else{
//	 	P0_OUT_P5 = 0;		   		//高边开关2 待驶指示灯灭
//		P10_OUT_P3 = 0;				//高边开关1	 鸣笛关
//	}


   // USER CODE END

  }

} //  End of function main



// USER CODE BEGIN (MAIN_General,10)

// USER CODE END

