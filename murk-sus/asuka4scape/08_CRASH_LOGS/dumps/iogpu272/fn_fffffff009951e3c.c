// FUN_fffffff009951e3c @ fffffff009951e3c size=280

ulong FUN_fffffff009951e3c
                (long param_1,long param_2,undefined8 param_3,undefined8 param_4,ulong param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long *plVar4;
  
  uVar3 = param_3;
  if ((param_5 & 0x1000) != 0) {
    uVar3 = 0;
  }
  lVar1 = thunk_EXT_FUN_80110000039629d0(uVar3,0x10060,param_4,1,0,100);
  *(long *)(param_1 + 0x40) = lVar1;
  uVar2 = 0;
  if (lVar1 != 0) {
    thunk_EXT_FUN_8011000003977b2c(lVar1,param_3,4,0);
    plVar4 = *(long **)(param_1 + 0x40);
    uVar2 = (*DAT_fffffff007feb260)(param_1);
    if ((((int)uVar2 != 0) && (uVar2 = 0, param_2 != 0)) && (plVar4 != (long *)0x0)) {
      *(long *)(param_1 + 0x20) = param_2;
      (**(code **)(*plVar4 + 0x20))(plVar4);
      *(long **)(param_1 + 0x28) = plVar4;
      lVar1 = thunk_EXT_FUN_801100000396cb64(*(undefined8 *)(param_1 + 0x40),param_3,0,param_5,0,0);
      *(long *)(param_1 + 0x48) = lVar1;
      uVar2 = 0;
      if (lVar1 != 0) {
        uVar3 = thunk_EXT_FUN_8011000003977d8c(*(undefined8 *)(param_1 + 0x28),0);
        *(undefined8 *)(param_1 + 0x58) = uVar3;
        lVar1 = thunk_EXT_FUN_80110000038ff134();
        *(long *)(param_1 + 0x60) = lVar1;
        uVar2 = (ulong)(lVar1 != 0);
      }
    }
  }
  return uVar2;
}

