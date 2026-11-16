// FUN_fffffff009c19270 @ fffffff009c19270 size=4

void FUN_fffffff009c19270(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  ulong unaff_x30;
  
  if (*(int *)(param_1 + 0x28) != 0) {
    thunk_EXT_FUN_8011000003a49114
              ("\"IOFenceTransaction %p freed with non-zero fence count!\\n\" @%s:%d");
    return;
  }
  lVar2 = *(long *)(param_1 + 0x30);
  if (lVar2 != 0) {
    lVar3 = (long)(int)*(uint *)(param_1 + 0x2c) << 3;
    if (0x7fffffff < *(uint *)(param_1 + 0x2c)) {
      lVar3 = -0x8000000000000000;
    }
    *(undefined8 *)(param_1 + 0x30) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806bbb0,lVar2,lVar3);
  }
  if (*(long *)(param_1 + 0x20) != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c192f8);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c19300. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

