// FUN_fffffff009cf4d88 @ fffffff009cf4d88

/* WARNING: Removing unreachable block (ram,0xfffffff009cf64ac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf6314) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf6140) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5f98) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5de8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5c34) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5a80) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf58c8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5718) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5508) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5368) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf518c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf4fdc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf4f4c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf50e8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5298) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5474) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5678) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5824) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf59d4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5b88) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5d40) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf5ef4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf60a0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf6248) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf641c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf661c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cf4e44) */

void FUN_fffffff009cf4d88
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  short *psVar7;
  undefined1 auVar8 [16];
  ulong local_48;
  
  plVar4 = thunk_FUN_fffffff00a894f30((long *)param_7[0x17],*(long *)PTR_PTR_fffffff008089ca8);
  iVar2 = (**(code **)(*plVar4 + 0x2d0))(plVar4,param_7);
  if (iVar2 != 0) {
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,4);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar6,4,uVar3 & 0xfffffff1);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_VALUES0.RECIEVER_DETECT_OVERRIDE_VALUE = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_VALUES0.RECIEVER_DETECT_OVERRIDE_VALUE = 0x%x\n"
                  );
      }
    }
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar6,0,uVar3 | 1);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_CFG.ENABLE_RXVALID_OVERRIDE = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_CFG.ENABLE_RXVALID_OVERRIDE = 0x%x\n"
                  );
      }
    }
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar6,0,uVar3 | 4);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_CFG.CFG_ENABLE_RECIEVER_DETECT_OVERRIDE = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_CFG.CFG_ENABLE_RECIEVER_DETECT_OVERRIDE = 0x%x\n"
                  );
      }
    }
    uVar5 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0x10);
    if ((uVar5 & 1) == 0) {
      lVar6 = param_7[0x4e5];
      uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0x10);
      (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar6,0x10,uVar3 | 1);
      if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
          psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                     (byte *)
                     "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_LOCK_PIPE_IF_REQ.LOCK_PIPE_IF_REQ = 0x%x\n"
                    );
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0
                    ((byte *)
                     "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_LOCK_PIPE_IF_REQ.LOCK_PIPE_IF_REQ = 0x%x\n"
                    );
        }
      }
      local_48 = 0;
      thunk_FUN_fffffff00a208ed8(6,1000000,(long *)&local_48);
      uVar5 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e5],0x14);
      while (((uVar5 & 1) == 0 && (uVar5 = thunk_FUN_fffffff00a39bc88(), uVar5 < local_48))) {
        thunk_FUN_fffffff00a902988(500);
        uVar5 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0x14);
      }
      uVar5 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0x14);
      if (((uVar5 & 1) == 0) && ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0)) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
          psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                     (byte *)"%s@%s: %s::%s: failed PIPE_HANDLER_LOCK_PIPE_IF_ACK\n");
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0
                    ((byte *)"%s@%s: %s::%s: failed PIPE_HANDLER_LOCK_PIPE_IF_ACK\n");
        }
      }
    }
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0x20);
    (**(code **)(*param_7 + 0x820))(param_7,lVar6,0x20,uVar3 & 0xfffffff0 | 2);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_NON_SELECTED_OVERRIDE.NATIVE_POWER_DOWN = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_NON_SELECTED_OVERRIDE.NATIVE_POWER_DOWN = 0x%x\n"
                  );
      }
    }
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0x20);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar6,0x20,uVar3 | 0x1000);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_NON_SELECTED_OVERRIDE.NATIVE_RESET = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_NON_SELECTED_OVERRIDE.NATIVE_RESET = 0x%x\n"
                  );
      }
    }
    thunk_FUN_fffffff00a902988(5);
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0xc);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar6,0xc,uVar3 & 0xffffff8f);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                  );
      }
    }
    thunk_FUN_fffffff00a902988(5);
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0xc);
    (**(code **)(*param_7 + 0x820))(param_7,lVar6,0xc,uVar3 & 0xfffffffc | 2);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_MODE = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_MODE = 0x%x\n"
                  );
      }
    }
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0xc);
    (**(code **)(*param_7 + 0x820))(param_7,lVar6,0xc,uVar3 & 0xffffff8f | 0x40);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                  );
      }
    }
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar6,0,uVar3 & 0xfffffffe);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_CFG.ENABLE_RXVALID_OVERRIDE = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_CFG.ENABLE_RXVALID_OVERRIDE = 0x%x\n"
                  );
      }
    }
    lVar6 = param_7[0x4e5];
    uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar6,0,uVar3 & 0xfffffffb);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_CFG.CFG_ENABLE_RECIEVER_DETECT_OVERRIDE = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_OVERRIDE_CFG.CFG_ENABLE_RECIEVER_DETECT_OVERRIDE = 0x%x\n"
                  );
      }
    }
    uVar5 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0x10);
    if ((uVar5 & 1) != 0) {
      lVar6 = param_7[0x4e5];
      uVar3 = (**(code **)(*param_7 + 0x818))(param_7,lVar6,0x10);
      (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar6,0x10,uVar3 & 0xfffffffe);
      if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
          psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                     (byte *)
                     "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_LOCK_PIPE_IF_REQ.LOCK_PIPE_IF_REQ = 0x%x\n"
                    );
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0
                    ((byte *)
                     "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_LOCK_PIPE_IF_REQ.LOCK_PIPE_IF_REQ = 0x%x\n"
                    );
        }
      }
      local_48 = 0;
      thunk_FUN_fffffff00a208ed8(6,1000000,(long *)&local_48);
      uVar5 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e5],0x14);
      while (((uVar5 & 1) != 0 && (uVar5 = thunk_FUN_fffffff00a39bc88(), uVar5 < local_48))) {
        thunk_FUN_fffffff00a902988(500);
        uVar5 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0x14);
      }
      uVar5 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0x14);
      if (((uVar5 & 1) != 0) && ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0)) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
          psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                     (byte *)"%s@%s: %s::%s: failed PIPE_HANDLER_LOCK_PIPE_IF_ACK\n");
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0
                    ((byte *)"%s@%s: %s::%s: failed PIPE_HANDLER_LOCK_PIPE_IF_ACK\n");
        }
      }
    }
    (**(code **)(*(long *)param_7[0x4d1] + 0x80))();
    (**(code **)(*(long *)param_7[0x4d0] + 0x80))();
    *(undefined1 *)(param_7 + 0x4f2) = 0;
    plVar4 = (long *)param_7[0x4f1];
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x80))(plVar4,param_7 + 0x4f2,0,0);
    }
  }
  (*(code *)PTR_FUN_fffffff008087698)(param_7);
  return;
}

