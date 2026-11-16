// FUN_fffffff008190870 @ fffffff008190870 size=376

void FUN_fffffff008190870
               (long param_1,undefined8 param_2,undefined8 param_3,uint param_4,undefined8 param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  long *local_58;
  
  local_58 = (long *)0x0;
  uVar4 = thunk_EXT_FUN_8011000002972b90();
  iVar3 = thunk_EXT_FUN_80110000039a3b60(uVar4,param_2,&local_58);
  if ((iVar3 == 0) &&
     (lVar5 = thunk_EXT_FUN_8011000003890f30(local_58,*(undefined8 *)PTR_DAT_fffffff007ca6080),
     lVar5 != 0)) {
    uVar4 = thunk_EXT_FUN_8011000002c12750();
    iVar3 = *(int *)(*(long *)(param_1 + 0x530) + 0x23c);
    plVar6 = (long *)FUN_fffffff0081e2fcc
                               (*(undefined8 *)
                                 (*(long *)(*(long *)(param_1 + 0x530) + 0x11d98) + 0x10),uVar4);
    if (plVar6 != (long *)0x0) {
      uVar2 = iVar3 * 1000 - 1000;
      if (3999 < uVar2) {
        uVar2 = 4000;
      }
      uVar1 = param_4;
      if (uVar2 <= param_4) {
        uVar1 = uVar2;
      }
      if (param_4 != 0) {
        uVar2 = uVar1;
      }
      iVar3 = FUN_fffffff00818b3a0(param_1,plVar6,param_3,uVar2,param_5,0);
      if (iVar3 != 0) {
        thunk_EXT_FUN_8011000002c13ca8
                  (uVar4,*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x350),param_3,0,param_1,
                   FUN_fffffff00818bf08);
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      goto LAB_fffffff0081908c8;
    }
  }
  *(undefined4 *)(param_1 + 0x520) = 10;
LAB_fffffff0081908c8:
  if (local_58 != (long *)0x0) {
    (**(code **)(*local_58 + 0x28))();
  }
  return;
}

