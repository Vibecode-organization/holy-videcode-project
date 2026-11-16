// FUN_fffffff0270ad8a4 @ fffffff0270ad8a4 size=412
// CALLERS:
//   fffffff02701c160 ?

void FUN_fffffff0270ad8a4(undefined8 param_1,undefined8 param_2,long param_3)

{
  byte *pbVar1;
  undefined1 auVar2 [16];
  undefined8 local_48;
  
  auVar2 = FUN_fffffff0270be6dc(param_1,2,0xf);
  pbVar1 = auVar2._0_8_;
  if (*(long *)(*(long *)(DAT_fffffff0270921b8 + 0x138) + 8) != 0x4b1d000000000002) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000020,auVar2._8_8_,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
  }
  if (param_3 + 0xfffc000000000000U < 0xfffc000000000001) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x14,auVar2._8_8_,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
  }
  local_48 = 0;
  FUN_fffffff0270bebf0(param_2,param_3 << 0xe,pbVar1,&local_48);
  *(undefined8 *)(pbVar1 + 0x20) = local_48;
  pbVar1[0x28] = 0;
  pbVar1[0x29] = 0;
  pbVar1[0x2a] = 0;
  pbVar1[0x2b] = 0;
  pbVar1[0x2c] = 0;
  pbVar1[0x2d] = 0;
  pbVar1[0x2e] = 0;
  pbVar1[0x2f] = 0;
  *(long *)(pbVar1 + 0x30) = param_3;
  pbVar1[0x38] = 0;
  if (pbVar1[0x1a] != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
  }
  pbVar1[0x1a] = 4;
  if ((*pbVar1 & 5) != 0) {
    FUN_fffffff0270d2f50(pbVar1);
    FUN_fffffff0270dfc5c();
  }
  FUN_fffffff0270ad5a4(param_1);
  return;
}

