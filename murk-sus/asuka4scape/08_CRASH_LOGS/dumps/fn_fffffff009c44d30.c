// FUN_fffffff009c44d30 @ fffffff009c44d30 size=996
// CALLERS:
//   fffffff00afec1de no-fn
//   fffffff009c44cd4 FUN_fffffff009c44c88@fffffff009c44c88
//   fffffff009c3ed9c FUN_fffffff009c3eb68@fffffff009c3eb68
//   fffffff009c44d2c FUN_fffffff009c44c88@fffffff009c44c88
// CALLEES:
//   fffffff009c49430 FUN_fffffff009c49430
//   fffffff009c49894 thunk_FUN_fffffff00a8a140c
//   fffffff009c45114 FUN_fffffff009c45114
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c49864 thunk_FUN_fffffff00a8a10d8
//   fffffff009c49674 thunk_FUN_fffffff00a228d30
//   fffffff009c429e4 FUN_fffffff009c429e4
//   fffffff009c49a54 thunk_FUN_fffffff00a89a1f4
//   fffffff009c49664 thunk_FUN_fffffff00a228180

undefined8
FUN_fffffff009c44d30
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long *param_8,
          long param_9)

{
  long *plVar1;
  bool bVar2;
  uint uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar13 [16];
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar4 = thunk_FUN_fffffff00a89a1f4(1);
  plVar5 = thunk_FUN_fffffff00a89a1f4(1);
  if (plVar4 == (long *)0x0) {
LAB_fffffff009c45058:
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
    if (plVar4 == (long *)0x0) {
      uVar8 = 0;
      goto joined_r0xfffffff009c45108;
    }
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
    if (plVar5 != (long *)0x0) {
      uVar9 = 1;
      plVar6 = thunk_FUN_fffffff00a89a1f4(1);
      thunk_FUN_fffffff00a228180(*(ulong *)(param_7 + 0x10));
      plVar12 = *(long **)(param_7 + 0x20);
      auVar13 = extraout_q0;
      while (plVar1 = plVar12, plVar1 != (long *)0x0) {
        plVar12 = (long *)plVar1[2];
        bVar2 = FUN_fffffff009c49430
                          (auVar13,param_2,param_3,param_4,param_5,param_6,(uint *)(plVar1 + 4));
        auVar13 = extraout_q0_00;
        if (bVar2) {
          (**(code **)(*plVar6 + 0xe8))(plVar6,plVar1);
          if ((param_9 == 0) || (plVar1[5] == param_9)) {
            plVar7 = thunk_FUN_fffffff00a8a10d8(1);
            if (plVar7 == (long *)0x0) {
              uVar9 = 0;
            }
            else {
              (**(code **)(*plVar7 + 0x20))();
              uVar3 = FUN_fffffff009c45114((long)plVar1,plVar7);
              uVar9 = (ulong)uVar3;
              if (uVar3 != 0) {
                (**(code **)(*plVar4 + 0xe8))(plVar4,plVar7);
              }
              (**(code **)(*plVar7 + 0x28))(plVar7);
            }
          }
          auVar13 = (**(code **)(*plVar1 + 0x28))(plVar1);
        }
      }
      thunk_FUN_fffffff00a228d30(*(long *)(param_7 + 0x10));
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      thunk_FUN_fffffff00a228180(*(ulong *)(param_7 + 0x18));
      lVar10 = *(long *)(param_7 + 0x30);
joined_r0xfffffff009c44ee4:
      lVar11 = lVar10;
      if (lVar10 != 0) {
        do {
          lVar10 = *(long *)(lVar11 + 0x30);
          if ((param_9 == 0) || (*(long *)(lVar11 + 0x10) == param_9)) {
            plVar12 = thunk_FUN_fffffff00a8a10d8(1);
            if (plVar12 == (long *)0x0) goto LAB_fffffff009c44f8c;
            (**(code **)(*plVar12 + 0x20))();
            uVar9 = FUN_fffffff009c429e4(lVar11,plVar12);
            if ((int)uVar9 != 0) {
              (**(code **)(*plVar5 + 0xe8))(plVar5,plVar12);
            }
            (**(code **)(*plVar12 + 0x28))(plVar12);
          }
          lVar11 = lVar10;
          if (lVar10 == 0) break;
        } while( true );
      }
      thunk_FUN_fffffff00a228d30(*(long *)(param_7 + 0x18));
      if ((uVar9 & 1) != 0) {
        local_70 = plVar5;
        (**(code **)(*plVar5 + 0x20))(plVar5);
        thunk_FUN_fffffff00a8a140c(param_8,"InUse",&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
        local_70 = plVar4;
        (**(code **)(*plVar4 + 0x20))(plVar4);
        thunk_FUN_fffffff00a8a140c(param_8,"OutOfUse",&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
      }
      goto LAB_fffffff009c45058;
    }
  }
  (**(code **)(*plVar4 + 0x28))(plVar4);
joined_r0xfffffff009c45108:
  if (param_8 != (long *)0x0) {
    (**(code **)(*param_8 + 0x28))(param_8);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar8;
LAB_fffffff009c44f8c:
  uVar9 = 0;
  goto joined_r0xfffffff009c44ee4;
}

