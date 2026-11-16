// FUN_fffffff00995263c @ fffffff00995263c size=900

undefined8 FUN_fffffff00995263c(long *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  ulong uVar10;
  undefined8 local_58;
  
  lVar8 = param_1[0xe];
  uVar3 = thunk_EXT_FUN_801100000390ebc0(param_1[10]);
  uVar4 = FUN_fffffff0099529c0(param_1);
  local_58 = 0;
  thunk_EXT_FUN_80110000032db760(uVar4,&local_58);
  thunk_EXT_FUN_80110000036da494(0x85090040,lVar8,uVar3,local_58,0,0);
  if ((*(byte *)((long)param_1 + 0x11) >> 1 & 1) != 0) {
    FUN_fffffff009983854();
LAB_fffffff0099529b8:
    FUN_fffffff009983884();
LAB_fffffff0099529bc:
    lVar8 = FUN_fffffff0099838a8();
    if (((*(char *)(lVar8 + 0x10) != -0x7e) || (lVar8 = *(long *)(lVar8 + 0x30), lVar8 != 0)) &&
       (plVar9 = *(long **)(lVar8 + 0x28), plVar9 != (long *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009952a04. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(*plVar9 + 0xe0))(plVar9,(undefined8 *)(*plVar9 + 0xe0));
      return uVar3;
    }
    return 0;
  }
  if ((long *)param_1[0x13] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x13] + 0x28))();
  }
  param_1[0x13] = 0;
  if (param_1[4] != 0) {
    (**(code **)(*param_1 + 0xf0))(param_1);
  }
  if ((char)param_1[2] == '\x03') {
    if (param_1[5] != 0) {
      lVar8 = thunk_EXT_FUN_8011000003890f30(param_1[5],DAT_fffffff007fed428);
      if (lVar8 == 0) goto LAB_fffffff0099529b8;
      if (param_1[6] != 0) {
        FUN_fffffff00996ae1c(lVar8,param_1[6],0);
      }
    }
    lVar8 = param_1[6];
    if (lVar8 != 0) {
      if ((*(byte *)(lVar8 + 0x40) & 1) == 0) {
LAB_fffffff0099527ec:
        FUN_fffffff009952a10(lVar8);
        thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff04e8,lVar8);
      }
      else {
        uVar7 = 0;
        lVar5 = *(long *)(lVar8 + 0x18);
        do {
          uVar10 = *(ulong *)(lVar5 + uVar7 * 8);
          if (uVar10 != 0) {
            do {
              uVar6 = (uVar10 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar10 & 0x5555555555555555) << 1;
              uVar6 = (uVar6 & 0xcccccccccccccccc) >> 2 | (uVar6 & 0x3333333333333333) << 2;
              uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f0f0f0f0f) << 4;
              uVar6 = (uVar6 & 0xff00ff00ff00ff00) >> 8 | (uVar6 & 0xff00ff00ff00ff) << 8;
              uVar6 = (uVar6 & 0xffff0000ffff0000) >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10;
              uVar6 = LZCOUNT(uVar6 >> 0x20 | uVar6 << 0x20);
              lVar5 = (uVar6 | (uint)((int)uVar7 << 6)) * 0x10;
              puVar2 = (undefined8 *)(*(long *)(lVar8 + 8) + (long)(int)lVar5);
              if (lVar5 - (int)lVar5 != 0) {
                puVar2 = (undefined8 *)
                         (*(long *)(lVar8 + 8) + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
              }
              uVar10 = uVar10 & (1L << (uVar6 & 0x3f) ^ 0xffffffffffffffffU);
              (**(code **)(*(long *)*puVar2 + 0x28))();
              *puVar2 = 0;
              *(int *)(lVar8 + 0x30) = *(int *)(lVar8 + 0x30) + -1;
            } while (uVar10 != 0);
            lVar5 = *(long *)(lVar8 + 0x18);
            *(undefined8 *)(lVar5 + uVar7 * 8) = 0;
          }
          uVar1 = (int)uVar7 + 1;
          uVar7 = (ulong)uVar1;
        } while (uVar1 <= *(uint *)(lVar8 + 0x28));
        if (*(int *)(lVar8 + 0x30) != 0) goto LAB_fffffff0099529bc;
        lVar8 = param_1[6];
        if (lVar8 != 0) goto LAB_fffffff0099527ec;
      }
      param_1[6] = 0;
    }
  }
  if ((long *)param_1[5] != (long *)0x0) {
    (**(code **)(*(long *)param_1[5] + 0x28))();
  }
  param_1[5] = 0;
  if (((char)param_1[2] == -0x7e) && (plVar9 = (long *)param_1[6], plVar9 != (long *)0x0)) {
    if ((long *)plVar9[6] != (long *)0x0) {
      (**(code **)(*(long *)plVar9[6] + 0x28))();
    }
    thunk_EXT_FUN_80110000032222a8(plVar9[0xc]);
    (**(code **)(*plVar9 + 0xe8))(plVar9);
    thunk_EXT_FUN_8011000003222de0(plVar9[0xc]);
    (**(code **)(*plVar9 + 0x28))(plVar9);
  }
  if (param_1[0xb] != 0) {
    param_1[0xb] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff0468);
    param_1[0xb] = 0;
  }
  if (param_1[3] != 0) {
    (**(code **)(*param_1 + 0xa0))(param_1);
    if (param_1[0xd] != 0) {
      FUN_fffffff009964010(param_1[0xd],*(undefined4 *)((long)param_1 + 0x8c));
    }
  }
  if ((long *)param_1[0xd] == (long *)0x0) {
    if (param_1[3] == 0) goto LAB_fffffff00995296c;
    (**(code **)(*(long *)param_1[10] + 0x580))();
  }
  else {
    (**(code **)(*(long *)param_1[0xd] + 0x28))();
    param_1[0xd] = 0;
  }
  param_1[3] = 0;
LAB_fffffff00995296c:
  if (param_1[0xc] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0xc] = 0;
  }
  uVar3 = (*DAT_fffffff007feb268)(param_1);
  return uVar3;
}

