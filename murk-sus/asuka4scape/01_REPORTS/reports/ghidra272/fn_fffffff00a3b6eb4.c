// FUN_fffffff00a3b6eb4 @ fffffff00a3b6eb4 size=308

void FUN_fffffff00a3b6eb4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  int iVar1;
  long lVar2;
  undefined1 auVar3 [16];
  ulong uVar4;
  undefined1 extraout_q0 [16];
  undefined4 uVar5;
  undefined1 auVar6 [12];
  undefined4 uVar7;
  undefined1 auVar8 [12];
  undefined1 auVar9 [16];
  ulong local_40;
  uint local_38 [2];
  
  uVar7 = param_4._0_4_;
  auVar8 = param_4._4_12_;
  uVar5 = param_3._0_4_;
  auVar6 = param_3._4_12_;
  if (param_7[0x18] == 0) {
    local_40 = 0;
    auVar9 = FUN_fffffff00a2dcc04
                       ((long *)DAT_fffffff007c678d8,(ulong *)0x4000,(undefined ********)0x0,
                        (undefined ********)0x8080,(undefined ********)0x1c,0);
    auVar9._8_8_ = auVar9._8_8_;
    if (auVar9._0_4_ == 0) {
      local_38[1] = 3;
      local_38[0] = 3;
      uVar4 = FUN_fffffff00a2e902c
                        (*(undefined ******)(*param_7 + 0x10),&local_40,(undefined *****)0x4000,
                         (undefined *****)0x0,(ulong *****)0x1c100008,DAT_fffffff007c678d8,
                         (ulong)auVar9._8_8_,0,local_38 + 1,local_38,2);
      if ((int)uVar4 == 0) {
        lVar2 = tpidr_el1;
        *(int *)(lVar2 + 0x1c0) = *(int *)(lVar2 + 0x1c0) + 1;
        param_7[0x18] = (long)auVar9._8_8_;
        *(ulong *)(param_7[0x16] + 0x4158) = local_40;
        *(ulong *)(param_7[0x16] + 0x4120) = *(ulong *)(param_7[0x16] + 0x4120) | 0x40000000000000;
        if (*(int *)(lVar2 + 0x1c0) == 0) {
          auVar9._4_12_ = auVar6;
          auVar9._0_4_ = uVar5;
          auVar3._4_12_ = auVar8;
          auVar3._0_4_ = uVar7;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa5c868(extraout_q0,param_2,auVar9,auVar3,param_5,param_6);
        }
        iVar1 = *(int *)(lVar2 + 0x1c0) + -1;
        *(int *)(lVar2 + 0x1c0) = iVar1;
        if ((iVar1 == 0) && ((*(byte *)(*(long *)(lVar2 + 0x1b8) + 0x4c) >> 2 & 1) != 0)) {
          FUN_fffffff00a3976a4();
        }
      }
      else {
        FUN_fffffff00a2defc4
                  (extraout_q0,param_2,uVar5,uVar7,param_5,param_6,(uint *)DAT_fffffff007c678d8,
                   auVar9._8_8_,0x4000,0,(undefined **)0x0);
      }
    }
  }
  *(undefined1 *)(param_7 + 0x17) = 1;
  return;
}

