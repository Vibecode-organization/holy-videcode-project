// FUN_fffffff009c3b3ac @ fffffff009c3b3ac size=480
// CALLERS:
//   fffffff00afec0bb ?
//   fffffff009c38a84 FUN_fffffff009c38a6c@fffffff009c38a6c
// CALLS:
//   fffffff009c209b8 FUN_fffffff009c209b8
//   fffffff009c3f130 FUN_fffffff009c3f130
//   fffffff009c41314 FUN_fffffff009c41314
//   fffffff009c26fcc FUN_fffffff009c26fcc
//   fffffff009c2c18c FUN_fffffff009c2c18c
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c2af10 FUN_fffffff009c2af10

/* WARNING: Removing unreachable block (ram,0xfffffff009c3b444) */

undefined8
FUN_fffffff009c3b3ac
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint *param_8,
          undefined8 *param_9,ulong param_10,int *param_11)

{
  uint uVar1;
  long *plVar2;
  long *plVar3;
  undefined8 *puVar4;
  long *plVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined1 extraout_q0 [16];
  undefined1 auVar8 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  uint local_5c;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar6 = 0xe00002c2;
  if ((((param_9 == (undefined8 *)0x0) || (param_8 == (uint *)0x0)) || ((int)param_10 != 0xc)) ||
     (*param_11 != 0xc68)) goto LAB_fffffff009c3b550;
  uVar1 = param_8[1];
  puVar4 = param_9;
  plVar2 = (long *)FUN_fffffff009c3f130
                             (param_1,param_2,param_3,param_4,param_5,param_6,param_7,*param_8);
  if (plVar2 == (long *)0x0) goto LAB_fffffff009c3b550;
  plVar5 = (long *)plVar2[8];
  if (plVar5 == (long *)0x0) {
    plVar5 = (long *)0x0;
LAB_fffffff009c3b47c:
    bVar7 = true;
    auVar8 = extraout_q0;
  }
  else {
    if (plVar5 == (long *)0x0) goto LAB_fffffff009c3b47c;
    auVar8 = (**(code **)(*plVar5 + 0x20))(plVar5);
    bVar7 = false;
  }
  local_5c = 0xaaaaaaaa;
  if ((uVar1 >> 2 & 1) != 0) {
    puVar4 = (undefined8 *)0xffffffff;
    plVar3 = (long *)FUN_fffffff009c26fcc
                               (auVar8,param_2,param_3,param_4,param_5,param_6,plVar5,
                                (ulong)(2 - (uVar1 & 1)),(undefined *)0xffffffff);
    auVar8 = extraout_q0_00;
    if (plVar3 != (long *)0x0) {
      FUN_fffffff009c41314(extraout_q0_00,param_2,param_3,param_4,param_5,param_6,plVar3,0);
      auVar8 = (**(code **)(*plVar3 + 0x28))(plVar3);
    }
  }
  auVar8 = FUN_fffffff009c2af10
                     (auVar8,param_2,param_3,param_4,param_5,param_6,(long)plVar5,uVar1 & 1,puVar4,
                      param_10,(ulong)param_11);
  uVar6 = FUN_fffffff009c209b8
                    (auVar8,param_2,param_3,param_4,param_5,param_6,(long)plVar5,uVar1,&local_5c,
                     param_10,(undefined *)param_11);
  if ((int)uVar6 == 0) {
    FUN_fffffff009c2c18c
              (extraout_q0_01,param_2,param_3,param_4,param_5,param_6,(long)plVar2,param_9);
    *(uint *)(param_9 + 0xd) = local_5c;
  }
  if (!bVar7) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  (**(code **)(*plVar2 + 0x28))(plVar2);
LAB_fffffff009c3b550:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_58) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar6;
}

