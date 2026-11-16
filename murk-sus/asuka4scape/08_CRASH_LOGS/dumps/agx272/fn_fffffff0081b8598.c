// FUN_fffffff0081b8598 @ fffffff0081b8598 size=240

/* WARNING: Removing unreachable block (ram,0xfffffff0081b8640) */

void FUN_fffffff0081b8598(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = *(long **)(param_1 + 0x280);
  if (*(char *)((long)plVar2 + 0x115c1) == '\x02') {
    return;
  }
  thunk_EXT_FUN_80110000032222a8(plVar2[0x234c]);
  (**(code **)(*plVar2 + 0x710))(plVar2,"",0);
  FUN_fffffff0081796f0(plVar2,1);
  (**(code **)(*plVar2 + 0x718))(*plVar2 + 0x718,plVar2,"",0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(plVar2[0x234c]);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b8684);
  (*pcVar1)();
}

