// FUN_fffffff009c43a1c @ fffffff009c43a1c size=1200
// CALLERS:
//   fffffff00afec1cd no-fn
//   fffffff009c4395c FUN_fffffff009c43898@fffffff009c43898
// CALLEES:
//   fffffff009c45b34 FUN_fffffff009c45b34
//   fffffff009c49594 thunk_FUN_fffffff00a903010
//   fffffff009c49a54 thunk_FUN_fffffff00a89a1f4
//   fffffff009c495f4 thunk_FUN_fffffff00a9029a0
//   fffffff00a89797c FUN_fffffff00a89797c
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c46f98 FUN_fffffff009c46f98

undefined8
FUN_fffffff009c43a1c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long *param_9,long param_10,long *param_11)

{
  bool bVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  undefined8 *puVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  undefined8 extraout_d0;
  undefined1 auVar11 [16];
  undefined8 extraout_var;
  
  auVar11 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))(param_1._0_8_);
  plVar6 = *(long **)(param_7 + 0x38);
  *(long **)(param_7 + 0x38) = param_11;
  if (param_11 != (long *)0x0) {
    auVar11 = (**(code **)(*param_11 + 0x20))(param_11);
  }
  if (plVar6 != (long *)0x0) {
    auVar11 = (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  FUN_fffffff009c46f98(auVar11,param_2,param_3,param_4,param_5,param_6,(int *)(param_7 + 0x20),1);
  puVar7 = (undefined8 *)(param_7 + 0x48);
  *(undefined8 *)(param_7 + 0x50) = 0;
  *puVar7 = 0;
  *(undefined8 *)(param_7 + 0x80) = 0;
  *(undefined8 *)(param_7 + 0x78) = 0;
  *(undefined8 *)(param_7 + 0x90) = 0;
  *(undefined8 *)(param_7 + 0x88) = 0;
  *(undefined8 *)(param_7 + 0x60) = 0;
  *(undefined8 *)(param_7 + 0x58) = 0;
  *(undefined8 *)(param_7 + 0x70) = 0;
  *(undefined8 *)(param_7 + 0x68) = 0;
  if (param_10 == 0) {
    param_10 = 0;
  }
  *(undefined8 *)(param_7 + 0x28) = param_8;
  *(long *)(param_7 + 0x30) = param_10;
  uVar3 = thunk_FUN_fffffff00a903010();
  *(undefined8 *)(param_7 + 0x40) = uVar3;
  plVar6 = *(long **)(param_7 + 0x98);
  *(long **)(param_7 + 0x98) = param_9;
  if (param_9 != (long *)0x0) {
    (**(code **)(*param_9 + 0x20))(param_9);
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  *(undefined2 *)(param_7 + 0xa0) = 0x100;
  if (*(long **)(param_7 + 0xa8) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0xa8) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0xa8) = 0;
  if (*(long *)(param_7 + 0x40) == 0) {
LAB_fffffff009c43e60:
    uVar3 = 0;
  }
  else {
    lVar9 = 0;
    lVar10 = 10;
    do {
      plVar6 = thunk_FUN_fffffff00a89a1f4(1);
      if ((long *)puVar7[lVar9] != (long *)0x0) {
        (**(code **)(*(long *)puVar7[lVar9] + 0x28))();
      }
      puVar7[lVar9] = plVar6;
      if (plVar6 == (long *)0x0) goto LAB_fffffff009c43e60;
      lVar9 = lVar9 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    plVar6 = *(long **)(param_7 + 0x98);
    if (plVar6 != (long *)0x0) {
      lVar9 = (**(code **)(*plVar6 + 0x138))(plVar6,PTR_s_IOSurfaceMemoryPoolSize_fffffff008066fd0);
      auVar11._8_8_ = extraout_var;
      auVar11._0_8_ = extraout_d0;
      if (lVar9 != 0) {
        if (param_9 != (long *)0x0) {
          auVar11 = (**(code **)(*param_9 + 0x20))(param_9);
        }
        bVar1 = FUN_fffffff009c45b34
                          (auVar11,param_2,param_3,param_4,param_5,param_6,param_7,param_9);
        if (!bVar1) {
          thunk_FUN_fffffff00a9029a0
                    ((byte *)
                     "====> %s:%d Unable to pre-allocate IOSurfaceMemoryPool memory for pool id %llu\n"
                    );
        }
      }
      plVar6 = (long *)(**(code **)(*param_9 + 0x138))
                                 (param_9,PTR_s_IOSurfaceMemoryPoolZerofillEnabl_fffffff008066fd8);
      lVar9 = *(long *)PTR_PTR_fffffff00806ca20;
      plVar6 = thunk_FUN_fffffff00a894f30(plVar6,lVar9);
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x20))(plVar6);
        uVar2 = (**(code **)(*plVar6 + 0x88))(plVar6);
        *(undefined1 *)(param_7 + 0xa0) = uVar2;
      }
      plVar4 = (long *)(**(code **)(*param_9 + 0x138))
                                 (param_9,PTR_s_IOSurfaceMemoryPoolCacheModeSwit_fffffff008066fe0);
      plVar4 = thunk_FUN_fffffff00a894f30(plVar4,lVar9);
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x20))(plVar4);
        uVar2 = (**(code **)(*plVar4 + 0x88))(plVar4);
        *(undefined1 *)(param_7 + 0xa1) = uVar2;
      }
      plVar5 = (long *)(**(code **)(*param_9 + 0x138))
                                 (param_9,PTR_s_IOSurfaceMemoryPoolEntitlement_fffffff008066fe8);
      plVar5 = thunk_FUN_fffffff00a894f30(plVar5,*(long *)PTR_PTR_fffffff00806ca10);
      plVar8 = *(long **)(param_7 + 0xa8);
      *(long **)(param_7 + 0xa8) = plVar5;
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x20))();
      }
      if (plVar8 != (long *)0x0) {
        (**(code **)(*plVar8 + 0x28))(plVar8);
      }
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
    }
    uVar3 = 1;
  }
  if (param_11 != (long *)0x0) {
    (**(code **)(*param_11 + 0x28))(param_11);
  }
  if (param_9 != (long *)0x0) {
    (**(code **)(*param_9 + 0x28))(param_9);
  }
  return uVar3;
}

