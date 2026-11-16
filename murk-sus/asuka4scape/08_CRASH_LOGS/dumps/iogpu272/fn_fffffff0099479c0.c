// FUN_fffffff0099479c0 @ fffffff0099479c0 size=4

undefined8 FUN_fffffff0099479c0(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_fffffff009945154
                    (*(undefined8 *)(*(long *)(param_1 + 0x120) + 0x88),
                     **(undefined4 **)(param_3 + 0x20));
  if (lVar1 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed for id %d\n");
    uVar2 = 0xe00002c2;
  }
  else {
    FUN_fffffff00997684c();
    FUN_fffffff009947080(param_1,0xffffffff);
    uVar2 = 0;
  }
  return uVar2;
}

