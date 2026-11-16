// FUN_fffffff009ab4738 @ fffffff009ab4738 size=576
// CALLERS:
// CALLEES:
//   fffffff009abd7cc thunk_FUN_fffffff009c2a65c
//   fffffff009abd9ac thunk_FUN_fffffff009c223d4
//   fffffff009abdb7c thunk_FUN_fffffff00aa65b10
//   fffffff009abd82c thunk_FUN_fffffff009c2a3d0
//   fffffff009abd6dc thunk_FUN_fffffff00a8d2200
//   fffffff009abd32c thunk_FUN_fffffff00a8a10d8
//   fffffff009abd38c thunk_FUN_fffffff009c34224
//   fffffff009abd7ec thunk_FUN_fffffff009c2a3c4
//   fffffff009abdafc thunk_FUN_fffffff00aa65cc0
//   fffffff009abd7dc thunk_FUN_fffffff009c2a640
//   fffffff009ab0f98 FUN_fffffff009ab0f98
//   fffffff009abd13c thunk_FUN_fffffff00a9029a0
//   fffffff009abd87c thunk_FUN_fffffff009c1e624
//   fffffff009abd8fc thunk_FUN_fffffff009c2235c
//   fffffff009abd36c thunk_FUN_fffffff009c33c28

void FUN_fffffff009ab4738
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7)

