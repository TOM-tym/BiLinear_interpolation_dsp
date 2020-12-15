/****************************************************************************/
/*  DM642.cmd                                                               */
/*  Copyright (c) 2012  Texas Instruments Incorporated                      */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on a DM642.              */
/*                 Use it as a guideline.  You will want to                 */
/*                 change the memory layout to match your specific          */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/****************************************************************************/

MEMORY
{
    IRAM:          o = 0x00000000  l = 0x00500000  /* 5MB Internal RAM (L2) */
    EMIFA_CS0:     o = 0x80000000  l = 0x10000000  /* 256MB EMIFA CE0 */
    EMIFA_CS1:     o = 0x90000000  l = 0x10000000  /* 256MB EMIFA CE1 */
    EMIFA_CS2:     o = 0xA0000000  l = 0x10000000  /* 256MB EMIFA CE2 */
    EMIFA_CS3:     o = 0xB0000000  l = 0x10000000  /* 256MB EMIFA CE3 */
} 

SECTIONS
{
    .text          >  IRAM
    .stack         >  IRAM
    .bss           >  IRAM
    .cio           >  IRAM
    .const         >  IRAM
    .data          >  IRAM
    .switch        >  IRAM
    .sysmem        >  IRAM
    .far           >  IRAM
    .args          >  IRAM
    .ppinfo        >  IRAM
    .ppdata        >  IRAM
  
    /* TI-ABI or COFF sections */
    .pinit         >  IRAM
    .cinit         >  IRAM
  
    /* EABI sections */
    .binit         >  IRAM
    .init_array    >  IRAM
    .neardata      >  IRAM
    .fardata       >  IRAM
    .rodata        >  IRAM
    .c6xabi.exidx  >  IRAM
    .c6xabi.extab  >  IRAM
}

