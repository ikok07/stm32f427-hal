/*
 * Copyright (c) 2009-2024 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * CMSIS Cortex-M23 Core Peripheral Access Layer Header File
 */

#if   defined ( __ICCARM__ )
  #pragma system_include                        /* treat file as system include file for MISRA check */
#elif defined (__clang__)
  #pragma clang system_header                   /* treat file as system include file */
#elif defined ( __GNUC__ )
  #pragma GCC diagnostic ignored "-Wpedantic"   /* disable pedantic warning due to unnamed structs/unions */
#endif

#ifndef __CORE_CM23_H_GENERIC
#define __CORE_CM23_H_GENERIC

#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

/**
  \page CMSIS_MISRA_Exceptions  MISRA-C:2004 Compliance Exceptions
  CMSIS violates the following MISRA-C:2004 rules:

   \li Required Rule 8.5, object/function definition in header file.<br>
     Function definitions in header files are used to allow 'inlining'.

   \li Required Rule 18.4, declaration of union type or object of union type: '{...}'.<br>
     Unions are used for effective representation of core registers.

   \li Advisory Rule 19.7, Function-like macro defined.<br>
     Function-like macros are used to allow more efficient code.
 */


/*******************************************************************************
 *                 CMSIS definitions
 ******************************************************************************/
/**
  \ingroup Cortex_M23
  @{
 */

#include "cmsis_version.h"

/* CMSIS CM23 definitions */

#define __CORTEX_M                (23U)                               /*!< Cortex-M Core */

/** __FPU_USED indicates whether an FPU is used or not.
    This core does not support an FPU at all
*/
#define __FPU_USED       0U

#if defined ( __CC_ARM )
  #if defined (__TARGET_FPU_VFP)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #if defined (__ARM_FP)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined (__ti__)
  #if defined (__ARM_FP)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __GNUC__ )
  #if defined (__VFP_FP__) && !defined(__SOFTFP__)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __ICCARM__ )
  #if defined (__ARMVFP__)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __TI_ARM__ )
  #if defined (__TI_VFP_SUPPORT__)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __TASKING__ )
  #if defined (__FPU_VFP__)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#elif defined ( __CSMC__ )
  #if ( __CSMC__ & 0x400U)
    #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
  #endif

#endif

#include "cmsis_compiler.h"


#ifdef __cplusplus
}
#endif

#endif /* __CORE_CM23_H_GENERIC */

#ifndef __CMSIS_GENERIC

#ifndef __CORE_CM23_H_DEPENDANT
#define __CORE_CM23_H_DEPENDANT

#ifdef __cplusplus
 extern "C" {
#endif

/* check device defines and use defaults */
#if defined __CHECK_DEVICE_DEFINES
  #ifndef __CM23_REV
    #define __CM23_REV                0x0000U
    #warning "__CM23_REV not defined in device header file; using default!"
  #endif

  #ifndef __FPU_PRESENT
    #define __FPU_PRESENT             0U
    #warning "__FPU_PRESENT not defined in device header file; using default!"
  #endif

  #ifndef __MPU_PRESENT
    #define __MPU_PRESENT             0U
    #warning "__MPU_PRESENT not defined in device header file; using default!"
  #endif

  #ifndef __SAUREGION_PRESENT
    #define __SAUREGION_PRESENT       0U
    #warning "__SAUREGION_PRESENT not defined in device header file; using default!"
  #endif

  #ifndef __VTOR_PRESENT
    #define __VTOR_PRESENT            0U
    #warning "__VTOR_PRESENT not defined in device header file; using default!"
  #endif

  #ifndef __NVIC_PRIO_BITS
    #define __NVIC_PRIO_BITS          2U
    #warning "__NVIC_PRIO_BITS not defined in device header file; using default!"
  #endif

  #ifndef __Vendor_SysTickConfig
    #define __Vendor_SysTickConfig    0U
    #warning "__Vendor_SysTickConfig not defined in device header file; using default!"
  #endif

  #ifndef __ETM_PRESENT
    #define __ETM_PRESENT             0U
    #warning "__ETM_PRESENT not defined in device header file; using default!"
  #endif

  #ifndef __MTB_PRESENT
    #define __MTB_PRESENT             0U
    #warning "__MTB_PRESENT not defined in device header file; using default!"
  #endif

#endif

/* IO definitions (access restrictions to peripheral registers) */
/**
    \defgroup CMSIS_glob_defs CMSIS Global Defines

    <strong>IO Type Qualifiers</strong> are used
    \li to specify the access to peripheral variables.
    \li for automatic generation of peripheral register debug information.
*/
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

/*@} end of group Cortex_M23 */



/*******************************************************************************
 *                 Register Abstraction
  Core Register contain:
  - Core Register
  - Core NVIC Register
  - Core SCB Register
  - Core SysTick Register
  - Core Debug Register
  - Core MPU Register
  - Core SAU Register
 ******************************************************************************/
/**
  \defgroup CMSIS_core_register Defines and Type Definitions
  \brief Type definitions and defines for Cortex-M processor based devices.
*/

/**
  \ingroup    CMSIS_core_register
  \defgroup   CMSIS_CORE  Status and Control Registers
  \brief      Core Register type definitions.
  @{
 */

/**
  \brief  Union type to access the Application Program Status Register (APSR).
 */
typedef union
{
  struct
  {
    uint32_t _reserved0:28;              /*!< bit:  0..27  Reserved */
    uint32_t V:1;                        /*!< bit:     28  Overflow condition code flag */
    uint32_t C:1;                        /*!< bit:     29  Carry condition code flag */
    uint32_t Z:1;                        /*!< bit:     30  Zero condition code flag */
    uint32_t N:1;                        /*!< bit:     31  Negative condition code flag */
  } b;                                   /*!< Structure used for bit  access */
  uint32_t w;                            /*!< Type      used for word access */
} APSR_Type;

/** \brief APSR Register Definitions */
#define APSR_N_Pos                         31U                                            /*!< APSR: N Position */
#define APSR_N_Msk                         (1UL << APSR_N_Pos)                            /*!< APSR: N Mask */

#define APSR_Z_Pos                         30U                                            /*!< APSR: Z Position */
#define APSR_Z_Msk                         (1UL << APSR_Z_Pos)                            /*!< APSR: Z Mask */

#define APSR_C_Pos                         29U                                            /*!< APSR: C Position */
#define APSR_C_Msk                         (1UL << APSR_C_Pos)                            /*!< APSR: C Mask */

#define APSR_V_Pos                         28U                                            /*!< APSR: V Position */
#define APSR_V_Msk                         (1UL << APSR_V_Pos)                            /*!< APSR: V Mask */


/**
  \brief  Union type to access the Interrupt Program Status Register (IPSR).
 */
typedef union
{
  struct
  {
    uint32_t ISR:9;                      /*!< bit:  0.. 8  Exception number */
    uint32_t _reserved0:23;              /*!< bit:  9..31  Reserved */
  } b;                                   /*!< Structure used for bit  access */
  uint32_t w;                            /*!< Type      used for word access */
} IPSR_Type;

/** \brief IPSR Register Definitions */
#define IPSR_ISR_Pos                        0U                                            /*!< IPSR: ISR Position */
#define IPSR_ISR_Msk                       (0x1FFUL /*<< IPSR_ISR_Pos*/)                  /*!< IPSR: ISR Mask */


/**
  \brief  Union type to access the Special-Purpose Program Status Registers (xPSR).
 */
typedef union
{
  struct
  {
    uint32_t ISR:9;                      /*!< bit:  0.. 8  Exception number */
    uint32_t _reserved0:15;              /*!< bit:  9..23  Reserved */
    uint32_t T:1;                        /*!< bit:     24  Thumb bit        (read 0) */
    uint32_t _reserved1:3;               /*!< bit: 25..27  Reserved */
    uint32_t V:1;                        /*!< bit:     28  Overflow condition code flag */
    uint32_t C:1;                        /*!< bit:     29  Carry condition code flag */
    uint32_t Z:1;                        /*!< bit:     30  Zero condition code flag */
    uint32_t N:1;                        /*!< bit:     31  Negative condition code flag */
  } b;                                   /*!< Structure used for bit  access */
  uint32_t w;                            /*!< Type      used for word access */
} xPSR_Type;

/** \brief xPSR Register Definitions */
#define xPSR_N_Pos                         31U                                            /*!< xPSR: N Position */
#define xPSR_N_Msk                         (1UL << xPSR_N_Pos)                            /*!< xPSR: N Mask */

#define xPSR_Z_Pos                         30U                                            /*!< xPSR: Z Position */
#define xPSR_Z_Msk                         (1UL << xPSR_Z_Pos)                            /*!< xPSR: Z Mask */

#define xPSR_C_Pos                         29U                                            /*!< xPSR: C Position */
#define xPSR_C_Msk                         (1UL << xPSR_C_Pos)                            /*!< xPSR: C Mask */

#define xPSR_V_Pos                         28U                                            /*!< xPSR: V Position */
#define xPSR_V_Msk                         (1UL << xPSR_V_Pos)                            /*!< xPSR: V Mask */

#define xPSR_T_Pos                         24U                                            /*!< xPSR: T Position */
#define xPSR_T_Msk                         (1UL << xPSR_T_Pos)                            /*!< xPSR: T Mask */

#define xPSR_ISR_Pos                        0U                                            /*!< xPSR: ISR Position */
#define xPSR_ISR_Msk                       (0x1FFUL /*<< xPSR_ISR_Pos*/)                  /*!< xPSR: ISR Mask */


/**
  \brief  Union type to access the Control Registers (CONTROL).
 */
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                    /*!< bit:      0  Execution privilege in Thread mode */
    uint32_t SPSEL:1;                    /*!< bit:      1  Stack-pointer select */
    uint32_t _reserved1:30;              /*!< bit:  2..31  Reserved */
  } b;                                   /*!< Structure used for bit  access */
  uint32_t w;                            /*!< Type      used for word access */
} CONTROL_Type;

/** \brief CONTROL Register Definitions */
#define CONTROL_SPSEL_Pos                   1U                                            /*!< CONTROL: SPSEL Position */
#define CONTROL_SPSEL_Msk                  (1UL << CONTROL_SPSEL_Pos)                     /*!< CONTROL: SPSEL Mask */

#define CONTROL_nPRIV_Pos                   0U                                            /*!< CONTROL: nPRIV Position */
#define CONTROL_nPRIV_Msk                  (1UL /*<< CONTROL_nPRIV_Pos*/)                 /*!< CONTROL: nPRIV Mask */

/*@} end of group CMSIS_CORE */


/**
  \ingroup    CMSIS_core_register
  \defgroup   CMSIS_NVIC  Nested Vectored Interrupt Controller (NVIC)
  \brief      Type definitions for the NVIC Registers
  @{
 */

/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  __IOM uint32_t ISER[16U];              /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[16U];
  __IOM uint32_t ICER[16U];              /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RESERVED1[16U];
  __IOM uint32_t ISPR[16U];              /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[16U];
  __IOM uint32_t ICPR[16U];              /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[16U];
  __IOM uint32_t IABR[16U];              /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[16U];
  __IOM uint32_t ITNS[16U];              /*!< Offset: 0x280 (R/W)  Interrupt Non-Secure State Register */
        uint32_t RESERVED5[16U];
  __IOM uint32_t IPR[124U];              /*!< Offset: 0x300 (R/W)  Interrupt Priority Register */
}  NVIC_Type;

/*@} end of group CMSIS_NVIC */


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_SCB     System Control Block (SCB)
  \brief    Type definitions for the System Control Block Registers
  @{
 */

/**
  \brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
  __IM  uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  __IOM uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
  __IOM uint32_t VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
#else
        uint32_t RESERVED0;
#endif
  __IOM uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  __IOM uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  __IOM uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
        uint32_t RESERVED1;
  __IOM uint32_t SHPR[2U];               /*!< Offset: 0x01C (R/W)  System Handlers Priority Registers. [0] is RESERVED */
  __IOM uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
} SCB_Type;

/** \brief SCB CPUID Register Definitions */
#define SCB_CPUID_IMPLEMENTER_Pos          24U                                            /*!< SCB CPUID: IMPLEMENTER Position */
#define SCB_CPUID_IMPLEMENTER_Msk          (0xFFUL << SCB_CPUID_IMPLEMENTER_Pos)          /*!< SCB CPUID: IMPLEMENTER Mask */

#define SCB_CPUID_VARIANT_Pos              20U                                            /*!< SCB CPUID: VARIANT Position */
#define SCB_CPUID_VARIANT_Msk              (0xFUL << SCB_CPUID_VARIANT_Pos)               /*!< SCB CPUID: VARIANT Mask */

#define SCB_CPUID_ARCHITECTURE_Pos         16U                                            /*!< SCB CPUID: ARCHITECTURE Position */
#define SCB_CPUID_ARCHITECTURE_Msk         (0xFUL << SCB_CPUID_ARCHITECTURE_Pos)          /*!< SCB CPUID: ARCHITECTURE Mask */

#define SCB_CPUID_PARTNO_Pos                4U                                            /*!< SCB CPUID: PARTNO Position */
#define SCB_CPUID_PARTNO_Msk               (0xFFFUL << SCB_CPUID_PARTNO_Pos)              /*!< SCB CPUID: PARTNO Mask */

#define SCB_CPUID_REVISION_Pos              0U                                            /*!< SCB CPUID: REVISION Position */
#define SCB_CPUID_REVISION_Msk             (0xFUL /*<< SCB_CPUID_REVISION_Pos*/)          /*!< SCB CPUID: REVISION Mask */

/** \brief SCB Interrupt Control State Register Definitions */
#define SCB_ICSR_PENDNMISET_Pos            31U                                            /*!< SCB ICSR: PENDNMISET Position */
#define SCB_ICSR_PENDNMISET_Msk            (1UL << SCB_ICSR_PENDNMISET_Pos)               /*!< SCB ICSR: PENDNMISET Mask */

#define SCB_ICSR_NMIPENDSET_Pos            SCB_ICSR_PENDNMISET_Pos                        /*!< SCB ICSR: NMIPENDSET Position, backward compatibility */
#define SCB_ICSR_NMIPENDSET_Msk            SCB_ICSR_PENDNMISET_Msk                        /*!< SCB ICSR: NMIPENDSET Mask, backward compatibility */

#define SCB_ICSR_PENDNMICLR_Pos            30U                                            /*!< SCB ICSR: PENDNMICLR Position */
#define SCB_ICSR_PENDNMICLR_Msk            (1UL << SCB_ICSR_PENDNMICLR_Pos)               /*!< SCB ICSR: PENDNMICLR Mask */

#define SCB_ICSR_PENDSVSET_Pos             28U                                            /*!< SCB ICSR: PENDSVSET Position */
#define SCB_ICSR_PENDSVSET_Msk             (1UL << SCB_ICSR_PENDSVSET_Pos)                /*!< SCB ICSR: PENDSVSET Mask */

