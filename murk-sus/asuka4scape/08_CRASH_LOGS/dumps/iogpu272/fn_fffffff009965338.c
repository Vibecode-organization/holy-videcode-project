// FUN_fffffff009965338 @ fffffff009965338 size=500

void FUN_fffffff009965338(long param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  uint uVar8;
  int iVar9;
  long *plVar10;
  long *plVar11;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x110) != 0) {
    FUN_fffffff00994463c();
    lVar4 = *(long *)(param_1 + 0x110);
    uVar1 = *(uint *)(lVar4 + 0x28);
    if (1 < uVar1) {
      uVar8 = 1;
      do {
        lVar4 = FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x110),uVar8);
        if (lVar4 != 0) {
          FUN_fffffff00994508c(*(undefined8 *)(param_1 + 0x110),uVar8);
          FUN_fffffff00995b020();
        }
        uVar8 = uVar8 + 1;
      } while (uVar1 != uVar8);
      lVar4 = *(long *)(param_1 + 0x110);
    }
    FUN_fffffff009944648(lVar4);
  }
  if (*(long *)(param_1 + 0x88) != 0) {
    FUN_fffffff00994463c();
    lVar4 = *(long *)(param_1 + 0x88);
    iVar2 = *(int *)(lVar4 + 0x28);
    if (1 < iVar2) {
      iVar9 = 1;
      do {
        lVar4 = FUN_fffffff009945214(*(undefined8 *)(param_1 + 0x88),iVar9);
        if (lVar4 != 0) {
          FUN_fffffff00994508c(*(undefined8 *)(param_1 + 0x88),iVar9);
          FUN_fffffff00997684c();
        }
        iVar9 = iVar9 + 1;
      } while (iVar2 != iVar9);
      lVar4 = *(long *)(param_1 + 0x88);
    }
    FUN_fffffff009944648(lVar4);
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xe0));
  plVar10 = (long *)(param_1 + 0xe8);
  plVar5 = (long *)*plVar10;
  do {
    if (plVar5 == (long *)0x0) {
      *(undefined1 *)(param_1 + 0xfc) = 1;
      thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0xe0),param_1,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xe0));
      if (*(long *)(param_1 + 0x10) == 0) {
        return;
      }
      FUN_fffffff00994463c();
      lVar4 = *(long *)(param_1 + 0x10);
      uVar1 = *(uint *)(lVar4 + 0x28);
      if (1 < uVar1) {
        uVar8 = 1;
        do {
          plVar5 = (long *)FUN_fffffff00994508c(*(undefined8 *)(param_1 + 0x10),uVar8);
          if (plVar5 != (long *)0x0) {
            (**(code **)(*plVar5 + 0xb0))(plVar5,param_1);
          }
          uVar8 = uVar8 + 1;
        } while (uVar1 != uVar8);
        lVar4 = *(long *)(param_1 + 0x10);
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        FUN_fffffff009944648(lVar4);
        return;
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009965518);
      (*pcVar3)();
    }
    plVar11 = (long *)plVar5[0x28];
    plVar6 = (long *)*plVar10;
    if (plVar6 == plVar5) {
      lVar4 = plVar6[0x28];
      *plVar10 = lVar4;
      plVar6 = plVar10;
      if (lVar4 == 0) goto LAB_fffffff009965458;
    }
    else {
      do {
        plVar7 = plVar6;
        plVar6 = (long *)plVar7[0x28];
      } while (plVar6 != plVar5);
      lVar4 = plVar6[0x28];
      plVar7[0x28] = lVar4;
      if (lVar4 == 0) {
        plVar6 = plVar7 + 0x28;
LAB_fffffff009965458:
        *(long **)(param_1 + 0xf0) = plVar6;
      }
    }
    (**(code **)(*plVar5 + 0x28))();
    plVar5 = plVar11;
  } while( true );
}

