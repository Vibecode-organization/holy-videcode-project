// FUN_fffffff00a1e862c @ fffffff00a1e862c size=428

undefined8 FUN_fffffff00a1e862c(ulong *param_1,ulong *param_2,long param_3,int param_4)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  
  uVar2 = (uint)param_2[1];
  uVar3 = uVar2 >> 0x18;
  if (uVar3 < 2) {
    if (uVar3 != 0) {
LAB_fffffff00a1e86b8:
      if (param_4 == 0) {
        puVar4 = (uint *)((long)param_2 + 4);
        uVar7 = (ulong)(uint)*param_2;
      }
      else {
        puVar4 = (uint *)((long)param_2 + 0xc);
        uVar7 = *param_2;
      }
      if ((uVar2 & 0xfe00) == 0) {
        uVar3 = *puVar4;
        if (((((uVar2 | uVar2 >> 8) & 0xff) == 0) && (0x8000 < uVar3)) &&
           (uVar5 = (ulong)uVar3 + 0x3fff & 0x1ffffc000, uVar9 = *(ulong *)(param_3 + 0x50),
           *(ulong *)(param_3 + 0x50) = uVar9 + uVar5, CARRY8(uVar9,uVar5))) {
          return 0x400;
        }
        *param_1 = uVar7;
        *(uint *)(param_1 + 1) = uVar2 & 0xff0001ff;
        *(uint *)((long)param_1 + 0xc) = uVar3;
        return 0;
      }
      return 0x1000000f;
    }
    uVar6 = 0x1000000e;
    uVar5 = *param_2;
    uVar7 = (ulong)(uint)uVar5;
    lVar1 = (ulong)*(uint *)(param_3 + 0x44) + 1;
    *(int *)(param_3 + 0x44) = (int)lVar1;
    if (lVar1 == lVar1 * 0x80000000 >> 0x1f) {
      lVar1 = (ulong)*(uint *)(param_3 + 0x48) + 1;
      *(int *)(param_3 + 0x48) = (int)lVar1;
      if (lVar1 == lVar1 * 0x80000000 >> 0x1f) {
        if ((uint)uVar5 == 0xffffffff) {
          uVar7 = 0xffffffffffffffff;
        }
        *param_1 = uVar7;
        *(uint *)(param_1 + 1) = uVar2 & 0xffff0000;
        *(undefined4 *)((long)param_1 + 0xc) = 0;
        return 0;
      }
    }
  }
  else {
    if (uVar3 == 2) {
      if (param_4 == 0) {
        puVar4 = (uint *)((long)param_2 + 4);
        uVar7 = (ulong)(uint)*param_2;
      }
      else {
        puVar4 = (uint *)((long)param_2 + 0xc);
        uVar7 = *param_2;
      }
      uVar8 = *puVar4;
      uVar3 = *(uint *)(param_3 + 0x48);
      *(uint *)(param_3 + 0x48) = uVar3 + uVar8;
      if (CARRY4(uVar3,uVar8)) {
        return 0x1000000e;
      }
    }
    else {
      if (uVar3 == 3) goto LAB_fffffff00a1e86b8;
      if (param_4 == 0) {
        puVar4 = (uint *)((long)param_2 + 4);
        uVar7 = (ulong)(uint)*param_2;
      }
      else {
        puVar4 = (uint *)((long)param_2 + 0xc);
        uVar7 = *param_2;
      }
      uVar8 = *puVar4;
      lVar1 = (ulong)*(uint *)(param_3 + 0x48) + 1;
      *(int *)(param_3 + 0x48) = (int)lVar1;
      if (lVar1 != lVar1 * 0x80000000 >> 0x1f) {
        return 0x1000000e;
      }
      if ((uVar2 & 0xff0000) != 0x100000) {
        return 0x1000000f;
      }
      if ((uVar2 & 0xffff) == 0) {
        return 0x1000000f;
      }
      if ((uVar2 & 0xfffc) != 0) {
        return 0x1000000f;
      }
      if (((uVar2 >> 1 & 1) != 0) && (uVar7 != 0)) {
        return 0x1000000f;
      }
    }
    uVar6 = 0;
    *param_1 = uVar7;
    *(uint *)(param_1 + 1) = uVar2;
    *(uint *)((long)param_1 + 0xc) = uVar8;
  }
  return uVar6;
}

