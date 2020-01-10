#include <project.h>
#include "stdio.h"
#include <string.h>
#include <stdlib.h> //atoi

/* Project Defines */
#define FALSE  0
#define TRUE   1
#define TRANSMIT_BUFFER_SIZE  16

/* Flags used to store transmit data commands */
uint8 ContinuouslySendData = FALSE;
uint8 SendSingleByte = FALSE;
uint8 clenchGesture = FALSE;
uint8 neutralGesture = FALSE;
uint8 spideyGesture = FALSE;
uint8 sigGesture = FALSE;
uint ms_count = 0;


CY_ISR(SAMPLE_ISR){       
    if(ContinuouslySendData == TRUE) { // 5 seconds
        ms_count++;
        if (ms_count == 5000){
        ContinuouslySendData = FALSE;
        ms_count = 0; // reset ms counter
        CyDelay(100);
        UART_1_PutString("INTERRUPT\r\n");
        }
    }
}

CY_ISR(VERIFY_ISR){ 
    
    uint8 userInput = '\0';
    
    if (sigGesture == TRUE){
        UART_1_PutString("HITL VERIFY\r\n");
        while (userInput == '\0'){
            userInput = UART_1_GetChar();
            
            switch(userInput)
            {
                case 0:
                    /* No new data was recieved */
                    break;
                case 'A':
                case 'a': //clench sequence
                    clenchGesture = TRUE;
                    break;
                case 'B': //spidey sequence
                case 'b':
                    spideyGesture = TRUE;
                    break;
                case 'N': //neutral sequence
                case 'n':
                    neutralGesture = TRUE;
                    break;
                default:
                    /* Place error handling code here */
                    break;    
            }
        }
        sigGesture = FALSE;
    }
}


int main()
{
    /* Variable to store ADC result */
    uint32 Output;
    /* Variable to store UART received character */
    uint8 Ch;

    /* Transmit Buffer */
    char TransmitBuffer[TRANSMIT_BUFFER_SIZE];
    
    ADC_SAR_1_Start();
    UART_1_Start();
    
    /* Start the ADC conversion */
    ADC_SAR_1_StartConvert();
    
    /* Send message to verify COM port is connected properly */
    UART_1_PutString("COM Port Open");
    
    PWM_1_Start(); //thumb
    PWM_2_Start(); //index
    PWM_3_Start(); // middle
    PWM_4_Start(); //ring
    PWM_5_Start(); //pinky
    
    int clenchValL = 2200;
    int clenchValR = 1100;
    int neutralVal = 1600;
    
    CYGlobalIntEnable;
    Timer_1_Start();
    Timer_2_Start();
    ISR_VERIFY_StartEx(VERIFY_ISR);
    ISR_SAMPLE_StartEx(SAMPLE_ISR);

    for(;;)
    {        
        /* Non-blocking call to get the latest data recieved  */
        Ch = UART_1_GetChar();
        
        /* Set flags based on UART command */
        switch(Ch)
        {
            case 0:
                /* No new data was recieved */
                break;
            case 'C':
            case 'c':
                SendSingleByte = TRUE;
                break;
            case 'S':
            case 's':                
                ContinuouslySendData = TRUE;
                break;
            case 'X':
            case 'x':
                ContinuouslySendData = FALSE;
                break;
            case 'A':
            case 'a': //clench sequence
                clenchGesture = TRUE;
                break;
            case 'B': //spidey sequence
            case 'b':
                spideyGesture = TRUE;
                break;
            case 'N': //neutral sequence
            case 'n':
                neutralGesture = TRUE;
                break;
            default:
                /* Place error handling code here */
                break;    
        }
        
        if(ADC_SAR_1_IsEndConversion(ADC_SAR_1_RETURN_STATUS))
        {
            CyDelay(100);
            Output = ADC_SAR_1_GetResult16();
            
            /* Send data based on last UART command */
            if(SendSingleByte || ContinuouslySendData)
            {
                /* Format ADC result for transmition */
                sprintf(TransmitBuffer, "%lu mV\r\n", Output);
                /* Send out the data */
                UART_1_PutString(TransmitBuffer);
                UART_1_GetByte();
                /* Reset the send once flag */
                SendSingleByte = FALSE;
            }      
        }
        if(clenchGesture == TRUE){
            sigGesture = TRUE;
            UART_1_PutString("Clenching...\r\n");            
            PWM_1_WriteCompare(clenchValL); //thumb
            PWM_2_WriteCompare(clenchValL); //index
            PWM_3_WriteCompare(clenchValL); //middle
            PWM_4_WriteCompare(clenchValR); //ring
            PWM_5_WriteCompare(clenchValR); //pinky
            UART_1_PutString("Clench complete!\r\n");
            clenchGesture = FALSE;      
        }
        else if(spideyGesture == TRUE){
            sigGesture = TRUE;
            UART_1_PutString("Spidey...\r\n");       
            PWM_1_WriteCompare(neutralVal); //thumb
            PWM_2_WriteCompare(neutralVal); //index
            PWM_3_WriteCompare(clenchValL); //middle
            PWM_4_WriteCompare(clenchValR); //ring
            PWM_5_WriteCompare(neutralVal); //pinky
            UART_1_PutString("Spidey complete!\r\n");
            spideyGesture = FALSE;        
        }
        else if (neutralGesture == TRUE){
            UART_1_PutString("Neutral...\r\n");
            PWM_1_WriteCompare(neutralVal); //thumb
            PWM_2_WriteCompare(neutralVal); //index
            PWM_3_WriteCompare(neutralVal); //middle
            PWM_4_WriteCompare(neutralVal); //ring
            PWM_5_WriteCompare(neutralVal); //pinky
            UART_1_PutString("Neutral complete!\r\n");
            neutralGesture = FALSE;
        }
    }
}


/* [] END OF FILE */
