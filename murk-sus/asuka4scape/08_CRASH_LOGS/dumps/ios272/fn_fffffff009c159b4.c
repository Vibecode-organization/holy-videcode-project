// FUN_fffffff009c159b4 @ fffffff009c159b4 size=360

void FUN_fffffff009c159b4(long *param_1)

{
  long *plVar1;
  code *pcVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *local_58;
  long *local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(param_1[2]);
  plVar3 = (long *)param_1[3];
  if (plVar3 != (long *)0x0) {
    do {
      plVar3[6] = (long)&local_58;
      local_50 = (long *)param_1[4];
      param_1[3] = 0;
      param_1[4] = (long)(param_1 + 3);
      local_58 = plVar3;
      thunk_EXT_FUN_8011000003222de0(param_1[2]);
      plVar3 = local_58;
      while (plVar3 != (long *)0x0) {
        plVar5 = (long *)plVar3[5];
        if (plVar5 == (long *)0x0) {
          plVar4 = (long *)plVar3[6];
          plVar1 = plVar4;
          if ((long *)*plVar4 != plVar3) goto LAB_fffffff009c15b08;
        }
        else {
          if ((long *)plVar5[6] != plVar3 + 5) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c15b18);
            (*pcVar2)();
          }
          if (*(long **)plVar3[6] != plVar3) {
LAB_fffffff009c15b08:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c15b10);
            (*pcVar2)();
          }
          plVar5[6] = (long)plVar3[6];
          plVar4 = (long *)plVar3[6];
          plVar1 = local_50;
        }
        local_50 = plVar1;
        *plVar4 = (long)plVar5;
        FUN_fffffff009c15b1c(plVar3);
        (**(code **)(*plVar3 + 0x28))(plVar3);
        plVar3 = plVar5;
      }
      thunk_EXT_FUN_80110000032222a8(param_1[2]);
      plVar3 = (long *)param_1[3];
    } while (plVar3 != (long *)0x0);
  }
  *(undefined1 *)(param_1 + 5) = 0;
  thunk_EXT_FUN_8011000003222de0(param_1[2]);
  (**(code **)(*param_1 + 0x28))(param_1);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

