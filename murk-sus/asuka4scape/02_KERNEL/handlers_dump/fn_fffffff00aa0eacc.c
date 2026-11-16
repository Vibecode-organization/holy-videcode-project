// FUN_fffffff00aa0eacc @ fffffff00aa0eacc size=164 depth=1
// CALLERS:
//   fffffff00afbfda0 ?
//   fffffff00a9e01a8 FUN_fffffff00a9dfff0
// CALLS:
//   fffffff00a8df19c FUN_fffffff00a8df19c
//   fffffff00a9029a0 FUN_fffffff00a9029a0

undefined8
FUN_fffffff00aa0eacc
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_7 + 0x1ec);
  if (((uVar1 >> 0x1a & 1) != 0) || ((*(ushort *)(param_7 + 0x1f0) & 0x108) != 0)) {
    return 0;
  }
  if ((((uVar1 ^ 0xffffffff) & 0x18) == 0) &&
     (*(int *)(param_7 + 0x224) == 0 && (uVar1 & 0x80) == 0)) {
    if ((DAT_fffffff00ad1fb18._2_1_ >> 1 & 1) == 0) {
      FUN_fffffff00a8df19c
                (param_1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                 (short *)&DAT_fffffff00ad98ba0,0,(byte *)"PMRD: full wake check: no AC\n");
    }
    else {
      FUN_fffffff00a9029a0((byte *)"PMRD: full wake check: no AC\n");
    }
    return 0;
  }
  return 1;
}

