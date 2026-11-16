// FUN_fffffff009c00764 @ fffffff009c00764 size=876
// CALLERS:
// CALLEES:
//   fffffff009c110a8 thunk_FUN_fffffff00a89a1f4
//   fffffff009c11038 thunk_FUN_fffffff00a89ca6c

/* WARNING: Removing unreachable block (ram,0xfffffff009c00a6c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c00aa0) */

undefined8 FUN_fffffff009c00764(long *param_1)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  code *pcVar9;
  undefined8 uVar10;
  undefined4 local_54;
  
  uVar10 = 0xe00002bc;
  local_54 = 0;
  if (((*(byte *)(param_1 + 0x12) & 1) != 0) &&
     (plVar2 = (long *)(**(code **)(*param_1 + 0x5b8))(param_1,&local_54), plVar2 != (long *)0x0)) {
    iVar1 = (**(code **)(*param_1 + 0x300))(param_1,0);
    if (iVar1 != 0) {
      uVar3 = (**(code **)(*(long *)param_1[0x17] + 0x90))();
      plVar4 = thunk_FUN_fffffff00a89a1f4(uVar3);
      if (plVar4 != (long *)0x0) {
        plVar5 = thunk_FUN_fffffff00a89ca6c(param_1[0x17]);
        if (plVar5 != (long *)0x0) {
          plVar6 = (long *)(**(code **)(*plVar5 + 0x88))();
          if (plVar6 != (long *)0x0) {
            do {
              iVar1 = (**(code **)(*plVar6 + 0x300))(plVar6,0);
              if (iVar1 == 0) goto LAB_fffffff009c009e0;
              uVar7 = (**(code **)(*plVar4 + 0xe8))(plVar4,plVar6);
              if ((uVar7 & 1) == 0) {
                (**(code **)(*plVar6 + 0x308))(plVar6);
                goto LAB_fffffff009c009e0;
              }
              plVar6 = (long *)(**(code **)(*plVar5 + 0x88))(plVar5);
            } while (plVar6 != (long *)0x0);
            lVar8 = (**(code **)(*param_1 + 0x5b0))(param_1,param_1[0x17],plVar2);
            if (lVar8 != 0) {
              (**(code **)(*(long *)param_1[0x17] + 0x28))();
              uVar10 = 0;
              param_1[0x17] = lVar8;
            }
          }
LAB_fffffff009c009e0:
          (**(code **)(*plVar5 + 0x28))(plVar5);
          pcVar9 = *(code **)(*plVar4 + 0x90);
          while (iVar1 = (*pcVar9)(plVar4), iVar1 != 0) {
            plVar5 = (long *)(**(code **)(*plVar4 + 0x118))(plVar4,iVar1 + -1);
            (**(code **)(*plVar5 + 0x308))(*plVar5 + 0x308);
            (**(code **)(*plVar4 + 0x108))(*plVar4 + 0x108,plVar4,iVar1 + -1);
            pcVar9 = *(code **)(*plVar4 + 0x90);
          }
        }
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      (**(code **)(*param_1 + 0x308))(param_1);
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar10;
}

