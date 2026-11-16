// FUN_fffffff0099491a4 @ fffffff0099491a4 size=396

undefined8 FUN_fffffff0099491a4(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong uVar6;
  
  uVar5 = 0xe00002c2;
  uVar1 = **(undefined4 **)(param_3 + 0x20);
  uVar6 = (ulong)(uint)(*(undefined4 **)(param_3 + 0x20))[2];
  plVar2 = *(long **)(param_3 + 0x40);
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)0x0;
    uVar4 = (ulong)*(uint *)(param_3 + 0x38);
    lVar3 = *(long *)(param_3 + 0x30);
  }
  else {
    plVar2 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0x1000);
    if (plVar2 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s failed to map arguments\n");
      return 0xe00002c8;
    }
    lVar3 = (**(code **)(*plVar2 + 0x78))();
    uVar4 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
  }
  if ((lVar3 != 0) && (uVar6 << 2 <= uVar4)) {
    uVar5 = FUN_fffffff009967e24(*(undefined8 *)(param_1 + 0x120),uVar1,lVar3,uVar6);
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if ((int)uVar5 != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s failed to add resources to group\n");
  }
  return uVar5;
}

