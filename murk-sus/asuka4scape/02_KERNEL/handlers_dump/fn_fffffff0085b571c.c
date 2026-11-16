// FUN_fffffff0085b571c @ fffffff0085b571c size=24 depth=1
// CALLERS:
//   fffffff00afc5a26 ?
//   fffffff0085c1c14 FUN_fffffff0085c1bf0
//   fffffff0085c1ce8 FUN_fffffff0085c1cc0
//   fffffff0085c1e54 FUN_fffffff0085c1e28
//   fffffff0085c1f8c FUN_fffffff0085c1f68
//   fffffff0085c2034 FUN_fffffff0085c201c
//   fffffff0085c20c0 FUN_fffffff0085c20a8
//   fffffff0085c2324 FUN_fffffff0085c2308
//   fffffff0085c2408 FUN_fffffff0085c23d0
//   fffffff0085c24a0 FUN_fffffff0085c2488
//   fffffff0085c2bdc FUN_fffffff0085c2bbc
//   fffffff0085c2c80 FUN_fffffff0085c2c64
//   fffffff0085c2da8 FUN_fffffff0085c2d8c
//   fffffff0085c2ef4 FUN_fffffff0085c2eb4
//   fffffff0085c310c FUN_fffffff0085c30cc
//   fffffff0085c31fc FUN_fffffff0085c31b4
//   fffffff0085c3374 FUN_fffffff0085c332c
//   fffffff0085c34c0 FUN_fffffff0085c349c
//   fffffff0085c3594 FUN_fffffff0085c3554
// CALLS:
//   fffffff0085b54c4 FUN_fffffff0085b54c4

bool FUN_fffffff0085b571c(void)

{
  code *pcVar1;
  bool bVar2;
  ulong unaff_x30;
  
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0085b5730);
    (*pcVar1)();
  }
  bVar2 = FUN_fffffff0085b54c4(-0xff8c7c59d);
  return bVar2;
}

