// FUN_fffffff0081d736c @ fffffff0081d736c size=400

/* WARNING: Removing unreachable block (ram,0xfffffff0081d7418) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d74b0) */

void FUN_fffffff0081d736c(long param_1,uint param_2)

{
  if (param_2 != (*(byte *)(param_1 + 8) & 1)) {
    if ((param_2 & 1) == 0) {
      if ((DAT_fffffff00ae22ce8._7_1_ & 1) != 0) {
        (**(code **)(*DAT_fffffff00ae22ce0 + 0x570))(DAT_fffffff00ae22ce0,0,0,0);
        (**(code **)(*DAT_fffffff00ae22ce0 + 0x568))
                  (*DAT_fffffff00ae22ce0 + 0x568,DAT_fffffff00ae22ce0,0,0);
        DAT_fffffff00ae22ce8._7_1_ = 0;
      }
    }
    else if (((DAT_fffffff00ae22ce8._7_1_ & 1) == 0) && ((DAT_fffffff00ae22cf1 & 1) != 0)) {
      (**(code **)(*DAT_fffffff00ae22ce0 + 0x568))(DAT_fffffff00ae22ce0,1,0);
      (**(code **)(*DAT_fffffff00ae22ce0 + 0x570))
                (*DAT_fffffff00ae22ce0 + 0x570,DAT_fffffff00ae22ce0,1,0,0);
      thunk_EXT_FUN_80110000038fe988(10);
      DAT_fffffff00ae22ce8._7_1_ = 1;
    }
    *(char *)(param_1 + 8) = (char)param_2;
  }
  return;
}

