// FUN_fffffff009955628 @ fffffff009955628 size=328

undefined8
FUN_fffffff009955628(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar2 = FUN_fffffff0099644dc(*(undefined8 *)(param_1 + 0x68));
  if (((uint)param_2 >> 4 & 1) == 0) {
    uVar1 = *(uint *)(param_1 + 0x10) & 0xf;
    if (uVar1 == 0 || uVar1 == 2) {
      lVar3 = (**(code **)(**(long **)(param_1 + 0x28) + 0xa0))
                        (*(long **)(param_1 + 0x28),uVar2,param_2,param_3,param_4);
      *(long *)(param_1 + 0x20) = lVar3;
      if (lVar3 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: failed to create mapping. resType=0x%x\n");
        return 0;
      }
    }
    else if (uVar1 != 3) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Unkown resource type. resType=0x%x\n");
      return 0;
    }
    uVar2 = 1;
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Can\'t pin global ro resources to fixed address\n");
    uVar2 = 0;
  }
  return uVar2;
}

