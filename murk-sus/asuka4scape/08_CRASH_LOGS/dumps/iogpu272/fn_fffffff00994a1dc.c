// FUN_fffffff00994a1dc @ fffffff00994a1dc size=184

ulong FUN_fffffff00994a1dc(long param_1,uint param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = 0xe00002c2;
  if ((*(byte *)(param_1 + 0x100) & 1) == 0) {
    uVar1 = 0xe00002d8;
  }
  else {
    if (0x37 < param_2) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00994a290. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(PTR_DAT_fffffff007ff27d0 + 0x550))();
      return uVar2;
    }
    if (*(long *)(param_3 + 0x10) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00994a268. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(PTR_DAT_fffffff007ff27d0 + 0x550))();
      return uVar2;
    }
  }
  return (ulong)uVar1;
}

