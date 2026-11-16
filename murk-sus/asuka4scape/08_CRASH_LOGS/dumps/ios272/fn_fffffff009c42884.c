// FUN_fffffff009c42884 @ fffffff009c42884 size=352

undefined8 FUN_fffffff009c42884(long param_1,long *param_2)

{
  int iVar1;
  bool bVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  long *plVar7;
  undefined8 *puVar8;
  
  plVar7 = (long *)param_2[3];
  if (plVar7 != (long *)0x0) {
    (**(code **)(*plVar7 + 0x20))(plVar7);
  }
  uVar3 = (**(code **)(*plVar7 + 0xb0))(plVar7);
  iVar1 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f);
  (**(code **)(*plVar7 + 0x28))(plVar7);
  if ((ulong)(long)iVar1 <= uVar3) {
    puVar8 = (undefined8 *)(param_1 + 0x40);
    uVar4 = 0xffffffff;
    uVar5 = 0;
    if ((long)iVar1 != 0) {
      uVar5 = uVar3 / (ulong)(long)iVar1;
    }
    do {
      uVar4 = uVar4 + 1;
      puVar8 = puVar8 + 1;
      bVar2 = 1 < uVar5;
      uVar5 = uVar5 >> 1;
    } while (bVar2);
    if (uVar4 < 0xb) {
      if ((*(byte *)(param_1 + 0xa0) & 1) != 0) {
        FUN_fffffff009c4346c(param_2);
      }
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x40));
      (**(code **)(*(long *)*puVar8 + 0xe8))((long *)*puVar8,param_2);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x40));
      uVar6 = 1;
      goto LAB_fffffff009c429ac;
    }
  }
  uVar6 = 0;
LAB_fffffff009c429ac:
  (**(code **)(*param_2 + 0x28))(param_2);
  return uVar6;
}

