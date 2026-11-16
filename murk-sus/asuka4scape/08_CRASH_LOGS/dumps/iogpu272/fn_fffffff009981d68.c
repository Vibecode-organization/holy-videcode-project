// FUN_fffffff009981d68 @ fffffff009981d68 size=4

void FUN_fffffff009981d68(long param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  byte bVar8;
  undefined8 uVar9;
  long *plVar10;
  undefined8 uStack_58;
  
  uVar4 = thunk_EXT_FUN_8011000003977aa8(*(undefined8 *)(param_1 + 0x90));
  uVar1 = *(uint *)(param_1 + 0x30);
  bVar2 = *(byte *)(*(long *)(param_1 + 0x10) + 0x1fd);
  if (DAT_fffffff00af227e8 != 0) {
    uVar9 = *(undefined8 *)(param_1 + 0x38);
    uVar5 = thunk_EXT_FUN_801100000390ebc0();
    uStack_58 = 0;
    thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x90),&uStack_58);
    thunk_EXT_FUN_80110000036da494(0x85180029,uVar9,uVar5,uVar4,uStack_58,0);
    if (DAT_fffffff00af227e8 != 0) {
      uVar9 = *(undefined8 *)(param_1 + 0x38);
      uVar5 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
      uStack_58 = 0;
      thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x90),&uStack_58);
      thunk_EXT_FUN_80110000036da494(0x85220005,uVar9,uVar5,uVar4,uStack_58,0);
    }
  }
  plVar10 = *(long **)(param_1 + 0xe0);
  if (plVar10 != (long *)0x0) {
    uVar5 = (**(code **)(*plVar10 + 0x88))(plVar10);
    iVar3 = thunk_EXT_FUN_801100000397871c(plVar10,0,0,uVar5);
    if (iVar3 != 0) {
      thunk_EXT_FUN_8011000003a49114
                ("\"%s: 0x%X mapping is not valid for wireRange, cannot unwire PTEs\" @%s:%d");
      return;
    }
  }
  (**(code **)(**(long **)(param_1 + 0x90) + 0xe0))(*(long **)(param_1 + 0x90),0);
  if ((*(byte *)(param_1 + 0x30) >> 3 & 1) == 0) {
    bVar8 = *(byte *)(param_1 + 0x35);
    if (1 < bVar8 - 3) goto LAB_fffffff009981eec;
  }
  else {
    FUN_fffffff009981bfc(param_1,2,0);
    bVar8 = 3;
  }
  FUN_fffffff009981bfc(param_1,bVar8,0);
LAB_fffffff009981eec:
  if (DAT_fffffff00af227e8 != 0) {
    uVar9 = *(undefined8 *)(param_1 + 0x38);
    uVar5 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
    uStack_58 = 0;
    thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x90),&uStack_58);
    thunk_EXT_FUN_80110000036da494(0x8518002a,uVar9,uVar5,uVar4,uStack_58,0);
    if (DAT_fffffff00af227e8 != 0) {
      uVar5 = *(undefined8 *)(param_1 + 0x38);
      uVar4 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
      thunk_EXT_FUN_80110000036da494(0x85220006,uVar5,uVar4,0,0,0);
    }
  }
  FUN_fffffff0099758d8
            (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x38),
             uVar1 & (bVar2 & 0x3f) >> 5);
  if ((*(byte *)(param_1 + 0x30) >> 1 & 1) == 0) {
    FUN_fffffff00997db18(*(long *)(*(long *)(param_1 + 0x10) + 0x160) + 0x1b8,param_1);
  }
  if (DAT_fffffff00af227e8 != 0) {
    lVar6 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),0);
    lVar7 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),1);
    uVar4 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
    thunk_EXT_FUN_80110000036da494(0x85180034,lVar7 + lVar6,uVar4,0,0,0);
  }
  return;
}

