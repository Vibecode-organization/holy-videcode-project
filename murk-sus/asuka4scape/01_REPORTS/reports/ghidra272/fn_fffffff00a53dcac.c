// FUN_fffffff00a53dcac @ fffffff00a53dcac size=416

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a53dcac(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  long *plVar6;
  int iVar7;
  uint uVar8;
  long local_a0 [3];
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  long local_70 [6];
  
  local_70[5] = DAT_fffffff00ad30000;
  local_70[4] = 0;
  local_70[1] = 0;
  local_70[0] = 0;
  local_70[3] = 0;
  local_70[2] = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  local_a0[2] = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  local_a0[1] = 0;
  local_a0[0] = 0;
  uVar8 = _DAT_fffffff00ad1324c & 0xffff;
  if (param_2 == 0x1e) {
    local_a0[2] = 0x1e1c00000000;
    uStack_7c = (undefined4)*(undefined8 *)(param_1 + 2);
    uStack_78 = (undefined4)((ulong)*(undefined8 *)(param_1 + 2) >> 0x20);
    uStack_84 = (undefined4)*(undefined8 *)param_1;
    uStack_80 = (undefined4)((ulong)*(undefined8 *)param_1 >> 0x20);
    iVar7 = 0xffc4;
    plVar6 = local_a0;
  }
  else {
    if (param_2 != 2) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114("pf_calc_mss: not AF_INET or AF_INET6! @%s:%d");
    }
    local_70[2] = 0x21000000000;
    local_70[3] = (long)*param_1;
    iVar7 = 0xffd8;
    plVar6 = local_70;
  }
  local_70[4] = 0;
  local_70[1] = 0;
  local_70[0] = 0;
  FUN_fffffff00a498318(plVar6);
  lVar3 = *plVar6;
  if (lVar3 != 0) {
    lVar4 = *(long *)(lVar3 + 0x88);
    if (lVar4 != 0) {
      uVar8 = *(uint *)(lVar4 + 0x100);
      if ((param_2 == 2) &&
         (((*(byte *)(lVar4 + 0xd5) >> 4 & 1) != 0 ||
          ((*(long *)(lVar4 + 0x898) != 0 &&
           ((*(byte *)(*(long *)(lVar4 + 0x898) + 0xd5) >> 4 & 1) != 0)))))) {
        lVar4 = *(long *)(lVar4 + 0x920);
        uVar5 = uVar8;
        if ((lVar4 != 0) &&
           ((*(int *)(lVar4 + 0x228) != 0 &&
            (uVar5 = *(uint *)(lVar4 + 0x22c), uVar5 == 0 || uVar8 <= uVar5)))) {
          uVar2 = *(uint *)(lVar4 + 0x230);
          uVar1 = uVar2;
          if (uVar8 <= uVar2) {
            uVar1 = uVar8;
          }
          uVar5 = uVar8;
          if (uVar2 != 0) {
            uVar5 = uVar1;
          }
        }
        uVar8 = uVar5 - 0x14;
      }
      uVar5 = iVar7 + uVar8 & 0xffff;
      uVar8 = _DAT_fffffff00ad1324c;
      if (_DAT_fffffff00ad1324c <= uVar5) {
        uVar8 = uVar5;
      }
    }
    FUN_fffffff00a498684(lVar3,0);
  }
  uVar5 = uVar8 & 0xffff;
  if (param_3 <= (uVar8 & 0xffff)) {
    uVar5 = param_3;
  }
  if (uVar5 < 0x41) {
    uVar5 = 0x40;
  }
  if (DAT_fffffff00ad30000 == local_70[5]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590(uVar5);
}

