// FUN_fffffff00996da88 @ fffffff00996da88 size=204

undefined8 FUN_fffffff00996da88(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  
  lVar1 = thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff0b28);
  lVar2 = FUN_fffffff00994e8dc();
  uVar3 = 0;
  if (lVar2 != 0) {
    *(undefined8 *)(lVar1 + 0x48) = param_2;
    lVar2 = (**(code **)(**(long **)(param_1 + 0x10) + 0x5f0))
                      (*(long **)(param_1 + 0x10),param_2,param_3,param_1);
    *(long *)(lVar1 + 0x40) = lVar2;
    if (lVar2 == 0) {
      thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff0ae8,lVar1);
      uVar3 = 0;
    }
    else {
      *(undefined8 *)(lVar1 + 0x50) = 0;
      plVar4 = *(long **)(param_1 + 0x40);
      *(long **)(lVar1 + 0x58) = plVar4;
      *plVar4 = lVar1;
      *(undefined8 **)(param_1 + 0x40) = (undefined8 *)(lVar1 + 0x50);
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
      uVar3 = 1;
    }
  }
  return uVar3;
}

