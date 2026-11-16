// FUN_fffffff009a1f1ac @ fffffff009a1f1ac size=608 depth=1
// CALLERS:
//   fffffff00afe78ac ?
//   fffffff009a1df14 FUN_fffffff009a1df0c
// CALLS:
//   fffffff009a4813c thunk_FUN_fffffff00a8eddac
//   fffffff009a4826c thunk_FUN_fffffff00a89b94c
//   fffffff009a1e470 FUN_fffffff009a1e470

undefined4
FUN_fffffff009a1f1ac
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,long param_8)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  int iVar3;
  undefined4 *puVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  undefined8 uVar9;
  undefined *local_120;
  undefined8 local_118;
  code *local_110;
  undefined *local_108;
  undefined8 *puStack_100;
  undefined8 *local_f8;
  undefined8 *puStack_f0;
  undefined8 *local_e8;
  undefined8 local_e0;
  long lStack_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_58;
  
  local_f8 = &local_70;
  local_70 = 0;
  local_60 = DAT_fffffff007849f60;
  local_58 = 0;
  local_e8 = &local_90;
  local_90 = 0;
  local_80 = DAT_fffffff007849f60;
  local_78 = 0xe00002f0;
  puStack_f0 = &local_b0;
  local_b0 = 0;
  local_a0 = DAT_fffffff007849f60;
  local_98 = 0;
  puStack_100 = &local_d0;
  local_d0 = 0;
  local_c0 = DAT_fffffff007849f60;
  local_b8 = 0;
  local_e0 = *(undefined8 *)(*(long *)(param_8 + 0x20) + 8);
  local_120 = PTR_DAT_fffffff008017340;
  local_118 = DAT_fffffff007849f68;
  local_110 = FUN_fffffff009a1f40c;
  local_108 = &DAT_fffffff0080137e8;
  lStack_d8 = param_8;
  local_c8 = puStack_100;
  local_a8 = puStack_f0;
  local_88 = local_e8;
  local_68 = local_f8;
  thunk_FUN_fffffff00a89b94c(*(long **)(param_7 + 0x118),(long)&local_120);
  puVar4 = (undefined4 *)local_c8[3];
  if (puVar4 != (undefined4 *)0x0) {
    pcVar8 = *(code **)(puVar4 + 8);
    if (pcVar8 == (code *)0x0) {
      (**(code **)(**(long **)(param_7 + 0xf8) + 0x108))(*(long **)(param_7 + 0xf8),local_68[3],0);
    }
    else {
      uVar6 = *(undefined8 *)(puVar4 + 6);
      uVar7 = *(undefined8 *)(puVar4 + 10);
      uVar1 = *puVar4;
      uVar9 = local_a8[3];
      iVar3 = 0;
      if (*(long **)(puVar4 + 2) != (long *)0x0) {
        iVar3 = (**(code **)(**(long **)(puVar4 + 2) + 0xb0))();
      }
      (*pcVar8)(uVar6,uVar7,uVar1,(int)uVar9 - iVar3);
      lVar5 = local_c8[3];
      if (*(long **)(lVar5 + 8) != (long *)0x0) {
        (**(code **)(**(long **)(lVar5 + 8) + 0x28))();
        lVar5 = local_c8[3];
      }
      *(undefined8 *)(lVar5 + 8) = 0;
      auVar2 = (**(code **)(**(long **)(param_7 + 0x118) + 0x108))
                         (*(long **)(param_7 + 0x118),local_68[3]);
      FUN_fffffff009a1e470(auVar2,param_2,param_3,param_4,param_5,param_6,param_7);
      *(int *)(param_7 + 0x168) = *(int *)(param_7 + 0x168) + -1;
    }
  }
  uVar1 = *(undefined4 *)(local_88 + 3);
  thunk_FUN_fffffff00a8eddac((long)&local_d0,8);
  thunk_FUN_fffffff00a8eddac((long)&local_b0,8);
  thunk_FUN_fffffff00a8eddac((long)&local_90,8);
  thunk_FUN_fffffff00a8eddac((long)&local_70,8);
  return uVar1;
}

