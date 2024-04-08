/**
 * @file
 * @date March 2024
 * @brief This library contains functions declarations and definitions used for practical debugging 
 * through the UART console.
*/

/* ============================================================================================ */

#include "../inc/Debug_Tools.h"

/* ============================================================================================ */

void UART2_Initialize(void)
{
    // Enable UART2 Transmitter
    U2CON0 |= 0b00100000; 
    
    // Enable UART2 module
    U2CON1 |= 0b10000000;
    return;
}

/* ============================================================================================ */

/**
 * @brief Redefinition of putch() for transmitting a char through UART2, which in turn is redirected 
 * to output window. The traditional putch() function transmits a char through stdout.
 */
void putch(unsigned char character)
{
    while(PIR6bits.U2TXIF == 0)
    {
        // While UART2 is actively shifting data, wait...
    }

    // Write character to UART2 output register
    U2TXB = character;
}

/* ============================================================================================ */
