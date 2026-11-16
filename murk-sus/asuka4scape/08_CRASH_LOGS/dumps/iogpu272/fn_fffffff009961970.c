// FUN_fffffff009961970 @ fffffff009961970 size=220

undefined8 FUN_fffffff009961970(long param_1,long param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  iVar1 = *(int *)(*(long *)(param_1 + 0x1a8) + 0x1fc);
  uVar4 = 0xe00002be;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  FUN_fffffff00997ddbc(&local_58,param_1 + 0x1b8);
  lVar2 = FUN_fffffff00997deac(&local_58);
  if (lVar2 != 0) {
    param_3 = param_3 & (iVar1 << 0x12) >> 0x1f;
    do {
      iVar1 = FUN_fffffff009942bf8(lVar2);
      if (iVar1 == 0) {
        FUN_fffffff009942c08(lVar2);
        lVar2 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x1a8),param_3);
        uVar3 = FUN_fffffff0099749b8(*(undefined8 *)(param_1 + 0x1a8),param_3);
        if ((ulong)(lVar2 + param_2) <= uVar3) {
          uVar4 = 0;
          break;
        }
      }
      lVar2 = FUN_fffffff00997deac(&local_58);
    } while (lVar2 != 0);
  }
  FUN_fffffff00997de5c(&local_58);
  return uVar4;
}

