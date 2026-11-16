// FUN_fffffff008181774 @ fffffff008181774 size=216

undefined8 FUN_fffffff008181774(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  long *plVar4;
  ulong unaff_x30;
  
  uVar3 = 0xe00002c2;
  if ((*(byte *)(param_1 + 0x5cd) >> 3 & 1) == 0) {
    plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(param_3,*(undefined8 *)PTR_DAT_fffffff007ca60a8)
    ;
    if (plVar2 != (long *)0x0) {
      plVar4 = *(long **)(param_1 + 0x4b0);
      if (plVar4 != (long *)0x0) {
        uVar3 = (**(code **)(*plVar2 + 0xa8))();
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008181820);
          (*pcVar1)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff008181828. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (**(code **)(*plVar4 + 0x318))(plVar4,uVar3,0,(undefined8 *)(*plVar4 + 0x318));
        return uVar3;
      }
      uVar3 = 0xe00002d8;
    }
  }
  else {
    uVar3 = 0xe00002c7;
  }
  return uVar3;
}

