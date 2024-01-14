/************************************************************************************
******************    @file   LinkerScript.ld                       *****************
******************    @author Ehab Magdy Abdallah                   *****************
******************    @brief  Linker script for STM32F401xx Device  *****************
************************************************************************************/

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM); /* (Start address of stack "Descending") End of "RAM" Ram type memory */

_Min_Heap_Size = 0x200 ;  /* Required amount of heap */
_Min_Stack_Size = 0x400 ; /* Required amount of stack */

/* Memories definition -> Label_Name(AttributeList) : ORIGIN = StartMemoryAddress,   LENGTH = MemoryLength 
        r -> read only section
        w -> read/write section
        r -> section containing excuatable code
*/
MEMORY
{
    RAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 64K
    FLASH  (rx)     : ORIGIN = 0x08000000,   LENGTH = 256K
}

/* Sections */
SECTIONS
{
    /* .isr_vector section, Interrupt Vector Table to start of "FLASH" */
    .isr_vector :
    {
        . = ALIGN(4); 
        *(.isr_vector)
        . = ALIGN(4);
    } >FLASH
    /* .text section, The program code and other data into "FLASH" */
    .text :
    {
        /* . =  0x08000000 (Start address of flash) */
        . = ALIGN(4);      /* Alignment by 4 -> each var stored in 4 bytes (evan if short + char would take 8 bytes) */
        *(.text)           /* .text sections (code) */
        *(.text*)          /* .text* (.text_ehab, .text_anything) sections (code) */
        . = ALIGN(4);      /* Alignment by 4 -> each var stored in 4 bytes (evan if short + char would take 8 bytes) */
        _etext = .;        /* Define a global symbols at end of text (. = 0x08000000 + *(.text) + *(.text*)) */
    } >FLASH

    /* .rodata section, Constant data into "FLASH" */
    .rodata :
    {
        /* . =  0x08000000 (Start address of flash) */
        . = ALIGN(4);      /* Alignment by 4 -> each var stored in 4 bytes (evan if short + char would take 8 bytes) */
        *(.rodata)         /* .rodata sections (constants, strings, etc.) */
        *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
        . = ALIGN(4);      /* Alignment by 4 -> each var stored in 4 bytes (evan if short + char would take 8 bytes) */
    } >FLASH

    /* Start address of .data segment in "Flash" memory */
    _sidata = LOADADDR(.data);

    /* .data section, Initialized data sections into "RAM" */
    .data :
    {
        . = ALIGN(4);      /* Alignment by 4 -> each var stored in 4 bytes (evan if short + char would take 8 bytes) */
        _sdata = .;        /* Create a global symbol at data start in "RAM" */
        *(.data)           /* .data sections */
        *(.data*)          /* .data* sections */
        . = ALIGN(4);      /* Alignment by 4 -> each var stored in 4 bytes (evan if short + char would take 8 bytes) */
        _edata = .;        /* Define a global symbol at data end in "RAM" */
    } >RAM AT> FLASH

    /* .bss section, Uninitialized data section into "RAM" */
    .bss :
    {
        _sbss = .;         /* Define a global symbol at bss start */
        *(.bss)            /* .bss sections */
        *(.bss*)           /* .bss* sections */
        . = ALIGN(4);      /* Alignment by 4 -> each var stored in 4 bytes (evan if short + char would take 8 bytes) */
        _ebss = .;         /* Define a global symbol at bss end */
    } >RAM

    /* .User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
    ._user_heap_stack :
    {
        . = ALIGN(8); 
        . = . + _Min_Heap_Size;
        . = . + _Min_Stack_Size;
        . = ALIGN(8);      
    } >RAM
}
