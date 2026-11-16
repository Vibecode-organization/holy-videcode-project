// FUN_fffffff009975e34 @ fffffff009975e34 size=524

void FUN_fffffff009975e34(long param_1)

{
  undefined *puVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  long *plVar7;
  int iVar8;
  int iVar9;
  ulong unaff_x30;
  
  plVar5 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x1c8));
  if (plVar5 == (long *)0x0) {
    return;
  }
  iVar3 = (**(code **)(*plVar5 + 0x90))();
  puVar1 = PTR_DAT_fffffff007ff2808;
  if (iVar3 != 0) {
    iVar8 = 0;
    do {
      lVar6 = (**(code **)(*plVar5 + 0x118))(plVar5,iVar8);
      if (lVar6 == 0) {
        thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar1,0x11,"%s null device\n");
      }
      else {
        plVar7 = (long *)FUN_fffffff009944a54(*(undefined8 *)(lVar6 + 0x88));
        if (plVar7 != (long *)0x0) {
          iVar4 = (**(code **)(*plVar7 + 0x90))();
          if (iVar4 != 0) {
            iVar9 = 0;
            do {
              lVar6 = (**(code **)(*plVar7 + 0x118))(plVar7,iVar9);
              if (lVar6 == 0) {
                thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar1,0x11,"%s null queue\n");
              }
              else {
                *(undefined1 *)(lVar6 + 0x5c8) = 1;
              }
              iVar9 = iVar9 + 1;
            } while (iVar4 != iVar9);
          }
          (**(code **)(*plVar7 + 0x28))(plVar7);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 != iVar3);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009976014);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00997601c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar5 + 0x28))(plVar5,(undefined8 *)(*plVar5 + 0x28));
  return;
}

