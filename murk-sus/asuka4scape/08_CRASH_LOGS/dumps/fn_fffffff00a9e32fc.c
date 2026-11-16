// FUN_fffffff00a9e32fc @ fffffff00a9e32fc size=372
// CALLERS:
//   fffffff00afbfade no-fn
//   fffffff007c66a88 no-fn
// CALLEES:
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00aa61ea0 FUN_fffffff00aa61ea0
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a27cacc FUN_fffffff00a27cacc

void FUN_fffffff00a9e32fc(long param_1,undefined8 param_2,undefined8 param_3)

{
  ulong *puVar1;
  uint *puVar2;
  uint uVar3;
  byte bVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  undefined8 *puVar8;
  long lVar9;
  uint in_wzr;
  
  uVar7 = *(ulong *)(*(long *)(param_1 + 0x10) + 0x60);
  lVar5 = tpidr_el1;
  puVar1 = (ulong *)(uVar7 + 8);
  if (*puVar1 == 0) {
    *puVar1 = (ulong)*(uint *)(lVar5 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(uVar7,lVar5,(undefined **)0x0);
  }
  lVar9 = *(long *)(param_1 + 0x10);
  if (*(ulong *)(lVar9 + 8) < 3) {
    if (*(ulong *)(lVar9 + 8) == 0) {
      (**(code **)(**(long **)(lVar9 + 0x68) + 0x108))(*(long **)(lVar9 + 0x68),param_1);
      bVar4 = *(byte *)(param_1 + 0x40);
    }
    else {
      (**(code **)(lVar9 + 0x18))(param_3);
      bVar4 = *(byte *)(param_1 + 0x40);
    }
  }
  else {
    (**(code **)(lVar9 + 0x50))(param_2,param_3,param_1 + 0x40);
    bVar4 = *(byte *)(param_1 + 0x40);
  }
  if ((bVar4 & 1) != 0) {
    puVar8 = *(undefined8 **)(param_1 + 0x38);
    iVar6 = *(int *)(puVar8 + 5);
    *(int *)(puVar8 + 5) = iVar6 + -1;
    LORelease();
    if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ea0();
    }
    if (iVar6 == 1) {
      in_wzr = *(uint *)(puVar8 + 5);
      FUN_fffffff00a27cacc(puVar8);
    }
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffe;
    *(undefined8 *)(param_1 + 0x48) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x50) = 0;
  }
  *(undefined8 *)(param_1 + 0x68) = 0;
  uVar7 = *(ulong *)(*(long *)(param_1 + 0x10) + 0x60);
  puVar2 = (uint *)(uVar7 + 8);
  uVar3 = *puVar2;
  if (uVar3 != *(uint *)(lVar5 + 0x4e8)) {
    FUN_fffffff00a226e08(uVar7,lVar5,uVar3);
    return;
  }
  *puVar2 = in_wzr;
  return;
}

