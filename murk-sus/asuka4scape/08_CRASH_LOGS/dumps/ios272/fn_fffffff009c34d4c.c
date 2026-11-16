// FUN_fffffff009c34d4c @ fffffff009c34d4c size=2068

/* WARNING: Removing unreachable block (ram,0xfffffff009c351e0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c350b4) */

void FUN_fffffff009c34d4c(long *param_1,long *param_2,int param_3)

{
  undefined8 uVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  long *local_c8;
  undefined *local_c0;
  undefined8 local_b8;
  code *local_b0;
  undefined *local_a8;
  long *local_a0;
  undefined *local_98;
  undefined8 local_90;
  code *local_88;
  undefined *local_80;
  long *local_78;
  int local_70;
  undefined4 uStack_6c;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar3 = (long *)thunk_EXT_FUN_801100000389d0d8(0x10);
  if (plVar3 != (long *)0x0) {
    plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)((long)param_1 + 0x1a4),0x20);
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x100))(plVar3,"Debug Bits Value",plVar4);
    }
    plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(0x10);
    if (plVar5 != (long *)0x0) {
      lVar11 = 0;
      lVar12 = 0x10;
      do {
        if ((((&DAT_fffffff008068380)[lVar11 * 4] & *(uint *)((long)param_1 + 0x1a4)) != 0) &&
           (plVar6 = (long *)thunk_EXT_FUN_80110000038ce200((&DAT_fffffff008068388)[lVar11 * 2]),
           plVar6 != (long *)0x0)) {
          (**(code **)(*plVar5 + 0xe8))(plVar5,plVar6);
          (**(code **)(*plVar6 + 0x28))(plVar6);
        }
        lVar11 = lVar11 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      (**(code **)(*plVar3 + 0x100))(plVar3,"Active Debug Flags",plVar5);
    }
    (**(code **)(*param_2 + 0x100))(param_2,"IOSurface Debug Configuration",plVar3);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  thunk_EXT_FUN_80110000032222a8(param_1[0x28]);
  plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)((long)param_1 + 0x1e4));
  if (plVar4 != (long *)0x0) {
    for (plVar5 = (long *)param_1[0x12]; plVar5 != (long *)0x0; plVar5 = (long *)plVar5[3]) {
      iVar2 = FUN_fffffff009c1f34c(plVar5);
      if (iVar2 != 0) {
        (**(code **)(*plVar4 + 0xe8))(plVar4,plVar5);
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
    }
  }
  plVar5 = (long *)thunk_EXT_FUN_801100000389d2fc(param_1[0x2b],0);
  plVar6 = (long *)param_1[0x43];
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x20))(plVar6);
  }
  thunk_EXT_FUN_8011000003222de0(param_1[0x28]);
  plVar7 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  if (plVar7 == (long *)0x0) {
    plVar8 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  }
  else {
    uStack_6c = 0x100;
    if (param_3 != 0) {
      uStack_6c = 0x800;
    }
    local_98 = PTR_DAT_fffffff00806c9b8;
    local_90 = DAT_fffffff0078a12a0;
    local_88 = FUN_fffffff009c35560;
    local_80 = &DAT_fffffff008068480;
    local_78 = plVar7;
    local_70 = param_3;
    (**(code **)(*plVar7 + 0x20))();
    thunk_EXT_FUN_801100000389794c(plVar4,&local_98);
    (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"Kernel Surfaces",plVar7);
    if (local_78 != (long *)0x0) {
      (**(code **)(*local_78 + 0x28))();
    }
    local_78 = (long *)0x0;
    plVar8 = (long *)thunk_EXT_FUN_80110000038961f4(1);
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (plVar8 != (long *)0x0) {
    local_b0 = FUN_fffffff009c3578c;
    local_a8 = &DAT_fffffff0080684b0;
    local_c0 = PTR_DAT_fffffff00806c9b8;
    local_b8 = DAT_fffffff0078a12a0;
    local_a0 = plVar8;
    (**(code **)(*plVar8 + 0x20))(plVar8);
    thunk_EXT_FUN_801100000389d600(plVar5,&local_c0);
    (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"Memory Regions",plVar8);
    if (local_a0 != (long *)0x0) {
      (**(code **)(*local_a0 + 0x28))();
    }
    local_a0 = (long *)0x0;
  }
  if ((plVar6 != (long *)0x0) &&
     (plVar7 = (long *)thunk_EXT_FUN_801100000389d0d8(1), plVar7 != (long *)0x0)) {
    (**(code **)(*plVar7 + 0x20))();
    FUN_fffffff009c44c88(plVar6,plVar7);
    local_c8 = plVar7;
    (**(code **)(*plVar7 + 0x20))(plVar7);
    thunk_EXT_FUN_801100000389d40c(param_2,"Memory Pools",&local_c8);
    if (local_c8 != (long *)0x0) {
      (**(code **)(*local_c8 + 0x28))();
    }
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  plVar7 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  if (plVar7 != (long *)0x0) {
    plVar9 = (long *)(**(code **)(*param_1 + 0x398))(param_1);
    if (plVar9 != (long *)0x0) {
      lVar11 = (**(code **)(*plVar9 + 0x88))(plVar9);
      uVar1 = DAT_fffffff008068500;
      while (lVar11 != 0) {
        lVar11 = thunk_EXT_FUN_8011000003890f30(lVar11,uVar1);
        if (lVar11 != 0) {
          plVar10 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
          FUN_fffffff009c3f998(lVar11,plVar10,param_3);
          (**(code **)(*plVar7 + 0xe8))(plVar7,plVar10);
          if (plVar10 != (long *)0x0) {
            (**(code **)(*plVar10 + 0x28))(plVar10);
          }
        }
        lVar11 = (**(code **)(*plVar9 + 0x88))(plVar9);
      }
    }
    (**(code **)(*param_2 + 0x100))(param_2,"User Clients",plVar7);
    if (plVar9 != (long *)0x0) {
      (**(code **)(*plVar9 + 0x28))(plVar9);
    }
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

