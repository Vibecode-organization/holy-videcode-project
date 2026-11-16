// FUN_fffffff00a6aee68 @ fffffff00a6aee68 size=316

void FUN_fffffff00a6aee68(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int in_wzr;
  undefined8 local_40;
  undefined8 uStack_38;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar2 = tpidr_el1;
    if (*(ulong *)(param_2 + 8) == 0) {
      *(ulong *)(param_2 + 8) = (ulong)*(uint *)(lVar2 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(param_2,lVar2,0);
    }
    if (((*(uint *)(param_2 + 0x108) ^ 0xffffffff) & 0xc0) == 0) {
      uStack_38 = *(undefined8 *)(param_2 + 0x80);
      local_40 = *(undefined8 *)(param_2 + 0x78);
      uVar3 = *(undefined8 *)(param_2 + 0x110);
      if (*(int *)(param_2 + 8) == *(int *)(lVar2 + 0x4e8)) {
        *(int *)(param_2 + 8) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_2,lVar2);
      }
      FUN_fffffff00a227a00(param_1 + 0x910);
      lVar2 = *(long *)(param_1 + 0x920);
      if (lVar2 == 0) {
        FUN_fffffff00a228d30(param_1 + 0x910);
        return;
      }
      iVar1 = FUN_fffffff00a354278(lVar2 + 0x2f0,&local_40,0x10);
      if (iVar1 == 0) {
        *(undefined8 *)(lVar2 + 0x308) = uVar3;
      }
      FUN_fffffff00a228d30(param_1 + 0x910);
    }
    else {
      if (*(int *)(param_2 + 8) != *(int *)(lVar2 + 0x4e8)) {
        FUN_fffffff00a226e08(param_2,lVar2);
        return;
      }
      *(int *)(param_2 + 8) = in_wzr;
    }
  }
  return;
}

