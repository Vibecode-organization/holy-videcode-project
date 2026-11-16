// FUN_fffffff00820d7f4 @ fffffff00820d7f4 size=84

void FUN_fffffff00820d7f4(long param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  *(int *)(param_1 + 0xc80) = (int)param_2;
  uVar2 = thunk_EXT_FUN_801100000296a26c();
  thunk_EXT_FUN_80110000029481a8(uVar2,param_2,param_1 + 0xc40);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820d844);
    (*pcVar1)();
  }
  thunk_EXT_FUN_801100000296a27c(param_1,param_2);
  return;
}

