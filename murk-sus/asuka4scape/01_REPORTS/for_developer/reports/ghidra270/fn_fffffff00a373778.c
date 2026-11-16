// FUN_fffffff00a373778 @ fffffff00a373778 size=604

undefined8 FUN_fffffff00a373778(undefined8 param_1,int param_2)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 local_78;
  ulong uStack_70;
  char *local_68;
  ulong local_60;
  ulong uStack_58;
  ulong local_50;
  ulong local_48;
  undefined8 local_40;
  
  local_40 = 0;
  uStack_58 = 0;
  local_60 = 0;
  local_48 = 0;
  local_50 = 0;
  iVar3 = FUN_fffffff00a34cec0(param_1,&local_60,0x28);
  if (iVar3 != 0) {
    return 0xfae94003;
  }
  lVar4 = FUN_fffffff00a3739d4(local_40,&local_68);
  uVar2 = local_50;
  uVar1 = local_60;
  if (lVar4 == 0) {
    return 0xfae94003;
  }
  uVar6 = (1L << ((ulong)*(byte *)(lVar4 + 0x2c) & 0x3f)) - 1;
  if (((((((uVar6 & local_60) != 0) || ((uStack_58 & uVar6) != 0)) || ((local_50 & uVar6) != 0)) ||
       ((7 < local_48 || (CARRY8(local_60,local_50))))) ||
      ((CARRY8(uStack_58,local_50) ||
       ((0x80000000000 < local_50 + local_60 || (uStack_58 < *(ulong *)(lVar4 + 0x10))))))) ||
     (*(ulong *)(lVar4 + 0x18) < local_50 + uStack_58)) {
    if (local_68 != (char *)0xffffffffffffffff) {
      if (local_68 == (char *)0x0) {
        lVar4 = tpidr_el1;
        if (*(long *)(lVar4 + 0x4a8) != 0) {
          return 0xfae94003;
        }
        FUN_fffffff00a2aa648();
        return 0xfae94003;
      }
      if (*local_68 != '-') {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c894(local_68,0,0x2d);
      }
    }
    FUN_fffffff00a1b894c(local_68);
    return 0xfae94003;
  }
  if (param_2 == 2) {
    if (local_50 != 0) {
      iVar3 = FUN_fffffff00a2ac15c(lVar4,uStack_58,local_50 + uStack_58,0);
      goto joined_r0xfffffff00a3738cc;
    }
LAB_fffffff00a3739b0:
    FUN_fffffff00a373bdc(local_68,lVar4);
    uVar7 = 0;
  }
  else {
    if (param_2 == 1) {
      iVar3 = FUN_fffffff00a2a187c(lVar4,uStack_58,local_50);
joined_r0xfffffff00a3738cc:
      if (iVar3 == 0) goto LAB_fffffff00a3739b0;
    }
    else {
      local_78 = 0;
      uStack_70 = uStack_58;
      uVar7 = tpidr_el1;
      lVar5 = FUN_fffffff00a25f6f4(uVar7);
      lVar5 = *(long *)(lVar5 + 0x28);
      if (lVar5 == 0) {
        lVar5 = 0;
      }
      iVar3 = FUN_fffffff00a2ac7fc
                        (lVar4,&uStack_70,uVar2,0,0x80001100001,lVar5,uVar1,0,(long)&local_78 + 4,
                         &local_78,2);
      uVar1 = local_48;
      if (iVar3 == 0) {
        if ((local_50 == 0) ||
           ((iVar3 = FUN_fffffff00a2ac15c(lVar4,uStack_58,local_50 + uStack_58,1,7), iVar3 == 0 &&
            ((local_50 == 0 ||
             (iVar3 = FUN_fffffff00a2ac15c(lVar4,uStack_58,local_50 + uStack_58,0,(uint)uVar1 & 7),
             iVar3 == 0)))))) goto LAB_fffffff00a3739b0;
        FUN_fffffff00a2a187c(lVar4,uStack_58,local_50);
      }
    }
    FUN_fffffff00a373bdc(local_68,lVar4);
    uVar7 = 0xfae94001;
  }
  return uVar7;
}

