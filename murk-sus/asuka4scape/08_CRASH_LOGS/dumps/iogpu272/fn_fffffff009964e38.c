// FUN_fffffff009964e38 @ fffffff009964e38 size=224

undefined8 FUN_fffffff009964e38(long param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  ulong unaff_x30;
  
  FUN_fffffff00994463c(*(undefined8 *)(param_1 + 0x10));
  if ((*(byte *)(param_1 + 0x70) & 1) == 0) {
    uVar2 = FUN_fffffff009965780(param_1);
    *(undefined8 *)(param_1 + 0x68) = uVar2;
    *(undefined1 *)(param_1 + 0x70) = 1;
  }
  FUN_fffffff009944648(*(undefined8 *)(param_1 + 0x10));
  plVar3 = *(long **)(param_1 + 0x68);
  uVar2 = 0;
  if ((plVar3 != (long *)0x0) &&
     (lVar4 = (**(code **)(*plVar3 + 0x138))(plVar3,param_2), uVar2 = 0, lVar4 != 0)) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar4,*(undefined8 *)PTR_DAT_fffffff007ff27c8);
    if (plVar3 != (long *)0x0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009964efc);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff009964f04. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*plVar3 + 0x88))(plVar3,(undefined8 *)(*plVar3 + 0x88));
      return uVar2;
    }
    uVar2 = 1;
  }
  return uVar2;
}

