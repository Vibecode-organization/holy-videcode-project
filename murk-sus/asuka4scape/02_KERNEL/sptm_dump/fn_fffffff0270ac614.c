// FUN_fffffff0270ac614 @ fffffff0270ac614 size=624
// CALLERS:
//   fffffff02701c1a8 ?
//   fffffff0270ad43c FUN_fffffff0270ad28c@fffffff0270ad28c

undefined8 FUN_fffffff0270ac614(undefined8 param_1)

{
  int *piVar1;
  byte *pbVar2;
  ulong uVar3;
  undefined8 extraout_x1;
  byte bVar4;
  uint uVar5;
  byte *pbVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  undefined1 auVar10 [16];
  long local_38;
  
  auVar10 = FUN_fffffff0270be6dc(param_1,5,0xf);
  uVar8 = auVar10._8_8_;
  pbVar2 = auVar10._0_8_;
  local_38 = 0;
  bVar4 = pbVar2[0x20];
  uVar5 = (uint)bVar4;
  if (bVar4 == 2) {
LAB_fffffff0270ac698:
    lVar7 = *(long *)(pbVar2 + 0x28);
    DataSynchronizationBarrier(0,2,0);
    if (lVar7 != 0) {
      lVar9 = 0;
      do {
        pbVar6 = pbVar2 + 0x48 + lVar9 * 0x10;
        if ((((ulong)(pbVar2 + 0x48) ^ (ulong)pbVar6) & 0xffc0000000000000) != 0) {
          pbVar6 = (byte *)((ulong)pbVar6 & 0xffffffffffff | 0xc8a2000000000000);
        }
        FUN_fffffff0270ac080(pbVar2,*(undefined8 *)pbVar6,*(long *)(pbVar6 + 8) << 0xe,1);
        lVar9 = lVar9 + 1;
        lVar7 = lVar7 + -1;
        uVar8 = extraout_x1;
      } while (lVar7 != 0);
    }
    DataSynchronizationBarrier(0,3,0);
    uVar5 = 4 - (pbVar2[0x40] & 1);
    pbVar2[0x20] = (byte)uVar5;
LAB_fffffff0270ac6f8:
    if (uVar5 == 4) {
LAB_fffffff0270ac750:
      uVar3 = FUN_fffffff0270ac884(pbVar2,&local_38,FUN_fffffff0270aca80);
      if ((uVar3 & 1) != 0) goto LAB_fffffff0270ac774;
      pbVar2[0x20] = 0;
    }
    else if (uVar5 == 3) {
      if (0x40 < (ulong)*(ushort *)(pbVar2 + 0x18)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f34fc("%s: Context ID not set despite cache flush maybe being needed");
      }
      piVar1 = (int *)(*(long *)(DAT_fffffff0270921b8 + 0x138) + 0x20 +
                      (ulong)*(ushort *)(pbVar2 + 0x18) * 0x18);
      if (((*(byte *)(*(long *)(DAT_fffffff0270921b8 + 0x138) + 0x638) & 1) == 0) && (*piVar1 == 1))
      {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f353c
                  (0x4000016,uVar8,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n");
      }
      *piVar1 = 0;
      DataMemoryBarrier(0,3);
      pbVar2[0x20] = 4;
      goto LAB_fffffff0270ac750;
    }
    uVar8 = 0;
    bVar4 = 2;
  }
  else {
    if (bVar4 != 1) goto LAB_fffffff0270ac6f8;
    auVar10 = FUN_fffffff0270ac884(pbVar2,&local_38,FUN_fffffff0270ad0c0);
    uVar8 = auVar10._8_8_;
    if (((auVar10._0_8_ & 1) == 0) &&
       (pbVar2[0x20] = 2, local_38 != *(long *)(DAT_fffffff0270921b8 + 0x1b8)))
    goto LAB_fffffff0270ac698;
LAB_fffffff0270ac774:
    bVar4 = 5;
    uVar8 = 1;
  }
  if (pbVar2[0x1a] == 1) {
    pbVar2[0x1a] = bVar4;
    if ((*pbVar2 & 5) != 0) {
      FUN_fffffff0270d2f50(pbVar2);
      FUN_fffffff0270dfc5c();
    }
    return uVar8;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
}

