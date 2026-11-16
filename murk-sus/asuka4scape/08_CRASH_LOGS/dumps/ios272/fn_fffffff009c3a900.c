// FUN_fffffff009c3a900 @ fffffff009c3a900 size=340

/* WARNING: Removing unreachable block (ram,0xfffffff009c3aa2c) */

void FUN_fffffff009c3a900(long *param_1)

{
  undefined1 uVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  iVar2 = (**(code **)(PTR_DAT_fffffff00806ca28 + 0x2c0))();
  if (iVar2 != 0) {
    puVar4 = *(undefined8 **)PTR_DAT_fffffff00806ca58;
    (**(code **)(*param_1 + 200))(param_1,"IOUserClientEntitlements",*puVar4);
    (**(code **)(*param_1 + 200))(param_1,"IOUserClientDefaultLocking",*puVar4);
    (**(code **)(*param_1 + 200))
              (param_1,"IOUserClientDefaultLockingSetProperties",
               **(undefined8 **)PTR_DAT_fffffff00806ca60);
    (**(code **)(*param_1 + 200))
              (param_1,"IOUserClientDefaultLockingSingleThreadExternalMethod",*puVar4);
    lVar3 = param_1[0x1f];
    if (lVar3 == 0) {
      lVar3 = 0;
    }
    uVar1 = FUN_fffffff009c37f40(param_1[0x1d],param_1,lVar3);
    *(undefined1 *)(param_1 + 0x1e) = uVar1;
  }
  return;
}

