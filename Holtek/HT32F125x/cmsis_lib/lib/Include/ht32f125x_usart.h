/*********************************************************************************************************//**
 * @file    ht32f125x_usart.h
 * @version V1.0
 * @date    04/11/2011
 * @brief   The header file of the USART library.
 *************************************************************************************************************
 *
 * <h2><center>Copyright (C) 2011 Holtek Semiconductor Inc. All rights reserved</center></h2>
 *
 ************************************************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __ht32f125x_usart_H
#define __ht32f125x_usart_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32f125x.h"

/** @addtogroup HT32F125x_Peripheral_Driver
  * @{
  */

/** @addtogroup USART
  * @{
  */

/* Exported types ------------------------------------------------------------------------------------------*/

/** @defgroup USART_Exported_Types USART exported types
  * @{
  */
/* Definition of USART Init Structure  ---------------------------------------------------------------------*/
typedef struct
{
  u32 USART_BaudRate;
  u16 USART_WordLength;
  u16 USART_StopBits;
  u16 USART_Parity;
  u16 USART_Mode;
}USART_InitTypeDef;

typedef struct
{
  u16 USART_ClockEnable;
  u16 USART_ClockPhase;
  u16 USART_ClockPolarity;
  u16 USART_TransferSelectMode;
} USART_SynClock_InitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/

/** @defgroup USART_Exported_Constants USART exported constants
  * @{
  */

/* USART Word Length ---------------------------------------------------------------------------------------*/
/** @defgroup USART_Word_Length Definitions of USART word length
  * @{
  */
#define USART_WORDLENGTH_7B                    ((u32)0x00000000)
#define USART_WORDLENGTH_8B                    ((u32)0x00000001)
#define USART_WORDLENGTH_9B                    ((u32)0x00000002)

#define IS_USART_WORD_LENGTH(LENGTH) ((LENGTH == USART_WORDLENGTH_9B) || \
                                      (LENGTH == USART_WORDLENGTH_8B) || \
                                      (LENGTH == USART_WORDLENGTH_7B))

/**
  * @}
  */

/* USART Stop Bits -----------------------------------------------------------------------------------------*/
/** @defgroup USART_Stop_Bit Definitions of USART stop bit
  * @{  
  */  
#define USART_STOPBITS_1                       ((u32)0x00000000)
#define USART_STOPBITS_2                       ((u32)0x00000004)


#define IS_USART_STOPBITS(STOPBITS) ((STOPBITS == USART_STOPBITS_1) || \
                                     (STOPBITS == USART_STOPBITS_2))

/**
  * @}
  */

/* USART Parity--------------------------------------------------------------------------------------------*/
/** @defgroup USART_Parity Definitions of USART parity
  * @{
  */
#define USART_PARITY_NO                        ((u32)0x00000000)
#define USART_PARITY_EVEN                      ((u32)0x00000018)
#define USART_PARITY_ODD                       ((u32)0x00000008)

#define IS_USART_PARITY(PARITY) ((PARITY == USART_PARITY_NO) || \
                                 (PARITY == USART_PARITY_EVEN) || \
                                 (PARITY == USART_PARITY_ODD))

/**
  * @}
  */

/* USART Mode ----------------------------------------------------------------------------------------------*/
/** @defgroup USART_Mode Definitions of USART mode
  * @{
  */
#define USART_MODE_NORMAL                      ((u32)0x00000000)
#define USART_MODE_IRDA                        ((u32)0x00000001)
#define USART_MODE_RS485                       ((u32)0x00000002)
#define USART_MODE_SYNCHRONOUS                 ((u32)0x00000003)

#define IS_USART_MODE(MODE) ((MODE == USART_MODE_NORMAL) || \
                             (MODE == USART_MODE_IRDA) || \
                             (MODE == USART_MODE_RS485) || \
                             (MODE == USART_MODE_SYNCHRONOUS))
/**
  * @}
  */

/* USART Transfer Select Mode ------------------------------------------------------------------------------*/
/** @defgroup USART_LSB Definitions of USART LSB
  * @{
  */
