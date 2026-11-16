// FUN_fffffff00817d9c4 @ fffffff00817d9c4 size=276

/* WARNING: Removing unreachable block (ram,0xfffffff00817da50) */

void FUN_fffffff00817d9c4(void)

{
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae22348);
  if ((DAT_fffffff00ae22ce8._7_1_ & 1) != 0) {
    (**(code **)(*DAT_fffffff00ae22ce0 + 0x570))(DAT_fffffff00ae22ce0,0,0,0);
    (**(code **)(*DAT_fffffff00ae22ce0 + 0x568))
              (*DAT_fffffff00ae22ce0 + 0x568,DAT_fffffff00ae22ce0,0,0);
    DAT_fffffff00ae22ce8._7_1_ = 0;
  }
  if (DAT_fffffff00ae22d18 != (long *)0x0) {
    (**(code **)(*DAT_fffffff00ae22d18 + 0x28))();
    DAT_fffffff00ae22d18 = (long *)0x0;
  }
  if (DAT_fffffff00ae22d10 != (long *)0x0) {
    (**(code **)(*DAT_fffffff00ae22d10 + 0x28))();
    DAT_fffffff00ae22d10 = (long *)0x0;
  }
  return;
}

