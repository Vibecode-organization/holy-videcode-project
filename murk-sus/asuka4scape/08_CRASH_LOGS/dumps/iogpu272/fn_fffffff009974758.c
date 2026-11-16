// FUN_fffffff009974758 @ fffffff009974758 size=492

void FUN_fffffff009974758(long param_1,long *param_2,int param_3,long *param_4)

{
  long *plVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 *puVar2;
  long lVar3;
  ulong unaff_x30;
  
  if (param_3 < 3) {
    if (param_3 == 0) {
      puVar2 = (undefined8 *)(*(long *)param_2[4] + 0xf8);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099748f4);
        (*UNRECOVERED_JUMPTABLE)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff0099748fc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar2)((long *)param_2[4],puVar2);
      return;
    }
    if (param_3 == 2) {
      if (param_4 == (long *)0x0) {
        lVar3 = FUN_fffffff009955198(param_2[4]);
      }
      else {
        lVar3 = FUN_fffffff0099552d4();
      }
      if (lVar3 != 0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997492c);
          (*UNRECOVERED_JUMPTABLE)();
        }
        FUN_fffffff00994b380(*(undefined8 *)(param_1 + 0x148),lVar3);
        return;
      }
    }
  }
  else {
    if (param_3 == 3) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff009974860);
        (*UNRECOVERED_JUMPTABLE)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff009974868. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_2 + 0x28))(param_2,param_2,(undefined8 *)(*param_2 + 0x28));
      return;
    }
    if (param_3 == 4) {
      plVar1 = (long *)param_2[4];
      plVar1[6] = 0;
      puVar2 = (undefined8 *)(*plVar1 + 0x28);
      UNRECOVERED_JUMPTABLE = (code *)*puVar2;
LAB_fffffff009974890:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099748ac);
        (*UNRECOVERED_JUMPTABLE)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff0099748b4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(plVar1,puVar2);
      return;
    }
    if ((param_3 == 9) && (*param_4 == 0)) {
      lVar3 = param_2[4];
      plVar1 = (long *)FUN_fffffff00994f734(param_4[2],param_4[1],param_1,0);
      if (plVar1 != (long *)0x0) {
        FUN_fffffff00994c49c
                  (*(undefined8 *)(param_1 + 0x148),*(long *)(lVar3 + 0x18) + 0x40,plVar1 + 0xe);
        FUN_fffffff009950614(*(undefined8 *)(param_1 + 0x158),0,plVar1);
        *(undefined4 *)(param_4 + 3) = 0;
        puVar2 = (undefined8 *)(*plVar1 + 0x28);
        UNRECOVERED_JUMPTABLE = (code *)*puVar2;
        goto LAB_fffffff009974890;
      }
      *(undefined4 *)(param_4 + 3) = 0;
    }
  }
  return;
}

