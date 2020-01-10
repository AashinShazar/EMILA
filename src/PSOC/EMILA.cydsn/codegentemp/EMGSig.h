/*******************************************************************************
* File Name: EMGSig.h  
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

#if !defined(CY_PINS_EMGSig_H) /* Pins EMGSig_H */
#define CY_PINS_EMGSig_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EMGSig_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EMGSig__PORT == 15 && ((EMGSig__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    EMGSig_Write(uint8 value);
void    EMGSig_SetDriveMode(uint8 mode);
uint8   EMGSig_ReadDataReg(void);
uint8   EMGSig_Read(void);
void    EMGSig_SetInterruptMode(uint16 position, uint16 mode);
uint8   EMGSig_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the EMGSig_SetDriveMode() function.
     *  @{
     */
        #define EMGSig_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define EMGSig_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define EMGSig_DM_RES_UP          PIN_DM_RES_UP
        #define EMGSig_DM_RES_DWN         PIN_DM_RES_DWN
        #define EMGSig_DM_OD_LO           PIN_DM_OD_LO
        #define EMGSig_DM_OD_HI           PIN_DM_OD_HI
        #define EMGSig_DM_STRONG          PIN_DM_STRONG
        #define EMGSig_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define EMGSig_MASK               EMGSig__MASK
#define EMGSig_SHIFT              EMGSig__SHIFT
#define EMGSig_WIDTH              1u

/* Interrupt constants */
#if defined(EMGSig__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in EMGSig_SetInterruptMode() function.
     *  @{
     */
        #define EMGSig_INTR_NONE      (uint16)(0x0000u)
        #define EMGSig_INTR_RISING    (uint16)(0x0001u)
        #define EMGSig_INTR_FALLING   (uint16)(0x0002u)
        #define EMGSig_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define EMGSig_INTR_MASK      (0x01u) 
#endif /* (EMGSig__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EMGSig_PS                     (* (reg8 *) EMGSig__PS)
/* Data Register */
#define EMGSig_DR                     (* (reg8 *) EMGSig__DR)
/* Port Number */
#define EMGSig_PRT_NUM                (* (reg8 *) EMGSig__PRT) 
/* Connect to Analog Globals */                                                  
#define EMGSig_AG                     (* (reg8 *) EMGSig__AG)                       
/* Analog MUX bux enable */
#define EMGSig_AMUX                   (* (reg8 *) EMGSig__AMUX) 
/* Bidirectional Enable */                                                        
#define EMGSig_BIE                    (* (reg8 *) EMGSig__BIE)
/* Bit-mask for Aliased Register Access */
#define EMGSig_BIT_MASK               (* (reg8 *) EMGSig__BIT_MASK)
/* Bypass Enable */
#define EMGSig_BYP                    (* (reg8 *) EMGSig__BYP)
/* Port wide control signals */                                                   
#define EMGSig_CTL                    (* (reg8 *) EMGSig__CTL)
/* Drive Modes */
#define EMGSig_DM0                    (* (reg8 *) EMGSig__DM0) 
#define EMGSig_DM1                    (* (reg8 *) EMGSig__DM1)
#define EMGSig_DM2                    (* (reg8 *) EMGSig__DM2) 
/* Input Buffer Disable Override */
#define EMGSig_INP_DIS                (* (reg8 *) EMGSig__INP_DIS)
/* LCD Common or Segment Drive */
#define EMGSig_LCD_COM_SEG            (* (reg8 *) EMGSig__LCD_COM_SEG)
/* Enable Segment LCD */
#define EMGSig_LCD_EN                 (* (reg8 *) EMGSig__LCD_EN)
/* Slew Rate Control */
#define EMGSig_SLW                    (* (reg8 *) EMGSig__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EMGSig_PRTDSI__CAPS_SEL       (* (reg8 *) EMGSig__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EMGSig_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EMGSig__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EMGSig_PRTDSI__OE_SEL0        (* (reg8 *) EMGSig__PRTDSI__OE_SEL0) 
#define EMGSig_PRTDSI__OE_SEL1        (* (reg8 *) EMGSig__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EMGSig_PRTDSI__OUT_SEL0       (* (reg8 *) EMGSig__PRTDSI__OUT_SEL0) 
#define EMGSig_PRTDSI__OUT_SEL1       (* (reg8 *) EMGSig__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EMGSig_PRTDSI__SYNC_OUT       (* (reg8 *) EMGSig__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(EMGSig__SIO_CFG)
    #define EMGSig_SIO_HYST_EN        (* (reg8 *) EMGSig__SIO_HYST_EN)
    #define EMGSig_SIO_REG_HIFREQ     (* (reg8 *) EMGSig__SIO_REG_HIFREQ)
    #define EMGSig_SIO_CFG            (* (reg8 *) EMGSig__SIO_CFG)
    #define EMGSig_SIO_DIFF           (* (reg8 *) EMGSig__SIO_DIFF)
#endif /* (EMGSig__SIO_CFG) */

/* Interrupt Registers */
#if defined(EMGSig__INTSTAT)
    #define EMGSig_INTSTAT            (* (reg8 *) EMGSig__INTSTAT)
    #define EMGSig_SNAP               (* (reg8 *) EMGSig__SNAP)
    
	#define EMGSig_0_INTTYPE_REG 		(* (reg8 *) EMGSig__0__INTTYPE)
#endif /* (EMGSig__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EMGSig_H */


/* [] END OF FILE */
