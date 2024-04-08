/** 
 * @file 
 * @date March 2024
 * @brief This library contains the variable types and functions declarations and definitions for 
 * using the UART Module.
 */

/* ============================================================================================ */

#include "../inc/UART_Library.h"

/* ============================================================================================ */

UART_Class_t* New_UART_Instance(UART_Class_t *UART_Instance, UART_Init_Function_t Initialize_Function, UART_Transmit_Function_t Transmit_Function, UART_Receive_Function_t Receive_Function)
{
    /*
     * Initialize UART_Instance methods
     */
    UART_Instance->Initialize = Initialize_Function;
    UART_Instance->Transmit_Word = Transmit_Function;
    UART_Instance->Receive_Word  = Receive_Function;
    UART_Instance->Set_Init_Status = Set_Init_Status;
    UART_Instance->Set_Transmission_Status = Set_Transmission_Status;
    UART_Instance->Set_Reception_Status = Set_Reception_Status;
    UART_Instance->Set_Transmission_Buffer = Set_Transmission_Buffer;
    UART_Instance->Set_Reception_Buffer = Set_Reception_Buffer;
    
    /*
     * Initialize UART_Instance attributes
     */
    UART_Instance->Set_Init_Status(UART_Instance, 0);
    UART_Instance->Set_Transmission_Status(UART_Instance, 0);
    UART_Instance->Set_Reception_Status(UART_Instance, 0);
    UART_Instance->Set_Transmission_Buffer(UART_Instance, 0);
    UART_Instance->Set_Reception_Buffer(UART_Instance, 0);
    
    /*
     * Return 0 if the instance was created successfully
     */
    return UART_Instance;    
}

/* ============================================================================================ */

void Set_Init_Status(void *Instance, uint8_t UART_Status)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    UART->Init_Status = UART_Status;
}

/* ============================================================================================ */

void Set_Transmission_Status(void *Instance, uint8_t Transmission_Status)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    UART->Transmission_Status = Transmission_Status;
}

/* ============================================================================================ */

void Set_Reception_Status(void *Instance, uint8_t Reception_Status)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    UART->Reception_Status = Reception_Status;
}

/* ============================================================================================ */

void Set_Transmission_Buffer(void *Instance, uint16_t Word_To_Transmit)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    UART->Transmission_Buffer = Word_To_Transmit;
}

/* ============================================================================================ */

void Set_Reception_Buffer(void *Instance, uint16_t Received_Word)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    UART->Reception_Buffer = Received_Word;
}

/* ============================================================================================ */

uint8_t Get_Init_Status(void *Instance)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    return UART->Init_Status;
}

/* ============================================================================================ */

uint8_t Get_Transmission_Status(void *Instance)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    return UART->Transmission_Status;
}

/* ============================================================================================ */

uint8_t Get_Reception_Status(void *Instance)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    return UART->Reception_Status;
}

/* ============================================================================================ */

uint16_t Get_Transmission_Buffer(void *Instance)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    return UART->Transmission_Buffer;
}

/* ============================================================================================ */

uint16_t Get_Reception_Buffer(void *Instance)
{
    UART_Class_t *UART = (UART_Class_t *)Instance;
    return UART->Reception_Buffer;
}

/* ============================================================================================ */
