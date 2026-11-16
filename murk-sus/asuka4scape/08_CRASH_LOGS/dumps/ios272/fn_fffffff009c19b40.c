// FUN_fffffff009c19b40 @ fffffff009c19b40 size=972

ulong FUN_fffffff009c19b40(long param_1,undefined8 param_2,long param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  undefined8 uVar9;
  int iVar10;
  undefined *local_138;
  undefined8 local_130;
  code *local_128;
  undefined *local_120;
  undefined8 *puStack_118;
  undefined8 local_110;
  int local_108;
  undefined *local_100;
  undefined8 local_f8;
  code *local_f0;
  undefined *local_e8;
  undefined8 *local_e0;
  undefined8 uStack_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined8 *local_c0;
  undefined8 local_b8;
  undefined1 local_b0;
  undefined *local_a8;
  undefined8 local_a0;
  code *local_98;
  undefined *local_90;
  long lStack_88;
  long local_80;
  
  local_80 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar2 = FUN_fffffff009c31474();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  plVar8 = *(long **)(param_1 + 0x18);
  if (plVar8 == (long *)0x0) {
    plVar8 = (long *)thunk_EXT_FUN_80110000038ccc44(0x40);
  }
  else {
    iVar3 = (**(code **)(*plVar8 + 0x90))(plVar8);
    plVar8 = (long *)thunk_EXT_FUN_80110000038cce40(plVar8,iVar3 + 0x40);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  plVar5 = (long *)FUN_fffffff009c198e8(param_1);
  iVar3 = (**(code **)(*plVar5 + 0x90))();
  if (0 < iVar3) {
    iVar10 = 0;
    do {
      lVar6 = (**(code **)(*plVar5 + 0x118))(plVar5,iVar10);
      uVar9 = *(undefined8 *)(lVar6 + 0x10);
      if (plVar8 != (long *)0x0) {
        (**(code **)(*plVar8 + 0x20))(plVar8);
      }
      FUN_fffffff009c279f0(uVar9,lVar6,plVar8);
      iVar10 = iVar10 + 1;
    } while (iVar3 != iVar10);
  }
  if (param_3 != 0) {
    (**(code **)(*plVar8 + 0xf0))(plVar8,param_3);
  }
  local_a8 = PTR_DAT_fffffff00806c9b8;
  local_a0 = DAT_fffffff0078a1280;
  local_98 = FUN_fffffff009c19f0c;
  local_90 = &DAT_fffffff008066d78;
  lStack_88 = param_1;
  thunk_EXT_FUN_801100000389794c(&local_90,plVar8,&local_a8);
  uVar9 = DAT_fffffff0078a1290;
  local_e0 = &local_c8;
  local_c8 = 0;
  local_b8 = DAT_fffffff0078a1288;
  local_b0 = 0;
  local_100 = PTR_DAT_fffffff00806c9b8;
  local_f8 = DAT_fffffff0078a1290;
  local_f0 = FUN_fffffff009c19f18;
  local_e8 = &DAT_fffffff008066d98;
  uStack_d8 = param_2;
  local_d0 = uVar2;
  local_c0 = local_e0;
  thunk_EXT_FUN_801100000389794c(plVar8,&local_100);
  if ((*(byte *)(local_c0 + 3) & 1) == 0) {
    FUN_fffffff009c31464();
    uVar4 = FUN_fffffff009c37a94();
    if (param_4 + 1U < uVar4) {
      local_138 = PTR_DAT_fffffff00806c9b8;
      local_130 = uVar9;
      local_128 = FUN_fffffff009c1a104;
      puStack_118 = &local_c8;
      local_120 = &DAT_fffffff008066dc8;
      local_110 = param_2;
      local_108 = param_4;
      thunk_EXT_FUN_801100000389794c(plVar8,&local_138);
    }
    else if ((DAT_fffffff00af48570 & 1) == 0) {
      DAT_fffffff00af48570 = 1;
      FUN_fffffff009c31464();
      FUN_fffffff009c37a94();
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0,
                 "IOSurfaceRoot: deadlock detection depth limit %d reached\n");
    }
  }
  bVar1 = *(byte *)(local_c0 + 3);
  thunk_EXT_FUN_80110000038e9dac(&local_c8,8);
  (**(code **)(*plVar5 + 0x28))(plVar5);
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_80) {
    return (ulong)(bVar1 & 1);
  }
  uVar7 = thunk_EXT_FUN_8011000003a48590();
  return uVar7;
}

