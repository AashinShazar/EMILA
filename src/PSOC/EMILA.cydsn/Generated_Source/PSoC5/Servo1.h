/*******************************************************************************
* File Name: Servo1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Servo1_H) /* Pins Servo1_H */
#define CY_PINS_Servo1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Servo1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Servo1__PORT == 15 && ((Servo1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Servo1_Write(uint8 value);
void    Servo1_SetDriveMode(uint8 mode);
uint8   Servo1_ReadDataReg(void);
uint8   Servo1_Read(void);
void    Servo1_SetInterruptMode(uint16 position, uint16 mode);
uint8   Servo1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Servo1_SetDriveMode() function.
     *  @{
     */
        #define Servo1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Servo1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Servo1_DM_RES_UP          PIN_DM_RES_UP
        #define Servo1_DM_RES_DWN         PIN_DM_RES_DWN
        #define Servo1_DM_OD_LO           PIN_DM_OD_LO
        #define Servo1_DM_OD_HI           PIN_DM_OD_HI
        #define Servo1_DM_STRONG          PIN_DM_STRONG
        #define Servo1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Servo1_MASK               Servo1__MASK
#define Servo1_SHIFT              Servo1__SHIFT
#define Servo1_WIDTH              1u

/* Interrupt constants */
#if defined(Servo1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Servo1_SetInterruptMode() function.
     *  @{
     */
        #define Servo1_INTR_NONE      (uint16)(0x0000u)
        #define Servo1_INTR_RISING    (uint16)(0x0001u)
        #define Servo1_INTR_FALLING   (uint16)(0x0002u)
        #define Servo1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Servo1_INTR_MASK      (0x01u) 
#endif /* (Servo1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Servo1_PS                     (* (reg8 *) Servo1__PS)
/* Data Register */
#define Servo1_DR                     (* (reg8 *) Servo1__DR)
/* Port Number */
#define Servo1_PRT_NUM                (* (reg8 *) Servo1__PRT) 
/* Connect to Analog Globals */                                                  
#define Servo1_AG                     (* (reg8 *) Servo1__AG)                       
/* Analog MUX bux enable */
#define Servo1_AMUX                   (* (reg8 *) Servo1__AMUX) 
/* Bidirectional Enable */                                                        
#define Servo1_BIE                    (* (reg8 *) Servo1__BIE)
/* Bit-mask for Aliased Register Access */
#define Servo1_BIT_MASK               (* (reg8 *) Servo1__BIT_MASK)
/* Bypass Enable */
#define Servo1_BYP                    (* (reg8 *) Servo1__BYP)
/* Port wide control signals */                                                   
#define Servo1_CTL                    (* (reg8 *) Servo1__CTL)
/* Drive Modes */
#define Servo1_DM0                    (* (reg8 *) Servo1__DM0) 
#define Servo1_DM1                    (* (reg8 *) Servo1__DM1)
#define Servo1_DM2                    (* (reg8 *) Servo1__DM2) 
/* Input Buffer Disable Override */
#define Servo1_INP_DIS                (* (reg8 *) Servo1__INP_DIS)
/* LCD Common or Segment Drive */
#define Servo1_LCD_COM_SEG            (* (reg8 *) Servo1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Servo1_LCD_EN                 (* (reg8 *) Servo1__LCD_EN)
/* Slew Rate Control */
#define Servo1_SLW                    (* (reg8 *) Servo1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Servo1_PRTDSI__CAPS_SEL       (* (reg8 *) Servo1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Servo1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Servo1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Servo1_PRTDSI__OE_SEL0        (* (reg8 *) Servo1__PRTDSI__OE_SEL0) 
#define Servo1_PRTDSI__OE_SEL1        (* (reg8 *) Servo1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Servo1_PRTDSI__OUT_SEL0       (* (reg8 *) Servo1__PRTDSI__OUT_SEL0) 
#define Servo1_PRTDSI__OUT_SEL1       (* (reg8 *) Servo1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Servo1_PRTDSI__SYNC_OUT       (* (reg8 *) Servo1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Servo1__SIO_CFG)
    #define Servo1_SIO_HYST_EN        (* (reg8 *) Servo1__SIO_HYST_EN)
    #define Servo1_SIO_REG_HIFREQ     (* (reg8 *) Servo1__SIO_REG_HIFREQ)
    #define Servo1_SIO_CFG            (* (reg8 *) Servo1__SIO_CFG)
    #define Servo1_SIO_DIFF           (* (reg8 *) Servo1__SIO_DIFF)
#endif /* (Servo1__SIO_CFG) */

/* Interrupt Registers */
#if defined(Servo1__INTSTAT)
    #define Servo1_INTSTAT            (* (reg8 *) Servo1__INTSTAT)
    #define Servo1_SNAP               (* (reg8 *) Servo1__SNAP)
    
	#define Servo1_0_INTTYPE_REG 		(* (reg8 *) Servo1__0__INTTYPE)
#endif /* (Servo1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Servo1_H */


/* [] END OF FILE */
