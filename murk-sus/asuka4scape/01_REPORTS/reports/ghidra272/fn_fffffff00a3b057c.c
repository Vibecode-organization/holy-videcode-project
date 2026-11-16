// FUN_fffffff00a3b057c @ fffffff00a3b057c size=604

undefined8
FUN_fffffff00a3b057c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,undefined8 *param_7,
          int param_8,undefined8 param_9,ulong *param_10)

{
  undefined1 auVar1 [16];
  undefined *****pppppuVar2;
  int iVar3;
  undefined8 uVar4;
  undefined *****pppppuVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  undefined *****pppppuVar9;
  undefined8 extraout_d0;
  undefined8 extraout_var;
  undefined8 local_78;
  undefined ****ppppuStack_70;
  byte *local_68;
  ulong local_60;
  undefined ****ppppuStack_58;
  undefined *****local_50;
  ulong local_48;
  ulong local_40;
  
  local_40 = 0;
  ppppuStack_58 = (undefined ****)0x0;
  local_60 = 0;
  local_48 = 0;
  local_50 = (undefined *****)0x0;
  uVar4 = FUN_fffffff00a389b14(param_7,&local_60,0x28,param_10);
  if ((int)uVar4 != 0) {
    return 0xfae94003;
  }
  auVar1._8_8_ = extraout_var;
  auVar1._0_8_ = extraout_d0;
  pppppuVar5 = (undefined *****)
               FUN_fffffff00a3b07d8
                         (auVar1,param_2,param_3,param_4,param_5,param_6,local_40,&local_68);
  pppppuVar2 = local_50;
  uVar7 = local_60;
  if (pppppuVar5 == (undefined *****)0x0) {
    return 0xfae94003;
  }
  uVar8 = (1L << ((ulong)*(byte *)((long)pppppuVar5 + 0x2c) & 0x3f)) - 1;
  if (((((((uVar8 & local_60) != 0) || (((ulong)ppppuStack_58 & uVar8) != 0)) ||
        (((ulong)local_50 & uVar8) != 0)) || ((7 < local_48 || (CARRY8(local_60,(ulong)local_50)))))
      || ((CARRY8((ulong)ppppuStack_58,(ulong)local_50) ||
          ((0x80000000000 < (long)local_50 + local_60 || (ppppuStack_58 < pppppuVar5[2])))))) ||
     (pppppuVar5[3] < (undefined ****)((long)local_50 + (long)ppppuStack_58))) {
    if (local_68 != (byte *)0xffffffffffffffff) {
      if (local_68 == (byte *)0x0) {
        lVar6 = tpidr_el1;
        if (*(long *)(lVar6 + 0x4a8) != 0) {
          return 0xfae94003;
        }
        FUN_fffffff00a2e6e78((ulong *)pppppuVar5);
        return 0xfae94003;
      }
      if (*local_68 != 0x2d) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d4b0(local_68,0,0x2d);
      }
    }
    FUN_fffffff00a1f4ae8(local_68);
    return 0xfae94003;
  }
  if (param_8 == 2) {
    if (local_50 != (undefined *****)0x0) {
      uVar7 = FUN_fffffff00a2e898c
                        (pppppuVar5,(ulong)ppppuStack_58,(long)local_50 + (long)ppppuStack_58,0,
                         (uint)local_48);
      iVar3 = (int)uVar7;
      goto joined_r0xfffffff00a3b06d0;
    }
LAB_fffffff00a3b07b4:
    FUN_fffffff00a3b09e0(local_68,(ulong *)pppppuVar5);
    uVar4 = 0;
  }
  else {
    if (param_8 == 1) {
      uVar4 = FUN_fffffff00a2de0a4((long)pppppuVar5,(ulong)ppppuStack_58,(ulong)local_50);
      iVar3 = (int)uVar4;
joined_r0xfffffff00a3b06d0:
      if (iVar3 == 0) goto LAB_fffffff00a3b07b4;
    }
    else {
      local_78 = 0;
      ppppuStack_70 = ppppuStack_58;
      lVar6 = tpidr_el1;
      lVar6 = FUN_fffffff00a29bafc(lVar6);
      pppppuVar9 = *(undefined ******)(lVar6 + 0x28);
      if (pppppuVar9 == (undefined *****)0x0) {
        pppppuVar9 = (undefined *****)0x0;
      }
      uVar8 = FUN_fffffff00a2e902c
                        (pppppuVar5,(ulong *)&ppppuStack_70,pppppuVar2,(undefined *****)0x0,
                         (ulong *****)0x80001100001,pppppuVar9,uVar7,0,(uint *)((long)&local_78 + 4)
                         ,(uint *)&local_78,2);
      uVar7 = local_48;
      if ((int)uVar8 == 0) {
        if ((local_50 == (undefined *****)0x0) ||
           ((uVar8 = FUN_fffffff00a2e898c
                               (pppppuVar5,(ulong)ppppuStack_58,(long)local_50 + (long)ppppuStack_58
                                ,1,7), (int)uVar8 == 0 &&
            ((local_50 == (undefined *****)0x0 ||
             (uVar7 = FUN_fffffff00a2e898c
                                (pppppuVar5,(ulong)ppppuStack_58,
                                 (long)local_50 + (long)ppppuStack_58,0,(uint)uVar7 & 7),
             (int)uVar7 == 0)))))) goto LAB_fffffff00a3b07b4;
        FUN_fffffff00a2de0a4((long)pppppuVar5,(ulong)ppppuStack_58,(ulong)local_50);
      }
    }
    FUN_fffffff00a3b09e0(local_68,(ulong *)pppppuVar5);
    uVar4 = 0xfae94001;
  }
  return uVar4;
}

