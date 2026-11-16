// FUN_fffffff009980b50 @ fffffff009980b50 size=508

long FUN_fffffff009980b50
               (long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long *plVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  plVar1 = (long *)FUN_fffffff00998088c(param_2,param_3,param_4,param_5);
  if (plVar1 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: failed to get the memory descriptor\n");
    lVar5 = 0;
  }
  else {
    uVar2 = (**(code **)(*plVar1 + 0xb0))();
    if ((-*(long *)PTR_DAT_fffffff007ff2838 &
        (param_1[0x23] * (ulong)*(uint *)((long)param_1 + 0x2ec)) / 100) < uVar2) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: memory larger than maximum system memory size\n");
      (**(code **)(*plVar1 + 0x28))(plVar1);
      lVar5 = 0;
    }
    else {
      lVar5 = (**(code **)(*param_1 + 0x590))(param_1);
      if (lVar5 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: allocIOGPUResource failed to alloc texture object\n");
        (**(code **)(*plVar1 + 0x28))(plVar1);
      }
      else {
        *(long **)(lVar5 + 0x90) = plVar1;
        uVar3 = (**(code **)(*plVar1 + 0xb0))(plVar1);
        *(undefined8 *)(lVar5 + 0x38) = uVar3;
        *(undefined4 *)(lVar5 + 0x84) = 0;
        lVar4 = (**(code **)(**(long **)(lVar5 + 0x90) + 0xb0))();
        param_1[0x22] = param_1[0x22] + lVar4;
      }
    }
  }
  return lVar5;
}

