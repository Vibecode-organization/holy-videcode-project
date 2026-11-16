// FUN_fffffff00994d0f4 @ fffffff00994d0f4 size=308

void FUN_fffffff00994d0f4(long param_1,long param_2)

{
  long *plVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x840));
  iVar2 = *(int *)(param_2 + 0x18);
  if (iVar2 < *(int *)(param_1 + 0x28)) {
    lVar5 = (long)iVar2 * 0x18;
    plVar1 = (long *)(param_1 + 0x848 + (long)(int)lVar5);
    if (lVar5 - (int)lVar5 != 0) {
      plVar1 = (long *)(param_1 + 0x848 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if (*plVar1 == param_2) {
      *plVar1 = 0;
      plVar6 = (long *)plVar1[1];
      if (plVar6 != (long *)0x0) {
        iVar4 = FUN_fffffff00994d91c(plVar6);
        if (iVar4 == 0) {
          plVar6 = (long *)0x0;
        }
        else {
          (**(code **)(*plVar6 + 0xd8))(plVar6,(long)iVar2);
        }
      }
      plVar1[1] = 0;
      thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
      if (plVar6 != (long *)0x0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994d20c);
          (*pcVar3)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff00994d214. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*plVar6 + 0x28))(plVar6,(undefined8 *)(*plVar6 + 0x28));
        return;
      }
      return;
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994d178);
    (*pcVar3)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
  return;
}

