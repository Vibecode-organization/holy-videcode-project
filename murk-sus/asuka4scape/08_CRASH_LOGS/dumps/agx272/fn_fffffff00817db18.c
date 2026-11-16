// FUN_fffffff00817db18 @ fffffff00817db18 size=304

void FUN_fffffff00817db18(long param_1,int param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  code *pcVar3;
  ulong unaff_x30;
  
  if ((*(byte *)(param_1 + 0x531) & 1) != 0) {
    pcVar1 = (char *)(param_1 + 0x115c1);
    if (param_2 == 0) {
      if (*pcVar1 == '\x01') {
        (**(code **)(**(long **)(param_1 + 0x4b0) + 0x298))(*(long **)(param_1 + 0x4b0),2);
        *pcVar1 = '\x02';
        if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
          uVar2 = 0x85930c14;
          goto LAB_fffffff00817dc00;
        }
      }
    }
    else if (*pcVar1 == '\x02') {
      (**(code **)(**(long **)(param_1 + 0x4b0) + 0x298))(*(long **)(param_1 + 0x4b0),1);
      *pcVar1 = '\x01';
      if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
        uVar2 = 0x85930c0c;
LAB_fffffff00817dc00:
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(uVar2,0,0,0,0,0);
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817dc44);
          (*pcVar3)();
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
        return;
      }
    }
  }
  return;
}