#define USART_LSB_FRIST                        ((u32)0x00000000)
#define USART_MSB_FRIST                        ((u32)0x00000004)

#define IS_USART_TRANSFER_MODE(TMODE) ((TMODE == USART_LSB_FRIST) || \
                                       (TMODE == USART_MSB_FRIST))
/**
  * @}
  */


/* USART Synchronous Clock ---------------------------------------------------------------------------------*/
/** @defgroup USART_Synchronous_Clock Definitions of USART synchronous clock
  * @{
  */
#define USART_SYN_CLOCK_DISABLE                ((u32)0x00000000)
#define USART_SYN_CLOCK_ENABLE                 ((u32)0x00000001)

#define IS_USART_SYNCHRONOUS_CLOCK(SYNCLOCK) ((SYNCLOCK == USART_SYN_CLOCK_DISABLE) || \
                                              (SYNCLOCK == USART_SYN_CLOCK_ENABLE))
/**
  * @}
  */
/* USART Synchronous Clock Phase ---------------------------------------------------------------------------*/
/** @defgroup USART_Synchronous_Clock_Phase Definitions of USART Synchronous clock phase
  * @{
  */
#define USART_SYN_CLOCK_PHASE_FIRST            ((u32)0x00000000)
#define USART_SYN_CLOCK_PHASE_SECOND           ((u32)0x00000004)

#define IS_USART_SYNCHRONOUS_PHASE(PHASE) ((PHASE == USART_SYN_CLOCK_PHASE_FIRST) || \
                                           (PHASE == USART_SYN_CLOCK_PHASE_SECOND))
/**
  * @}
  */

/* USART Clock Polarity ------------------------------------------------------------------------------------*/
/** @defgroup USART_Clock_Polarity Definitions of USART clock polarity
  * @{
  */
#define USART_SYN_CLOCK_POLARITY_LOW           ((u32)0x00000000)
#define USART_SYN_CLOCK_POLARITY_HIGH          ((u32)0x00000008)

#define IS_USART_SYNCHRONOUS_POLARITY(POLARITY) ((POLARITY == USART_SYN_CLOCK_POLARITY_LOW) || \
                                                 (POLARITY == USART_SYN_CLOCK_POLARITY_HIGH))
/**
  * @}
  */

/* USART IrDA  ---------------------------------------------------------------------------------------------*/
/** @defgroup USART_IrDA Definitions of USART IrDA
  * @{
  */
#define USART_IRDA_LOWPOWER                    ((u32)0x00000002)
#define USART_IRDA_NORMAL                      ((u32)0xFFFFFFFD)

#define IS_USART_IRDA_MODE(MODE) ((MODE == USART_IRDA_LOWPOWER) || (MODE == USART_IRDA_NORMAL))

#define USART_IRDA_TX                          ((u32)0x00000004)
#define USART_IRDA_RX                          ((u32)0xFFFFFFFB)

#define IS_USART_IRDA_DIRECTION(DIRECTION) ((DIRECTION == USART_IRDA_TX) || (DIRECTION == USART_IRDA_RX))
                             
/**
  * @}
  */

/* USART Rx FIFO Interrupt Trigger Level--------------------------------------------------------------------*/
/** @defgroup USART_RX_FIFO_Trigger_Level Definitions of USART Rx FIFO interrupts
  * @{
  */
#define USART_RFITL_01                     ((u32)0x00000000)
#define USART_RFITL_04                     ((u32)0x00000040)
#define USART_RFITL_08                     ((u32)0x00000080)
#define USART_RFITL_14                     ((u32)0x000000C0)

#define IS_USART_RFITL(RFITL) ((RFITL == USART_RFITL_01) || \
                               (RFITL == USART_RFITL_04) || \
                               (RFITL == USART_RFITL_08) || \
                               (RFITL == USART_RFITL_14))
/**
  * @}
  */

/* USART Tx FIFO Interrupt Trigger Level--------------------------------------------------------------------*/
/** @defgroup USART_TX_FIFO_Trigger_Level Definitions of USART Tx FIFO interrupts
  * @{
  */
