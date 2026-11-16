// FUN_fffffff00995d140 @ fffffff00995d140 size=124

void FUN_fffffff00995d140(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(param_1 + 0x54);
  uVar4 = 0;
  if (uVar2 != 0) {
    uVar4 = *(uint *)(param_1 + 0x4c) / uVar2;
  }
  lVar3 = (ulong)(*(uint *)(param_1 + 0x4c) - uVar4 * uVar2) * 8;
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0x58) + (long)(int)lVar3);
  if (lVar3 != (int)lVar3) {
    puVar1 = (undefined8 *)
             (*(long *)(param_1 + 0x58) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
  }
  FUN_fffffff00995ce6c(param_1,*puVar1,param_2,param_3);
  if ((param_4 != 0) && (-1 < *(char *)(*(long *)(param_1 + 0xc0) + 0x1fd))) {
    *(undefined1 *)(param_1 + 0x65) = 1;
  }
  return;
}

