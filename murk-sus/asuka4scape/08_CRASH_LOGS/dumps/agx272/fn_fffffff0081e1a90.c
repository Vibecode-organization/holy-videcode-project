// FUN_fffffff0081e1a90 @ fffffff0081e1a90 size=424

/* WARNING: Removing unreachable block (ram,0xfffffff0081e1bec) */

void FUN_fffffff0081e1a90(long param_1,ulong param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  long *plVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  plVar3 = (long *)(param_1 + 0x10);
  thunk_EXT_FUN_80110000032222a8(*plVar3);
  if (**(ulong **)(param_1 + 0x68) < param_2) {
    **(ulong **)(param_1 + 0x68) = param_2;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x10));
    DataMemoryBarrier(2,3);
    plVar3 = *(long **)(param_1 + 0x18);
    if ((*(byte *)((long)plVar3 + 0x1ac44) >> 3 & 1) != 0) {
      uVar4 = *(undefined8 *)(param_1 + 0x20);
      thunk_EXT_FUN_80110000032222a8(plVar3[0x3589]);
      thunk_EXT_FUN_80110000036da494(0x85930d58,param_1,param_2,uVar4,0,0);
      thunk_EXT_FUN_8011000003222de0(plVar3[0x3589]);
      plVar3 = *(long **)(param_1 + 0x18);
    }
    thunk_EXT_FUN_80110000032222a8(plVar3[0x234c]);
    (**(code **)(*plVar3 + 0x710))(plVar3,"",0);
    plVar3 = *(long **)(*(long *)(param_1 + 0x18) + 0x310);
    puVar2 = (undefined8 *)(*plVar3 + 0xe8);
    (*(code *)*puVar2)(puVar2,plVar3,FUN_fffffff00817dfe8,4,0,*(int *)(param_1 + 0x70) != 0,0);
    plVar3 = *(long **)(param_1 + 0x18);
    (**(code **)(*plVar3 + 0x718))(*plVar3 + 0x718,plVar3,"",0);
    plVar3 = plVar3 + 0x234c;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*plVar3);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e1c34);
  (*pcVar1)();
}

