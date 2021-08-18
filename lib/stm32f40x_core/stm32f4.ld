/* memory defs */

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
  CCM (rwx) : ORIGIN =  0x10000000, LENGTH = 64K
}

_stack_size_    = 16K;

_rom_start_     = ORIGIN(FLASH);
_rom_size_      = LENGTH(FLASH);
_ram_start_     = ORIGIN(RAM);
_ram_size_      = LENGTH(RAM);
_ram_end_       = _ram_start_ + _ram_size_;
_stack_end_     = _ram_end_;
_stack_start_   = _stack_end_ - _stack_size_;
_heap_start_    = _bss_end_;
_heap_end_      = _stack_start_;
_ccm_start_     = ORIGIN(CCM);
_ccm_size_      = LENGTH(CCM);
end             = _heap_start_;


SECTIONS
{
  . = 0;
  .text : {
    KEEP(*(.startup))         /* Startup code */
    *(.text*)                 /* Program code */
    KEEP(*(.rodata*))         /* Read only data */
    *(.glue_7)
    *(.glue_7t)
    *(.eh_frame)
    . = ALIGN(4);
    _ctors_start_ = .;
    KEEP(*(.init_array))      /* C++ constructors */
    KEEP(*(.ctors))           /* C++ constructors */
    _ctors_end_ = .;
    . = ALIGN(16);
    _text_end_ = .;
  } > FLASH

  .data : ALIGN(16) {
    _data_start_ = .;
    *(.data*)
    _data_end_ = .;
  } > RAM AT > FLASH


  .bss (NOLOAD) : ALIGN(16) {
    _bss_start_ = .;
    *(.bss*)
    *(COMMON)
    _bss_end_ = .;
  } > RAM


}

ENTRY(_vectors)
