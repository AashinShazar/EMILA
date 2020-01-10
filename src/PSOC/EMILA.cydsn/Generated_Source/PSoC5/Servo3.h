/*******************************************************************************
* File Name: Servo3.h  
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

#if !defined(CY_PINS_Servo3_H) /* Pins Servo3_H */
#define CY_PINS_Servo3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Servo3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Servo3__PORT == 15 && ((Servo3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Servo3_Write(uint8 value);
void    Servo3_SetDriveMode(uint8 mode);
uint8   Servo3_ReadDataReg(void);
uint8   Servo3_Read(void);
void    Servo3_SetInterruptMode(uint16 position, uint16 mode);
uint8   Servo3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Servo3_SetDriveMode() function.
     *  @{
     */
        #define Servo3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Servo3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Servo3_DM_RES_UP          PIN_DM_RES_UP
        #define Servo3_DM_RES_DWN         PIN_DM_RES_DWN
        #define Servo3_DM_OD_LO           PIN_DM_OD_LO
        #define Servo3_DM_OD_HI           PIN_DM_OD_HI
        #define Servo3_DM_STRONG          PIN_DM_STRONG
        #define Servo3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Servo3_MASK               Servo3__MASK
#define Servo3_SHIFT              Servo3__SHIFT
#define Servo3_WIDTH              1u

/* Interrupt constants */
#if defined(Servo3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Servo3_SetInterruptMode() function.
     *  @{
     */
        #define Servo3_INTR_NONE      (uint16)(0x0000u)
        #define Servo3_INTR_RISING    (uint16)(0x0001u)
        #define Servo3_INTR_FALLING   (uint16)(0x0002u)
        #define Servo3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Servo3_INTR_MASK      (0x01u) 
#endif /* (Servo3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Servo3_PS                     (* (reg8 *) Servo3__PS)
/* Data Register */
#define Servo3_DR                     (* (reg8 *) Servo3__DR)
/* Port Number */
#define Servo3_PRT_NUM                (* (reg8 *) Servo3__PRT) 
/* Connect to Analog Globals */                                                  
#define Servo3_AG                     (* (reg8 *) Servo3__AG)                       
/* Analog MUX bux enable */
#define Servo3_AMUX                   (* (reg8 *) Servo3__AMUX) 
/* Bidirectional Enable */                                                        
#define Servo3_BIE                    (* (reg8 *) Servo3__BIE)
/* Bit-mask for Aliased Register Access */
#define Servo3_BIT_MASK               (* (reg8 *) Servo3__BIT_MASK)
/* Bypass Enable */
#define Servo3_BYP                    (* (reg8 *) Servo3__BYP)
/* Port wide control signals */                                                   
#define Servo3_CTL                    (* (reg8 *) Servo3__CTL)
/* Drive Modes */
#define Servo3_DM0                    (* (reg8 *) Servo3__DM0) 
#define Servo3_DM1                    (* (reg8 *) Servo3__DM1)
#define Servo3_DM2                    (* (reg8 *) Servo3__DM2) 
/* Input Buffer Disable Override */
#define Servo3_INP_DIS                (* (reg8 *) Servo3__INP_DIS)
/* LCD Common or Segment Drive */
#define Servo3_LCD_COM_SEG            (* (reg8 *) Servo3__LCD_COM_SEG)
/* Enable Segment LCD */
#define Servo3_LCD_EN                 (* (reg8 *) Servo3__LCD_EN)
/* Slew Rate Control */
#define Servo3_SLW                    (* (reg8 *) Servo3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Servo3_PRTDSI__CAPS_SEL       (* (reg8 *) Servo3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Servo3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Servo3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Servo3_PRTDSI__OE_SEL0        (* (reg8 *) Servo3__PRTDSI__OE_SEL0) 
#define Servo3_PRTDSI__OE_SEL1        (* (reg8 *) Servo3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Servo3_PRTDSI__OUT_SEL0       (* (reg8 *) Servo3__PRTDSI__OUT_SEL0) 
#define Servo3_PRTDSI__OUT_SEL1       (* (reg8 *) Servo3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Servo3_PRTDSI__SYNC_OUT       (* (reg8 *) Servo3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Servo3__SIO_CFG)
    #define Servo3_SIO_HYST_EN        (* (reg8 *) Servo3__SIO_HYST_EN)
    #define Servo3_SIO_REG_HIFREQ     (* (reg8 *) Servo3__SIO_REG_HIFREQ)
    #define Servo3_SIO_CFG            (* (reg8 *) Servo3__SIO_CFG)
    #define Servo3_SIO_DIFF           (* (reg8 *) Servo3__SIO_DIFF)
#endif /* (Servo3__SIO_CFG) */

/* Interrupt Registers */
#if defined(Servo3__INTSTAT)
    #define Servo3_INTSTAT            (* (reg8 *) Servo3__INTSTAT)
    #define Servo3_SNAP               (* (reg8 *) Servo3__SNAP)
    
	#define Servo3_0_INTTYPE_REG 		(* (reg8 *) Servo3__0__INTTYPE)
#endif /* (Servo3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Servo3_H */


/* [] END OF FILE */
