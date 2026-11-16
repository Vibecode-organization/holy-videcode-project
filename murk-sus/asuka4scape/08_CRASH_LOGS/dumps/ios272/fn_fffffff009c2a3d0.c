// FUN_fffffff009c2a3d0 @ fffffff009c2a3d0 size=188

void FUN_fffffff009c2a3d0(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  long *plVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  plVar3 = *(long **)(param_1 + 0x30);
  if ((plVar3 != (long *)0x0) && ((*(uint *)(param_1 + 0x3d0) >> 10 & 1) != 0)) {
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffbff;
    (**(code **)(*plVar3 + 0xe0))(plVar3,0);
  }
  FUN_fffffff009c21f78((long *)(param_1 + 0x30),param_2);
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  if (*(long *)(param_1 + 0x30) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = thunk_EXT_FUN_8011000003977aa8();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2a488);
    (*pcVar2)();
  }
  thunk_EXT_FUN_80110000036da494(0x540000c,uVar1,uVar4,0,0,0);
  return;
}

