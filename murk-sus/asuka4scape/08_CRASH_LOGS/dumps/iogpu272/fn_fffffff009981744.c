// FUN_fffffff009981744 @ fffffff009981744 size=1208

ulong FUN_fffffff009981744(long param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  undefined8 in_x6;
  undefined8 in_x7;
  long *plVar10;
  uint uVar11;
  undefined8 uVar12;
  char *pcVar13;
  undefined8 local_58;
  
  uVar4 = thunk_EXT_FUN_8011000003977aa8(*(undefined8 *)(param_1 + 0x90));
  uVar5 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1 + 0xa8) = uVar5;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  if (DAT_fffffff00af227e8 != 0) {
    uVar12 = *(undefined8 *)(param_1 + 0x38);
    local_58 = 0;
    thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x90),&local_58);
    uVar5 = local_58;
    uVar6 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
    thunk_EXT_FUN_80110000036da494(0x85180025,uVar12,uVar5,uVar6,uVar4,0);
    if (DAT_fffffff00af227e8 != 0) {
      uVar12 = *(undefined8 *)(param_1 + 0x38);
      local_58 = 0;
      thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x90),&local_58);
      uVar5 = local_58;
      uVar6 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
      thunk_EXT_FUN_80110000036da494(0x85220001,uVar12,uVar5,uVar6,uVar4,0);
    }
  }
  if ((*(char *)(param_1 + 0x35) != '\x02') &&
     (iVar3 = FUN_fffffff009981bfc(param_1,2,0), iVar3 != 0)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: failed to mark memory %p non-volatile Error 0x%x\n");
  }
  uVar2 = *(uint *)(param_1 + 0x30) & (*(byte *)(*(long *)(param_1 + 0x10) + 0x1fd) & 0x3f) >> 5;
  if ((*(uint *)(param_1 + 0x30) >> 2 & 1) == 0) {
    uVar7 = FUN_fffffff0099758f0();
    if ((uVar7 & 1) == 0) {
      if (DAT_fffffff00af227e8 != 0) {
        uVar5 = *(undefined8 *)(param_1 + 0x38);
        uVar4 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
        thunk_EXT_FUN_80110000036da494(0x85180026,uVar5,0,uVar4,0,0);
        if (DAT_fffffff00af227e8 != 0) {
          uVar5 = *(undefined8 *)(param_1 + 0x38);
          uVar4 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
          thunk_EXT_FUN_80110000036da494(0x85220002,uVar5,0,uVar4,0,0);
        }
      }
      uVar4 = thunk_EXT_FUN_8011000003397c88();
      *(undefined8 *)(param_1 + 0xd8) = uVar4;
      return 0xe00002be;
    }
  }
  else {
    FUN_fffffff0099758c4(*(long *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x38),uVar2);
  }
  lVar8 = *(long *)(param_1 + 0x10);
  uVar1 = *(uint *)(lVar8 + 0x1f0) >> 2 & 0x20;
  iVar3 = *(int *)(param_1 + 0x7c);
  uVar11 = uVar1;
  if (iVar3 == 1) {
    uVar11 = (*(uint *)(lVar8 + 0x1fc) >> 0xf & 0x100 | uVar1) ^ 0x100;
  }
  FUN_fffffff009975c34(lVar8,0x10000000000);
  uVar4 = (**(code **)(**(long **)(param_1 + 0x90) + 0xd8))(*(long **)(param_1 + 0x90),uVar11);
  if (iVar3 == 1) {
    if ((int)uVar4 == -0x1ffffd28) {
      *(undefined4 *)(param_1 + 0x7c) = 4;
      uVar4 = (**(code **)(**(long **)(param_1 + 0x90) + 0xd8))(*(long **)(param_1 + 0x90),uVar1);
    }
    else {
      *(undefined4 *)(param_1 + 0x7c) = 2;
    }
  }
  FUN_fffffff009975c44(*(undefined8 *)(param_1 + 0x10),0x10000000000);
  uVar5 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1 + 0xd8) = uVar5;
  iVar3 = (int)uVar4;
  if (iVar3 == 0) {
    plVar10 = *(long **)(param_1 + 0xe0);
    if (plVar10 != (long *)0x0) {
      uVar4 = (**(code **)(*plVar10 + 0x88))(plVar10);
      iVar3 = thunk_EXT_FUN_801100000397871c(plVar10,3,0,uVar4);
      if (iVar3 != 0) {
        uVar7 = thunk_EXT_FUN_8011000003a49114
                          (
                          "\"%s: 0x%X mapping is not valid for wireRange, cannot wire PTEs\" @%s:%d"
                          );
        return uVar7;
      }
    }
    if (DAT_fffffff00af227e8 != 0) {
      uVar5 = *(undefined8 *)(param_1 + 0x38);
      uVar4 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
      thunk_EXT_FUN_80110000036da494(0x85180026,uVar5,1,uVar4,0,0);
      if (DAT_fffffff00af227e8 != 0) {
        uVar5 = *(undefined8 *)(param_1 + 0x38);
        uVar4 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
        thunk_EXT_FUN_80110000036da494(0x85220002,uVar5,1,uVar4,0,0);
      }
    }
    if ((*(byte *)(param_1 + 0x30) >> 1 & 1) == 0) {
      FUN_fffffff00997d900(*(long *)(*(long *)(param_1 + 0x10) + 0x160) + 0x1b8,param_1);
    }
    if (DAT_fffffff00af227e8 != 0) {
      lVar8 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),0);
      lVar9 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x10),1);
      uVar4 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
      thunk_EXT_FUN_80110000036da494(0x85180034,lVar9 + lVar8,uVar4,0,0,0);
    }
    uVar7 = 0;
  }
  else {
    uVar5 = *(undefined8 *)(param_1 + 0x90);
    pcVar13 = "virtual IOReturn IOGPUSysMemory::wire()";
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: memory %p failed to prepare. Error 0x%x\n");
    if (DAT_fffffff00af227e8 != 0) {
      uVar12 = *(undefined8 *)(param_1 + 0x38);
      uVar6 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
      thunk_EXT_FUN_80110000036da494(0x85180026,uVar12,0,uVar6,0,0,in_x6,in_x7,pcVar13,uVar5,uVar4);
      if (DAT_fffffff00af227e8 != 0) {
        uVar12 = *(undefined8 *)(param_1 + 0x38);
        uVar6 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
        thunk_EXT_FUN_80110000036da494
                  (0x85220002,uVar12,0,uVar6,0,0,in_x6,in_x7,pcVar13,uVar5,uVar4);
      }
    }
    FUN_fffffff0099758d8(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x38),uVar2);
    uVar2 = 0xe00002d8;
    if (iVar3 != -0x1ffffd28) {
      uVar2 = 0xe00002bd;
    }
    uVar7 = (ulong)uVar2;
  }
  return uVar7;
}

