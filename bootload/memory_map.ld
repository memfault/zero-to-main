MEMORY
{
  bootrom  (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00010000
  approm   (rx)  : ORIGIN = 0x00010000, LENGTH = 0x00030000
  ram      (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000
}

