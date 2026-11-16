// FUN_fffffff00a743b98 @ fffffff00a743b98 size=104

undefined8 FUN_fffffff00a743b98(long param_1,uint param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0x28);
  puVar1 = puVar3;
  if (puVar3 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)0x0;
  }
  if ((param_2 >> 6 & 1) != 0) {
    *(ushort *)(param_1 + 0x42) = *(ushort *)(param_1 + 0x42) | 0x8010;
    return 1;
  }
  uVar2 = FUN_fffffff00a743960(param_1,0,puVar3,*puVar1);
  return uVar2;
}

