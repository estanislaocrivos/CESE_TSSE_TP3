/**
 * @file
 * @date March 2024
 * @brief This is the main.c file.
*/

/* === Configuration Bit Settings =============================================== */

// These bits configure essential functionalities during microcontroller boot

// CONFIG1L
#pragma config FEXTOSC = OFF    // External Oscillator Selection (Oscillator not enabled)
#pragma config RSTOSC = HFINTOSC_1MHZ// Reset Oscillator Selection (HFINTOSC with HFFRQ = 4 MHz and CDIV = 4:1)

// CONFIG1H
#pragma config CLKOUTEN = ON    // Clock out Enable bit (CLKOUT function is enabled)
#pragma config PR1WAY = ON      // PRLOCKED One-Way Set Enable bit (PRLOCK bit can be cleared and set only once)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)

// CONFIG2L
#pragma config MCLRE = INTMCLR  // MCLR Enable bit (If LVP = 0, MCLR pin function is port defined function; If LVP =1, RE3 pin fuction is MCLR)
#pragma config PWRTS = PWRT_16  // Power-up timer selection bits (PWRT set at 16ms)
#pragma config MVECEN = ON      // Multi-vector enable bit (Multi-vector enabled, Vector table used for interrupts)
#pragma config IVT1WAY = ON     // IVTLOCK bit One-way set enable bit (IVTLOCK bit can be cleared and set only once)
#pragma config LPBOREN = OFF    // Low Power BOR Enable bit (ULPBOR disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled , SBOREN bit is ignored)

// CONFIG2H
#pragma config BORV = VBOR_2P45 // Brown-out Reset Voltage Selection bits (Brown-out Reset Voltage (VBOR) set to 2.45V)
#pragma config ZCD = OFF        // ZCD Disable bit (ZCD disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON)
#pragma config PPS1WAY = ON     // PPSLOCK bit One-Way Set Enable bit (PPSLOCK bit can be cleared and set only once; PPS registers remain locked after one clear/set cycle)
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config DEBUG = OFF      // Debugger Enable bit (Background debugger disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Extended Instruction Set and Indexed Addressing Mode disabled)

// CONFIG3L
#pragma config WDTCPS = WDTCPS_31// WDT Period selection bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

// CONFIG3H
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG4L
#pragma config BBSIZE = BBSIZE_512// Boot Block Size selection bits (Boot Block size is 512 words)
#pragma config BBEN = OFF       // Boot Block enable bit (Boot block disabled)
#pragma config SAFEN = OFF      // Storage Area Flash enable bit (SAF disabled)
#pragma config WRTAPP = OFF     // Application Block write protection bit (Application Block not write protected)

// CONFIG4H
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block not write-protected)
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)
#pragma config WRTSAF = OFF     // SAF Write protection bit (SAF not Write Protected)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (HV on MCLR/VPP must be used for programming)

// CONFIG5L
#pragma config CP = OFF         // PFM and Data EEPROM Code Protection bit (PFM and Data EEPROM code protection disabled)

/* === Headers files inclusions =============================================================== */  

#include "../inc/main.h"

/* === Macros definitions ===================================================================== */

#define EXAMPLE_16BIT_WORD 0x1234
#define UART_INITIALIZED_VALUE 1

/* === Private data type declarations ========================================================= */

/* === Private variable declarations ========================================================== */

/* === Private function declarations ========================================================== */

/* === Public variable definitions ============================================================ */

/* === Private variable definitions =========================================================== */

/* === Private function implementation ======================================================== */

/* === Public function implementation ========================================================= */

/* ============================================================================================ */

/** 
 * @brief This is the main function
 * @param void
 * @return void
*/
void main(void)
{
    /* ======================================================================================== */

    /*
     * For debugging...
     */
    UART2_Initialize();
    printf("Program initialization...\n");
    
    /* ======================================================================================== */

    uint16_t Received_Word_Buffer; // Where the received word will be stored

    /*
     * Create an instance of UART class (object UART_Object) and initialize it. UART is a pointer 
     * to the new instance.
     */
    UART_Class_t *UART;
    
    New_UART_Instance(UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);
        
    /*
     * Initialize UART hardware calling low-layer function and save return value in the Init_Status att.
     */
    if(UART->Initialize() == 0)
    {
        UART->Set_Init_Status(UART, UART_INITIALIZED_VALUE);
    }
        
    UART->Set_Transmission_Buffer(UART, EXAMPLE_16BIT_WORD);
    
    UART->Set_Transmission_Status(UART, UART->Transmit_Word(EXAMPLE_16BIT_WORD));

    UART->Set_Reception_Status(UART, UART->Receive_Word(&Received_Word_Buffer));
    
    UART->Set_Reception_Buffer(UART, Received_Word_Buffer);
    
    Destroy_UART_Instance(UART);
    
    while (1)
    {

    }
}
    
/* === End of documentation =================================================================== */