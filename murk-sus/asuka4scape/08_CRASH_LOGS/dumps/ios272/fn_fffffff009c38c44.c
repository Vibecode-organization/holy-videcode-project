// FUN_fffffff009c38c44 @ fffffff009c38c44 size=4

undefined8 FUN_fffffff009c38c44(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  uint uStack_6c;
  long lStack_68;
  
  lStack_68 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar3 = 0xe00002c8;
  lVar4 = *(long *)(param_3 + 0x30);
  lVar5 = *(long *)(param_3 + 0x58);
  uVar6 = (ulong)*(uint *)(param_3 + 0x38);
  uVar7 = *(uint *)(param_3 + 0x60);
  plVar1 = *(long **)(param_3 + 0x40);
  uStack_6c = uVar7;
  if (plVar1 == (long *)0x0) {
    plVar1 = (long *)0x0;
LAB_fffffff009c38d20:
    plVar2 = *(long **)(param_3 + 0x68);
    if (plVar2 == (long *)0x0) {
      plVar2 = (long *)0x0;
    }
    else {
      plVar2 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0);
      if (plVar2 == (long *)0x0) goto LAB_fffffff009c38dec;
      lVar5 = (**(code **)(*plVar2 + 0x78))();
      uVar7 = *(uint *)(param_3 + 0x70);
      uStack_6c = uVar7;
    }
    if (((lVar4 == 0 || (uint)uVar6 < 0xd) || lVar5 == 0) || uVar7 < 0xd) {
      uVar3 = 0xe00002c2;
    }
    else {
      uVar3 = FUN_fffffff009c3c538(param_1,lVar4,lVar5,uVar6,&uStack_6c);
      uVar7 = uStack_6c;
    }
    if (plVar2 != (long *)0x0) {
      *(uint *)(param_3 + 0x70) = uVar7;
      (**(code **)(*plVar2 + 0x28))(plVar2);
      goto joined_r0xfffffff009c38dc0;
    }
  }
  else {
    plVar1 = (long *)(**(code **)(*plVar1 + 0xe8))(plVar1,0x1000);
    if (plVar1 != (long *)0x0) {
      lVar4 = (**(code **)(*plVar1 + 0x78))(plVar1);
      uVar6 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
      goto LAB_fffffff009c38d20;
    }
  }
LAB_fffffff009c38dec:
  *(uint *)(param_3 + 0x60) = uVar7;
joined_r0xfffffff009c38dc0:
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != lStack_68) {
    uVar3 = thunk_EXT_FUN_8011000003a48590();
    return uVar3;
  }
  return uVar3;
}

