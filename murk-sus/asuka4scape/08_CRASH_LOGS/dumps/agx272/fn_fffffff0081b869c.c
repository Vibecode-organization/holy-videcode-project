// FUN_fffffff0081b869c @ fffffff0081b869c size=348

/* WARNING: Removing unreachable block (ram,0xfffffff0081b87c0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081b8774) */

void FUN_fffffff0081b869c(long *param_1,ulong param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  ulong unaff_x30;
  
  lVar6 = (param_2 & 0xffffffff) * 0x38;
  iVar5 = (int)lVar6;
  puVar1 = (undefined8 *)((long)param_1 + (long)iVar5 + 0x1460);
  if (lVar6 - iVar5 != 0) {
    puVar1 = (undefined8 *)
             ((ulong)(param_1 + (param_2 & 0xffffffff) * 7 + 0x28c) & 0xffffffffffff |
             0x2bad000000000000);
  }
  *(undefined1 *)(puVar1 + 5) = 1;
  uVar3 = thunk_EXT_FUN_8011000003397c88();
  puVar1[6] = uVar3;
  if ((*(byte *)(puVar1 + 5) & 1) != 0) {
    *(undefined1 *)((long)param_1 + 0x14e9) = 1;
    (**(code **)(**(long **)(param_1[0x50] + 0x310) + 0x108))
              (*(long **)(param_1[0x50] + 0x310),(undefined1 *)((long)param_1 + 0x14e9),0);
  }
  uVar3 = (**(code **)(*(long *)puVar1[2] + 0x98))();
  uVar4 = (**(code **)(*param_1 + 0x208))(*param_1 + 0x208,param_1,uVar3,0);
  lVar6 = *(long *)*puVar1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081b87f4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar6 + 0x558))
              ((long *)*puVar1,uVar4 & 0xfffffffffff | 0x81000000000000,lVar6 + 0x558);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b87ec);
  (*pcVar2)();
}

