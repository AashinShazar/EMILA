/* ==================================================
 * Followed by project posted by 
 * Bob Marlowe TxRx20
 * http://www.cypress.com/?app=forum&id=2233&rID=63901

 * Provided As-is, without any warranties to perform
 * under license terms CREATIVE COMMONS - SHARE ALIKE
 *
 * ==================================================
*/

//#ifndef UART_H
//#define UART_H
//#if (!#defined(UART_H))
//#define UART_H
    
#include <project.h>            

//#define	FALSE	0
//#define TRUE	!FALSE

#define RxBufferSize	128     //size of the Rx circular buffer
//#define EOM_char        0x0D    //message separator char (\r)
//#define EOM_char        0x0A    //message separator char (\n)

//any standard terminator (or their combination) will work
#define EOM_CR        0x0D    //message separator char (\r)
#define EOM_LF        0x0A    //message separator char (\n)

  
    // each Rx command consists of: <char command><string value><CR>

    union TRxBuffer {
        char   RxStr[20];   // received Rx packet (to hold individual command message)
        struct {            // anonimous structure
            char cmd;       // 1-byte command
            char valstr[19];// command value           
        };
    } RB;

   
//=====================================
//        Function Prototypes 
//=====================================
   
CY_ISR_PROTO(MyRxInt);          // process Rx interrupt

uint8	IsCharReady(void);		// Returns TRUE when a char is ready
uint8	GetRxStr(void);			// Extract command string from buffer, non-blocking 


//#endif
/* [] END OF FILE */
