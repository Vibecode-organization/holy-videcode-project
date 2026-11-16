// FUN_fffffff0099622ec @ fffffff0099622ec size=4

undefined8 FUN_fffffff0099622ec(long param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  long *plVar9;
  long *plVar10;
  ulong uVar11;
  int iVar12;
  undefined4 uStack_6c;
  long *plStack_68;
  
  plVar4 = (long *)FUN_fffffff0099627fc();
  if (plVar4 != (long *)0x0) {
    iVar1 = (**(code **)(*plVar4 + 0x90))(plVar4);
    plVar5 = (long *)thunk_EXT_FUN_80110000038961f4();
    if (0 < iVar1) {
      iVar12 = 0;
      do {
        plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(0x10);
        plVar7 = (long *)(**(code **)(*plVar4 + 0x118))(plVar4,iVar12);
        (**(code **)(*plVar7 + 0x80))(plVar7,plVar6);
        (**(code **)(*plVar5 + 0xe8))(plVar5,plVar6);
        if (plVar6 != (long *)0x0) {
          (**(code **)(*plVar6 + 0x28))(plVar6);
        }
        iVar12 = iVar12 + 1;
      } while (iVar1 != iVar12);
    }
    plStack_68 = plVar5;
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x20))(plVar5);
    }
    thunk_EXT_FUN_801100000389d40c(param_2,"BusyWorkQueues",&plStack_68);
    if (plStack_68 != (long *)0x0) {
      (**(code **)(*plStack_68 + 0x28))();
    }
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  uVar2 = FUN_fffffff00994abb0(*(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0x148));
  plVar5 = (long *)thunk_EXT_FUN_80110000038961f4();
  if (plVar5 != (long *)0x0) {
    if (0 < (int)uVar2) {
      uVar11 = 0;
      do {
        uVar8 = FUN_fffffff00994b748(*(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0x148),uVar11);
        if (((uVar8 & 1) == 0) &&
           (plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(3), plVar6 != (long *)0x0)) {
          uStack_6c = 0;
          uVar3 = FUN_fffffff00994d624
                            (*(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0x148),uVar11,&uStack_6c);
          plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar11,0x20);
          plVar9 = (long *)thunk_EXT_FUN_80110000038c6e24(uStack_6c,0x20);
          plVar10 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar3,0x20);
          if ((plVar7 != (long *)0x0) && ((plVar9 != (long *)0x0 && (plVar10 != (long *)0x0)))) {
            plStack_68 = plVar7;
            (**(code **)(*plVar7 + 0x20))(plVar7);
            thunk_EXT_FUN_801100000389d40c(plVar6,"idx",&plStack_68);
            if (plStack_68 != (long *)0x0) {
              (**(code **)(*plStack_68 + 0x28))();
            }
            plStack_68 = plVar9;
            (**(code **)(*plVar9 + 0x20))(plVar9);
            thunk_EXT_FUN_801100000389d40c(plVar6,"sub",&plStack_68);
            if (plStack_68 != (long *)0x0) {
              (**(code **)(*plStack_68 + 0x28))();
            }
            plStack_68 = plVar10;
            (**(code **)(*plVar10 + 0x20))(plVar10);
            thunk_EXT_FUN_801100000389d40c(plVar6,"gpu",&plStack_68);
            if (plStack_68 != (long *)0x0) {
              (**(code **)(*plStack_68 + 0x28))();
            }
          }
          plStack_68 = plVar6;
          (**(code **)(*plVar6 + 0x20))(plVar6);
          thunk_EXT_FUN_80110000038963f0(plVar5,&plStack_68);
          if (plStack_68 != (long *)0x0) {
            (**(code **)(*plStack_68 + 0x28))();
          }
          if (plVar10 != (long *)0x0) {
            (**(code **)(*plVar10 + 0x28))(plVar10);
          }
          if (plVar9 != (long *)0x0) {
            (**(code **)(*plVar9 + 0x28))(plVar9);
          }
          if (plVar7 != (long *)0x0) {
            (**(code **)(*plVar7 + 0x28))(plVar7);
          }
          (**(code **)(*plVar6 + 0x28))(plVar6);
        }
        uVar11 = uVar11 + 1;
      } while (uVar2 != uVar11);
    }
    plStack_68 = plVar5;
    (**(code **)(*plVar5 + 0x20))(plVar5);
    thunk_EXT_FUN_801100000389d40c(param_2,"Stamps",&plStack_68);
    if (plStack_68 != (long *)0x0) {
      (**(code **)(*plStack_68 + 0x28))();
    }
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  return 1;
}

