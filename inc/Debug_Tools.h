/**
 * @file 
 * @date March 2024
 * @brief This file contains functions declarations used for practical debugging through the UART
 * console.
*/

/* ============================================================================================ */

#ifndef DEBUG_TOOLS_H
#define	DEBUG_TOOLS_H

/* ============================================================================================ */

#include <xc.h>

/* ============================================================================================ */

/**
 * @brief This function initializes the UART2 transmitter to be used to print characters on screen.
 * @param void
 * @return void
 */
void UART2_Initialize(void);

/* ============================================================================================ */

#endif	/* DEBUG_TOOLS_H */

