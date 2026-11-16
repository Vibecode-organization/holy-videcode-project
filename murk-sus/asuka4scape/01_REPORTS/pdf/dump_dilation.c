/* ==== FUN_183b65c8c @ 183b65c8c size=160 ==== */

undefined4 FUN_183b65c8c(long param_1)

{
  long *plVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  
  uVar2 = 0;
  if (param_1 != 0) {
    plVar1 = (long *)(param_1 + 0x28);
    lVar4 = *plVar1;
    if (*plVar1 == 0) {
      lVar3 = func_0x000188138460(1,0x70,0x10000400ac616f7);
      (**(code **)(*(long *)(param_1 + 0x10) + 0x70))(*(undefined8 *)(param_1 + 0x70),lVar3);
      lVar4 = *plVar1;
      if (lVar4 == 0) {
        *plVar1 = lVar3;
        lVar4 = lVar3;
      }
      else {
        func_0x000188138390(lVar3);
      }
    }
    if (lVar4 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(lVar4 + 8);
    }
  }
  return uVar2;
}



