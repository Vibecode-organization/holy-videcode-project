// FUN_fffffff00994822c @ fffffff00994822c size=4

undefined8 FUN_fffffff00994822c(long param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(*(undefined4 **)(param_3 + 0x20) + 2);
  plVar1 = (long *)FUN_fffffff009965cc4
                             (*(undefined8 *)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20));
  if (plVar1 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Could not find event_id %u (value %llu)\n");
    uVar2 = 0xe00002c2;
  }
  else {
    (**(code **)(*plVar1 + 0x88))(plVar1,uVar2);
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  return uVar2;
}

