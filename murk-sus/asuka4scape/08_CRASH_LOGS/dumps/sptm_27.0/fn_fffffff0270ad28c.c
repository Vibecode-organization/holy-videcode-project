// FUN_fffffff0270ad28c @ fffffff0270ad28c size=792
// CALLERS:
//   fffffff02701c190 ?

void FUN_fffffff0270ad28c(undefined8 param_1,ulong param_2,ulong param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined8 extraout_x1;
  ulong uVar3;
  long lVar4;
  ulong *puVar5;
  ulong uVar6;
  undefined1 auVar7 [16];
  
  auVar7 = FUN_fffffff0270be6dc(param_1,2,0xf);
  uVar2 = auVar7._8_8_;
  pbVar1 = auVar7._0_8_;
  if (*(long *)(*(long *)(DAT_fffffff0270921b8 + 0x138) + 8) != 0x4b1d000000000002) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000020,uVar2,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
  }
  if ((param_2 & 0x3fff) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000009,uVar2,"%s(%s:%d) - %s(%#llx)\n");
  }
  if (param_2 < DAT_fffffff0270921c8 || DAT_fffffff0270921d0 <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(6,uVar2,"%s(%s:%d) - %s(%#llx)\n");
  }
  FUN_fffffff0270dfa18(param_2,0xb);
  if ((param_3 == 0) || (*(ulong *)(DAT_fffffff0270921b8 + 0x1b0) < param_3)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000010,extraout_x1,"%s(%s:%d) - %s(%#llx)\n");
  }
  if (0x4000 < param_3 * 0x10 + ((ulong)(pbVar1 + 0x48) & 0x3fff)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: Copying segments into %p will overflow the state object page %zu");
  }
  if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
    lVar4 = (param_2 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
  }
  else {
    uVar3 = (ulong)DAT_fffffff0270fd9f8;
    if (DAT_fffffff0270fd9f8 != 0) {
      lVar4 = 0;
      do {
        puVar5 = &DAT_fffffff0270fda00 + lVar4 * 3;
        if ((((ulong)puVar5 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
          puVar5 = (ulong *)((ulong)puVar5 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar6 = *puVar5;
        if ((uVar6 <= param_2) && (param_2 < uVar6 + (ulong)(uint)puVar5[2] * 0x4000)) {
          lVar4 = (param_2 - uVar6) + puVar5[1];
          goto LAB_fffffff0270ad3c8;
        }
        lVar4 = lVar4 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    lVar4 = FUN_fffffff0270debdc(param_2);
  }
LAB_fffffff0270ad3c8:
  thunk_FUN_fffffff0270a4570(pbVar1 + 0x48,lVar4,param_3 * 0x10);
  FUN_fffffff0270dfc5c(param_2);
  pbVar1[0x20] = 1;
  pbVar1[0x30] = 0;
  pbVar1[0x31] = 0;
  pbVar1[0x32] = 0;
  pbVar1[0x33] = 0;
  pbVar1[0x34] = 0;
  pbVar1[0x35] = 0;
  pbVar1[0x36] = 0;
  pbVar1[0x37] = 0;
  pbVar1[0x38] = 0;
  pbVar1[0x39] = 0;
  pbVar1[0x3a] = 0;
  pbVar1[0x3b] = 0;
  pbVar1[0x3c] = 0;
  pbVar1[0x3d] = 0;
  pbVar1[0x3e] = 0;
  pbVar1[0x3f] = 0;
  *(ulong *)(pbVar1 + 0x28) = param_3;
  pbVar1[0x40] = 0;
  if (pbVar1[0x1a] != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
  }
  pbVar1[0x1a] = 5;
  if ((*pbVar1 & 5) != 0) {
    FUN_fffffff0270d2f50(pbVar1);
    FUN_fffffff0270dfc5c();
  }
  FUN_fffffff0270ac614(param_1);
  return;
}

