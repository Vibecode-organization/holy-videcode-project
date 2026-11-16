// FUN_fffffff0082119b4 @ fffffff0082119b4 size=76

ulong FUN_fffffff0082119b4
                (undefined8 param_1,int param_2,ulong param_3,ulong param_4,ulong param_5,
                long param_6,uint param_7)

{
  ulong uVar1;
  
  uVar1 = 0xc03;
  if (param_2 != 0) {
    uVar1 = 0x403;
  }
  return uVar1 | (param_4 & 0x7e1) << 0x35 | (param_3 & 0xffffffcf) << 6 | (param_5 & 0x3f1) << 0x36
         | param_6 << 0x37 | (ulong)param_7 << 2;
}

