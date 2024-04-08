#include "build/test/mocks/mock_PIC18F57K42_UART1.h"
#include "test/../inc/UART_Library.h"
#include "/Library/Ruby/Gems/2.6.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


















void test_01_UART_Instance_Creation(void)

{

    UART_Class_t UART;



    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);



    do {if ((((UART.Initialize)) != ((void*)0))) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(53))));}} while(0);

    do {if ((((UART.Transmit_Word)) != ((void*)0))) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(54))));}} while(0);

    do {if ((((UART.Receive_Word)) != ((void*)0))) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(55))));}} while(0);

}













void test_02_UART_Instance_Methods(void)

{

    UART_Class_t UART;



    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);



    UnityAssertEqualNumber((UNITY_INT)((PIC18F57K42_UART1_Initialize)), (UNITY_INT)((UART.Initialize)), (((void*)0)), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((PIC18F57K42_UART1_Transmit_Word)), (UNITY_INT)((UART.Transmit_Word)), (((void*)0)), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((PIC18F57K42_UART1_Receive_Word)), (UNITY_INT)((UART.Receive_Word)), (((void*)0)), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

}













void test_03_UART_Instance_Attributes(void)

{

    UART_Class_t UART;



    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((UART.Init_Status)), (((void*)0)), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((UART.Transmission_Status)), (((void*)0)), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((UART.Reception_Status)), (((void*)0)), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((UART.Transmission_Buffer)), (((void*)0)), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((UART.Reception_Buffer)), (((void*)0)), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

}













void test_04_UART_Instance_Initialize(void)

{

    UART_Class_t UART;



    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);



    PIC18F57K42_UART1_Initialize_CMockExpectAndReturn(103, 0);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((UART.Initialize())), (((void*)0)), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_INT);

}













void test_05_UART_Instance_Transmit(void)

{

    UART_Class_t UART;



    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);



    PIC18F57K42_UART1_Transmit_Word_CMockExpectAndReturn(119, 0x12, 0);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((UART.Transmit_Word(0x12))), (((void*)0)), (UNITY_UINT)(121), UNITY_DISPLAY_STYLE_INT);

}













void test_06_UART_Instance_Receive(void)

{

    UART_Class_t UART;



    New_UART_Instance(&UART, PIC18F57K42_UART1_Initialize, PIC18F57K42_UART1_Transmit_Word, PIC18F57K42_UART1_Receive_Word);



    uint16_t Received_Word_Buffer = 0;



    PIC18F57K42_UART1_Receive_Word_CMockExpectAndReturn(137, &Received_Word_Buffer, 0);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((UART.Receive_Word(&Received_Word_Buffer))), (((void*)0)), (UNITY_UINT)(139), UNITY_DISPLAY_STYLE_INT);

}
