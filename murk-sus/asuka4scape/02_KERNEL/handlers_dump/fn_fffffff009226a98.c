// FUN_fffffff009226a98 @ fffffff009226a98 size=4 depth=0
// CALLERS:
//   fffffff00afdc800 ?
//   fffffff007eec0e8 ?
// CALLS:

/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_fffffff009226a98(long param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  long *plVar4;
  long in_x3;
  long *in_x4;
  undefined8 uVar5;
  long *plVar6;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  ulong auStack_98 [10];
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff007efc840;
  uVar5 = 0xe00002c2;
  uVar1 = *(uint *)(param_3 + 0x60);
  if (uVar1 == 0) {
    if (*(long *)(param_3 + 0x68) == 0) {
      uVar5 = 0xe00002c7;
    }
    else {
      auStack_98[6] = 0;
      auStack_98[5] = 0;
      auStack_98[8] = 0;
      auStack_98[7] = 0;
      auStack_98[2] = 0;
      auStack_98[1] = 0;
      auStack_98[4] = 0;
      auStack_98[3] = 0;
      if (0xffffffc0 < *(int *)(param_3 + 0x38) - 0x40U) {
        thunk_FUN_fffffff00a354958(auStack_98 + 1,*(undefined8 **)(param_3 + 0x30),0x40);
        auVar2._8_8_ = extraout_var_00;
        auVar2._0_8_ = extraout_d0_00;
        uVar5 = FUN_fffffff009251028
                          (auVar2,in_q1,in_s2,in_s3,in_s4,in_s5,param_2,"get-named-property",
                           auStack_98 + 1,in_x3,in_x4);
        if ((int)uVar5 == 0) {
          plVar6 = *(long **)(param_3 + 0x68);
          auStack_98[0] = (ulong)*(uint *)(param_3 + 0x70);
          uVar5 = (**(code **)(*plVar6 + 0xd8))(plVar6,0);
          if ((int)uVar5 == 0) {
            plVar4 = (long *)(**(code **)(*plVar6 + 0xe8))(plVar6,0);
            if (plVar4 == (long *)0x0) {
              uVar5 = 0xe00002bc;
            }
            else {
              uVar5 = (**(code **)(*plVar4 + 0x78))();
              uVar5 = FUN_fffffff00923fc18(param_1,auStack_98 + 1,uVar5,auStack_98,0,0);
              *(int *)(param_3 + 0x70) = (int)auStack_98[0];
              (**(code **)(*plVar4 + 0xa8))(plVar4);
              (**(code **)(*plVar4 + 0x28))(plVar4);
            }
            (**(code **)(*plVar6 + 0xe0))(plVar6,0);
          }
        }
      }
    }
  }
  else {
    auStack_98[6] = 0;
    auStack_98[5] = 0;
    auStack_98[8] = 0;
    auStack_98[7] = 0;
    auStack_98[2] = 0;
    auStack_98[1] = 0;
    auStack_98[4] = 0;
    auStack_98[3] = 0;
    auStack_98[0] = (ulong)uVar1;
    if (0xffffffc0 < *(int *)(param_3 + 0x38) - 0x40U) {
      thunk_FUN_fffffff00a354958(auStack_98 + 1,*(undefined8 **)(param_3 + 0x30),0x40);
      auVar3._8_8_ = extraout_var;
      auVar3._0_8_ = extraout_d0;
      uVar5 = FUN_fffffff009251028
                        (auVar3,in_q1,in_s2,in_s3,in_s4,in_s5,param_2,"get-named-property",
                         auStack_98 + 1,in_x3,in_x4);
      if ((int)uVar5 == 0) {
        uVar5 = FUN_fffffff00923fc18
                          (param_1,auStack_98 + 1,*(undefined8 *)(param_3 + 0x58),auStack_98,0,0);
        *(int *)(param_3 + 0x60) = (int)auStack_98[0];
      }
    }
  }
  if (*(long *)PTR_DAT_fffffff007efc840 != lStack_48) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar5;
}