{
  uint uVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  long *plVar12;
  long *plVar13;
  long *extraout_x0;
  ulong uVar14;
  long lVar15;
  char *pcVar16;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined1 auVar17 [16];
  undefined8 extraout_var_00;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined8 uVar22;
  undefined4 uVar23;
  undefined1 auVar24 [12];
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  uVar19 = param_2._8_8_;
  uVar18 = param_2._0_8_;
  uVar23 = param_4._0_4_;
  auVar24 = param_4._4_12_;
  uVar20 = param_3._0_4_;
  uVar21 = param_3._4_4_;
  uVar22 = param_3._8_8_;
  uVar1 = *(uint *)(param_7 + 0x1bf0);
  uVar2 = *(uint *)(param_7 + 0x1bf4);
  thunk_FUN_fffffff00aa65cc0((undefined8 *)(param_7 + 0x130),0x6e0);
  *(undefined8 *)(param_7 + 0x27c) = 0xffffffffffffffff;
  thunk_FUN_fffffff00aa65b10((undefined8 *)(param_7 + 0x810),(undefined8 *)(param_7 + 0x130),0x6e0);
  if (((*(byte *)(param_7 + 0x1cc0) & 1) != 0) && (uVar2 != 0 && uVar1 != 0)) {
    plVar12 = thunk_FUN_fffffff00a8a10d8(1);
    plVar13 = thunk_FUN_fffffff00a8d2200("PurpleGfxMem");
    auVar17._8_8_ = extraout_var;
    auVar17._0_8_ = extraout_d0;
    if (plVar13 != (long *)0x0) {
      (**(code **)(*plVar12 + 0x100))(plVar12,*(undefined8 *)PTR_PTR_fffffff00802a470,plVar13);
      auVar17 = (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    auVar4._8_8_ = uVar19;
    auVar4._0_8_ = uVar18;
    auVar7._4_4_ = uVar21;
    auVar7._0_4_ = uVar20;
    auVar7._8_8_ = uVar22;
    auVar9._4_12_ = auVar24;
    auVar9._0_4_ = uVar23;
    thunk_FUN_fffffff009c33c28
              (auVar17,auVar4,auVar7,auVar9,param_5,param_6,*(long *)(param_7 + 0x1b40),0,plVar12);
    (**(code **)(*plVar12 + 0x28))(plVar12);
    thunk_FUN_fffffff00aa65cc0((undefined8 *)(param_7 + 0xef0),0x5a8);
    if (extraout_x0 != (long *)0x0) {
      plVar12 = *(long **)(param_7 + 0x1d10);
      if (plVar12 == (long *)0x0) {
        if (*(long *)(param_7 + 0x1b40) == 0) {
          plVar12 = (long *)0x0;
        }
        else {
          plVar12 = (long *)thunk_FUN_fffffff009c34224(*(long *)(param_7 + 0x1b40),"PurpleGfxMem");
          *(long **)(param_7 + 0x1d10) = plVar12;
        }
      }
      thunk_FUN_fffffff009c2a3c4((long)extraout_x0,plVar12);
      auVar17 = thunk_FUN_fffffff009c2a640((long)extraout_x0,*(undefined4 *)(param_7 + 0x1c40));
      auVar5._8_8_ = uVar19;
      auVar5._0_8_ = uVar18;
      thunk_FUN_fffffff009c2a3d0
                (auVar17,auVar5,uVar20,uVar23,param_5,param_6,(long)extraout_x0,(long *)0x0);
      thunk_FUN_fffffff009c2a65c((long)extraout_x0,1);
      uStack_78 = *(undefined8 *)(param_7 + 0x1c78);
      uStack_80 = *(undefined8 *)*(undefined1 (*) [16])(param_7 + 0x1c70);
      uStack_68 = *(undefined8 *)(param_7 + 0x1c88);
      local_70 = *(undefined8 *)(param_7 + 0x1c80);
      uStack_58 = *(undefined8 *)(param_7 + 0x1c98);
      uStack_60 = *(undefined8 *)(param_7 + 0x1c90);
      uStack_48 = *(undefined8 *)(param_7 + 0x1ca8);
      local_50 = *(undefined8 *)(param_7 + 0x1ca0);
      uStack_a8 = *(undefined8 *)(param_7 + 0x1c48);
      local_b0 = *(undefined8 *)(param_7 + 0x1c40);
      uVar22 = *(undefined8 *)(param_7 + 0x1c58);
      uStack_a0 = *(undefined8 *)*(undefined1 (*) [16])(param_7 + 0x1c50);
      uVar20 = (undefined4)uStack_a0;
      uVar21 = (undefined4)((ulong)uStack_a0 >> 0x20);
      uVar19 = *(undefined8 *)(param_7 + 0x1c68);
      uVar18 = *(undefined8 *)*(undefined1 (*) [16])(param_7 + 0x1c60);
      auVar10._4_12_ = auVar24;
      auVar10._0_4_ = uVar23;
      uStack_98 = uVar22;
      local_90 = uVar18;
      uStack_88 = uVar19;
      uVar14 = FUN_fffffff009ab0f98
                         (*(undefined1 (*) [16])(param_7 + 0x1c70),
                          *(undefined1 (*) [16])(param_7 + 0x1c60),
                          *(undefined1 (*) [16])(param_7 + 0x1c50),auVar10,param_5,param_6,
                          (long)extraout_x0,(ulong)uVar1,uVar2,(undefined4 *)&local_b0);
      if ((int)uVar14 == 0) {
        thunk_FUN_fffffff009c2235c((long)extraout_x0);
        pcVar16 = "IOMFB: %s : layout_buffers - failed for Surface = 0x%p, sid = %d\n";
      }
      else {
        auVar3._8_8_ = extraout_var_00;
        auVar3._0_8_ = extraout_d0_00;
        auVar6._8_8_ = uVar19;
        auVar6._0_8_ = uVar18;
        auVar8._4_4_ = uVar21;
        auVar8._0_4_ = uVar20;
        auVar8._8_8_ = uVar22;
        auVar11._4_12_ = auVar24;
        auVar11._0_4_ = uVar23;
        thunk_FUN_fffffff009c1e624(auVar3,auVar6,auVar8,auVar11,param_5,param_6,extraout_x0);
        lVar15 = thunk_FUN_fffffff009c223d4((long)extraout_x0);
        if (lVar15 != 0) {
          *(long **)(param_7 + 0x1b60) = extraout_x0;
          return;
        }
        thunk_FUN_fffffff009c2235c((long)extraout_x0);
        pcVar16 = "IOMFB: %s : getMemoryRegion Failed for Surface = 0x%p, sid = %d\n";
      }
      thunk_FUN_fffffff00a9029a0((byte *)pcVar16);
    }
  }
  return;
}

