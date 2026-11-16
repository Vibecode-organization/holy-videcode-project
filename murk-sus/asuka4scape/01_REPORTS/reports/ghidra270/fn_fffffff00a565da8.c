// FUN_fffffff00a565da8 @ fffffff00a565da8 size=476

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff00a565da8(long param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  undefined4 in_wzr;
  
  if (*(int *)(param_1 + 0x14) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa0c4f8("%s: inm=%p negative reqcnt @%s:%d");
  }
  iVar2 = *(int *)(param_1 + 0x14) + -1;
  *(int *)(param_1 + 0x14) = iVar2;
  if (iVar2 == 0) {
    uVar1 = *(uint *)(param_1 + 0x18);
    if ((uVar1 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa0c4f8("%s: Attempt to detach an unattached record inm=%p @%s:%d");
    }
    if ((uVar1 >> 4 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa0c4f8("%s: inm %p is already in trash list @%s:%d");
    }
    lVar6 = *(long *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x18) = uVar1 & 0xffffffee;
    if (lVar6 == 0) {
      plVar7 = *(long **)(param_1 + 0x28);
      if (*plVar7 != param_1) goto LAB_fffffff00a565ec4;
      lVar6 = 0;
    }
    else {
      if (*(long **)(lVar6 + 0x28) != (long *)(param_1 + 0x20)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a565ed4);
        (*pcVar4)();
      }
      if (**(long **)(param_1 + 0x28) != param_1) {
LAB_fffffff00a565ec4:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a565ecc);
        (*pcVar4)();
      }
      *(long **)(lVar6 + 0x28) = *(long **)(param_1 + 0x28);
      lVar6 = *(long *)(param_1 + 0x20);
      plVar7 = *(long **)(param_1 + 0x28);
    }
    *plVar7 = lVar6;
    if ((*(byte *)(param_1 + 0x18) >> 2 & 1) != 0) {
      FUN_fffffff00a1ead70();
      lVar6 = tpidr_el1;
      uVar3 = (ulong)*(uint *)(lVar6 + 0x4e8);
      if (_DAT_fffffff00ad8f348 != 0) {
        FUN_fffffff00a1ea02c(&DAT_fffffff00ad8f340,lVar6,0);
        uVar3 = _DAT_fffffff00ad8f348;
      }
      _DAT_fffffff00ad8f348 = uVar3;
      *(undefined8 *)(param_1 + 0x12e0) = 0;
      *(long **)(param_1 + 0x12e8) = _DAT_fffffff00acd2710;
      *_DAT_fffffff00acd2710 = param_1;
      _DAT_fffffff00acd2710 = (long *)(param_1 + 0x12e0);
      if (DAT_fffffff00ad8f348 == *(int *)(lVar6 + 0x4e8)) {
        _DAT_fffffff00ad8f348 = CONCAT44(DAT_fffffff00ad8f348_4,in_wzr);
      }
      else {
        FUN_fffffff00a1eab60(&DAT_fffffff00ad8f340);
      }
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x10;
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

