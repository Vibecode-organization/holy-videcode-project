// FUN_fffffff00820f5dc @ fffffff00820f5dc size=692

void FUN_fffffff00820f5dc(long *param_1)

{
  long lVar1;
  uint uVar2;
  undefined *puVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  
  if ((int)param_1[0x16] != -1) {
    (**(code **)(*param_1 + 0xd0))(param_1);
    *(undefined4 *)(param_1 + 0x16) = 0xffffffff;
  }
  FUN_fffffff00820f890(param_1);
  puVar3 = PTR_DAT_fffffff007ca5f88;
  if ((param_1[5] == *(long *)PTR_DAT_fffffff007ca61d0) && ((*(byte *)(param_1 + 0x19) & 1) == 0)) {
    lVar7 = 2;
  }
  else {
    lVar7 = 1;
    if (*(int *)(param_1[2] + 0x10964) == 1) {
      lVar7 = 2;
    }
  }
  lVar10 = 0;
  do {
    plVar8 = param_1 + 6 + lVar10 * 8;
    if ((((ulong)(param_1 + 6) ^ (ulong)plVar8) & 0xffc0000000000000) != 0) {
      plVar8 = (long *)((ulong)plVar8 & 0xffffffffffff | 0xc8a2000000000000);
    }
    plVar8[1] = 0;
    (**(code **)(*(long *)*plVar8 + 0xe0))((long *)*plVar8,0);
    (**(code **)(*(long *)*plVar8 + 0x28))();
    *plVar8 = 0;
    lVar4 = plVar8[2];
    plVar8[2] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca5048,lVar4,0x40);
    lVar4 = plVar8[3];
    plVar8[3] = 0;
    plVar8[2] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca5098,lVar4,0x40);
    lVar4 = plVar8[4];
    plVar8[4] = 0;
    plVar8[3] = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar4,0x20);
    lVar9 = 0;
    lVar4 = 0;
    plVar8[4] = 0;
    do {
      if (*(long *)(plVar8[6] + lVar4 * 8) != 0) {
        uVar2 = *(uint *)puVar3;
        uVar5 = *(undefined8 *)(plVar8[5] + lVar4 * 8);
        *(undefined8 *)(plVar8[5] + lVar4 * 8) = 0;
        thunk_EXT_FUN_80110000038fe768
                  (&DAT_fffffff007ca50e8,uVar5,(long)(int)(1 << (ulong)(uVar2 & 0x1f) & 0xfffffff8))
        ;
        lVar1 = plVar8[6];
        *(undefined8 *)(plVar8[5] + lVar4 * 8) = 0;
        uVar6 = (ulong)(int)(1 << (ulong)(*(uint *)puVar3 & 0x1f) & 0xfffffff8);
        if (0x7fffffffffffffff < uVar6) {
          uVar6 = 0x8000000000000000;
        }
        uVar5 = *(undefined8 *)(lVar1 + lVar4 * 8);
        *(undefined8 *)(lVar1 + lVar4 * 8) = 0;
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca5138,uVar5,uVar6);
        lVar1 = plVar8[7];
        *(undefined8 *)(plVar8[6] + lVar4 * 8) = 0;
        uVar2 = *(uint *)puVar3;
        uVar5 = *(undefined8 *)(lVar1 + lVar4 * 8);
        *(undefined8 *)(lVar1 + lVar4 * 8) = 0;
        thunk_EXT_FUN_80110000038fe6b0
                  (uVar5,(ulong)(long)(1 << (ulong)(uVar2 & 0x1f)) >> 1 & 0x7ffffffffffffffc);
      }
      lVar4 = lVar4 + 1;
      lVar9 = lVar9 + 8;
    } while (lVar9 != 0x40);
    lVar4 = plVar8[6];
    plVar8[6] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca5188,lVar4,0x40);
    lVar4 = plVar8[5];
    plVar8[5] = 0;
    plVar8[6] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca51d8,lVar4,0x40);
    plVar8[5] = 0;
    lVar4 = plVar8[7];
    plVar8[7] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca5228,lVar4,0x40);
    plVar8[7] = 0;
    lVar10 = lVar10 + 1;
  } while (lVar10 != lVar7);
  DataMemoryBarrier(2,3);
  return;
}

