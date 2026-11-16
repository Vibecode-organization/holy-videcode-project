// FUN_fffffff00a2d3720 @ fffffff00a2d3720 size=208

undefined8 FUN_fffffff00a2d3720(long param_1,undefined8 *param_2,long param_3,long param_4)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  if ((((param_3 != 0) && (param_4 != param_3)) && ((*(byte *)(param_4 + 0x75) & 0x14) == 0)) &&
     (((*(byte *)(param_4 + 0xa8) & 1) == 0 || (param_2 == &DAT_fffffff00ad6cc50)))) {
    lVar2 = FUN_fffffff00a29b24c();
    if (*(long *)(lVar2 + 0x18) == 0) {
      iVar1 = FUN_fffffff00a6ec3c0(DAT_fffffff007c6b250);
    }
    else {
      iVar1 = FUN_fffffff00a6ec3c0();
    }
    if (((iVar1 == 0) &&
        ((*(undefined8 **)(param_1 + 0x58) == (undefined8 *)0x0 ||
         (*(undefined8 **)(param_1 + 0x58) != &DAT_fffffff00ad6cc50)))) &&
       ((*(byte *)(param_1 + 0xfa) >> 2 & 1) == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    return uVar3;
  }
  return 0;
}

