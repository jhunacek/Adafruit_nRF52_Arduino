/* Linker script to configure memory regions. */

SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
   /* 0x27000 reserved for s140 v7.2.0
	* 0x6D000 is top of application flash for 512k
	* 0x6D000 to 0x74000 is 28k for User Data
	* 0x74000 to 0x80000 is 48k for Bootloader
	* (See https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/hathach-memory-map)
	*/
  FLASH (rx)     : ORIGIN = 0x27000, LENGTH = 0x6D000 - 0x27000

  /* SRAM required by Softdevice depend on
   * - Attribute Table Size (Number of Services and Characteristics)
   * - Vendor UUID count
   * - Max ATT MTU
   * - Concurrent connection peripheral + central + secure links
   * - Event Len, HVN queue, Write CMD queue
   */ 
  /* 128k RAM from address 0x20000000 to 0x20020000 
   * Leaving 18k for soft device
   */
  RAM (rwx) :  ORIGIN = 0x20006000, LENGTH = 0x20020000 - 0x20006000
}

SECTIONS
{
  . = ALIGN(4);
  .svc_data :
  {
    PROVIDE(__start_svc_data = .);
    KEEP(*(.svc_data))
    PROVIDE(__stop_svc_data = .);
  } > RAM
  
  .fs_data :
  {
    PROVIDE(__start_fs_data = .);
    KEEP(*(.fs_data))
    PROVIDE(__stop_fs_data = .);
  } > RAM
} INSERT AFTER .data;

INCLUDE "nrf52_common.ld"
