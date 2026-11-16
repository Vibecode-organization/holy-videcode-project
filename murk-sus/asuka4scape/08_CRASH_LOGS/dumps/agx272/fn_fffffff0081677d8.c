// FUN_fffffff0081677d8 @ fffffff0081677d8 size=564

/* WARNING: Removing unreachable block (ram,0xfffffff00816798c) */

void FUN_fffffff0081677d8(long *param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  
  if ((*(byte *)((long)param_1 + 0x1112c) >> 1 & 1) == 0) {
    return;
  }
  lVar1 = (**(code **)(DAT_fffffff00ae22f20 + 0x68))();
  *(undefined8 *)(lVar1 + 0x10) = *(undefined8 *)PTR_DAT_fffffff007ca61d0;
  FUN_fffffff0081e07cc(lVar1,param_1,0x200,0x100023);
  lVar2 = thunk_EXT_FUN_8011000002971b4c(param_1);
  plVar3 = *(long **)(lVar1 + 0x58);
  if (plVar3 == (long *)0x0) {
    plVar3 = (long *)(**(code **)(**(long **)(lVar1 + 0x48) + 0x90))
                               (*(long **)(lVar1 + 0x48),lVar2,0x500000085);
    lVar4 = 0;
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x20))();
      (**(code **)(*plVar3 + 0x28))(plVar3);
      *(long **)(lVar1 + 0x58) = plVar3;
      goto LAB_fffffff0081678dc;
    }
  }
  else {
LAB_fffffff0081678dc:
    if (plVar3[4] != lVar2) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Attempting to map into multiple GPU Contexts!\n");
      return;
    }
    lVar4 = (**(code **)(*plVar3 + 0x98))();
  }
  param_1[0x359a] = lVar4;
  plVar3 = *(long **)(lVar1 + 0x60);
  if (plVar3 == (long *)0x0) {
    lVar4 = thunk_EXT_FUN_801100000297ea14(*(undefined8 *)(lVar1 + 0x48),0);
    *(long *)(lVar1 + 0x60) = lVar4;
    lVar2 = 0;
    if (lVar4 == 0) goto LAB_fffffff00816795c;
    LOAcquire();
    DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + *(long *)(lVar1 + 0x30);
    LORelease();
    plVar3 = *(long **)(lVar1 + 0x60);
  }
  lVar2 = (**(code **)(*plVar3 + 0x78))();
LAB_fffffff00816795c:
  param_1[0x359b] = lVar2;
  param_1[0x3599] = lVar1;
  FUN_fffffff0081e0b20(lVar1);
  uVar5 = (**(code **)(*param_1 + 0x778))(*param_1 + 0x778,param_1);
  uVar6 = -(uVar5 >> 0x1f & 1) & 0xfffffff000000000 | (uVar5 & 0xffffffff) << 4;
  if (0x7fffffff < (uint)uVar5) {
    uVar6 = 0x8000000000000000;
  }
  lVar1 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca2b68,uVar6);
  param_1[0x359d] = lVar1;
  lVar1 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x359c] = lVar1;
  return;
}

