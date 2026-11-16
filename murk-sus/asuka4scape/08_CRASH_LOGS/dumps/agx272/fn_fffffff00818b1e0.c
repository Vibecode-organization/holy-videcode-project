// FUN_fffffff00818b1e0 @ fffffff00818b1e0 size=448

ulong FUN_fffffff00818b1e0(long param_1,long param_2,undefined8 param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  ulong unaff_x30;
  
  uVar3 = 0xe00002bc;
  if (param_2 == 0) {
LAB_fffffff00818b388:
    return (ulong)uVar3;
  }
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
     (lVar8 = *(long *)(param_1 + 0x530), (*(byte *)(lVar8 + 0x10a71) & 1) != 0)) {
    uVar2 = *(int *)(lVar8 + 0x23c) * 1000 - 1000;
    if (3999 < uVar2) {
      uVar2 = 4000;
    }
    if (uVar3 <= uVar2) {
      plVar7 = (long *)FUN_fffffff0081e2fcc(*(undefined8 *)(*(long *)(lVar8 + 0x11d98) + 0x10));
      if (plVar7 == (long *)0x0) {
        *(undefined4 *)(param_1 + 0x520) = 10;
      }
      else {
        if (uVar3 != 0) {
          uVar2 = uVar3;
        }
        iVar5 = FUN_fffffff00818b3a0(param_1,plVar7,param_3,uVar2,0,1);
        if (iVar5 != 0) {
          thunk_EXT_FUN_8011000002c13ca8
                    (param_2,*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x350),param_3,0,param_1,
                     FUN_fffffff00818bf08);
          (**(code **)(*plVar7 + 0x28))(plVar7);
        }
      }
      uVar3 = 0;
      if (*(int *)(param_1 + 0x520) != 0) {
        uVar3 = 0xe00002bc;
      }
      goto LAB_fffffff00818b388;
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818b2b4);
    (*pcVar4)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00818b2bc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar6 = (**(code **)(PTR_DAT_fffffff007ca6130 + 0x150))();
  return uVar6;
}

