// FUN_fffffff009c44170 @ fffffff009c44170 size=624
// CALLERS:
//   fffffff00afec1d6 no-fn
//   fffffff009c440ac FUN_fffffff009c4405c@fffffff009c4405c
//   fffffff009c37474 FUN_fffffff009c373ec@fffffff009c373ec
//   fffffff009c3adbc FUN_fffffff009c3ab8c@fffffff009c3ab8c
// CALLEES:
//   fffffff009c49bd4 thunk_FUN_fffffff00a29b0b4
//   fffffff009c49804 thunk_FUN_fffffff00a9a6b94
//   fffffff009c49d04 thunk_FUN_fffffff00a726d80
//   fffffff009c495f4 thunk_FUN_fffffff00a9029a0
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c
//   fffffff009c49d14 thunk_FUN_fffffff00a724f30

/* WARNING: Removing unreachable block (ram,0xfffffff009c441e0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_fffffff009c44170
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,long param_8)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  ulong uVar7;
  char *pcVar8;
  undefined8 *puVar9;
  long *plVar10;
  undefined8 extraout_d0;
  undefined8 extraout_var;
  undefined1 auVar11 [16];
  undefined8 uVar12;
  undefined8 uVar13;
  char local_70 [8];
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  auVar2._8_8_ = ram0xfffffff0078a12d8;
  auVar2._0_8_ = s__unknown__fffffff0078a12d0._0_8_;
  uVar12 = 0;
  uVar13 = 0;
  uStack_68 = ram0xfffffff0078a12d8;
  local_70 = (char  [8])s__unknown__fffffff0078a12d0._0_8_;
  uStack_58 = 0;
  uStack_60 = 0;
  if (param_8 == 0) {
    thunk_FUN_fffffff00a8df19c
              (auVar2,ZEXT816(0),param_3,param_4,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,
               (byte *)
               "IOSurfaceMemoryPool: %s (%d) invalid task (%p) can\'t access pool id %llu (wrong entitlements)\n"
              );
    pcVar8 = 
    "====> %s:%d IOSurfaceMemoryPool: %s (%d) invalid task (%p) can\'t access pool id %llu (wrong entitlements)\n"
    ;
LAB_fffffff009c443a4:
    thunk_FUN_fffffff00a9029a0((byte *)pcVar8);
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
    if ((param_8 == *(long *)(param_7 + 0x30)) || (param_8 == *(long *)PTR_DAT_fffffff00806ca70))
    goto LAB_fffffff009c443ac;
    if (*(long **)(param_7 + 0xa8) == (long *)0x0) {
      puVar9 = *(undefined8 **)PTR_PTR_fffffff00806ca60;
LAB_fffffff009c442dc:
      plVar6 = (long *)thunk_FUN_fffffff00a9a6b94(param_8,-0xff87631c2);
      plVar10 = (long *)*puVar9;
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      if (plVar10 != plVar6) {
        uVar7 = thunk_FUN_fffffff00a29b0b4(param_8);
        auVar11._8_8_ = extraout_var;
        auVar11._0_8_ = extraout_d0;
        if (uVar7 != 0) {
          uVar3 = thunk_FUN_fffffff00a724f30(uVar7);
          auVar11 = thunk_FUN_fffffff00a726d80(uVar3,(undefined8 *)local_70,0x20);
        }
        auVar1._8_8_ = uVar13;
        auVar1._0_8_ = uVar12;
        thunk_FUN_fffffff00a8df19c
                  (auVar11,auVar1,param_3,param_4,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                   (byte *)
                   "IOSurfaceMemoryPool: %s (%d) can\'t access pool id %llu (wrong entitlements)\n")
        ;
        pcVar8 = 
        "====> %s:%d IOSurfaceMemoryPool: %s (%d) can\'t access pool id %llu (wrong entitlements)\n"
        ;
        goto LAB_fffffff009c443a4;
      }
    }
    else {
      lVar5 = (**(code **)(**(long **)(param_7 + 0xa8) + 0xa8))();
      plVar6 = (long *)thunk_FUN_fffffff00a9a6b94(param_8,lVar5);
      puVar9 = *(undefined8 **)PTR_PTR_fffffff00806ca60;
      plVar10 = (long *)*puVar9;
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      if (plVar10 != plVar6) goto LAB_fffffff009c442dc;
    }
    uVar4 = 1;
  }
LAB_fffffff009c443ac:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_48) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar4;
}

