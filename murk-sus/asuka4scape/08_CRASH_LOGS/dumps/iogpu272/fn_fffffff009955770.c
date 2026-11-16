// FUN_fffffff009955770 @ fffffff009955770 size=4

undefined8 FUN_fffffff009955770(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  
  if ((((uint)param_2 >> 4 & 1) == 0) && (*(long *)(param_1 + 0x68) != 0)) {
    uVar2 = FUN_fffffff0099644dc();
  }
  else {
    uVar2 = FUN_fffffff009975b4c(*(undefined8 *)(param_1 + 0x50));
  }
  if (*(long *)(param_1 + 0x20) != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: resource already has a map\n");
    return 1;
  }
  uVar1 = *(uint *)(param_1 + 0x10) & 0xff;
  lVar4 = param_1;
  if ((*(uint *)(param_1 + 0x10) & 0xf) != 0) {
    if (uVar1 == 3) {
      return 1;
    }
    if (uVar1 != 0x82) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Unkown resource type. resType=0x%x\n");
      return 1;
    }
    lVar4 = *(long *)(param_1 + 0x30);
    if (lVar4 == 0) goto LAB_fffffff009955898;
  }
  plVar3 = *(long **)(lVar4 + 0x28);
  if (plVar3 != (long *)0x0) {
    lVar4 = (**(code **)(*plVar3 + 0x98))(plVar3,uVar2,param_2,param_3);
    *(long *)(param_1 + 0x20) = lVar4;
    if (lVar4 != 0) {
      return 1;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: failed to create mapping. resType=0x%x\n");
    return 0;
  }
LAB_fffffff009955898:
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: no memory. resType=0x%x\n");
  return 0;
}

