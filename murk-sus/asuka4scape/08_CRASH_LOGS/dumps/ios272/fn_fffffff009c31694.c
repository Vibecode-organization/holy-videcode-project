// FUN_fffffff009c31694 @ fffffff009c31694 size=2340

/* WARNING: Removing unreachable block (ram,0xfffffff009c31f88) */

undefined8 FUN_fffffff009c31694(long *param_1)

{
  uint *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  char *pcVar11;
  uint uVar12;
  undefined4 uVar13;
  byte *local_b0;
  long *plStack_a8;
  byte local_99;
  undefined8 local_98;
  ulong local_90;
  undefined1 *local_88;
  undefined4 local_7c;
  undefined8 local_78;
  undefined1 *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar5 = (**(code **)(PTR_DAT_fffffff00806ca38 + 0x2c0))();
  lVar6 = thunk_EXT_FUN_8011000003397c88();
  param_1[0x89] = lVar6;
  lVar6 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x28] = lVar6;
  if (lVar6 == 0) goto LAB_fffffff009c31d88;
  lVar6 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x29] = lVar6;
  if (lVar6 == 0) goto LAB_fffffff009c31d88;
  param_1[0x12] = 0;
  param_1[0x13] = (long)(param_1 + 0x12);
  param_1[0x31] = 0;
  param_1[0x32] = (long)(param_1 + 0x31);
  param_1[0x73] = 0;
  param_1[0x74] = (long)(param_1 + 0x73);
  lVar6 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x75] = lVar6;
  if (lVar6 == 0) goto LAB_fffffff009c31d88;
  lVar6 = thunk_EXT_FUN_801100000389d0d8(1);
  if ((long *)param_1[0x2b] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x2b] + 0x28))();
  }
  param_1[0x2b] = lVar6;
  if (lVar6 == 0) goto LAB_fffffff009c31d88;
  param_1[0x7b] = 0;
  param_1[0x7c] = (long)(param_1 + 0x7b);
  lVar6 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x76] = lVar6;
  if (lVar6 == 0) goto LAB_fffffff009c31d88;
  lVar6 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x77] = lVar6;
  if (lVar6 == 0) goto LAB_fffffff009c31d88;
  lVar6 = thunk_EXT_FUN_80110000039589e4();
  if ((long *)param_1[0x91] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x91] + 0x28))();
  }
  param_1[0x91] = lVar6;
  lVar6 = thunk_EXT_FUN_801100000395abd8(param_1,FUN_fffffff009c31fb8,0,0);
  if ((long *)param_1[0x92] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x92] + 0x28))();
  }
  param_1[0x92] = lVar6;
  (**(code **)(*(long *)param_1[0x91] + 0xa0))((long *)param_1[0x91],lVar6);
  (**(code **)(*(long *)param_1[0x92] + 0xb0))();
  *(undefined1 *)(param_1 + 0x11) = 1;
  lVar6 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x3e] = lVar6;
  if (lVar6 == 0) goto LAB_fffffff009c31d88;
  lVar6 = thunk_EXT_FUN_80110000038961f4(1);
  if ((long *)param_1[0x3f] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3f] + 0x28))();
  }
  param_1[0x3f] = lVar6;
  lVar6 = thunk_EXT_FUN_8011000003277094(FUN_fffffff009c32010,param_1,1);
  param_1[0x40] = lVar6;
  if (lVar6 == 0) goto LAB_fffffff009c31d88;
  local_78 = 8;
  local_70 = &DAT_aaaaaaaaaaaaaaaa;
  iVar3 = thunk_EXT_FUN_8011000003742368("hw.cachelinesize",&local_70,&local_78,0,0);
  if (iVar3 == 0) {
    if (local_70 == (undefined1 *)0x0) {
      local_70 = (undefined1 *)0x80;
    }
    *(int *)(param_1 + 0x15) = (int)local_70;
    iVar3 = (int)local_70 + -1;
  }
  else {
    *(undefined4 *)(param_1 + 0x15) = 0x20;
    iVar3 = 0x1f;
  }
  *(int *)((long)param_1 + 0xac) = iVar3;
  *(int *)(param_1 + 0x16) = iVar3;
  param_1[0x18] = 0x7fffffff;
  param_1[0x17] = 0x7fffffff;
  param_1[0x19] = 0x7fffffff;
  param_1[0x1c] = 0;
  FUN_fffffff009c32250(param_1);
  param_1[0x27] = 0;
  local_7c = 0xaaaaaaaa;
  local_88 = &DAT_aaaaaaaaaaaaaaaa;
  uVar7 = FUN_fffffff009c32528(param_1,0,&local_7c,&local_88);
  if ((uVar7 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,
               "IOSurfaceRoot: Initial shared event memory alloc failed\n");
  }
  local_98 = 8;
  local_90 = 0;
  iVar3 = thunk_EXT_FUN_8011000003742368("hw.memsize",&local_90,&local_98,0,0);
  uVar7 = local_90;
  if (local_90 >> 0x23 == 0) {
    uVar7 = local_90 >> 2;
  }
  if (iVar3 != 0) {
    uVar7 = 0x10000000;
  }
  param_1[0x33] = uVar7;
  *(undefined1 *)((long)param_1 + 0x89) = 1;
  lVar6 = thunk_EXT_FUN_8011000003397c88();
  param_1[0x8a] = lVar6;
  puVar2 = PTR_DAT_fffffff00806ca50;
  plVar8 = (long *)thunk_EXT_FUN_8011000003906044("/",*(undefined8 *)PTR_DAT_fffffff00806ca50,0,0,0)
  ;
  iVar3 = thunk_EXT_FUN_801100000390e80c(plVar8,"non-coherent",*(undefined8 *)puVar2,1);
  if (iVar3 != 0) {
    *(undefined1 *)((long)param_1 + 0x89) = 0;
    (**(code **)(*param_1 + 0xd8))(param_1,"iosurface-non-coherent",1);
  }
  param_1[0x2d] = 0;
  *(undefined4 *)(param_1 + 0x2e) = 0;
  local_99 = 0;
  *(undefined1 *)(param_1 + 0x93) = 0;
  iVar3 = thunk_EXT_FUN_801100000390e80c
                    (plVar8,"display-carveout-inhibitcache",*(undefined8 *)puVar2,1);
  if (iVar3 != 0) {
    local_99 = 1;
  }
  iVar3 = thunk_EXT_FUN_801100000390e80c
                    (plVar8,"display-carveout-restricted",*(undefined8 *)puVar2,1);
  if (iVar3 != 0) {
    *(undefined1 *)(param_1 + 0x93) = 1;
  }
  local_b0 = &local_99;
  plStack_a8 = param_1;
  plVar9 = (long *)thunk_EXT_FUN_8011000003906044("/vram",*(undefined8 *)puVar2,0,0,0);
  if (plVar9 != (long *)0x0) {
    iVar3 = FUN_fffffff009c325b0(plVar9);
    *(int *)(param_1 + 0x2e) = iVar3;
    if (iVar3 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface: couldn\'t count /vram\'s reg tuples; assuming a single carveout\n");
      iVar3 = 1;
    }
    iVar4 = thunk_EXT_FUN_8011000003a12d84(0);
    if (iVar4 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0,
                 "IOSurface: discovered %u display carveout(s) in /vram\n");
    }
    iVar4 = 0;
    do {
      plVar10 = (long *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff00806b530);
      if (plVar10 != (long *)0x0) {
        uVar13 = 0x100;
        if ((local_99 & 1) == 0) {
          uVar13 = 0x400;
        }
        *(undefined4 *)(plVar10 + 2) = uVar13;
        *(int *)((long)plVar10 + 0x14) = iVar4;
        *(int *)(param_1 + 0x2d) = (int)param_1[0x2d] + 1;
        *plVar10 = param_1[0x2c];
        plVar10[1] = (long)"vram";
        param_1[0x2c] = (long)plVar10;
      }
      iVar4 = iVar4 + 1;
    } while (iVar3 != iVar4);
  }
  plVar10 = (long *)thunk_EXT_FUN_8011000003906044("/sma",*(undefined8 *)puVar2,0,0,0);
  if (plVar10 != (long *)0x0) {
    (**(code **)(*plVar10 + 0x28))();
    FUN_fffffff009c32718(&local_b0,"sma",0);
  }
  param_1[0x2f] = (long)FUN_fffffff009c32794;
  lVar6 = thunk_EXT_FUN_801100000327729c(FUN_fffffff009c32794,param_1);
  param_1[0x30] = lVar6;
  thunk_EXT_FUN_8011000003277760();
  lVar6 = thunk_EXT_FUN_8011000003397c88();
  param_1[0x8b] = lVar6;
  param_1[0x3a] = 0;
  param_1[0x3b] = (long)(param_1 + 0x3a);
  lVar6 = thunk_EXT_FUN_80110000039589e4();
  if ((long *)param_1[0x36] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x36] + 0x28))();
  }
  param_1[0x36] = lVar6;
  if (lVar6 == 0) {
LAB_fffffff009c31d3c:
    uVar5 = 0;
  }
  else {
    lVar6 = thunk_EXT_FUN_801100000395c074(param_1,0);
    if ((long *)param_1[0x37] != (long *)0x0) {
      (**(code **)(*(long *)param_1[0x37] + 0x28))();
    }
    param_1[0x37] = lVar6;
    if (lVar6 == 0) goto LAB_fffffff009c31d3c;
    lVar6 = thunk_EXT_FUN_80110000038ff010();
    param_1[0x39] = lVar6;
    if (lVar6 == 0) goto LAB_fffffff009c31d3c;
    lVar6 = thunk_EXT_FUN_801100000395abd8(param_1,FUN_fffffff009c32a28,0,0);
    if ((long *)param_1[0x38] != (long *)0x0) {
      (**(code **)(*(long *)param_1[0x38] + 0x28))();
    }
    param_1[0x38] = lVar6;
    if (((lVar6 == 0) ||
        (iVar3 = (**(code **)(*(long *)param_1[0x36] + 0xa0))((long *)param_1[0x36],lVar6),
        iVar3 != 0)) ||
       (iVar3 = (**(code **)(*(long *)param_1[0x36] + 0xa0))((long *)param_1[0x36],param_1[0x37]),
       iVar3 != 0)) goto LAB_fffffff009c31d3c;
    (**(code **)(*(long *)param_1[0x38] + 0xb0))();
    (**(code **)(*(long *)param_1[0x37] + 0xb0))();
    lVar6 = thunk_EXT_FUN_8011000003397c88();
    param_1[0x8c] = lVar6;
    *(undefined1 *)(param_1 + 0x34) = 0;
    iVar3 = thunk_EXT_FUN_8011000003a10b0c("iosurface_timestamp_enable",param_1 + 0x34,1);
    if (iVar3 == 0) {
      *(undefined1 *)(param_1 + 0x34) = 0;
    }
    puVar1 = (uint *)(param_1 + 0x72);
    iVar3 = thunk_EXT_FUN_8011000003a10b0c("iofence_ddd",puVar1,4);
    if ((iVar3 != 0) && (0x10 < *puVar1)) {
      *puVar1 = 0x10;
    }
    puVar1 = (uint *)((long)param_1 + 0x1a4);
    iVar3 = thunk_EXT_FUN_8011000003a10b0c("iosurface_debug",puVar1,4);
    if (iVar3 == 0) {
      *puVar1 = 0x10;
LAB_fffffff009c31eb0:
      pcVar11 = "IOSurface disallowing global lookups\n";
    }
    else {
      uVar12 = *puVar1;
      if ((uVar12 >> 1 & 1) != 0) {
        thunk_EXT_FUN_8011000003a132c0("IOSurface disallowing pixel size casting by default\n");
        uVar12 = *puVar1;
      }
      if ((uVar12 >> 2 & 1) == 0) goto LAB_fffffff009c31eb0;
      pcVar11 = "IOSurface allowing global lookups (with warnings)\n";
    }
    thunk_EXT_FUN_8011000003a132c0(pcVar11);
    if ((*(byte *)puVar1 >> 3 & 1) != 0) {
      *(uint *)(param_1 + 0x35) = *(uint *)(param_1 + 0x35) | 0x20;
      thunk_EXT_FUN_8011000003a132c0("IOSurface using pageable shmems\n");
    }
    lVar6 = thunk_EXT_FUN_8011000003397c88();
    param_1[0x8d] = lVar6;
    lVar6 = thunk_EXT_FUN_8011000003962c64
                      (*(uint *)(param_1 + 0x35) | 0x10000,*(undefined8 *)PTR_DAT_fffffff00806ca78,
                       *(undefined8 *)PTR_DAT_fffffff00806ca78);
    if ((long *)param_1[0x3d] != (long *)0x0) {
      (**(code **)(*(long *)param_1[0x3d] + 0x28))();
    }
    param_1[0x3d] = lVar6;
    (**(code **)(*param_1 + 0x210))(param_1,"IOCoreSurfaceRoot",0);
    lVar6 = thunk_EXT_FUN_8011000003397c88();
    param_1[0x8e] = lVar6;
    (**(code **)(*param_1 + 0x2a0))(*param_1 + 0x2a0,param_1,0);
    lVar6 = thunk_EXT_FUN_8011000003397c88();
    param_1[0x8f] = lVar6;
  }
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 0x28))();
  }
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
LAB_fffffff009c31d88:
  lVar6 = thunk_EXT_FUN_8011000003397c88();
  param_1[0x90] = lVar6;
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
    uVar5 = thunk_EXT_FUN_8011000003a48590();
    return uVar5;
  }
  return uVar5;
}

