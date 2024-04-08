/**
 * @file 
 * @date March 2024
 * @brief This library contains the declaration and definition of hardware-specific functions for 
 * handling and using the UART1 module on the PIC18F57K42 microcontroller.
*/

/* ============================================================================================ */

#include "../inc/PIC18F57K42_UART1.h"

/* ============================================================================================ */

uint8_t PIC18F57K42_UART1_Initialize(void)
{   
    /*
     * Configure pin-out
     */
    PORTC &= 0b00000000;    // Reset port C
    ANSELCbits.ANSELC0 = 0; // Digital Input Enabled 
    ANSELCbits.ANSELC1 = 0; // Digital Input Enabled 
    TRISCbits.TRISC0 = 0;   // Output (PIC UART TX)
    TRISCbits.TRISC1 = 1;   // Input (PIC UART RX)
    RC0PPS &= 0b00010011;   // Pin C0 set as UART1 TX
    U1RXPPS &= 0b00010001;  // Pin C1 set as UART1 RX
    
    /*
     * Configure UART Control Register 0 (U1CON0):
     * 8-bit mode, no parity bit
     */
    U1CON0 |= 0b00110000;

    /* 
     * Calculate final baud rate according to desired baud rate. U1BRGL and U1BRGH together set 
     * the baud rate.
     */
    uint16_t X = (uint16_t)((uint32_t)F_CLOCK/((uint32_t)(16*(uint32_t)BAUD_RATE)) - 1); // Intermediate value used during baud rate calculation
    uint16_t Baudrate_Register_Value = (uint16_t)(F_CLOCK/(16*(X+1))); // Calculated baud rate based on values
    
    U1BRGL |= (uint8_t)(Baudrate_Register_Value & 0xFF); // Set high and low registers values
    U1BRGH |= (uint8_t)(Baudrate_Register_Value >> 8);
    
    /*
     * Enable UART Module
     * ON = 1 (UART Module Enable: Enabled)
     */
    U1CON1 |= 0b10000000;
    
    /*
     * Configure UART Control Register 2 (U1CON2)
     * All bits set to 0 (No special configuration for now)
     */
    U1CON2 |= 0B00000000;
    
    while (PIR3bits.U1TXIF == 0) 
    {
        // While initialization not completed, wait...
    }
    
    return 0;
}
    
/* ============================================================================================ */

uint8_t PIC18F57K42_UART1_Transmit_Byte(uint8_t Byte_To_transmit)
{
    while (PIR3bits.U1TXIF == 0) 
    {
        // While transmit buffer is full, wait...
    }
    
    U1TXB = Byte_To_transmit; // Write byte to transmit buffer
    
    if(U1ERRIR == 0) // Check error register value
    {
        return 0; // If no errors occurred
    }
    else
    {
        return U1ERRIR; // If errors present, return error register value
    }
}

/* ============================================================================================ */

uint8_t PIC18F57K42_UART1_Transmit_Word(uint16_t Word_To_Transmit)
{
    uint8_t Buffer[2] = {};
    uint8_t Transmission_1_Status = 0;
    uint8_t Transmission_2_Status = 0;
    
    // Split 16-bit word in two bytes
    Buffer[1] = (uint8_t)(Word_To_Transmit >> 8); // Most significant byte 
    Buffer[0] = (uint8_t)(Word_To_Transmit & 0xFF); // Least significant byte 

    // Transmit first byte
    Transmission_1_Status = PIC18F57K42_UART1_Transmit_Byte(Buffer[1]);
    if(Transmission_1_Status != 0)
    {
        return Transmission_1_Status;
    }
    
    // Transmit second byte
    Transmission_2_Status = PIC18F57K42_UART1_Transmit_Byte(Buffer[0]);
    if(Transmission_2_Status != 0)
    {
        return Transmission_2_Status;
    }
    
    return 0;
}

/* ============================================================================================ */

uint8_t PIC18F57K42_UART1_Receive_Byte(uint8_t *Received_Byte)
{    
    *Received_Byte = U1RXB; // Copy value stored in receive buffer U1RXB to Received_Byte variable
    
    if(U1ERRIR == 0) // Check error register value
    {
        return 0; // If no errors occurred
    }
    else
    {
        return U1ERRIR; // If errors present, return error register value
    }
}

/* ============================================================================================ */

uint8_t PIC18F57K42_UART1_Receive_Word(uint16_t *Received_Word)
{
    uint8_t Buffer[2] = {};
    uint8_t Reception_1_Status = 0; 
    uint8_t Reception_2_Status = 0;
    
    // Receive first byte
    Reception_1_Status = PIC18F57K42_UART1_Receive_Byte(&Buffer[0]);
    if(Reception_1_Status != 0)
    {
        return Reception_1_Status;
    }
    
    // Receive second byte
    Reception_2_Status = PIC18F57K42_UART1_Receive_Byte(&Buffer[1]);
    if(Reception_2_Status != 0)
    {
        return Reception_2_Status;
    }
    
    // Compose 16-bit word
    *Received_Word = ((uint16_t)Buffer[1] << 8) | Buffer[0];
    
    return 0;
}

/* ============================================================================================ */
