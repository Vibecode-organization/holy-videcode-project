// FUN_fffffff00817a2cc @ fffffff00817a2cc size=4

/* WARNING: Removing unreachable block (ram,0xfffffff00817a908) */
/* WARNING: Removing unreachable block (ram,0xfffffff00817a954) */
/* WARNING: Removing unreachable block (ram,0xfffffff00817a358) */

void FUN_fffffff00817a2cc(long *param_1)

{
  long lVar1;
  ulong uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined *puVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  undefined4 uStack_6c;
  long lStack_68;
  
  thunk_EXT_FUN_80110000032222a8(param_1[0x234c]);
  (**(code **)(*param_1 + 0x710))(param_1,"",0);
  iVar10 = (**(code **)(*param_1 + 0xb28))(*param_1 + 0xb28,param_1);
  if ((iVar10 != 0) && (iVar10 = (**(code **)(*param_1 + 0xb38))(param_1), iVar10 != 0)) {
    (**(code **)(*param_1 + 0xb40))(param_1);
    lStack_68 = 0;
    uStack_6c = 0;
    thunk_EXT_FUN_8011000003203330(&lStack_68,&uStack_6c);
    lVar13 = (ulong)(DAT_fffffff00ae21b18 % 0x13) * 0x10;
    puVar3 = (undefined4 *)((long)(int)lVar13 + -0xff51de618);
    if (lVar13 != (int)lVar13) {
      puVar3 = (undefined4 *)(lVar13 - 0xff51de618U & 0xffffffffffff | 0x2bad000000000000);
    }
    uVar2 = lStack_68 - 0x6270;
    puVar3[3] = uStack_6c;
    auVar6._8_8_ = 0;
    auVar6._0_8_ = uVar2;
    uVar4 = (int)uVar2 + SUB164(auVar6 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
    *(char *)(puVar3 + 2) = (char)uVar4 + (char)(uVar4 / 0x3c) * -0x3c;
    *(char *)((long)puVar3 + 7) =
         (char)(uVar4 / 0x3c) + (char)((uVar4 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
    *(char *)((long)puVar3 + 6) = (char)(uVar4 / 0xe10);
    uVar2 = uVar2 / 0x15180 + 0x2db;
    uVar11 = uVar2 % 0x5b5;
    uVar2 = (uVar2 / 0x5b5) * 4 + 0x7b0;
    uVar5 = (int)uVar11 - 0x16e;
    uVar4 = (uVar5 & 0xffff) / 0x16d;
    puVar9 = &UNK_fffffff007115d18;
    if (0x16d < uVar11) {
      uVar2 = uVar2 + (uVar4 + 1);
      uVar11 = (ulong)(uVar5 + uVar4 * -0x16d) & 0xffff;
      puVar9 = &UNK_fffffff007115ce4;
    }
    if (uVar2 < 0x834) {
      uVar12 = 0;
      *puVar3 = (int)uVar2;
      lVar13 = 1;
      do {
        uVar12 = uVar12 + 1;
        lVar1 = lVar13 * 4;
        lVar13 = lVar13 + 1;
      } while (*(uint *)(puVar9 + lVar1) <= uVar11 && uVar12 < 0xc);
      *(char *)(puVar3 + 1) = (char)uVar12;
      *(char *)((long)puVar3 + 5) =
           ((char)uVar11 - (char)*(undefined4 *)(puVar9 + uVar12 * 4 + -4)) + '\x01';
    }
    (**(code **)(*param_1 + 0x38))(param_1);
    thunk_EXT_FUN_8011000003891b28();
    DAT_fffffff00ae21b18 = DAT_fffffff00ae21b18 + 1;
    iVar10 = (**(code **)(*(long *)param_1[0x96] + 0xb8))();
    if (iVar10 != 0) {
      lStack_68 = 0;
      uStack_6c = 0;
      thunk_EXT_FUN_8011000003203330(&lStack_68,&uStack_6c);
      lVar13 = (ulong)(DAT_fffffff00ae21b18 % 0x13) * 0x10;
      puVar3 = (undefined4 *)((long)(int)lVar13 + -0xff51de618);
      if (lVar13 != (int)lVar13) {
        puVar3 = (undefined4 *)(lVar13 - 0xff51de618U & 0xffffffffffff | 0x2bad000000000000);
      }
      uVar2 = lStack_68 - 0x6270;
      puVar3[3] = uStack_6c;
      auVar7._8_8_ = 0;
      auVar7._0_8_ = uVar2;
      uVar4 = (int)uVar2 + SUB164(auVar7 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
      *(char *)(puVar3 + 2) = (char)uVar4 + (char)(uVar4 / 0x3c) * -0x3c;
      *(char *)((long)puVar3 + 7) =
           (char)(uVar4 / 0x3c) + (char)((uVar4 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
      *(char *)((long)puVar3 + 6) = (char)(uVar4 / 0xe10);
      uVar2 = uVar2 / 0x15180 + 0x2db;
      uVar11 = uVar2 % 0x5b5;
      uVar2 = (uVar2 / 0x5b5) * 4 + 0x7b0;
      uVar5 = (int)uVar11 - 0x16e;
      uVar4 = (uVar5 & 0xffff) / 0x16d;
      puVar9 = &UNK_fffffff007115d18;
      if (0x16d < uVar11) {
        uVar2 = uVar2 + (uVar4 + 1);
        uVar11 = (ulong)(uVar5 + uVar4 * -0x16d) & 0xffff;
        puVar9 = &UNK_fffffff007115ce4;
      }
      if (uVar2 < 0x834) {
        uVar12 = 0;
        *puVar3 = (int)uVar2;
        lVar13 = 1;
        do {
          uVar12 = uVar12 + 1;
          lVar1 = lVar13 * 4;
          lVar13 = lVar13 + 1;
        } while (*(uint *)(puVar9 + lVar1) <= uVar11 && uVar12 < 0xc);
        *(char *)(puVar3 + 1) = (char)uVar12;
        *(char *)((long)puVar3 + 5) =
             ((char)uVar11 - (char)*(undefined4 *)(puVar9 + uVar12 * 4 + -4)) + '\x01';
      }
      (**(code **)(*param_1 + 0x38))(param_1);
      thunk_EXT_FUN_8011000003891b28();
      DAT_fffffff00ae21b18 = DAT_fffffff00ae21b18 + 1;
      thunk_EXT_FUN_80110000032222a8(param_1[0x2232]);
      (**(code **)(*(long *)param_1[0x96] + 0xa8))();
      thunk_EXT_FUN_8011000003222de0(param_1[0x2232]);
      lStack_68 = 0;
      uStack_6c = 0;
      thunk_EXT_FUN_8011000003203330(&lStack_68,&uStack_6c);
      lVar13 = (ulong)(DAT_fffffff00ae21b18 % 0x13) * 0x10;
      puVar3 = (undefined4 *)((long)(int)lVar13 + -0xff51de618);
      if (lVar13 != (int)lVar13) {
        puVar3 = (undefined4 *)(lVar13 - 0xff51de618U & 0xffffffffffff | 0x2bad000000000000);
      }
      uVar2 = lStack_68 - 0x6270;
      puVar3[3] = uStack_6c;
      auVar8._8_8_ = 0;
      auVar8._0_8_ = uVar2;
      uVar4 = (int)uVar2 + SUB164(auVar8 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
      *(char *)(puVar3 + 2) = (char)uVar4 + (char)(uVar4 / 0x3c) * -0x3c;
      *(char *)((long)puVar3 + 7) =
           (char)(uVar4 / 0x3c) + (char)((uVar4 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
      *(char *)((long)puVar3 + 6) = (char)(uVar4 / 0xe10);
      uVar2 = uVar2 / 0x15180 + 0x2db;
      uVar11 = uVar2 % 0x5b5;
      uVar2 = (uVar2 / 0x5b5) * 4 + 0x7b0;
      uVar5 = (int)uVar11 - 0x16e;
      uVar4 = (uVar5 & 0xffff) / 0x16d;
      puVar9 = &UNK_fffffff007115d18;
      if (0x16d < uVar11) {
        uVar2 = uVar2 + (uVar4 + 1);
        uVar11 = (ulong)(uVar5 + uVar4 * -0x16d) & 0xffff;
        puVar9 = &UNK_fffffff007115ce4;
      }
      if (uVar2 < 0x834) {
        uVar12 = 0;
        *puVar3 = (int)uVar2;
        lVar13 = 1;
        do {
          uVar12 = uVar12 + 1;
          lVar1 = lVar13 * 4;
          lVar13 = lVar13 + 1;
        } while (*(uint *)(puVar9 + lVar1) <= uVar11 && uVar12 < 0xc);
        *(char *)(puVar3 + 1) = (char)uVar12;
        *(char *)((long)puVar3 + 5) =
             ((char)uVar11 - (char)*(undefined4 *)(puVar9 + uVar12 * 4 + -4)) + '\x01';
      }
      (**(code **)(*param_1 + 0x38))(param_1);
      thunk_EXT_FUN_8011000003891b28();
      DAT_fffffff00ae21b18 = DAT_fffffff00ae21b18 + 1;
      (**(code **)(*param_1 + 0x718))(*param_1 + 0x718,param_1,"",0);
      thunk_EXT_FUN_8011000003222de0(param_1[0x234c]);
      (**(code **)(*param_1 + 0x920))(*param_1 + 0x920,param_1,1);
      iVar10 = (**(code **)(*(long *)param_1[0x96] + 0xd0))();
      if (iVar10 != 0) {
        (**(code **)(*param_1 + 0x828))(param_1);
        *(undefined1 *)(param_1 + 0xaf) = 1;
      }
    }
  }
  return;
}

