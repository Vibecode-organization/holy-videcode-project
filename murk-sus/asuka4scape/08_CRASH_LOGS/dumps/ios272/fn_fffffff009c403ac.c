// FUN_fffffff009c403ac @ fffffff009c403ac size=132

bool FUN_fffffff009c403ac(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_2 + 0x60);
  lVar2 = *(long *)(*(long *)(param_1 + 0x28) + 0x10);
  if (lVar1 == lVar2) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "IOSurfaceRootUserClient: duplicate listener refcon %08llx\n");
    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) = 0xe00002c2;
  }
  return lVar1 == lVar2;
}

