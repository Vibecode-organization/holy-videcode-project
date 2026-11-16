// FUN_fffffff009c41d4c @ fffffff009c41d4c size=416

undefined8
FUN_fffffff009c41d4c
          (long *param_1,undefined8 *param_2,uint param_3,undefined8 param_4,undefined8 param_5,
          long param_6,long *param_7)

{
  uint *puVar1;
  undefined8 *puVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  if (param_1 != (long *)0x0) {
    puVar5 = (undefined8 *)0x0;
    puVar6 = param_2;
    do {
      puVar2 = (undefined8 *)*puVar6;
      if ((undefined8 *)*puVar6 == (undefined8 *)0x0) {
        puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff00806b7f0);
        if (puVar2 == (undefined8 *)0x0) {
          thunk_EXT_FUN_80110000038fe9a0("IONewZero failed to alloc IOSurfaceClientSharedListEntry")
          ;
          return 0;
        }
        plVar3 = (long *)thunk_EXT_FUN_801100000396cb64(param_1[1],param_4,0,param_5,0,0);
        if ((long *)puVar2[1] != (long *)0x0) {
          (**(code **)(*(long *)puVar2[1] + 0x28))();
        }
        puVar2[1] = plVar3;
        if (plVar3 == (long *)0x0) {
          thunk_EXT_FUN_80110000038fe9a0
                    ("IOSurfaceRootUserClient: couldn\'t map shared memory region into client");
          thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b830,puVar2);
          return 0;
        }
        uVar4 = (**(code **)(*plVar3 + 0x78))(plVar3);
        puVar2[2] = uVar4;
        *puVar2 = 0;
        puVar6 = param_2;
        if (puVar5 != (undefined8 *)0x0) {
          puVar6 = puVar5;
        }
        *puVar6 = puVar2;
      }
      puVar5 = puVar2;
      puVar1 = (uint *)(param_1 + 4);
      if (param_3 < *puVar1) {
        *param_7 = puVar5[2] + param_6 * (ulong)param_3;
        return 1;
      }
      param_1 = (long *)*param_1;
      puVar6 = puVar5;
      param_3 = param_3 - *puVar1;
    } while (param_1 != (long *)0x0);
  }
  uVar4 = thunk_EXT_FUN_8011000003a49114
                    (
                    "\"IOSurfaceRootUserClient: asked to allocate client shared id %08x not known by IOSurfaceRoot\" @%s:%d"
                    );
  return uVar4;
}

