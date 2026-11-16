// FUN_fffffff0081920f4 @ fffffff0081920f4 size=584

ulong FUN_fffffff0081920f4
                (long param_1,long param_2,undefined8 param_3,ulong param_4,long param_5,
                undefined8 param_6,undefined8 param_7,long param_8)

{
  char *pcVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  if ((param_4 & 1) != 0) {
    if (param_8 == 0) {
      thunk_EXT_FUN_80110000029615ec(*(undefined8 *)(param_1 + 0x488));
    }
    plVar3 = (long *)(**(code **)(DAT_fffffff00ae21e00 + 0x68))();
    uVar8 = *(undefined8 *)(param_1 + 0x530);
    uVar9 = *(undefined8 *)(param_1 + 0x480);
    pcVar1 = (char *)0x0;
    if (*(char *)(param_2 + 0x10) != '\0') {
      pcVar1 = (char *)(param_2 + 0x10);
    }
    uVar7 = *(undefined8 *)(param_5 + 0x78);
    uVar4 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x580),&DAT_fffffff00ae22130);
    (**(code **)(*plVar3 + 0xe8))(plVar3,uVar8,param_1,uVar9,pcVar1,uVar7,uVar4);
    thunk_EXT_FUN_801100000296a540(plVar3,*(long *)(*(long *)(param_5 + 0x70) + 0x20) + 0x20);
    lVar6 = *(long *)(*(long *)(param_1 + 0x488) + 0x1e0);
    if (lVar6 != 0) {
      if (*(long *)(lVar6 + 0x50) != 0) {
        thunk_EXT_FUN_8011000002969a34(plVar3);
      }
      if (*(long *)(lVar6 + 0x58) != 0) {
        thunk_EXT_FUN_8011000002969a34(plVar3);
      }
    }
    uVar5 = FUN_fffffff008193c64(param_1,plVar3,param_5,param_2,param_8,param_3,param_6,param_7);
    if ((uVar5 & 1) == 0) {
      if (param_8 == 0) {
        thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
      }
    }
    else {
      iVar2 = *(int *)(param_1 + 0x844);
      *(int *)(plVar3 + 0x3b) = iVar2;
      *(int *)(param_1 + 0x844) = iVar2 + 1;
      if (param_8 == 0) {
        thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
      }
      if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac44) >> 3 & 1) != 0) {
        FUN_fffffff00817dc48
                  (*(long *)(param_1 + 0x530),0x30d,0,*(undefined4 *)((long)plVar3 + 0x534),
                   *(undefined8 *)(param_1 + 0x410),plVar3[0x20],
                   *(undefined8 *)(*(long *)(param_1 + 0x810) + 0x30),0);
      }
      if (param_8 == 0) {
        FUN_fffffff008193af4
                  (param_1,plVar3,*(undefined8 *)(param_1 + 0x820),*(undefined8 *)(param_1 + 0x810))
        ;
      }
      else {
        uVar8 = *(undefined8 *)(param_1 + 0x820);
        *(long **)(param_8 + 0x38) = plVar3;
        *(undefined8 *)(param_8 + 0x40) = uVar8;
        *(undefined8 *)(param_8 + 0x48) = *(undefined8 *)(param_1 + 0x810);
      }
    }
    return uVar5;
  }
  uVar5 = thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
  return uVar5;
}

