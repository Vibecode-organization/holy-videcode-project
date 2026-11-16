// FUN_fffffff009c722d0 @ fffffff009c722d0

undefined8
FUN_fffffff009c722d0
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7)

{
  long *plVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  long extraout_x0;
  undefined8 extraout_x0_00;
  undefined8 extraout_x0_01;
  long extraout_x1;
  ulong uVar8;
  undefined8 *puVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  undefined8 uVar14;
  ulong *puVar15;
  undefined8 extraout_d0;
  undefined1 auVar16 [16];
  undefined8 extraout_var;
  undefined4 uVar17;
  undefined1 auVar18 [12];
  undefined4 uVar19;
  undefined1 auVar20 [12];
  long local_a0 [9];
  long local_58;
  
  uVar19 = param_4._0_4_;
  auVar20 = param_4._4_12_;
  uVar17 = param_3._0_4_;
  auVar18 = param_3._4_12_;
  auVar16 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x28));
  puVar9 = *(undefined8 **)(param_7 + 0x18);
  if ((*(byte *)(param_7 + 0xf0) & 1) == 0) {
    if (puVar9 == (undefined8 *)0x0) {
      FUN_fffffff009c7d328(auVar16,param_2,uVar17,uVar19,param_5,param_6);
      uVar14 = 0;
      goto LAB_fffffff009c72334;
    }
  }
  else if (puVar9 == (undefined8 *)0x0) {
    auVar4._4_12_ = auVar18;
    auVar4._0_4_ = uVar17;
    auVar6._4_12_ = auVar20;
    auVar6._0_4_ = uVar19;
    FUN_fffffff009c7d2b8(auVar16,param_2,auVar4,auVar6,param_5,param_6);
    local_58 = *(long *)PTR_DAT_fffffff00807b630;
    if (extraout_x1 == 0) {
      auVar16._8_8_ = extraout_var;
      auVar16._0_8_ = extraout_d0;
      FUN_fffffff009c7d408(auVar16,param_2,uVar17,uVar19,param_5,param_6);
      uVar14 = extraout_x0_00;
    }
    else {
      uVar10 = *(ulong *)(extraout_x1 + 8);
      if (uVar10 < *(ulong *)(extraout_x0 + 0x30)) {
        local_a0[5] = 0;
        local_a0[4] = 0;
        local_a0[7] = 0;
        local_a0[6] = 0;
        local_a0[1] = 0;
        local_a0[0] = 0;
        local_a0[3] = 0;
        local_a0[2] = 0;
        lVar11 = uVar10 * 0x18;
        uVar2 = *(long *)(extraout_x0 + 0x10) + (long)(int)lVar11;
        if (lVar11 - (int)lVar11 != 0) {
          uVar2 = *(long *)(extraout_x0 + 0x10) + lVar11 & 0xffffffffffffU | 0x2bad000000000000;
        }
        *(undefined8 *)(uVar2 + 8) = 0;
        uVar8 = (ulong)*(byte *)(extraout_x0 + 0x40);
        if (uVar8 != 0) {
          lVar11 = 0;
          uVar12 = uVar8;
          do {
            lVar13 = *(long *)(extraout_x0 + 0x48 + lVar11 * 8);
            local_a0[lVar11 * 2] = lVar13 * uVar10;
            local_a0[lVar11 * 2 + 1] = lVar13;
            lVar11 = lVar11 + 1;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        FUN_fffffff009c64250
                  (ZEXT816(0),param_2,uVar17,uVar19,param_5,param_6,extraout_x1,local_a0,uVar8);
        puVar15 = (ulong *)(extraout_x0 + 0x28);
        auVar16 = thunk_FUN_fffffff00a2262a8(*puVar15);
        if ((*(byte *)(uVar2 + 0x10) & 1) == 0) {
          if ((*(byte *)(extraout_x0 + 0xf1) & 1) != 0) {
            auVar5._4_12_ = auVar18;
            auVar5._0_4_ = uVar17;
            auVar7._4_12_ = auVar20;
            auVar7._0_4_ = uVar19;
                    /* WARNING: Subroutine does not return */
            thunk_FUN_fffffff00aa4d114
                      (auVar16,param_2,auVar5,auVar7,param_5,param_6,
                       (byte *)
                       "\"INTERNAL PANIC: Double complete of TSNPacket at index %lu, num outstanding: %llu\" @%s:%d"
                      );
          }
          auVar16 = thunk_FUN_fffffff00a8df19c
                              (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,
                               (short *)PTR_DAT_fffffff00807b638,0,
                               (byte *)
                               "TSNPacketPool ERROR: Double complete of TSNPacket at index %lu, num outstanding: %llu"
                              );
          if ((*(byte *)(uVar2 + 0x10) & 1) == 0) {
            uVar14 = FUN_fffffff009c7d3b0(auVar16,param_2,uVar17,uVar19,param_5,param_6,puVar15);
            goto LAB_fffffff009c7249c;
          }
        }
        *(undefined1 *)(uVar2 + 0x10) = 0;
        if (*(long *)(extraout_x0 + 0x20) == 0) {
          *(ulong *)(extraout_x0 + 0x18) = uVar2;
        }
        else {
          *(ulong *)(*(long *)(extraout_x0 + 0x20) + 8) = uVar2;
        }
        *(ulong *)(extraout_x0 + 0x20) = uVar2;
        plVar1 = (long *)(extraout_x0 + 0xb8);
        *plVar1 = *plVar1 + -1;
        if (*(long *)(extraout_x0 + 0xb8) == 0) {
          thunk_FUN_fffffff00a24a024((long)plVar1,0,0);
        }
        uVar14 = thunk_FUN_fffffff00a226de0(*puVar15);
      }
      else {
        auVar3._8_8_ = extraout_var;
        auVar3._0_8_ = extraout_d0;
        FUN_fffffff009c7d36c(auVar3,param_2,uVar17,uVar19,param_5,param_6);
        uVar14 = extraout_x0_01;
      }
    }
LAB_fffffff009c7249c:
    if (*(long *)PTR_DAT_fffffff00807b630 == local_58) {
      return uVar14;
    }
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  *(undefined1 *)(puVar9 + 2) = 1;
  uVar14 = *puVar9;
  lVar11 = puVar9[1];
  *(long *)(param_7 + 0x18) = lVar11;
  if (lVar11 == 0) {
    *(undefined8 *)(param_7 + 0x20) = 0;
  }
  *(long *)(param_7 + 0xb8) = *(long *)(param_7 + 0xb8) + 1;
LAB_fffffff009c72334:
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x28));
  return uVar14;
}

