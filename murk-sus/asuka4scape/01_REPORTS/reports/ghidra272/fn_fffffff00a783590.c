// FUN_fffffff00a783590 @ fffffff00a783590 size=528

void FUN_fffffff00a783590(ulong param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  undefined4 in_wzr;
  
  plVar4 = (long *)(param_2 + 0x28);
  lVar3 = *plVar4;
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  else {
    param_1 = ((long)*(char *)(param_2 + 0x40) & 0xffffU | (ulong)*(byte *)(param_2 + 0x41) << 8) ^
              0x4f71;
  }
  FUN_fffffff00a77c274(param_1,lVar3);
  if (*(long *)(param_2 + 0x18) != -1) {
    uVar5 = (ulong)*(uint *)(*plVar4 + 0xbc) & 0xffffff;
    lVar2 = tpidr_el1;
    uVar1 = (ulong)*(uint *)(lVar2 + 0x4e8);
    if (DAT_fffffff00ad94178 != 0) {
      FUN_fffffff00a2262d4(&DAT_fffffff00ad94170,lVar2,0);
      uVar1 = DAT_fffffff00ad94178;
    }
    DAT_fffffff00ad94178 = uVar1;
    if ((int)uVar5 < DAT_fffffff00add4930) {
      lVar6 = *(long *)(DAT_fffffff00add4928 + uVar5 * 8);
      if ((int)DAT_fffffff00ad94178 == *(int *)(lVar2 + 0x4e8)) {
        DAT_fffffff00ad94178 = CONCAT44(DAT_fffffff00ad94178._4_4_,in_wzr);
      }
      else {
        FUN_fffffff00a226e08(&DAT_fffffff00ad94170,lVar2);
      }
      if (lVar6 != 0) {
        if (*(char *)(param_2 + 0x40) == -2) {
          lVar2 = *(long *)(lVar6 + 0x70);
          if (lVar2 == param_2) {
            *(undefined8 *)(lVar6 + 0x70) = *(undefined8 *)(lVar2 + 0x18);
            goto LAB_fffffff00a783720;
          }
          do {
            lVar6 = lVar2;
            lVar2 = *(long *)(lVar6 + 0x18);
          } while (lVar2 != param_2);
        }
        else {
          if (*(char *)(param_2 + 0x40) != -1) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa4d114("invalid knote %p detach, filter: %d @%s:%d");
          }
          lVar2 = *(long *)(lVar6 + 0x38);
          if (lVar2 == param_2) {
            *(undefined8 *)(lVar6 + 0x38) = *(undefined8 *)(lVar2 + 0x18);
            goto LAB_fffffff00a783720;
          }
          do {
            lVar6 = lVar2;
            lVar2 = *(long *)(lVar6 + 0x18);
          } while (lVar2 != param_2);
        }
        *(undefined8 *)(lVar6 + 0x18) = *(undefined8 *)(lVar2 + 0x18);
      }
    }
    else if ((int)DAT_fffffff00ad94178 == *(int *)(lVar2 + 0x4e8)) {
      DAT_fffffff00ad94178 = CONCAT44(DAT_fffffff00ad94178._4_4_,in_wzr);
    }
    else {
      FUN_fffffff00a226e08(&DAT_fffffff00ad94170,lVar2);
    }
  }
LAB_fffffff00a783720:
  *plVar4 = 0;
  FUN_fffffff00a779b78(lVar3);
  FUN_fffffff00a77c3d0(lVar3);
  return;
}

