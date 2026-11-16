// FUN_fffffff009948920 @ fffffff009948920 size=4

undefined8 FUN_fffffff009948920(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_fffffff009945154
                    (*(undefined8 *)(*(long *)(param_1 + 0x120) + 0x110),
                     **(undefined4 **)(param_3 + 0x20));
  if (lVar1 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid IO Queue ID (%u)\n");
    uVar2 = 0xe00002c2;
  }
  else {
    FUN_fffffff00995b020();
    uVar2 = 0;
  }
  return uVar2;
}

