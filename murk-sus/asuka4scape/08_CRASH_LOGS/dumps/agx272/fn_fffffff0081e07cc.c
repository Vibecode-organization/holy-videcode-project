// FUN_fffffff0081e07cc @ fffffff0081e07cc size=392

undefined8 FUN_fffffff0081e07cc(long param_1,long param_2,long param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  
  lVar3 = thunk_EXT_FUN_80110000038ff010();
  *(long *)(param_1 + 0x40) = lVar3;
  if ((lVar3 == 0) || (iVar2 = (**(code **)(PTR_DAT_fffffff007ca60e0 + 0x78))(param_1), iVar2 == 0))
  {
    uVar6 = 0;
  }
  else {
    uVar6 = 0;
    *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(param_2 + 0x11da0);
    uVar1 = *(uint *)PTR_DAT_fffffff007ca5f88;
    *(uint *)(param_1 + 0x28) = param_4 | 0x100023;
    lVar3 = (long)(1 << (ulong)(uVar1 & 0x1f));
    uVar7 = (param_3 + lVar3) - 1U & -lVar3;
    *(ulong *)(param_1 + 0x30) = uVar7;
    if (*(char *)(param_2 + 0x1fc) < '\0') {
      uVar6 = *(undefined8 *)(param_1 + 0x10);
    }
    plVar4 = (long *)thunk_EXT_FUN_801100000297cd4c(param_2,uVar6,0,0,param_4 | 0x100023,uVar7,0);
    uVar6 = 0;
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x20))(plVar4);
      (**(code **)(*plVar4 + 0x28))(plVar4);
      if (*(long *)(param_1 + 0x10) != *(long *)PTR_DAT_fffffff007ca61d0) {
        uVar6 = thunk_EXT_FUN_801100000297dd00(plVar4);
        thunk_EXT_FUN_8011000003977b2c(uVar6,*(undefined8 *)(param_1 + 0x10),4,4);
      }
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x20) = 0;
      *(undefined8 *)(param_1 + 0x38) = 0;
      *(long **)(param_1 + 0x48) = plVar4;
      *(undefined8 *)(param_1 + 0x50) = 0;
      thunk_EXT_FUN_801100000297dcd4(plVar4);
      uVar6 = 1;
      uVar5 = thunk_EXT_FUN_80110000038905f0(1,PTR_DAT_fffffff007ca6190);
      *(undefined8 *)(param_1 + 0x68) = uVar5;
    }
  }
  return uVar6;
}

