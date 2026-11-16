// FUN_fffffff0081a5c00 @ fffffff0081a5c00 size=576

undefined8 FUN_fffffff0081a5c00(long param_1)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x5b0) != 0) {
    uVar1 = **(uint **)(param_1 + 0x5a8);
    *(uint *)(param_1 + 0x5b8) = uVar1;
    uVar2 = (*(uint **)(param_1 + 0x5a8))[8];
    *(uint *)(param_1 + 0x5bc) = uVar2;
    if ((*(ulong *)(param_1 + 0x5c8) <= (ulong)uVar1) ||
       (*(ulong *)(param_1 + 0x5c8) <= (ulong)uVar2)) {
LAB_fffffff0081a5e30:
      uVar5 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! read_index out of bounds\n");
      return uVar5;
    }
    if (uVar1 == uVar2) {
      if (*(long *)(param_1 + 0x5e0) == 0) goto LAB_fffffff0081a5dd4;
      uVar1 = **(uint **)(param_1 + 0x5d8);
      *(uint *)(param_1 + 0x5e8) = uVar1;
      uVar2 = (*(uint **)(param_1 + 0x5d8))[8];
      *(uint *)(param_1 + 0x5ec) = uVar2;
      if ((*(ulong *)(param_1 + 0x5f8) <= (ulong)uVar1) ||
         (*(ulong *)(param_1 + 0x5f8) <= (ulong)uVar2)) goto LAB_fffffff0081a5e30;
      if (uVar1 == uVar2) {
        if (*(long *)(param_1 + 0x610) == 0) goto LAB_fffffff0081a5dd4;
        uVar1 = **(uint **)(param_1 + 0x608);
        *(uint *)(param_1 + 0x618) = uVar1;
        uVar2 = (*(uint **)(param_1 + 0x608))[8];
        *(uint *)(param_1 + 0x61c) = uVar2;
        if ((*(ulong *)(param_1 + 0x628) <= (ulong)uVar1) ||
           (*(ulong *)(param_1 + 0x628) <= (ulong)uVar2)) goto LAB_fffffff0081a5e30;
        if (uVar1 == uVar2) {
          if (*(long *)(param_1 + 0x640) == 0) goto LAB_fffffff0081a5dd4;
          uVar1 = **(uint **)(param_1 + 0x638);
          *(uint *)(param_1 + 0x648) = uVar1;
          uVar2 = (*(uint **)(param_1 + 0x638))[8];
          *(uint *)(param_1 + 0x64c) = uVar2;
          if ((*(ulong *)(param_1 + 0x658) <= (ulong)uVar1) ||
             (*(ulong *)(param_1 + 0x658) <= (ulong)uVar2)) goto LAB_fffffff0081a5e30;
          if (uVar1 == uVar2) {
            if (*(long *)(param_1 + 0x670) == 0) goto LAB_fffffff0081a5dd4;
            uVar1 = **(uint **)(param_1 + 0x668);
            *(uint *)(param_1 + 0x678) = uVar1;
            uVar2 = (*(uint **)(param_1 + 0x668))[8];
            *(uint *)(param_1 + 0x67c) = uVar2;
            if ((*(ulong *)(param_1 + 0x688) <= (ulong)uVar1) ||
               (*(ulong *)(param_1 + 0x688) <= (ulong)uVar2)) goto LAB_fffffff0081a5e30;
            if (uVar1 == uVar2) {
              if (*(long *)(param_1 + 0x6a0) == 0) goto LAB_fffffff0081a5dd4;
              uVar1 = **(uint **)(param_1 + 0x698);
              *(uint *)(param_1 + 0x6a8) = uVar1;
              uVar2 = (*(uint **)(param_1 + 0x698))[8];
              *(uint *)(param_1 + 0x6ac) = uVar2;
              if ((*(ulong *)(param_1 + 0x6b8) <= (ulong)uVar1) ||
                 (*(ulong *)(param_1 + 0x6b8) <= (ulong)uVar2)) goto LAB_fffffff0081a5e30;
              if (uVar1 == uVar2) {
                FUN_fffffff0081b7b5c(param_1 + 0x6c0);
                uVar4 = FUN_fffffff0081b7c18(param_1 + 0x6c0);
                if ((uVar4 & 1) == 0) {
                  FUN_fffffff0081b7b5c(param_1 + 0x6f0);
                  uVar4 = FUN_fffffff0081b7c18(param_1 + 0x6f0);
                  if ((uVar4 & 1) == 0) {
                    FUN_fffffff0081b7b5c(param_1 + 0x720);
                    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                      uVar5 = FUN_fffffff0081b7c18(param_1 + 0x720);
                      return uVar5;
                    }
                    /* WARNING: Does not return */
                    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a5dd0);
                    (*pcVar3)();
                  }
                }
              }
            }
          }
        }
      }
    }
    return 1;
  }
LAB_fffffff0081a5dd4:
  uVar5 = thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Using uninitialized validator class\n");
  return uVar5;
}

