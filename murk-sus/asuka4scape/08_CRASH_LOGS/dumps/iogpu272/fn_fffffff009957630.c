// FUN_fffffff009957630 @ fffffff009957630 size=196

undefined8
FUN_fffffff009957630(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009957448();
  if (plVar1 == (long *)0x0) {
    FUN_fffffff0099574e0
              (param_1,
               "IOReturn IOGPUResource::replace_backing_bytes(task_t, mach_vm_address_t, uint64_t)")
    ;
    uVar2 = 0xe00002e2;
  }
  else {
    uVar2 = (**(code **)(*plVar1 + 0xb0))(plVar1,param_2,param_3,param_4);
    if ((int)uVar2 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to replace memory\n");
    }
  }
  return uVar2;
}

