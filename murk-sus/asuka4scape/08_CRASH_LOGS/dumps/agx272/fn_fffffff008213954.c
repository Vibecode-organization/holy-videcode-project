// FUN_fffffff008213954 @ fffffff008213954 size=92

void FUN_fffffff008213954(long param_1,long param_2)

{
  undefined8 *puVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar2 = *(long *)(param_1 + 0x218);
  lVar3 = *(long *)(*(long *)(param_2 + 0x488) + 0x1f0);
  uVar4 = 0;
  if (lVar3 != 0) {
    uVar4 = *(undefined8 *)(lVar3 + 0x13a0);
  }
  *(undefined8 *)(lVar2 + 0x50) = uVar4;
  *(undefined8 *)(*(long *)(lVar2 + 0x60) + 0x84) = uVar4;
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x218) + 0x148);
                    /* WARNING: Could not recover jumptable at 0xfffffff0082139a4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x218),puVar1);
  return;
}

