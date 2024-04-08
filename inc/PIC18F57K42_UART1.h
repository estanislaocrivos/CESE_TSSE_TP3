/**
 * @file
 * @date March 2024
 * @brief This library contains the mock functions which emulate the functionality of the PIC18F57K42 UART1 library.
*/

/* ============================================================================================ */

#ifndef PIC18F57K42_UART1_H
#define	PIC18F57K42_UART1_H

/* ============================================================================================ */

#include <stdint.h>

/* ============================================================================================ */

/**
 * @brief This function initializes the UART Module.
 * @param void
 * @return Returns 0 in case of success, 1 otherwise.
 */
uint8_t PIC18F57K42_UART1_Initialize(void);

/* ============================================================================================ */

/**
 * @brief This function transmits one byte through the UART interface.
 * @param Byte_To_Transmit The byte to be transmitted.
 * @return A status code indicating the success or failure of the transmission.
 *         - 0: Transmission successful.
 *         - Non-zero: Transmission failed, and the error code provides more details.
 */
uint8_t PIC18F57K42_UART1_Transmit_Byte(uint8_t Byte_To_Transmit);

/* ============================================================================================ */

/**
 * @brief This function receives one byte through the UART interface.
 * @param Received_Byte A pointer to the variable where the received byte is stored.
 * @return A status code indicating the success or failure of the reception.
 *         - 0: Reception successful.
 *         - Non-zero: Reception failed, and the error code provides more details.
 */
uint8_t PIC18F57K42_UART1_Receive_Byte(uint8_t *Received_Byte);

/* ============================================================================================ */

/**
 * @brief This function transmits one 16-bit word through the UART interface.
 * @param Word_To_Transmit The 16-bit word to be transmitted
 * @return A status code indicating the success or failure of the reception.
 *         - 0: Reception successful.
 *         - Non-zero: Reception failed, and the error code provides more details.
 */
uint8_t PIC18F57K42_UART1_Transmit_Word(uint16_t Word_To_Transmit);

/* ============================================================================================ */

/**
 * @brief This function receives one 16-bit word through the UART interface.
 * @param Receieved_Word A pointer to a 16-bit variable where the received word will be stored.
 * @return A status code indicating the success or failure of the reception.
 *         - 0: Reception successful.
 *         - Non-zero: Reception failed, and the error code provides more details.
 */
uint8_t PIC18F57K42_UART1_Receive_Word(uint16_t *Receieved_Word);

/* ============================================================================================ */

#endif	/* PIC18F57K42_UART1_H */

