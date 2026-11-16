// FUN_fffffff0081df034 @ fffffff0081df034 size=84

uint FUN_fffffff0081df034(uint *param_1)

{
  long lVar1;
  
  lVar1 = 10;
  if ((*(byte *)((long)param_1 + 9) & 1) == 0) {
    lVar1 = 8;
  }
  return ((byte)param_1[1] & 0x30) << 0xe | (*(byte *)((long)param_1 + 5) & 3) << 0x14 |
         (*(byte *)((long)param_1 + 6) & 1) << 0x16 | (uint)*(byte *)((long)param_1 + lVar1) << 0x17
         | (uint)*(byte *)((long)param_1 + 9) << 0x1f |
         *param_1 >> 3 & 0x3fff | (*(byte *)((long)param_1 + 0xe) & 0xf) << 0xe;
}