#define SCB_ICSR_PENDSVCLR_Pos             27U                                            /*!< SCB ICSR: PENDSVCLR Position */
#define SCB_ICSR_PENDSVCLR_Msk             (1UL << SCB_ICSR_PENDSVCLR_Pos)                /*!< SCB ICSR: PENDSVCLR Mask */

#define SCB_ICSR_PENDSTSET_Pos             26U                                            /*!< SCB ICSR: PENDSTSET Position */
#define SCB_ICSR_PENDSTSET_Msk             (1UL << SCB_ICSR_PENDSTSET_Pos)                /*!< SCB ICSR: PENDSTSET Mask */

#define SCB_ICSR_PENDSTCLR_Pos             25U                                            /*!< SCB ICSR: PENDSTCLR Position */
#define SCB_ICSR_PENDSTCLR_Msk             (1UL << SCB_ICSR_PENDSTCLR_Pos)                /*!< SCB ICSR: PENDSTCLR Mask */

#define SCB_ICSR_STTNS_Pos                 24U                                            /*!< SCB ICSR: STTNS Position (Security Extension) */
#define SCB_ICSR_STTNS_Msk                 (1UL << SCB_ICSR_STTNS_Pos)                    /*!< SCB ICSR: STTNS Mask (Security Extension) */

#define SCB_ICSR_ISRPREEMPT_Pos            23U                                            /*!< SCB ICSR: ISRPREEMPT Position */
#define SCB_ICSR_ISRPREEMPT_Msk            (1UL << SCB_ICSR_ISRPREEMPT_Pos)               /*!< SCB ICSR: ISRPREEMPT Mask */

#define SCB_ICSR_ISRPENDING_Pos            22U                                            /*!< SCB ICSR: ISRPENDING Position */
#define SCB_ICSR_ISRPENDING_Msk            (1UL << SCB_ICSR_ISRPENDING_Pos)               /*!< SCB ICSR: ISRPENDING Mask */

#define SCB_ICSR_VECTPENDING_Pos           12U                                            /*!< SCB ICSR: VECTPENDING Position */
#define SCB_ICSR_VECTPENDING_Msk           (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)          /*!< SCB ICSR: VECTPENDING Mask */

#define SCB_ICSR_RETTOBASE_Pos             11U                                            /*!< SCB ICSR: RETTOBASE Position */
#define SCB_ICSR_RETTOBASE_Msk             (1UL << SCB_ICSR_RETTOBASE_Pos)                /*!< SCB ICSR: RETTOBASE Mask */

#define SCB_ICSR_VECTACTIVE_Pos             0U                                            /*!< SCB ICSR: VECTACTIVE Position */
#define SCB_ICSR_VECTACTIVE_Msk            (0x1FFUL /*<< SCB_ICSR_VECTACTIVE_Pos*/)       /*!< SCB ICSR: VECTACTIVE Mask */

#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
/** \brief SCB Vector Table Offset Register Definitions */
#define SCB_VTOR_TBLOFF_Pos                 7U                                            /*!< SCB VTOR: TBLOFF Position */
#define SCB_VTOR_TBLOFF_Msk                (0x1FFFFFFUL << SCB_VTOR_TBLOFF_Pos)           /*!< SCB VTOR: TBLOFF Mask */
#endif

/** \brief SCB Application Interrupt and Reset Control Register Definitions */
#define SCB_AIRCR_VECTKEY_Pos              16U                                            /*!< SCB AIRCR: VECTKEY Position */
#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)            /*!< SCB AIRCR: VECTKEY Mask */

#define SCB_AIRCR_VECTKEYSTAT_Pos          16U                                            /*!< SCB AIRCR: VECTKEYSTAT Position */
#define SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)        /*!< SCB AIRCR: VECTKEYSTAT Mask */

#define SCB_AIRCR_ENDIANNESS_Pos           15U                                            /*!< SCB AIRCR: ENDIANNESS Position */
#define SCB_AIRCR_ENDIANNESS_Msk           (1UL << SCB_AIRCR_ENDIANNESS_Pos)              /*!< SCB AIRCR: ENDIANNESS Mask */

#define SCB_AIRCR_PRIS_Pos                 14U                                            /*!< SCB AIRCR: PRIS Position */
#define SCB_AIRCR_PRIS_Msk                 (1UL << SCB_AIRCR_PRIS_Pos)                    /*!< SCB AIRCR: PRIS Mask */

#define SCB_AIRCR_BFHFNMINS_Pos            13U                                            /*!< SCB AIRCR: BFHFNMINS Position */
#define SCB_AIRCR_BFHFNMINS_Msk            (1UL << SCB_AIRCR_BFHFNMINS_Pos)               /*!< SCB AIRCR: BFHFNMINS Mask */

#define SCB_AIRCR_SYSRESETREQS_Pos          3U                                            /*!< SCB AIRCR: SYSRESETREQS Position */
#define SCB_AIRCR_SYSRESETREQS_Msk         (1UL << SCB_AIRCR_SYSRESETREQS_Pos)            /*!< SCB AIRCR: SYSRESETREQS Mask */

#define SCB_AIRCR_SYSRESETREQ_Pos           2U                                            /*!< SCB AIRCR: SYSRESETREQ Position */
#define SCB_AIRCR_SYSRESETREQ_Msk          (1UL << SCB_AIRCR_SYSRESETREQ_Pos)             /*!< SCB AIRCR: SYSRESETREQ Mask */

#define SCB_AIRCR_VECTCLRACTIVE_Pos         1U                                            /*!< SCB AIRCR: VECTCLRACTIVE Position */
#define SCB_AIRCR_VECTCLRACTIVE_Msk        (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)           /*!< SCB AIRCR: VECTCLRACTIVE Mask */

/** \brief SCB System Control Register Definitions */
#define SCB_SCR_SEVONPEND_Pos               4U                                            /*!< SCB SCR: SEVONPEND Position */
#define SCB_SCR_SEVONPEND_Msk              (1UL << SCB_SCR_SEVONPEND_Pos)                 /*!< SCB SCR: SEVONPEND Mask */

#define SCB_SCR_SLEEPDEEPS_Pos              3U                                            /*!< SCB SCR: SLEEPDEEPS Position */
#define SCB_SCR_SLEEPDEEPS_Msk             (1UL << SCB_SCR_SLEEPDEEPS_Pos)                /*!< SCB SCR: SLEEPDEEPS Mask */

#define SCB_SCR_SLEEPDEEP_Pos               2U                                            /*!< SCB SCR: SLEEPDEEP Position */
#define SCB_SCR_SLEEPDEEP_Msk              (1UL << SCB_SCR_SLEEPDEEP_Pos)                 /*!< SCB SCR: SLEEPDEEP Mask */

#define SCB_SCR_SLEEPONEXIT_Pos             1U                                            /*!< SCB SCR: SLEEPONEXIT Position */
#define SCB_SCR_SLEEPONEXIT_Msk            (1UL << SCB_SCR_SLEEPONEXIT_Pos)               /*!< SCB SCR: SLEEPONEXIT Mask */

/** \brief SCB Configuration Control Register Definitions */
#define SCB_CCR_BP_Pos                     18U                                            /*!< SCB CCR: BP Position */
#define SCB_CCR_BP_Msk                     (1UL << SCB_CCR_BP_Pos)                        /*!< SCB CCR: BP Mask */

#define SCB_CCR_IC_Pos                     17U                                            /*!< SCB CCR: IC Position */
#define SCB_CCR_IC_Msk                     (1UL << SCB_CCR_IC_Pos)                        /*!< SCB CCR: IC Mask */

#define SCB_CCR_DC_Pos                     16U                                            /*!< SCB CCR: DC Position */
#define SCB_CCR_DC_Msk                     (1UL << SCB_CCR_DC_Pos)                        /*!< SCB CCR: DC Mask */

#define SCB_CCR_STKOFHFNMIGN_Pos           10U                                            /*!< SCB CCR: STKOFHFNMIGN Position */
#define SCB_CCR_STKOFHFNMIGN_Msk           (1UL << SCB_CCR_STKOFHFNMIGN_Pos)              /*!< SCB CCR: STKOFHFNMIGN Mask */

#define SCB_CCR_BFHFNMIGN_Pos               8U                                            /*!< SCB CCR: BFHFNMIGN Position */
#define SCB_CCR_BFHFNMIGN_Msk              (1UL << SCB_CCR_BFHFNMIGN_Pos)                 /*!< SCB CCR: BFHFNMIGN Mask */

#define SCB_CCR_DIV_0_TRP_Pos               4U                                            /*!< SCB CCR: DIV_0_TRP Position */
#define SCB_CCR_DIV_0_TRP_Msk              (1UL << SCB_CCR_DIV_0_TRP_Pos)                 /*!< SCB CCR: DIV_0_TRP Mask */

#define SCB_CCR_UNALIGN_TRP_Pos             3U                                            /*!< SCB CCR: UNALIGN_TRP Position */
#define SCB_CCR_UNALIGN_TRP_Msk            (1UL << SCB_CCR_UNALIGN_TRP_Pos)               /*!< SCB CCR: UNALIGN_TRP Mask */

#define SCB_CCR_USERSETMPEND_Pos            1U                                            /*!< SCB CCR: USERSETMPEND Position */
#define SCB_CCR_USERSETMPEND_Msk           (1UL << SCB_CCR_USERSETMPEND_Pos)              /*!< SCB CCR: USERSETMPEND Mask */

/** \brief SCB System Handler Control and State Register Definitions */
#define SCB_SHCSR_HARDFAULTPENDED_Pos      21U                                            /*!< SCB SHCSR: HARDFAULTPENDED Position */
#define SCB_SHCSR_HARDFAULTPENDED_Msk      (1UL << SCB_SHCSR_HARDFAULTPENDED_Pos)         /*!< SCB SHCSR: HARDFAULTPENDED Mask */

#define SCB_SHCSR_SVCALLPENDED_Pos         15U                                            /*!< SCB SHCSR: SVCALLPENDED Position */
#define SCB_SHCSR_SVCALLPENDED_Msk         (1UL << SCB_SHCSR_SVCALLPENDED_Pos)            /*!< SCB SHCSR: SVCALLPENDED Mask */

#define SCB_SHCSR_SYSTICKACT_Pos           11U                                            /*!< SCB SHCSR: SYSTICKACT Position */
#define SCB_SHCSR_SYSTICKACT_Msk           (1UL << SCB_SHCSR_SYSTICKACT_Pos)              /*!< SCB SHCSR: SYSTICKACT Mask */

#define SCB_SHCSR_PENDSVACT_Pos            10U                                            /*!< SCB SHCSR: PENDSVACT Position */
#define SCB_SHCSR_PENDSVACT_Msk            (1UL << SCB_SHCSR_PENDSVACT_Pos)               /*!< SCB SHCSR: PENDSVACT Mask */

#define SCB_SHCSR_SVCALLACT_Pos             7U                                            /*!< SCB SHCSR: SVCALLACT Position */
#define SCB_SHCSR_SVCALLACT_Msk            (1UL << SCB_SHCSR_SVCALLACT_Pos)               /*!< SCB SHCSR: SVCALLACT Mask */

#define SCB_SHCSR_NMIACT_Pos                5U                                            /*!< SCB SHCSR: NMIACT Position */
#define SCB_SHCSR_NMIACT_Msk               (1UL << SCB_SHCSR_NMIACT_Pos)                  /*!< SCB SHCSR: NMIACT Mask */

#define SCB_SHCSR_HARDFAULTACT_Pos          2U                                            /*!< SCB SHCSR: HARDFAULTACT Position */
#define SCB_SHCSR_HARDFAULTACT_Msk         (1UL << SCB_SHCSR_HARDFAULTACT_Pos)            /*!< SCB SHCSR: HARDFAULTACT Mask */

/*@} end of group CMSIS_SCB */


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_SysTick     System Tick Timer (SysTick)
  \brief    Type definitions for the System Timer Registers.
  @{
 */

/**
  \brief  Structure type to access the System Timer (SysTick).
 */
typedef struct
{
  __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  __IOM uint32_t LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  __IOM uint32_t VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  __IM  uint32_t CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;

/** \brief SysTick Control / Status Register Definitions */
#define SysTick_CTRL_COUNTFLAG_Pos         16U                                            /*!< SysTick CTRL: COUNTFLAG Position */
#define SysTick_CTRL_COUNTFLAG_Msk         (1UL << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG Mask */

#define SysTick_CTRL_CLKSOURCE_Pos          2U                                            /*!< SysTick CTRL: CLKSOURCE Position */
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE Mask */

#define SysTick_CTRL_TICKINT_Pos            1U                                            /*!< SysTick CTRL: TICKINT Position */
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */

#define SysTick_CTRL_ENABLE_Pos             0U                                            /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL /*<< SysTick_CTRL_ENABLE_Pos*/)           /*!< SysTick CTRL: ENABLE Mask */

/** \brief SysTick Reload Register Definitions */
#define SysTick_LOAD_RELOAD_Pos             0U                                            /*!< SysTick LOAD: RELOAD Position */
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFUL /*<< SysTick_LOAD_RELOAD_Pos*/)    /*!< SysTick LOAD: RELOAD Mask */

/** \brief SysTick Current Register Definitions */
#define SysTick_VAL_CURRENT_Pos             0U                                            /*!< SysTick VAL: CURRENT Position */
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFUL /*<< SysTick_VAL_CURRENT_Pos*/)    /*!< SysTick VAL: CURRENT Mask */

/** \brief SysTick Calibration Register Definitions */
#define SysTick_CALIB_NOREF_Pos            31U                                            /*!< SysTick CALIB: NOREF Position */
#define SysTick_CALIB_NOREF_Msk            (1UL << SysTick_CALIB_NOREF_Pos)               /*!< SysTick CALIB: NOREF Mask */

#define SysTick_CALIB_SKEW_Pos             30U                                            /*!< SysTick CALIB: SKEW Position */
#define SysTick_CALIB_SKEW_Msk             (1UL << SysTick_CALIB_SKEW_Pos)                /*!< SysTick CALIB: SKEW Mask */

#define SysTick_CALIB_TENMS_Pos             0U                                            /*!< SysTick CALIB: TENMS Position */
#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFUL /*<< SysTick_CALIB_TENMS_Pos*/)    /*!< SysTick CALIB: TENMS Mask */