#define USART_TFITL_00                     ((u32)0x00000000)
#define USART_TFITL_02                     ((u32)0x00000010)
#define USART_TFITL_04                     ((u32)0x00000020)
#define USART_TFITL_08                     ((u32)0x00000030)

#define IS_USART_TFITL(TFITL) ((TFITL == USART_TFITL_00) || \
                               (TFITL == USART_TFITL_02) || \
                               (TFITL == USART_TFITL_04) || \
                               (TFITL == USART_TFITL_08))
/**
  * @}
  */

/* USART Interrupt definition ------------------------------------------------------------------------------*/
/** @defgroup USART_Interrupt Definitions of USART interrupts
  * @{
  */
#define USART_IID_RLS                          ((u8)0x06)
#define USART_IID_RDA                          ((u8)0x04)
#define USART_IID_CTI                          ((u8)0x0C)
#define USART_IID_THRE                         ((u8)0x02)
#define USART_IID_MS                           ((u8)0x00)
#define USART_IID_NON                          ((u8)0x01)

#define IS_USART_IID(IID) ((IID == USART_IID_RLS) || (IID == USART_IID_RDA) || \
                           (IID == USART_IID_CTI) || (IID == USART_IID_THRE) || \
                           (IID == USART_IID_MS)  || (IID == USART_IID_NON))
                           

#define USART_IER_MSIE                         ((u32)0x00000008)
#define USART_IER_RLSIE                        ((u32)0x00000004)
#define USART_IER_THREIE                       ((u32)0x00000002)
#define USART_IER_RDAIE                        ((u32)0x00000001)
#define USART_IER_ALL                          ((u32)0x0000000F)

#define IS_USART_CONFIG_IER(IER) (((IER & 0xFFFFFFF0) == 0x0) && (IER != 0x0))

/**
  * @}
  */

/* USART Flags ---------------------------------------------------------------------------------------------*/
/** @defgroup USART_Flag Definitions of USART flags
  * @{
  */
#define USART_LSR_RFDR                         ((u32)0x00000001)
#define USART_LSR_OEI                          ((u32)0x00000002)
#define USART_LSR_PEI                          ((u32)0x00000004)
#define USART_LSR_FEI                          ((u32)0x00000008)
#define USART_LSR_BII                          ((u32)0x00000010)
#define USART_LSR_THRE                         ((u32)0x00000020)
#define USART_LSR_TE                           ((u32)0x00000040)
#define USART_LSR_ERR                          ((u32)0x00000080)

#define IS_USART_LSR_FLAG(FLAG) ((FLAG == USART_LSR_RFDR) || (FLAG == USART_LSR_OEI) || \
                                 (FLAG == USART_LSR_PEI) || (FLAG == USART_LSR_FEI) || \
                                 (FLAG == USART_LSR_BII) || (FLAG == USART_LSR_THRE) || \
                                 (FLAG == USART_LSR_TE) || (FLAG == USART_LSR_ERR))                                

/**
  * @}
  */
  
/* USART Modem definition ------------------------------------------------------------------------------*/
/** @defgroup USART_MODEM Definitions of USART Modem
  * @{
  */
#define USART_MODEM_DTR                        ((u32)0x00000000)
#define USART_MODEM_RTS                        ((u32)0x00000001)

#define IS_USART_MODEM_PIN(PIN) ((PIN == USART_MODEM_DTR) || (PIN == USART_MODEM_RTS))

#define USART_MODEMSTATE_HIGH                  ((u32)0x00000000)
#define USART_MODEMSTATE_LOW                   ((u32)0x00000001)

#define IS_USART_MODEM_STATE(STATE) ((STATE == USART_MODEMSTATE_HIGH) || (STATE == USART_MODEMSTATE_LOW))
                                                                 
/**
  * @}
  */
  
/* USART RS485 definition ------------------------------------------------------------------------------*/
/** @defgroup USART_RS485 Definitions of USART RS485
  * @{
  */
#define USART_RS485POLARITY_LOW                ((u32)0x00000001)
#define USART_RS485POLARITY_HIGH               ((u32)0xFFFFFFFE)

