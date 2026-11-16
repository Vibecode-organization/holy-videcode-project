// FUN_fffffff00994f3b8 @ fffffff00994f3b8 size=156

bool FUN_fffffff00994f3b8(long param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  
  uVar2 = *(uint *)(param_1 + 0x100);
  if (uVar2 < 0x400) {
    lVar3 = *(long *)(param_1 + 0xf8);
    if (lVar3 != 0) {
      *(uint *)(param_1 + 0x100) = uVar2 + 1;
      lVar4 = (ulong)uVar2 * 4;
      puVar1 = (undefined4 *)(lVar3 + (int)lVar4);
      if (lVar4 - (int)lVar4 != 0) {
        puVar1 = (undefined4 *)(lVar3 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = param_2;
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: pid count is greater than or equal to the max allowed (%u)\n");
  }
  return uVar2 < 0x400;
}

