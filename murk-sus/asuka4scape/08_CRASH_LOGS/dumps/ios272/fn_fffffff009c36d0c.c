// FUN_fffffff009c36d0c @ fffffff009c36d0c size=392

long * FUN_fffffff009c36d0c
                 (long param_1,long param_2,undefined8 param_3,undefined8 param_4,uint *param_5,
                 uint *param_6)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  long *plVar4;
  long *plVar5;
  
  *param_5 = 0;
  *param_6 = 0xffffffff;
  if (param_2 == 0) {
    plVar4 = (long *)0x0;
  }
  else if ((uint)param_3 < 4) {
    uVar2 = FUN_fffffff009c182a4(param_2,param_3,param_4);
    uVar1 = FUN_fffffff009c17530(param_2);
    if ((uVar2 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "%s: slot index %u is not allocated for signal value 0x%016llx on event %08x\n");
      plVar4 = (long *)0x0;
    }
    else {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x148));
      for (plVar5 = *(long **)(param_1 + 0x138); plVar5 != (long *)0x0; plVar5 = (long *)*plVar5) {
        uVar3 = *(uint *)(plVar5 + 4);
        if (uVar1 < uVar3) {
          plVar4 = (long *)plVar5[1];
          if (plVar4 != (long *)0x0) {
            (**(code **)(*plVar4 + 0x20))(plVar4);
            uVar3 = *(uint *)(plVar5 + 4);
          }
          *param_5 = uVar3;
          *param_6 = (uint)param_3 | uVar1 << 2;
          goto LAB_fffffff009c36e6c;
        }
        uVar1 = uVar1 - uVar3;
      }
      plVar4 = (long *)0x0;
LAB_fffffff009c36e6c:
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x148));
    }
  }
  else {
    FUN_fffffff009c17530(param_2);
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "%s: slot index %u is out of range for event %08x\n");
    plVar4 = (long *)0x0;
  }
  return plVar4;
}

