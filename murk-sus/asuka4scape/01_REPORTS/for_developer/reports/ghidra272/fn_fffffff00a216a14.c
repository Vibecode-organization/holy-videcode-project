// FUN_fffffff00a216a14 @ fffffff00a216a14 size=496

undefined8
FUN_fffffff00a216a14
          (long param_1,uint param_2,long param_3,uint *param_4,long param_5,long param_6,
          long param_7)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  int in_wzr;
  
  uVar4 = 4;
  if ((param_1 != 0) && ((param_2 & 0xffffc001) == 0)) {
    lVar3 = tpidr_el1;
    if (*(ulong *)(param_1 + 8) == 0) {
      *(ulong *)(param_1 + 8) = (ulong)*(uint *)(lVar3 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(param_1,lVar3,0);
    }
    uVar8 = 0;
    lVar7 = 1;
    do {
      uVar2 = 1 << (ulong)((uint)lVar7 & 0x1f);
      if ((uVar2 & param_2) != 0) {
        plVar1 = (long *)(param_1 + 0x138 + lVar7 * 0x20);
        uVar5 = 0;
        if (uVar8 == 0) {
LAB_fffffff00a216b44:
          if (uVar5 != uVar8) goto LAB_fffffff00a216ab8;
        }
        else {
          do {
            lVar6 = *plVar1;
            if (*plVar1 == 0) {
              lVar6 = 0;
            }
            if (((lVar6 == *(long *)(param_5 + uVar5 * 8)) &&
                (*(int *)((long)plVar1 + 0xc) == *(int *)(param_6 + uVar5 * 4))) &&
               ((int)plVar1[1] == *(int *)(param_7 + uVar5 * 4))) {
              *(uint *)(param_3 + uVar5 * 4) = *(uint *)(param_3 + uVar5 * 4) | uVar2;
              goto LAB_fffffff00a216b44;
            }
            uVar5 = uVar5 + 1;
          } while (uVar8 != uVar5);
        }
        if (uVar8 < *param_4) {
          *(uint *)(param_3 + uVar8 * 4) = uVar2;
          lVar6 = *plVar1;
          if (lVar6 == 0) {
            lVar6 = 0;
          }
          if (1 < lVar6 + 1U) {
            if (DAT_fffffff007bc7030 == lVar6) {
              lVar6 = FUN_fffffff00a1f45e4();
            }
            else {
              lVar6 = FUN_fffffff00a1f472c();
            }
          }
          *(long *)(param_5 + uVar8 * 8) = lVar6;
          *(undefined4 *)(param_6 + uVar8 * 4) = *(undefined4 *)((long)plVar1 + 0xc);
          *(int *)(param_7 + uVar8 * 4) = (int)plVar1[1];
          uVar8 = uVar8 + 1;
        }
      }
LAB_fffffff00a216ab8:
      lVar7 = lVar7 + 1;
    } while (lVar7 != 0xe);
    if (*(int *)(param_1 + 8) == *(int *)(lVar3 + 0x4e8)) {
      *(int *)(param_1 + 8) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08();
    }
    uVar4 = 0;
    *param_4 = (uint)uVar8;
  }
  return uVar4;
}

