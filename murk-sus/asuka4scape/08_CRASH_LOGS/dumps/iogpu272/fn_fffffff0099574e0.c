// FUN_fffffff0099574e0 @ fffffff0099574e0 size=172

undefined8 FUN_fffffff0099574e0(long param_1)

{
  if ((*(uint *)(param_1 + 0x10) & 0xff) == 0x80) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: resource does not own its backing (resType=0x%x child=%u device_cache=%s)\n");
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: resource does not own its backing (resType=0x%x)\n");
  }
  return 0xe00002e2;
}

