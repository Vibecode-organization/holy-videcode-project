// FUN_fffffff009c462d8 @ fffffff009c462d8 size=1976
// CALLERS:
//   fffffff00afec202 no-fn
//   fffffff009c4449c FUN_fffffff009c443e0@fffffff009c443e0
//   fffffff009c44550 FUN_fffffff009c443e0@fffffff009c443e0
//   fffffff009c4666c FUN_fffffff009c462d8@fffffff009c462d8
//   fffffff009c466ac FUN_fffffff009c462d8@fffffff009c462d8
//   fffffff009c466c8 FUN_fffffff009c462d8@fffffff009c462d8
// CALLEES:
//   fffffff009c49a54 thunk_FUN_fffffff00a89a1f4
//   fffffff009c42884 FUN_fffffff009c42884
//   fffffff009c49a64 thunk_FUN_fffffff00a89a3f0
//   fffffff009c43270 FUN_fffffff009c43270
//   fffffff009c499a4 thunk_FUN_fffffff00a89ca6c
//   fffffff009c462d8 FUN_fffffff009c462d8
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30

/* WARNING: Removing unreachable block (ram,0xfffffff009c46598) */

uint FUN_fffffff009c462d8
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               uint param_8,ulong param_9,long *param_10,uint param_11)

{
  long lVar1;
  undefined8 *puVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  undefined8 uVar9;
  long *plVar10;
  long lVar11;
  long *plVar12;
  uint uVar13;
  undefined1 extraout_q0 [16];
  undefined1 auVar14 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  if (9 < param_8) {
    uVar13 = 0;
    goto LAB_fffffff009c46a20;
  }
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x40));
  lVar1 = param_7 + 0x48;
  lVar11 = (ulong)param_8 * 8;
  puVar2 = (undefined8 *)(lVar1 + (int)lVar11);
  if (lVar11 != (int)lVar11) {
    puVar2 = (undefined8 *)(lVar1 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar6 = thunk_FUN_fffffff00a89ca6c(*puVar2);
  if (plVar6 == (long *)0x0) {
    plVar12 = (long *)0x0;
    bVar3 = true;
    uVar13 = 0;
  }
  else {
    uVar13 = (uint)param_9 & 0xf00;
    plVar10 = (long *)0x0;
    plVar7 = (long *)0x0;
    while( true ) {
      plVar12 = plVar7;
      plVar7 = (long *)(**(code **)(*plVar6 + 0x88))(plVar6);
      plVar8 = thunk_FUN_fffffff00a894f30(plVar7,-0xff50b7ba8);
      if (plVar8 != (long *)0x0) {
        (**(code **)(*plVar8 + 0x20))(plVar8);
      }
      if (plVar10 != (long *)0x0) {
        (**(code **)(*plVar10 + 0x28))(plVar10);
      }
      if (plVar8 == (long *)0x0) goto LAB_fffffff009c46504;
      uVar5 = *(uint *)((long)plVar8 + 0xc) & 0xf00;
      if (uVar5 == uVar13) break;
      plVar10 = plVar8;
      plVar7 = plVar12;
      if (((*(byte *)(param_7 + 0xa1) & 1) != 0) &&
         (((plVar12 == (long *)0x0 ||
           ((uVar5 != 0x700 && ((*(uint *)((long)plVar12 + 0xc) & 0xf00) == 0x700)))) &&
          ((**(code **)(*plVar8 + 0x20))(plVar8), plVar7 = plVar8, plVar12 != (long *)0x0)))) {
        (**(code **)(*plVar12 + 0x28))(plVar12);
      }
    }
    (**(code **)(*plVar8 + 0x20))(plVar8);
    if (plVar12 != (long *)0x0) {
      (**(code **)(*plVar12 + 0x28))(plVar12);
    }
    (**(code **)(*plVar8 + 0x28))(plVar8);
    plVar12 = plVar8;
LAB_fffffff009c46504:
    param_9 = param_9 & 0xffffffff;
    (**(code **)(*plVar6 + 0x28))(plVar6);
    if (plVar12 == (long *)0x0) {
      uVar13 = 0;
    }
    else {
      lVar11 = (ulong)param_8 * 8;
      puVar2 = (undefined8 *)(lVar1 + (int)lVar11);
      if (lVar11 - (int)lVar11 != 0) {
        puVar2 = (undefined8 *)(lVar1 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      plVar6 = (long *)*puVar2;
      uVar9 = (**(code **)(*plVar6 + 0x128))(plVar6,plVar12,0);
      (**(code **)(*plVar6 + 0x108))(*plVar6 + 0x108,plVar6,uVar9);
      if ((uVar13 == 0x700) && ((*(uint *)((long)plVar12 + 0xc) & 0xf00) != 0x700)) {
        (**(code **)(*plVar12 + 0x28))(plVar12);
        plVar12 = (long *)0x0;
        uVar13 = 0;
        bVar3 = false;
        param_11 = 1;
        goto LAB_fffffff009c46610;
      }
      (**(code **)(*param_10 + 0xe8))(param_10,plVar12);
      uVar13 = 1;
    }
    bVar3 = true;
  }
LAB_fffffff009c46610:
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x40));
  if (((param_8 != 0) && (uVar13 == 0)) && (bVar3)) {
    plVar6 = thunk_FUN_fffffff00a89a1f4(1);
    uVar5 = param_8 - 1;
    if (plVar6 == (long *)0x0) {
      uVar4 = FUN_fffffff009c462d8
                        (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,uVar5,param_9,
                         (long *)0x0,0);
      auVar14 = extraout_q0_00;
      if ((uVar4 & 1) != 0) goto LAB_fffffff009c466b4;
LAB_fffffff009c467cc:
      plVar10 = thunk_FUN_fffffff00a89ca6c(plVar6);
      if (plVar10 != (long *)0x0) {
        plVar7 = (long *)0x0;
        while( true ) {
          plVar8 = (long *)(**(code **)(*plVar10 + 0x88))(plVar10);
          plVar8 = thunk_FUN_fffffff00a894f30(plVar8,-0xff50b7ba8);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar8 + 0x20))(plVar8);
          }
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          if (plVar8 == (long *)0x0) break;
          (**(code **)(*plVar8 + 0x20))(plVar8);
          FUN_fffffff009c42884(param_7,plVar8);
          plVar7 = plVar8;
        }
        (**(code **)(*plVar10 + 0x28))(plVar10);
        param_9 = param_9 & 0xffffffff;
      }
    }
    else {
      auVar14 = (**(code **)(*plVar6 + 0x20))(plVar6);
      uVar4 = FUN_fffffff009c462d8
                        (auVar14,param_2,param_3,param_4,param_5,param_6,param_7,uVar5,param_9,
                         plVar6,0);
      if (uVar4 == 0) goto LAB_fffffff009c467cc;
      auVar14 = (**(code **)(*plVar6 + 0x20))(plVar6);
LAB_fffffff009c466b4:
      uVar5 = FUN_fffffff009c462d8
                        (auVar14,param_2,param_3,param_4,param_5,param_6,param_7,uVar5,param_9,
                         plVar6,0);
      if (uVar5 == 0) goto LAB_fffffff009c467cc;
      plVar10 = thunk_FUN_fffffff00a89ca6c(plVar6);
      if (plVar10 == (long *)0x0) {
        uVar13 = 1;
      }
      else {
        plVar7 = (long *)0x0;
        while( true ) {
          plVar8 = (long *)(**(code **)(*plVar10 + 0x88))(plVar10);
          plVar8 = thunk_FUN_fffffff00a894f30(plVar8,-0xff50b7ba8);
          if (plVar8 != (long *)0x0) {
            (**(code **)(*plVar8 + 0x20))(plVar8);
          }
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          if (plVar8 == (long *)0x0) break;
          local_70 = plVar8;
          (**(code **)(*plVar8 + 0x20))(plVar8);
          thunk_FUN_fffffff00a89a3f0(param_10,&local_70);
          plVar7 = plVar8;
          if (local_70 != (long *)0x0) {
            (**(code **)(*local_70 + 0x28))();
          }
        }
        (**(code **)(*plVar10 + 0x28))(plVar10);
        uVar13 = 1;
      }
    }
    if (plVar6 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
  }
  if ((param_11 & (uVar13 ^ 1)) == 1) {
    plVar6 = (long *)(**(code **)(DAT_fffffff00af48458 + 0x68))();
    auVar14 = extraout_q0_01;
    if (plVar12 != (long *)0x0) {
      auVar14 = (**(code **)(*plVar12 + 0x28))(plVar12);
    }
    if (plVar6 == (long *)0x0) goto LAB_fffffff009c46a20;
    bVar3 = FUN_fffffff009c43270
                      (auVar14,param_2,param_3,param_4,param_5,param_6,(long)plVar6,param_9,
                       (long)((1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f)) <<
                             (ulong)(param_8 & 0x1f)));
    if (bVar3) {
      (**(code **)(*param_10 + 0xe8))(param_10,plVar6);
      uVar13 = 1;
    }
  }
  else {
    plVar6 = plVar12;
    if (plVar12 == (long *)0x0) goto LAB_fffffff009c46a20;
  }
  (**(code **)(*plVar6 + 0x28))(plVar6);
LAB_fffffff009c46a20:
  if (param_10 != (long *)0x0) {
    (**(code **)(*param_10 + 0x28))(param_10);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return uVar13;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

