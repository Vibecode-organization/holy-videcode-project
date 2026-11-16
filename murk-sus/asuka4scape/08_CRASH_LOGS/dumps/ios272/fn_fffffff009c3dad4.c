// FUN_fffffff009c3dad4 @ fffffff009c3dad4 size=280

/* WARNING: Removing unreachable block (ram,0xfffffff009c3db68) */

undefined8
FUN_fffffff009c3dad4(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar5 = 0xe00002bd;
  plVar2 = (long *)FUN_fffffff009c16a78(*(undefined8 *)(param_1 + 0xe8));
  if (plVar2 != (long *)0x0) {
    plVar3 = (long *)FUN_fffffff009c165ec();
    if (plVar3 != (long *)0x0) {
      uVar6 = *(undefined8 *)(param_1 + 0x118);
      uVar5 = FUN_fffffff009c17530(plVar2);
      iVar1 = FUN_fffffff009c41eec(uVar6,uVar5,param_4);
      if (iVar1 == 0) {
        uVar5 = 0xe00002c8;
      }
      else {
        lVar4 = *(long *)(param_1 + 0xf8);
        if (lVar4 == 0) {
          lVar4 = 0;
        }
        uVar5 = thunk_EXT_FUN_80110000039a3b30(lVar4,plVar3,param_3);
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar5;
}

