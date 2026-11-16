// FUN_fffffff009979580 @ fffffff009979580 size=292

void FUN_fffffff009979580(long param_1,ulong *param_2)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  
  if (*(long *)(*(long *)(param_1 + 0x538) + 0x238) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "MTLEvent: timed out while waiting, GPU is not up yet\n");
    iVar2 = FUN_fffffff0099603b8(*(undefined8 *)(param_1 + 0x538));
    if (iVar2 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "MTLEvent: while waiting, sleep occurred, but woken up from an unknown event <%d>\n"
                );
    }
    uVar3 = *(ulong *)(*(long *)(param_1 + 0x538) + 0x230);
    uVar1 = *param_2 - uVar3;
    if (*param_2 < uVar3 || uVar1 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "MTLEvent: timed out but sleep started after deadline <%llu>. This is a real timeout\n"
                );
      *param_2 = 0;
    }
    else {
      *param_2 = uVar1;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "MTLEvent: timed out while waiting, GPU is up now, extending deadline by <%llu>\n")
      ;
    }
  }
  else {
    *param_2 = *(ulong *)(*(long *)(param_1 + 0x538) + 0x238);
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "MTLEvent: timed out while waiting. Sleep/wake occurred while waiting. Extend deadline by <%llu>\n"
              );
  }
  return;
}