/*@} end of group CMSIS_SysTick */


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_DWT     Data Watchpoint and Trace (DWT)
  \brief    Type definitions for the Data Watchpoint and Trace (DWT)
  @{
 */

/**
  \brief  Structure type to access the Data Watchpoint and Trace Register (DWT).
 */
typedef struct
{
  __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  Control Register */
  __IOM uint32_t CYCCNT;                 /*!< Offset: 0x004 (R/W)  Cycle Count Register */
  __IOM uint32_t CPICNT;                 /*!< Offset: 0x008 (R/W)  CPI Count Register */
  __IOM uint32_t EXCCNT;                 /*!< Offset: 0x00C (R/W)  Exception Overhead Count Register */
  __IOM uint32_t SLEEPCNT;               /*!< Offset: 0x010 (R/W)  Sleep Count Register */
  __IOM uint32_t LSUCNT;                 /*!< Offset: 0x014 (R/W)  LSU Count Register */
  __IOM uint32_t FOLDCNT;                /*!< Offset: 0x018 (R/W)  Folded-instruction Count Register */
  __IM  uint32_t PCSR;                   /*!< Offset: 0x01C (R/ )  Program Counter Sample Register */
  __IOM uint32_t COMP0;                  /*!< Offset: 0x020 (R/W)  Comparator Register 0 */
        uint32_t RESERVED1[1U];
  __IOM uint32_t FUNCTION0;              /*!< Offset: 0x028 (R/W)  Function Register 0 */
        uint32_t RESERVED2[1U];
  __IOM uint32_t COMP1;                  /*!< Offset: 0x030 (R/W)  Comparator Register 1 */
        uint32_t RESERVED3[1U];
  __IOM uint32_t FUNCTION1;              /*!< Offset: 0x038 (R/W)  Function Register 1 */
        uint32_t RESERVED14[992U];
  __IM  uint32_t DEVARCH;                /*!< Offset: 0xFBC (R/ )  Device Type Architecture Register */
} DWT_Type;

/** \brief DWT Control Register Definitions */
#define DWT_CTRL_NUMCOMP_Pos               28U                                         /*!< DWT CTRL: NUMCOMP Position */
#define DWT_CTRL_NUMCOMP_Msk               (0xFUL << DWT_CTRL_NUMCOMP_Pos)             /*!< DWT CTRL: NUMCOMP Mask */

#define DWT_CTRL_NOTRCPKT_Pos              27U                                         /*!< DWT CTRL: NOTRCPKT Position */
#define DWT_CTRL_NOTRCPKT_Msk              (1UL << DWT_CTRL_NOTRCPKT_Pos)              /*!< DWT CTRL: NOTRCPKT Mask */

#define DWT_CTRL_NOEXTTRIG_Pos             26U                                         /*!< DWT CTRL: NOEXTTRIG Position */
#define DWT_CTRL_NOEXTTRIG_Msk             (1UL << DWT_CTRL_NOEXTTRIG_Pos)             /*!< DWT CTRL: NOEXTTRIG Mask */

#define DWT_CTRL_NOCYCCNT_Pos              25U                                         /*!< DWT CTRL: NOCYCCNT Position */
#define DWT_CTRL_NOCYCCNT_Msk              (1UL << DWT_CTRL_NOCYCCNT_Pos)              /*!< DWT CTRL: NOCYCCNT Mask */

#define DWT_CTRL_NOPRFCNT_Pos              24U                                         /*!< DWT CTRL: NOPRFCNT Position */
#define DWT_CTRL_NOPRFCNT_Msk              (1UL << DWT_CTRL_NOPRFCNT_Pos)              /*!< DWT CTRL: NOPRFCNT Mask */

/** \brief DWT Comparator Function Register Definitions */
#define DWT_FUNCTION_ID_Pos                27U                                         /*!< DWT FUNCTION: ID Position */
#define DWT_FUNCTION_ID_Msk                (0x1FUL << DWT_FUNCTION_ID_Pos)             /*!< DWT FUNCTION: ID Mask */

#define DWT_FUNCTION_MATCHED_Pos           24U                                         /*!< DWT FUNCTION: MATCHED Position */
#define DWT_FUNCTION_MATCHED_Msk           (1UL << DWT_FUNCTION_MATCHED_Pos)           /*!< DWT FUNCTION: MATCHED Mask */

#define DWT_FUNCTION_DATAVSIZE_Pos         10U                                         /*!< DWT FUNCTION: DATAVSIZE Position */
#define DWT_FUNCTION_DATAVSIZE_Msk         (0x3UL << DWT_FUNCTION_DATAVSIZE_Pos)       /*!< DWT FUNCTION: DATAVSIZE Mask */

#define DWT_FUNCTION_ACTION_Pos             4U                                         /*!< DWT FUNCTION: ACTION Position */
#define DWT_FUNCTION_ACTION_Msk            (0x3UL << DWT_FUNCTION_ACTION_Pos)          /*!< DWT FUNCTION: ACTION Mask */

#define DWT_FUNCTION_MATCH_Pos              0U                                         /*!< DWT FUNCTION: MATCH Position */
#define DWT_FUNCTION_MATCH_Msk             (0xFUL /*<< DWT_FUNCTION_MATCH_Pos*/)       /*!< DWT FUNCTION: MATCH Mask */

/*@}*/ /* end of group CMSIS_DWT */


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_TPIU     Trace Port Interface Unit (TPIU)
  \brief    Type definitions for the Trace Port Interface Unit (TPIU)
  @{
 */

/**
  \brief  Structure type to access the Trace Port Interface Unit Register (TPIU).
 */
typedef struct
{
  __IM  uint32_t SSPSR;                  /*!< Offset: 0x000 (R/ )  Supported Parallel Port Size Register */
  __IOM uint32_t CSPSR;                  /*!< Offset: 0x004 (R/W)  Current Parallel Port Size Register */
        uint32_t RESERVED0[2U];
  __IOM uint32_t ACPR;                   /*!< Offset: 0x010 (R/W)  Asynchronous Clock Prescaler Register */
        uint32_t RESERVED1[55U];
  __IOM uint32_t SPPR;                   /*!< Offset: 0x0F0 (R/W)  Selected Pin Protocol Register */
        uint32_t RESERVED2[131U];
  __IM  uint32_t FFSR;                   /*!< Offset: 0x300 (R/ )  Formatter and Flush Status Register */
  __IOM uint32_t FFCR;                   /*!< Offset: 0x304 (R/W)  Formatter and Flush Control Register */
  __IOM uint32_t PSCR;                   /*!< Offset: 0x308 (R/W)  Periodic Synchronization Control Register */
        uint32_t RESERVED3[759U];
  __IM  uint32_t TRIGGER;                /*!< Offset: 0xEE8 (R/ )  TRIGGER Register */
  __IM  uint32_t ITFTTD0;                /*!< Offset: 0xEEC (R/ )  Integration Test FIFO Test Data 0 Register */
  __IOM uint32_t ITATBCTR2;              /*!< Offset: 0xEF0 (R/W)  Integration Test ATB Control Register 2 */
        uint32_t RESERVED4[1U];
  __IM  uint32_t ITATBCTR0;              /*!< Offset: 0xEF8 (R/ )  Integration Test ATB Control Register 0 */
  __IM  uint32_t ITFTTD1;                /*!< Offset: 0xEFC (R/ )  Integration Test FIFO Test Data 1 Register */
  __IOM uint32_t ITCTRL;                 /*!< Offset: 0xF00 (R/W)  Integration Mode Control */
        uint32_t RESERVED5[39U];
  __IOM uint32_t CLAIMSET;               /*!< Offset: 0xFA0 (R/W)  Claim tag set */
  __IOM uint32_t CLAIMCLR;               /*!< Offset: 0xFA4 (R/W)  Claim tag clear */
        uint32_t RESERVED7[8U];
  __IM  uint32_t DEVID;                  /*!< Offset: 0xFC8 (R/ )  Device Configuration Register */
  __IM  uint32_t DEVTYPE;                /*!< Offset: 0xFCC (R/ )  Device Type Identifier Register */
} TPIU_Type;

/** \brief TPIU Asynchronous Clock Prescaler Register Definitions */
#define TPIU_ACPR_PRESCALER_Pos             0U                                         /*!< TPIU ACPR: PRESCALER Position */
#define TPIU_ACPR_PRESCALER_Msk            (0x1FFFUL /*<< TPIU_ACPR_PRESCALER_Pos*/)   /*!< TPIU ACPR: PRESCALER Mask */

/** \brief TPIU Selected Pin Protocol Register Definitions */
#define TPIU_SPPR_TXMODE_Pos                0U                                         /*!< TPIU SPPR: TXMODE Position */
#define TPIU_SPPR_TXMODE_Msk               (0x3UL /*<< TPIU_SPPR_TXMODE_Pos*/)         /*!< TPIU SPPR: TXMODE Mask */

/** \brief TPIU Formatter and Flush Status Register Definitions */
#define TPIU_FFSR_FtNonStop_Pos             3U                                         /*!< TPIU FFSR: FtNonStop Position */
#define TPIU_FFSR_FtNonStop_Msk            (1UL << TPIU_FFSR_FtNonStop_Pos)            /*!< TPIU FFSR: FtNonStop Mask */

#define TPIU_FFSR_TCPresent_Pos             2U                                         /*!< TPIU FFSR: TCPresent Position */
#define TPIU_FFSR_TCPresent_Msk            (1UL << TPIU_FFSR_TCPresent_Pos)            /*!< TPIU FFSR: TCPresent Mask */

#define TPIU_FFSR_FtStopped_Pos             1U                                         /*!< TPIU FFSR: FtStopped Position */
#define TPIU_FFSR_FtStopped_Msk            (1UL << TPIU_FFSR_FtStopped_Pos)            /*!< TPIU FFSR: FtStopped Mask */

#define TPIU_FFSR_FlInProg_Pos              0U                                         /*!< TPIU FFSR: FlInProg Position */
#define TPIU_FFSR_FlInProg_Msk             (1UL /*<< TPIU_FFSR_FlInProg_Pos*/)         /*!< TPIU FFSR: FlInProg Mask */

/** \brief TPIU Formatter and Flush Control Register Definitions */
#define TPIU_FFCR_TrigIn_Pos                8U                                         /*!< TPIU FFCR: TrigIn Position */
#define TPIU_FFCR_TrigIn_Msk               (1UL << TPIU_FFCR_TrigIn_Pos)               /*!< TPIU FFCR: TrigIn Mask */

#define TPIU_FFCR_FOnMan_Pos                6U                                         /*!< TPIU FFCR: FOnMan Position */
#define TPIU_FFCR_FOnMan_Msk               (1UL << TPIU_FFCR_FOnMan_Pos)               /*!< TPIU FFCR: FOnMan Mask */

#define TPIU_FFCR_EnFCont_Pos               1U                                         /*!< TPIU FFCR: EnFCont Position */
#define TPIU_FFCR_EnFCont_Msk              (1UL << TPIU_FFCR_EnFCont_Pos)              /*!< TPIU FFCR: EnFCont Mask */

/** \brief TPIU Periodic Synchronization Control Register Definitions */
#define TPIU_PSCR_PSCount_Pos               0U                                         /*!< TPIU PSCR: PSCount Position */
#define TPIU_PSCR_PSCount_Msk              (0x1FUL /*<< TPIU_PSCR_PSCount_Pos*/)       /*!< TPIU PSCR: TPSCount Mask */

/** \brief TPIU TRIGGER Register Definitions */
#define TPIU_TRIGGER_TRIGGER_Pos            0U                                         /*!< TPIU TRIGGER: TRIGGER Position */
#define TPIU_TRIGGER_TRIGGER_Msk           (1UL /*<< TPIU_TRIGGER_TRIGGER_Pos*/)       /*!< TPIU TRIGGER: TRIGGER Mask */

/** \brief TPIU Integration Test FIFO Test Data 0 Register Definitions */
#define TPIU_ITFTTD0_ATB_IF2_ATVALID_Pos   29U                                         /*!< TPIU ITFTTD0: ATB Interface 2 ATVALIDPosition */
#define TPIU_ITFTTD0_ATB_IF2_ATVALID_Msk   (0x3UL << TPIU_ITFTTD0_ATB_IF2_ATVALID_Pos) /*!< TPIU ITFTTD0: ATB Interface 2 ATVALID Mask */

#define TPIU_ITFTTD0_ATB_IF2_bytecount_Pos 27U                                         /*!< TPIU ITFTTD0: ATB Interface 2 byte count Position */
#define TPIU_ITFTTD0_ATB_IF2_bytecount_Msk (0x3UL << TPIU_ITFTTD0_ATB_IF2_bytecount_Pos) /*!< TPIU ITFTTD0: ATB Interface 2 byte count Mask */

#define TPIU_ITFTTD0_ATB_IF1_ATVALID_Pos   26U                                         /*!< TPIU ITFTTD0: ATB Interface 1 ATVALID Position */
#define TPIU_ITFTTD0_ATB_IF1_ATVALID_Msk   (0x3UL << TPIU_ITFTTD0_ATB_IF1_ATVALID_Pos) /*!< TPIU ITFTTD0: ATB Interface 1 ATVALID Mask */

#define TPIU_ITFTTD0_ATB_IF1_bytecount_Pos 24U                                         /*!< TPIU ITFTTD0: ATB Interface 1 byte count Position */
#define TPIU_ITFTTD0_ATB_IF1_bytecount_Msk (0x3UL << TPIU_ITFTTD0_ATB_IF1_bytecount_Pos) /*!< TPIU ITFTTD0: ATB Interface 1 byte countt Mask */

#define TPIU_ITFTTD0_ATB_IF1_data2_Pos     16U                                         /*!< TPIU ITFTTD0: ATB Interface 1 data2 Position */
#define TPIU_ITFTTD0_ATB_IF1_data2_Msk     (0xFFUL << TPIU_ITFTTD0_ATB_IF1_data1_Pos)  /*!< TPIU ITFTTD0: ATB Interface 1 data2 Mask */

#define TPIU_ITFTTD0_ATB_IF1_data1_Pos      8U                                         /*!< TPIU ITFTTD0: ATB Interface 1 data1 Position */
#define TPIU_ITFTTD0_ATB_IF1_data1_Msk     (0xFFUL << TPIU_ITFTTD0_ATB_IF1_data1_Pos)  /*!< TPIU ITFTTD0: ATB Interface 1 data1 Mask */

#define TPIU_ITFTTD0_ATB_IF1_data0_Pos      0U                                         /*!< TPIU ITFTTD0: ATB Interface 1 data0 Position */
#define TPIU_ITFTTD0_ATB_IF1_data0_Msk     (0xFFUL /*<< TPIU_ITFTTD0_ATB_IF1_data0_Pos*/) /*!< TPIU ITFTTD0: ATB Interface 1 data0 Mask */

/** \brief TPIU Integration Test ATB Control Register 2 Register Definitions */
#define TPIU_ITATBCTR2_AFVALID2S_Pos        1U                                         /*!< TPIU ITATBCTR2: AFVALID2S Position */
#define TPIU_ITATBCTR2_AFVALID2S_Msk       (1UL << TPIU_ITATBCTR2_AFVALID2S_Pos)       /*!< TPIU ITATBCTR2: AFVALID2SS Mask */

#define TPIU_ITATBCTR2_AFVALID1S_Pos        1U                                         /*!< TPIU ITATBCTR2: AFVALID1S Position */
#define TPIU_ITATBCTR2_AFVALID1S_Msk       (1UL << TPIU_ITATBCTR2_AFVALID1S_Pos)       /*!< TPIU ITATBCTR2: AFVALID1SS Mask */

#define TPIU_ITATBCTR2_ATREADY2S_Pos        0U                                         /*!< TPIU ITATBCTR2: ATREADY2S Position */
#define TPIU_ITATBCTR2_ATREADY2S_Msk       (1UL /*<< TPIU_ITATBCTR2_ATREADY2S_Pos*/)   /*!< TPIU ITATBCTR2: ATREADY2S Mask */

#define TPIU_ITATBCTR2_ATREADY1S_Pos        0U                                         /*!< TPIU ITATBCTR2: ATREADY1S Position */
#define TPIU_ITATBCTR2_ATREADY1S_Msk       (1UL /*<< TPIU_ITATBCTR2_ATREADY1S_Pos*/)   /*!< TPIU ITATBCTR2: ATREADY1S Mask */

/** \brief TPIU Integration Test FIFO Test Data 1 Register Definitions */
#define TPIU_ITFTTD1_ATB_IF2_ATVALID_Pos   29U                                         /*!< TPIU ITFTTD1: ATB Interface 2 ATVALID Position */
#define TPIU_ITFTTD1_ATB_IF2_ATVALID_Msk   (0x3UL << TPIU_ITFTTD1_ATB_IF2_ATVALID_Pos) /*!< TPIU ITFTTD1: ATB Interface 2 ATVALID Mask */

#define TPIU_ITFTTD1_ATB_IF2_bytecount_Pos 27U                                         /*!< TPIU ITFTTD1: ATB Interface 2 byte count Position */
#define TPIU_ITFTTD1_ATB_IF2_bytecount_Msk (0x3UL << TPIU_ITFTTD1_ATB_IF2_bytecount_Pos) /*!< TPIU ITFTTD1: ATB Interface 2 byte count Mask */

#define TPIU_ITFTTD1_ATB_IF1_ATVALID_Pos   26U                                         /*!< TPIU ITFTTD1: ATB Interface 1 ATVALID Position */
#define TPIU_ITFTTD1_ATB_IF1_ATVALID_Msk   (0x3UL << TPIU_ITFTTD1_ATB_IF1_ATVALID_Pos) /*!< TPIU ITFTTD1: ATB Interface 1 ATVALID Mask */

#define TPIU_ITFTTD1_ATB_IF1_bytecount_Pos 24U                                         /*!< TPIU ITFTTD1: ATB Interface 1 byte count Position */
#define TPIU_ITFTTD1_ATB_IF1_bytecount_Msk (0x3UL << TPIU_ITFTTD1_ATB_IF1_bytecount_Pos) /*!< TPIU ITFTTD1: ATB Interface 1 byte countt Mask */

#define TPIU_ITFTTD1_ATB_IF2_data2_Pos     16U                                         /*!< TPIU ITFTTD1: ATB Interface 2 data2 Position */
#define TPIU_ITFTTD1_ATB_IF2_data2_Msk     (0xFFUL << TPIU_ITFTTD1_ATB_IF2_data1_Pos)  /*!< TPIU ITFTTD1: ATB Interface 2 data2 Mask */

#define TPIU_ITFTTD1_ATB_IF2_data1_Pos      8U                                         /*!< TPIU ITFTTD1: ATB Interface 2 data1 Position */
#define TPIU_ITFTTD1_ATB_IF2_data1_Msk     (0xFFUL << TPIU_ITFTTD1_ATB_IF2_data1_Pos)  /*!< TPIU ITFTTD1: ATB Interface 2 data1 Mask */

#define TPIU_ITFTTD1_ATB_IF2_data0_Pos      0U                                         /*!< TPIU ITFTTD1: ATB Interface 2 data0 Position */
#define TPIU_ITFTTD1_ATB_IF2_data0_Msk     (0xFFUL /*<< TPIU_ITFTTD1_ATB_IF2_data0_Pos*/) /*!< TPIU ITFTTD1: ATB Interface 2 data0 Mask */

/** \brief TPIU Integration Test ATB Control Register 0 Definitions */
#define TPIU_ITATBCTR0_AFVALID2S_Pos        1U                                         /*!< TPIU ITATBCTR0: AFVALID2S Position */
#define TPIU_ITATBCTR0_AFVALID2S_Msk       (1UL << TPIU_ITATBCTR0_AFVALID2S_Pos)       /*!< TPIU ITATBCTR0: AFVALID2SS Mask */

#define TPIU_ITATBCTR0_AFVALID1S_Pos        1U                                         /*!< TPIU ITATBCTR0: AFVALID1S Position */
#define TPIU_ITATBCTR0_AFVALID1S_Msk       (1UL << TPIU_ITATBCTR0_AFVALID1S_Pos)       /*!< TPIU ITATBCTR0: AFVALID1SS Mask */

#define TPIU_ITATBCTR0_ATREADY2S_Pos        0U                                         /*!< TPIU ITATBCTR0: ATREADY2S Position */
#define TPIU_ITATBCTR0_ATREADY2S_Msk       (1UL /*<< TPIU_ITATBCTR0_ATREADY2S_Pos*/)   /*!< TPIU ITATBCTR0: ATREADY2S Mask */

#define TPIU_ITATBCTR0_ATREADY1S_Pos        0U                                         /*!< TPIU ITATBCTR0: ATREADY1S Position */
#define TPIU_ITATBCTR0_ATREADY1S_Msk       (1UL /*<< TPIU_ITATBCTR0_ATREADY1S_Pos*/)   /*!< TPIU ITATBCTR0: ATREADY1S Mask */

/** \brief TPIU Integration Mode Control Register Definitions */
#define TPIU_ITCTRL_Mode_Pos                0U                                         /*!< TPIU ITCTRL: Mode Position */
#define TPIU_ITCTRL_Mode_Msk               (0x3UL /*<< TPIU_ITCTRL_Mode_Pos*/)         /*!< TPIU ITCTRL: Mode Mask */

/** \brief TPIU DEVID Register Definitions */
#define TPIU_DEVID_NRZVALID_Pos            11U                                         /*!< TPIU DEVID: NRZVALID Position */
#define TPIU_DEVID_NRZVALID_Msk            (1UL << TPIU_DEVID_NRZVALID_Pos)            /*!< TPIU DEVID: NRZVALID Mask */

#define TPIU_DEVID_MANCVALID_Pos           10U                                         /*!< TPIU DEVID: MANCVALID Position */
#define TPIU_DEVID_MANCVALID_Msk           (1UL << TPIU_DEVID_MANCVALID_Pos)           /*!< TPIU DEVID: MANCVALID Mask */

#define TPIU_DEVID_PTINVALID_Pos            9U                                         /*!< TPIU DEVID: PTINVALID Position */
#define TPIU_DEVID_PTINVALID_Msk           (1UL << TPIU_DEVID_PTINVALID_Pos)           /*!< TPIU DEVID: PTINVALID Mask */

#define TPIU_DEVID_FIFOSZ_Pos               6U                                         /*!< TPIU DEVID: FIFOSZ Position */
#define TPIU_DEVID_FIFOSZ_Msk              (0x7UL << TPIU_DEVID_FIFOSZ_Pos)            /*!< TPIU DEVID: FIFOSZ Mask */

#define TPIU_DEVID_NrTraceInput_Pos         0U                                         /*!< TPIU DEVID: NrTraceInput Position */
#define TPIU_DEVID_NrTraceInput_Msk        (0x3FUL /*<< TPIU_DEVID_NrTraceInput_Pos*/) /*!< TPIU DEVID: NrTraceInput Mask */

/** \brief TPIU DEVTYPE Register Definitions */
#define TPIU_DEVTYPE_SubType_Pos            4U                                         /*!< TPIU DEVTYPE: SubType Position */
#define TPIU_DEVTYPE_SubType_Msk           (0xFUL /*<< TPIU_DEVTYPE_SubType_Pos*/)     /*!< TPIU DEVTYPE: SubType Mask */

#define TPIU_DEVTYPE_MajorType_Pos          0U                                         /*!< TPIU DEVTYPE: MajorType Position */
#define TPIU_DEVTYPE_MajorType_Msk         (0xFUL << TPIU_DEVTYPE_MajorType_Pos)       /*!< TPIU DEVTYPE: MajorType Mask */

/*@}*/ /* end of group CMSIS_TPIU */


#if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U)
/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_MPU     Memory Protection Unit (MPU)
  \brief    Type definitions for the Memory Protection Unit (MPU)
  @{
 */

/**
  \brief  Structure type to access the Memory Protection Unit (MPU).
 */
typedef struct
{
  __IM  uint32_t TYPE;                   /*!< Offset: 0x000 (R/ )  MPU Type Register */
  __IOM uint32_t CTRL;                   /*!< Offset: 0x004 (R/W)  MPU Control Register */
  __IOM uint32_t RNR;                    /*!< Offset: 0x008 (R/W)  MPU Region Number Register */
  __IOM uint32_t RBAR;                   /*!< Offset: 0x00C (R/W)  MPU Region Base Address Register */
  __IOM uint32_t RLAR;                   /*!< Offset: 0x010 (R/W)  MPU Region Limit Address Register */
        uint32_t RESERVED0[7U];
  union {
  __IOM uint32_t MAIR[2];
  struct {
  __IOM uint32_t MAIR0;                  /*!< Offset: 0x030 (R/W)  MPU Memory Attribute Indirection Register 0 */
  __IOM uint32_t MAIR1;                  /*!< Offset: 0x034 (R/W)  MPU Memory Attribute Indirection Register 1 */
  };
  };
} MPU_Type;

#define MPU_TYPE_RALIASES                  1U

/** \brief MPU Type Register Definitions */
#define MPU_TYPE_IREGION_Pos               16U                                            /*!< MPU TYPE: IREGION Position */
#define MPU_TYPE_IREGION_Msk               (0xFFUL << MPU_TYPE_IREGION_Pos)               /*!< MPU TYPE: IREGION Mask */

#define MPU_TYPE_DREGION_Pos                8U                                            /*!< MPU TYPE: DREGION Position */
#define MPU_TYPE_DREGION_Msk               (0xFFUL << MPU_TYPE_DREGION_Pos)               /*!< MPU TYPE: DREGION Mask */

#define MPU_TYPE_SEPARATE_Pos               0U                                            /*!< MPU TYPE: SEPARATE Position */
#define MPU_TYPE_SEPARATE_Msk              (1UL /*<< MPU_TYPE_SEPARATE_Pos*/)             /*!< MPU TYPE: SEPARATE Mask */

/** \brief MPU Control Register Definitions */
#define MPU_CTRL_PRIVDEFENA_Pos             2U                                            /*!< MPU CTRL: PRIVDEFENA Position */
#define MPU_CTRL_PRIVDEFENA_Msk            (1UL << MPU_CTRL_PRIVDEFENA_Pos)               /*!< MPU CTRL: PRIVDEFENA Mask */

#define MPU_CTRL_HFNMIENA_Pos               1U                                            /*!< MPU CTRL: HFNMIENA Position */
#define MPU_CTRL_HFNMIENA_Msk              (1UL << MPU_CTRL_HFNMIENA_Pos)                 /*!< MPU CTRL: HFNMIENA Mask */

#define MPU_CTRL_ENABLE_Pos                 0U                                            /*!< MPU CTRL: ENABLE Position */
#define MPU_CTRL_ENABLE_Msk                (1UL /*<< MPU_CTRL_ENABLE_Pos*/)               /*!< MPU CTRL: ENABLE Mask */

/** \brief MPU Region Number Register Definitions */
#define MPU_RNR_REGION_Pos                  0U                                            /*!< MPU RNR: REGION Position */
#define MPU_RNR_REGION_Msk                 (0xFFUL /*<< MPU_RNR_REGION_Pos*/)             /*!< MPU RNR: REGION Mask */

/** \brief MPU Region Base Address Register Definitions */
#define MPU_RBAR_BASE_Pos                   5U                                            /*!< MPU RBAR: BASE Position */
#define MPU_RBAR_BASE_Msk                  (0x7FFFFFFUL << MPU_RBAR_BASE_Pos)             /*!< MPU RBAR: BASE Mask */

#define MPU_RBAR_SH_Pos                     3U                                            /*!< MPU RBAR: SH Position */
#define MPU_RBAR_SH_Msk                    (0x3UL << MPU_RBAR_SH_Pos)                     /*!< MPU RBAR: SH Mask */

#define MPU_RBAR_AP_Pos                     1U                                            /*!< MPU RBAR: AP Position */
#define MPU_RBAR_AP_Msk                    (0x3UL << MPU_RBAR_AP_Pos)                     /*!< MPU RBAR: AP Mask */

#define MPU_RBAR_XN_Pos                     0U                                            /*!< MPU RBAR: XN Position */
#define MPU_RBAR_XN_Msk                    (01UL /*<< MPU_RBAR_XN_Pos*/)                  /*!< MPU RBAR: XN Mask */

/** \brief MPU Region Limit Address Register Definitions */
#define MPU_RLAR_LIMIT_Pos                  5U                                            /*!< MPU RLAR: LIMIT Position */
#define MPU_RLAR_LIMIT_Msk                 (0x7FFFFFFUL << MPU_RLAR_LIMIT_Pos)            /*!< MPU RLAR: LIMIT Mask */

#define MPU_RLAR_AttrIndx_Pos               1U                                            /*!< MPU RLAR: AttrIndx Position */
#define MPU_RLAR_AttrIndx_Msk              (0x7UL << MPU_RLAR_AttrIndx_Pos)               /*!< MPU RLAR: AttrIndx Mask */

#define MPU_RLAR_EN_Pos                     0U                                            /*!< MPU RLAR: Region enable bit Position */
#define MPU_RLAR_EN_Msk                    (1UL /*<< MPU_RLAR_EN_Pos*/)                   /*!< MPU RLAR: Region enable bit Mask */

/** \brief MPU Memory Attribute Indirection Register 0 Definitions */
#define MPU_MAIR0_Attr3_Pos                24U                                            /*!< MPU MAIR0: Attr3 Position */
#define MPU_MAIR0_Attr3_Msk                (0xFFUL << MPU_MAIR0_Attr3_Pos)                /*!< MPU MAIR0: Attr3 Mask */

#define MPU_MAIR0_Attr2_Pos                16U                                            /*!< MPU MAIR0: Attr2 Position */
#define MPU_MAIR0_Attr2_Msk                (0xFFUL << MPU_MAIR0_Attr2_Pos)                /*!< MPU MAIR0: Attr2 Mask */

#define MPU_MAIR0_Attr1_Pos                 8U                                            /*!< MPU MAIR0: Attr1 Position */
#define MPU_MAIR0_Attr1_Msk                (0xFFUL << MPU_MAIR0_Attr1_Pos)                /*!< MPU MAIR0: Attr1 Mask */

#define MPU_MAIR0_Attr0_Pos                 0U                                            /*!< MPU MAIR0: Attr0 Position */
#define MPU_MAIR0_Attr0_Msk                (0xFFUL /*<< MPU_MAIR0_Attr0_Pos*/)            /*!< MPU MAIR0: Attr0 Mask */

/** \brief MPU Memory Attribute Indirection Register 1 Definitions */
#define MPU_MAIR1_Attr7_Pos                24U                                            /*!< MPU MAIR1: Attr7 Position */
#define MPU_MAIR1_Attr7_Msk                (0xFFUL << MPU_MAIR1_Attr7_Pos)                /*!< MPU MAIR1: Attr7 Mask */

#define MPU_MAIR1_Attr6_Pos                16U                                            /*!< MPU MAIR1: Attr6 Position */
#define MPU_MAIR1_Attr6_Msk                (0xFFUL << MPU_MAIR1_Attr6_Pos)                /*!< MPU MAIR1: Attr6 Mask */

#define MPU_MAIR1_Attr5_Pos                 8U                                            /*!< MPU MAIR1: Attr5 Position */
#define MPU_MAIR1_Attr5_Msk                (0xFFUL << MPU_MAIR1_Attr5_Pos)                /*!< MPU MAIR1: Attr5 Mask */

#define MPU_MAIR1_Attr4_Pos                 0U                                            /*!< MPU MAIR1: Attr4 Position */
#define MPU_MAIR1_Attr4_Msk                (0xFFUL /*<< MPU_MAIR1_Attr4_Pos*/)            /*!< MPU MAIR1: Attr4 Mask */

/*@} end of group CMSIS_MPU */
#endif


#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_SAU     Security Attribution Unit (SAU)
  \brief    Type definitions for the Security Attribution Unit (SAU)
  @{
 */

/**
  \brief  Structure type to access the Security Attribution Unit (SAU).
 */
typedef struct
{
  __IOM uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  SAU Control Register */
  __IM  uint32_t TYPE;                   /*!< Offset: 0x004 (R/ )  SAU Type Register */
#if defined (__SAUREGION_PRESENT) && (__SAUREGION_PRESENT == 1U)
  __IOM uint32_t RNR;                    /*!< Offset: 0x008 (R/W)  SAU Region Number Register */
  __IOM uint32_t RBAR;                   /*!< Offset: 0x00C (R/W)  SAU Region Base Address Register */
  __IOM uint32_t RLAR;                   /*!< Offset: 0x010 (R/W)  SAU Region Limit Address Register */
#endif
} SAU_Type;

/** \brief SAU Control Register Definitions */
#define SAU_CTRL_ALLNS_Pos                  1U                                            /*!< SAU CTRL: ALLNS Position */
#define SAU_CTRL_ALLNS_Msk                 (1UL << SAU_CTRL_ALLNS_Pos)                    /*!< SAU CTRL: ALLNS Mask */

#define SAU_CTRL_ENABLE_Pos                 0U                                            /*!< SAU CTRL: ENABLE Position */
#define SAU_CTRL_ENABLE_Msk                (1UL /*<< SAU_CTRL_ENABLE_Pos*/)               /*!< SAU CTRL: ENABLE Mask */

/** \brief SAU Type Register Definitions */
#define SAU_TYPE_SREGION_Pos                0U                                            /*!< SAU TYPE: SREGION Position */
#define SAU_TYPE_SREGION_Msk               (0xFFUL /*<< SAU_TYPE_SREGION_Pos*/)           /*!< SAU TYPE: SREGION Mask */

#if defined (__SAUREGION_PRESENT) && (__SAUREGION_PRESENT == 1U)
/** \brief SAU Region Number Register Definitions */
#define SAU_RNR_REGION_Pos                  0U                                            /*!< SAU RNR: REGION Position */
#define SAU_RNR_REGION_Msk                 (0xFFUL /*<< SAU_RNR_REGION_Pos*/)             /*!< SAU RNR: REGION Mask */

/** \brief SAU Region Base Address Register Definitions */
#define SAU_RBAR_BADDR_Pos                  5U                                            /*!< SAU RBAR: BADDR Position */
#define SAU_RBAR_BADDR_Msk                 (0x7FFFFFFUL << SAU_RBAR_BADDR_Pos)            /*!< SAU RBAR: BADDR Mask */

/** \brief SAU Region Limit Address Register Definitions */
#define SAU_RLAR_LADDR_Pos                  5U                                            /*!< SAU RLAR: LADDR Position */
#define SAU_RLAR_LADDR_Msk                 (0x7FFFFFFUL << SAU_RLAR_LADDR_Pos)            /*!< SAU RLAR: LADDR Mask */

#define SAU_RLAR_NSC_Pos                    1U                                            /*!< SAU RLAR: NSC Position */
#define SAU_RLAR_NSC_Msk                   (1UL << SAU_RLAR_NSC_Pos)                      /*!< SAU RLAR: NSC Mask */

#define SAU_RLAR_ENABLE_Pos                 0U                                            /*!< SAU RLAR: ENABLE Position */
#define SAU_RLAR_ENABLE_Msk                (1UL /*<< SAU_RLAR_ENABLE_Pos*/)               /*!< SAU RLAR: ENABLE Mask */

#endif /* defined (__SAUREGION_PRESENT) && (__SAUREGION_PRESENT == 1U) */

/*@} end of group CMSIS_SAU */
#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */



/**
  \ingroup    CMSIS_core_register
  \defgroup CMSIS_DCB       Debug Control Block
  \brief    Type definitions for the Debug Control Block Registers
  @{
 */

/**
  \brief  Structure type to access the Debug Control Block Registers (DCB).
 */
typedef struct
{
  __IOM uint32_t DHCSR;                  /*!< Offset: 0x000 (R/W)  Debug Halting Control and Status Register */
  __OM  uint32_t DCRSR;                  /*!< Offset: 0x004 ( /W)  Debug Core Register Selector Register */
  __IOM uint32_t DCRDR;                  /*!< Offset: 0x008 (R/W)  Debug Core Register Data Register */
  __IOM uint32_t DEMCR;                  /*!< Offset: 0x00C (R/W)  Debug Exception and Monitor Control Register */
        uint32_t RESERVED0[1U];
  __IOM uint32_t DAUTHCTRL;              /*!< Offset: 0x014 (R/W)  Debug Authentication Control Register */
  __IOM uint32_t DSCSR;                  /*!< Offset: 0x018 (R/W)  Debug Security Control and Status Register */
} DCB_Type;

/** \brief DCB Debug Halting Control and Status Register Definitions */
#define DCB_DHCSR_DBGKEY_Pos               16U                                            /*!< DCB DHCSR: Debug key Position */
#define DCB_DHCSR_DBGKEY_Msk               (0xFFFFUL << DCB_DHCSR_DBGKEY_Pos)             /*!< DCB DHCSR: Debug key Mask */

#define DCB_DHCSR_S_RESTART_ST_Pos         26U                                            /*!< DCB DHCSR: Restart sticky status Position */
#define DCB_DHCSR_S_RESTART_ST_Msk         (1UL << DCB_DHCSR_S_RESTART_ST_Pos)            /*!< DCB DHCSR: Restart sticky status Mask */

#define DCB_DHCSR_S_RESET_ST_Pos           25U                                            /*!< DCB DHCSR: Reset sticky status Position */
#define DCB_DHCSR_S_RESET_ST_Msk           (1UL << DCB_DHCSR_S_RESET_ST_Pos)              /*!< DCB DHCSR: Reset sticky status Mask */

#define DCB_DHCSR_S_RETIRE_ST_Pos          24U                                            /*!< DCB DHCSR: Retire sticky status Position */
#define DCB_DHCSR_S_RETIRE_ST_Msk          (1UL << DCB_DHCSR_S_RETIRE_ST_Pos)             /*!< DCB DHCSR: Retire sticky status Mask */

#define DCB_DHCSR_S_SDE_Pos                20U                                            /*!< DCB DHCSR: Secure debug enabled Position */
#define DCB_DHCSR_S_SDE_Msk                (1UL << DCB_DHCSR_S_SDE_Pos)                   /*!< DCB DHCSR: Secure debug enabled Mask */

#define DCB_DHCSR_S_LOCKUP_Pos             19U                                            /*!< DCB DHCSR: Lockup status Position */
#define DCB_DHCSR_S_LOCKUP_Msk             (1UL << DCB_DHCSR_S_LOCKUP_Pos)                /*!< DCB DHCSR: Lockup status Mask */

#define DCB_DHCSR_S_SLEEP_Pos              18U                                            /*!< DCB DHCSR: Sleeping status Position */
#define DCB_DHCSR_S_SLEEP_Msk              (1UL << DCB_DHCSR_S_SLEEP_Pos)                 /*!< DCB DHCSR: Sleeping status Mask */

#define DCB_DHCSR_S_HALT_Pos               17U                                            /*!< DCB DHCSR: Halted status Position */
#define DCB_DHCSR_S_HALT_Msk               (1UL << DCB_DHCSR_S_HALT_Pos)                  /*!< DCB DHCSR: Halted status Mask */

#define DCB_DHCSR_S_REGRDY_Pos             16U                                            /*!< DCB DHCSR: Register ready status Position */
#define DCB_DHCSR_S_REGRDY_Msk             (1UL << DCB_DHCSR_S_REGRDY_Pos)                /*!< DCB DHCSR: Register ready status Mask */

#define DCB_DHCSR_C_MASKINTS_Pos            3U                                            /*!< DCB DHCSR: Mask interrupts control Position */
#define DCB_DHCSR_C_MASKINTS_Msk           (1UL << DCB_DHCSR_C_MASKINTS_Pos)              /*!< DCB DHCSR: Mask interrupts control Mask */

#define DCB_DHCSR_C_STEP_Pos                2U                                            /*!< DCB DHCSR: Step control Position */
#define DCB_DHCSR_C_STEP_Msk               (1UL << DCB_DHCSR_C_STEP_Pos)                  /*!< DCB DHCSR: Step control Mask */

#define DCB_DHCSR_C_HALT_Pos                1U                                            /*!< DCB DHCSR: Halt control Position */
#define DCB_DHCSR_C_HALT_Msk               (1UL << DCB_DHCSR_C_HALT_Pos)                  /*!< DCB DHCSR: Halt control Mask */

#define DCB_DHCSR_C_DEBUGEN_Pos             0U                                            /*!< DCB DHCSR: Debug enable control Position */
#define DCB_DHCSR_C_DEBUGEN_Msk            (1UL /*<< DCB_DHCSR_C_DEBUGEN_Pos*/)           /*!< DCB DHCSR: Debug enable control Mask */

/** \brief DCB Debug Core Register Selector Register Definitions */
#define DCB_DCRSR_REGWnR_Pos               16U                                            /*!< DCB DCRSR: Register write/not-read Position */
#define DCB_DCRSR_REGWnR_Msk               (1UL << DCB_DCRSR_REGWnR_Pos)                  /*!< DCB DCRSR: Register write/not-read Mask */

#define DCB_DCRSR_REGSEL_Pos                0U                                            /*!< DCB DCRSR: Register selector Position */
#define DCB_DCRSR_REGSEL_Msk               (0x7FUL /*<< DCB_DCRSR_REGSEL_Pos*/)           /*!< DCB DCRSR: Register selector Mask */

/** \brief DCB Debug Core Register Data Register Definitions */
#define DCB_DCRDR_DBGTMP_Pos                0U                                            /*!< DCB DCRDR: Data temporary buffer Position */
#define DCB_DCRDR_DBGTMP_Msk               (0xFFFFFFFFUL /*<< DCB_DCRDR_DBGTMP_Pos*/)     /*!< DCB DCRDR: Data temporary buffer Mask */

/** \brief DCB Debug Exception and Monitor Control Register Definitions */
#define DCB_DEMCR_TRCENA_Pos               24U                                            /*!< DCB DEMCR: Trace enable Position */
#define DCB_DEMCR_TRCENA_Msk               (1UL << DCB_DEMCR_TRCENA_Pos)                  /*!< DCB DEMCR: Trace enable Mask */

#define DCB_DEMCR_VC_HARDERR_Pos           10U                                            /*!< DCB DEMCR: Vector Catch HardFault errors Position */
#define DCB_DEMCR_VC_HARDERR_Msk           (1UL << DCB_DEMCR_VC_HARDERR_Pos)              /*!< DCB DEMCR: Vector Catch HardFault errors Mask */

#define DCB_DEMCR_VC_CORERESET_Pos          0U                                            /*!< DCB DEMCR: Vector Catch Core reset Position */
#define DCB_DEMCR_VC_CORERESET_Msk         (1UL /*<< DCB_DEMCR_VC_CORERESET_Pos*/)        /*!< DCB DEMCR: Vector Catch Core reset Mask */

/** \brief DCB Debug Authentication Control Register Definitions */
#define DCB_DAUTHCTRL_INTSPNIDEN_Pos        3U                                            /*!< DCB DAUTHCTRL: Internal Secure non-invasive debug enable Position */
#define DCB_DAUTHCTRL_INTSPNIDEN_Msk       (1UL << DCB_DAUTHCTRL_INTSPNIDEN_Pos)          /*!< DCB DAUTHCTRL: Internal Secure non-invasive debug enable Mask */

#define DCB_DAUTHCTRL_SPNIDENSEL_Pos        2U                                            /*!< DCB DAUTHCTRL: Secure non-invasive debug enable select Position */
#define DCB_DAUTHCTRL_SPNIDENSEL_Msk       (1UL << DCB_DAUTHCTRL_SPNIDENSEL_Pos)          /*!< DCB DAUTHCTRL: Secure non-invasive debug enable select Mask */

#define DCB_DAUTHCTRL_INTSPIDEN_Pos         1U                                            /*!< DCB DAUTHCTRL: Internal Secure invasive debug enable Position */
#define DCB_DAUTHCTRL_INTSPIDEN_Msk        (1UL << DCB_DAUTHCTRL_INTSPIDEN_Pos)           /*!< DCB DAUTHCTRL: Internal Secure invasive debug enable Mask */

#define DCB_DAUTHCTRL_SPIDENSEL_Pos         0U                                            /*!< DCB DAUTHCTRL: Secure invasive debug enable select Position */
#define DCB_DAUTHCTRL_SPIDENSEL_Msk        (1UL /*<< DCB_DAUTHCTRL_SPIDENSEL_Pos*/)       /*!< DCB DAUTHCTRL: Secure invasive debug enable select Mask */

/** \brief DCB Debug Security Control and Status Register Definitions */
#define DCB_DSCSR_CDSKEY_Pos               17U                                            /*!< DCB DSCSR: CDS write-enable key Position */
#define DCB_DSCSR_CDSKEY_Msk               (1UL << DCB_DSCSR_CDSKEY_Pos)                  /*!< DCB DSCSR: CDS write-enable key Mask */

#define DCB_DSCSR_CDS_Pos                  16U                                            /*!< DCB DSCSR: Current domain Secure Position */
#define DCB_DSCSR_CDS_Msk                  (1UL << DCB_DSCSR_CDS_Pos)                     /*!< DCB DSCSR: Current domain Secure Mask */

#define DCB_DSCSR_SBRSEL_Pos                1U                                            /*!< DCB DSCSR: Secure banked register select Position */
#define DCB_DSCSR_SBRSEL_Msk               (1UL << DCB_DSCSR_SBRSEL_Pos)                  /*!< DCB DSCSR: Secure banked register select Mask */

#define DCB_DSCSR_SBRSELEN_Pos              0U                                            /*!< DCB DSCSR: Secure banked register select enable Position */
#define DCB_DSCSR_SBRSELEN_Msk             (1UL /*<< DCB_DSCSR_SBRSELEN_Pos*/)            /*!< DCB DSCSR: Secure banked register select enable Mask */

/*@} end of group CMSIS_DCB */


/**
  \ingroup  CMSIS_core_register
  \defgroup CMSIS_DIB       Debug Identification Block
  \brief    Type definitions for the Debug Identification Block Registers
  @{
 */

/**
  \brief  Structure type to access the Debug Identification Block Registers (DIB).
 */
typedef struct
{
  __OM  uint32_t DLAR;                   /*!< Offset: 0x000 ( /W)  SCS Software Lock Access Register */
  __IM  uint32_t DLSR;                   /*!< Offset: 0x004 (R/ )  SCS Software Lock Status Register */
  __IM  uint32_t DAUTHSTATUS;            /*!< Offset: 0x008 (R/ )  Debug Authentication Status Register */
  __IM  uint32_t DDEVARCH;               /*!< Offset: 0x00C (R/ )  SCS Device Architecture Register */
  __IM  uint32_t DDEVTYPE;               /*!< Offset: 0x010 (R/ )  SCS Device Type Register */
} DIB_Type;

/** \brief DIB SCS Software Lock Access Register Definitions */
#define DIB_DLAR_KEY_Pos                    0U                                            /*!< DIB DLAR: KEY Position */
#define DIB_DLAR_KEY_Msk                   (0xFFFFFFFFUL /*<< DIB_DLAR_KEY_Pos */)        /*!< DIB DLAR: KEY Mask */

/** \brief DIB SCS Software Lock Status Register Definitions */
#define DIB_DLSR_nTT_Pos                    2U                                            /*!< DIB DLSR: Not thirty-two bit Position */
#define DIB_DLSR_nTT_Msk                   (1UL << DIB_DLSR_nTT_Pos )                     /*!< DIB DLSR: Not thirty-two bit Mask */

#define DIB_DLSR_SLK_Pos                    1U                                            /*!< DIB DLSR: Software Lock status Position */
#define DIB_DLSR_SLK_Msk                   (1UL << DIB_DLSR_SLK_Pos )                     /*!< DIB DLSR: Software Lock status Mask */

#define DIB_DLSR_SLI_Pos                    0U                                            /*!< DIB DLSR: Software Lock implemented Position */
#define DIB_DLSR_SLI_Msk                   (1UL /*<< DIB_DLSR_SLI_Pos*/)                  /*!< DIB DLSR: Software Lock implemented Mask */

/** \brief DIB Debug Authentication Status Register Definitions */
#define DIB_DAUTHSTATUS_SNID_Pos            6U                                            /*!< DIB DAUTHSTATUS: Secure Non-invasive Debug Position */
#define DIB_DAUTHSTATUS_SNID_Msk           (0x3UL << DIB_DAUTHSTATUS_SNID_Pos )           /*!< DIB DAUTHSTATUS: Secure Non-invasive Debug Mask */

#define DIB_DAUTHSTATUS_SID_Pos             4U                                            /*!< DIB DAUTHSTATUS: Secure Invasive Debug Position */
#define DIB_DAUTHSTATUS_SID_Msk            (0x3UL << DIB_DAUTHSTATUS_SID_Pos )            /*!< DIB DAUTHSTATUS: Secure Invasive Debug Mask */

#define DIB_DAUTHSTATUS_NSNID_Pos           2U                                            /*!< DIB DAUTHSTATUS: Non-secure Non-invasive Debug Position */
#define DIB_DAUTHSTATUS_NSNID_Msk          (0x3UL << DIB_DAUTHSTATUS_NSNID_Pos )          /*!< DIB DAUTHSTATUS: Non-secure Non-invasive Debug Mask */

#define DIB_DAUTHSTATUS_NSID_Pos            0U                                            /*!< DIB DAUTHSTATUS: Non-secure Invasive Debug Position */
#define DIB_DAUTHSTATUS_NSID_Msk           (0x3UL /*<< DIB_DAUTHSTATUS_NSID_Pos*/)        /*!< DIB DAUTHSTATUS: Non-secure Invasive Debug Mask */

/** \brief DIB SCS Device Architecture Register Definitions */
#define DIB_DDEVARCH_ARCHITECT_Pos         21U                                            /*!< DIB DDEVARCH: Architect Position */
#define DIB_DDEVARCH_ARCHITECT_Msk         (0x7FFUL << DIB_DDEVARCH_ARCHITECT_Pos )       /*!< DIB DDEVARCH: Architect Mask */

#define DIB_DDEVARCH_PRESENT_Pos           20U                                            /*!< DIB DDEVARCH: DEVARCH Present Position */
#define DIB_DDEVARCH_PRESENT_Msk           (0x1FUL << DIB_DDEVARCH_PRESENT_Pos )          /*!< DIB DDEVARCH: DEVARCH Present Mask */

#define DIB_DDEVARCH_REVISION_Pos          16U                                            /*!< DIB DDEVARCH: Revision Position */
#define DIB_DDEVARCH_REVISION_Msk          (0xFUL << DIB_DDEVARCH_REVISION_Pos )          /*!< DIB DDEVARCH: Revision Mask */

#define DIB_DDEVARCH_ARCHVER_Pos           12U                                            /*!< DIB DDEVARCH: Architecture Version Position */
#define DIB_DDEVARCH_ARCHVER_Msk           (0xFUL << DIB_DDEVARCH_ARCHVER_Pos )           /*!< DIB DDEVARCH: Architecture Version Mask */

#define DIB_DDEVARCH_ARCHPART_Pos           0U                                            /*!< DIB DDEVARCH: Architecture Part Position */
#define DIB_DDEVARCH_ARCHPART_Msk          (0xFFFUL /*<< DIB_DDEVARCH_ARCHPART_Pos*/)     /*!< DIB DDEVARCH: Architecture Part Mask */

/** \brief DIB SCS Device Type Register Definitions */
#define DIB_DDEVTYPE_SUB_Pos                4U                                            /*!< DIB DDEVTYPE: Sub-type Position */
#define DIB_DDEVTYPE_SUB_Msk               (0xFUL << DIB_DDEVTYPE_SUB_Pos )               /*!< DIB DDEVTYPE: Sub-type Mask */

#define DIB_DDEVTYPE_MAJOR_Pos              0U                                            /*!< DIB DDEVTYPE: Major type Position */
#define DIB_DDEVTYPE_MAJOR_Msk             (0xFUL /*<< DIB_DDEVTYPE_MAJOR_Pos*/)          /*!< DIB DDEVTYPE: Major type Mask */

/*@} end of group CMSIS_DIB */


/**
  \ingroup    CMSIS_core_register
  \defgroup   CMSIS_core_bitfield     Core register bit field macros
  \brief      Macros for use with bit field definitions (xxx_Pos, xxx_Msk).
  @{
 */

/**
  \brief   Mask and shift a bit field value for use in a register bit range.
  \param[in] field  Name of the register bit field.
  \param[in] value  Value of the bit field. This parameter is interpreted as an uint32_t type.
  \return           Masked and shifted value.
*/
#define _VAL2FLD(field, value)    (((uint32_t)(value) << field ## _Pos) & field ## _Msk)

/**
  \brief     Mask and shift a register value to extract a bit filed value.
  \param[in] field  Name of the register bit field.
  \param[in] value  Value of register. This parameter is interpreted as an uint32_t type.
  \return           Masked and shifted bit field value.
*/
#define _FLD2VAL(field, value)    (((uint32_t)(value) & field ## _Msk) >> field ## _Pos)

/*@} end of group CMSIS_core_bitfield */


/**
  \ingroup    CMSIS_core_register
  \defgroup   CMSIS_core_base     Core Definitions
  \brief      Definitions for base addresses, unions, and structures.
  @{
 */

/* Memory mapping of Core Hardware */
  #define SCS_BASE            (0xE000E000UL)                             /*!< System Control Space Base Address */
  #define DWT_BASE            (0xE0001000UL)                             /*!< DWT Base Address */
  #define TPIU_BASE           (0xE0040000UL)                             /*!< TPIU Base Address */
  #define DCB_BASE            (0xE000EDF0UL)                             /*!< DCB Base Address */
  #define DIB_BASE            (0xE000EFB0UL)                             /*!< DIB Base Address */
  #define SysTick_BASE        (SCS_BASE +  0x0010UL)                     /*!< SysTick Base Address */
  #define NVIC_BASE           (SCS_BASE +  0x0100UL)                     /*!< NVIC Base Address */
  #define SCB_BASE            (SCS_BASE +  0x0D00UL)                     /*!< System Control Block Base Address */


  #define SCB                 ((SCB_Type       *)     SCB_BASE         ) /*!< SCB configuration struct */
  #define SysTick             ((SysTick_Type   *)     SysTick_BASE     ) /*!< SysTick configuration struct */
  #define NVIC                ((NVIC_Type      *)     NVIC_BASE        ) /*!< NVIC configuration struct */
  #define DWT                 ((DWT_Type       *)     DWT_BASE         ) /*!< DWT configuration struct */
  #define TPIU                ((TPIU_Type      *)     TPIU_BASE        ) /*!< TPIU configuration struct */
  #define DCB                 ((DCB_Type       *)     DCB_BASE         ) /*!< DCB configuration struct */
  #define DIB                 ((DIB_Type       *)     DIB_BASE         ) /*!< DIB configuration struct */

  #if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U)
    #define MPU_BASE          (SCS_BASE +  0x0D90UL)                     /*!< Memory Protection Unit */
    #define MPU               ((MPU_Type       *)     MPU_BASE         ) /*!< Memory Protection Unit */
  #endif

  #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    #define SAU_BASE          (SCS_BASE +  0x0DD0UL)                     /*!< Security Attribution Unit */
    #define SAU               ((SAU_Type       *)     SAU_BASE         ) /*!< Security Attribution Unit */
  #endif

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  #define SCS_BASE_NS         (0xE002E000UL)                             /*!< System Control Space Base Address (non-secure address space) */
  #define DCB_BASE_NS         (0xE002EDF0UL)                             /*!< DCB Base Address                  (non-secure address space) */
  #define DIB_BASE_NS         (0xE002EFB0UL)                             /*!< DIB Base Address                  (non-secure address space) */
  #define SysTick_BASE_NS     (SCS_BASE_NS +  0x0010UL)                  /*!< SysTick Base Address              (non-secure address space) */
  #define NVIC_BASE_NS        (SCS_BASE_NS +  0x0100UL)                  /*!< NVIC Base Address                 (non-secure address space) */
  #define SCB_BASE_NS         (SCS_BASE_NS +  0x0D00UL)                  /*!< System Control Block Base Address (non-secure address space) */

  #define SCB_NS              ((SCB_Type       *)     SCB_BASE_NS      ) /*!< SCB configuration struct          (non-secure address space) */
  #define SysTick_NS          ((SysTick_Type   *)     SysTick_BASE_NS  ) /*!< SysTick configuration struct      (non-secure address space) */
  #define NVIC_NS             ((NVIC_Type      *)     NVIC_BASE_NS     ) /*!< NVIC configuration struct         (non-secure address space) */
  #define DCB_NS              ((DCB_Type       *)     DCB_BASE_NS      ) /*!< DCB configuration struct          (non-secure address space) */
  #define DIB_NS              ((DIB_Type       *)     DIB_BASE_NS      ) /*!< DIB configuration struct          (non-secure address space) */

  #if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U)
    #define MPU_BASE_NS       (SCS_BASE_NS +  0x0D90UL)                  /*!< Memory Protection Unit            (non-secure address space) */
    #define MPU_NS            ((MPU_Type       *)     MPU_BASE_NS      ) /*!< Memory Protection Unit            (non-secure address space) */
  #endif

#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
/*@} */


/**
  \defgroup   CMSIS_deprecated_aliases     Backwards Compatibility Aliases
  \brief      Alias definitions present for backwards compatibility for deprecated symbols.
  @{
 */

#ifndef CMSIS_DISABLE_DEPRECATED

#define SCB_AIRCR_ENDIANESS_Pos            SCB_AIRCR_ENDIANNESS_Pos
#define SCB_AIRCR_ENDIANESS_Msk            SCB_AIRCR_ENDIANNESS_Msk

/* deprecated, CMSIS_5 backward compatibility */
typedef struct
{
  __IOM uint32_t DHCSR;
  __OM  uint32_t DCRSR;
  __IOM uint32_t DCRDR;
  __IOM uint32_t DEMCR;
        uint32_t RESERVED0[1U];
  __IOM uint32_t DAUTHCTRL;
  __IOM uint32_t DSCSR;
} CoreDebug_Type;

/* Debug Halting Control and Status Register Definitions */
#define CoreDebug_DHCSR_DBGKEY_Pos         DCB_DHCSR_DBGKEY_Pos
#define CoreDebug_DHCSR_DBGKEY_Msk         DCB_DHCSR_DBGKEY_Msk

#define CoreDebug_DHCSR_S_RESTART_ST_Pos   DCB_DHCSR_S_RESTART_ST_Pos
#define CoreDebug_DHCSR_S_RESTART_ST_Msk   DCB_DHCSR_S_RESTART_ST_Msk

#define CoreDebug_DHCSR_S_RESET_ST_Pos     DCB_DHCSR_S_RESET_ST_Pos
#define CoreDebug_DHCSR_S_RESET_ST_Msk     DCB_DHCSR_S_RESET_ST_Msk

#define CoreDebug_DHCSR_S_RETIRE_ST_Pos    DCB_DHCSR_S_RETIRE_ST_Pos
#define CoreDebug_DHCSR_S_RETIRE_ST_Msk    DCB_DHCSR_S_RETIRE_ST_Msk

#define CoreDebug_DHCSR_S_LOCKUP_Pos       DCB_DHCSR_S_LOCKUP_Pos
#define CoreDebug_DHCSR_S_LOCKUP_Msk       DCB_DHCSR_S_LOCKUP_Msk

#define CoreDebug_DHCSR_S_SLEEP_Pos        DCB_DHCSR_S_SLEEP_Pos
#define CoreDebug_DHCSR_S_SLEEP_Msk        DCB_DHCSR_S_SLEEP_Msk

#define CoreDebug_DHCSR_S_HALT_Pos         DCB_DHCSR_S_HALT_Pos
#define CoreDebug_DHCSR_S_HALT_Msk         DCB_DHCSR_S_HALT_Msk

#define CoreDebug_DHCSR_S_REGRDY_Pos       DCB_DHCSR_S_REGRDY_Pos
#define CoreDebug_DHCSR_S_REGRDY_Msk       DCB_DHCSR_S_REGRDY_Msk

#define CoreDebug_DHCSR_C_MASKINTS_Pos     DCB_DHCSR_C_MASKINTS_Pos
#define CoreDebug_DHCSR_C_MASKINTS_Msk     DCB_DHCSR_C_MASKINTS_Msk

#define CoreDebug_DHCSR_C_STEP_Pos         DCB_DHCSR_C_STEP_Pos
#define CoreDebug_DHCSR_C_STEP_Msk         DCB_DHCSR_C_STEP_Msk

#define CoreDebug_DHCSR_C_HALT_Pos         DCB_DHCSR_C_HALT_Pos
#define CoreDebug_DHCSR_C_HALT_Msk         DCB_DHCSR_C_HALT_Msk

#define CoreDebug_DHCSR_C_DEBUGEN_Pos      DCB_DHCSR_C_DEBUGEN_Pos
#define CoreDebug_DHCSR_C_DEBUGEN_Msk      DCB_DHCSR_C_DEBUGEN_Msk

/* Debug Core Register Selector Register Definitions */
#define CoreDebug_DCRSR_REGWnR_Pos         DCB_DCRSR_REGWnR_Pos
#define CoreDebug_DCRSR_REGWnR_Msk         DCB_DCRSR_REGWnR_Msk

#define CoreDebug_DCRSR_REGSEL_Pos         DCB_DCRSR_REGSEL_Pos
#define CoreDebug_DCRSR_REGSEL_Msk         DCB_DCRSR_REGSEL_Msk

/* Debug Exception and Monitor Control Register Definitions */
#define CoreDebug_DEMCR_DWTENA_Pos         DCB_DEMCR_TRCENA_Pos
#define CoreDebug_DEMCR_DWTENA_Msk         DCB_DEMCR_TRCENA_Msk

#define CoreDebug_DEMCR_VC_HARDERR_Pos     DCB_DEMCR_VC_HARDERR_Pos
#define CoreDebug_DEMCR_VC_HARDERR_Msk     DCB_DEMCR_VC_HARDERR_Msk

#define CoreDebug_DEMCR_VC_CORERESET_Pos   DCB_DEMCR_VC_CORERESET_Pos
#define CoreDebug_DEMCR_VC_CORERESET_Msk   DCB_DEMCR_VC_CORERESET_Msk

/* Debug Authentication Control Register Definitions */
#define CoreDebug_DAUTHCTRL_INTSPNIDEN_Pos DCB_DAUTHCTRL_INTSPNIDEN_Pos
#define CoreDebug_DAUTHCTRL_INTSPNIDEN_Msk DCB_DAUTHCTRL_INTSPNIDEN_Msk

#define CoreDebug_DAUTHCTRL_SPNIDENSEL_Pos DCB_DAUTHCTRL_SPNIDENSEL_Pos
#define CoreDebug_DAUTHCTRL_SPNIDENSEL_Msk DCB_DAUTHCTRL_SPNIDENSEL_Msk

#define CoreDebug_DAUTHCTRL_INTSPIDEN_Pos  DCB_DAUTHCTRL_INTSPIDEN_Pos
#define CoreDebug_DAUTHCTRL_INTSPIDEN_Msk  DCB_DAUTHCTRL_INTSPIDEN_Msk

#define CoreDebug_DAUTHCTRL_SPIDENSEL_Pos  DCB_DAUTHCTRL_SPIDENSEL_Pos
#define CoreDebug_DAUTHCTRL_SPIDENSEL_Msk  DCB_DAUTHCTRL_SPIDENSEL_Msk

/* Debug Security Control and Status Register Definitions */
#define CoreDebug_DSCSR_CDS_Pos            DCB_DSCSR_CDS_Pos
#define CoreDebug_DSCSR_CDS_Msk            DCB_DSCSR_CDS_Msk

#define CoreDebug_DSCSR_SBRSEL_Pos         DCB_DSCSR_SBRSEL_Pos
#define CoreDebug_DSCSR_SBRSEL_Msk         DCB_DSCSR_SBRSEL_Msk

#define CoreDebug_DSCSR_SBRSELEN_Pos       DCB_DSCSR_SBRSELEN_Pos
#define CoreDebug_DSCSR_SBRSELEN_Msk       DCB_DSCSR_SBRSELEN_Msk

#define CoreDebug           ((CoreDebug_Type *)     DCB_BASE)
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define CoreDebug_NS        ((CoreDebug_Type *)     DCB_BASE_NS)
#endif

#endif // CMSIS_DISABLE_DEPRECATED

/*@} */


/*******************************************************************************
 *                Hardware Abstraction Layer
  Core Function Interface contains:
  - Core NVIC Functions
  - Core SysTick Functions
  - Core Debug Functions
  - Core Register Access Functions
 ******************************************************************************/
/**
  \defgroup CMSIS_Core_FunctionInterface Functions and Instructions Reference
*/



/* ##########################   NVIC functions  #################################### */
/**
  \ingroup  CMSIS_Core_FunctionInterface
  \defgroup CMSIS_Core_NVICFunctions NVIC Functions
  \brief    Functions that manage interrupts and exceptions via the NVIC.
  @{
 */

#ifdef CMSIS_NVIC_VIRTUAL
  #ifndef CMSIS_NVIC_VIRTUAL_HEADER_FILE
    #define CMSIS_NVIC_VIRTUAL_HEADER_FILE "cmsis_nvic_virtual.h"
  #endif
  #include CMSIS_NVIC_VIRTUAL_HEADER_FILE
#else
/*        NVIC_SetPriorityGrouping    not available for Cortex-M23 */
/*        NVIC_GetPriorityGrouping    not available for Cortex-M23 */
  #define NVIC_EnableIRQ              __NVIC_EnableIRQ
  #define NVIC_GetEnableIRQ           __NVIC_GetEnableIRQ
  #define NVIC_DisableIRQ             __NVIC_DisableIRQ
  #define NVIC_GetPendingIRQ          __NVIC_GetPendingIRQ
  #define NVIC_SetPendingIRQ          __NVIC_SetPendingIRQ
  #define NVIC_ClearPendingIRQ        __NVIC_ClearPendingIRQ
  #define NVIC_GetActive              __NVIC_GetActive
  #define NVIC_SetPriority            __NVIC_SetPriority
  #define NVIC_GetPriority            __NVIC_GetPriority
  #define NVIC_SystemReset            __NVIC_SystemReset
#endif /* CMSIS_NVIC_VIRTUAL */

#ifdef CMSIS_VECTAB_VIRTUAL
  #ifndef CMSIS_VECTAB_VIRTUAL_HEADER_FILE
    #define CMSIS_VECTAB_VIRTUAL_HEADER_FILE "cmsis_vectab_virtual.h"
  #endif
  #include CMSIS_VECTAB_VIRTUAL_HEADER_FILE
#else
  #define NVIC_SetVector              __NVIC_SetVector
  #define NVIC_GetVector              __NVIC_GetVector
#endif  /* (CMSIS_VECTAB_VIRTUAL) */

#define NVIC_USER_IRQ_OFFSET          16


/* Special LR values for Secure/Non-Secure call handling and exception handling                                               */

/* Function Return Payload (from ARMv8-M Architecture Reference Manual) LR value on entry from Secure BLXNS                   */
#define FNC_RETURN                 (0xFEFFFFFFUL)     /* bit [0] ignored when processing a branch                             */

/* The following EXC_RETURN mask values are used to evaluate the LR on exception entry */
#define EXC_RETURN_PREFIX          (0xFF000000UL)     /* bits [31:24] set to indicate an EXC_RETURN value                     */
#define EXC_RETURN_S               (0x00000040UL)     /* bit [6] stack used to push registers: 0=Non-secure 1=Secure          */
#define EXC_RETURN_DCRS            (0x00000020UL)     /* bit [5] stacking rules for called registers: 0=skipped 1=saved       */
#define EXC_RETURN_FTYPE           (0x00000010UL)     /* bit [4] allocate stack for floating-point context: 0=done 1=skipped  */
#define EXC_RETURN_MODE            (0x00000008UL)     /* bit [3] processor mode for return: 0=Handler mode 1=Thread mode      */
#define EXC_RETURN_SPSEL           (0x00000004UL)     /* bit [2] stack pointer used to restore context: 0=MSP 1=PSP           */
#define EXC_RETURN_ES              (0x00000001UL)     /* bit [0] security state exception was taken to: 0=Non-secure 1=Secure */

/* Integrity Signature (from ARMv8-M Architecture Reference Manual) for exception context stacking                            */
#if defined (__FPU_PRESENT) && (__FPU_PRESENT == 1U)  /* Value for processors with floating-point extension:                  */
#define EXC_INTEGRITY_SIGNATURE     (0xFEFA125AUL)     /* bit [0] SFTC must match LR bit[4] EXC_RETURN_FTYPE                   */
#else
#define EXC_INTEGRITY_SIGNATURE     (0xFEFA125BUL)     /* Value for processors without floating-point extension                */
#endif


/* Interrupt Priorities are WORD accessible only under Armv6-M                  */
/* The following MACROS handle generation of the register offset and byte masks */
#define _BIT_SHIFT(IRQn)         (  ((((uint32_t)(int32_t)(IRQn))         )      &  0x03UL) * 8UL)
#define _SHP_IDX(IRQn)           ( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >>    2UL)      )
#define _IP_IDX(IRQn)            (   (((uint32_t)(int32_t)(IRQn))                >>    2UL)      )

#define __NVIC_SetPriorityGrouping(X) (void)(X)
#define __NVIC_GetPriorityGrouping()  (0U)

/**
  \brief   Enable Interrupt
  \details Enables a device specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    __COMPILER_BARRIER();
    NVIC->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __COMPILER_BARRIER();
  }
}


/**
  \brief   Get Interrupt Enable status
  \details Returns a device specific interrupt enable status from the NVIC interrupt controller.
  \param [in]      IRQn  Device specific interrupt number.
  \return             0  Interrupt is not enabled.
  \return             1  Interrupt is enabled.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC->ISER[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}


/**
  \brief   Disable Interrupt
  \details Disables a device specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC->ICER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __DSB();
    __ISB();
  }
}


/**
  \brief   Get Pending Interrupt
  \details Reads the NVIC pending register and returns the pending bit for the specified device specific interrupt.
  \param [in]      IRQn  Device specific interrupt number.
  \return             0  Interrupt status is not pending.
  \return             1  Interrupt status is pending.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC->ISPR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}


/**
  \brief   Set Pending Interrupt
  \details Sets the pending bit of a device specific interrupt in the NVIC pending register.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC->ISPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}


/**
  \brief   Clear Pending Interrupt
  \details Clears the pending bit of a device specific interrupt in the NVIC pending register.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC->ICPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}


/**
  \brief   Get Active Interrupt
  \details Reads the active register in the NVIC and returns the active bit for the device specific interrupt.
  \param [in]      IRQn  Device specific interrupt number.
  \return             0  Interrupt status is not active.
  \return             1  Interrupt status is active.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC->IABR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}


#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  \brief   Get Interrupt Target State
  \details Reads the interrupt target field in the NVIC and returns the interrupt target bit for the device specific interrupt.
  \param [in]      IRQn  Device specific interrupt number.
  \return             0  if interrupt is assigned to Secure
  \return             1  if interrupt is assigned to Non Secure
  \note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t NVIC_GetTargetState(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC->ITNS[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}


/**
  \brief   Set Interrupt Target State
  \details Sets the interrupt target field in the NVIC and returns the interrupt target bit for the device specific interrupt.
  \param [in]      IRQn  Device specific interrupt number.
  \return             0  if interrupt is assigned to Secure
                      1  if interrupt is assigned to Non Secure
  \note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t NVIC_SetTargetState(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC->ITNS[(((uint32_t)IRQn) >> 5UL)] |=  ((uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL)));
    return((uint32_t)(((NVIC->ITNS[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}


/**
  \brief   Clear Interrupt Target State
  \details Clears the interrupt target field in the NVIC and returns the interrupt target bit for the device specific interrupt.
  \param [in]      IRQn  Device specific interrupt number.
  \return             0  if interrupt is assigned to Secure
                      1  if interrupt is assigned to Non Secure
  \note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t NVIC_ClearTargetState(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC->ITNS[(((uint32_t)IRQn) >> 5UL)] &= ~((uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL)));
    return((uint32_t)(((NVIC->ITNS[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */


/**
  \brief   Set Interrupt Priority
  \details Sets the priority of a device specific interrupt or a processor exception.
           The interrupt number can be positive to specify a device specific interrupt,
           or negative to specify a processor exception.
  \param [in]      IRQn  Interrupt number.
  \param [in]  priority  Priority to set.
  \note    The priority cannot be set for every processor exception.
 */
__STATIC_INLINE void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC->IPR[_IP_IDX(IRQn)]  = ((uint32_t)(NVIC->IPR[_IP_IDX(IRQn)]  & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
       (((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(IRQn)));
  }
  else
  {
    SCB->SHPR[_SHP_IDX(IRQn)] = ((uint32_t)(SCB->SHPR[_SHP_IDX(IRQn)] & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
       (((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(IRQn)));
  }
}


/**
  \brief   Get Interrupt Priority
  \details Reads the priority of a device specific interrupt or a processor exception.
           The interrupt number can be positive to specify a device specific interrupt,
           or negative to specify a processor exception.
  \param [in]   IRQn  Interrupt number.
  \return             Interrupt Priority.
                      Value is aligned automatically to the implemented priority bits of the microcontroller.
 */
__STATIC_INLINE uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC->IPR[ _IP_IDX(IRQn)] >> _BIT_SHIFT(IRQn) ) & (uint32_t)0xFFUL) >> (8U - __NVIC_PRIO_BITS)));
  }
  else
  {
    return((uint32_t)(((SCB->SHPR[_SHP_IDX(IRQn)] >> _BIT_SHIFT(IRQn) ) & (uint32_t)0xFFUL) >> (8U - __NVIC_PRIO_BITS)));
  }
}


/**
  \brief   Encode Priority
  \details Encodes the priority for an interrupt with the given priority group,
           preemptive priority value, and subpriority value.
           In case of a conflict between priority grouping and available
           priority bits (__NVIC_PRIO_BITS), the smallest possible priority group is set.
  \param [in]     PriorityGroup  Used priority group.
  \param [in]   PreemptPriority  Preemptive priority value (starting from 0).
  \param [in]       SubPriority  Subpriority value (starting from 0).
  \return                        Encoded priority. Value can be used in the function \ref NVIC_SetPriority().
 */
__STATIC_INLINE uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);   /* only values 0..7 are used          */
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(__NVIC_PRIO_BITS)) ? (uint32_t)(__NVIC_PRIO_BITS) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(__NVIC_PRIO_BITS));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}


