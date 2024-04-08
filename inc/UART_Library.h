/**
 * @file 
 * @date March 2024
 * @brief This library contains the variable types and functions declarations and definitions for 
 * using the UART Module.
 */

/* ============================================================================================ */

#ifndef UART_LIBRARY_H
#define	UART_LIBRARY_H

/* ============================================================================================ */

#include <stdint.h>

/* ============================================================================================ */

/*
 * Definition of function pointer types for initialize, transmit and receive functions
 */
typedef uint8_t (*UART_Init_Function_t)(void);
typedef uint8_t (*UART_Transmit_Function_t)(uint16_t);
typedef uint8_t (*UART_Receive_Function_t)(uint16_t *);

/* ============================================================================================ */

/**
 * @brief This structure contains the definition of the class UART. All UART objects created will 
 * be instances of this class. 
 */ 
typedef struct
{
    /**
     * [Attributes]
     */
    uint8_t Init_Status; /**< This attribute indicates if the UART module has been initialized. 1 means it has been initialized, 0 means it hasn't */
    uint8_t Transmission_Status; /**< This attribute contains the status of a transmission. 0 means no errors, != 0 means error, and error code provides information */
    uint8_t Reception_Status; /**< This attribute contains the status of a reception. 0 means no errors, != 0 means error, and error code provides information */
    uint16_t Transmission_Buffer; /**< This buffer contains the word to be transmitted */
    uint16_t Reception_Buffer; /**< This buffer contains the received word */
    
    /**
     * [Methods] Hardware-specific function pointers
     */
    UART_Init_Function_t     Initialize;    /**< This function pointer should point to the function used for initializing the UART module of the microcontroller */
    UART_Transmit_Function_t Transmit_Word; /**< This function pointer should point to the function used for transmitting data through the UART module of the microcontroller */
    UART_Receive_Function_t  Receive_Word;  /**< This function pointer should point to the function used for receiving data through the UART module of the microcontroller */

    /**
     * [Methods] Setter functions
     */
    void (*Set_Init_Status)(void *, uint8_t); /**< This method sets the Init_Status attribute */
    void (*Set_Transmission_Status)(void *, uint8_t); /**< This method sets the Transmission_Status attribute */
    void (*Set_Reception_Status)(void *, uint8_t); /**< This method sets the Reception_Status attribute */
    void (*Set_Transmission_Buffer)(void *, uint16_t); /**< This method sets the Word_To_Transmit attribute*/
    void (*Set_Reception_Buffer)(void *, uint16_t); /**< This method sets the Received_Word attribute */

    /**
     * [Methods] Getter functions
     */
    uint8_t  (*Get_Init_Status)(void *); /**< This method gets the Init_Status attribute */
    uint8_t  (*Get_Transmission_Status)(void *); /**< This method gets the Transmission_Status attribute */
    uint8_t  (*Get_Reception_Status)(void *); /**< This method gets the Reception_Status attribute */
    uint16_t (*Get_Transmission_Buffer)(void *); /**< This method gets the Transmissio_Buffer attribute */
    uint16_t (*Get_Reception_Buffer)(void *); /**< This method gets the Reception_Buffer attribute */
    
}UART_Class_t;

/* ============================================================================================ */

/**
 * @brief This function creates a new instance (object) of class UART_Class_t. It also initializes
 * the object attributes and methods.
 * @param Initialize_Function This function pointer should point to the low-layer function which
 * will be used to initialize the hardware.
 * @param Transmit_Function This function pointer should point to the low-layer function which
 * will be used to transmit a 16-bit word using the specific hardware. It should allow a 16-bit 
 * word as input and it should return an 8-bit value indicating success (0) or error (!=0).
 * @param Receive_Function This function pointer should point to the low-layer function which
 * will be used to receive a 16-bit word using the specific hardware. It should allow a 16-bit
 * variable pointer as input and it should return an 8-bit value indicating success (0) or error (!=0).
 * @return It returns a UART_Class_t type variable which is a pointer to the generated struct
 * which contains the object.
 */
UART_Class_t* New_UART_Instance(UART_Class_t *UART_Instance, UART_Init_Function_t Initialize_Function, UART_Transmit_Function_t Transmit_Function, UART_Receive_Function_t Receive_Function);

/* ============================================================================================ */

/**
 * @brief This function frees the memory used by the UART_Class_t object pointed by Instance.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 */
void Destroy_UART_Instance(UART_Class_t *Instance);

/* ============================================================================================ */

/**
 * @brief This function sets the Init_Status attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @param UART_Status This is the value to be assigned to Init_Status.
 */
void Set_Init_Status(void *Instance, uint8_t UART_Status);

/* ============================================================================================ */

/**
 * @brief This function sets the Transmission_Status attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @param Transmission_Status This is the value to be assigned to Transmission_Status.
 */
void Set_Transmission_Status(void *Instance, uint8_t Transmission_Status);

/* ============================================================================================ */

/**
 * @brief This function sets the Reception_Status attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @param Reception_Status This is the value to be assigned to Reception_Status.
 */
void Set_Reception_Status(void *Instance, uint8_t Reception_Status);

/* ============================================================================================ */

/**
 * @brief This function sets The Transmission_Buffer attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @param Word_To_Transmit This is the value to be assigned to Transmission_Buffer.
 */
void Set_Transmission_Buffer(void *Instance, uint16_t Word_To_Transmit);

/* ============================================================================================ */

/**
 * @brief This function sets the Reception_Buffer attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @param Received_Word This is the value to be assigned to Received_Word.
 */
void Set_Reception_Buffer(void *Instance, uint16_t Received_Word);

/* ============================================================================================ */

/**
 * @brief This function gets the Init_Status attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @return Returns the value of the attribute.
 */
uint8_t Get_Init_Status(void *Instance);

/* ============================================================================================ */

/**
 * @brief This function gets the Transmission_Status attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @return Returns the value of the attribute.
 */
uint8_t Get_Transmission_Status(void *Instance);

/* ============================================================================================ */

/**
 * @brief This function gets the Reception_Status attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @return Returns the value of the attribute.
 */
uint8_t Get_Reception_Status(void *Instance);

/* ============================================================================================ */

/**
 * @brief This function gets the Transmission_Buffer attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @return Returns the value of the attribute.
 */
uint16_t Get_Transmission_Buffer(void *Instance);

/* ============================================================================================ */

/**
 * @brief This function gets the Reception_Buffer attribute of UART_Class_t class.
 * @param Instance This is a pointer to the object instance which you wish to modify.
 * @return Returns the value of the attribute.
 */
uint16_t Get_Reception_Buffer(void *Instance);

/* ============================================================================================ */

#endif	/* UART_LIBRARY_H */