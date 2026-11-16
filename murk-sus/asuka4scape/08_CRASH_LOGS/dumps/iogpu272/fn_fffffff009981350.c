// FUN_fffffff009981350 @ fffffff009981350 size=448

/* WARNING: Removing unreachable block (ram,0xfffffff009981454) */
/* WARNING: Removing unreachable block (ram,0xfffffff0099813f8) */

void FUN_fffffff009981350(long param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x90) == 0) {
    return;
  }
  uVar6 = *(undefined8 *)(param_1 + 0x38);
  FUN_fffffff009942d70();
  uVar1 = *(uint *)(param_1 + 0x98) & 0xf00;
  if (((uVar1 == 0x100) || (uVar1 == 0x400)) || (uVar1 == 0x200)) {
    thunk_EXT_FUN_8011000003390134();
  }
  else {
    iVar3 = FUN_fffffff0099437e4(param_1);
    plVar4 = *(long **)(param_1 + 0x90);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*plVar4 + 0xd8))(plVar4,0);
      plVar4 = *(long **)(param_1 + 0x90);
      if (iVar3 == 0) {
        (**(code **)(*plVar4 + 0x88))(plVar4,2,0,uVar6);
        (**(code **)(**(long **)(param_1 + 0x90) + 0xe0))(*(long **)(param_1 + 0x90),0);
      }
      else {
        plVar4 = (long *)(**(code **)(*plVar4 + 0xe8))(plVar4,1);
        if (plVar4 != (long *)0x0) {
          uVar7 = *(undefined8 *)PTR_DAT_fffffff007ff2830;
          uVar5 = (**(code **)(*plVar4 + 0x78))();
          thunk_EXT_FUN_80110000038fe8d4(uVar7,uVar5,uVar6);
          (**(code **)(*plVar4 + 0x28))(plVar4);
        }
      }
    }
    else {
      (**(code **)(*plVar4 + 0x88))(plVar4,2,0,uVar6);
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff009942d7c(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099813c0);
  (*pcVar2)();
}

