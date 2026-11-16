// FUN_fffffff009947a54 @ fffffff009947a54 size=4
// CALLERS:
//   fffffff00afb815a no-fn
// CALLEES:

undefined8 FUN_fffffff009947a54(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  
  uVar4 = 0xe00002c2;
  lVar5 = *(long *)(param_3 + 0x58);
  plVar1 = *(long **)(param_3 + 0x40);
  if (plVar1 == (long *)0x0) {
    plVar1 = (long *)0x0;
    uVar3 = (ulong)*(uint *)(param_3 + 0x38);
    lVar2 = *(long *)(param_3 + 0x30);
  }
  else {
    plVar1 = (long *)(**(code **)(*plVar1 + 0xe8))(plVar1,0x1000);
    if (plVar1 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s failed to map arguments\n");
      return 0xe00002c8;
    }
    lVar2 = (**(code **)(*plVar1 + 0x78))();
    uVar3 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
  }
  if ((lVar2 != 0) && (0x57 < uVar3 && lVar5 != 0)) {
    uVar4 = FUN_fffffff00994a30c(param_1,lVar2,lVar5,uVar3,param_3 + 0x60);
  }
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  if ((int)uVar4 != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s failed to create resource\n");
  }
  return uVar4;
}

