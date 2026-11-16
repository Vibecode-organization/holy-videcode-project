// FUN_fffffff0094c264c @ fffffff0094c264c size=840
// CALLERS:
//   fffffff00afb8051 ?
//   fffffff0094beea0 FUN_fffffff0094bee68@fffffff0094bee68
//   fffffff0094bef14 FUN_fffffff0094beeb4@fffffff0094beeb4
//   fffffff0094bf05c FUN_fffffff0094bf004@fffffff0094bf004
//   fffffff0094bf1a4 FUN_fffffff0094bf14c@fffffff0094bf14c
//   fffffff0094bf244 FUN_fffffff0094bf1ec@fffffff0094bf1ec
//   fffffff0094bf2e0 FUN_fffffff0094bf28c@fffffff0094bf28c
//   fffffff0094c2c4c FUN_fffffff0094c2bd8@fffffff0094c2bd8
//   fffffff0094c2c8c FUN_fffffff0094c2bd8@fffffff0094c2bd8
//   fffffff0094c2e9c FUN_fffffff0094c2e68@fffffff0094c2e68
//   fffffff0094bf104 FUN_fffffff0094bf0a4@fffffff0094bf0a4
//   fffffff0094c29cc FUN_fffffff0094c2998@fffffff0094c2998
//   fffffff0094c7bd8 FUN_fffffff0094c7a20@fffffff0094c7a20
// CALLS:
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c35f4 FUN_fffffff0094c35f4
//   fffffff0094c6df8 FUN_fffffff0094c6df8
//   fffffff0094c99d4 thunk_EXT_FUN_8011000003a61cc0
//   fffffff0094c8058 FUN_fffffff0094c8058
//   fffffff0094c828c FUN_fffffff0094c828c
//   fffffff0094c82cc FUN_fffffff0094c82cc
//   fffffff0094c8638 FUN_fffffff0094c8638

void FUN_fffffff0094c264c
               (ulong param_1,ulong param_2,undefined1 param_3,uint param_4,long param_5,
               long param_6,long param_7,long param_8,long *param_9,long *param_10,
               undefined8 *param_11)

