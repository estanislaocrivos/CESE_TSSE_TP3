/**
 * @file
 * @date April 2024
 * @brief This file contains the tests for the UART_Library module.
 */

/* ============================================================================================ */

/*
 * Unity is the test environment to be used for testing.
 */
#include "unity.h"

/*
 * This is the library which includes the functions to be tested.
 */
#include "../inc/UART_Library.h"

/*
 * By calling the low layer hardware-specific library this way (with the prefix "mock") you tell 
 * Unity to interpret its functions declarations as mock functions.
*/
#include "mock_PIC18F57K42_UART1.h"

/* ============================================================================================ */

#define EXAMPLE_BYTE 0x12

/* ============================================================================================ */

/**
 * List of tests to be made over the UART_Library module:
 * 
 * - Test 01: Test the creation of an UART instance.
 * - Test 02: Test that the methods of the UART instance point to the correct functions passed as arguments.
 * - Test 03: Test that the attributes of the UART instance are correctly initialized.
 * - Test 04: Test that the initialize function returns what it is suposed to.
 * - Test 05: Test that the transmit function returns what it is suposed to.
 * - Test 06: Test that the receive function returns what it is suposed to.
 */

/* ============================================================================================ */

/**
 * This test verifies that an UART instance can be created and that the methods of the instance point to non-null addresses.
 */
void test_01_UART_Instance_Creation(void)
{    
    UART_Class_t UART;

    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);

    TEST_ASSERT_NOT_NULL(UART.Initialize);
    TEST_ASSERT_NOT_NULL(UART.Transmit_Word);
    TEST_ASSERT_NOT_NULL(UART.Receive_Word);
}

/* ============================================================================================ */

/**
 * This test verifies that the methods of the UART instance point to the correct functions passed as arguments.
 */
void test_02_UART_Instance_Methods(void)
{
    UART_Class_t UART;

    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);

    TEST_ASSERT_EQUAL(PIC18F57K42_UART1_Initialize, UART.Initialize);
    TEST_ASSERT_EQUAL(PIC18F57K42_UART1_Transmit_Word, UART.Transmit_Word);
    TEST_ASSERT_EQUAL(PIC18F57K42_UART1_Receive_Word, UART.Receive_Word);
}

/* ============================================================================================ */

/**
 * This test verifies that the attributes of the UART instance are correctly initialized.
 */
void test_03_UART_Instance_Attributes(void)
{
    UART_Class_t UART;

    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);

    TEST_ASSERT_EQUAL(0, UART.Init_Status);
    TEST_ASSERT_EQUAL(0, UART.Transmission_Status);
    TEST_ASSERT_EQUAL(0, UART.Reception_Status);
    TEST_ASSERT_EQUAL(0, UART.Transmission_Buffer);
    TEST_ASSERT_EQUAL(0, UART.Reception_Buffer);
}

/* ============================================================================================ */

/**
 * This test verifies the return value of the initialize function call.
 */
void test_04_UART_Instance_Initialize(void)
{
    UART_Class_t UART;

    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);

    PIC18F57K42_UART1_Initialize_ExpectAndReturn(0);

    TEST_ASSERT_EQUAL(0, UART.Initialize());
}

/* ============================================================================================ */

/**
 * This test verifies the return value of the transmit function.
 */
void test_05_UART_Instance_Transmit(void)
{
    UART_Class_t UART;
            
    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);

    PIC18F57K42_UART1_Transmit_Word_ExpectAndReturn(EXAMPLE_BYTE, 0);

    TEST_ASSERT_EQUAL(0, UART.Transmit_Word(EXAMPLE_BYTE));
}

/* ============================================================================================ */

/**
 * This test verifies the return value of the receive function.
 */
void test_06_UART_Instance_Receive(void)
{
    UART_Class_t UART;

    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);

    uint16_t Received_Word_Buffer = 0;

    PIC18F57K42_UART1_Receive_Word_ExpectAndReturn(&Received_Word_Buffer, 0);

    TEST_ASSERT_EQUAL(0, UART.Receive_Word(&Received_Word_Buffer));
}

/* ============================================================================================ */
