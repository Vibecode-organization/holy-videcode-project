// FUN_fffffff009c14478 @ fffffff009c14478

undefined8 FUN_fffffff009c14478(long *param_1,long *param_2,long *param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  
  uVar9 = 0;
  if ((param_2 != (long *)0x0) && (param_3 != (long *)0x0)) {
    plVar2 = thunk_FUN_fffffff00a89ca6c(param_3);
    if (plVar2 == (long *)0x0) {
      uVar9 = 0;
    }
    else {
      plVar3 = (long *)(**(code **)(*plVar2 + 0x88))();
      if (plVar3 == (long *)0x0) {
LAB_fffffff009c1474c:
        uVar9 = 0;
      }
      else {
        uVar9 = 0;
        lVar8 = *(long *)PTR_PTR_fffffff008066510;
        do {
          (**(code **)(*plVar3 + 0xa8))(plVar3);
          plVar4 = (long *)(**(code **)(*param_2 + 0x108))(param_2,plVar3);
          if (plVar4 == (long *)0x0) {
            plVar4 = (long *)0x0;
          }
          else {
            plVar4 = thunk_FUN_fffffff00a894f30(plVar4,lVar8);
          }
          plVar5 = (long *)(**(code **)(*param_3 + 0x128))(param_3,plVar3);
          plVar5 = thunk_FUN_fffffff00a894f30(plVar5,lVar8);
          if ((plVar4 == (long *)0x0) || (plVar5 == (long *)0x0)) {
            uVar9 = (**(code **)(*param_3 + 0x128))(param_3,plVar3);
            uVar7 = (**(code **)(*param_2 + 0xb8))(param_2,plVar3,uVar9);
            if ((uVar7 & 1) == 0) goto LAB_fffffff009c1474c;
          }
          else {
            plVar6 = (long *)(**(code **)(*plVar4 + 200))(plVar4,0);
            if (plVar6 == (long *)0x0) break;
            (**(code **)(*plVar4 + 0x98))(plVar4);
            uVar7 = (**(code **)(*param_1 + 0x548))(param_1,plVar5,plVar6);
            if ((uVar7 & 1) == 0) {
              (**(code **)(*plVar6 + 0x28))(plVar6);
              goto LAB_fffffff009c1474c;
            }
            (**(code **)(*plVar4 + 0x98))(plVar4);
            iVar1 = (**(code **)(*param_2 + 0xb8))(param_2,plVar3,plVar6);
            (**(code **)(*plVar6 + 0x28))(plVar6);
            if (iVar1 == 0) goto LAB_fffffff009c1474c;
          }
          plVar3 = (long *)(**(code **)(*plVar2 + 0x88))(plVar2);
          uVar9 = 1;
        } while (plVar3 != (long *)0x0);
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  return uVar9;
}

