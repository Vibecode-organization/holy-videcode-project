// FUN_fffffff00817234c @ fffffff00817234c size=260

undefined8
FUN_fffffff00817234c
          (long *param_1,long param_2,undefined8 param_3,undefined4 *param_4,undefined4 *param_5,
          undefined4 *param_6,undefined4 *param_7)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  
  if (param_2 == DAT_fffffff00ae219a0) {
    puVar3 = *(undefined4 **)(param_1[0x96] + 0x918);
    *param_4 = puVar3[0x178];
    *param_5 = *puVar3;
    *param_6 = puVar3[0x179];
    *param_7 = puVar3[1];
    return 0;
  }
  if (param_2 == DAT_fffffff00ae219d8) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008172400. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*param_1 + 0x928))
                      (param_1,param_4 != (undefined4 *)0x0,(undefined8 *)(*param_1 + 0x928));
    return uVar2;
  }
  if (param_2 != DAT_fffffff00ae219d0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008172398. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(PTR_DAT_fffffff007ca6170 + 0x3b8))();
    return uVar2;
  }
  if ((ulong)param_4 >> 0x20 == 0) {
    puVar1 = (undefined8 *)(*(long *)param_1[0x96] + 0x970);
                    /* WARNING: Could not recover jumptable at 0xfffffff008172440. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)*puVar1)((long *)param_1[0x96],param_4,puVar1);
    return uVar2;
  }
  return 0xe00002c2;
}

