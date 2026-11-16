// FUN_fffffff0099812f8 @ fffffff0099812f8 size=88

/* WARNING: Removing unreachable block (ram,0xfffffff009981454) */
/* WARNING: Removing unreachable block (ram,0xfffffff0099813f8) */
/* WARNING: Removing unreachable block (ram,0xfffffff0099813bc) */

void FUN_fffffff0099812f8(undefined8 param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong unaff_x30;
  
  FUN_fffffff009942d70();
  iVar3 = FUN_fffffff0099437e4(param_1);
  if (iVar3 == 0) {
    FUN_fffffff009942d9c(param_1,7);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009981348);
      (*pcVar2)();
    }
    FUN_fffffff009942d7c(param_1);
    return;
  }
  lVar4 = FUN_fffffff0099841fc();
  if (*(long *)(lVar4 + 0x90) == 0) {
    return;
  }
  uVar7 = *(undefined8 *)(lVar4 + 0x38);
  FUN_fffffff009942d70();
  uVar1 = *(uint *)(lVar4 + 0x98) & 0xf00;
  if (((uVar1 == 0x100) || (uVar1 == 0x400)) || (uVar1 == 0x200)) {
    thunk_EXT_FUN_8011000003390134();
  }
  else {
    iVar3 = FUN_fffffff0099437e4(lVar4);
    plVar5 = *(long **)(lVar4 + 0x90);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*plVar5 + 0xd8))(plVar5,0);
      plVar5 = *(long **)(lVar4 + 0x90);
      if (iVar3 == 0) {
        (**(code **)(*plVar5 + 0x88))(plVar5,2,0,uVar7);
        (**(code **)(**(long **)(lVar4 + 0x90) + 0xe0))(*(long **)(lVar4 + 0x90),0);
      }
      else {
        plVar5 = (long *)(**(code **)(*plVar5 + 0xe8))(plVar5,1);
        if (plVar5 != (long *)0x0) {
          uVar8 = *(undefined8 *)PTR_DAT_fffffff007ff2830;
          uVar6 = (**(code **)(*plVar5 + 0x78))();
          thunk_EXT_FUN_80110000038fe8d4(uVar8,uVar6,uVar7);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
      }
    }
    else {
      (**(code **)(*plVar5 + 0x88))(plVar5,2,0,uVar7);
    }
  }
  FUN_fffffff009942d7c(lVar4);
  return;
}

