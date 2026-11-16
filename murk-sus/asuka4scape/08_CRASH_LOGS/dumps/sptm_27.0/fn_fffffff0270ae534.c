// FUN_fffffff0270ae534 @ fffffff0270ae534 size=764
// CALLERS:
//   fffffff02701c118 ?

void FUN_fffffff0270ae534(undefined8 param_1,undefined8 param_2,char param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  byte *pbVar4;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  ulong uVar5;
  byte bVar6;
  undefined1 auVar7 [16];
  long local_50;
  ulong local_48;
  
  pbVar4 = (byte *)FUN_fffffff0270be6dc(param_1,2,0xf);
  local_48 = 0;
  FUN_fffffff0270bebf0(param_2,0x4000,pbVar4,&local_48);
  uVar2 = local_48;
  if ((byte)(param_3 - 3U) < 0xfe) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x400000a,extraout_x1,"%s(%s:%d) - %s(%#llx)\n");
  }
  local_50 = 0;
  uVar5 = local_48 >> ((ulong)*(byte *)(DAT_fffffff0270921b8 + 0x1a1) & 0x3f);
  bVar6 = 5;
  if ((uVar5 & 1) != 0) {
    bVar6 = 0xe;
  }
  if ((bVar6 & *pbVar4) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: %d is not a valid UAT state object type when getting TTBR%d");
  }
  auVar7 = FUN_fffffff0270ace00
                     (*(undefined8 *)(pbVar4 + (uVar5 & 1) * 8 + 8),local_48,param_3,&local_50);
  uVar5 = *auVar7._0_8_;
  if ((~(uint)uVar5 & 3) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c
              (0x400000c,auVar7._8_8_,
               "%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n");
  }
  uVar5 = uVar5 & 0xfffffffff000;
  FUN_fffffff0270dfa18(uVar5,0x18);
  *auVar7._0_8_ = 0;
  DataSynchronizationBarrier(0,2,0);
  FUN_fffffff0270ac080(pbVar4,uVar2,0x4000,0);
  lVar1 = local_50;
  DataSynchronizationBarrier(0,3,0);
  if (local_50 != *(long *)(DAT_fffffff0270921b8 + 0x108)) {
    FUN_fffffff0270dfa18(local_50,0x18);
    iVar3 = FUN_fffffff0270dff8c(lVar1,0xffffffff);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: Parent page table has a zero refcnt");
    }
    FUN_fffffff0270dfc5c(lVar1);
  }
  iVar3 = FUN_fffffff0270dff8c(uVar5,0xffffffff);
  if (iVar3 != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x400000f,extraout_x1_00,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
  }
  FUN_fffffff0270dfc5c(uVar5);
  if (pbVar4[0x1a] != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
  }
  pbVar4[0x1a] = 2;
  if ((*pbVar4 & 5) != 0) {
    FUN_fffffff0270d2f50(pbVar4);
    FUN_fffffff0270dfc5c();
  }
  return;
}

