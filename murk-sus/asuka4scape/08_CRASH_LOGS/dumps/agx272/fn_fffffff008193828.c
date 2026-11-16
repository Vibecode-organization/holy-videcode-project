// FUN_fffffff008193828 @ fffffff008193828 size=200

void FUN_fffffff008193828(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  ulong unaff_x30;
  
  if ((*(byte *)(param_3 + 8) & 1) == 0) {
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
    return;
  }
  uVar1 = *(undefined4 *)(param_3 + 0x2c);
  uVar2 = *(undefined8 *)(param_3 + 0x18);
  FUN_fffffff0081909e8
            (param_1,*(undefined4 *)(param_3 + 0x28),*(undefined8 *)(param_3 + 0x10),
             *(undefined8 *)(param_3 + 0x20),param_2);
  uVar4 = *(int *)(*(long *)(param_1 + 0x530) + 0x23c) * 1000 - 1000;
  if (3999 < uVar4) {
    uVar4 = 4000;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081938bc);
    (*pcVar3)();
  }
  FUN_fffffff008190870(param_1,uVar1,uVar2,uVar4,param_2);
  return;
}

