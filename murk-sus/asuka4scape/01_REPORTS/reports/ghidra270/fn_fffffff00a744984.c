// FUN_fffffff00a744984 @ fffffff00a744984 size=552

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff00a744984(ulong param_1,long param_2)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  undefined4 in_wzr;
  
  if (*(code **)((param_1 >> 0x18 & 0xff) * 0x70 + -0xff5323970) == FUN_fffffff00a741ca0) {
    uVar2 = (uint)param_1 & 0xffffff;
    lVar8 = tpidr_el1;
    uVar3 = (ulong)*(uint *)(lVar8 + 0x4e8);
    if (_DAT_fffffff00ad540b8 != 0) {
      FUN_fffffff00a1ea02c(&DAT_fffffff00ad540b0,lVar8,0);
      uVar3 = _DAT_fffffff00ad540b8;
    }
    _DAT_fffffff00ad540b8 = uVar3;
    if (((int)uVar2 < DAT_fffffff00ad94850) &&
       (plVar7 = *(long **)(DAT_fffffff00ad94848 + (ulong)uVar2 * 8), plVar7 != (long *)0x0)) {
      if (DAT_fffffff00ad540b8 == *(int *)(lVar8 + 0x4e8)) {
        _DAT_fffffff00ad540b8 = CONCAT44(DAT_fffffff00ad540b8_4,in_wzr);
      }
      else {
        FUN_fffffff00a1eab60(&DAT_fffffff00ad540b0,lVar8);
      }
      lVar8 = *plVar7;
      FUN_fffffff00a73cb8c(lVar8);
      *(undefined1 *)(param_2 + 0x41) = 0x25;
      piVar1 = (int *)(lVar8 + 0x1e0);
      iVar4 = *piVar1;
      *piVar1 = iVar4 + 1;
      if (0xf0000001 < iVar4 + 0xf0000001U) {
        *(long **)(param_2 + 0x28) = plVar7;
        if (*(char *)(param_2 + 0x40) == -1) {
          lVar6 = 0x38;
        }
        else {
          if (*(char *)(param_2 + 0x40) != -2) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa0c4f8("ptmx kevent: unexpected filter: %d, kn = %p, tty = %p @%s:%d");
          }
          lVar6 = 0x70;
        }
        *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)((long)plVar7 + lVar6);
        *(long *)((long)plVar7 + lVar6) = param_2;
        uVar5 = FUN_fffffff00a743960(param_2,0,plVar7,lVar8);
        FUN_fffffff00a73a490(lVar8);
        return uVar5;
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa21104(piVar1);
    }
    if (DAT_fffffff00ad540b8 == *(int *)(lVar8 + 0x4e8)) {
      _DAT_fffffff00ad540b8 = CONCAT44(DAT_fffffff00ad540b8_4,in_wzr);
    }
    else {
      FUN_fffffff00a1eab60(&DAT_fffffff00ad540b0,lVar8);
    }
    *(ushort *)(param_2 + 0x42) = *(ushort *)(param_2 + 0x42) | 0x4000;
    uVar5 = 6;
  }
  else {
    *(ushort *)(param_2 + 0x42) = *(ushort *)(param_2 + 0x42) | 0x4000;
    uVar5 = 0x13;
  }
  *(undefined8 *)(param_2 + 0x58) = uVar5;
  return 0;
}

