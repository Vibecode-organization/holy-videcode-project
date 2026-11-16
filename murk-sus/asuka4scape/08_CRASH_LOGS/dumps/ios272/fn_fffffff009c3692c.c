// FUN_fffffff009c3692c @ fffffff009c3692c size=692

undefined8
FUN_fffffff009c3692c
          (undefined8 *param_1,uint param_2,ulong param_3,uint param_4,uint *param_5,long *param_6)

{
  undefined *puVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  undefined *puVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  
  puVar1 = PTR_DAT_fffffff00806ca78;
  puVar6 = PTR_DAT_fffffff00806ca70;
  puVar8 = param_1;
  puVar9 = (undefined8 *)0x0;
  do {
    uVar10 = param_2;
    puVar8 = (undefined8 *)*puVar8;
    if (puVar8 == (undefined8 *)0x0) {
      puVar8 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff00806b570);
      if (puVar8 == (undefined8 *)0x0) {
        thunk_EXT_FUN_80110000038fe9a0("IONewZero failed to alloc IOSurfaceSharedListEntry");
        return 0;
      }
      lVar5 = thunk_EXT_FUN_8011000003962c64(param_4 | 0x10063,0x4000,*(undefined8 *)puVar1);
      if ((long *)puVar8[1] != (long *)0x0) {
        (**(code **)(*(long *)puVar8[1] + 0x28))();
      }
      puVar8[1] = lVar5;
      if (lVar5 == 0) {
        thunk_EXT_FUN_80110000038fe9a0
                  (
                  "IOBufferMemoryDescriptor::inTaskWithOptions failed to allocate a surface shared block."
                  );
        puVar6 = &DAT_fffffff00806b5b0;
LAB_fffffff009c36bb4:
        thunk_EXT_FUN_80110000038fe270(puVar6,puVar8);
        return 0;
      }
      iVar2 = thunk_EXT_FUN_8011000003977af0(lVar5,*(undefined8 *)puVar6,4,4);
      if (iVar2 != 0) {
        thunk_EXT_FUN_80110000038fe9a0
                  ("Unable to set shared memory region ownership to kernel: %08x\n");
      }
      iVar2 = (**(code **)(*(long *)puVar8[1] + 0xd8))((long *)puVar8[1],0);
      if (iVar2 != 0) {
        thunk_EXT_FUN_80110000038fe9a0("Unable to prepare shared entry: %08x");
        if ((long *)puVar8[1] != (long *)0x0) {
          (**(code **)(*(long *)puVar8[1] + 0x28))();
        }
        puVar8[1] = 0;
        puVar6 = &DAT_fffffff00806b5f0;
        goto LAB_fffffff009c36bb4;
      }
      plVar3 = (long *)(**(code **)(*(long *)puVar8[1] + 0xe8))((long *)puVar8[1],1);
      if ((long *)puVar8[2] != (long *)0x0) {
        (**(code **)(*(long *)puVar8[2] + 0x28))();
      }
      puVar8[2] = plVar3;
      if (plVar3 == (long *)0x0) {
        if ((long *)puVar8[1] != (long *)0x0) {
          (**(code **)(*(long *)puVar8[1] + 0x28))();
        }
        puVar8[1] = 0;
        puVar6 = &DAT_fffffff00806b630;
        goto LAB_fffffff009c36bb4;
      }
      uVar4 = (**(code **)(*plVar3 + 0x78))(plVar3);
      puVar8[3] = uVar4;
      *puVar8 = 0;
      uVar7 = 0;
      if (param_3 != 0) {
        uVar7 = (uint)(0x4000 / param_3);
      }
      *(uint *)(puVar8 + 4) = uVar7;
      if (puVar9 == (undefined8 *)0x0) {
        *param_1 = puVar8;
      }
      else {
        *puVar9 = puVar8;
      }
    }
    else {
      uVar7 = *(uint *)(puVar8 + 4);
    }
    puVar9 = puVar8;
    param_2 = uVar10 - uVar7;
    if (uVar10 < uVar7) {
      *param_5 = uVar10;
      lVar5 = puVar8[3] + param_3 * uVar10;
      *param_6 = lVar5;
      thunk_EXT_FUN_8011000003a61cc0(lVar5,param_3);
      return 1;
    }
  } while( true );
}

