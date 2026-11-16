// FUN_fffffff009c3b628 @ fffffff009c3b628 size=392

/* WARNING: Removing unreachable block (ram,0xfffffff009c3b6b0) */

undefined8 FUN_fffffff009c3b628(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ulong uVar2;
  long *plVar3;
  long *plVar4;
  undefined8 extraout_x1;
  long lVar5;
  undefined8 uVar6;
  undefined1 auStack_50 [8];
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar6 = 0xe00002bd;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  uVar2 = FUN_fffffff009c3f044(param_1,param_2,auStack_50);
  if ((uVar2 & 1) == 0) {
    lVar5 = *(long *)(param_1 + 0xf8);
    if (lVar5 == 0) {
      lVar5 = 0;
    }
    plVar3 = (long *)FUN_fffffff009c33a4c(*(undefined8 *)(param_1 + 0xe8),param_2,lVar5,param_1);
    if (plVar3 != (long *)0x0) {
      plVar4 = (long *)FUN_fffffff009c2b810(*(undefined8 *)(param_1 + 0x118),plVar3,0);
      if ((plVar4 != (long *)0x0) &&
         (iVar1 = FUN_fffffff009c3f2b0(param_1,plVar4,(int)plVar3[2]), iVar1 != 0)) {
        FUN_fffffff009c3f478(param_1,extraout_x1,0);
        FUN_fffffff009c2c18c(plVar4,param_3);
        uVar6 = 0;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
      (**(code **)(*plVar3 + 0x28))(plVar3);
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
      goto LAB_fffffff009c3b778;
    }
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
  uVar6 = 0xe00002c2;
LAB_fffffff009c3b778:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return uVar6;
  }
  uVar6 = thunk_EXT_FUN_8011000003a48590();
  return uVar6;
}

