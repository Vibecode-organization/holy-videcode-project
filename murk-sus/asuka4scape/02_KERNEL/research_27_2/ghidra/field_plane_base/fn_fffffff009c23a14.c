// FUN_fffffff009c23a14 @ fffffff009c23a14

/* WARNING: Removing unreachable block (ram,0xfffffff009c23b34) */

undefined8
FUN_fffffff009c23a14
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  undefined1 auVar6 [16];
  undefined1 extraout_q0 [16];
  undefined1 local_30 [2];
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined3 uStack_2b;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x398));
  iVar3 = thunk_FUN_fffffff00a89460c((int *)(param_7 + 0x22c));
  if (iVar3 == 1) {
    uVar4 = FUN_fffffff009c31488(0x100);
    if (uVar4 == 0) {
      uVar4 = FUN_fffffff009c31488(0x20);
      if (uVar4 == 0) {
        uVar4 = FUN_fffffff009c31488(0x40);
        lVar2 = _local_30;
        if ((uVar4 != 0) && (*(int *)(*(long *)(param_7 + 0x178) + 0x24) == 0)) {
          uVar1 = *(undefined4 *)(param_7 + 0x80);
          uStack_2b = SUB83(lVar2,5);
          _local_30 = (uint5)CONCAT13((char)uVar1,
                                      CONCAT12((char)((uint)uVar1 >> 8),
                                               CONCAT11((char)((uint)uVar1 >> 0x10),
                                                        (char)((uint)uVar1 >> 0x18))));
          plVar5 = *(long **)(param_7 + 0x1a8);
          if (plVar5 == (long *)0x0) {
            thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x50));
            FUN_fffffff009c20460(param_7);
            thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
            plVar5 = *(long **)(param_7 + 0x1a8);
          }
          plVar5 = (long *)(**(code **)(*plVar5 + 0x138))(plVar5,"IOSurfaceName");
          plVar5 = thunk_FUN_fffffff00a894f30(plVar5,*(long *)PTR_PTR_fffffff00806ca10);
          auVar6 = extraout_q0;
          if (plVar5 != (long *)0x0) {
            auVar6 = (**(code **)(*plVar5 + 0xa8))();
          }
          thunk_FUN_fffffff00a8df19c
                    (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00806ca48,0,
                     (byte *)
                     "sid %08x complete() without assertion. dims: %llux%llu, fmt: %s, name: %s\n");
        }
      }
      else {
        (**(code **)(**(long **)(param_7 + 0x30) + 0xe0))(*(long **)(param_7 + 0x30),0);
      }
    }
    else {
      *(uint *)(param_7 + 0x3d0) = *(uint *)(param_7 + 0x3d0) | 0x400;
    }
    _local_30 = 0;
    auVar6 = thunk_FUN_fffffff00a2df760(*(ulong *)(param_7 + 0x30),(long *)local_30);
    thunk_FUN_fffffff00a6de494
              (auVar6,param_2,param_3,param_4,param_5,param_6,0x85210020,_local_30,
               (ulong)*(uint *)(param_7 + 0x10),0,0);
  }
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x398));
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

