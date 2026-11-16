// FUN_fffffff008202310 @ fffffff008202310 size=92

undefined8 FUN_fffffff008202310(long param_1,ulong *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  puVar1 = (undefined8 *)param_2[2];
  if ((((undefined8 *)*param_2 <= puVar1) && (puVar1 < (undefined8 *)0xffffffffffffffe8)) &&
     (puVar1 + 3 <= (undefined8 *)param_2[1])) {
    uVar3 = puVar1[1];
    uVar2 = *puVar1;
    *(undefined8 *)(param_1 + 0x20) = puVar1[2];
    *(undefined8 *)(param_1 + 0x18) = uVar3;
    *(undefined8 *)(param_1 + 0x10) = uVar2;
    param_2[2] = (ulong)(puVar1 + 3);
    *(undefined1 *)(param_1 + 8) = 1;
    return 1;
  }
  *(undefined4 *)(param_1 + 0xc) = 10;
  return 0;
}

