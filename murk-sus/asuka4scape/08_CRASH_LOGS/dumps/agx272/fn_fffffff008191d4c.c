// FUN_fffffff008191d4c @ fffffff008191d4c size=936

undefined8
FUN_fffffff008191d4c
          (long param_1,long param_2,long param_3,ulong param_4,long param_5,undefined8 param_6,
          undefined8 param_7)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long *plVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long *plVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  
  if ((param_4 & 1) != 0) {
    thunk_EXT_FUN_80110000029615ec(*(undefined8 *)(param_1 + 0x488));
    plVar4 = (long *)(**(code **)(DAT_fffffff00ae256c8 + 0x68))();
    uVar10 = *(undefined8 *)(param_1 + 0x530);
    uVar12 = *(undefined8 *)(param_1 + 0x480);
    pcVar1 = (char *)0x0;
    if (*(char *)(param_2 + 0x10) != '\0') {
      pcVar1 = (char *)(param_2 + 0x10);
    }
    uVar9 = *(undefined8 *)(param_5 + 0x78);
    uVar5 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x580),&DAT_fffffff00ae22130);
    (**(code **)(*plVar4 + 0xe8))(plVar4,uVar10,param_1,uVar12,pcVar1,uVar9,uVar5);
    thunk_EXT_FUN_801100000296a540(plVar4,*(long *)(*(long *)(param_5 + 0x70) + 0x20) + 0x20);
    if ((*(byte *)(param_3 + 8) & 1) != 0) {
      plVar11 = *(long **)(*(long *)(param_1 + 0x610) + 0xa0);
      lVar8 = *(long *)(param_3 + 0xe0);
      lVar7 = *(long *)(param_3 + 0xd8);
      lVar13 = *(long *)(param_3 + 0xe8);
      lVar15 = *(long *)(param_3 + 0x100);
      lVar14 = *(long *)(param_3 + 0xf8);
      lVar17 = *(long *)(param_3 + 0xd0);
      lVar16 = *(long *)(param_3 + 200);
      plVar11[0xb] = *(long *)(param_3 + 0xf0);
      plVar11[10] = lVar13;
      plVar11[0xd] = lVar15;
      plVar11[0xc] = lVar14;
      plVar11[7] = lVar17;
      plVar11[6] = lVar16;
      plVar11[9] = lVar8;
      plVar11[8] = lVar7;
      lVar7 = *(long *)(param_3 + 0xa8);
      lVar13 = *(long *)(param_3 + 0xc0);
      lVar8 = *(long *)(param_3 + 0xb8);
      plVar11[3] = *(long *)(param_3 + 0xb0);
      plVar11[2] = lVar7;
      plVar11[5] = lVar13;
      plVar11[4] = lVar8;
      uVar6 = (**(code **)(*plVar11 + 0x78))(plVar11,plVar11 + 2);
      if ((uVar6 & 1) == 0) {
        (**(code **)(*plVar4 + 0x28))(plVar4);
        *(undefined4 *)(param_1 + 0x520) = 0x10f;
      }
      else {
        (**(code **)(*plVar11 + 0x80))(plVar11);
        uVar6 = FUN_fffffff008196468(param_1,plVar4,param_6,param_7,param_2,param_3,param_5);
        if ((uVar6 & 1) != 0) {
          iVar2 = *(int *)(param_1 + 0x840);
          *(int *)(plVar4 + 0x3b) = iVar2;
          *(int *)(param_1 + 0x840) = iVar2 + 1;
          thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
          lVar7 = *(long *)(param_1 + 0x530);
          if ((*(byte *)(lVar7 + 0x1ac44) >> 3 & 1) != 0) {
            lVar8 = plVar4[0x20];
            uVar3 = *(undefined4 *)((long)plVar4 + 0x814);
            uVar10 = *(undefined8 *)(param_1 + 0x410);
            uVar12 = *(undefined8 *)(*(long *)(param_1 + 0x808) + 0x30);
            thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x1ac48));
            thunk_EXT_FUN_80110000036da494(0x85930c2c,uVar3,uVar10,lVar8,uVar12,0);
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x1ac48));
          }
          thunk_EXT_FUN_80110000029595ec(*(undefined8 *)(param_1 + 0x818),plVar4);
          (**(code **)(*plVar4 + 0x28))(plVar4);
          *(byte *)(param_1 + 0x7e9) =
               *(byte *)(param_1 + 0x7e9) |
               (byte)(1 << (ulong)(*(uint *)(*(long *)(param_1 + 0x818) + 0xe8) & 0x1f));
          (**(code **)(**(long **)(param_1 + 0x808) + 0x98))
                    (*(long **)(param_1 + 0x808),param_1 + 0x768);
          plVar4 = *(long **)(param_1 + 0x808);
          (**(code **)(*plVar4 + 0x98))(plVar4,param_1 + 0x498);
          if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x11164) & 1) != 0) {
            thunk_EXT_FUN_80110000029486ac
                      (*(undefined8 *)(plVar4[2] + 0x148),plVar4 + 0x23,param_1 + 0x628);
          }
          lVar7 = *(long *)(*(long *)(param_1 + 0x610) + 0xa8);
          lVar8 = (ulong)*(uint *)(lVar7 + 0x28) * 0x40;
          uVar6 = lVar7 + 0x4c0 + (long)(int)lVar8;
          if (lVar8 - (int)lVar8 != 0) {
            uVar6 = lVar7 + 0x4c0 + lVar8 & 0xffffffffffffU | 0x2bad000000000000;
          }
          thunk_EXT_FUN_801100000294849c
                    (*(undefined8 *)(*(long *)(lVar7 + 0x18) + 0x148),param_1 + 0x498,uVar6);
          lVar7 = *(long *)(param_1 + 0x530);
          if ((((*(byte *)(*(long *)(lVar7 + 0x111b0) + 0x54) & 1) != 0) &&
              ((*(byte *)(*(long *)(lVar7 + 0x111b0) + 0x2c) >> 4 & 1) != 0)) ||
             ((*(byte *)(lVar7 + 0x5c8) >> 5 & 1) != 0)) {
            thunk_EXT_FUN_8011000002947870(*(undefined8 *)(lVar7 + 0x148),param_1 + 0x498);
          }
          return 1;
        }
      }
      thunk_EXT_FUN_80110000029615f8(*(undefined8 *)(param_1 + 0x488));
      return 0;
    }
  }
  uVar10 = thunk_EXT_FUN_8011000003a49114
                     ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
  return uVar10;
}