/**
  \brief   Decode Priority
  \details Decodes an interrupt priority value with a given priority group to
           preemptive priority value and subpriority value.
           In case of a conflict between priority grouping and available
           priority bits (__NVIC_PRIO_BITS) the smallest possible priority group is set.
  \param [in]         Priority   Priority value, which can be retrieved with the function \ref NVIC_GetPriority().
  \param [in]     PriorityGroup  Used priority group.
  \param [out] pPreemptPriority  Preemptive priority value (starting from 0).
  \param [out]     pSubPriority  Subpriority value (starting from 0).
 */
__STATIC_INLINE void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);   /* only values 0..7 are used          */
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(__NVIC_PRIO_BITS)) ? (uint32_t)(__NVIC_PRIO_BITS) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(__NVIC_PRIO_BITS)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(__NVIC_PRIO_BITS));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}


/**
  \brief   Set Interrupt Vector
  \details Sets an interrupt vector in SRAM based interrupt vector table.
           The interrupt number can be positive to specify a device specific interrupt,
           or negative to specify a processor exception.
           VTOR must been relocated to SRAM before.
           If VTOR is not present address 0 must be mapped to SRAM.
  \param [in]   IRQn      Interrupt number
  \param [in]   vector    Address of interrupt handler function
 */
__STATIC_INLINE void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
  uint32_t *vectors = (uint32_t *) ((uintptr_t) SCB->VTOR);
