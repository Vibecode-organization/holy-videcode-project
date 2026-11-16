// FUN_fffffff0081a6258 @ fffffff0081a6258 size=448

void FUN_fffffff0081a6258(long param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  long lVar5;
  undefined8 uVar6;
  ulong unaff_x30;
  int local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  uVar1 = *(undefined4 *)(param_1 + 0x8f0);
  uVar6 = *(undefined8 *)(param_1 + 0x900);
  thunk_EXT_FUN_80110000032222a8(uVar6);
  lVar5 = *(long *)(param_1 + 0x760);
  if (lVar5 != 0) {
    uVar2 = **(uint **)(param_1 + 0x758);
    *(uint *)(param_1 + 0x768) = uVar2;
    uVar3 = (*(uint **)(param_1 + 0x758))[8];
    *(uint *)(param_1 + 0x76c) = uVar3;
    if ((*(ulong *)(param_1 + 0x778) <= (ulong)uVar2) ||
       (*(ulong *)(param_1 + 0x778) <= (ulong)uVar3)) {
      thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! read_index out of bounds\n");
      return;
    }
    while (lVar5 != 0) {
      if (*(int *)(param_1 + 0x768) == *(int *)(param_1 + 0x76c)) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a638c);
          (*pcVar4)();
        }
        thunk_EXT_FUN_8011000003222de0(uVar6);
        return;
      }
      local_40 = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_48 = 0;
      uStack_50 = 0;
      uStack_78 = 0;
      uStack_74 = 0;
      local_80 = 0;
      uStack_7c = 0;
      uStack_68 = 0;
      local_64 = 0;
      uStack_70 = 0;
      local_6c = 0;
      FUN_fffffff0081b7c6c(param_1 + 0x750,&local_80);
      if (local_80 != 5) {
        thunk_EXT_FUN_8011000003a49114
                  ("AGXk: %s:%d:%s: !!! Ring is processing event of incorrect type\n");
        return;
      }
      thunk_EXT_FUN_80110000036dbc20
                (uVar1,(uint)uStack_50 | (uStack_54 & 0x3fff) << 2 | 0x85000000 |
                       uStack_54 * 0x100 + 0x900000 & 0xff0000,CONCAT44(uStack_78,uStack_7c),
                 CONCAT44(uStack_70,uStack_74),CONCAT44(uStack_68,local_6c),
                 CONCAT44(uStack_60,local_64),CONCAT44(uStack_58,uStack_5c),(int)uStack_54 >> 0x18);
      lVar5 = *(long *)(param_1 + 0x760);
    }
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Using uninitialized validator class\n");
  return;
}

