// FUN_fffffff008212b50 @ fffffff008212b50 size=220

void FUN_fffffff008212b50(long param_1,long param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  
  lVar3 = *(long *)(param_1 + 0x218);
  if (lVar3 != 0) {
    lVar4 = *(long *)(*(long *)(param_2 + 0x488) + 0x1f0);
    uVar5 = 0;
    if (lVar4 != 0) {
      uVar5 = *(undefined8 *)(lVar4 + 0x13a0);
    }
    *(undefined8 *)(lVar3 + 0x50) = uVar5;
    *(undefined8 *)(*(long *)(lVar3 + 0x60) + 0x84) = uVar5;
    (**(code **)(**(long **)(param_1 + 0x218) + 0x148))();
  }
  lVar3 = *(long *)(param_1 + 0x220);
  lVar4 = *(long *)(*(long *)(param_2 + 0x488) + 0x1f0);
  uVar5 = 0;
  if (lVar4 != 0) {
    uVar5 = *(undefined8 *)(lVar4 + 0x13a0);
  }
  *(undefined8 *)(lVar3 + 0x50) = uVar5;
  *(undefined8 *)(*(long *)(lVar3 + 0x60) + 0x84) = uVar5;
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x220) + 0x148);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008212c10);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008212c18. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x220),puVar1);
  return;
}

