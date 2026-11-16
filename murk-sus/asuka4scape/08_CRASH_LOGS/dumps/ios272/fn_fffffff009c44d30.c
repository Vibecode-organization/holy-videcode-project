// FUN_fffffff009c44d30 @ fffffff009c44d30 size=996

undefined8 FUN_fffffff009c44d30(long param_1,long *param_2,long param_3)

{
  long *plVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  long *plVar11;
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(1);
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
      uVar3 = 1;
      plVar6 = (long *)thunk_EXT_FUN_80110000038961f4(1);
      thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_1 + 0x10));
      plVar11 = *(long **)(param_1 + 0x20);
      while (plVar1 = plVar11, plVar1 != (long *)0x0) {
        plVar11 = (long *)plVar1[2];
        iVar2 = FUN_fffffff009c49430(plVar1 + 4);
        if (iVar2 != 0) {
          (**(code **)(*plVar6 + 0xe8))(plVar6,plVar1);
          if ((param_3 == 0) || (plVar1[5] == param_3)) {
            plVar7 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
            if (plVar7 == (long *)0x0) {
              uVar3 = 0;
            }
            else {
              (**(code **)(*plVar7 + 0x20))();
              uVar3 = FUN_fffffff009c45114(plVar1,plVar7);
              if (uVar3 != 0) {
                (**(code **)(*plVar4 + 0xe8))(plVar4,plVar7);
              }
              (**(code **)(*plVar7 + 0x28))(plVar7);
            }
          }
          (**(code **)(*plVar1 + 0x28))(plVar1);
        }
      }
      thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x10));
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_1 + 0x18));
      lVar9 = *(long *)(param_1 + 0x30);
joined_r0xfffffff009c44ee4:
      lVar10 = lVar9;
      if (lVar9 != 0) {
        do {
          lVar9 = *(long *)(lVar10 + 0x30);
          if ((param_3 == 0) || (*(long *)(lVar10 + 0x10) == param_3)) {
            plVar11 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
            if (plVar11 == (long *)0x0) goto LAB_fffffff009c44f8c;
            (**(code **)(*plVar11 + 0x20))();
            uVar3 = FUN_fffffff009c429e4(lVar10,plVar11);
            if (uVar3 != 0) {
              (**(code **)(*plVar5 + 0xe8))(plVar5,plVar11);
            }
            (**(code **)(*plVar11 + 0x28))(plVar11);
          }
          lVar10 = lVar9;
          if (lVar9 == 0) break;
        } while( true );
      }
      thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x18));
      if ((uVar3 & 1) != 0) {
        local_70 = plVar5;
        (**(code **)(*plVar5 + 0x20))(plVar5);
        thunk_EXT_FUN_801100000389d40c(param_2,"InUse",&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
        local_70 = plVar4;
        (**(code **)(*plVar4 + 0x20))(plVar4);
        thunk_EXT_FUN_801100000389d40c(param_2,"OutOfUse",&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
      }
      goto LAB_fffffff009c45058;
    }
  }
  (**(code **)(*plVar4 + 0x28))(plVar4);
joined_r0xfffffff009c45108:
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
    uVar8 = thunk_EXT_FUN_8011000003a48590();
    return uVar8;
  }
  return uVar8;
LAB_fffffff009c44f8c:
  uVar3 = 0;
  goto joined_r0xfffffff009c44ee4;
}

