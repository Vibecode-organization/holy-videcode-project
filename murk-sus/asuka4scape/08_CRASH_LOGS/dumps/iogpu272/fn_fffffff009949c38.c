// FUN_fffffff009949c38 @ fffffff009949c38 size=200

undefined8
FUN_fffffff009949c38
          (long param_1,undefined8 param_2,undefined8 param_3,ulong param_4,long param_5,
          undefined8 param_6)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009965da8(*(undefined8 *)(param_1 + 0x120));
  if (plVar1 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to find command queue\n");
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff00997ad78(plVar1,param_3,param_4 | param_5 << 0x20,0,param_6);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

