MEMORY
{
  bootrom  (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00010000
  approm   (rx)  : ORIGIN = 0x00010000, LENGTH = 0x00004000
  ram      (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00004000
  eram     (rwx) : ORIGIN = 0x20004000, LENGTH = 0x00004000
}

__bootrom_start__ = ORIGIN(bootrom);
__bootrom_size__ = LENGTH(bootrom);
__approm_start__ = ORIGIN(approm);
__approm_size__ = LENGTH(approm);
__eram_start__ = ORIGIN(eram);
__eram_size__ = LENGTH(eram);
