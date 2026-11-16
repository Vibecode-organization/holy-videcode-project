// FUN_fffffff008214afc @ fffffff008214afc size=316

void FUN_fffffff008214afc(long param_1,undefined4 param_2,undefined4 *param_3)

{
  long lVar1;
  undefined *puVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  
  uVar3 = param_1 - 0x6270;
  param_3[3] = param_2;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = uVar3;
  uVar4 = (int)uVar3 + SUB164(auVar6 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
  *(char *)(param_3 + 2) = (char)uVar4 + (char)(uVar4 / 0x3c) * -0x3c;
  *(char *)((long)param_3 + 7) =
       (char)(uVar4 / 0x3c) + (char)((uVar4 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
  *(char *)((long)param_3 + 6) = (char)(uVar4 / 0xe10);
  uVar3 = uVar3 / 0x15180 + 0x2db;
  uVar7 = uVar3 % 0x5b5;
  uVar3 = (uVar3 / 0x5b5) * 4 + 0x7b0;
  if (uVar7 < 0x16e) {
    puVar2 = &UNK_fffffff007115d18;
  }
  else {
    uVar5 = (int)uVar7 - 0x16e;
    uVar4 = (uVar5 & 0xffff) / 0x16d;
    uVar7 = (ulong)(uVar5 + uVar4 * -0x16d) & 0xffff;
    uVar3 = uVar3 + (uVar4 + 1);
    puVar2 = &UNK_fffffff007115ce4;
  }
  if (0x833 < uVar3) {
    return;
  }
  uVar9 = 0;
  *param_3 = (int)uVar3;
  lVar8 = 1;
  do {
    uVar9 = uVar9 + 1;
    lVar1 = lVar8 * 4;
    lVar8 = lVar8 + 1;
  } while (*(uint *)(puVar2 + lVar1) <= uVar7 && uVar9 < 0xc);
  *(char *)(param_3 + 1) = (char)uVar9;
  *(char *)((long)param_3 + 5) =
       ((char)uVar7 - (char)*(undefined4 *)(puVar2 + uVar9 * 4 + -4)) + '\x01';
  return;
}

