// FUN_fffffff009c45114 @ fffffff009c45114 size=1248

undefined8 FUN_fffffff009c45114(long param_1,long *param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  undefined8 uVar9;
  long *plVar10;
  long *plVar11;
  long *plVar12;
  ulong uVar13;
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(10);
  if (plVar5 == (long *)0x0) {
    uVar9 = 0;
  }
  else {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x40));
    uVar13 = 0;
    do {
      plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
      (**(code **)(**(long **)(param_1 + 0x48 + uVar13 * 8) + 0x90))();
      plVar7 = (long *)thunk_EXT_FUN_80110000038961f4();
      bVar2 = plVar6 != (long *)0x0;
      bVar3 = plVar7 != (long *)0x0;
      bVar4 = bVar2 && bVar3;
      if (bVar2 && bVar3) {
        local_70 = (long *)thunk_EXT_FUN_80110000038c6e24
                                     ((long)((1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f)
                                             ) << (ulong)((uint)uVar13 & 0x1f)),0x20);
        thunk_EXT_FUN_801100000389d40c(plVar6,"Bucket buffer size",&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
      }
      plVar8 = (long *)thunk_EXT_FUN_8011000003898a6c(*(undefined8 *)(param_1 + 0x48 + uVar13 * 8));
      if (plVar8 == (long *)0x0) {
        if (!bVar2 || !bVar3) goto LAB_fffffff009c45444;
LAB_fffffff009c4537c:
        local_70 = plVar7;
        if (plVar7 != (long *)0x0) {
          (**(code **)(*plVar7 + 0x20))(plVar7);
        }
        thunk_EXT_FUN_801100000389d40c(plVar6,"Descriptors",&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
        local_70 = plVar6;
        if (plVar6 != (long *)0x0) {
          (**(code **)(*plVar6 + 0x20))(plVar6);
        }
        thunk_EXT_FUN_80110000038963f0(plVar5,&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
        uVar9 = 1;
      }
      else {
        plVar12 = (long *)0x0;
        while( true ) {
          uVar9 = (**(code **)(*plVar8 + 0x88))(plVar8);
          plVar10 = (long *)thunk_EXT_FUN_8011000003890f30(uVar9,&DAT_fffffff00af48458);
          if (plVar10 != (long *)0x0) {
            (**(code **)(*plVar10 + 0x20))(plVar10);
          }
          if (plVar12 != (long *)0x0) {
            (**(code **)(*plVar12 + 0x28))(plVar12);
          }
          if (plVar10 == (long *)0x0) break;
          plVar11 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
          bVar4 = plVar11 != (long *)0x0;
          plVar12 = plVar10;
          if (plVar11 != (long *)0x0) {
            FUN_fffffff009c42d48(plVar10,plVar11);
            local_70 = plVar11;
            (**(code **)(*plVar11 + 0x20))(plVar11);
            thunk_EXT_FUN_80110000038963f0(plVar7,&local_70);
            if (local_70 != (long *)0x0) {
              (**(code **)(*local_70 + 0x28))();
            }
            (**(code **)(*plVar11 + 0x28))(plVar11);
          }
        }
        (**(code **)(*plVar8 + 0x28))(plVar8);
        if (bVar4) goto LAB_fffffff009c4537c;
LAB_fffffff009c45444:
        uVar9 = 0;
      }
      if (plVar7 != (long *)0x0) {
        (**(code **)(*plVar7 + 0x28))(plVar7);
      }
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      bVar4 = uVar13 < 9;
      uVar13 = uVar13 + 1;
      iVar1 = 0;
      if (bVar4) {
        iVar1 = (int)uVar9;
      }
    } while (iVar1 != 0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x40));
    if ((int)uVar9 != 0) {
      local_70 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined8 *)(param_1 + 0x28),0x40);
      thunk_EXT_FUN_801100000389d40c(param_2,"Pool Id",&local_70);
      if (local_70 != (long *)0x0) {
        (**(code **)(*local_70 + 0x28))();
      }
      local_70 = plVar5;
      (**(code **)(*plVar5 + 0x20))();
      thunk_EXT_FUN_801100000389d40c(param_2,"Buckets",&local_70);
      if (local_70 != (long *)0x0) {
        (**(code **)(*local_70 + 0x28))();
      }
    }
    (**(code **)(*plVar5 + 0x28))();
  }
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return uVar9;
  }
  uVar9 = thunk_EXT_FUN_8011000003a48590();
  return uVar9;
}

