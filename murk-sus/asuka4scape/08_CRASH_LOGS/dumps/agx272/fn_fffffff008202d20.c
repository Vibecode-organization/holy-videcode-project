// FUN_fffffff008202d20 @ fffffff008202d20 size=308

/* WARNING: Removing unreachable block (ram,0xfffffff008202e10) */

void FUN_fffffff008202d20(long param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  ulong unaff_x30;
  
  puVar4 = *(undefined4 **)(param_1 + 0x68);
  *(undefined4 **)(param_1 + 0x68) = puVar4 + 1;
  *puVar4 = 0x40000002;
  lVar5 = *(long *)(param_1 + 8);
  if ((*(byte *)(lVar5 + 0x1ac44) >> 3 & 1) != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x78);
    uVar2 = *(undefined4 *)(param_1 + 0x7c);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930cb4,uVar2,uVar1,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = ((*(int *)(param_1 + 0x68) - *(int *)(param_1 + 0x28)) - *(int *)(param_1 + 0x5c)) +
               0x3fU & 0xffffffc0;
  }
  lVar5 = (**(code **)(**(long **)(param_1 + 0x20) + 0x98))();
  plVar6 = *(long **)(*(long *)(param_1 + 8) + 0x4b0);
  lVar7 = *plVar6;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008202e50. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar7 + 0x208))(plVar6,lVar5 + (ulong)*(uint *)(param_1 + 0x5c),0,lVar7 + 0x208);
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008202e48);
  (*pcVar3)();
}

