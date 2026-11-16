// FUN_fffffff0270abc74 @ fffffff0270abc74 size=1036
// CALLERS:
//   fffffff02701c1d8 ?

void FUN_fffffff0270abc74(undefined8 param_1)

{
  ulong *puVar1;
  char *pcVar2;
  ushort uVar3;
  ushort uVar4;
  byte *pbVar5;
  undefined8 extraout_x1;
  undefined8 uVar6;
  long lVar7;
  byte in_wzr;
  undefined1 auVar8 [16];
  
  auVar8 = FUN_fffffff0270be6dc(param_1,2,5);
  uVar6 = auVar8._8_8_;
  pbVar5 = auVar8._0_8_;
  uVar3 = *(ushort *)(pbVar5 + 0x18);
  if (0x3f < uVar3) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000019,uVar6,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
  }
  if (*(int *)(*(long *)(DAT_fffffff0270921b8 + 0x138) + 0x20 +
              ((ulong)uVar3 + (ulong)(uint)uVar3 * 2) * 8) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000016,uVar6,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
  }
  lVar7 = UnkSytemRegRead(3,6,0xf,8,0);
  if (lVar7 == 0) {
    lVar7 = tpidr_el2;
  }
  else {
    lVar7 = UnkSytemRegRead(3,6,0xf,0xb,1);
  }
  if (*(byte *)(DAT_fffffff0270921b8 + 0x60) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x400001a,uVar6,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
  }
  *(byte *)(DAT_fffffff0270921b8 + 0x60) = *(char *)(lVar7 + 0x14a8) << 1 | 1;
  lVar7 = DAT_fffffff0270921b8;
  puVar1 = (ulong *)(*(long *)(DAT_fffffff0270921b8 + 0x78) + (ulong)uVar3 * 0x10);
  if (((*puVar1 & 1) == 0) || ((puVar1[1] & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc
              ("%s: Valid context ID but the TTBAT already contains invalid entries %p %d");
  }
  puVar1[1] = (ulong)((uint)puVar1[1] & 0xfffffffe);
  *puVar1 = (ulong)((uint)*puVar1 & 0xfffffffe);
  if ((*(byte *)(lVar7 + 0x80) & 1) != 0) {
    pcVar2 = (char *)(lVar7 + 0x82 + (ulong)*(ushort *)(pbVar5 + 0x18) * 2);
    *pcVar2 = *pcVar2 + '\x01';
  }
  DataSynchronizationBarrier(0,2,0);
  uVar4 = *(ushort *)(pbVar5 + 0x18);
  if (uVar4 != 0xffff) {
    if ((*pbVar5 & 5) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc
                ("%s: Attempted a TLB Invalidate by ASID on a UAT state object with type %d");
    }
    if ((*(byte *)(DAT_fffffff0270921b8 + 0x1a0) & 1) == 0) {
      if (0x3f < uVar4) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f34fc("%s: invalid context ID %p %u");
      }
      SysOp_W(0,8,1,2,(ulong)uVar4 << 0x30);
    }
    else {
      FUN_fffffff0270ac080(pbVar5,0x1000000000,0x6000000000,0);
      uVar6 = extraout_x1;
    }
  }
  DataSynchronizationBarrier(0,3,0);
  if ((*(byte *)(DAT_fffffff0270921b8 + 0x80) & 1) != 0) {
    pcVar2 = (char *)(DAT_fffffff0270921b8 + (ulong)*(ushort *)(pbVar5 + 0x18) * 2 + 0x83);
    *pcVar2 = *pcVar2 + '\x01';
  }
  if (*(uint *)(*(long *)(DAT_fffffff0270921b8 + 0x138) + 0x18) == (uint)uVar3) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x400001d,uVar6,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
  }
  pbVar5[0x18] = 0xff;
  pbVar5[0x19] = 0xff;
  lVar7 = UnkSytemRegRead(3,6,0xf,8,0);
  if (lVar7 == 0) {
    lVar7 = tpidr_el2;
  }
  else {
    lVar7 = UnkSytemRegRead(3,6,0xf,0xb,1);
  }
  if (*(byte *)(DAT_fffffff0270921b8 + 0x60) == (byte)(*(char *)(lVar7 + 0x14a8) << 1 | 1U)) {
    *(byte *)(DAT_fffffff0270921b8 + 0x60) = in_wzr;
    if (pbVar5[0x1a] == 1) {
      pbVar5[0x1a] = 2;
      if ((*pbVar5 & 5) == 0) {
        return;
      }
      FUN_fffffff0270d2f50();
      FUN_fffffff0270dfc5c();
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
}

