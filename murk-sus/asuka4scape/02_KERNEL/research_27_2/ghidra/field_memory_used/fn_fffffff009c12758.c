// FUN_fffffff009c12758 @ fffffff009c12758

undefined8 FUN_fffffff009c12758(long param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  uVar7 = 0xe00002c2;
  if (*(long *)(param_1 + 0xb8) == 0) {
    uVar7 = 0xe00002d8;
  }
  else {
    lVar4 = (**(code **)(**(long **)(param_1 + 0xa8) + 0xb0))();
    lVar5 = *(long *)(param_1 + 0xb8);
    uVar6 = (uint)(lVar4 + 0x1ffffffff0U >> 5);
    if (*(uint *)(lVar5 + 4) < uVar6) {
      uVar3 = *(uint *)(lVar5 + 8);
      if ((param_2 != (undefined8 *)0x0) && (uVar3 < uVar6)) {
        uVar2 = 0;
        if (uVar3 + 1 < uVar6) {
          uVar2 = uVar3 + 1;
        }
        if (uVar2 == *(uint *)(lVar5 + 4)) {
          uVar7 = 0xe00002e8;
        }
        else {
          uVar7 = 0;
          lVar4 = (ulong)uVar3 * 0x20;
          puVar1 = (undefined8 *)(lVar5 + 0x10 + (long)(int)lVar4);
          if (lVar4 - (int)lVar4 != 0) {
            puVar1 = (undefined8 *)(lVar5 + 0x10 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar8 = *param_2;
          uVar10 = param_2[3];
          uVar9 = param_2[2];
          puVar1[1] = param_2[1];
          *puVar1 = uVar8;
          puVar1[3] = uVar10;
          puVar1[2] = uVar9;
          *(uint *)(*(long *)(param_1 + 0xb8) + 8) = uVar2;
        }
      }
    }
  }
  return uVar7;
}

