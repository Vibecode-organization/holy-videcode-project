// FUN_fffffff00995b9a4 @ fffffff00995b9a4 size=456

undefined8 FUN_fffffff00995b9a4(long param_1,ulong *param_2,long *param_3)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  plVar2 = (long *)(**(code **)(**(long **)(*(long *)(param_1 + 0x78) + 0x48) + 0x6b8))();
  if (plVar2 == (long *)0x0) {
    uVar4 = 0xe00002bd;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: IO Command Buffer creation failed\n")
    ;
  }
  else {
    uVar3 = (**(code **)(*plVar2 + 0x90))(plVar2,param_1);
    if ((uVar3 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: IO Command Buffer init failed\n");
      (**(code **)(*plVar2 + 0x28))(plVar2);
      uVar4 = 0xe00002c9;
    }
    else {
      uVar1 = thunk_FUN_fffffff009944798(*(undefined8 *)(param_1 + 0x38),plVar2);
      if (uVar1 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: IO Command Buffer add to namespace failed\n");
        (**(code **)(*plVar2 + 0x28))(plVar2);
        uVar4 = 0xe00002db;
      }
      else {
        *(uint *)(plVar2 + 2) = uVar1;
        *param_2 = (ulong)uVar1;
        *param_3 = plVar2[7];
        (**(code **)(*plVar2 + 0x28))(plVar2);
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

