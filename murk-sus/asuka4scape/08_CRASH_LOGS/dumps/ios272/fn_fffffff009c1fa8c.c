// FUN_fffffff009c1fa8c @ fffffff009c1fa8c size=188

/* WARNING: Removing unreachable block (ram,0xfffffff009c1fb24) */

void FUN_fffffff009c1fa8c(long param_1)

{
  uint uVar1;
  ulong uVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  
  uVar2 = param_1 + 0x1b0;
  if ((param_1 + 0x210U < uVar2) || ((param_1 + 0x210U) - uVar2 >> 0x20 != 0)) {
    lVar5 = FUN_fffffff009c48f64();
    if (*(long **)(lVar5 + 0x3c0) != (long *)0x0) {
      (**(code **)(**(long **)(lVar5 + 0x3c0) + 0x28))();
      *(undefined8 *)(lVar5 + 0x3c0) = 0;
    }
    if (*(long *)(lVar5 + 0x30) != 0) {
      if (-1 < *(char *)(lVar5 + 0x3d2)) {
        FUN_fffffff009c3760c(DAT_fffffff00af483b0);
      }
      FUN_fffffff009c22140(lVar5);
      plVar3 = *(long **)(lVar5 + 0x30);
      if (plVar3 != (long *)0x0) {
        (**(code **)(*plVar3 + 0x50))(plVar3,*(undefined8 *)PTR_DAT_fffffff00806c9c0);
      }
      *(undefined8 *)(lVar5 + 0x30) = 0;
      thunk_EXT_FUN_80110000036da494(0x540000c,*(undefined4 *)(lVar5 + 0x10),0,0,0,0);
    }
    plVar3 = *(long **)(lVar5 + 0x28);
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x88))(plVar3,lVar5);
      if (*(long **)(lVar5 + 0x28) != (long *)0x0) {
        (**(code **)(**(long **)(lVar5 + 0x28) + 0x28))();
      }
      *(undefined8 *)(lVar5 + 0x28) = 0;
    }
    return;
  }
  uVar6 = 0;
  do {
    plVar3 = (long *)(uVar2 + uVar6);
    uVar4 = -(ulong)CARRY8(uVar2,uVar6);
    if ((uVar4 != CARRY8(uVar2,uVar6)) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50();
    }
    if ((*plVar3 != 0) && (plVar3[1] != 0)) {
      thunk_EXT_FUN_80110000038fe6b0();
      *plVar3 = 0;
      plVar3[1] = 0;
    }
    uVar1 = (int)uVar6 + 0x10;
    uVar6 = (ulong)uVar1;
  } while (uVar1 != 0x60);
  lVar5 = *(long *)(param_1 + 0x178);
  if ((lVar5 != 0) && (lVar5 != 0)) {
    *(undefined1 *)(lVar5 + 0x2f) = 0;
  }
  return;
}

