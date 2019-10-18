//****************************************************************************
// @Module        MultiCAN Module (CAN)
// @Filename      CAN.C
// @Project       test3.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2267M-104F80
//
// @Compiler      Keil
//
// @Codegenerator 2.0
//
// @Description   This file contains functions that use the CAN module.
//
//----------------------------------------------------------------------------
// @Date          2018/11/1 16:59:46
//
//****************************************************************************



// USER CODE BEGIN (CAN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (CAN_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CAN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (CAN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CAN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************


// USER CODE BEGIN (CAN_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (CAN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (CAN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void CAN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the CAN function 
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

// USER CODE BEGIN (Init,1)

// USER CODE END

void CAN_vInit(void)
{

  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of Kernel State Configuration Register:
  ///  -----------------------------------------------------------------------
  ///  - Enable the CAN module(MODEN)
  ///  - Enable Bit Protection for MODEN

    MCAN_KSCCFG  =  0x0003;      // load Kernel State Configuration Register

    _nop_();  // one cycle delay 

    _nop_();  // one cycle delay 


  ///  -----------------------------------------------------------------------
  ///  Configuration of the Module Clock:
  ///  -----------------------------------------------------------------------
  ///  - the CAN module clock = 40.00 MHz
  ///  - Normal divider mode selected

    CAN_FDRL     =  0x43FE;      // load Fractional Divider Register

  ///  -----------------------------------------------------------------------
  ///  Panel Control
  ///  -----------------------------------------------------------------------
  ///  - wait until Panel has finished the initialisation

    while(CAN_PANCTRL & CAN_PANCTR_BUSY){ // wait until Panel has finished 
                                          // the initialisation
      }                         

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node 0:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node 0:
  ///  - set INIT and CCE

    CAN_NCR0     =  0x0041;      // load NODE 0 control register[15-0]

  ///  - load NODE 0 interrupt pointer register

    CAN_NIPR0    =  0x0000;      // load NIPR0_LECINP, ALINP, CFCINP and TRINP

  ///  Configuration of the used CAN Port Pins:
  ///  - Loop-back mode is disabled
  ///  - P2.0 is used for CAN0 Receive input(RXDC0C)
  ///  - P2.1 is used for CAN0 Transmit output(TXDC0C)

  P2_IOCR01 = 0x0090;    //set direction register
    CAN_NPCR0    =  0x0002;      // load node0 port control register


  ///  Configuration of the Node 0 Baud Rate:
  ///  - required baud rate = 250.000 kbaud
  ///  - real baud rate     = 250.000 kbaud
  ///  - sample point       = 60.00 %
  ///  - there are 5 time quanta before sample point
  ///  - there are 4 time quanta after sample point
  ///  - the (re)synchronization jump width is 2 time quanta

    CAN_NBTR0L   =  0x344F;      // load NBTR0_DIV8, TSEG2, TSEG1, SJW and BRP

  ///  Configuration of the Node 0 Error Counter:
  ///  - the error warning threshold value (warning level) is 96

    CAN_NECNT0H = 0x0060;        // load NECNT0_EWRNLVL register
    CAN_NECNT0L = 0x0000;       

  ///  Configuration of the Frame Counter:
  ///  - Frame Counter Mode: the counter is incremented upon the reception 
  ///    and transmission of frames
  ///  - frame counter: 0x0000

    CAN_NFCR0H = 0x0000;         // load NFCR0_CFCOV, CFCIE, CFMOD, CFSEL
    CAN_NFCR0L = 0x0000;         // load NFCR0_CFC

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node 1:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node 1:
  ///  - set INIT and CCE

    CAN_NCR1     =  0x0041;      // load NODE 1 control register[15-0]

  ///  - load NODE 1 interrupt pointer register

    CAN_NIPR1    =  0x0000;      // load NIPR1_LECINP, ALINP, CFCINP and TRINP

  ///  Configuration of the used CAN Port Pins:
  ///  - Loop-back mode is disabled
  ///  - P0.4 is used for CAN1 Receive input(RXDC1B)
  ///  - P0.6 is used for CAN1 Transmit Output(TXDC1A)

  P0_IOCR06 = 0x00A0;    //set direction register
    CAN_NPCR1    =  0x0001;      // load node1 port control register


  ///  Configuration of the Node 1 Baud Rate:
  ///  - required baud rate = 250.000 kbaud
  ///  - real baud rate     = 250.000 kbaud
  ///  - sample point       = 60.00 %
  ///  - there are 5 time quanta before sample point
  ///  - there are 4 time quanta after sample point
  ///  - the (re)synchronization jump width is 2 time quanta

    CAN_NBTR1L   =  0x344F;      // load NBTR1_DIV8, TSEG2, TSEG1, SJW and BRP

  ///  Configuration of the Node 1 Error Counter:
  ///  - the error warning threshold value (warning level) is 96

    CAN_NECNT1H = 0x0060;        // load NECNT1_EWRNLVL register
    CAN_NECNT1L = 0x0000;       

  ///  Configuration of the Frame Counter:
  ///  - Frame Counter Mode: the counter is incremented upon the reception 
  ///    and transmission of frames
  ///  - frame counter: 0x0000

    CAN_NFCR1H = 0x0000;         // load NFCR1_CFCOV, CFCIE, CFMOD, CFSEL
    CAN_NFCR1L = 0x0000;         // load NFCR1_CFC

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node 2:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node 2:
  ///  - set INIT and CCE

    CAN_NCR2     =  0x0041;      // load NODE 2 control register[15-0]

  ///  - load NODE 2 interrupt pointer register

    CAN_NIPR2    =  0x0000;      // load NIPR2_LECINP, ALINP, CFCINP and TRINP

  ///  Configuration of the used CAN Port Pins:
  ///  - Loop-back mode is disabled
  ///  - P4.3 is used for CAN2 Receive inputA(RXDC2A)
  ///  - P4.2 is used for CAN2 Transmit output(TXDC2B)

  P4_IOCR02 = 0x00A0;    //set direction register
    CAN_NPCR2    =  0x0000;      // load node2 port control register


  ///  Configuration of the Node 2 Baud Rate:
  ///  - required baud rate = 250.000 kbaud
  ///  - real baud rate     = 250.000 kbaud
  ///  - sample point       = 60.00 %
  ///  - there are 5 time quanta before sample point
  ///  - there are 4 time quanta after sample point
  ///  - the (re)synchronization jump width is 2 time quanta

    CAN_NBTR2L   =  0x344F;      // load NBTR2_DIV8, TSEG2, TSEG1, SJW and BRP

  ///  Configuration of the Node 2 Error Counter:
  ///  - the error warning threshold value (warning level) is 96

    CAN_NECNT2H = 0x0060;        // load NECNT2_EWRNLVL register
    CAN_NECNT2L = 0x0000;       

  ///  Configuration of the Frame Counter:
  ///  - Frame Counter Mode: the counter is incremented upon the reception 
  ///    and transmission of frames
  ///  - frame counter: 0x0000

    CAN_NFCR2H = 0x0000;         // load NFCR2_CFCOV, CFCIE, CFMOD, CFSEL
    CAN_NFCR2L = 0x0000;         // load NFCR2_CFC

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node 3:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node 3:
  ///  - set INIT and CCE

    CAN_NCR3     =  0x0041;      // load NODE 3 control register[15-0]

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node 4:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node 4:
  ///  - set INIT and CCE

    CAN_NCR4     =  0x0041;      // load NODE 4 control register[15-0]

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAN Node 5:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Node 5:
  ///  - set INIT and CCE

    CAN_NCR5     =  0x0041;      // load NODE 5 control register[15-0]

  ///  -----------------------------------------------------------------------
  ///  Configuration of the CAN Message Object List Structure:
  ///  -----------------------------------------------------------------------

  ///  Allocate MOs for list 1:

    SetListCommand(0x0105,0x0002);  // MO5 for list 1 (Node 0)

    SetListCommand(0x0102,0x0002);  // MO2 for list 1 (Node 0)

    SetListCommand(0x0101,0x0002);  // MO1 for list 1 (Node 0)

  ///  Allocate MOs for list 2:

    SetListCommand(0x0204,0x0002);  // MO4 for list 2 (Node 1)

    SetListCommand(0x0203,0x0002);  // MO3 for list 2 (Node 1)

  ///  Allocate MOs for list 3:

    SetListCommand(0x0300,0x0002);  // MO0 for list 3 (Node 2)

  ///  -----------------------------------------------------------------------
  ///  Configuration of the CAN Message Objects 0 - 254:
  ///  -----------------------------------------------------------------------
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 0:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Message Object 0 :
  ///  - message object 0 is valid
  ///  - message object is used as transmit object
  ///  - this message object is assigned to list 3 (node 2)

    CAN_MOCTR0H = 0x0EA8;        // load MO0 control register high
    CAN_MOCTR0L = 0x0000;        // load MO0 control register low

  ///  Configuration of Message Object 0 Arbitration:
  ///  - priority class 1; transmit acceptance filtering is based on the list 
  ///    order
  ///  - standard 11-bit identifier
  ///  - identifier 11-bit:      0x203

    CAN_MOAR0H = 0x480C;         // load MO0 arbitration register high
    CAN_MOAR0L = 0x0000;         // load MO0 arbitration register low

  ///  Configuration of Message Object 0 Data:

    CAN_MODATA0HH = 0x0000;      // load MO0 Data Bytes(DB7 & DB6)
    CAN_MODATA0HL = 0x0000;      // load MO0 Data Bytes(DB5 & DB4)
    CAN_MODATA0LH = 0x0000;      // load MO0 Data Bytes(DB3 & DB2)
    CAN_MODATA0LL = 0x0000;      // load MO0 Data Bytes(DB1 & DB0)

  ///  Configuration of Message Object 0 acceptance mask:
  ///  - only accept receive frames with matching IDE bit
  ///  - acceptance mask 11-bit: 0x7FF

    CAN_MOAMR0H = 0x3FFF;        // load MO0 acceptance mask register high
    CAN_MOAMR0L = 0xFFFF;        // load MO0 acceptance mask register low

  ///  Configuration of Message Object 0 interrupt pointer:
  ///  - use message pending register 0 bit position 0

    CAN_MOIPR0H = 0x0000;        // load MO0 interrupt pointer register high
    CAN_MOIPR0L = 0x0000;        // load MO0 interrupt pointer register low

  ///  Configuration of Message Object 0 FIFO/Gateway pointer:

    CAN_MOFGPR0H = 0x0000;       // load MO0 FIFO/gateway pointer register 
                                 // high
    CAN_MOFGPR0L = 0x0000;       // load MO0 FIFO/gateway pointer register low


  ///  Configuration of Message Object 0 Function control:
  ///  - this object is a STANDARD MESSAGE OBJECT
  ///  - 8 valid data bytes

    CAN_MOFCR0H = 0x0800;        // load MO0 function control register high
    CAN_MOFCR0L = 0x0000;        // load MO0 function control register low

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 1:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Message Object 1 :
  ///  - message object 1 is valid
  ///  - message object is used as transmit object
  ///  - this message object is assigned to list 1 (node 0)

    CAN_MOCTR1H = 0x0EA8;        // load MO1 control register high
    CAN_MOCTR1L = 0x0000;        // load MO1 control register low

  ///  Configuration of Message Object 1 Arbitration:
  ///  - priority class 1; transmit acceptance filtering is based on the list 
  ///    order
  ///  - extended 29-bit identifier
  ///  - identifier 29-bit:      0x08C1EF21

    CAN_MOAR1H = 0x68C1;         // load MO1 arbitration register high
    CAN_MOAR1L = 0xEF21;         // load MO1 arbitration register low

  ///  Configuration of Message Object 1 Data:

    CAN_MODATA1HH = 0x0000;      // load MO1 Data Bytes(DB7 & DB6)
    CAN_MODATA1HL = 0x0000;      // load MO1 Data Bytes(DB5 & DB4)
    CAN_MODATA1LH = 0x0000;      // load MO1 Data Bytes(DB3 & DB2)
    CAN_MODATA1LL = 0x0000;      // load MO1 Data Bytes(DB1 & DB0)

  ///  Configuration of Message Object 1 acceptance mask:
  ///  - only accept receive frames with matching IDE bit
  ///  - acceptance mask 29-bit: 0x1FFFFFFF

    CAN_MOAMR1H = 0x3FFF;        // load MO1 acceptance mask register high
    CAN_MOAMR1L = 0xFFFF;        // load MO1 acceptance mask register low

  ///  Configuration of Message Object 1 interrupt pointer:
  ///  - use message pending register 0 bit position 1

    CAN_MOIPR1H = 0x0000;        // load MO1 interrupt pointer register high
    CAN_MOIPR1L = 0x0100;        // load MO1 interrupt pointer register low

  ///  Configuration of Message Object 1 FIFO/Gateway pointer:

    CAN_MOFGPR1H = 0x0000;       // load MO1 FIFO/gateway pointer register 
                                 // high
    CAN_MOFGPR1L = 0x0000;       // load MO1 FIFO/gateway pointer register low


  ///  Configuration of Message Object 1 Function control:
  ///  - this object is a STANDARD MESSAGE OBJECT
  ///  - 8 valid data bytes

    CAN_MOFCR1H = 0x0800;        // load MO1 function control register high
    CAN_MOFCR1L = 0x0000;        // load MO1 function control register low

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 2:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Message Object 2 :
  ///  - message object 2 is valid
  ///  - message object is used as receive object
  ///  - this message object is assigned to list 1 (node 0)

    CAN_MOCTR2H = 0x00A0;        // load MO2 control register high
    CAN_MOCTR2L = 0x0000;        // load MO2 control register low

  ///  Configuration of Message Object 2 Arbitration:
  ///  - priority class 1; transmit acceptance filtering is based on the list 
  ///    order
  ///  - extended 29-bit identifier
  ///  - identifier 29-bit:      0x0CFFC6EF

    CAN_MOAR2H = 0x6CFF;         // load MO2 arbitration register high
    CAN_MOAR2L = 0xC6EF;         // load MO2 arbitration register low

  ///  Configuration of Message Object 2 acceptance mask:
  ///  - only accept receive frames with matching IDE bit
  ///  - acceptance mask 29-bit: 0x1FFFFFFF

    CAN_MOAMR2H = 0x3FFF;        // load MO2 acceptance mask register high
    CAN_MOAMR2L = 0xFFFF;        // load MO2 acceptance mask register low

  ///  Configuration of Message Object 2 interrupt pointer:
  ///  - use message pending register 0 bit position 2
  ///  - receive interrupt node pointer: MultiCAN SRN 0

    CAN_MOIPR2H = 0x0000;        // load MO2 interrupt pointer register high
    CAN_MOIPR2L = 0x0200;        // load MO2 interrupt pointer register low

  ///  Configuration of Message Object 2 FIFO/Gateway pointer:

    CAN_MOFGPR2H = 0x0000;       // load MO2 FIFO/gateway pointer register 
                                 // high
    CAN_MOFGPR2L = 0x0000;       // load MO2 FIFO/gateway pointer register low


  ///  Configuration of Message Object 2 Function control:
  ///  - this object is a STANDARD MESSAGE OBJECT
  ///  - 8 valid data bytes
  ///  - enable receive interrupt; bit RXPND is set after successful 
  ///    reception of a frame

    CAN_MOFCR2H = 0x0801;        // load MO2 function control register high
    CAN_MOFCR2L = 0x0000;        // load MO2 function control register low

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 3:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Message Object 3 :
  ///  - message object 3 is valid
  ///  - message object is used as receive object
  ///  - this message object is assigned to list 2 (node 1)

    CAN_MOCTR3H = 0x00A0;        // load MO3 control register high
    CAN_MOCTR3L = 0x0000;        // load MO3 control register low

  ///  Configuration of Message Object 3 Arbitration:
  ///  - priority class 1; transmit acceptance filtering is based on the list 
  ///    order
  ///  - extended 29-bit identifier
  ///  - identifier 29-bit:      0x186040F3

    CAN_MOAR3H = 0x7860;         // load MO3 arbitration register high
    CAN_MOAR3L = 0x40F3;         // load MO3 arbitration register low

  ///  Configuration of Message Object 3 acceptance mask:
  ///  - only accept receive frames with matching IDE bit
  ///  - acceptance mask 29-bit: 0x1FFFFFFF

    CAN_MOAMR3H = 0x3FFF;        // load MO3 acceptance mask register high
    CAN_MOAMR3L = 0xFFFF;        // load MO3 acceptance mask register low

  ///  Configuration of Message Object 3 interrupt pointer:
  ///  - use message pending register 0 bit position 3
  ///  - receive interrupt node pointer: MultiCAN SRN 0

    CAN_MOIPR3H = 0x0000;        // load MO3 interrupt pointer register high
    CAN_MOIPR3L = 0x0300;        // load MO3 interrupt pointer register low

  ///  Configuration of Message Object 3 FIFO/Gateway pointer:

    CAN_MOFGPR3H = 0x0000;       // load MO3 FIFO/gateway pointer register 
                                 // high
    CAN_MOFGPR3L = 0x0000;       // load MO3 FIFO/gateway pointer register low


  ///  Configuration of Message Object 3 Function control:
  ///  - this object is a STANDARD MESSAGE OBJECT
  ///  - 8 valid data bytes
  ///  - enable receive interrupt; bit RXPND is set after successful 
  ///    reception of a frame

    CAN_MOFCR3H = 0x0801;        // load MO3 function control register high
    CAN_MOFCR3L = 0x0000;        // load MO3 function control register low

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 4:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Message Object 4 :
  ///  - message object 4 is valid
  ///  - message object is used as receive object
  ///  - this message object is assigned to list 2 (node 1)

    CAN_MOCTR4H = 0x00A0;        // load MO4 control register high
    CAN_MOCTR4L = 0x0000;        // load MO4 control register low

  ///  Configuration of Message Object 4 Arbitration:
  ///  - priority class 1; transmit acceptance filtering is based on the list 
  ///    order
  ///  - extended 29-bit identifier
  ///  - identifier 29-bit:      0x186240F3

    CAN_MOAR4H = 0x7862;         // load MO4 arbitration register high
    CAN_MOAR4L = 0x40F3;         // load MO4 arbitration register low

  ///  Configuration of Message Object 4 acceptance mask:
  ///  - only accept receive frames with matching IDE bit
  ///  - acceptance mask 29-bit: 0x1FFFFFFF

    CAN_MOAMR4H = 0x3FFF;        // load MO4 acceptance mask register high
    CAN_MOAMR4L = 0xFFFF;        // load MO4 acceptance mask register low

  ///  Configuration of Message Object 4 interrupt pointer:
  ///  - use message pending register 0 bit position 4
  ///  - receive interrupt node pointer: MultiCAN SRN 0

    CAN_MOIPR4H = 0x0000;        // load MO4 interrupt pointer register high
    CAN_MOIPR4L = 0x0400;        // load MO4 interrupt pointer register low

  ///  Configuration of Message Object 4 FIFO/Gateway pointer:

    CAN_MOFGPR4H = 0x0000;       // load MO4 FIFO/gateway pointer register 
                                 // high
    CAN_MOFGPR4L = 0x0000;       // load MO4 FIFO/gateway pointer register low


  ///  Configuration of Message Object 4 Function control:
  ///  - this object is a STANDARD MESSAGE OBJECT
  ///  - 8 valid data bytes
  ///  - enable receive interrupt; bit RXPND is set after successful 
  ///    reception of a frame

    CAN_MOFCR4H = 0x0801;        // load MO4 function control register high
    CAN_MOFCR4L = 0x0000;        // load MO4 function control register low

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 5:
  ///  -----------------------------------------------------------------------

  ///  General Configuration of the Message Object 5 :
  ///  - message object 5 is valid
  ///  - message object is used as receive object
  ///  - this message object is assigned to list 1 (node 0)

    CAN_MOCTR5H = 0x00A0;        // load MO5 control register high
    CAN_MOCTR5L = 0x0000;        // load MO5 control register low

  ///  Configuration of Message Object 5 Arbitration:
  ///  - priority class 1; transmit acceptance filtering is based on the list 
  ///    order
  ///  - extended 29-bit identifier
  ///  - identifier 29-bit:      0x0CFFC7EF

    CAN_MOAR5H = 0x6CFF;         // load MO5 arbitration register high
    CAN_MOAR5L = 0xC7EF;         // load MO5 arbitration register low

  ///  Configuration of Message Object 5 acceptance mask:
  ///  - only accept receive frames with matching IDE bit
  ///  - acceptance mask 29-bit: 0x1FFFFFFF

    CAN_MOAMR5H = 0x3FFF;        // load MO5 acceptance mask register high
    CAN_MOAMR5L = 0xFFFF;        // load MO5 acceptance mask register low

  ///  Configuration of Message Object 5 interrupt pointer:
  ///  - use message pending register 0 bit position 5
  ///  - receive interrupt node pointer: MultiCAN SRN 0

    CAN_MOIPR5H = 0x0000;        // load MO5 interrupt pointer register high
    CAN_MOIPR5L = 0x0500;        // load MO5 interrupt pointer register low

  ///  Configuration of Message Object 5 FIFO/Gateway pointer:

    CAN_MOFGPR5H = 0x0000;       // load MO5 FIFO/gateway pointer register 
                                 // high
    CAN_MOFGPR5L = 0x0000;       // load MO5 FIFO/gateway pointer register low


  ///  Configuration of Message Object 5 Function control:
  ///  - this object is a STANDARD MESSAGE OBJECT
  ///  - 8 valid data bytes
  ///  - enable receive interrupt; bit RXPND is set after successful 
  ///    reception of a frame

    CAN_MOFCR5H = 0x0801;        // load MO5 function control register high
    CAN_MOFCR5L = 0x0000;        // load MO5 function control register low

  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 6:
  ///  -----------------------------------------------------------------------
  ///  - message object 6 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 7:
  ///  -----------------------------------------------------------------------
  ///  - message object 7 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 8:
  ///  -----------------------------------------------------------------------
  ///  - message object 8 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 9:
  ///  -----------------------------------------------------------------------
  ///  - message object 9 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 10:
  ///  -----------------------------------------------------------------------
  ///  - message object 10 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 11:
  ///  -----------------------------------------------------------------------
  ///  - message object 11 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 12:
  ///  -----------------------------------------------------------------------
  ///  - message object 12 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 13:
  ///  -----------------------------------------------------------------------
  ///  - message object 13 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 14:
  ///  -----------------------------------------------------------------------
  ///  - message object 14 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 15:
  ///  -----------------------------------------------------------------------
  ///  - message object 15 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 16:
  ///  -----------------------------------------------------------------------
  ///  - message object 16 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 17:
  ///  -----------------------------------------------------------------------
  ///  - message object 17 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 18:
  ///  -----------------------------------------------------------------------
  ///  - message object 18 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 19:
  ///  -----------------------------------------------------------------------
  ///  - message object 19 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 20:
  ///  -----------------------------------------------------------------------
  ///  - message object 20 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 21:
  ///  -----------------------------------------------------------------------
  ///  - message object 21 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 22:
  ///  -----------------------------------------------------------------------
  ///  - message object 22 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 23:
  ///  -----------------------------------------------------------------------
  ///  - message object 23 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 24:
  ///  -----------------------------------------------------------------------
  ///  - message object 24 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 25:
  ///  -----------------------------------------------------------------------
  ///  - message object 25 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 26:
  ///  -----------------------------------------------------------------------
  ///  - message object 26 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 27:
  ///  -----------------------------------------------------------------------
  ///  - message object 27 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 28:
  ///  -----------------------------------------------------------------------
  ///  - message object 28 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 29:
  ///  -----------------------------------------------------------------------
  ///  - message object 29 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 30:
  ///  -----------------------------------------------------------------------
  ///  - message object 30 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 31:
  ///  -----------------------------------------------------------------------
  ///  - message object 31 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 32:
  ///  -----------------------------------------------------------------------
  ///  - message object 32 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 33:
  ///  -----------------------------------------------------------------------
  ///  - message object 33 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 34:
  ///  -----------------------------------------------------------------------
  ///  - message object 34 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 35:
  ///  -----------------------------------------------------------------------
  ///  - message object 35 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 36:
  ///  -----------------------------------------------------------------------
  ///  - message object 36 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 37:
  ///  -----------------------------------------------------------------------
  ///  - message object 37 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 38:
  ///  -----------------------------------------------------------------------
  ///  - message object 38 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 39:
  ///  -----------------------------------------------------------------------
  ///  - message object 39 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 40:
  ///  -----------------------------------------------------------------------
  ///  - message object 40 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 41:
  ///  -----------------------------------------------------------------------
  ///  - message object 41 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 42:
  ///  -----------------------------------------------------------------------
  ///  - message object 42 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 43:
  ///  -----------------------------------------------------------------------
  ///  - message object 43 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 44:
  ///  -----------------------------------------------------------------------
  ///  - message object 44 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 45:
  ///  -----------------------------------------------------------------------
  ///  - message object 45 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 46:
  ///  -----------------------------------------------------------------------
  ///  - message object 46 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 47:
  ///  -----------------------------------------------------------------------
  ///  - message object 47 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 48:
  ///  -----------------------------------------------------------------------
  ///  - message object 48 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 49:
  ///  -----------------------------------------------------------------------
  ///  - message object 49 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 50:
  ///  -----------------------------------------------------------------------
  ///  - message object 50 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 51:
  ///  -----------------------------------------------------------------------
  ///  - message object 51 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 52:
  ///  -----------------------------------------------------------------------
  ///  - message object 52 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 53:
  ///  -----------------------------------------------------------------------
  ///  - message object 53 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 54:
  ///  -----------------------------------------------------------------------
  ///  - message object 54 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 55:
  ///  -----------------------------------------------------------------------
  ///  - message object 55 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 56:
  ///  -----------------------------------------------------------------------
  ///  - message object 56 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 57:
  ///  -----------------------------------------------------------------------
  ///  - message object 57 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 58:
  ///  -----------------------------------------------------------------------
  ///  - message object 58 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 59:
  ///  -----------------------------------------------------------------------
  ///  - message object 59 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 60:
  ///  -----------------------------------------------------------------------
  ///  - message object 60 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 61:
  ///  -----------------------------------------------------------------------
  ///  - message object 61 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 62:
  ///  -----------------------------------------------------------------------
  ///  - message object 62 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 63:
  ///  -----------------------------------------------------------------------
  ///  - message object 63 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 64:
  ///  -----------------------------------------------------------------------
  ///  - message object 64 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 65:
  ///  -----------------------------------------------------------------------
  ///  - message object 65 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 66:
  ///  -----------------------------------------------------------------------
  ///  - message object 66 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 67:
  ///  -----------------------------------------------------------------------
  ///  - message object 67 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 68:
  ///  -----------------------------------------------------------------------
  ///  - message object 68 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 69:
  ///  -----------------------------------------------------------------------
  ///  - message object 69 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 70:
  ///  -----------------------------------------------------------------------
  ///  - message object 70 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 71:
  ///  -----------------------------------------------------------------------
  ///  - message object 71 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 72:
  ///  -----------------------------------------------------------------------
  ///  - message object 72 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 73:
  ///  -----------------------------------------------------------------------
  ///  - message object 73 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 74:
  ///  -----------------------------------------------------------------------
  ///  - message object 74 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 75:
  ///  -----------------------------------------------------------------------
  ///  - message object 75 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 76:
  ///  -----------------------------------------------------------------------
  ///  - message object 76 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 77:
  ///  -----------------------------------------------------------------------
  ///  - message object 77 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 78:
  ///  -----------------------------------------------------------------------
  ///  - message object 78 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 79:
  ///  -----------------------------------------------------------------------
  ///  - message object 79 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 80:
  ///  -----------------------------------------------------------------------
  ///  - message object 80 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 81:
  ///  -----------------------------------------------------------------------
  ///  - message object 81 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 82:
  ///  -----------------------------------------------------------------------
  ///  - message object 82 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 83:
  ///  -----------------------------------------------------------------------
  ///  - message object 83 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 84:
  ///  -----------------------------------------------------------------------
  ///  - message object 84 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 85:
  ///  -----------------------------------------------------------------------
  ///  - message object 85 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 86:
  ///  -----------------------------------------------------------------------
  ///  - message object 86 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 87:
  ///  -----------------------------------------------------------------------
  ///  - message object 87 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 88:
  ///  -----------------------------------------------------------------------
  ///  - message object 88 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 89:
  ///  -----------------------------------------------------------------------
  ///  - message object 89 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 90:
  ///  -----------------------------------------------------------------------
  ///  - message object 90 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 91:
  ///  -----------------------------------------------------------------------
  ///  - message object 91 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 92:
  ///  -----------------------------------------------------------------------
  ///  - message object 92 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 93:
  ///  -----------------------------------------------------------------------
  ///  - message object 93 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 94:
  ///  -----------------------------------------------------------------------
  ///  - message object 94 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 95:
  ///  -----------------------------------------------------------------------
  ///  - message object 95 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 96:
  ///  -----------------------------------------------------------------------
  ///  - message object 96 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 97:
  ///  -----------------------------------------------------------------------
  ///  - message object 97 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 98:
  ///  -----------------------------------------------------------------------
  ///  - message object 98 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 99:
  ///  -----------------------------------------------------------------------
  ///  - message object 99 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 100:
  ///  -----------------------------------------------------------------------
  ///  - message object 100 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 101:
  ///  -----------------------------------------------------------------------
  ///  - message object 101 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 102:
  ///  -----------------------------------------------------------------------
  ///  - message object 102 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 103:
  ///  -----------------------------------------------------------------------
  ///  - message object 103 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 104:
  ///  -----------------------------------------------------------------------
  ///  - message object 104 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 105:
  ///  -----------------------------------------------------------------------
  ///  - message object 105 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 106:
  ///  -----------------------------------------------------------------------
  ///  - message object 106 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 107:
  ///  -----------------------------------------------------------------------
  ///  - message object 107 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 108:
  ///  -----------------------------------------------------------------------
  ///  - message object 108 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 109:
  ///  -----------------------------------------------------------------------
  ///  - message object 109 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 110:
  ///  -----------------------------------------------------------------------
  ///  - message object 110 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 111:
  ///  -----------------------------------------------------------------------
  ///  - message object 111 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 112:
  ///  -----------------------------------------------------------------------
  ///  - message object 112 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 113:
  ///  -----------------------------------------------------------------------
  ///  - message object 113 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 114:
  ///  -----------------------------------------------------------------------
  ///  - message object 114 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 115:
  ///  -----------------------------------------------------------------------
  ///  - message object 115 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 116:
  ///  -----------------------------------------------------------------------
  ///  - message object 116 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 117:
  ///  -----------------------------------------------------------------------
  ///  - message object 117 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 118:
  ///  -----------------------------------------------------------------------
  ///  - message object 118 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 119:
  ///  -----------------------------------------------------------------------
  ///  - message object 119 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 120:
  ///  -----------------------------------------------------------------------
  ///  - message object 120 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 121:
  ///  -----------------------------------------------------------------------
  ///  - message object 121 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 122:
  ///  -----------------------------------------------------------------------
  ///  - message object 122 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 123:
  ///  -----------------------------------------------------------------------
  ///  - message object 123 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 124:
  ///  -----------------------------------------------------------------------
  ///  - message object 124 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 125:
  ///  -----------------------------------------------------------------------
  ///  - message object 125 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 126:
  ///  -----------------------------------------------------------------------
  ///  - message object 126 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 127:
  ///  -----------------------------------------------------------------------
  ///  - message object 127 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 128:
  ///  -----------------------------------------------------------------------
  ///  - message object 128 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 129:
  ///  -----------------------------------------------------------------------
  ///  - message object 129 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 130:
  ///  -----------------------------------------------------------------------
  ///  - message object 130 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 131:
  ///  -----------------------------------------------------------------------
  ///  - message object 131 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 132:
  ///  -----------------------------------------------------------------------
  ///  - message object 132 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 133:
  ///  -----------------------------------------------------------------------
  ///  - message object 133 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 134:
  ///  -----------------------------------------------------------------------
  ///  - message object 134 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 135:
  ///  -----------------------------------------------------------------------
  ///  - message object 135 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 136:
  ///  -----------------------------------------------------------------------
  ///  - message object 136 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 137:
  ///  -----------------------------------------------------------------------
  ///  - message object 137 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 138:
  ///  -----------------------------------------------------------------------
  ///  - message object 138 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 139:
  ///  -----------------------------------------------------------------------
  ///  - message object 139 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 140:
  ///  -----------------------------------------------------------------------
  ///  - message object 140 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 141:
  ///  -----------------------------------------------------------------------
  ///  - message object 141 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 142:
  ///  -----------------------------------------------------------------------
  ///  - message object 142 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 143:
  ///  -----------------------------------------------------------------------
  ///  - message object 143 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 144:
  ///  -----------------------------------------------------------------------
  ///  - message object 144 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 145:
  ///  -----------------------------------------------------------------------
  ///  - message object 145 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 146:
  ///  -----------------------------------------------------------------------
  ///  - message object 146 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 147:
  ///  -----------------------------------------------------------------------
  ///  - message object 147 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 148:
  ///  -----------------------------------------------------------------------
  ///  - message object 148 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 149:
  ///  -----------------------------------------------------------------------
  ///  - message object 149 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 150:
  ///  -----------------------------------------------------------------------
  ///  - message object 150 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 151:
  ///  -----------------------------------------------------------------------
  ///  - message object 151 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 152:
  ///  -----------------------------------------------------------------------
  ///  - message object 152 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 153:
  ///  -----------------------------------------------------------------------
  ///  - message object 153 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 154:
  ///  -----------------------------------------------------------------------
  ///  - message object 154 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 155:
  ///  -----------------------------------------------------------------------
  ///  - message object 155 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 156:
  ///  -----------------------------------------------------------------------
  ///  - message object 156 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 157:
  ///  -----------------------------------------------------------------------
  ///  - message object 157 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 158:
  ///  -----------------------------------------------------------------------
  ///  - message object 158 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 159:
  ///  -----------------------------------------------------------------------
  ///  - message object 159 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 160:
  ///  -----------------------------------------------------------------------
  ///  - message object 160 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 161:
  ///  -----------------------------------------------------------------------
  ///  - message object 161 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 162:
  ///  -----------------------------------------------------------------------
  ///  - message object 162 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 163:
  ///  -----------------------------------------------------------------------
  ///  - message object 163 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 164:
  ///  -----------------------------------------------------------------------
  ///  - message object 164 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 165:
  ///  -----------------------------------------------------------------------
  ///  - message object 165 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 166:
  ///  -----------------------------------------------------------------------
  ///  - message object 166 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 167:
  ///  -----------------------------------------------------------------------
  ///  - message object 167 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 168:
  ///  -----------------------------------------------------------------------
  ///  - message object 168 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 169:
  ///  -----------------------------------------------------------------------
  ///  - message object 169 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 170:
  ///  -----------------------------------------------------------------------
  ///  - message object 170 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 171:
  ///  -----------------------------------------------------------------------
  ///  - message object 171 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 172:
  ///  -----------------------------------------------------------------------
  ///  - message object 172 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 173:
  ///  -----------------------------------------------------------------------
  ///  - message object 173 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 174:
  ///  -----------------------------------------------------------------------
  ///  - message object 174 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 175:
  ///  -----------------------------------------------------------------------
  ///  - message object 175 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 176:
  ///  -----------------------------------------------------------------------
  ///  - message object 176 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 177:
  ///  -----------------------------------------------------------------------
  ///  - message object 177 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 178:
  ///  -----------------------------------------------------------------------
  ///  - message object 178 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 179:
  ///  -----------------------------------------------------------------------
  ///  - message object 179 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 180:
  ///  -----------------------------------------------------------------------
  ///  - message object 180 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 181:
  ///  -----------------------------------------------------------------------
  ///  - message object 181 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 182:
  ///  -----------------------------------------------------------------------
  ///  - message object 182 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 183:
  ///  -----------------------------------------------------------------------
  ///  - message object 183 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 184:
  ///  -----------------------------------------------------------------------
  ///  - message object 184 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 185:
  ///  -----------------------------------------------------------------------
  ///  - message object 185 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 186:
  ///  -----------------------------------------------------------------------
  ///  - message object 186 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 187:
  ///  -----------------------------------------------------------------------
  ///  - message object 187 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 188:
  ///  -----------------------------------------------------------------------
  ///  - message object 188 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 189:
  ///  -----------------------------------------------------------------------
  ///  - message object 189 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 190:
  ///  -----------------------------------------------------------------------
  ///  - message object 190 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 191:
  ///  -----------------------------------------------------------------------
  ///  - message object 191 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 192:
  ///  -----------------------------------------------------------------------
  ///  - message object 192 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 193:
  ///  -----------------------------------------------------------------------
  ///  - message object 193 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 194:
  ///  -----------------------------------------------------------------------
  ///  - message object 194 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 195:
  ///  -----------------------------------------------------------------------
  ///  - message object 195 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 196:
  ///  -----------------------------------------------------------------------
  ///  - message object 196 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 197:
  ///  -----------------------------------------------------------------------
  ///  - message object 197 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 198:
  ///  -----------------------------------------------------------------------
  ///  - message object 198 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 199:
  ///  -----------------------------------------------------------------------
  ///  - message object 199 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 200:
  ///  -----------------------------------------------------------------------
  ///  - message object 200 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 201:
  ///  -----------------------------------------------------------------------
  ///  - message object 201 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 202:
  ///  -----------------------------------------------------------------------
  ///  - message object 202 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 203:
  ///  -----------------------------------------------------------------------
  ///  - message object 203 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 204:
  ///  -----------------------------------------------------------------------
  ///  - message object 204 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 205:
  ///  -----------------------------------------------------------------------
  ///  - message object 205 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 206:
  ///  -----------------------------------------------------------------------
  ///  - message object 206 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 207:
  ///  -----------------------------------------------------------------------
  ///  - message object 207 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 208:
  ///  -----------------------------------------------------------------------
  ///  - message object 208 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 209:
  ///  -----------------------------------------------------------------------
  ///  - message object 209 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 210:
  ///  -----------------------------------------------------------------------
  ///  - message object 210 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 211:
  ///  -----------------------------------------------------------------------
  ///  - message object 211 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 212:
  ///  -----------------------------------------------------------------------
  ///  - message object 212 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 213:
  ///  -----------------------------------------------------------------------
  ///  - message object 213 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 214:
  ///  -----------------------------------------------------------------------
  ///  - message object 214 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 215:
  ///  -----------------------------------------------------------------------
  ///  - message object 215 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 216:
  ///  -----------------------------------------------------------------------
  ///  - message object 216 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 217:
  ///  -----------------------------------------------------------------------
  ///  - message object 217 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 218:
  ///  -----------------------------------------------------------------------
  ///  - message object 218 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 219:
  ///  -----------------------------------------------------------------------
  ///  - message object 219 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 220:
  ///  -----------------------------------------------------------------------
  ///  - message object 220 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 221:
  ///  -----------------------------------------------------------------------
  ///  - message object 221 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 222:
  ///  -----------------------------------------------------------------------
  ///  - message object 222 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 223:
  ///  -----------------------------------------------------------------------
  ///  - message object 223 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 224:
  ///  -----------------------------------------------------------------------
  ///  - message object 224 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 225:
  ///  -----------------------------------------------------------------------
  ///  - message object 225 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 226:
  ///  -----------------------------------------------------------------------
  ///  - message object 226 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 227:
  ///  -----------------------------------------------------------------------
  ///  - message object 227 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 228:
  ///  -----------------------------------------------------------------------
  ///  - message object 228 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 229:
  ///  -----------------------------------------------------------------------
  ///  - message object 229 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 230:
  ///  -----------------------------------------------------------------------
  ///  - message object 230 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 231:
  ///  -----------------------------------------------------------------------
  ///  - message object 231 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 232:
  ///  -----------------------------------------------------------------------
  ///  - message object 232 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 233:
  ///  -----------------------------------------------------------------------
  ///  - message object 233 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 234:
  ///  -----------------------------------------------------------------------
  ///  - message object 234 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 235:
  ///  -----------------------------------------------------------------------
  ///  - message object 235 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 236:
  ///  -----------------------------------------------------------------------
  ///  - message object 236 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 237:
  ///  -----------------------------------------------------------------------
  ///  - message object 237 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 238:
  ///  -----------------------------------------------------------------------
  ///  - message object 238 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 239:
  ///  -----------------------------------------------------------------------
  ///  - message object 239 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 240:
  ///  -----------------------------------------------------------------------
  ///  - message object 240 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 241:
  ///  -----------------------------------------------------------------------
  ///  - message object 241 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 242:
  ///  -----------------------------------------------------------------------
  ///  - message object 242 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 243:
  ///  -----------------------------------------------------------------------
  ///  - message object 243 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 244:
  ///  -----------------------------------------------------------------------
  ///  - message object 244 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 245:
  ///  -----------------------------------------------------------------------
  ///  - message object 245 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 246:
  ///  -----------------------------------------------------------------------
  ///  - message object 246 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 247:
  ///  -----------------------------------------------------------------------
  ///  - message object 247 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 248:
  ///  -----------------------------------------------------------------------
  ///  - message object 248 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 249:
  ///  -----------------------------------------------------------------------
  ///  - message object 249 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 250:
  ///  -----------------------------------------------------------------------
  ///  - message object 250 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 251:
  ///  -----------------------------------------------------------------------
  ///  - message object 251 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 252:
  ///  -----------------------------------------------------------------------
  ///  - message object 252 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 253:
  ///  -----------------------------------------------------------------------
  ///  - message object 253 is not valid
  ///  -----------------------------------------------------------------------
  ///  Configuration of Message Object 254:
  ///  -----------------------------------------------------------------------
  ///  - message object 254 is not valid

  ///  -----------------------------------------------------------------------
  ///  Configuration of Service Request Nodes 0 - 15:
  ///  -----------------------------------------------------------------------
  ///  SRN0 service request node configuration:
  ///  - SRN0 interrupt priority level (ILVL) = 13
  ///  - SRN0 interrupt group level (GLVL) = 3
  ///  - SRN0 group priority extension (GPX) = 0

  CAN_0IC        =  0x0077;     


  //   -----------------------------------------------------------------------
  //   Start the CAN Nodes:
  //   -----------------------------------------------------------------------

  ///  - ------------- CAN_NCR0 ----------------------------------------------

    CAN_NCR0 &= ~ (uword) 0x0041; // reset INIT and CCE
  ///  - ------------- CAN_NCR1 ----------------------------------------------

    CAN_NCR1 &= ~ (uword) 0x0041; // reset INIT and CCE
  ///  - ------------- CAN_NCR2 ----------------------------------------------

    CAN_NCR2 &= ~ (uword) 0x0041; // reset INIT and CCE



  // USER CODE BEGIN (Init,3)

  // USER CODE END

} //  End of function CAN_vInit