#else
  uint32_t *vectors = (uint32_t *)0x0U;
#endif
  vectors[(int32_t)IRQn + NVIC_USER_IRQ_OFFSET] = vector;
  __DSB();
}


/**
  \brief   Get Interrupt Vector
  \details Reads an interrupt vector from interrupt vector table.
           The interrupt number can be positive to specify a device specific interrupt,
           or negative to specify a processor exception.
  \param [in]   IRQn      Interrupt number.
  \return                 Address of interrupt handler function
 */
__STATIC_INLINE uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
  uint32_t *vectors = (uint32_t *) ((uintptr_t) SCB->VTOR);
#else
  uint32_t *vectors = (uint32_t *)0x0U;
#endif
  return vectors[(int32_t)IRQn + NVIC_USER_IRQ_OFFSET];
}


/**
  \brief   System Reset
  \details Initiates a system reset request to reset the MCU.
 */
__NO_RETURN __STATIC_INLINE void __NVIC_SystemReset(void)
{
  __DSB();                                                          /* Ensure all outstanding memory accesses included
                                                                       buffered write are completed before reset */
  SCB->AIRCR  = ((0x5FAUL << SCB_AIRCR_VECTKEY_Pos) |
                 SCB_AIRCR_SYSRESETREQ_Msk);
  __DSB();                                                          /* Ensure completion of memory access */

  for(;;)                                                           /* wait until reset */
  {
    __NOP();
  }
}

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  \brief   Enable Interrupt (non-secure)
  \details Enables a device specific interrupt in the non-secure NVIC interrupt controller when in secure state.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE void TZ_NVIC_EnableIRQ_NS(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC_NS->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}