#define IS_USART_RS485_POLARITY(POLARITY) ((POLARITY == USART_RS485POLARITY_LOW) || (POLARITY == USART_RS485POLARITY_HIGH))
                                                                 
/**
  * @}
  */ 
  
#define USART_FIFO_TX                                 ((u32)0x00000004)
#define USART_FIFO_RX                                 ((u32)0x00000002)

#define IS_USART_FIFO_DIRECTION(DIRECTION)            (((DIRECTION & 0xFFFFFFF9) == 0x0) && (DIRECTION != 0x0))

#define USART_STICK_LOW                               ((u32)0x00000010)
#define USART_STICK_HIGH                              ((u32)0xFFFFFFEF)

#define IS_USART_STICK_PARITY(PARITY)                 ((PARITY == USART_STICK_LOW) || (PARITY == USART_STICK_HIGH))



#define IS_USART(x) (x == USART)
#define IS_USART_BAUDRATE(BAUDRATE) ((BAUDRATE > 0) && (BAUDRATE < 0x0044AA21))
#define IS_USART_DATA(DATA) (DATA <= 0x1FF)
#define IS_USART_GUARD_TIME(TIME) (TIME <= 0xFF) 
#define IS_USART_IRDA_PRESCALER(PRESCALER) (PRESCALER <= 0xFF) 
#define IS_USART_TIMEOUT(TIMEOUT) (TIMEOUT <= 0x7F)

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------------------------------------*/

/** @defgroup USART_Exported_Macro USART exported macro
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/

/** @defgroup USART_Exported_Functions USART exported functions
  * @{
  */
void USART_DeInit(USART_TypeDef* USARTx);
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStructure);
void USART_StructInit(USART_InitTypeDef* USART_InitStructure);
void USART_SynClockInit(USART_TypeDef* USARTx, USART_SynClock_InitTypeDef* USART_SynClock_InitStruct);
void USART_SynClockStructInit(USART_SynClock_InitTypeDef* USART_SynClock_InitStruct);
void USART_SendData(USART_TypeDef* USARTx, u16 Data);
u16 USART_ReceiveData(USART_TypeDef* USARTx);
void USART_SetGuardTime(USART_TypeDef* USARTx, u32 USART_GuardTime);
FlagStatus USART_GetLineStatus(USART_TypeDef* USARTx, u32 USART_FLAG);
u8 USART_GetModemStatus(USART_TypeDef* USARTx);
void USART_ForceModemPinState(USART_TypeDef* USARTx, u32 USART_ModemPin, u32 USART_ModemState);
void USART_IrDACmd(USART_TypeDef* USARTx, ControlStatus NewState);
void USART_IrDAConfig(USART_TypeDef* USARTx, u32 USART_IrDAMode);
void USART_SetIrDAPrescaler(USART_TypeDef* USARTx, u32 USART_IrDAPrescaler);
void USART_IrDADirectionConfig(USART_TypeDef* USARTx, u32 USART_IrDADirection);
void USART_RS485TxEnablePolarityConfig(USART_TypeDef* USARTx, u32 USART_RS485Polarity);
void USART_ForceBreakCmd(USART_TypeDef* USARTx, ControlStatus NewState);
void USART_IntConfig(USART_TypeDef* USARTx, u32 USART_IER, ControlStatus NewState);
u8 USART_GetIntID(USART_TypeDef* USARTx);
void USART_RFITLConfig(USART_TypeDef* USARTx, u32 USART_RFITL);
void USART_TFITLConfig(USART_TypeDef* USARTx, u32 USART_TFITL);
void USART_TimeOutIntConfig(USART_TypeDef* USARTx, ControlStatus NewState);
void USART_SetTimeOutValue(USART_TypeDef* USARTx, u32 USART_TimeOut);
void USART_FIFOReset(USART_TypeDef* USARTx, u32 USART_FIFODirection);
void USART_StickParityCmd(USART_TypeDef* USARTx, ControlStatus NewState);
void USART_StickParityConfig(USART_TypeDef * USARTx, u32 USART_StickParity);



#ifdef __cplusplus
}
#endif

#endif /* __HT32F125x_USART_H -------------------------------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
