// FUN_fffffff009caa18c @ fffffff009caa18c

void FUN_fffffff009caa18c(long param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  undefined1 *local_40;
  undefined1 *puStack_38;
  undefined4 local_2c;
  undefined8 local_28;
  
  if (*(long *)(param_1 + 0x10) != 0) {
    local_28 = 0;
    local_2c = 1;
    puStack_38 = &DAT_aaaaaaaaaaaaaaaa;
    local_40 = &DAT_aaaaaaaaaaaaaaaa;
    plVar4 = *(long **)(*(long *)(param_1 + 0x10) + 0x28);
    iVar3 = (**(code **)(*plVar4 + 0xb8))(plVar4,&local_28,&local_40,&local_2c);
    if (iVar3 != 0) {
      local_40 = (undefined1 *)0x0;
    }
    lVar5 = *(long *)(param_1 + 0x18);
    uVar6 = (ulong)*(uint *)(param_1 + 0x3c);
    lVar7 = uVar6 * 0x10;
    puVar1 = (undefined8 *)(lVar5 + (int)lVar7);
    if (lVar7 - (int)lVar7 != 0) {
      puVar1 = (undefined8 *)(lVar5 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = local_40;
    lVar7 = uVar6 * 8;
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x30) + (long)(int)lVar7);
    if (lVar7 - (int)lVar7 != 0) {
      puVar1 = (undefined8 *)
               (*(long *)(param_1 + 0x30) + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar6 = uVar6 << 4 | 8;
    puVar2 = (undefined4 *)(lVar5 + (int)uVar6);
    if (uVar6 != (long)(int)uVar6) {
      puVar2 = (undefined4 *)(lVar5 + uVar6 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = local_40;
    *puVar2 = 0;
    DataMemoryBarrier(2,3);
    uVar6 = (ulong)*(uint *)(param_1 + 0x3c) << 4 | 0xc;
    puVar2 = (undefined4 *)(*(long *)(param_1 + 0x18) + (long)(int)uVar6);
    if (uVar6 != (long)(int)uVar6) {
      puVar2 = (undefined4 *)
               (*(long *)(param_1 + 0x18) + uVar6 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar2 = 0x81;
    DataMemoryBarrier(2,3);
  }
  return;
}