/**
  \brief   Get Interrupt Enable status (non-secure)
  \details Returns a device specific interrupt enable status from the non-secure NVIC interrupt controller when in secure state.
  \param [in]      IRQn  Device specific interrupt number.
  \return             0  Interrupt is not enabled.
  \return             1  Interrupt is enabled.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t TZ_NVIC_GetEnableIRQ_NS(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC_NS->ISER[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}


/**
  \brief   Disable Interrupt (non-secure)
  \details Disables a device specific interrupt in the non-secure NVIC interrupt controller when in secure state.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE void TZ_NVIC_DisableIRQ_NS(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC_NS->ICER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}


/**
  \brief   Get Pending Interrupt (non-secure)
  \details Reads the NVIC pending register in the non-secure NVIC when in secure state and returns the pending bit for the specified device specific interrupt.
  \param [in]      IRQn  Device specific interrupt number.
  \return             0  Interrupt status is not pending.
  \return             1  Interrupt status is pending.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t TZ_NVIC_GetPendingIRQ_NS(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC_NS->ISPR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}


/**
  \brief   Set Pending Interrupt (non-secure)
  \details Sets the pending bit of a device specific interrupt in the non-secure NVIC pending register when in secure state.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE void TZ_NVIC_SetPendingIRQ_NS(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC_NS->ISPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}


/**
  \brief   Clear Pending Interrupt (non-secure)
  \details Clears the pending bit of a device specific interrupt in the non-secure NVIC pending register when in secure state.
  \param [in]      IRQn  Device specific interrupt number.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE void TZ_NVIC_ClearPendingIRQ_NS(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC_NS->ICPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}


/**
  \brief   Get Active Interrupt (non-secure)
  \details Reads the active register in non-secure NVIC when in secure state and returns the active bit for the device specific interrupt.
  \param [in]      IRQn  Device specific interrupt number.
  \return             0  Interrupt status is not active.
  \return             1  Interrupt status is active.
  \note    IRQn must not be negative.
 */
