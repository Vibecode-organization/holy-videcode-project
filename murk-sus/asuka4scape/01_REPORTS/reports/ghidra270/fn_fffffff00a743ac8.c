// FUN_fffffff00a743ac8 @ fffffff00a743ac8 size=208

undefined8 FUN_fffffff00a743ac8(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x28);
  puVar3 = puVar2;
  if (puVar2 == (undefined8 *)0x0) {
    puVar3 = (undefined8 *)0x0;
  }
  uVar4 = *puVar2;
  FUN_fffffff00a73cb8c(uVar4);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x18);
  *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)(param_2 + 0x20);
  uVar1 = FUN_fffffff00a743960(param_1,0,puVar3,uVar4);
  FUN_fffffff00a73a490(uVar4);
  return uVar1;
}

