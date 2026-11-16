// FUN_fffffff009958fd8 @ fffffff009958fd8 size=4

undefined8 FUN_fffffff009958fd8(long param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  iVar1 = (*DAT_fffffff007feb260)();
  uVar4 = 0;
  if ((param_2 != (long *)0x0) && (iVar1 != 0)) {
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    lVar2 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x18) = lVar2;
    if (lVar2 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Failed to create Command Buffer Lock\n");
      uVar4 = 0;
    }
    else {
      *(long **)(param_1 + 0x50) = param_2;
      (**(code **)(*param_2 + 0x20))(param_2);
      *(undefined8 *)(param_1 + 0x40) = 0;
      *(undefined8 **)(param_1 + 0x48) = (undefined8 *)(param_1 + 0x40);
      *(undefined4 *)(param_1 + 0x58) = 0;
      uVar4 = 1;
      uVar3 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
      *(undefined8 *)(param_1 + 0x38) = uVar3;
      thunk_EXT_FUN_80110000036da494
                (0x851800f8,*(undefined8 *)(*(long *)(param_1 + 0x50) + 0x30),uVar3,0,0,0);
    }
  }
  return uVar4;
}

