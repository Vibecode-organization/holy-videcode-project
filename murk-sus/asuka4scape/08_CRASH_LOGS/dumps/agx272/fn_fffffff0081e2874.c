// FUN_fffffff0081e2874 @ fffffff0081e2874 size=132

void FUN_fffffff0081e2874(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x10);
  if (lVar2 != 0) {
    *(undefined8 *)(param_1 + 0x10) = 0;
    thunk_EXT_FUN_80110000038fe768
              (&DAT_fffffff007ca4238,lVar2,(ulong)*(uint *)(param_1 + 0x20) << 3);
  }
  if (*(long *)(param_1 + 0x28) != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e28ec);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e28f4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca60e0 + 0x80))(param_1);
  return;
}

