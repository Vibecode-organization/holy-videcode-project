// FUN_fffffff0081b6674 @ fffffff0081b6674 size=912

void FUN_fffffff0081b6674(long *param_1,int param_2,long param_3)

{
  bool bVar1;
  byte bVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  ulong unaff_x30;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)((long)param_1 + 0x8f4) = 1;
      *(int *)((long)param_1 + 0x8fc) = (int)param_1[0x11f];
      *(int *)param_1[0x107] = (int)param_1[0x11f];
      (**(code **)(*param_1 + 0x1b8))();
      puVar7 = (undefined8 *)(**(long **)(param_1[0x50] + 0x310) + 0xe8);
      (*(code *)*puVar7)(puVar7,*(long **)(param_1[0x50] + 0x310),FUN_fffffff00817eecc,0,0,0,0);
      lVar5 = param_1[0x50];
      if ((*(byte *)(lVar5 + 0x1ac44) >> 2 & 1) == 0) {
        return;
      }
      lVar6 = *(long *)(lVar5 + 0x1ac50);
      if (*(long *)(lVar6 + 0x1300) == *(long *)(lVar6 + 0x550)) {
        uVar8 = 0;
      }
      else {
        uVar8 = 0xffffffffffffffff;
        if (*(long *)(lVar6 + 0x1308) == *(long *)(lVar6 + 0x550)) {
          uVar8 = 1;
        }
      }
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85920804,uVar8,0xffff,0xffff,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
      lVar5 = param_1[0x50];
      if ((*(byte *)(lVar5 + 0x1ac44) >> 2 & 1) == 0) {
        return;
      }
      uVar8 = *(undefined8 *)(*(long *)(lVar5 + 0x1ac50) + 0x530);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85920800,uVar8,0xffff,0xffff,0xffff,0);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b6a00);
        (*pcVar3)();
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
      return;
    }
    if (param_2 != 1) {
      return;
    }
    *(undefined1 *)((long)param_1 + 0x8f4) = 0;
    *(undefined4 *)((long)param_1 + 0x8fc) = 0;
    *(undefined4 *)param_1[0x107] = 0;
    goto LAB_fffffff0081b6900;
  }
  if (param_2 == 2) {
    if (*(int *)((long)param_1 + 0x8fc) == 0) {
      return;
    }
    puVar7 = (undefined8 *)(**(long **)(param_1[0x50] + 0x310) + 0xe8);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b6808);
      (*pcVar3)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081b6810. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar7)(*(long **)(param_1[0x50] + 0x310),FUN_fffffff00817eed8,0,0,0,0,puVar7);
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *(undefined4 *)(param_1 + 0x11f) = 0;
  bVar2 = *(byte *)(param_3 + 0x10b2);
  bVar1 = (bVar2 & 1) != 0;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x11f) = 1;
    bVar2 = *(byte *)(param_3 + 0x10b2);
  }
  uVar4 = (uint)bVar1;
  if ((bVar2 >> 1 & 1) != 0) {
    uVar4 = uVar4 | 2;
    *(uint *)(param_1 + 0x11f) = uVar4;
    bVar2 = *(byte *)(param_3 + 0x10b2);
  }
  if ((bVar2 >> 2 & 1) == 0) {
    if ((bVar2 >> 3 & 1) == 0) goto LAB_fffffff0081b6838;
LAB_fffffff0081b6874:
    uVar4 = uVar4 | 8;
    *(uint *)(param_1 + 0x11f) = uVar4;
    bVar2 = *(byte *)(param_3 + 0x10b2);
    if ((bVar2 >> 4 & 1) != 0) goto LAB_fffffff0081b6884;
LAB_fffffff0081b683c:
    if ((bVar2 >> 5 & 1) == 0) goto LAB_fffffff0081b6840;
LAB_fffffff0081b6894:
    uVar4 = uVar4 | 0x20;
    *(uint *)(param_1 + 0x11f) = uVar4;
    bVar2 = *(byte *)(param_3 + 0x10b2);
    if ((bVar2 >> 6 & 1) != 0) goto LAB_fffffff0081b68a4;
LAB_fffffff0081b6844:
    if (-1 < (char)bVar2) goto LAB_fffffff0081b6848;
LAB_fffffff0081b68b4:
    uVar4 = uVar4 | 0x80;
    *(uint *)(param_1 + 0x11f) = uVar4;
    bVar2 = *(byte *)(param_3 + 0x10b3);
    if ((bVar2 & 1) != 0) goto LAB_fffffff0081b68c4;
LAB_fffffff0081b6850:
    if ((bVar2 >> 1 & 1) == 0) goto LAB_fffffff0081b6854;
LAB_fffffff0081b68d4:
    uVar4 = uVar4 | 0x200;
    *(uint *)(param_1 + 0x11f) = uVar4;
    if ((*(byte *)(param_3 + 0x10b3) >> 2 & 1) != 0) goto LAB_fffffff0081b68e4;
LAB_fffffff0081b6858:
    bVar2 = *(byte *)((long)param_1 + 0x8f4);
  }
  else {
    uVar4 = uVar4 | 4;
    *(uint *)(param_1 + 0x11f) = uVar4;
    bVar2 = *(byte *)(param_3 + 0x10b2);
    if ((bVar2 >> 3 & 1) != 0) goto LAB_fffffff0081b6874;
LAB_fffffff0081b6838:
    if ((bVar2 >> 4 & 1) == 0) goto LAB_fffffff0081b683c;
LAB_fffffff0081b6884:
    uVar4 = uVar4 | 0x10;
    *(uint *)(param_1 + 0x11f) = uVar4;
    bVar2 = *(byte *)(param_3 + 0x10b2);
    if ((bVar2 >> 5 & 1) != 0) goto LAB_fffffff0081b6894;
LAB_fffffff0081b6840:
    if ((bVar2 >> 6 & 1) == 0) goto LAB_fffffff0081b6844;
LAB_fffffff0081b68a4:
    uVar4 = uVar4 | 0x40;
    *(uint *)(param_1 + 0x11f) = uVar4;
    if (*(char *)(param_3 + 0x10b2) < '\0') goto LAB_fffffff0081b68b4;
LAB_fffffff0081b6848:
    bVar2 = *(byte *)(param_3 + 0x10b3);
    if ((bVar2 & 1) == 0) goto LAB_fffffff0081b6850;
LAB_fffffff0081b68c4:
    uVar4 = uVar4 | 0x100;
    *(uint *)(param_1 + 0x11f) = uVar4;
    bVar2 = *(byte *)(param_3 + 0x10b3);
    if ((bVar2 >> 1 & 1) != 0) goto LAB_fffffff0081b68d4;
LAB_fffffff0081b6854:
    if ((bVar2 >> 2 & 1) == 0) goto LAB_fffffff0081b6858;
LAB_fffffff0081b68e4:
    uVar4 = uVar4 | 0x400;
    *(uint *)(param_1 + 0x11f) = uVar4;
    bVar2 = *(byte *)((long)param_1 + 0x8f4);
  }
  if ((bVar2 & 1) == 0) {
    return;
  }
  *(uint *)((long)param_1 + 0x8fc) = uVar4;
  *(uint *)param_1[0x107] = uVar4;
LAB_fffffff0081b6900:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b6940);
    (*pcVar3)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081b6948. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x1b8))(param_1,(undefined8 *)(*param_1 + 0x1b8));
  return;
}

