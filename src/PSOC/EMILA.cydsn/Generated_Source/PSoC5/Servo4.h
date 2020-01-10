/*******************************************************************************
* File Name: Servo4.h  
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

#if !defined(CY_PINS_Servo4_H) /* Pins Servo4_H */
#define CY_PINS_Servo4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Servo4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Servo4__PORT == 15 && ((Servo4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Servo4_Write(uint8 value);
void    Servo4_SetDriveMode(uint8 mode);
uint8   Servo4_ReadDataReg(void);
uint8   Servo4_Read(void);
void    Servo4_SetInterruptMode(uint16 position, uint16 mode);
uint8   Servo4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Servo4_SetDriveMode() function.
     *  @{
     */
        #define Servo4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Servo4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Servo4_DM_RES_UP          PIN_DM_RES_UP
        #define Servo4_DM_RES_DWN         PIN_DM_RES_DWN
        #define Servo4_DM_OD_LO           PIN_DM_OD_LO
        #define Servo4_DM_OD_HI           PIN_DM_OD_HI
        #define Servo4_DM_STRONG          PIN_DM_STRONG
        #define Servo4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Servo4_MASK               Servo4__MASK
#define Servo4_SHIFT              Servo4__SHIFT
#define Servo4_WIDTH              1u

/* Interrupt constants */
#if defined(Servo4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Servo4_SetInterruptMode() function.
     *  @{
     */
        #define Servo4_INTR_NONE      (uint16)(0x0000u)
        #define Servo4_INTR_RISING    (uint16)(0x0001u)
        #define Servo4_INTR_FALLING   (uint16)(0x0002u)
        #define Servo4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Servo4_INTR_MASK      (0x01u) 
#endif /* (Servo4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Servo4_PS                     (* (reg8 *) Servo4__PS)
/* Data Register */
#define Servo4_DR                     (* (reg8 *) Servo4__DR)
/* Port Number */
#define Servo4_PRT_NUM                (* (reg8 *) Servo4__PRT) 
/* Connect to Analog Globals */                                                  
#define Servo4_AG                     (* (reg8 *) Servo4__AG)                       
/* Analog MUX bux enable */
#define Servo4_AMUX                   (* (reg8 *) Servo4__AMUX) 
/* Bidirectional Enable */                                                        
#define Servo4_BIE                    (* (reg8 *) Servo4__BIE)
/* Bit-mask for Aliased Register Access */
#define Servo4_BIT_MASK               (* (reg8 *) Servo4__BIT_MASK)
/* Bypass Enable */
#define Servo4_BYP                    (* (reg8 *) Servo4__BYP)
/* Port wide control signals */                                                   
#define Servo4_CTL                    (* (reg8 *) Servo4__CTL)
/* Drive Modes */
#define Servo4_DM0                    (* (reg8 *) Servo4__DM0) 
#define Servo4_DM1                    (* (reg8 *) Servo4__DM1)
#define Servo4_DM2                    (* (reg8 *) Servo4__DM2) 
/* Input Buffer Disable Override */
#define Servo4_INP_DIS                (* (reg8 *) Servo4__INP_DIS)
/* LCD Common or Segment Drive */
#define Servo4_LCD_COM_SEG            (* (reg8 *) Servo4__LCD_COM_SEG)
/* Enable Segment LCD */
#define Servo4_LCD_EN                 (* (reg8 *) Servo4__LCD_EN)
/* Slew Rate Control */
#define Servo4_SLW                    (* (reg8 *) Servo4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Servo4_PRTDSI__CAPS_SEL       (* (reg8 *) Servo4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Servo4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Servo4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Servo4_PRTDSI__OE_SEL0        (* (reg8 *) Servo4__PRTDSI__OE_SEL0) 
#define Servo4_PRTDSI__OE_SEL1        (* (reg8 *) Servo4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Servo4_PRTDSI__OUT_SEL0       (* (reg8 *) Servo4__PRTDSI__OUT_SEL0) 
#define Servo4_PRTDSI__OUT_SEL1       (* (reg8 *) Servo4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Servo4_PRTDSI__SYNC_OUT       (* (reg8 *) Servo4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Servo4__SIO_CFG)
    #define Servo4_SIO_HYST_EN        (* (reg8 *) Servo4__SIO_HYST_EN)
    #define Servo4_SIO_REG_HIFREQ     (* (reg8 *) Servo4__SIO_REG_HIFREQ)
    #define Servo4_SIO_CFG            (* (reg8 *) Servo4__SIO_CFG)
    #define Servo4_SIO_DIFF           (* (reg8 *) Servo4__SIO_DIFF)
#endif /* (Servo4__SIO_CFG) */

/* Interrupt Registers */
#if defined(Servo4__INTSTAT)
    #define Servo4_INTSTAT            (* (reg8 *) Servo4__INTSTAT)
    #define Servo4_SNAP               (* (reg8 *) Servo4__SNAP)
    
	#define Servo4_0_INTTYPE_REG 		(* (reg8 *) Servo4__0__INTTYPE)
#endif /* (Servo4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Servo4_H */


/* [] END OF FILE */
