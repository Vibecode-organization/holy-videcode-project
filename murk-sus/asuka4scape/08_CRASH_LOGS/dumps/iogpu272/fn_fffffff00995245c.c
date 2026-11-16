// FUN_fffffff00995245c @ fffffff00995245c size=4

undefined8 FUN_fffffff00995245c(long *param_1,long param_2,long param_3,undefined1 param_4)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined4 uStack_34;
  
  (*DAT_fffffff007feb260)();
  lVar2 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
  param_1[0xe] = lVar2;
  uStack_34 = 0;
  param_1[10] = param_2;
  if ((*(byte *)(param_2 + 0x1fc) >> 2 & 1) == 0) {
    *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x10000;
  }
  if (param_3 != 0) {
    plVar3 = *(long **)(param_3 + 0x30);
    param_1[0xd] = (long)plVar3;
    (**(code **)(*plVar3 + 0x20))();
  }
  *(undefined1 *)(param_1 + 2) = param_4;
  if (param_1[0xd] == 0) {
    lVar2 = (**(code **)(*(long *)param_1[10] + 0x578))();
    param_1[3] = lVar2;
    if (lVar2 == 0) {
      return 0;
    }
    uVar5 = 0;
  }
  else {
    uVar4 = FUN_fffffff009963d30(param_1[0xd],&uStack_34);
    if ((uVar4 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Couldn\'t allocate object_handle\n\n");
      return 0;
    }
    iVar1 = FUN_fffffff0099640c0(param_1[0xd],uStack_34,param_1 + 3);
    if (iVar1 == 0) {
      FUN_fffffff009964010(param_1[0xd],uStack_34);
      return 0;
    }
    lVar2 = param_1[3];
    uVar5 = uStack_34;
  }
  *(undefined4 *)((long)param_1 + 0x8c) = uVar5;
  (**(code **)(*param_1 + 0x98))(param_1,lVar2);
  return 1;
}

