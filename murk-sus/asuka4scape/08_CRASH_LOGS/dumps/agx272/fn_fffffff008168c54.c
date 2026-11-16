// FUN_fffffff008168c54 @ fffffff008168c54 size=240

void FUN_fffffff008168c54(long param_1,undefined8 *param_2)

{
  long lVar1;
  long *plVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  lVar1 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-sochot-temp");
  if ((lVar1 == 0) ||
     (plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(lVar1,*(undefined8 *)PTR_DAT_fffffff007ca6090)
     , plVar2 == (long *)0x0)) {
    uVar4 = 0x78;
  }
  else {
    puVar3 = (undefined4 *)(**(code **)(*plVar2 + 0xd8))();
    uVar4 = *puVar3;
  }
  *param_2 = *(undefined8 *)(param_1 + 0x105f8);
  *(undefined4 *)(param_2 + 1) = uVar4;
  *(undefined8 *)((long)param_2 + 0x14) = 0;
  *(undefined8 *)((long)param_2 + 0xc) = 0;
  *(undefined8 *)((long)param_2 + 0x24) = 0;
  *(undefined8 *)((long)param_2 + 0x1c) = 0;
  *(undefined8 *)((long)param_2 + 0x34) = 0;
  *(undefined8 *)((long)param_2 + 0x2c) = 0;
  *(undefined8 *)((long)param_2 + 0x44) = 0;
  *(undefined8 *)((long)param_2 + 0x3c) = 0;
  *(undefined8 *)((long)param_2 + 0x54) = 0;
  *(undefined8 *)((long)param_2 + 0x4c) = 0;
  *(undefined8 *)((long)param_2 + 100) = 0;
  *(undefined8 *)((long)param_2 + 0x5c) = 0;
  *(undefined8 *)((long)param_2 + 0x74) = 0;
  *(undefined8 *)((long)param_2 + 0x6c) = 0;
  *(undefined8 *)((long)param_2 + 0x84) = 0;
  *(undefined8 *)((long)param_2 + 0x7c) = 0;
  *(undefined8 *)((long)param_2 + 0x94) = 0;
  *(undefined8 *)((long)param_2 + 0x8c) = 0;
  *(undefined8 *)((long)param_2 + 0xa4) = 0;
  *(undefined8 *)((long)param_2 + 0x9c) = 0;
  *(undefined8 *)((long)param_2 + 0xb4) = 0;
  *(undefined8 *)((long)param_2 + 0xac) = 0;
  *(undefined8 *)((long)param_2 + 0xc4) = 0;
  *(undefined8 *)((long)param_2 + 0xbc) = 0;
  *(undefined8 *)((long)param_2 + 0xd4) = 0;
  *(undefined8 *)((long)param_2 + 0xcc) = 0;
  *(undefined8 *)((long)param_2 + 0xe4) = 0;
  *(undefined8 *)((long)param_2 + 0xdc) = 0;
  *(undefined8 *)((long)param_2 + 0xf4) = 0;
  *(undefined8 *)((long)param_2 + 0xec) = 0;
  *(undefined8 *)((long)param_2 + 0x104) = 0;
  *(undefined8 *)((long)param_2 + 0xfc) = 0;
  return;
}

