// FUN_fffffff0270ae830 @ fffffff0270ae830 size=732
// CALLERS:
//   fffffff02701c100 ?

void FUN_fffffff0270ae830(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  byte *pbVar3;
  ulong uVar4;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined4 uVar5;
  ulong uVar6;
  byte bVar7;
  undefined1 auVar8 [16];
  long local_50;
  ulong local_48;
  
  pbVar3 = (byte *)FUN_fffffff0270be6dc(param_1,2,0xf);
  local_48 = 0;
  FUN_fffffff0270bebf0(param_2,0x4000,pbVar3,&local_48);
  if ((byte)(param_3 - 3U) < 0xfe) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x400000a,extraout_x1,"%s(%s:%d) - %s(%#llx)\n");
  }
  uVar5 = 4;
  if (param_3 != '\x01') {
    uVar5 = 5;
  }
  uVar4 = FUN_fffffff0270bea54(param_4,uVar5);
  local_50 = 0;
  uVar6 = local_48 >> ((ulong)*(byte *)(DAT_fffffff0270921b8 + 0x1a1) & 0x3f);
  bVar7 = 5;
  if ((uVar6 & 1) != 0) {
    bVar7 = 0xe;
  }
  if ((bVar7 & *pbVar3) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: %d is not a valid UAT state object type when getting TTBR%d");
  }
  auVar8 = FUN_fffffff0270ace00
                     (*(undefined8 *)(pbVar3 + (uVar6 & 1) * 8 + 8),local_48,param_3,&local_50);
  lVar1 = local_50;
  if ((~(uint)*auVar8._0_8_ & 3) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c
              (0x400000c,auVar8._8_8_,
               "%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n");
  }
  if (local_50 != *(long *)(DAT_fffffff0270921b8 + 0x108)) {
    FUN_fffffff0270dfa18(local_50,0x18);
    FUN_fffffff0270dff8c(lVar1,1);
    FUN_fffffff0270dfc5c(lVar1);
  }
  iVar2 = FUN_fffffff0270dff8c(uVar4,1);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x400000f,extraout_x1_00,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
  }
  DataMemoryBarrier(0,2);
  *auVar8._0_8_ = uVar4 & 0xfffffff000 | 3;
  FUN_fffffff0270dfc5c(uVar4);
  if (pbVar3[0x1a] != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
  }
  pbVar3[0x1a] = 2;
  if ((*pbVar3 & 5) != 0) {
    FUN_fffffff0270d2f50(pbVar3);
    FUN_fffffff0270dfc5c();
  }
  return;
}