__STATIC_INLINE uint32_t TZ_NVIC_GetActive_NS(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC_NS->IABR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}


/**
  \brief   Set Interrupt Priority (non-secure)
  \details Sets the priority of a non-secure device specific interrupt or a non-secure processor exception when in secure state.
           The interrupt number can be positive to specify a device specific interrupt,
           or negative to specify a processor exception.
  \param [in]      IRQn  Interrupt number.
  \param [in]  priority  Priority to set.
  \note    The priority cannot be set for every non-secure processor exception.
 */
__STATIC_INLINE void TZ_NVIC_SetPriority_NS(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    NVIC_NS->IPR[_IP_IDX(IRQn)]  = ((uint32_t)(NVIC_NS->IPR[_IP_IDX(IRQn)]  & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
       (((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(IRQn)));
  }
  else
  {
    SCB_NS->SHPR[_SHP_IDX(IRQn)] = ((uint32_t)(SCB_NS->SHPR[_SHP_IDX(IRQn)] & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
       (((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL) << _BIT_SHIFT(IRQn)));
  }
}


/**
  \brief   Get Interrupt Priority (non-secure)
  \details Reads the priority of a non-secure device specific interrupt or a non-secure processor exception when in secure state.
           The interrupt number can be positive to specify a device specific interrupt,
           or negative to specify a processor exception.
  \param [in]   IRQn  Interrupt number.
  \return             Interrupt Priority. Value is aligned automatically to the implemented priority bits of the microcontroller.
 */
__STATIC_INLINE uint32_t TZ_NVIC_GetPriority_NS(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((NVIC_NS->IPR[ _IP_IDX(IRQn)] >> _BIT_SHIFT(IRQn) ) & (uint32_t)0xFFUL) >> (8U - __NVIC_PRIO_BITS)));
  }
  else
  {
    return((uint32_t)(((SCB_NS->SHPR[_SHP_IDX(IRQn)] >> _BIT_SHIFT(IRQn) ) & (uint32_t)0xFFUL) >> (8U - __NVIC_PRIO_BITS)));
  }
}
#endif /*  defined (__ARM_FEATURE_CMSE) &&(__ARM_FEATURE_CMSE == 3U) */

/*@} end of CMSIS_Core_NVICFunctions */

/* ##########################  MPU functions  #################################### */

#if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U)

  #include "m-profile/armv8m_mpu.h"

#endif


/* ##########################  FPU functions  #################################### */
/**
  \ingroup  CMSIS_Core_FunctionInterface
  \defgroup CMSIS_Core_FpuFunctions FPU Functions
  \brief    Function that provides FPU type.
  @{
 */

/**
  \brief   get FPU type
  \details returns the FPU type
  \returns
   - \b  0: No FPU
   - \b  1: Single precision FPU
   - \b  2: Double + Single precision FPU
 */
__STATIC_INLINE uint32_t SCB_GetFPUType(void)
{
    return 0U;           /* No FPU */
}

/*@} end of CMSIS_Core_FpuFunctions */



/* ##########################   SAU functions  #################################### */
/**
  \ingroup  CMSIS_Core_FunctionInterface
  \defgroup CMSIS_Core_SAUFunctions SAU Functions
  \brief    Functions that configure the SAU.
  @{
 */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)

