// FUN_fffffff00997eb7c @ fffffff00997eb7c size=500

undefined8
FUN_fffffff00997eb7c
          (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4,
          undefined8 param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  long *plVar4;
  long *plVar5;
  undefined8 uVar6;
  
  uVar6 = 0xe00002be;
  *param_4 = 0;
  plVar4 = (long *)FUN_fffffff009974c30(*(undefined8 *)(param_1 + 0xe0));
  plVar5 = (long *)thunk_EXT_FUN_80110000038d4814(param_2,0,0);
  if (plVar4 == (long *)0x0 || plVar5 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to serialize memory data\n");
    if (plVar5 == (long *)0x0) goto LAB_fffffff00997ed2c;
  }
  else {
    (**(code **)(*plVar5 + 0x80))(plVar5);
    iVar1 = (**(code **)(*plVar4 + 0x30))(plVar4,plVar5);
    if (iVar1 != 0) {
      uVar2 = (**(code **)(*plVar5 + 0xb8))(plVar5);
      *param_3 = uVar2;
      uVar3 = (**(code **)(*plVar5 + 0xb8))(plVar5);
      if (uVar3 <= (uint)param_2) {
        uVar2 = (**(code **)(*plVar5 + 0xb8))(plVar5);
        *param_4 = uVar2;
        uVar6 = (**(code **)(*plVar5 + 0x78))(plVar5);
        uVar2 = (**(code **)(*plVar5 + 0xb8))(plVar5);
        thunk_EXT_FUN_8011000003a61b10(param_5,uVar6,uVar2);
      }
      uVar6 = 0;
    }
  }
  (**(code **)(*plVar5 + 0x28))(plVar5);
LAB_fffffff00997ed2c:
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  return uVar6;
}

