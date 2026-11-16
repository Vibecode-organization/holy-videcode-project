// FUN_fffffff009c44a58 @ fffffff009c44a58 size=4

undefined8 FUN_fffffff009c44a58(long param_1,long *param_2)

{
  uint uVar1;
  long *plVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long *plStack_70;
  long lStack_68;
  
  lStack_68 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar2 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  if (plVar2 == (long *)0x0) {
    uVar4 = 0;
    goto joined_r0xfffffff009c44b98;
  }
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_1 + 0x18));
  lVar5 = *(long *)(param_1 + 0x30);
  if (*(long *)(param_1 + 0x30) == 0) {
    thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x18));
LAB_fffffff009c44ba8:
    plStack_70 = plVar2;
    (**(code **)(*plVar2 + 0x20))(plVar2);
    thunk_EXT_FUN_801100000389d40c(param_2,"Contexts",&plStack_70);
    if (plStack_70 != (long *)0x0) {
      (**(code **)(*plStack_70 + 0x28))();
    }
    uVar4 = 1;
  }
  else {
    do {
      lVar6 = *(long *)(lVar5 + 0x30);
      plVar3 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
      if (plVar3 == (long *)0x0) {
        uVar1 = 0;
      }
      else {
        (**(code **)(*plVar3 + 0x20))();
        uVar1 = FUN_fffffff009c429e4(lVar5,plVar3);
        if (uVar1 != 0) {
          plStack_70 = plVar3;
          (**(code **)(*plVar3 + 0x20))(plVar3);
          thunk_EXT_FUN_80110000038963f0(plVar2,&plStack_70);
          if (plStack_70 != (long *)0x0) {
            (**(code **)(*plStack_70 + 0x28))();
          }
        }
        (**(code **)(*plVar3 + 0x28))(plVar3);
      }
      lVar5 = lVar6;
    } while (lVar6 != 0);
    thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x18));
    if ((uVar1 & 1) != 0) goto LAB_fffffff009c44ba8;
    uVar4 = 0;
  }
  (**(code **)(*plVar2 + 0x28))(plVar2);
joined_r0xfffffff009c44b98:
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_68) {
    return uVar4;
  }
  uVar4 = thunk_EXT_FUN_8011000003a48590();
  return uVar4;
}

