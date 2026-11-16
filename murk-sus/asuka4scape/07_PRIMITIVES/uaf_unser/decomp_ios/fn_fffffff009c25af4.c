// FUN_fffffff009c25af4 @ fffffff009c25af4 size=836
// CALLERS:
//   fffffff009c3d6dc FUN_fffffff009c3d564@fffffff009c3d564

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_fffffff009c25af4(long param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  long *plVar6;
  ulong uVar7;
  undefined4 uVar8;
  long *plVar9;
  undefined1 auStack_6c [4];
  long local_68;
  
  local_68 = *_DAT_fffffff00806ca40;
  iVar1 = FUN_fffffff009c371e8(_DAT_fffffff00af483b0);
  if (iVar1 == 0) {
    uVar8 = 0;
    goto LAB_fffffff009c25da4;
  }
  uVar8 = 0xe00002bc;
  if (param_4 == (long *)0x0) {
    uVar2 = FUN_fffffff009c49c54();
    param_4 = (long *)FUN_fffffff009c49a84(uVar2,0x40);
    if (param_4 == (long *)0x0) {
      FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a00f2);
      goto LAB_fffffff009c25da4;
    }
    (**(code **)(*param_4 + 0x28))();
  }
  FUN_fffffff009c495b4(*(undefined8 *)(param_1 + 0x50));
  plVar3 = (long *)FUN_fffffff009c259a0(param_1,0xfffffff00789b25d,auStack_6c);
  uVar2 = *_DAT_fffffff00806c9c8;
  plVar4 = (long *)FUN_fffffff009c498d4(plVar3,uVar2);
  if (plVar4 == (long *)0x0) {
    plVar9 = (long *)FUN_fffffff009c49864(1);
    if (plVar9 == (long *)0x0) {
      FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0127);
    }
    else {
      uVar7 = FUN_fffffff009c25a44(param_1,0xfffffff00789b25d,plVar9,auStack_6c);
      plVar4 = plVar9;
      if ((uVar7 & 1) != 0) goto LAB_fffffff009c25bc8;
      FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a015e);
    }
LAB_fffffff009c25e24:
    FUN_fffffff009c495d4(*(undefined8 *)(param_1 + 0x50));
  }
  else {
    plVar9 = (long *)0x0;
LAB_fffffff009c25bc8:
    uVar5 = (**(code **)(*plVar4 + 0x138))(plVar4,param_2);
    plVar6 = (long *)FUN_fffffff009c498d4(uVar5,uVar2);
    if (plVar6 == (long *)0x0) {
      plVar6 = (long *)FUN_fffffff009c49864(1);
      if (plVar6 == (long *)0x0) {
        FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a019b);
        goto LAB_fffffff009c25e24;
      }
      uVar7 = (**(code **)(*plVar4 + 0x100))(plVar4,param_2,plVar6);
      plVar4 = plVar6;
      if ((uVar7 & 1) != 0) goto LAB_fffffff009c25c04;
      FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a01d8);
      FUN_fffffff009c495d4(*(undefined8 *)(param_1 + 0x50));
    }
    else {
      plVar4 = (long *)0x0;
LAB_fffffff009c25c04:
      iVar1 = (**(code **)(*plVar6 + 0x100))(plVar6,param_3,param_4);
      uVar8 = 0;
      if (iVar1 == 0) {
        uVar8 = 0xe00002bc;
      }
      FUN_fffffff009c495d4(*(undefined8 *)(param_1 + 0x50));
      plVar6 = plVar4;
      if (plVar4 == (long *)0x0) goto joined_r0xfffffff009c25e2c;
    }
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
joined_r0xfffffff009c25e2c:
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 0x28))(plVar9);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
LAB_fffffff009c25da4:
  if (*_DAT_fffffff00806ca40 != local_68) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c49b64();
  }
  return uVar8;
}

