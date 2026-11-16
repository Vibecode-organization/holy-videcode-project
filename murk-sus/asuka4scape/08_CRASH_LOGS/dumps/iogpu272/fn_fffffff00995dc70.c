// FUN_fffffff00995dc70 @ fffffff00995dc70 size=152

void FUN_fffffff00995dc70(long param_1,long param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x48);
  if (uVar5 != *(uint *)(param_1 + 0x4c)) {
    do {
      uVar2 = *(uint *)(param_1 + 0x54);
      uVar4 = 0;
      if (uVar2 != 0) {
        uVar4 = uVar5 / uVar2;
      }
      lVar3 = (ulong)(uVar5 - uVar4 * uVar2) * 8;
      puVar1 = (undefined8 *)(*(long *)(param_1 + 0x58) + (long)(int)lVar3);
      if (lVar3 != (int)lVar3) {
        puVar1 = (undefined8 *)
                 (*(long *)(param_1 + 0x58) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
      }
      (**(code **)(param_2 + 0x10))(param_2,*puVar1);
      uVar5 = uVar5 + 1;
    } while (uVar5 != *(uint *)(param_1 + 0x4c));
  }
  return;
}

