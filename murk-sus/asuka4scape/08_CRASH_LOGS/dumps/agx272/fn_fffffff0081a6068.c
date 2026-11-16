// FUN_fffffff0081a6068 @ fffffff0081a6068 size=496

void FUN_fffffff0081a6068(long *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  if (param_2 == 0) {
    (**(code **)(*param_1 + 0x7e0))(param_1);
  }
  else {
    iVar3 = FUN_fffffff0081a5c00(param_1);
    if (iVar3 != 0) {
      (**(code **)(**(long **)(param_1[0x50] + 0x570) + 0xf8))
                (*(long **)(param_1[0x50] + 0x570),0,0,0);
    }
  }
  (**(code **)(*param_1 + 0x7d8))(param_1);
  FUN_fffffff0081a6258(param_1);
  lVar4 = param_1[0xf2];
  if (lVar4 != 0) {
    uVar1 = *(uint *)param_1[0xf1];
    *(uint *)(param_1 + 0xf3) = uVar1;
    uVar2 = ((uint *)param_1[0xf1])[8];
    *(uint *)((long)param_1 + 0x79c) = uVar2;
    if (((ulong)param_1[0xf5] <= (ulong)uVar1) || ((ulong)param_1[0xf5] <= (ulong)uVar2)) {
      thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! read_index out of bounds\n");
      return;
    }
    while (lVar4 != 0) {
      if ((int)param_1[0xf3] == *(int *)((long)param_1 + 0x79c)) {
        return;
      }
      local_30 = 0;
      uStack_48 = 0;
      local_50 = 0;
      uStack_38 = 0;
      uStack_40 = 0;
      uStack_68 = 0;
      local_70 = 0;
      uStack_58 = 0;
      uStack_60 = 0;
      FUN_fffffff0081b7c6c(param_1 + 0xf0,&local_70);
      uStack_98 = uStack_48;
      local_a0 = local_50;
      uStack_88 = uStack_38;
      uStack_90 = uStack_40;
      local_80 = local_30;
      uStack_b8 = uStack_68;
      local_c0 = local_70;
      uStack_a8 = uStack_58;
      uStack_b0 = uStack_60;
      FUN_fffffff008209548(*(undefined8 *)(param_1[0x50] + 0x1ac50),&local_c0);
      lVar4 = param_1[0xf2];
    }
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Using uninitialized validator class\n");
  return;
}

