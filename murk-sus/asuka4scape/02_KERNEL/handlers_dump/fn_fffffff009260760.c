// FUN_fffffff009260760 @ fffffff009260760 size=4 depth=0
// CALLERS:
//   fffffff00afdcffa ?
//   fffffff007ef9e38 ?
// CALLS:

ulong FUN_fffffff009260760(long param_1,long param_2,long param_3)

{
  undefined1 auVar1 [16];
  ulong uVar2;
  long in_x3;
  long *in_x4;
  ulong uVar3;
  ulong uVar4;
  undefined8 extraout_d0;
  undefined8 extraout_var;
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  ulong auStack_70 [5];
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff007efc840;
  uVar3 = **(ulong **)(param_3 + 0x20);
  uVar4 = uVar3 & 0xffffffff;
  auStack_70[1] = 0;
  auStack_70[0] = 0;
  auStack_70[3] = 0;
  auStack_70[2] = 0;
  thunk_FUN_fffffff00a76d3ec((undefined1 *)auStack_70,0x20,&DAT_fffffff0076ff7a8);
  auVar1._8_8_ = extraout_var;
  auVar1._0_8_ = extraout_d0;
  uVar2 = FUN_fffffff009260860
                    (auVar1,in_q1,in_s2,in_s3,in_s4,in_s5,param_2,"send-command",auStack_70,in_x3,
                     in_x4);
  if ((((int)uVar2 == 0) && (uVar2 = 0xe00002e2, 1 < uVar4 - 0x19)) && (uVar4 < 0x100)) {
    auStack_70[0] = (ulong)*(uint *)(param_3 + 0x60);
    uVar2 = FUN_fffffff00923f8c8
                      (*(long *)(param_1 + 0xe0),(int)uVar3,*(undefined8 *)(param_3 + 0x30),
                       (ulong)*(uint *)(param_3 + 0x38),*(undefined8 *)(param_3 + 0x58),auStack_70,0
                      );
    *(int *)(param_3 + 0x60) = (int)auStack_70[0];
  }
  if (*(long *)PTR_DAT_fffffff007efc840 == lStack_48) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

