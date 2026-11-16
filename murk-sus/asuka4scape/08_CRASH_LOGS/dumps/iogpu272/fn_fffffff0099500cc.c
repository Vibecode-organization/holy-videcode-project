// FUN_fffffff0099500cc @ fffffff0099500cc size=204

undefined8 FUN_fffffff0099500cc(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))();
  if ((int)uVar1 != 0) {
    *(undefined8 *)(param_1 + 0x40) = 0;
    uVar1 = *(undefined8 *)(param_2 + 0x148);
    *(long *)(param_1 + 0x10) = param_2;
    *(undefined8 *)(param_1 + 0x18) = uVar1;
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined8 **)(param_1 + 0x48) = (undefined8 *)(param_1 + 0x40);
    *(undefined8 **)(param_1 + 0x58) = (undefined8 *)(param_1 + 0x50);
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(undefined8 **)(param_1 + 0x68) = (undefined8 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 **)(param_1 + 0x30) = (undefined8 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x38) = 0;
    lVar2 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x20) = lVar2;
    if (lVar2 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: fFenceLock alloc fail\n");
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