//****************************************************************************
// @Function      void CAN_vGetMsgObj(ubyte ubObjNr, stCAN_SWObj *pstObj) 
//
//----------------------------------------------------------------------------
// @Description   This function fills the forwarded SW message object with 
//                the content of the chosen HW message object.
//                
//                For Receive Message object use function CAN_vReleaseObj, to 
//                release the message object. 
//                
//                The structure of the SW message object is defined in the 
//                header file CAN.H (see stCAN_SWObj).
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object to be read (0-254)
// @Parameters    *pstObj: 
//                Pointer on a message object to be filled by this function
//
//----------------------------------------------------------------------------
// @Date          2018/11/1
//
//****************************************************************************

// USER CODE BEGIN (GetMsgObj,1)

// USER CODE END

void CAN_vGetMsgObj(ubyte ubObjNr, stCAN_SWObj *pstObj)
{
  ubyte i;

  //----- get DLC -------------------------------------------------------
  pstObj->ubMOCfg = (ubyte)((CAN_HWOBJ[ubObjNr].uwMOFCRH & 0x0F00) >> 8); //MOFCRnH[11-8] DLC

  //----- get MODATA ----------------------------------------------------
  for(i = 0; i < pstObj->ubMOCfg; i++)
  {
    pstObj->ubData[i] = CAN_HWOBJ[ubObjNr].ubData[i];
  }

  //----- get DIR -------------------------------------------------------
    pstObj->ubMOCfg |= (ubyte)((CAN_HWOBJ[ubObjNr].uwMOCTRL & 0x0800) >> 7);  // set DIR if transmit object

  //----- get Identifier ------------------------------------------------
  if(CAN_HWOBJ[ubObjNr].uwMOARH & 0x2000)    // if extended identifier
  {
    //----- get Extended Identifier -------------------------------------
    pstObj->ulID = (((ulong)(CAN_HWOBJ[ubObjNr].uwMOARH & 0x1FFF))<<16) + CAN_HWOBJ[ubObjNr].uwMOARL;

    pstObj->ubMOCfg = pstObj->ubMOCfg | 0x20;  // set IDE
  }
  else                                       // standard identifier
  {
    //----- get Standard Identifier -------------------------------------
    pstObj->ulID = (CAN_HWOBJ[ubObjNr].uwMOARH & 0x1FFF) >> 2;
  }

  //----- get Acceptance Mask -----------------------------------------
  if(((CAN_HWOBJ[ubObjNr].uwMOARH & 0x2000) == 0) && (CAN_HWOBJ[ubObjNr].uwMOAMRH & 0x2000))    // if IDE = 0 & MIDE = 1
  {
    pstObj->ulMask = (CAN_HWOBJ[ubObjNr].uwMOAMRH & 0x1FFF) >> 2;
  }
  else
  {
    pstObj->ulMask = (((ulong)(CAN_HWOBJ[ubObjNr].uwMOAMRH & 0x1FFF))<<16) + CAN_HWOBJ[ubObjNr].uwMOAMRL;
  }

  //----- get Acceptance Mask bit ---------------------------------------
  pstObj->ubMOCfg |= (ubyte)((CAN_HWOBJ[ubObjNr].uwMOAMRH & 0x2000) >> 7); // set MIDE

  //----- get Frame Counter Value ---------------------------------------
  pstObj->uwCounter = CAN_HWOBJ[ubObjNr].uwMOIPRH;

} //  End of function CAN_vGetMsgObj

