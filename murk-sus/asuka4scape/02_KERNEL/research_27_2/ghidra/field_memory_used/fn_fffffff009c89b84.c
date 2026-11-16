// FUN_fffffff009c89b84 @ fffffff009c89b84

/* WARNING: Removing unreachable block (ram,0xfffffff009c89f6c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c89f1c) */

undefined8
FUN_fffffff009c89b84
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,ulong param_8,long *param_9,
          long *param_10,long *param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  bool bVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  short *psVar7;
  undefined8 uVar8;
  long *plVar9;
  long lVar10;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  long *local_78;
  long local_70;
  undefined8 *puStack_68;
  undefined8 local_60;
  long *local_58;
  code *pcStack_50;
  ulong local_48;
  
  if (*(int *)((long)param_7 + 0xc) == 3) {
    local_58 = (long *)&DAT_aaaaaaaaaaaaaaaa;
    pcStack_50 = (code *)&DAT_aaaaaaaaaaaaaaaa;
    (**(code **)(*(long *)param_7[0x10] + 0xb8))(param_1._0_8_);
    if (param_10 == (long *)0x0) {
      param_10 = (long *)param_7[0xe];
    }
    param_7[8] = (long)param_10;
    (**(code **)(*param_10 + 0x20))(param_10);
    (**(code **)(*(long *)param_7[8] + 0xd8))((long *)param_7[8],0);
    plVar9 = param_7 + 5;
    param_7[3] = param_8;
    param_7[4] = 0;
    if ((long *)*plVar9 != (long *)0x0) {
      (**(code **)(*(long *)*plVar9 + 0x28))();
    }
    *plVar9 = 0;
    param_7[6] = 0;
    param_7[7] = 0;
    if (param_9 != (long *)0x0) {
      lVar5 = param_9[2];
      lVar10 = *param_9;
      param_7[6] = param_9[1];
      *plVar9 = lVar10;
      param_7[7] = lVar5;
      if ((long *)*plVar9 != (long *)0x0) {
        (**(code **)(*(long *)*plVar9 + 0x20))();
      }
    }
    if (param_11 != (long *)0x0) {
      lVar10 = param_11[1];
      lVar5 = *param_11;
      param_7[0xb] = param_11[2];
      param_7[10] = lVar10;
      param_7[9] = lVar5;
    }
    pcStack_50 = FUN_fffffff009c89ff0;
    local_58 = param_7;
    local_48 = param_8;
    iVar4 = (**(code **)(*(long *)param_7[0xd] + 0x748))
                      ((long *)param_7[0xd],(int)param_7[0xc],param_7[8],param_8,&local_58,0,0);
    if (iVar4 == 0) {
      uVar8 = 0;
      if ((param_8 != 0) && ((*(uint *)(param_7 + 0x11) & 1) == 0)) {
        if (param_8 < *(ushort *)((long)param_7 + 0x16)) {
          if ((long *)param_7[0xd] == (long *)0x0) {
            uVar6 = 0x3f;
          }
          else {
            iVar4 = (**(code **)(*(long *)param_7[0xd] + 0x5c0))();
            uVar6 = 0x1ff;
            if (iVar4 < 3) {
              uVar6 = 0x3f;
            }
          }
          if ((uVar6 & param_8) == 0) {
            local_60 = 0;
            local_70 = *(long *)(*param_7 + 0x88);
            local_78 = param_7;
            if ((local_70 == 0) &&
               (local_70 = thunk_FUN_fffffff00a894f04(param_7,-0xff6375bcc), local_70 == 0)) {
              local_70 = 0;
            }
            puStack_68 = &local_60;
            iVar4 = (**(code **)(*(long *)param_7[0xd] + 0x748))
                              ((long *)param_7[0xd],(int)param_7[0xc],param_7[0xe],0,&local_78,0,0);
            if (iVar4 != 0) {
              auVar1._8_8_ = extraout_var_00;
              auVar1._0_8_ = extraout_d0_00;
              FUN_fffffff009c895b0(auVar1,param_2,param_3,param_4,param_5,param_6,param_7);
            }
          }
        }
        uVar8 = 0;
      }
    }
    else {
      auVar2._8_8_ = extraout_var;
      auVar2._0_8_ = extraout_d0;
      FUN_fffffff009c895b0(auVar2,param_2,param_3,param_4,param_5,param_6,param_7);
      (**(code **)(*(long *)param_7[8] + 0xe0))((long *)param_7[8],0);
      if ((long *)param_7[5] != (long *)0x0) {
        (**(code **)(*(long *)param_7[5] + 0x28))();
      }
      *plVar9 = 0;
      param_7[6] = 0;
      param_7[7] = 0;
      if ((long *)param_7[8] != (long *)0x0) {
        (**(code **)(*(long *)param_7[8] + 0x28))();
      }
      uVar8 = 0;
      param_7[8] = 0;
    }
  }
  else {
    uVar8 = 0xe00002d8;
    if ((*(uint *)((long)param_7 + 0x8c) & 1) != 0) {
      if (((*(uint *)((long)param_7 + 0x8c) >> 0x1e & 1) == 0) ||
         (bVar3 = thunk_FUN_fffffff00a394140(), !bVar3)) {
        psVar7 = *(short **)PTR_DAT_fffffff00807fa80;
        lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
        auVar1 = thunk_FUN_fffffff00a895b28(lVar5);
        thunk_FUN_fffffff00a8df19c
                  (auVar1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar7,0,
                   (byte *)"%s: %s::%s: Unexpected call to sendControlInData in state %d\n");
      }
      else {
        lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
        thunk_FUN_fffffff00a895b28(lVar5);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"%s: %s::%s: Unexpected call to sendControlInData in state %d\n");
      }
    }
  }
  return uVar8;
}

