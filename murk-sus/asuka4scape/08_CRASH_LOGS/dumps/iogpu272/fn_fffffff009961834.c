// FUN_fffffff009961834 @ fffffff009961834 size=316

undefined8 FUN_fffffff009961834(long param_1,long *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  
  uVar1 = *(uint *)(param_2 + 6);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x1a8) + 0x1fc);
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  FUN_fffffff00997ddbc(&local_68,param_1 + 0x1b8);
  lVar4 = FUN_fffffff00997deac(&local_68);
  uVar7 = 0xe00002be;
  if (lVar4 != 0) {
    uVar1 = uVar1 & (uVar2 & 0x3fff) >> 0xd;
    do {
      iVar3 = FUN_fffffff009942bf8(lVar4);
      if (iVar3 == 0) {
        FUN_fffffff009942c08(lVar4);
        lVar4 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x1a8),uVar1);
        lVar5 = (**(code **)(*param_2 + 0x88))(param_2);
        uVar6 = FUN_fffffff0099749b8(*(undefined8 *)(param_1 + 0x1a8),uVar1);
        if (((ulong)(lVar5 + lVar4) <= uVar6) &&
           (uVar7 = (**(code **)(*param_2 + 200))(param_2),
           (int)uVar7 == -0x1ffffd43 || (int)uVar7 == 0)) break;
      }
      lVar4 = FUN_fffffff00997deac(&local_68);
      uVar7 = 0xe00002be;
    } while (lVar4 != 0);
  }
  FUN_fffffff00997de5c(&local_68);
  return uVar7;
}

