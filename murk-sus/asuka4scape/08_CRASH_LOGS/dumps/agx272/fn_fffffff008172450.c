// FUN_fffffff008172450 @ fffffff008172450 size=4996

/* WARNING: Removing unreachable block (ram,0xfffffff008172950) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081725f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081725bc) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081728ac) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081729f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081724f8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff008172450(long *param_1,undefined8 param_2)

{
  ulong *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  long *plVar4;
  long *plVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  long *plVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  undefined8 local_70;
  undefined8 uStack_68;
  
  puVar1 = (ulong *)(param_1 + 0x20bf);
  thunk_EXT_FUN_8011000002970c1c();
  if ((*(byte *)((long)param_1 + 0x10a72) & 1) != 0) {
    (**(code **)(*param_1 + 0xd8))(param_1,"SharedEventAgentSignalEnabled",0);
    uStack_68 = _UNK_fffffff007113708;
    local_70 = _DAT_fffffff007113700;
    (**(code **)(*param_1 + 0x430))(*param_1 + 0x430,param_1,0xe0078101,&local_70,0x10);
  }
  (**(code **)(*param_1 + 0xd70))(param_1);
  if ((*(byte *)(param_1 + 0xaf) & 1) != 0) {
    thunk_EXT_FUN_80110000029476b0(param_1[0x29]);
    (**(code **)(*(long *)param_1[0x96] + 0xd8))();
    (**(code **)(*(long *)param_1[0x96] + 0xc0))();
    (**(code **)(*param_1 + 0xb48))(*param_1 + 0xb48,param_1);
    (**(code **)(*param_1 + 0xb30))(*param_1 + 0xb30,param_1);
    lVar13 = 0;
    lVar14 = 0x3c;
    do {
      param_1[lVar13 + 0x227a] = 0;
      if ((long *)param_1[lVar13 + 0x223e] != (long *)0x0) {
        (**(code **)(*(long *)param_1[lVar13 + 0x223e] + 0x28))();
      }
      param_1[lVar13 + 0x223e] = 0;
      lVar13 = lVar13 + 1;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    *(undefined1 *)(param_1 + 0xaf) = 0;
  }
  (**(code **)(*param_1 + 0xb98))(param_1);
  if ((long *)param_1[0x5e] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x5e] + 0x28))();
    param_1[0x5e] = 0;
  }
  if ((long *)param_1[0x8b] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x8b] + 0x78))();
    param_1[0x8b] = 0;
  }
  if ((long *)param_1[0x23b2] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x23b2] + 0x28))();
    param_1[0x23b2] = 0;
  }
  plVar4 = param_1 + 0x2ff7;
  if ((long *)param_1[0x234b] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x234b] + 0x28))();
    param_1[0x234b] = 0;
  }
  plVar5 = (long *)param_1[0x234a];
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))();
    param_1[0x234a] = 0;
  }
  if (param_1[0x3079] != 0) {
    thunk_EXT_FUN_801100000297b408();
    (**(code **)(*(long *)param_1[0x3079] + 0x28))();
    param_1[0x3079] = 0;
  }
  if ((long *)param_1[0x2233] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x2233] + 0x28))();
    param_1[0x2233] = 0;
  }
  uVar9 = *puVar1;
  if (uVar9 != 0) {
    uVar9 = (uVar9 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar9 & 0x5555555555555555) << 1;
    uVar9 = (uVar9 & 0xcccccccccccccccc) >> 2 | (uVar9 & 0x3333333333333333) << 2;
    uVar9 = (uVar9 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar9 = (uVar9 & 0xff00ff00ff00ff00) >> 8 | (uVar9 & 0xff00ff00ff00ff) << 8;
    uVar9 = (uVar9 & 0xffff0000ffff0000) >> 0x10 | (uVar9 & 0xffff0000ffff) << 0x10;
    uVar12 = LZCOUNT(uVar9 >> 0x20 | uVar9 << 0x20);
    uVar9 = uVar12;
    do {
      iVar7 = (int)(uVar9 * 8);
      puVar3 = (undefined8 *)((long)param_1 + (long)iVar7 + 0x10608);
      if (uVar9 * 8 - (long)iVar7 != 0) {
        puVar3 = (undefined8 *)
                 ((ulong)(param_1 + uVar9 + 0x20c1) & 0xffffffffffff | 0x2bad000000000000);
      }
      thunk_EXT_FUN_80110000038fe6b0((int *)*puVar3,*(int *)*puVar3 << 2);
      *puVar3 = 0;
      uVar10 = uVar9 >> 3 & 0x1ffffffffffffff8;
      uVar9 = *(ulong *)((long)puVar1 + uVar10) & (1L << (uVar9 & 0x3f) ^ 0xffffffffffffffffU);
      *(ulong *)((long)puVar1 + uVar10) = uVar9;
      uVar8 = (uint)uVar12 & 0x3f;
      uVar10 = 0;
      if (uVar8 != 0x3f) {
        uVar10 = -1L << ((ulong)(uVar8 + 1) & 0x3f);
      }
      uVar9 = uVar9 & uVar10;
      uVar10 = (uVar9 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar9 & 0x5555555555555555) << 1;
      uVar10 = (uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x3333333333333333) << 2;
      uVar10 = (uVar10 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
      uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
      uVar8 = (uint)LZCOUNT(uVar10 >> 0x20 | uVar10 << 0x20);
      if (uVar9 == 0) {
        uVar8 = 0xffffffff;
      }
      uVar2 = uVar8 + ((uint)uVar12 & 0xffffffc0);
      uVar12 = (ulong)uVar2;
      if (0x7fffffff < uVar8) {
        uVar2 = 0xffffffff;
      }
      uVar9 = (ulong)uVar2;
    } while (uVar2 != 0xffffffff);
  }
  if ((long *)param_1[0xa9] != (long *)0x0) {
    *(undefined1 *)(param_1 + 0xaa) = 0;
    (**(code **)(*(long *)param_1[0xa9] + 0xb8))();
    plVar5 = (long *)(**(code **)(*param_1 + 0x378))(*param_1 + 0x378,param_1);
    (**(code **)(*plVar5 + 0xa8))(plVar5,param_1[0xa9]);
    (**(code **)(*(long *)param_1[0xa9] + 0x28))();
    param_1[0xa9] = 0;
  }
  if ((long *)param_1[0xab] != (long *)0x0) {
    *(undefined1 *)(param_1 + 0xac) = 0;
    (**(code **)(*(long *)param_1[0xab] + 0xb8))();
    plVar5 = (long *)(**(code **)(*param_1 + 0x378))(*param_1 + 0x378,param_1);
    (**(code **)(*plVar5 + 0xa8))(plVar5,param_1[0xab]);
    (**(code **)(*(long *)param_1[0xab] + 0x28))();
    param_1[0xab] = 0;
  }
  if ((long *)param_1[0x6f] != (long *)0x0) {
    *(undefined1 *)(param_1 + 0x70) = 0;
    (**(code **)(*(long *)param_1[0x6f] + 0xb8))();
    plVar5 = (long *)(**(code **)(*param_1 + 0x378))(*param_1 + 0x378,param_1);
    (**(code **)(*plVar5 + 0xa8))(plVar5,param_1[0x6f]);
    (**(code **)(*(long *)param_1[0x6f] + 0x28))();
    param_1[0x6f] = 0;
  }
  if ((long *)param_1[0xa3] != (long *)0x0) {
    *(undefined1 *)(param_1 + 0xa4) = 0;
    (**(code **)(*(long *)param_1[0xa3] + 0xb8))();
    (**(code **)(*(long *)param_1[0x97] + 0xa8))((long *)param_1[0x97],param_1[0xa3]);
    (**(code **)(*(long *)param_1[0xa3] + 0x28))();
    param_1[0xa3] = 0;
  }
  if ((long *)param_1[0xa5] != (long *)0x0) {
    *(undefined1 *)(param_1 + 0xa6) = 0;
    (**(code **)(*(long *)param_1[0xa5] + 0xb8))();
    (**(code **)(*(long *)param_1[0x97] + 0xa8))((long *)param_1[0x97],param_1[0xa5]);
    (**(code **)(*(long *)param_1[0xa5] + 0x28))();
    param_1[0xa5] = 0;
  }
  if ((long *)param_1[0xa7] != (long *)0x0) {
    *(undefined1 *)(param_1 + 0xa8) = 0;
    (**(code **)(*(long *)param_1[0xa7] + 0xb8))();
    (**(code **)(*(long *)param_1[0x97] + 0xa8))((long *)param_1[0x97],param_1[0xa7]);
    (**(code **)(*(long *)param_1[0xa7] + 0x28))();
    param_1[0xa7] = 0;
  }
  if ((long *)param_1[0x98] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x98] + 0xb8))();
    (**(code **)(*(long *)param_1[0x97] + 0xa8))((long *)param_1[0x97],param_1[0x98]);
    (**(code **)(*(long *)param_1[0x98] + 0x28))();
    param_1[0x98] = 0;
  }
  if ((param_1[0x99] != 0) && ((long *)param_1[0x73] != (long *)0x0)) {
    (**(code **)(*(long *)param_1[0x73] + 0xb8))();
    (**(code **)(*(long *)param_1[0x99] + 0xa8))((long *)param_1[0x99],param_1[0x73]);
    (**(code **)(*(long *)param_1[0x73] + 0x28))();
    param_1[0x73] = 0;
  }
  plVar5 = (long *)param_1[0x3037];
  if (plVar5 != (long *)0x0) {
    plVar11 = (long *)param_1[0x3038];
    if (plVar11 == (long *)0x0) {
LAB_fffffff008172d0c:
      (**(code **)(*plVar5 + 0x28))();
    }
    else {
      (**(code **)(*plVar11 + 0xb8))(plVar11);
      (**(code **)(*(long *)param_1[0x3037] + 0xa8))((long *)param_1[0x3037],param_1[0x3038]);
      if ((long *)param_1[0x3038] != (long *)0x0) {
        (**(code **)(*(long *)param_1[0x3038] + 0x28))();
      }
      param_1[0x3038] = 0;
      plVar5 = (long *)param_1[0x3037];
      if (plVar5 != (long *)0x0) goto LAB_fffffff008172d0c;
    }
    param_1[0x3037] = 0;
  }
  plVar5 = (long *)*plVar4;
  if (plVar5 != (long *)0x0) {
    plVar11 = (long *)param_1[0x2ff8];
    if (plVar11 == (long *)0x0) {
LAB_fffffff008172dac:
      (**(code **)(*plVar5 + 0x28))();
    }
    else {
      (**(code **)(*plVar11 + 0xb8))(plVar11);
      (**(code **)(*(long *)*plVar4 + 0xa8))((long *)*plVar4,param_1[0x2ff8]);
      if ((long *)param_1[0x2ff8] != (long *)0x0) {
        (**(code **)(*(long *)param_1[0x2ff8] + 0x28))();
      }
      param_1[0x2ff8] = 0;
      plVar5 = (long *)*plVar4;
      if (plVar5 != (long *)0x0) goto LAB_fffffff008172dac;
    }
    *plVar4 = 0;
  }
  cVar6 = *(char *)((long)param_1 + 0x646);
  if ('\0' < cVar6) {
    lVar13 = 0;
    do {
      if ((long *)param_1[lVar13 + 0x9a] != (long *)0x0) {
        (**(code **)(*(long *)param_1[lVar13 + 0x9a] + 0xb8))();
        (**(code **)(*(long *)param_1[0x97] + 0xa8))((long *)param_1[0x97],param_1[lVar13 + 0x9a]);
        (**(code **)(*(long *)param_1[lVar13 + 0x9a] + 0x28))();
        param_1[lVar13 + 0x9a] = 0;
        cVar6 = *(char *)((long)param_1 + 0x646);
      }
      lVar13 = lVar13 + 1;
    } while (lVar13 < cVar6);
  }
  if (((long *)param_1[0xae] != (long *)0x0) && (param_1[0xad] != 0)) {
    (**(code **)(*(long *)param_1[0xae] + 0xb8))();
    (**(code **)(*(long *)param_1[0xad] + 0xa8))((long *)param_1[0xad],param_1[0xae]);
    (**(code **)(*(long *)param_1[0xae] + 0x28))();
    param_1[0xae] = 0;
  }
  if ((long *)param_1[0x62] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x62] + 0xb8))();
    (**(code **)(*(long *)param_1[0x97] + 0xa8))((long *)param_1[0x97],param_1[0x62]);
    (**(code **)(*(long *)param_1[0x62] + 0x28))();
    param_1[0x62] = 0;
  }
  if ((long *)param_1[99] != (long *)0x0) {
    (**(code **)(*(long *)param_1[99] + 0xb8))();
    (**(code **)(*(long *)param_1[0xad] + 0xa8))((long *)param_1[0xad],param_1[99]);
    if ((long *)param_1[99] != (long *)0x0) {
      (**(code **)(*(long *)param_1[99] + 0x28))();
    }
    param_1[99] = 0;
  }
  if ((long *)param_1[0x99] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x99] + 0x28))();
    param_1[0x99] = 0;
  }
  if ((long *)param_1[0xad] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0xad] + 0x28))();
    param_1[0xad] = 0;
  }
  if ((long *)param_1[0x97] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x97] + 0x28))();
    param_1[0x97] = 0;
  }
  if (param_1[0x23c9] != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  uVar8 = *(uint *)(param_1 + 0x23da);
  uVar9 = (ulong)uVar8;
  while (uVar8 != 0) {
    uVar8 = (int)uVar9 - 1;
    uVar9 = (ulong)uVar8;
    *(uint *)(param_1 + 0x23da) = uVar8;
    iVar7 = (int)(uVar9 * 8);
    plVar4 = (long *)((long)param_1 + (long)iVar7 + 0x11e50);
    if (uVar9 * 8 != (long)iVar7) {
      plVar4 = (long *)((ulong)(param_1 + uVar9 + 0x23ca) & 0xffffffffffff | 0x2bad000000000000);
    }
    if ((long *)*plVar4 != (long *)0x0) {
      (**(code **)(*(long *)*plVar4 + 0x28))();
      uVar9 = (ulong)*(uint *)(param_1 + 0x23da);
    }
    uVar8 = (uint)uVar9;
  }
  if ((long *)param_1[0x96] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x96] + 0x28))();
    param_1[0x96] = 0;
  }
  lVar13 = param_1[0x3075];
  if (lVar13 == 0) {
    if ((int)param_1[0x94] != 0) goto LAB_fffffff00817313c;
  }
  else {
    if ((int)param_1[0x94] == 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar13 + 0x40));
      if (0 < *(long *)(lVar13 + 0x38)) {
        if (*(long *)(lVar13 + 0x50) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        if (*(long *)(lVar13 + 0x58) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        *(long *)(lVar13 + 0x38) = *(long *)(lVar13 + 0x38) + -1;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar13 + 0x40));
      (**(code **)(*(long *)param_1[0x3075] + 0x28))();
    }
LAB_fffffff00817313c:
    param_1[0x3075] = 0;
  }
  lVar13 = param_1[0x3076];
  if (lVar13 == 0) {
    if (*(int *)((long)param_1 + 0x4a4) != 0) goto LAB_fffffff0081731b8;
  }
  else {
    if (*(int *)((long)param_1 + 0x4a4) == 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar13 + 0x40));
      if (0 < *(long *)(lVar13 + 0x38)) {
        if (*(long *)(lVar13 + 0x50) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        if (*(long *)(lVar13 + 0x58) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        *(long *)(lVar13 + 0x38) = *(long *)(lVar13 + 0x38) + -1;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar13 + 0x40));
      (**(code **)(*(long *)param_1[0x3076] + 0x28))();
    }
LAB_fffffff0081731b8:
    param_1[0x3076] = 0;
  }
  lVar13 = param_1[0x3077];
  if (lVar13 == 0) {
    if ((int)param_1[0x95] != 0) goto LAB_fffffff008173234;
  }
  else {
    if ((int)param_1[0x95] == 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar13 + 0x40));
      if (0 < *(long *)(lVar13 + 0x38)) {
        if (*(long *)(lVar13 + 0x50) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        if (*(long *)(lVar13 + 0x58) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        *(long *)(lVar13 + 0x38) = *(long *)(lVar13 + 0x38) + -1;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar13 + 0x40));
      (**(code **)(*(long *)param_1[0x3077] + 0x28))();
    }
LAB_fffffff008173234:
    param_1[0x3077] = 0;
  }
  lVar13 = param_1[0x3078];
  if (lVar13 == 0) {
    if (*(int *)((long)param_1 + 0x4ac) == 0) goto LAB_fffffff0081732b4;
  }
  else if (*(int *)((long)param_1 + 0x4ac) == 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar13 + 0x40));
    if (0 < *(long *)(lVar13 + 0x38)) {
      if (*(long *)(lVar13 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar13 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar13 + 0x38) = *(long *)(lVar13 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar13 + 0x40));
    (**(code **)(*(long *)param_1[0x3078] + 0x28))();
  }
  param_1[0x3078] = 0;
LAB_fffffff0081732b4:
  (**(code **)(*param_1 + 0x488))(param_1);
  if (param_1[0x23c6] != 0) {
    thunk_EXT_FUN_80110000038fe6b0(param_1[0x23c6],(long)(int)param_1[0x23c1] << 2);
    param_1[0x23c6] = 0;
  }
  if (param_1[0x23c5] != 0) {
    thunk_EXT_FUN_80110000038fe6b0(param_1[0x23c5],(long)(int)param_1[0x23c0] << 2);
    param_1[0x23c5] = 0;
  }
  lVar13 = param_1[0x23c4];
  if (lVar13 != 0) {
    lVar14 = (long)(int)*(uint *)(param_1 + 0x23c0) << 3;
    if (0x7fffffff < *(uint *)(param_1 + 0x23c0)) {
      lVar14 = -0x8000000000000000;
    }
    param_1[0x23c4] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3478,lVar13,lVar14);
    param_1[0x23c4] = 0;
  }
  if (param_1[0x23c3] != 0) {
    thunk_EXT_FUN_80110000038fe6b0(param_1[0x23c3],(long)(int)param_1[0x23c0] << 3);
    param_1[0x23c3] = 0;
  }
  lVar13 = param_1[0x23c2];
  if (lVar13 != 0) {
    uVar9 = thunk_EXT_FUN_8011000002946bb0(*(undefined8 *)(param_1[0x23be] + 0x148));
    thunk_EXT_FUN_80110000038fe6b0
              (lVar13,-(uVar9 >> 0x1f & 1) & 0xfffffffc00000000 | (uVar9 & 0xffffffff) << 2);
    param_1[0x23c2] = 0;
  }
  if (param_1[0x23bf] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x23bf] = 0;
  }
  if (param_1[0x23bb] != 0) {
    thunk_EXT_FUN_80110000038fe6b0(param_1[0x23bb],(long)(int)param_1[0x23b7] << 2);
    param_1[0x23bb] = 0;
  }
  if (param_1[0x23ba] != 0) {
    thunk_EXT_FUN_80110000038fe6b0(param_1[0x23ba],(int)param_1[0x23b7] + 0x3fU >> 3 & 0x1ffffff8);
    param_1[0x23ba] = 0;
  }
  if (param_1[0x23b9] != 0) {
    thunk_EXT_FUN_80110000038fe6b0(param_1[0x23b9],(long)(int)param_1[0x23b7] << 2);
    param_1[0x23b9] = 0;
  }
  lVar13 = param_1[0x23b8];
  if (lVar13 != 0) {
    lVar14 = (long)(int)*(uint *)(param_1 + 0x23b7) << 3;
    if (0x7fffffff < *(uint *)(param_1 + 0x23b7)) {
      lVar14 = -0x8000000000000000;
    }
    param_1[0x23b8] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4198,lVar13,lVar14);
    param_1[0x23b8] = 0;
  }
  if (param_1[0x23b6] != 0) {
    thunk_EXT_FUN_80110000038ff1d4();
  }
  if (param_1[0x3074] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x3074] = 0;
  }
  if (*(int *)((long)param_1 + 0x10934) != 0) {
    lVar13 = param_1[0x23e8];
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar13 + 0x40));
    if (0 < *(long *)(lVar13 + 0x38)) {
      if (*(long *)(lVar13 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar13 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar13 + 0x38) = *(long *)(lVar13 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar13 + 0x40));
    *(int *)(param_1 + 0x23ea) = (int)param_1[0x23ea] + -1;
    FUN_fffffff0081e0190(param_1 + 0x23dd);
  }
  if ((long *)param_1[0x2236] != (long *)0x0) {
    *(undefined1 *)(param_1 + 0x2238) = 0;
    (**(code **)(*(long *)param_1[0x2236] + 0x28))();
    param_1[0x2236] = 0;
  }
  if (param_1[0x2237] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x2237] = 0;
  }
  if (param_1[0x2239] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x2239] = 0;
  }
  param_1[0x223a] = 0;
  param_1[0x223c] = DAT_fffffff007113e90;
  if (param_1[100] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[100] = 0;
  }
  if (param_1[0x6b] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x6b] = 0;
  }
  if (param_1[0x72] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x72] = 0;
  }
  if (param_1[0x6e] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x6e] = 0;
  }
  if ((long *)param_1[0x6a] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x6a] + 0x28))();
  }
  param_1[0x6a] = 0;
  (**(code **)(PTR_DAT_fffffff007ca6170 + 0x2c8))(param_1,param_2);
  (**(code **)(*(long *)param_1[0x313a] + 0x70))();
  if ((long *)param_1[0x358c] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x358c] + 0x28))();
  }
  param_1[0x358c] = 0;
  (**(code **)(*param_1 + 0x38))(param_1);
  thunk_EXT_FUN_8011000003891b28();
  if (param_1[0x234e] != 0) {
    thunk_EXT_FUN_80110000038ff474();
    param_1[0x234e] = 0;
  }
  if (param_1[0x234f] != 0) {
    thunk_EXT_FUN_80110000038ff474();
    param_1[0x234f] = 0;
  }
  if (param_1[0x23b1] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x23b1] = 0;
  }
  if (param_1[0x358e] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x358e] = 0;
  }
  if (param_1[0x234c] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x234c] = 0;
  }
  if (param_1[0x3589] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x3589] = 0;
  }
  if ((long *)param_1[0x23b3] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x23b3] + 0x28))();
  }
  param_1[0x23b3] = 0;
  FUN_fffffff0081e8ac4();
  if ((long *)param_1[0x223d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x223d] + 0x28))();
  }
  param_1[0x223d] = 0;
  if ((long *)param_1[0x8a] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x8a] + 0x28))();
  }
  param_1[0x8a] = 0;
  if ((param_1[0x3591] != 0) && ((long *)param_1[0x3592] != (long *)0x0)) {
    (**(code **)(*(long *)param_1[0x3592] + 0xb8))();
    (**(code **)(*(long *)param_1[0x3591] + 0xa8))((long *)param_1[0x3591],param_1[0x3592]);
  }
  if ((long *)param_1[0x3592] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3592] + 0x28))();
  }
  param_1[0x3592] = 0;
  if ((long *)param_1[0x3590] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3590] + 0x28))();
  }
  param_1[0x3590] = 0;
  if ((long *)param_1[0x3591] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3591] + 0x28))();
  }
  param_1[0x3591] = 0;
  if ((long *)param_1[0x3596] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3596] + 0x28))();
  }
  param_1[0x3596] = 0;
  thunk_EXT_FUN_8011000003740d38(&DAT_fffffff00ae20720);
  thunk_EXT_FUN_8011000003740d38(&DAT_fffffff00ae206d0);
  return;
}

