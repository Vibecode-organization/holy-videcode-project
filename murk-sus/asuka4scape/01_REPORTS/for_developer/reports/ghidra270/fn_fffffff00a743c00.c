// FUN_fffffff00a743c00 @ fffffff00a743c00 size=256

void FUN_fffffff00a743c00(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  puVar3 = *(undefined8 **)(param_1 + 0x28);
  uVar4 = *puVar3;
  FUN_fffffff00a73cb8c
            (((short)*(char *)(param_1 + 0x40) | (ushort)*(byte *)(param_1 + 0x41) << 8) ^ 0x4f71,
             uVar4);
  if (*(long *)(param_1 + 0x18) != -1) {
    if (*(char *)(param_1 + 0x40) == -1) {
      lVar1 = 0x38;
    }
    else {
      if (*(char *)(param_1 + 0x40) != -2) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c4f8("invalid knote %p detach, filter: %d @%s:%d");
      }
      lVar1 = 0x70;
    }
    lVar2 = *(long *)((long)puVar3 + lVar1);
    if (lVar2 == param_1) {
      *(undefined8 *)((long)puVar3 + lVar1) = *(undefined8 *)(lVar2 + 0x18);
    }
    else {
      do {
        lVar1 = lVar2;
        lVar2 = *(long *)(lVar1 + 0x18);
      } while (lVar2 != param_1);
      *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(lVar2 + 0x18);
    }
  }
  *(long *)(param_1 + 0x28) = 0;
  FUN_fffffff00a73a490(uVar4);
  FUN_fffffff00a73cce8(uVar4);
  return;
}

