// FUN_fffffff00a784424 @ fffffff00a784424 size=568

undefined8 FUN_fffffff00a784424(ulong param_1,long param_2)

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
  
  if (*(code **)((param_1 >> 0x18 & 0xff) * 0x70 + -0xff52e3960) == FUN_fffffff00a78139c) {
    uVar2 = (uint)param_1 & 0xffffff;
    lVar8 = tpidr_el1;
    uVar3 = (ulong)*(uint *)(lVar8 + 0x4e8);
    if (DAT_fffffff00ad94178 != 0) {
      FUN_fffffff00a2262d4(&DAT_fffffff00ad94170,lVar8,0);
      uVar3 = DAT_fffffff00ad94178;
    }
    DAT_fffffff00ad94178 = uVar3;
    if (((int)uVar2 < DAT_fffffff00add4930) &&
       (plVar7 = *(long **)(DAT_fffffff00add4928 + (ulong)uVar2 * 8), plVar7 != (long *)0x0)) {
      if ((int)DAT_fffffff00ad94178 == *(int *)(lVar8 + 0x4e8)) {
        DAT_fffffff00ad94178 = CONCAT44(DAT_fffffff00ad94178._4_4_,in_wzr);
      }
      else {
        FUN_fffffff00a226e08(&DAT_fffffff00ad94170,lVar8);
      }
      lVar8 = *plVar7;
      FUN_fffffff00a77c274(lVar8);
      *(undefined1 *)(param_2 + 0x41) = 0x25;
      piVar1 = (int *)(lVar8 + 0x1e0);
      iVar4 = *piVar1;
      *piVar1 = iVar4 + 1;
      if (0xf0000001 < iVar4 + 0xf0000001U) {
        lVar6 = lVar8;
        if (lVar8 == 0) {
          lVar6 = 0;
        }
        *(long *)(param_2 + 0x28) = lVar6;
        if (*(char *)(param_2 + 0x40) == -1) {
          lVar6 = 0x38;
        }
        else {
          if (*(char *)(param_2 + 0x40) != -2) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa4d114("ptmx kevent: unexpected filter: %d, kn = %p, tty = %p @%s:%d");
          }
          lVar6 = 0x70;
        }
        *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)((long)plVar7 + lVar6);
        *(long *)((long)plVar7 + lVar6) = param_2;
        uVar5 = FUN_fffffff00a78310c(param_2,0,plVar7,lVar8);
        FUN_fffffff00a779b78(lVar8);
        return uVar5;
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ed0(piVar1);
    }
    if ((int)DAT_fffffff00ad94178 == *(int *)(lVar8 + 0x4e8)) {
      DAT_fffffff00ad94178 = CONCAT44(DAT_fffffff00ad94178._4_4_,in_wzr);
    }
    else {
      FUN_fffffff00a226e08(&DAT_fffffff00ad94170,lVar8);
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

