/************************************************************************************
******************    @file   startup_stm32f401xx.c                 *****************
******************    @author Ehab Magdy Abdallah                   *****************
******************    @brief  Startup code for STM32F401xx Device   *****************
************************************************************************************/

typedef unsigned int uint32_t;
typedef void (*const PF_Handler)(void);

#define NULL (void*)(0) 

/* Symbols from LinkerScript file */
extern uint32_t _estack, _etext, _sidata, _sdata, _edata, _sbss, _ebss;

extern void main(void);

void Reset_Handler                     (void);
void NMI_Handler                       (void) __attribute__ ((weak, alias ("Default_Handler")));
void HardFault_Handler                 (void) __attribute__ ((weak, alias ("Default_Handler")));
void MemManage_Handler                 (void) __attribute__ ((weak, alias ("Default_Handler")));
void BusFault_Handler                  (void) __attribute__ ((weak, alias ("Default_Handler")));
void UsageFault_Handler                (void) __attribute__ ((weak, alias ("Default_Handler")));
void SVC_Handler                       (void) __attribute__ ((weak, alias ("Default_Handler")));
void DebugMon_Handler                  (void) __attribute__ ((weak, alias ("Default_Handler")));
void PendSV_Handler                    (void) __attribute__ ((weak, alias ("Default_Handler")));
void SysTick_Handler                   (void) __attribute__ ((weak, alias ("Default_Handler")));
void WWDG_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));                                        
void PVD_IRQHandler                    (void) __attribute__ ((weak, alias ("Default_Handler")));
void TAMP_STAMP_IRQHandler             (void) __attribute__ ((weak, alias ("Default_Handler")));
void RTC_WKUP_IRQHandler               (void) __attribute__ ((weak, alias ("Default_Handler")));
void FLASH_IRQHandler                  (void) __attribute__ ((weak, alias ("Default_Handler"))); 
void RCC_IRQHandler                    (void) __attribute__ ((weak, alias ("Default_Handler")));   
void EXTI0_IRQHandler                  (void) __attribute__ ((weak, alias ("Default_Handler")));
void EXTI1_IRQHandler                  (void) __attribute__ ((weak, alias ("Default_Handler")));
void EXTI2_IRQHandler                  (void) __attribute__ ((weak, alias ("Default_Handler")));
void EXTI3_IRQHandler                  (void) __attribute__ ((weak, alias ("Default_Handler")));
void EXTI4_IRQHandler                  (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream0_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream1_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream2_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream3_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream4_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream5_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream6_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC_IRQHandler                    (void) __attribute__ ((weak, alias ("Default_Handler")));
void EXTI9_5_IRQHandler                (void) __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler          (void) __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler          (void) __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler     (void) __attribute__ ((weak, alias ("Default_Handler")));
void TIM1_CC_IRQHandler                (void) __attribute__ ((weak, alias ("Default_Handler")));
void TIM2_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));
void TIM3_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));
void TIM4_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C1_EV_IRQHandler                (void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C1_ER_IRQHandler                (void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C2_EV_IRQHandler                (void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C2_ER_IRQHandler                (void) __attribute__ ((weak, alias ("Default_Handler")));
void SPI1_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));
void SPI2_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));
void USART1_IRQHandler                 (void) __attribute__ ((weak, alias ("Default_Handler")));
void USART2_IRQHandler                 (void) __attribute__ ((weak, alias ("Default_Handler")));
void EXTI15_10_IRQHandler              (void) __attribute__ ((weak, alias ("Default_Handler")));
void RTC_Alarm_IRQHandler              (void) __attribute__ ((weak, alias ("Default_Handler")));
void OTG_FS_WKUP_IRQHandler            (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA1_Stream7_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void SDIO_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));
void TIM5_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));
void SPI3_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream0_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream1_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream2_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream3_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream4_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void OTG_FS_IRQHandler                 (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream5_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream6_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA2_Stream7_IRQHandler           (void) __attribute__ ((weak, alias ("Default_Handler")));
void USART6_IRQHandler                 (void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C3_EV_IRQHandler                (void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C3_ER_IRQHandler                (void) __attribute__ ((weak, alias ("Default_Handler")));
void FPU_IRQHandler                    (void) __attribute__ ((weak, alias ("Default_Handler")));
void SPI4_IRQHandler                   (void) __attribute__ ((weak, alias ("Default_Handler")));

static void System_Intitialization(void);


/* Vector Table array of pointers to ISR <stored in ".isr_vector" section in start of flash > */
__attribute__((section(".isr_vector")))
PF_Handler vector_table[]  = {
    (PF_Handler)&_estack,                          /* Main Stack Pointer                        */
    (PF_Handler)Reset_Handler,                     /* Reset                                     */
    (PF_Handler)NMI_Handler,                       /* Non maskable interrupt                    */
    (PF_Handler)HardFault_Handler,                 /* All class of fault                        */
    (PF_Handler)MemManage_Handler,                 /* Memory management                         */
    (PF_Handler)BusFault_Handler,                  /* Pre-fetch fault, memory access fault      */ 
    (PF_Handler)UsageFault_Handler,                /* Undefined instruction or illegal state    */
    0,                                             /* Reserved                                  */
    0,                                             /* Reserved                                  */
    0,                                             /* Reserved                                  */
    0,                                             /* Reserved                                  */
    (PF_Handler)SVC_Handler,                       /* System service call via SWI instruction   */
    (PF_Handler)DebugMon_Handler,                  /* Debug Monitor                             */
    0,                                             /* Reserved                                  */
    (PF_Handler)PendSV_Handler,                    /* Pendable request for system service       */ 
    (PF_Handler)SysTick_Handler,                   /* System tick timer                         */

    /**************************                                    *******************************
    *********                       External Interrupts                                  ********/
   /**************************                                    *******************************
    (PF_Handler)WWDG_IRQHandler,                   /* Window WatchDog                           */                                        
    (PF_Handler)PVD_IRQHandler,                    /* PVD through EXTI Line detection           */                        
    (PF_Handler)TAMP_STAMP_IRQHandler,             /* Tamper and TimeStamps through the EXTI line */            
    (PF_Handler)RTC_WKUP_IRQHandler,               /* RTC Wakeup through the EXTI line          */                      
    (PF_Handler)FLASH_IRQHandler,                  /* FLASH                                     */                                          
    (PF_Handler)RCC_IRQHandler,                    /* RCC                                       */                                            
    (PF_Handler)EXTI0_IRQHandler,                  /* EXTI Line0                                */                        
    (PF_Handler)EXTI1_IRQHandler,                  /* EXTI Line1                                */                          
    (PF_Handler)EXTI2_IRQHandler,                  /* EXTI Line2                                */                          
    (PF_Handler)EXTI3_IRQHandler,                  /* EXTI Line3                                */                          
    (PF_Handler)EXTI4_IRQHandler,                  /* EXTI Line4                                */                          
    (PF_Handler)DMA1_Stream0_IRQHandler,           /* DMA1 Stream 0                             */                  
    (PF_Handler)DMA1_Stream1_IRQHandler,           /* DMA1 Stream 1                             */                   
    (PF_Handler)DMA1_Stream2_IRQHandler,           /* DMA1 Stream 2                             */                   
    (PF_Handler)DMA1_Stream3_IRQHandler,           /* DMA1 Stream 3                             */                   
    (PF_Handler)DMA1_Stream4_IRQHandler,           /* DMA1 Stream 4                             */                   
    (PF_Handler)DMA1_Stream5_IRQHandler,           /* DMA1 Stream 5                             */                   
    (PF_Handler)DMA1_Stream6_IRQHandler,           /* DMA1 Stream 6                             */                   
    (PF_Handler)ADC_IRQHandler,                    /* ADC1, ADC2 and ADC3s                      */   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                                        
    (PF_Handler)EXTI9_5_IRQHandler,                /* External Line[9:5]s                       */                          
    (PF_Handler)TIM1_BRK_TIM9_IRQHandler,          /* TIM1 Break and TIM9                       */         
    (PF_Handler)TIM1_UP_TIM10_IRQHandler,          /* TIM1 Update and TIM10                     */         
    (PF_Handler)TIM1_TRG_COM_TIM11_IRQHandler,     /* TIM1 Trigger and Commutation and TIM11    */
    (PF_Handler)TIM1_CC_IRQHandler,                /* TIM1 Capture Compare                      */                          
    (PF_Handler)TIM2_IRQHandler,                   /* TIM2                                      */                   
    (PF_Handler)TIM3_IRQHandler,                   /* TIM3                                      */                   
    (PF_Handler)TIM4_IRQHandler,                   /* TIM4                                      */                   
    (PF_Handler)I2C1_EV_IRQHandler,                /* I2C1 Event                                */                          
    (PF_Handler)I2C1_ER_IRQHandler,                /* I2C1 Error                                */                          
    (PF_Handler)I2C2_EV_IRQHandler,                /* I2C2 Event                                */                          
    (PF_Handler)I2C2_ER_IRQHandler,                /* I2C2 Error                                */                            
    (PF_Handler)SPI1_IRQHandler,                   /* SPI1                                      */                   
    (PF_Handler)SPI2_IRQHandler,                   /* SPI2                                      */                   
    (PF_Handler)USART1_IRQHandler,                 /* USART1                                    */                   
    (PF_Handler)USART2_IRQHandler,                 /* USART2                                    */ 
    0,                                             /* Reserved                                  */                                   
    (PF_Handler)EXTI15_10_IRQHandler,              /* External Line[15:10]s                     */                          
    (PF_Handler)RTC_Alarm_IRQHandler,              /* RTC Alarm (A and B) through EXTI Line     */                 
    (PF_Handler)OTG_FS_WKUP_IRQHandler,            /* USB OTG FS Wakeup through EXTI line       */
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                                        
    (PF_Handler)DMA1_Stream7_IRQHandler,           /* DMA1 Stream7                              */ 
    0,                                             /* Reserved                                  */                                          
    (PF_Handler)SDIO_IRQHandler,                   /* SDIO                                      */                   
    (PF_Handler)TIM5_IRQHandler,                   /* TIM5                                      */                   
    (PF_Handler)SPI3_IRQHandler,                   /* SPI3                                      */                         
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */
    (PF_Handler)DMA2_Stream0_IRQHandler,           /* DMA2 Stream 0                             */                   
    (PF_Handler)DMA2_Stream1_IRQHandler,           /* DMA2 Stream 1                             */                   
    (PF_Handler)DMA2_Stream2_IRQHandler,           /* DMA2 Stream 2                             */                   
    (PF_Handler)DMA2_Stream3_IRQHandler,           /* DMA2 Stream 3                             */                   
    (PF_Handler)DMA2_Stream4_IRQHandler,           /* DMA2 Stream 4                             */   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                         
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */
    (PF_Handler)OTG_FS_IRQHandler,                 /* USB OTG FS                                */                   
    (PF_Handler)DMA2_Stream5_IRQHandler,           /* DMA2 Stream 5                             */                   
    (PF_Handler)DMA2_Stream6_IRQHandler,           /* DMA2 Stream 6                             */                   
    (PF_Handler)DMA2_Stream7_IRQHandler,           /* DMA2 Stream 7                             */                   
    (PF_Handler)USART6_IRQHandler,                 /* USART6                                    */                    
    (PF_Handler)I2C3_EV_IRQHandler,                /* I2C3 event                                */                          
    (PF_Handler)I2C3_ER_IRQHandler,                /* I2C3 error                                */ 
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                         
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */                   
    0,                                             /* Reserved                                  */
    (PF_Handler)FPU_IRQHandler,                    /* FPU                                       */
    0,                                             /* Reserved                                  */
    0,                                             /* Reserved                                  */
    (PF_Handler)SPI4_IRQHandler                    /* SPI4                                      */   
};

void Reset_Handler(void)
{
    uint32_t SectionSize = 0;
    uint32_t* Src_SADDFlash = NULL;         /* Source start address in Flash       */
    uint32_t* Dest_SADDRam = NULL;          /* Destination start address in Flash  */

    /* Copy the data segment initializers from flash to SRAM */
    SectionSize = &_edata - &_sdata;        /* Length of .data segment */
    Src_SADDFlash = (uint32_t *)&_sidata;   /* Start address of .data sengement (LMA) -> Load Memory Address */
    Dest_SADDRam = (uint32_t *)&_sdata;     /* Start address of .data sengement (VMA) -> Virtual Memory Address */

    for(uint32_t ADDRCounter = 0 ; ADDRCounter < SectionSize ; ADDRCounter++)
    {
        *(Dest_SADDRam++) = *(Src_SADDFlash++);
    }

    /* Initialize the .bss segment with zeros */
    SectionSize = &_ebss - &_sbss;           /* Length of .bss segment */
    Dest_SADDRam = (uint32_t*)&_sbss;        /* Start address of .bss sengement */

    for(uint32_t ADDRCounter = 0 ; ADDRCounter < SectionSize ; ADDRCounter++)
    {
        *(Dest_SADDRam++) = 0;
    }

    /* Call the system intitialization function */
    System_Intitialization();

    /* Call main function */
    main();
}

static void System_Intitialization(void){}

void Default_Handler(void){}
