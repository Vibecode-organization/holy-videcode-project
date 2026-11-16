// FUN_fffffff0089d215c @ fffffff0089d215c size=300
// CALLERS:
//   fffffff00afcc9d0 no-fn
//   fffffff0089d1e74 FUN_fffffff0089d1e2c@fffffff0089d1e2c
//   fffffff0089d4614 FUN_fffffff0089d45d4@fffffff0089d45d4
// CALLEES:
//   fffffff0089a17e8 FUN_fffffff0089a17e8
//   fffffff008a81ed4 thunk_FUN_fffffff00a8df19c
//   fffffff0089c46cc FUN_fffffff0089c46cc
//   fffffff008a82174 thunk_FUN_fffffff00aa65b10

undefined8
FUN_fffffff0089d215c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 *param_8,long *param_9,undefined8 param_10,undefined *param_11)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  undefined4 uVar7;
  undefined4 uVar8;
  long local_30;
  long *plStack_28;
  
  uVar8 = param_4._0_4_;
  uVar7 = param_3._0_4_;
  FUN_fffffff0089a17e8
            (&local_30,param_1,param_2,param_3,param_4,param_5,param_6,*(long *)(param_7 + 0x10),
             *(undefined8 *)(param_7 + 0x88),(long *)(param_7 + 0x48),param_10,param_11);
  plVar1 = plStack_28;
  lVar4 = local_30;
  auVar6._8_8_ = plStack_28;
  auVar6._0_8_ = local_30;
  plVar2 = (long *)param_9[1];
  local_30 = 0;
  plStack_28 = (long *)0x0;
  param_9[1] = (long)plVar1;
  *param_9 = lVar4;
  if (plVar2 != (long *)0x0) {
    auVar6 = FUN_fffffff0089c46cc(plVar2);
    if (plStack_28 != (long *)0x0) {
      auVar6 = FUN_fffffff0089c46cc(plStack_28);
    }
    lVar4 = *param_9;
  }
  if (lVar4 == 0) {
    thunk_FUN_fffffff00a8df19c
              (auVar6,param_2,uVar7,uVar8,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff007ddeaa8,0x10,
               (byte *)"[ERROR] %s: %s: mapRequest allocation failed\n");
    uVar3 = 0xe00002bd;
  }
  else {
    thunk_FUN_fffffff00aa65b10
              ((undefined8 *)(lVar4 + 0xa0),param_8,(ulong)*(uint *)(param_8 + 0x102) << 4);
    uVar3 = 0;
    lVar4 = *param_9;
    uVar5 = param_8[0x100];
    *(undefined8 *)(lVar4 + 0x1098) = param_8[0x101];
    *(undefined8 *)(lVar4 + 0x1090) = uVar5;
    *(undefined8 *)(lVar4 + 0x10a0) = param_8[0x102];
    *(undefined8 *)(lVar4 + 0x10a8) = param_8[0x103];
  }
  return uVar3;
}

