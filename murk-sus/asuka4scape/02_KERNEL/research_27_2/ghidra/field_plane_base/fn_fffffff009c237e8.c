// FUN_fffffff009c237e8 @ fffffff009c237e8

/* WARNING: Removing unreachable block (ram,0xfffffff009c238d8) */

undefined8
FUN_fffffff009c237e8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined1 extraout_q0 [16];
  undefined1 auVar8 [16];
  undefined1 local_40 [2];
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined3 uStack_3b;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  if (*(long *)(param_7 + 0x30) == 0) {
    uVar7 = 0xe00002bc;
  }
  else {
    thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x398));
    iVar3 = thunk_FUN_fffffff00a8945fc((int *)(param_7 + 0x22c));
    if (iVar3 == 0) {
      if (((*(byte *)(param_7 + 0x3d1) >> 2 & 1) == 0) &&
         (uVar4 = FUN_fffffff009c31488(0x120), uVar4 != 0)) {
        iVar3 = (**(code **)(**(long **)(param_7 + 0x30) + 0xd8))(*(long **)(param_7 + 0x30),0);
        uVar4 = (uint)(iVar3 == 0);
      }
      else {
        uVar4 = 1;
      }
      lVar6 = (**(code **)(**(long **)(param_7 + 0x30) + 0xa0))();
      uVar5 = FUN_fffffff009c31488(0x20);
      lVar2 = _local_40;
      auVar8 = extraout_q0;
      if (((uVar5 != 0) && (*(int *)(*(long *)(param_7 + 0x178) + 0x24) == 0)) &&
         (lVar6 != *(long *)(param_7 + 0x388))) {
        uVar1 = *(undefined4 *)(param_7 + 0x80);
        uStack_3b = SUB83(lVar2,5);
        _local_40 = (uint5)CONCAT13((char)uVar1,
                                    CONCAT12((char)((uint)uVar1 >> 8),
                                             CONCAT11((char)((uint)uVar1 >> 0x10),
                                                      (char)((uint)uVar1 >> 0x18))));
        auVar8 = thunk_FUN_fffffff00a8df19c
                           (extraout_q0,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                            (short *)PTR_DAT_fffffff00806ca48,0,
                            (byte *)"sid %08x prepare(): %s. format: %s\n");
        *(long *)(param_7 + 0x388) = lVar6;
        *(long *)(param_7 + 0x390) = *(long *)(param_7 + 0x390) + 1;
      }
      if ((uVar4 & (*(byte *)(param_7 + 0x3d0) & 0x20) >> 5) == 1) {
        FUN_fffffff009c206fc(auVar8,param_2,param_3,param_4,param_5,param_6,param_7);
        *(uint *)(param_7 + 0x3d0) = *(uint *)(param_7 + 0x3d0) & 0xffffffdf;
      }
      if (uVar4 == 0) {
        thunk_FUN_fffffff00a89460c((int *)(param_7 + 0x22c));
      }
      else {
        _local_40 = 0;
        auVar8 = thunk_FUN_fffffff00a2df760(*(ulong *)(param_7 + 0x30),(long *)local_40);
        thunk_FUN_fffffff00a6de494
                  (auVar8,param_2,param_3,param_4,param_5,param_6,0x8521001c,_local_40,
                   (ulong)*(uint *)(param_7 + 0x10),0,0);
      }
    }
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x398));
    uVar7 = 0;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar7;
}

