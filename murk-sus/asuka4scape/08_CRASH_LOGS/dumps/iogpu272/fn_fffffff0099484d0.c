// FUN_fffffff0099484d0 @ fffffff0099484d0 size=152

undefined8 FUN_fffffff0099484d0(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  uint local_44;
  
  puVar5 = *(undefined4 **)(param_3 + 0x20);
  uVar2 = *puVar5;
  uVar4 = *(undefined8 *)(puVar5 + 2);
  uVar1 = *(undefined8 *)(puVar5 + 4);
  local_44 = 0;
  uVar3 = thunk_EXT_FUN_8011000003271d1c
                    (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x120) + 0x48) + 0x2e0));
  uVar4 = FUN_fffffff0099676d4(*(undefined8 *)(param_1 + 0x120),uVar2,uVar4,uVar1,&local_44);
  if ((int)uVar4 == 0) {
    **(ulong **)(param_3 + 0x48) = (ulong)local_44;
  }
  thunk_EXT_FUN_8011000003271d1c(uVar3);
  return uVar4;
}