//****************************************************************************
// @Function      void CAN_vTransmit(ubyte ubObjNr) 
//
//----------------------------------------------------------------------------
// @Description   This function triggers the CAN controller to send the 
//                selected message.
//                If the selected message object is a TRANSMIT OBJECT then 
//                this function triggers the sending of a data frame. If 
//                however the selected message object is a RECEIVE OBJECT 
//                this function triggers the sending of a remote frame.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object (0-254)
//
//----------------------------------------------------------------------------
// @Date          2018/11/1
//
//****************************************************************************

// USER CODE BEGIN (Transmit,1)

// USER CODE END

void CAN_vTransmit(ubyte ubObjNr)
{

  CAN_HWOBJ[ubObjNr].uwMOCTRH = 0x0720;  // set TXRQ,TXEN0,TXEN1,MSGVAL

} //  End of function CAN_vTransmit

//****************************************************************************
// @Function      void CAN_vLoadData(ubyte ubObjNr, ubyte *ubpubData) 
//
//----------------------------------------------------------------------------
// @Description   If a hardware TRANSMIT OBJECT has to be loaded with data 
//                but not with a new identifier, this function may be used 
//                instead of the function CAN_vConfigMsgObj. The message 
//                object should be accessed by calling the function 
//                CAN_ubRequestMsgObj before calling this function. This 
//                prevents the CAN controller from working with invalid data.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubObjNr: 
//                Number of the message object to be configured (0-254)
// @Parameters    *ubpubData: 
//                Pointer on a data buffer
//
//----------------------------------------------------------------------------
// @Date          2018/11/1
//
//****************************************************************************

