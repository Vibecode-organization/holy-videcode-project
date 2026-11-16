// FUN_fffffff009859648 @ fffffff009859648 size=4 depth=0
// CALLERS:
//   fffffff00afe3e6e ?
//   fffffff007fc17e0 ?
// CALLS:

undefined8 FUN_fffffff009859648(long *param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  long *plVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined1 auVar10 [16];
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  long *plStack_48;
  
  plStack_48 = (long *)0x0;
  uVar9 = **(undefined8 **)(param_3 + 0x20);
  auVar10 = thunk_FUN_fffffff00a895b28(-0xff50dfb28);
  plVar4 = (long *)param_1[0x1c];
  if (plVar4 != (long *)0x0) {
    auVar10 = (**(code **)(*plVar4 + 0xa8))();
  }
  uVar7 = 0xe00002c0;
  thunk_FUN_fffffff00a8df19c
            (auVar10,in_q1,in_s2,in_s3,in_s4,in_s5,&MACH_HEADER,(short *)PTR_DAT_fffffff007fc77c8,0,
             (byte *)"%s::%s(): Copying LDCM data... (target: %s)\n");
  if (*(long *)(param_3 + 0x58) == 0) {
    uVar7 = 0xe00002c2;
  }
  else if ((param_1[0x1d] != 0) && (uVar1 = thunk_FUN_fffffff00a92d93c(param_1), (uVar1 & 1) == 0))
  {
    uVar7 = (**(code **)(*(long *)param_1[0x1d] + 0x5c8))((long *)param_1[0x1d],&plStack_48,uVar9);
    if ((int)uVar7 == 0) {
      if (plStack_48 == (long *)0x0) {
        *(undefined4 *)(param_3 + 0x60) = 0;
        return 0;
      }
      uVar1 = *(uint *)(param_3 + 0x60);
      uVar2 = (**(code **)(*plStack_48 + 0xa0))();
      if (uVar1 < uVar2) {
        uVar7 = 0xe00002e8;
      }
      else {
        puVar8 = *(undefined8 **)(param_3 + 0x58);
        puVar5 = (undefined8 *)(**(code **)(*plStack_48 + 0xd8))();
        uVar6 = (**(code **)(*plStack_48 + 0xa0))();
        thunk_FUN_fffffff00aa65b10(puVar8,puVar5,uVar6 & 0xffffffff);
        uVar3 = (**(code **)(*plStack_48 + 0xa0))();
        uVar7 = 0;
        *(undefined4 *)(param_3 + 0x60) = uVar3;
      }
    }
    else {
      FUN_fffffff00989fb2c(extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,param_1 + 0x1c);
    }
  }
  if (plStack_48 != (long *)0x0) {
    (**(code **)(*plStack_48 + 0x28))();
  }
  return uVar7;
}

