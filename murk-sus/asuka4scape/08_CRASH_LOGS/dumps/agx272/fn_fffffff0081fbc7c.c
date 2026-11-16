// FUN_fffffff0081fbc7c @ fffffff0081fbc7c size=200

uint FUN_fffffff0081fbc7c
               (undefined8 param_1,ulong param_2,uint param_3,int param_4,int param_5,int param_6,
               int param_7)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((param_2 >> 0x20 < 0x11) || (param_2 >> 0x21 < 9)) || (param_2 >> 0x20 < 0x13)) ||
     (((param_2 >> 0x24 < 7 || (param_2 < 0xffffff9fffe00000)) || (0xffffffa1893fffff < param_2))))
  {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  uVar3 = 3;
  if (param_5 != 0) {
    uVar3 = 1;
  }
  if (param_7 == 0 && !bVar2) {
    uVar3 = 0;
  }
  uVar4 = uVar3;
  if (param_6 == 0) {
    uVar4 = uVar3 | 8;
  }
  uVar3 = uVar3 | 4;
  if (4 < param_2 + 0x5e80000000 >> 0x16) {
    uVar3 = uVar4;
  }
  uVar4 = 0x300;
  if ((param_3 & 1) != 0) {
    uVar4 = 0x100;
  }
  uVar1 = 0;
  if (param_4 == 0) {
    uVar1 = uVar4;
  }
  return uVar3 | uVar1;
}

