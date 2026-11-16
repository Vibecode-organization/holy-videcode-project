// FUN_fffffff009942c08 @ fffffff009942c08 size=220

undefined8 FUN_fffffff009942c08(long *param_1)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  long *plVar6;
  long in_xzr;
  
  uVar2 = *(uint *)((long)param_1 + 0x24);
  if (uVar2 == 0) {
    uVar5 = 1;
  }
  else if (uVar2 < 4 && uVar2 != 1) {
    thunk_EXT_FUN_80110000032222a8(param_1[9]);
    uVar2 = *(uint *)((long)param_1 + 0x24);
    uVar4 = (ulong)uVar2;
    if ((uVar2 >> 1 & 1) == 0) {
      uVar5 = 1;
    }
    else {
      uVar4 = (ulong)(uVar2 & 3);
      puVar1 = (uint *)((long)param_1 + 0x24);
      if (*puVar1 == (uVar2 & 3)) {
        *puVar1 = 2;
        plVar6 = param_1 + 5;
        FUN_fffffff0099438ec(param_1,*plVar6);
        (**(code **)(*param_1 + 0xd0))(param_1);
        param_1[8] = 0;
        lVar3 = *plVar6;
        *plVar6 = in_xzr;
        LORelease();
        uVar2 = *puVar1;
        *puVar1 = uVar2 & 0xfffffffd;
        uVar4 = CONCAT44((int)((ulong)lVar3 >> 0x20),uVar2);
        LORelease();
        uVar5 = 1;
        *(undefined4 *)((long)param_1 + 0x7c) = 1;
      }
      else {
        uVar5 = 0;
      }
    }
    thunk_EXT_FUN_8011000003222de0(uVar4,param_1[9]);
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

