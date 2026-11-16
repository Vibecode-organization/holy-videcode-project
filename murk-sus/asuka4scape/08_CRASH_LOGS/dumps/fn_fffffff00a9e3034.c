// FUN_fffffff00a9e3034 @ fffffff00a9e3034 size=468
// CALLERS:
//   fffffff00afbfada no-fn
//   fffffff00a9e2f34 FUN_fffffff00a9e2eb8@fffffff00a9e2eb8
//   fffffff00a9e327c FUN_fffffff00a9e3208@fffffff00a9e3208
// CALLEES:
//   fffffff00a22c2dc FUN_fffffff00a22c2dc
//   fffffff00a393464 FUN_fffffff00a393464
//   fffffff00a29bafc FUN_fffffff00a29bafc
//   fffffff00a22c478 FUN_fffffff00a22c478
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00aa61ed0 FUN_fffffff00aa61ed0

ulong FUN_fffffff00a9e3034
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                long param_8,undefined **param_9,ulong param_10,ulong param_11)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  undefined8 extraout_x1;
  long *plVar6;
  ulong uVar7;
  uint *puVar8;
  ulong uVar9;
  ulong uVar10;
  undefined1 auVar11 [16];
  undefined4 uVar12;
  undefined4 uVar13;
  
  uVar13 = param_4._0_4_;
  uVar12 = param_3._0_4_;
  lVar5 = tpidr_el1;
  uVar2 = daif;
  if (((uint)uVar2 >> 9 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114
              (param_1,param_2,param_3,param_4,param_5,param_6,
               (byte *)"%s: debug exceptions enabled in kernel mode @%s:%d");
  }
  plVar6 = *(long **)(param_7 + 0x30);
  if ((uVar2 & 0x1c0) != 0x1c0) {
    uVar9 = daif;
    daif = uVar9 | 0x1c0;
  }
  *(int *)(lVar5 + 0x1c0) = *(int *)(lVar5 + 0x1c0) + 1;
  if (*plVar6 == 0) {
    if (*plVar6 == 0) {
      *plVar6 = lVar5;
      goto LAB_fffffff00a9e3090;
    }
  }
  else {
    WaitForEvent();
  }
  param_9 = &PTR_s_hw_lock_t_fffffff007bc34b8;
  FUN_fffffff00a22c2dc(plVar6,lVar5,-0xff843cb48);
LAB_fffffff00a9e3090:
  uVar9 = *(long *)(param_7 + 0x20) - 1;
  if (uVar9 != 0) {
    uVar10 = *(ulong *)(param_7 + 0x28);
    uVar7 = uVar9;
    do {
      lVar3 = uVar10 * 0x38;
      if (*(long *)(*(long *)(param_7 + 0x18) + lVar3) == 0) {
        puVar8 = (uint *)(param_8 + 0x28);
        uVar4 = *puVar8;
        *puVar8 = uVar4 + 1;
        if (uVar4 + 0xf0000001 < 0xf0000002) {
LAB_fffffff00a9e3200:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa61ed0(puVar8);
        }
        *(long *)(*(long *)(param_7 + 0x18) + lVar3) = param_8;
        if ((*(byte *)(param_7 + 0x60) & 1) != 0) {
          lVar5 = FUN_fffffff00a29bafc(lVar5);
          if (lVar5 == 0) {
            lVar5 = 0;
          }
          else {
            lVar5 = *(long *)(lVar5 + 0x5d0);
          }
          puVar8 = (uint *)(lVar5 + 0x10);
          uVar4 = *puVar8;
          *puVar8 = uVar4 + 1;
          if (uVar4 + 0xf0000001 < 0xf0000002) goto LAB_fffffff00a9e3200;
          uVar9 = *(ulong *)(param_7 + 0x18) + lVar3;
          if (((*(ulong *)(param_7 + 0x18) ^ uVar9) & 0xffc0000000000000) != 0) {
            uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
          }
          *(long *)(uVar9 + 8) = lVar5;
        }
        uVar7 = *(long *)(param_7 + 0x20) - 1;
        uVar9 = 0;
        if (uVar7 != 0) {
          uVar9 = uVar10 / uVar7;
        }
        *(ulong *)(param_7 + 0x28) = (uVar10 - uVar9 * uVar7) + 1;
        goto LAB_fffffff00a9e3178;
      }
      uVar1 = 0;
      if (uVar9 != 0) {
        uVar1 = uVar10 / uVar9;
      }
      uVar10 = (uVar10 - uVar1 * uVar9) + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  uVar10 = 0;
LAB_fffffff00a9e3178:
  auVar11 = FUN_fffffff00a22c478(*(undefined8 **)(param_7 + 0x30));
  FUN_fffffff00a393464
            (auVar11,param_2,uVar12,uVar13,param_5,param_6,(ulong)((uVar2 & 0x1c0) != 0x1c0),
             extraout_x1,param_9,param_10,param_11);
  return uVar10;
}

