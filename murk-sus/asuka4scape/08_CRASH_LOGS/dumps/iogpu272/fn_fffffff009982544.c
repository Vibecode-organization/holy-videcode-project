// FUN_fffffff009982544 @ fffffff009982544 size=408

undefined8
FUN_fffffff009982544
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  if ((*(byte *)(param_1 + 0x30) >> 4 & 1) == 0) {
    uVar4 = 0xe00002c2;
    thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Not detached\n");
  }
  else {
    plVar1 = (long *)FUN_fffffff00998088c(param_2,param_3,param_4,param_5);
    if (plVar1 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to make new descriptor\n");
      uVar4 = 0xe00002bd;
    }
    else {
      lVar2 = (**(code **)(*plVar1 + 0xb0))();
      lVar3 = (**(code **)(**(long **)(param_1 + 0x90) + 0xb0))();
      if (lVar2 == lVar3) {
        (**(code **)(**(long **)(param_1 + 0x90) + 0x28))();
        uVar4 = 0;
        *(undefined8 *)(param_1 + 0x88) = 0;
        *(long **)(param_1 + 0x90) = plVar1;
      }
      else {
        uVar4 = 0xe00002c2;
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Size mismatch\n");
        (**(code **)(*plVar1 + 0x28))(plVar1);
      }
    }
  }
  return uVar4;
}

