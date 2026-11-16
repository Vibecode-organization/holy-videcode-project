// FUN_fffffff00995758c @ fffffff00995758c size=164

undefined8 FUN_fffffff00995758c(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_fffffff009957448();
  if (lVar1 == 0) {
    FUN_fffffff0099574e0(param_1,"IOReturn IOGPUResource::detach_backing()");
    uVar2 = 0xe00002e2;
  }
  else {
    FUN_fffffff00994b870
              (*(undefined8 *)(*(long *)(param_1 + 0x50) + 0x148),*(undefined8 *)(param_1 + 0x18));
    uVar2 = FUN_fffffff00994396c(lVar1);
    if ((int)uVar2 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to detach memory\n");
    }
  }
  return uVar2;
}

