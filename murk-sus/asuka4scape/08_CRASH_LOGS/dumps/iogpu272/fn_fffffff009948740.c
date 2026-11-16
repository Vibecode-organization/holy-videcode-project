// FUN_fffffff009948740 @ fffffff009948740 size=480

undefined8 FUN_fffffff009948740(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  long *plVar2;
  ulong uVar3;
  ulong *puVar4;
  undefined8 uVar5;
  
  uVar5 = **(undefined8 **)(param_3 + 0x20);
  uVar1 = (*(undefined8 **)(param_3 + 0x20))[1];
  plVar2 = (long *)(**(code **)(**(long **)(param_1 + 0xf8) + 0x6b0))();
  if (plVar2 == (long *)0x0) {
    uVar5 = 0xe00002bd;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: IO Command Queue creation failed\n");
  }
  else {
    uVar3 = (**(code **)(*plVar2 + 0x88))(plVar2,*(undefined8 *)(param_1 + 0x120),uVar5,uVar1);
    if ((uVar3 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: IO Command Queue init failed\n");
      (**(code **)(*plVar2 + 0x28))(plVar2);
      uVar5 = 0xe00002c9;
    }
    else {
      uVar3 = thunk_FUN_fffffff009944798(*(undefined8 *)(*(long *)(param_1 + 0x120) + 0x110),plVar2)
      ;
      if ((int)uVar3 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: IO Command Queue add to namespace failed\n");
        (**(code **)(*plVar2 + 0x28))(plVar2);
        uVar5 = 0xe00002db;
      }
      else {
        FUN_fffffff00995b2e0(plVar2,uVar3);
        puVar4 = *(ulong **)(param_3 + 0x48);
        *puVar4 = uVar3 & 0xffffffff;
        puVar4[1] = plVar2[6];
        (**(code **)(*plVar2 + 0x28))(plVar2);
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}

