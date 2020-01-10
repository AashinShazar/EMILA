/*******************************************************************************
* File Name: ISR_VERIFY.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_ISR_VERIFY_H)
#define CY_ISR_ISR_VERIFY_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ISR_VERIFY_Start(void);
void ISR_VERIFY_StartEx(cyisraddress address);
void ISR_VERIFY_Stop(void);

CY_ISR_PROTO(ISR_VERIFY_Interrupt);

void ISR_VERIFY_SetVector(cyisraddress address);
cyisraddress ISR_VERIFY_GetVector(void);

void ISR_VERIFY_SetPriority(uint8 priority);
uint8 ISR_VERIFY_GetPriority(void);

void ISR_VERIFY_Enable(void);
uint8 ISR_VERIFY_GetState(void);
void ISR_VERIFY_Disable(void);

void ISR_VERIFY_SetPending(void);
void ISR_VERIFY_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_VERIFY ISR. */
#define ISR_VERIFY_INTC_VECTOR            ((reg32 *) ISR_VERIFY__INTC_VECT)

/* Address of the ISR_VERIFY ISR priority. */
#define ISR_VERIFY_INTC_PRIOR             ((reg8 *) ISR_VERIFY__INTC_PRIOR_REG)

/* Priority of the ISR_VERIFY interrupt. */
#define ISR_VERIFY_INTC_PRIOR_NUMBER      ISR_VERIFY__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_VERIFY interrupt. */
#define ISR_VERIFY_INTC_SET_EN            ((reg32 *) ISR_VERIFY__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_VERIFY interrupt. */
#define ISR_VERIFY_INTC_CLR_EN            ((reg32 *) ISR_VERIFY__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_VERIFY interrupt state to pending. */
#define ISR_VERIFY_INTC_SET_PD            ((reg32 *) ISR_VERIFY__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_VERIFY interrupt. */
#define ISR_VERIFY_INTC_CLR_PD            ((reg32 *) ISR_VERIFY__INTC_CLR_PD_REG)


#endif /* CY_ISR_ISR_VERIFY_H */


/* [] END OF FILE */
