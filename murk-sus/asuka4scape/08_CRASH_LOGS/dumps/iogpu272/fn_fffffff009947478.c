// FUN_fffffff009947478 @ fffffff009947478 size=208

undefined8 FUN_fffffff009947478(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  
  plVar5 = *(long **)(param_3 + 0x58);
  lVar3 = (**(code **)(**(long **)(param_1 + 0x110) + 0x78))();
  *plVar5 = lVar3 + (ulong)*(uint *)(param_1 + 0x118);
  lVar3 = *(long *)(param_1 + 0xf8);
  plVar5[1] = *(long *)(lVar3 + 0x22c);
  *(undefined4 *)(plVar5 + 2) = *(undefined4 *)(lVar3 + 0x234);
  iVar1 = FUN_fffffff00994abb0(*(undefined8 *)(lVar3 + 0x148));
  *(int *)((long)plVar5 + 0x14) = iVar1;
  if (0 < iVar1) {
    lVar3 = 0;
    do {
      plVar4 = *(long **)(*(long *)(param_1 + 0xf8) + 0x148);
      uVar2 = (**(code **)(*plVar4 + 0x88))(plVar4,lVar3);
      *(undefined4 *)((long)plVar5 + lVar3 * 4 + 0x18) = uVar2;
      lVar3 = lVar3 + 1;
    } while (lVar3 < *(int *)((long)plVar5 + 0x14));
  }
  return 0;
}

