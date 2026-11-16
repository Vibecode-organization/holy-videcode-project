// FUN_fffffff008d15064 @ fffffff008d15064 size=460
// CALLERS:
//   fffffff00afb8d54 no-fn
//   fffffff008d15078 FUN_fffffff008d15064@fffffff008d15064
// CALLEES:
//   fffffff008d5d5cc FUN_fffffff008d5d5cc
//   fffffff008de694c FUN_fffffff008de694c
//   fffffff008e00070 thunk_EXT_FUN_8011000003976e84
//   fffffff008cd5954 FUN_fffffff008cd5954
//   fffffff008de6908 FUN_fffffff008de6908

/* WARNING: Removing unreachable block (ram,0xfffffff008d150e8) */

undefined8 FUN_fffffff008d15064(long param_1,undefined8 *param_2,long param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  uVar5 = 0xe00002bd;
  if (param_3 == 0x10) {
    plVar2 = (long *)thunk_EXT_FUN_8011000003976e84
                               (*param_2,0x1b0,3,*(undefined8 *)(param_1 + 0x130));
    if (plVar2 != (long *)0x0) {
      plVar3 = (long *)thunk_EXT_FUN_8011000003976e84
                                 (param_2[1],0x18,3,*(undefined8 *)(param_1 + 0x130));
      if (plVar3 == (long *)0x0) {
        pcVar4 = *(code **)(*plVar2 + 0x28);
      }
      else {
        iVar1 = (**(code **)(*plVar2 + 0xd8))(plVar2,0);
        if ((iVar1 == 0) && (iVar1 = (**(code **)(*plVar3 + 0xd8))(plVar3,0), iVar1 == 0)) {
          uVar5 = FUN_fffffff008d5d5cc(*(undefined8 *)(param_1 + 0x100),plVar2,plVar3,param_1);
          (**(code **)(*plVar2 + 0xe0))(plVar2,0);
          (**(code **)(*plVar3 + 0xe0))(plVar3,0);
        }
        else {
          iVar1 = FUN_fffffff008cd5954(1,4);
          if (iVar1 != 0) {
            FUN_fffffff008de694c();
          }
        }
        (**(code **)(*plVar2 + 0x28))(plVar2);
        pcVar4 = *(code **)(*plVar3 + 0x28);
        plVar2 = plVar3;
      }
      (*pcVar4)(plVar2);
    }
  }
  else {
    iVar1 = FUN_fffffff008cd5954(1,4);
    uVar5 = 0xe00002c2;
    if (iVar1 != 0) {
      FUN_fffffff008de6908(param_3);
    }
  }
  return uVar5;
}

