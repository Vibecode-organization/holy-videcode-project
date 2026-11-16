// FUN_fffffff00873be90 @ fffffff00873be90 size=4 depth=0
// CALLERS:
//   fffffff00afc83c6 ?
//   fffffff007d54030 ?
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff00873bf44) */

undefined8 FUN_fffffff00873be90(long *param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulong unaff_x30;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long *plStack_48;
  code *pcStack_40;
  undefined8 *puStack_38;
  
  if (*(long *)(param_3 + 8) != 0) {
    puVar2 = (undefined8 *)thunk_FUN_fffffff00a902074((long *)&DAT_fffffff007d55850);
    if (puVar2 == (undefined8 *)0x0) {
      uVar3 = 0xe00002bd;
    }
    else {
      (**(code **)(*param_1 + 0x20))(param_1);
      puVar4 = *(undefined8 **)(param_3 + 0x10);
      uVar3 = puVar4[4];
      uVar6 = puVar4[7];
      uVar5 = puVar4[6];
      uVar10 = puVar4[1];
      uVar9 = *puVar4;
      uVar8 = puVar4[3];
      uVar7 = puVar4[2];
      puVar2[5] = puVar4[5];
      puVar2[4] = uVar3;
      puVar2[7] = uVar6;
      puVar2[6] = uVar5;
      puVar2[1] = uVar10;
      *puVar2 = uVar9;
      puVar2[3] = uVar8;
      puVar2[2] = uVar7;
      pcStack_40 = FUN_fffffff00873d204;
      plStack_48 = param_1;
      puStack_38 = puVar2;
      uVar3 = (**(code **)(*param_1 + 0x5e8))
                        (*param_1 + 0x5e8,param_1,**(undefined8 **)(param_3 + 0x20),
                         (*(undefined8 **)(param_3 + 0x20))[1],&plStack_48);
      if ((int)uVar3 != 0) {
        thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff007d55890,puVar2);
        (**(code **)(*param_1 + 0x28))(param_1);
      }
    }
    return uVar3;
  }
  if (*(long *)(param_3 + 0x40) != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00873bff8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(*param_1 + 0x5f0))
                        (param_1,*(long *)(param_3 + 0x40),(undefined8 *)(*param_1 + 0x5f0));
      return uVar3;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00873bff0);
    (*pcVar1)();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00873c074. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(*param_1 + 0x5f8))
                      (param_1,*(undefined8 *)(param_3 + 0x30),*(undefined4 *)(param_3 + 0x38),
                       (undefined8 *)(*param_1 + 0x5f8));
    return uVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00873c06c);
  (*pcVar1)();
}

