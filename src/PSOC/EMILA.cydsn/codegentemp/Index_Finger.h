/*******************************************************************************
* File Name: Index_Finger.h  
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

#if !defined(CY_PINS_Index_Finger_H) /* Pins Index_Finger_H */
#define CY_PINS_Index_Finger_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Index_Finger_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Index_Finger__PORT == 15 && ((Index_Finger__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Index_Finger_Write(uint8 value);
void    Index_Finger_SetDriveMode(uint8 mode);
uint8   Index_Finger_ReadDataReg(void);
uint8   Index_Finger_Read(void);
void    Index_Finger_SetInterruptMode(uint16 position, uint16 mode);
uint8   Index_Finger_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Index_Finger_SetDriveMode() function.
     *  @{
     */
        #define Index_Finger_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Index_Finger_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Index_Finger_DM_RES_UP          PIN_DM_RES_UP
        #define Index_Finger_DM_RES_DWN         PIN_DM_RES_DWN
        #define Index_Finger_DM_OD_LO           PIN_DM_OD_LO
        #define Index_Finger_DM_OD_HI           PIN_DM_OD_HI
        #define Index_Finger_DM_STRONG          PIN_DM_STRONG
        #define Index_Finger_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Index_Finger_MASK               Index_Finger__MASK
#define Index_Finger_SHIFT              Index_Finger__SHIFT
#define Index_Finger_WIDTH              1u

/* Interrupt constants */
#if defined(Index_Finger__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Index_Finger_SetInterruptMode() function.
     *  @{
     */
        #define Index_Finger_INTR_NONE      (uint16)(0x0000u)
        #define Index_Finger_INTR_RISING    (uint16)(0x0001u)
        #define Index_Finger_INTR_FALLING   (uint16)(0x0002u)
        #define Index_Finger_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Index_Finger_INTR_MASK      (0x01u) 
#endif /* (Index_Finger__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Index_Finger_PS                     (* (reg8 *) Index_Finger__PS)
/* Data Register */
#define Index_Finger_DR                     (* (reg8 *) Index_Finger__DR)
/* Port Number */
#define Index_Finger_PRT_NUM                (* (reg8 *) Index_Finger__PRT) 
/* Connect to Analog Globals */                                                  
#define Index_Finger_AG                     (* (reg8 *) Index_Finger__AG)                       
/* Analog MUX bux enable */
#define Index_Finger_AMUX                   (* (reg8 *) Index_Finger__AMUX) 
/* Bidirectional Enable */                                                        
#define Index_Finger_BIE                    (* (reg8 *) Index_Finger__BIE)
/* Bit-mask for Aliased Register Access */
#define Index_Finger_BIT_MASK               (* (reg8 *) Index_Finger__BIT_MASK)
/* Bypass Enable */
#define Index_Finger_BYP                    (* (reg8 *) Index_Finger__BYP)
/* Port wide control signals */                                                   
#define Index_Finger_CTL                    (* (reg8 *) Index_Finger__CTL)
/* Drive Modes */
#define Index_Finger_DM0                    (* (reg8 *) Index_Finger__DM0) 
#define Index_Finger_DM1                    (* (reg8 *) Index_Finger__DM1)
#define Index_Finger_DM2                    (* (reg8 *) Index_Finger__DM2) 
/* Input Buffer Disable Override */
#define Index_Finger_INP_DIS                (* (reg8 *) Index_Finger__INP_DIS)
/* LCD Common or Segment Drive */
#define Index_Finger_LCD_COM_SEG            (* (reg8 *) Index_Finger__LCD_COM_SEG)
/* Enable Segment LCD */
#define Index_Finger_LCD_EN                 (* (reg8 *) Index_Finger__LCD_EN)
/* Slew Rate Control */
#define Index_Finger_SLW                    (* (reg8 *) Index_Finger__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Index_Finger_PRTDSI__CAPS_SEL       (* (reg8 *) Index_Finger__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Index_Finger_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Index_Finger__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Index_Finger_PRTDSI__OE_SEL0        (* (reg8 *) Index_Finger__PRTDSI__OE_SEL0) 
#define Index_Finger_PRTDSI__OE_SEL1        (* (reg8 *) Index_Finger__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Index_Finger_PRTDSI__OUT_SEL0       (* (reg8 *) Index_Finger__PRTDSI__OUT_SEL0) 
#define Index_Finger_PRTDSI__OUT_SEL1       (* (reg8 *) Index_Finger__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Index_Finger_PRTDSI__SYNC_OUT       (* (reg8 *) Index_Finger__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Index_Finger__SIO_CFG)
    #define Index_Finger_SIO_HYST_EN        (* (reg8 *) Index_Finger__SIO_HYST_EN)
    #define Index_Finger_SIO_REG_HIFREQ     (* (reg8 *) Index_Finger__SIO_REG_HIFREQ)
    #define Index_Finger_SIO_CFG            (* (reg8 *) Index_Finger__SIO_CFG)
    #define Index_Finger_SIO_DIFF           (* (reg8 *) Index_Finger__SIO_DIFF)
#endif /* (Index_Finger__SIO_CFG) */

/* Interrupt Registers */
#if defined(Index_Finger__INTSTAT)
    #define Index_Finger_INTSTAT            (* (reg8 *) Index_Finger__INTSTAT)
    #define Index_Finger_SNAP               (* (reg8 *) Index_Finger__SNAP)
    
	#define Index_Finger_0_INTTYPE_REG 		(* (reg8 *) Index_Finger__0__INTTYPE)
#endif /* (Index_Finger__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Index_Finger_H */


/* [] END OF FILE */
