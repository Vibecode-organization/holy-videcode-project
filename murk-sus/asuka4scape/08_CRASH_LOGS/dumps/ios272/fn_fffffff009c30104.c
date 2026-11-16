// FUN_fffffff009c30104 @ fffffff009c30104 size=460

void FUN_fffffff009c30104(long param_1,undefined8 param_2)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  undefined1 *local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  local_50 = &DAT_aaaaaaaaaaaaaaaa;
  (*DAT_fffffff008067b90)();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  FUN_fffffff009c302d0(param_2,"Size",*(undefined8 *)(param_1 + 0x48));
  lVar6 = *(long *)(param_1 + 0x48);
  lVar4 = (**(code **)(**(long **)(param_1 + 0x30) + 0xa8))();
  FUN_fffffff009c302d0(param_2,"Allocated",lVar6 - lVar4);
  uVar5 = (**(code **)(**(long **)(param_1 + 0x30) + 0xa8))();
  FUN_fffffff009c302d0(param_2,"Free",uVar5);
  puVar2 = PTR_DAT_fffffff00806ca78;
  if (*(ulong *)PTR_DAT_fffffff00806ca78 < 0x80000001) {
    uVar8 = 0;
    uVar7 = 0x80000000;
    do {
      uVar1 = (uint)uVar7 | uVar8;
      iVar3 = (**(code **)(**(long **)(param_1 + 0x30) + 0xb0))
                        (*(long **)(param_1 + 0x30),uVar1,&local_50,0);
      if (iVar3 == 0) {
        uVar8 = uVar8 & ((uint)uVar7 ^ 0xffffffff);
      }
      else {
        (**(code **)(**(long **)(param_1 + 0x30) + 0xc0))(*(long **)(param_1 + 0x30),local_50,uVar1)
        ;
        uVar8 = uVar1;
      }
      uVar7 = uVar7 >> 1;
    } while (*(ulong *)puVar2 <= uVar7);
  }
  else {
    uVar8 = 0;
  }
  FUN_fffffff009c302d0(param_2,"LargestFree",uVar8);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_48) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

