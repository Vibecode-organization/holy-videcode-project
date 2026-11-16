// FUN_fffffff009c1a104 @ fffffff009c1a104 size=92

byte FUN_fffffff009c1a104(long param_1,undefined8 param_2)

{
  undefined1 uVar1;
  
  uVar1 = FUN_fffffff009c19b40
                    (param_2,*(undefined8 *)(param_1 + 0x28),0,*(int *)(param_1 + 0x30) + 1);
  *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) = uVar1;
  return *(byte *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) & 1;
}

