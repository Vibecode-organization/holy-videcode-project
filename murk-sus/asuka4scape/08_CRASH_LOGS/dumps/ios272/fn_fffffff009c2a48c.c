// FUN_fffffff009c2a48c @ fffffff009c2a48c size=280

void FUN_fffffff009c2a48c(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = *(long **)(param_1 + 0x30);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x50))(plVar2,*(undefined8 *)PTR_DAT_fffffff00806c9c0);
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
  thunk_EXT_FUN_80110000036da494(0x540000c,*(undefined4 *)(param_1 + 0x10),0,0,0,0);
  if (*(long *)(param_1 + 0x308) != 0) {
    thunk_EXT_FUN_80110000038fe6b0
              (*(long *)(param_1 + 0x308),(ulong)*(uint *)(param_1 + 0x98) * 0x3c);
    *(undefined8 *)(param_1 + 0x308) = 0;
    *(undefined4 *)(param_1 + 0x310) = 0;
    *(undefined4 *)(param_1 + 0x3b8) = 0;
  }
  *(undefined8 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  thunk_EXT_FUN_80110000036da494
            (0x5400010,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x80),0,
             *(uint *)(param_1 + 0x3d0) >> 9 & 1,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2a5a0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000036da494
            (0x5400014,*(undefined4 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x58),
             *(undefined8 *)(param_1 + 0x60),
             (long)(int)((uint)*(byte *)(param_1 + 0x72) << 0x18) |
             (ulong)*(byte *)(param_1 + 0x73) << 0x10 | (ulong)*(ushort *)(param_1 + 0x70),0);
  return;
}

