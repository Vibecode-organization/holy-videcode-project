// FUN_fffffff0081c305c @ fffffff0081c305c size=4

long * FUN_fffffff0081c305c(long param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  
  lVar10 = *(long *)(param_1 + 0x2c0);
  if (lVar10 == 0) {
    plVar1 = (long *)0x0;
  }
  else {
    plVar1 = (long *)thunk_EXT_FUN_801100000389d0d8(8);
    if (plVar1 != (long *)0x0) {
      plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar10 + 0x6a4c),0x20);
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar1 + 0x100))(plVar1,"imax_budget",plVar2);
      }
      plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined8 *)(lVar10 + 0x6a34),0x40);
      if (plVar3 != (long *)0x0) {
        (**(code **)(*plVar1 + 0x100))(plVar1,"lowest_trig_threshold",plVar3);
      }
      plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(8);
      if (plVar4 != (long *)0x0) {
        plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar10 + 0x6a50),0x20);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar10 + 0x6a54),0x20);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar10 + 0x6a58),0x20);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar10 + 0x6a5c),0x20);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar10 + 0x6a60),0x20);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar10 + 0x6a64),0x20);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar10 + 0x6a68),0x20);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar10 + 0x6a6c),0x20);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        (**(code **)(*plVar1 + 0x100))(plVar1,"downshift",plVar4);
      }
      plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(0x10);
      if (plVar5 != (long *)0x0) {
        lVar9 = 0;
        lVar11 = 0x10;
        do {
          plVar6 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined4 *)(lVar10 + 0x69f4 + lVar9 * 4),0x20);
          if (plVar6 != (long *)0x0) {
            (**(code **)(*plVar5 + 0xe8))(plVar5,plVar6);
            (**(code **)(*plVar6 + 0x28))(plVar6);
          }
          lVar9 = lVar9 + 1;
          lVar11 = lVar11 + -1;
        } while (lVar11 != 0);
        (**(code **)(*plVar1 + 0x100))(plVar1,"enabled_levels",plVar5);
      }
      plVar6 = (long *)thunk_EXT_FUN_80110000038961f4(0x80);
      if (plVar6 != (long *)0x0) {
        uVar13 = 0;
        lVar9 = lVar10 + 0x63f4;
        lVar11 = 0x10;
        do {
          uVar12 = uVar13 * 0x20;
          plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar9 + uVar12),0x20);
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar6 + 0xe8))(plVar6,plVar7);
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined4 *)
                                       (lVar9 + ((uVar13 & 0x3ffffffffffffff) << 5 | 4)),0x20);
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar6 + 0xe8))(plVar6,plVar7);
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined4 *)(lVar9 + (uVar12 | 8)),0x20);
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar6 + 0xe8))(plVar6,plVar7);
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined4 *)(lVar9 + (uVar12 | 0xc)),0x20);
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar6 + 0xe8))(plVar6,plVar7);
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined4 *)(lVar9 + (uVar12 | 0x10)),0x20);
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar6 + 0xe8))(plVar6,plVar7);
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined4 *)(lVar9 + (uVar12 | 0x14)),0x20);
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar6 + 0xe8))(plVar6,plVar7);
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined4 *)(lVar9 + (uVar12 | 0x18)),0x20);
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar6 + 0xe8))(plVar6,plVar7);
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined4 *)(lVar9 + (uVar12 | 0x1c)),0x20);
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar6 + 0xe8))(plVar6,plVar7);
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          uVar13 = uVar13 + 1;
          lVar11 = lVar11 + -1;
        } while (lVar11 != 0);
        (**(code **)(*plVar1 + 0x100))(plVar1,"thresholds_ma",plVar6);
      }
      plVar7 = (long *)thunk_EXT_FUN_80110000038961f4(0x80);
      if (plVar7 != (long *)0x0) {
        uVar13 = 0;
        lVar10 = lVar10 + 0x65f4;
        lVar9 = 0x10;
        do {
          uVar12 = uVar13 * 0x40;
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined8 *)(lVar10 + uVar12),0x40);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar7 + 0xe8))(plVar7,plVar8);
            (**(code **)(*plVar8 + 0x28))(plVar8);
          }
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined8 *)
                                       (lVar10 + ((uVar13 & 0x1ffffffffffffff) << 6 | 8)),0x40);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar7 + 0xe8))(plVar7,plVar8);
            (**(code **)(*plVar8 + 0x28))(plVar8);
          }
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined8 *)(lVar10 + (uVar12 | 0x10)),0x40);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar7 + 0xe8))(plVar7,plVar8);
            (**(code **)(*plVar8 + 0x28))(plVar8);
          }
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined8 *)(lVar10 + (uVar12 | 0x18)),0x40);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar7 + 0xe8))(plVar7,plVar8);
            (**(code **)(*plVar8 + 0x28))(plVar8);
          }
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined8 *)(lVar10 + (uVar12 | 0x20)),0x40);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar7 + 0xe8))(plVar7,plVar8);
            (**(code **)(*plVar8 + 0x28))(plVar8);
          }
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined8 *)(lVar10 + (uVar12 | 0x28)),0x40);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar7 + 0xe8))(plVar7,plVar8);
            (**(code **)(*plVar8 + 0x28))(plVar8);
          }
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined8 *)(lVar10 + (uVar12 | 0x30)),0x40);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar7 + 0xe8))(plVar7,plVar8);
            (**(code **)(*plVar8 + 0x28))(plVar8);
          }
          plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     (*(undefined8 *)(lVar10 + (uVar12 | 0x38)),0x40);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar7 + 0xe8))(plVar7,plVar8);
            (**(code **)(*plVar8 + 0x28))(plVar8);
          }
          uVar13 = uVar13 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        (**(code **)(*plVar1 + 0x100))(plVar1,"threshold_pF",plVar7);
        (**(code **)(*plVar7 + 0x28))(plVar7);
      }
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      if (plVar3 != (long *)0x0) {
        (**(code **)(*plVar3 + 0x28))();
      }
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
    }
  }
  return plVar1;
}