// USER CODE BEGIN (LoadData,1)

// USER CODE END

void CAN_vLoadData(ubyte ubObjNr, ubyte *ubpubData)
{
  ubyte i;

  CAN_HWOBJ[ubObjNr].uwMOCTRH = 0x0008;       // set NEWDAT

  for(i = 0; i < (CAN_HWOBJ[ubObjNr].uwMOFCRH & 0x0F00) >> 8; i++)
  {
    CAN_HWOBJ[ubObjNr].ubData[i] = *(ubpubData++); //load MODATA
  }

  CAN_HWOBJ[ubObjNr].uwMOCTRH = 0x0020;       // set MSGVAL
  CAN_HWOBJ[ubObjNr].uwMOCTRL = 0x0040;       // reset RTSEL

} //  End of function CAN_vLoadData



//****************************************************************************
// @Macro         CAN_viSRN0() 
//
//----------------------------------------------------------------------------
// @Description   
//
//----------------------------------------------------------------------------
// @Returnvalue   
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2018/11/1
//
//****************************************************************************

// USER CODE BEGIN (SRN0,1)
//    动力电池 总电压      总电流       SOC     最高温度  最低温度
unsigned int BatVoltage=0,BatCurrent=0,BatSoc=0,MaxTemp=0,MinTemp=0;
unsigned int RotateSpeed=0,mcFlag=0,motorTemp=0,mcuTemp=0;

