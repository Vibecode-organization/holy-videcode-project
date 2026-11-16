// FUN_fffffff0270ae210 @ fffffff0270ae210 size=804
// CALLERS:
//   fffffff02701c130 ?

void FUN_fffffff0270ae210
               (undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4,uint param_5)

{
  byte *pbVar1;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  ulong uVar2;
  long lVar3;
  ulong *puVar4;
  ulong uVar5;
  undefined8 local_58;
  
  pbVar1 = (byte *)FUN_fffffff0270be6dc(param_1,2,0xf);
  local_58 = 0;
  FUN_fffffff0270bebf0(param_2,0x4000,pbVar1,&local_58);
  if ((param_3 & 0x3fff) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000009,extraout_x1,"%s(%s:%d) - %s(%#llx)\n");
  }
  if (param_3 < DAT_fffffff0270921c8 || DAT_fffffff0270921d0 <= param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(6,extraout_x1,"%s(%s:%d) - %s(%#llx)\n");
  }
  FUN_fffffff0270dfa18(param_3,0xb);
  if ((param_4 == 0) || (*(ulong *)(DAT_fffffff0270921b8 + 0x1b0) < param_4)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000010,extraout_x1_00,"%s(%s:%d) - %s(%#llx)\n");
  }
  if (0x4000 < param_4 * 0x10 + ((ulong)(pbVar1 + 0x48) & 0x3fff)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: Copying segments into %p will overflow the state object page %zu");
  }
  if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
    lVar3 = (param_3 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
  }
  else {
    uVar2 = (ulong)DAT_fffffff0270fd9f8;
    if (DAT_fffffff0270fd9f8 != 0) {
      lVar3 = 0;
      do {
        puVar4 = &DAT_fffffff0270fda00 + lVar3 * 3;
        if ((((ulong)puVar4 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
          puVar4 = (ulong *)((ulong)puVar4 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar5 = *puVar4;
        if ((uVar5 <= param_3) && (param_3 < uVar5 + (ulong)(uint)puVar4[2] * 0x4000)) {
          lVar3 = (param_3 - uVar5) + puVar4[1];
          goto LAB_fffffff0270ae350;
        }
        lVar3 = lVar3 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    lVar3 = FUN_fffffff0270debdc(param_3);
  }
LAB_fffffff0270ae350:
  thunk_FUN_fffffff0270a4570(pbVar1 + 0x48,lVar3,param_4 * 0x10);
  FUN_fffffff0270dfc5c(param_3);
  if ((param_5 & 0xfff0fcf0) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x400001e,extraout_x1_01,"%s(%s:%d) - %s(%#llx)\n");
  }
  *(undefined8 *)(pbVar1 + 0x20) = local_58;
  *(ulong *)(pbVar1 + 0x28) = param_4;
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
  *(uint *)(pbVar1 + 0x40) = param_5;
  if (pbVar1[0x1a] != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
  }
  pbVar1[0x1a] = 3;
  if ((*pbVar1 & 5) != 0) {
    FUN_fffffff0270d2f50(pbVar1);
    FUN_fffffff0270dfc5c();
  }
  FUN_fffffff0270ada40(param_1);
  return;
}

