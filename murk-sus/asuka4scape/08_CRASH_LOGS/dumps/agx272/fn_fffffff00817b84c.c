// FUN_fffffff00817b84c @ fffffff00817b84c size=396

void FUN_fffffff00817b84c(long param_1,byte *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong unaff_x30;
  
  if ((*param_2 & 1) == 0) {
    if ((*(byte *)(param_1 + 0x530) & 1) != 0) {
      (**(code **)(**(long **)(param_1 + 0x528) + 0x138))();
      *(undefined1 *)(param_1 + 0x530) = 0;
    }
    if (((*(byte *)(param_1 + 0x531) & 1) != 0) && (*(char *)(param_1 + 0x115c1) == '\x02')) {
      (**(code **)(**(long **)(param_1 + 0x4b0) + 0x298))(*(long **)(param_1 + 0x4b0),1);
      *(char *)(param_1 + 0x115c1) = '\x01';
      if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85930c0c,0,0,0,0,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
      }
    }
    *(byte *)(param_1 + 0x531) = *param_2 & 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x531) = 1;
    iVar2 = thunk_EXT_FUN_8011000002946de4(*(undefined8 *)(param_1 + 0x148));
    if (((iVar2 != 0) && ((*(byte *)(param_1 + 0x531) & 1) != 0)) &&
       ((*(byte *)(param_1 + 0x530) & 1) == 0)) {
      *(undefined1 *)(param_1 + 0x530) = 1;
      puVar3 = (undefined8 *)(**(long **)(param_1 + 0x528) + 0xf0);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817b8e4);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff00817b8ec. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar3)(*(long **)(param_1 + 0x528),*(undefined1 *)(param_1 + 0x658),puVar3);
      return;
    }
  }
  return;
}