/**
  \brief   Enable SAU
  \details Enables the Security Attribution Unit (SAU).
 */
__STATIC_INLINE void TZ_SAU_Enable(void)
{
    SAU->CTRL |=  (SAU_CTRL_ENABLE_Msk);
}



/**
  \brief   Disable SAU
  \details Disables the Security Attribution Unit (SAU).
 */
__STATIC_INLINE void TZ_SAU_Disable(void)
{
    SAU->CTRL &= ~(SAU_CTRL_ENABLE_Msk);
}

#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

/*@} end of CMSIS_Core_SAUFunctions */




/* ##################################    Debug Control function  ############################################ */
/**
  \ingroup  CMSIS_Core_FunctionInterface
  \defgroup CMSIS_Core_DCBFunctions Debug Control Functions
  \brief    Functions that access the Debug Control Block.
  @{
 */


/**
  \brief   Set Debug Authentication Control Register
  \details writes to Debug Authentication Control register.
  \param [in]  value  value to be writen.
 */
__STATIC_INLINE void DCB_SetAuthCtrl(uint32_t value)
{
    __DSB();
    __ISB();
    DCB->DAUTHCTRL = value;
    __DSB();
    __ISB();
}


/**
  \brief   Get Debug Authentication Control Register
  \details Reads Debug Authentication Control register.
  \return             Debug Authentication Control Register.
 */
__STATIC_INLINE uint32_t DCB_GetAuthCtrl(void)
{
    return (DCB->DAUTHCTRL);
}


#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  \brief   Set Debug Authentication Control Register (non-secure)
  \details writes to non-secure Debug Authentication Control register when in secure state.
  \param [in]  value  value to be writen
 */
__STATIC_INLINE void TZ_DCB_SetAuthCtrl_NS(uint32_t value)
{
    __DSB();
    __ISB();
    DCB_NS->DAUTHCTRL = value;
    __DSB();
    __ISB();
}


/**
  \brief   Get Debug Authentication Control Register (non-secure)
  \details Reads non-secure Debug Authentication Control register when in secure state.
  \return             Debug Authentication Control Register.
 */
__STATIC_INLINE uint32_t TZ_DCB_GetAuthCtrl_NS(void)
{
    return (DCB_NS->DAUTHCTRL);
}
#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

/*@} end of CMSIS_Core_DCBFunctions */




/* ##################################    Debug Identification function  ############################################ */
/**
  \ingroup  CMSIS_Core_FunctionInterface
  \defgroup CMSIS_Core_DIBFunctions Debug Identification Functions
  \brief    Functions that access the Debug Identification Block.
  @{
 */


/**
  \brief   Get Debug Authentication Status Register
  \details Reads Debug Authentication Status register.
  \return             Debug Authentication Status Register.
 */
__STATIC_INLINE uint32_t DIB_GetAuthStatus(void)
{
    return (DIB->DAUTHSTATUS);
}


#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  \brief   Get Debug Authentication Status Register (non-secure)
  \details Reads non-secure Debug Authentication Status register when in secure state.
  \return             Debug Authentication Status Register.
 */
__STATIC_INLINE uint32_t TZ_DIB_GetAuthStatus_NS(void)
{
    return (DIB_NS->DAUTHSTATUS);
}
#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

/*@} end of CMSIS_Core_DCBFunctions */




/* ##################################    SysTick function  ############################################ */
/**
  \ingroup  CMSIS_Core_FunctionInterface
  \defgroup CMSIS_Core_SysTickFunctions SysTick Functions
  \brief    Functions that configure the System.
  @{
 */

#if defined (__Vendor_SysTickConfig) && (__Vendor_SysTickConfig == 0U)

/**
  \brief   System Tick Configuration
  \details Initializes the System Timer and its interrupt, and starts the System Tick Timer.
           Counter is in free running mode to generate periodic interrupts.
  \param [in]  ticks  Number of ticks between two interrupts.
  \return          0  Function succeeded.
  \return          1  Function failed.
  \note    When the variable <b>__Vendor_SysTickConfig</b> is set to 1, then the
           function <b>SysTick_Config</b> is not included. In this case, the file <b><i>device</i>.h</b>
           must contain a vendor-specific implementation of this function.
 */
__STATIC_INLINE uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
  {
    return (1UL);                                                   /* Reload value impossible */
  }

  SysTick->LOAD  = (uint32_t)(ticks - 1UL);                         /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
  SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
  return (0UL);                                                     /* Function successful */
}

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  \brief   System Tick Configuration (non-secure)
  \details Initializes the non-secure System Timer and its interrupt when in secure state, and starts the System Tick Timer.
           Counter is in free running mode to generate periodic interrupts.
  \param [in]  ticks  Number of ticks between two interrupts.
  \return          0  Function succeeded.
  \return          1  Function failed.
  \note    When the variable <b>__Vendor_SysTickConfig</b> is set to 1, then the
           function <b>TZ_SysTick_Config_NS</b> is not included. In this case, the file <b><i>device</i>.h</b>
           must contain a vendor-specific implementation of this function.

 */
__STATIC_INLINE uint32_t TZ_SysTick_Config_NS(uint32_t ticks)
{
  if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
  {
    return (1UL);                                                         /* Reload value impossible */
  }

  SysTick_NS->LOAD  = (uint32_t)(ticks - 1UL);                            /* set reload register */
  TZ_NVIC_SetPriority_NS (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
  SysTick_NS->VAL   = 0UL;                                                /* Load the SysTick Counter Value */
  SysTick_NS->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                      SysTick_CTRL_TICKINT_Msk   |
                      SysTick_CTRL_ENABLE_Msk;                            /* Enable SysTick IRQ and SysTick Timer */
  return (0UL);                                                           /* Function successful */
}
#endif /* defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

#endif

/*@} end of CMSIS_Core_SysTickFunctions */




#ifdef __cplusplus
}
#endif

#endif /* __CORE_CM23_H_DEPENDANT */

#endif /* __CMSIS_GENERIC */
