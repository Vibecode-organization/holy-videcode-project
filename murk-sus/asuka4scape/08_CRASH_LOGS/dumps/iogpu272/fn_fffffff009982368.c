// FUN_fffffff009982368 @ fffffff009982368 size=352

undefined8 FUN_fffffff009982368(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((*(byte *)(param_1 + 0x30) >> 4 & 1) == 0) {
    uVar2 = 0xe00002c2;
    thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Not detached\n");
  }
  else {
    lVar1 = (**(code **)(**(long **)(param_1 + 0x90) + 0xb0))();
    if (param_4 == lVar1) {
      lVar1 = FUN_fffffff0099805d0(param_2,param_3,param_4);
      if (lVar1 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to make new descriptor\n")
        ;
        uVar2 = 0xe00002bd;
      }
      else {
        (**(code **)(**(long **)(param_1 + 0x90) + 0x28))();
        uVar2 = 0;
        *(undefined8 *)(param_1 + 0x88) = param_3;
        *(long *)(param_1 + 0x90) = lVar1;
      }
    }
    else {
      uVar2 = 0xe00002c2;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Size mismatch\n");
    }
  }
  return uVar2;
}

