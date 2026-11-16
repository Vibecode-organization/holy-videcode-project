// FUN_fffffff008171770 @ fffffff008171770 size=4

void FUN_fffffff008171770(long *param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined4 *puVar3;
  byte bVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined *puVar8;
  uint uVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  undefined4 uStack_5c;
  long lStack_58;
  
  lStack_58 = 0;
  uStack_5c = 0;
  thunk_EXT_FUN_8011000003203330(&lStack_58,&uStack_5c);
  lVar13 = (ulong)(DAT_fffffff00ae21b18 % 0x13) * 0x10;
  puVar3 = (undefined4 *)((long)(int)lVar13 + -0xff51de618);
  if (lVar13 != (int)lVar13) {
    puVar3 = (undefined4 *)(lVar13 - 0xff51de618U & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar2 = lStack_58 - 0x6270;
  puVar3[3] = uStack_5c;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = uVar2;
  uVar9 = (int)uVar2 + SUB164(auVar6 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
  *(char *)(puVar3 + 2) = (char)uVar9 + (char)(uVar9 / 0x3c) * -0x3c;
  *(char *)((long)puVar3 + 7) =
       (char)(uVar9 / 0x3c) + (char)((uVar9 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
  *(char *)((long)puVar3 + 6) = (char)(uVar9 / 0xe10);
  uVar2 = uVar2 / 0x15180 + 0x2db;
  uVar11 = uVar2 % 0x5b5;
  uVar2 = (uVar2 / 0x5b5) * 4 + 0x7b0;
  uVar5 = (int)uVar11 - 0x16e;
  uVar9 = (uVar5 & 0xffff) / 0x16d;
  puVar8 = &UNK_fffffff007115d18;
  if (0x16d < uVar11) {
    uVar2 = uVar2 + (uVar9 + 1);
    uVar11 = (ulong)(uVar5 + uVar9 * -0x16d) & 0xffff;
    puVar8 = &UNK_fffffff007115ce4;
  }
  if (uVar2 < 0x834) {
    uVar12 = 0;
    *puVar3 = (int)uVar2;
    lVar13 = 1;
    do {
      uVar12 = uVar12 + 1;
      lVar1 = lVar13 * 4;
      lVar13 = lVar13 + 1;
    } while (*(uint *)(puVar8 + lVar1) <= uVar11 && uVar12 < 0xc);
    *(char *)(puVar3 + 1) = (char)uVar12;
    *(char *)((long)puVar3 + 5) =
         ((char)uVar11 - (char)*(undefined4 *)(puVar8 + uVar12 * 4 + -4)) + '\x01';
  }
  (**(code **)(*param_1 + 0x38))(param_1);
  thunk_EXT_FUN_8011000003891b28();
  bVar4 = *(byte *)((long)param_1 + 0x10a9d);
  *(undefined8 *)(param_2 + 8) = DAT_fffffff007113e98;
  DAT_fffffff00ae21b18 = DAT_fffffff00ae21b18 + 1;
  uVar9 = 0x240;
  if ((bVar4 & 1) == 0) {
    uVar9 = 0x40;
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0x80;
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x44) = 0x800000008;
  *(undefined4 *)(param_2 + 0x4c) = 0;
  *(uint *)(param_2 + 0x50) = uVar9 | *(uint *)(param_2 + 0x50);
  iVar10 = 5;
  if ((DAT_fffffff00ae22cf1 & 0x10) != 0) {
    iVar10 = 0xb4;
  }
  *(int *)(param_2 + 0x54) = iVar10;
  *(undefined4 *)(param_2 + 0x58) = 2;
  if ((param_1[0xb9] & 0x40000000U) != 0) {
    iVar10 = 0x168;
  }
  *(int *)(param_2 + 0x54) = iVar10;
  uVar9 = *(uint *)(param_2 + 0x84);
  if (uVar9 != 0) {
    if (uVar9 <= (uint)(iVar10 * 2)) {
      uVar9 = iVar10 * 2;
    }
    *(uint *)(param_2 + 0x84) = uVar9;
  }
  (**(code **)(*param_1 + 0x888))(param_1,param_2);
  lStack_58 = 0;
  uStack_5c = 0;
  thunk_EXT_FUN_8011000003203330(&lStack_58,&uStack_5c);
  lVar13 = (ulong)(DAT_fffffff00ae21b18 % 0x13) * 0x10;
  puVar3 = (undefined4 *)((long)(int)lVar13 + -0xff51de618);
  if (lVar13 != (int)lVar13) {
    puVar3 = (undefined4 *)(lVar13 - 0xff51de618U & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar2 = lStack_58 - 0x6270;
  puVar3[3] = uStack_5c;
  auVar7._8_8_ = 0;
  auVar7._0_8_ = uVar2;
  uVar9 = (int)uVar2 + SUB164(auVar7 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
  *(char *)(puVar3 + 2) = (char)uVar9 + (char)(uVar9 / 0x3c) * -0x3c;
  *(char *)((long)puVar3 + 7) =
       (char)(uVar9 / 0x3c) + (char)((uVar9 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
  *(char *)((long)puVar3 + 6) = (char)(uVar9 / 0xe10);
  uVar2 = uVar2 / 0x15180 + 0x2db;
  uVar11 = uVar2 % 0x5b5;
  uVar2 = (uVar2 / 0x5b5) * 4 + 0x7b0;
  uVar5 = (int)uVar11 - 0x16e;
  uVar9 = (uVar5 & 0xffff) / 0x16d;
  puVar8 = &UNK_fffffff007115d18;
  if (0x16d < uVar11) {
    uVar2 = uVar2 + (uVar9 + 1);
    uVar11 = (ulong)(uVar5 + uVar9 * -0x16d) & 0xffff;
    puVar8 = &UNK_fffffff007115ce4;
  }
  if (uVar2 < 0x834) {
    uVar12 = 0;
    *puVar3 = (int)uVar2;
    lVar13 = 1;
    do {
      uVar12 = uVar12 + 1;
      lVar1 = lVar13 * 4;
      lVar13 = lVar13 + 1;
    } while (*(uint *)(puVar8 + lVar1) <= uVar11 && uVar12 < 0xc);
    *(char *)(puVar3 + 1) = (char)uVar12;
    *(char *)((long)puVar3 + 5) =
         ((char)uVar11 - (char)*(undefined4 *)(puVar8 + uVar12 * 4 + -4)) + '\x01';
  }
  (**(code **)(*param_1 + 0x38))(param_1);
  thunk_EXT_FUN_8011000003891b28();
  DAT_fffffff00ae21b18 = DAT_fffffff00ae21b18 + 1;
  return;
}

