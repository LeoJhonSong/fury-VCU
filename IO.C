//****************************************************************************
// @Module        Parallel Ports
// @Filename      IO.C
// @Project       test3.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2267M-104F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains functions that use the IO module.
//
//----------------------------------------------------------------------------
// @Date          2018/11/1 16:59:45
//
//****************************************************************************

// USER CODE BEGIN (IO_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (IO_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (IO_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (IO_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (IO_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (IO_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (IO_General,9)

// USER CODE END


//****************************************************************************
// @Function      void IO_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the IO function 
//                library. It is assumed that the SFRs used by this library 
//                are in reset state. 
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

// USER CODE BEGIN (IO_Function,1)

// USER CODE END

void IO_vInit(void)
{
  // USER CODE BEGIN (IO_Function,2)

  // USER CODE END


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P0:
  ///  -----------------------------------------------------------------------
  ///  P0.4 is used as alternate input for the CAN1 Receive input(RXDC1B)
  ///  P0.5 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P0.6 is used as alternate output for the CAN1 Transmit Output(TXDC1A)
  ///  - push/pull output is selected

  ///  P0.0 - P0.3 output driver characteristic: strong driver
  ///  P0.4 - P0.7 output driver characteristic: strong driver

  ///  P0.0 - P0.3 output edge characteristic: sharp edge mode
  ///  P0.4 - P0.7 output edge characteristic: sharp edge mode

  P0_IOCR05      =  0x0080;      // load port control register 5

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P1:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P1 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P2:
  ///  -----------------------------------------------------------------------
  ///  P2.0 is used as alternate input for the CAN0 Receive input(RXDC0C)
  ///  P2.1 is used as alternate output for the CAN0 Transmit output(TXDC0C)
  ///  - push/pull output is selected

  ///  P2.0 - P2.3 output driver characteristic: strong driver
  ///  P2.4 - P2.7 output driver characteristic: strong driver
  ///  P2.8 - P2.13 output driver characteristic: strong driver

  ///  P2.0 - P2.3 output edge characteristic: sharp edge mode
  ///  P2.4 - P2.7 output edge characteristic: sharp edge mode
  ///  P2.8 - P2.13 output edge characteristic: sharp edge mode


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P4:
  ///  -----------------------------------------------------------------------
  ///  P4.2 is used as alternate output for the CAN2 Transmit output(TXDC2B)
  ///  - push/pull output is selected
  ///  P4.3 is used as alternate input for the CAN2 Receive inputA(RXDC2A)

  ///  P4.0 - P4.3 output driver characteristic: strong driver

  ///  P4.0 - P4.3 output edge characteristic: sharp edge mode


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P5:
  ///  -----------------------------------------------------------------------
  ///  P5.10 is used as general input
  ///  P5.11 is used as general input
  ///  P5.13 is used as general input
  ///  P5.15 is used as general input


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P6:
  ///  -----------------------------------------------------------------------
  ///  P6.0 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P6.1 is used as general input
  ///  - pull device is tristate 

  ///  P6.0 - P6.2 output driver characteristic: strong driver

  ///  P6.0 - P6.2 output edge characteristic: sharp edge mode

  P6_IOCR00      =  0x0080;      // load port control register 0

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P7:
  ///  -----------------------------------------------------------------------
  ///  P7.1 is used as general input
  ///  - pull device is tristate 
  ///  P7.2 is used as general input
  ///  - pull device is tristate 

  ///  P7.0 - P7.3 output driver characteristic: strong driver
  ///  P7.4 - P7.4 output driver characteristic: strong driver

  ///  P7.0 - P7.3 output edge characteristic: sharp edge mode
  ///  P7.4 - P7.4 output edge characteristic: sharp edge mode


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P10:
  ///  -----------------------------------------------------------------------
  ///  P10.3 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.4 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level

  ///  P10.0 - P10.3 output driver characteristic: strong driver
  ///  P10.4 - P10.7 output driver characteristic: strong driver
  ///  P10.8 - P10.11 output driver characteristic: strong driver
  ///  P10.12 - P10.15 output driver characteristic: strong driver

  ///  P10.0 - P10.3 output edge characteristic: sharp edge mode
  ///  P10.4 - P10.7 output edge characteristic: sharp edge mode
  ///  P10.8 - P10.11 output edge characteristic: sharp edge mode
  ///  P10.12 - P10.15 output edge characteristic: sharp edge mode

  P10_IOCR03     =  0x0080;      // load port control register 3
  P10_IOCR04     =  0x0080;      // load port control register 4

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P15:
  ///  -----------------------------------------------------------------------
  ///  P15.0 is used as alternate input for the  Analog Input Pin (AN0)
  ///  P15.2 is used as alternate input for the  Analog Input Pin (AN2)
  ///  P15.4 is used as alternate input for the  Analog Input Pin (AN4)



  // USER CODE BEGIN (IO_Function,3)

  // USER CODE END

} //  End of function IO_vInit




// USER CODE BEGIN (IO_General,10)

// USER CODE END