{
  long lVar1;
  byte bVar2;
  code *pcVar3;
  undefined8 uVar4;
  long *plVar5;
  undefined4 uVar6;
  long *plVar7;
  undefined8 local_5b0;
  undefined8 uStack_5a8;
  byte local_5a0;
  undefined1 local_59f;
  byte local_59e;
  byte local_59d;
  byte local_59c;
  undefined2 local_59b;
  undefined1 local_599;
  long *local_598;
  undefined1 *local_590;
  undefined1 *local_588;
  undefined8 uStack_580;
  long local_570;
  long lStack_568;
  ulong local_560;
  ulong local_558;
  undefined1 *puStack_550;
  long *local_548;
  long **local_540;
  long *local_538;
  undefined1 *puStack_530;
  long local_528 [5];
  undefined8 local_500;
  undefined8 uStack_4f8;
  undefined8 local_4f0;
  undefined8 uStack_4e8;
  undefined8 local_4e0;
  undefined8 uStack_4d8;
  undefined8 local_4d0;
  undefined8 uStack_4c8;
  undefined8 local_4c0;
  undefined8 uStack_4b8;
  undefined8 local_4b0;
  undefined8 uStack_4a8;
  undefined8 local_4a0;
  undefined8 uStack_498;
  undefined8 local_490;
  undefined8 uStack_488;
  undefined8 local_480;
  undefined8 uStack_478;
  undefined8 local_470;
  undefined8 uStack_468;
  undefined8 local_458;
  undefined8 uStack_450;
  undefined8 uStack_448;
  undefined8 uStack_440;
  undefined8 local_430;
  undefined8 uStack_428;
  byte local_41f;
  long local_418;
  undefined8 uStack_410;
  long *local_408;
  long **local_400;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff007f5bb60;
  local_528[1] = 0;
  local_528[0] = 0;
  local_528[3] = 0;
  local_528[2] = 0;
  uStack_4f8 = 0;
  local_500 = 0;
  uStack_4e8 = 0;
  local_4f0 = 0;
  uStack_4d8 = 0;
  local_4e0 = 0;
  uStack_4c8 = 0;
  local_4d0 = 0;
  uStack_4b8 = 0;
  local_4c0 = 0;
  uStack_4a8 = 0;
  local_4b0 = 0;
  uStack_498 = 0;
  local_4a0 = 0;
  uStack_488 = 0;
  local_490 = 0;
  uStack_478 = 0;
  local_480 = 0;
  uStack_468 = 0;
  local_470 = 0;
  uStack_450 = 0;
  local_458 = 0;
  uStack_440 = 0;
  uStack_448 = 0;
  uStack_428 = 0;
  local_430 = 0;
  local_418 = 0;
  uStack_410 = 0;
  thunk_EXT_FUN_8011000003a61cc0(local_528,0x4c0);
  if (CARRY8(param_1,param_2)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c2990);
    (*pcVar3)();
  }
  if (param_1 + param_2 < param_1) goto LAB_fffffff0094c2988;
  local_538 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  puStack_530 = &DAT_aaaaaaaaaaaaaaaa;
  local_548 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  local_540 = (long **)&DAT_aaaaaaaaaaaaaaaa;
  puStack_550 = &DAT_aaaaaaaaaaaaaaaa;
  local_560 = param_1;
  local_558 = param_1 + param_2;
  uVar4 = FUN_fffffff0094c8058(&local_560,local_528,4,&local_538,&puStack_550);
  if ((int)uVar4 != 0) goto LAB_fffffff0094c28e8;
  if (local_560 != local_558) {
    uVar4 = 0x5000a;
    goto LAB_fffffff0094c28e8;
  }
  if (((param_4 & 1) == 0) && (local_418 == 0)) {
    FUN_fffffff0094c828c(&local_548,&local_538);
    if (local_548 == (long *)0x0) {
      local_408 = (long *)0x0;
      local_540 = &local_408;
    }
    else {
      if ((long **)local_548[0x25] != &local_548) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0094c2988);
        (*pcVar3)();
      }
      local_408 = local_548;
      local_548[0x25] = (long)&local_408;
    }
    local_548 = local_528;
    local_400 = &local_548;
  }
  else {
    if ((local_41f & 1) == 0) {
      plVar7 = &local_68;
      plVar5 = local_528;
LAB_fffffff0094c27f8:
      if ((plVar7 < plVar5 + 0x26) || (plVar5 + 0x26 < plVar5)) goto LAB_fffffff0094c2988;
    }
    else {
      plVar5 = local_538;
      if (local_538 != (long *)0x0) {
        do {
          if ((*(byte *)((long)plVar5 + 0x109) & 1) == 0) {
            plVar7 = plVar5 + 0x26;
            if (plVar5 <= plVar7) goto LAB_fffffff0094c27f8;
            goto LAB_fffffff0094c2988;
          }
          plVar7 = plVar5 + 0x22;
          plVar5 = (long *)*plVar7;
        } while ((long *)*plVar7 != (long *)0x0);
        plVar7 = local_538 + 0x26;
        plVar5 = local_538;
        goto LAB_fffffff0094c27f8;
      }
      plVar5 = (long *)0x0;
    }
    uVar4 = FUN_fffffff0094c82cc(plVar5,&local_538,&local_548,param_4 ^ 1);
    if ((int)uVar4 != 0) goto LAB_fffffff0094c28e8;
  }
  local_590 = &DAT_aaaaaaaaaaaaaaaa;
  local_588 = &DAT_aaaaaaaaaaaaaaaa;
  local_598 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  uStack_5a8 = param_11[1];
  local_5b0 = *param_11;
  local_5a0 = *(byte *)(param_11 + 2) & 1;
  if (param_7 != 0 && param_8 != 0) {
    param_3 = 1;
  }
  local_59e = *(byte *)((long)param_11 + 0x12) & 1;
  local_59d = *(byte *)((long)param_11 + 0x13) & 1;
  bVar2 = *(byte *)((long)param_11 + 0x14);
  local_59c = bVar2 & 1;
  local_59b = 0;
  local_599 = 0;
  local_59f = param_3;
  local_570 = param_7;
  lStack_568 = param_8;
  if (param_7 == 0 || param_8 == 0) {
    plVar7 = (long *)param_11[3];
    if (plVar7 + 2 < plVar7) goto LAB_fffffff0094c2988;
    local_590 = (undefined1 *)param_11[4];
    local_588 = (undefined1 *)param_11[5];
    local_598 = plVar7;
  }
  else {
    local_598 = &local_570;
    local_590 = (undefined1 *)param_11[4];
    local_588 = (undefined1 *)FUN_fffffff0094c35f4(param_8);
  }
  uStack_580 = param_11[6];
  uVar6 = 7;
  if ((bVar2 & 1) == 0) {
    uVar6 = 4;
  }
  uVar4 = FUN_fffffff0094c8638(0xc,uVar6,&local_548,&local_5b0,0);
  plVar7 = local_548;
  if ((int)uVar4 == 0) {
    if (((param_5 != 0) && (param_6 != 0)) && (local_548 != (long *)0x0)) {
      if (local_548 + 0x26 < local_548) {
LAB_fffffff0094c2988:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c298c);
        (*pcVar3)();
      }
      uVar4 = FUN_fffffff0094c6df8(local_548,param_5,param_6);
      if ((int)uVar4 != 0) goto LAB_fffffff0094c28e8;
    }
    if ((param_10 != (long *)0x0) && (plVar7 != (long *)0x0)) {
      lVar1 = plVar7[0x20];
      *param_10 = plVar7[0x1f];
      param_10[1] = lVar1;
    }
    uVar4 = 0;
    if ((param_9 != (long *)0x0) && (plVar7 != (long *)0x0)) {
      uVar4 = 0;
      *param_9 = plVar7[0x1e];
    }
  }
LAB_fffffff0094c28e8:
  if (*(long *)PTR_DAT_fffffff007f5bb60 == local_68) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar4);
  return;
}

