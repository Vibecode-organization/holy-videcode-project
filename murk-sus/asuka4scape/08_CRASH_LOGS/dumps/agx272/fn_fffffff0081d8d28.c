// FUN_fffffff0081d8d28 @ fffffff0081d8d28 size=296

undefined8
FUN_fffffff0081d8d28
          (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined4 *param_5,
          undefined8 param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  
  if (param_2 != DAT_fffffff00ae228d0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d8e44);
      (*pcVar2)();
    }
    uVar5 = FUN_fffffff0081a1d0c(param_1);
    return uVar5;
  }
  if (*(long *)(param_1 + 0x1acf0) == 0) {
    return 0xe00002bc;
  }
  if ((*(byte *)(*(long *)(param_1 + 0x1acf0) + 0x18) & 1) == 0) {
    return 0xe00002bc;
  }
  if (param_5 != (undefined4 *)0x0) {
    plVar4 = *(long **)(param_1 + 0x4b0);
    uVar5 = 0xe00002bc;
    if (plVar4 == (long *)0x0) goto LAB_fffffff0081d8de4;
    uVar1 = *param_5;
    thunk_EXT_FUN_80110000032222a8(plVar4[0x178]);
    *(undefined4 *)((long)plVar4 + 0xbac) = uVar1;
    if ((*(byte *)((long)plVar4 + 0xba4) & 1) == 0) {
      uVar1 = (undefined4)plVar4[0x175];
    }
    (**(code **)(*plVar4 + 0x9e0))(plVar4,uVar1,0);
    thunk_EXT_FUN_8011000003222de0(plVar4[0x178]);
  }
  uVar5 = 0;
LAB_fffffff0081d8de4:
  uVar3 = uVar5;
  if ((param_7 != (undefined4 *)0x0) && (uVar3 = 0xe00002bc, *(long *)(param_1 + 0x4b0) != 0)) {
    FUN_fffffff0081a8898(*(long *)(param_1 + 0x4b0),2,*param_7,0);
    uVar3 = uVar5;
  }
  return uVar3;
}