ubyte can2_recieve[8]={0}; //VCU接收电机控制器发送当前转速,电控状态标志
ubyte can3_recieve[8]={0}; //VCU接收BMS发送的电压、电流、SOC
ubyte can4_recieve[8]={0}; //VCU接收BMS发送的最高温度
ubyte can5_recieve[8]={0}; //VCU接收电机控制器发送电控温度及电机温度
// USER CODE END

void CAN_viSRN0(void) interrupt CAN_SRN0INT
{

  uword uwSRN0ObjHandler;

  // USER CODE BEGIN (SRN0,2)
   ubyte  i=0;
  // USER CODE END

  CAN_MSIMASKH = 0x0000;          // set message index mask register
  CAN_MSIMASKL = 0x003C;

  while (CAN_MSID0 != 0x0020)
  {
    switch(CAN_MSID0){

    case 2: // message object 2 interrupt 
    
      uwSRN0ObjHandler = CAN_HWOBJ[2].uwMOCTRL;

      if(uwSRN0ObjHandler & MOSTAT_RXPND)          // if message object 2 receive interrupt
      {
            // USER CODE BEGIN (SRN0_OBJ2,1)

            // USER CODE END

        if(uwSRN0ObjHandler & MOSTAT_NEWDAT)       // if NEWDAT is set
        {
            // USER CODE BEGIN (SRN0_OBJ2,2)
			 for(i = 0; i < 8; i++)
					can2_recieve[i] = CAN_HWOBJ[2].ubData[i];	   //can2_recieve[8]; //VCU接收电机控制器发送当前转速
			 RotateSpeed =((can2_recieve[1]*256+can2_recieve[0])/2)-10000;
			 mcFlag=can2_recieve[5];
			 can2WatchDog=0;
            // USER CODE END

          if (uwSRN0ObjHandler & MOSTAT_MSGLST)    // if MSGLST is set
          {
            // Indicates that the CAN controller has stored a new 
            // message into this object, while NEWDAT was still set,
            // ie. the previously stored message is lost.

            // USER CODE BEGIN (SRN0_OBJ2,3)

            // USER CODE END

          }
          else
          {
            // The CAN controller has stored a new message into this object.

            // USER CODE BEGIN (SRN0_OBJ2,4)

            // USER CODE END
          }

        }

        CAN_HWOBJ[2].uwMOCTRL = MOSTAT_RST_MNR;            // reset MSGLST + NEWDAT + RXPND

      }  // End of RXPND2


      CAN_MSPND0H = ~(uword) 0x0000; // reset PND bit
      CAN_MSPND0L = ~(uword) 0x0004;

      // USER CODE BEGIN (SRN0_OBJ2,7)

      // USER CODE END

      break;


    case 3: // message object 3 interrupt 
    
      uwSRN0ObjHandler = CAN_HWOBJ[3].uwMOCTRL;

      if(uwSRN0ObjHandler & MOSTAT_RXPND)          // if message object 3 receive interrupt
      {
            // USER CODE BEGIN (SRN0_OBJ3,1)

            // USER CODE END

        if(uwSRN0ObjHandler & MOSTAT_NEWDAT)       // if NEWDAT is set
        {
            // USER CODE BEGIN (SRN0_OBJ3,2)
			 for(i = 0; i < 8; i++)
			can3_recieve[i] = CAN_HWOBJ[3].ubData[i];	//can3_recieve[8]; //VCU接收BMS发送的电压、电流、SOC
			BatVoltage =can3_recieve[0]*256+can3_recieve[1];
			BatCurrent =can3_recieve[2]*256+can3_recieve[3];
			BatSoc=	can3_recieve[4];
			can1WatchDog=0;
            // USER CODE END

          if (uwSRN0ObjHandler & MOSTAT_MSGLST)    // if MSGLST is set
          {
            // Indicates that the CAN controller has stored a new 
            // message into this object, while NEWDAT was still set,
            // ie. the previously stored message is lost.

            // USER CODE BEGIN (SRN0_OBJ3,3)

            // USER CODE END

          }
          else
          {
            // The CAN controller has stored a new message into this object.

            // USER CODE BEGIN (SRN0_OBJ3,4)

            // USER CODE END
          }

        }

        CAN_HWOBJ[3].uwMOCTRL = MOSTAT_RST_MNR;            // reset MSGLST + NEWDAT + RXPND

      }  // End of RXPND3


      CAN_MSPND0H = ~(uword) 0x0000; // reset PND bit
      CAN_MSPND0L = ~(uword) 0x0008;

      // USER CODE BEGIN (SRN0_OBJ3,7)

      // USER CODE END

      break;


    case 4: // message object 4 interrupt 
    
      uwSRN0ObjHandler = CAN_HWOBJ[4].uwMOCTRL;

      if(uwSRN0ObjHandler & MOSTAT_RXPND)          // if message object 4 receive interrupt
      {
            // USER CODE BEGIN (SRN0_OBJ4,1)

            // USER CODE END

        if(uwSRN0ObjHandler & MOSTAT_NEWDAT)       // if NEWDAT is set
        {
            // USER CODE BEGIN (SRN0_OBJ4,2)
			for(i = 0; i < 8; i++)
			can4_recieve[i] = CAN_HWOBJ[4].ubData[i];	//can4_recieve		// can4_recieve[8]; //VCU接收BMS发送的最高温度
			MaxTemp= can4_recieve[0];
			MinTemp= can4_recieve[1];
			can1WatchDog=0;
            // USER CODE END

          if (uwSRN0ObjHandler & MOSTAT_MSGLST)    // if MSGLST is set
          {
            // Indicates that the CAN controller has stored a new 
            // message into this object, while NEWDAT was still set,
            // ie. the previously stored message is lost.

            // USER CODE BEGIN (SRN0_OBJ4,3)

            // USER CODE END

          }
          else
          {
            // The CAN controller has stored a new message into this object.

            // USER CODE BEGIN (SRN0_OBJ4,4)

            // USER CODE END
          }

        }

        CAN_HWOBJ[4].uwMOCTRL = MOSTAT_RST_MNR;            // reset MSGLST + NEWDAT + RXPND

      }  // End of RXPND4


      CAN_MSPND0H = ~(uword) 0x0000; // reset PND bit
      CAN_MSPND0L = ~(uword) 0x0010;

      // USER CODE BEGIN (SRN0_OBJ4,7)

      // USER CODE END

      break;


    case 5: // message object 5 interrupt 
    
      uwSRN0ObjHandler = CAN_HWOBJ[5].uwMOCTRL;

      if(uwSRN0ObjHandler & MOSTAT_RXPND)          // if message object 5 receive interrupt
      {
            // USER CODE BEGIN (SRN0_OBJ5,1)

            // USER CODE END

        if(uwSRN0ObjHandler & MOSTAT_NEWDAT)       // if NEWDAT is set		  //VCU接收电机及电控温度
        {
            // USER CODE BEGIN (SRN0_OBJ5,2)
			  for(i = 0; i < 8; i++)
					can5_recieve[i] = CAN_HWOBJ[5].ubData[i];	   
			 mcuTemp=can5_recieve[0]-50;
			 motorTemp =can5_recieve[1]-50;
			 can2WatchDog=0;
            // USER CODE END

          if (uwSRN0ObjHandler & MOSTAT_MSGLST)    // if MSGLST is set
          {
            // Indicates that the CAN controller has stored a new 
            // message into this object, while NEWDAT was still set,
            // ie. the previously stored message is lost.

            // USER CODE BEGIN (SRN0_OBJ5,3)

            // USER CODE END

          }
          else
          {
            // The CAN controller has stored a new message into this object.

            // USER CODE BEGIN (SRN0_OBJ5,4)

            // USER CODE END
          }

        }

        CAN_HWOBJ[5].uwMOCTRL = MOSTAT_RST_MNR;            // reset MSGLST + NEWDAT + RXPND

      }  // End of RXPND5


      CAN_MSPND0H = ~(uword) 0x0000; // reset PND bit
      CAN_MSPND0L = ~(uword) 0x0020;

      // USER CODE BEGIN (SRN0_OBJ5,7)

      // USER CODE END

      break;

    default:

      // USER CODE BEGIN (SRN0,3)

      // USER CODE END

      break;

    }  // end switch 

    // USER CODE BEGIN (SRN0,7)

    // USER CODE END

  }  // end of while CAN_MSID


  // USER CODE BEGIN (SRN0,15)

  // USER CODE END

} //  End of function CAN_viSRN0



// USER CODE BEGIN (CAN_General,10)

// USER CODE END

