// FUN_fffffff0099765dc @ fffffff0099765dc size=540

undefined8 FUN_fffffff0099765dc(long param_1,long param_2,long param_3,long param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  iVar2 = (*DAT_fffffff007feb260)();
  uVar7 = 0;
  if (((param_3 != 0) && (param_2 != 0)) && (iVar2 != 0)) {
    *(long *)(param_1 + 0x530) = param_2;
    *(undefined4 *)(param_1 + 0x424) = 0xffffffff;
    uVar7 = thunk_EXT_FUN_80110000038ff010();
    *(undefined8 *)(param_1 + 0x458) = uVar7;
    uVar7 = thunk_EXT_FUN_80110000038ff010();
    *(undefined8 *)(param_1 + 0x528) = uVar7;
    lVar4 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1b38,0x2a8);
    *(long *)(param_1 + 0x430) = lVar4;
    if (((*(long *)(param_1 + 0x458) == 0) || (*(long *)(param_1 + 0x528) == 0)) || (lVar4 == 0)) {
      bVar1 = false;
      uVar7 = 0;
      if (lVar4 == 0) goto LAB_fffffff00997679c;
    }
    else {
      bVar1 = *(uint *)(param_4 + 0x400) < 5;
    }
    lVar4 = thunk_EXT_FUN_80110000038ff010();
    uVar7 = 0;
    *(long *)(*(long *)(param_1 + 0x430) + 0x298) = lVar4;
    if ((lVar4 != 0) && (bVar1)) {
      thunk_EXT_FUN_8011000003350958(param_1 + 0x10,param_4,0x400);
      *(bool *)(param_1 + 0x439) = *(char *)(param_4 + 0x404) != '\0';
      *(undefined4 *)(param_1 + 0x450) = *(undefined4 *)(param_4 + 0x400);
      *(undefined4 *)(param_1 + 0x454) = 0;
      uVar7 = 1;
      *(undefined4 *)(param_1 + 0x444) = 1;
      *(undefined8 *)(param_1 + 0x448) = 0x300000003;
      *(bool *)(param_1 + 0x527) = *(char *)(param_4 + 0x405) != '\0';
      *(long *)(param_1 + 0x488) = param_3;
      *(undefined4 *)(param_1 + 0x490) = *(undefined4 *)(param_3 + 0x60);
      plVar5 = (long *)FUN_fffffff0099676a8(param_3);
      *(long **)(param_1 + 0x480) = plVar5;
      (**(code **)(*plVar5 + 0x20))();
      *(undefined8 *)(param_1 + 0x460) = 0;
      *(long *)(param_1 + 0x468) = param_1 + 0x460;
      plVar5 = *(long **)(*(long *)(param_1 + 0x530) + 0x160);
      *(long **)(param_1 + 0x538) = plVar5;
      (**(code **)(*plVar5 + 0x20))();
      uVar6 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
      *(undefined8 *)(param_1 + 0x550) = uVar6;
      FUN_fffffff00994af14(param_1 + 0x498);
      FUN_fffffff00994af14(param_1 + 0x4d8);
      thunk_EXT_FUN_8011000003722ec0(param_1 + 0x588,0x40);
      uVar3 = FUN_fffffff009962f8c(*(undefined8 *)(param_1 + 0x538),param_1);
      *(undefined4 *)(param_1 + 0x424) = uVar3;
    }
  }
LAB_fffffff00997679c:
  if (DAT_fffffff00af227e8 != 0) {
    uVar8 = *(undefined8 *)(*(long *)(param_1 + 0x488) + 0x38);
    uVar9 = *(undefined8 *)(param_1 + 0x550);
    uVar6 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x530));
    thunk_EXT_FUN_80110000036da494(0x85090018,uVar8,uVar9,uVar6,uVar7,0);
  }
  return uVar7;
}

