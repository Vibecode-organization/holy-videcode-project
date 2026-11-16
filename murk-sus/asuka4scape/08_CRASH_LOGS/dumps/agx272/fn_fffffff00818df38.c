// FUN_fffffff00818df38 @ fffffff00818df38 size=440

void FUN_fffffff00818df38(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  ulong unaff_x30;
  
  if (param_4 == -1) {
    uVar3 = *(int *)(*(long *)(param_1 + 0x530) + 0x23c) * 1000 - 1000;
    if (3999 < uVar3) {
      uVar3 = 4000;
    }
    bVar1 = *(byte *)(param_1 + 0x7f7);
  }
  else {
    uVar3 = param_4 * 1000;
    bVar1 = *(byte *)(param_1 + 0x7f7);
  }
  if (((bVar1 & 1) != 0) &&
     (lVar7 = *(long *)(param_1 + 0x530), (*(byte *)(lVar7 + 0x10a71) & 1) != 0)) {
    uVar2 = *(int *)(lVar7 + 0x23c) * 1000 - 1000;
    if (3999 < uVar2) {
      uVar2 = 4000;
    }
    if (uVar3 <= uVar2) {
      plVar6 = (long *)FUN_fffffff0081e2fcc(*(undefined8 *)(*(long *)(lVar7 + 0x11d98) + 0x10));
      if (plVar6 == (long *)0x0) {
        *(undefined4 *)(param_1 + 0x520) = 10;
      }
      else {
        if (uVar3 != 0) {
          uVar2 = uVar3;
        }
        iVar5 = FUN_fffffff00818b3a0(param_1,plVar6,param_3,uVar2,0,0);
        if (iVar5 != 0) {
          thunk_EXT_FUN_8011000002c13ca8
                    (param_2,*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x350),param_3,0,param_1,
                     FUN_fffffff00818bf08);
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818e0c8);
            (*pcVar4)();
          }
                    /* WARNING: Could not recover jumptable at 0xfffffff00818e0d0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)(*plVar6 + 0x28))(plVar6,(undefined8 *)(*plVar6 + 0x28));
          return;
        }
      }
      return;
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818e000);
    (*pcVar4)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00818e008. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6130 + 0x138))();
  return;
}

