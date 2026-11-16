// FUN_fffffff0099745c4 @ fffffff0099745c4 size=404

long * FUN_fffffff0099745c4(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;
  
  plVar1 = (long *)thunk_EXT_FUN_8011000002c1bcc8
                             (param_2,param_1,*(undefined4 *)(param_1 + 0x100),param_3);
  if (plVar1 == (long *)0x0) {
    return (long *)0x0;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1b8));
  *(undefined1 *)((long)plVar1 + 0x5a) = 1;
  if (plVar1[4] == 0) {
    plVar2 = (long *)FUN_fffffff009953a40(param_1,plVar1);
    if (plVar2 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to allocate\n");
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1b8));
    }
    else {
      (**(code **)(*plVar1 + 0xa8))
                ((undefined8 *)(*plVar1 + 0xa8),plVar1,plVar2,FUN_fffffff009974758);
      uVar3 = (**(code **)(*plVar2 + 0x88))(plVar2,0,0,0);
      if ((uVar3 & 1) != 0) goto LAB_fffffff009974618;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to initialize\n");
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1b8));
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  else {
LAB_fffffff009974618:
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1b8));
  }
  return plVar1;
}

