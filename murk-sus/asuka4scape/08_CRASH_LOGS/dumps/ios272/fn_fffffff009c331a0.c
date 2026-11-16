// FUN_fffffff009c331a0 @ fffffff009c331a0 size=340

undefined8
FUN_fffffff009c331a0
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4,long *param_5)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  
  *param_5 = 0;
  if ((param_4 == 0) &&
     (plVar2 = (long *)(**(code **)(*DAT_fffffff008068500 + 0x68))(), plVar2 != (long *)0x0)) {
    iVar1 = (**(code **)(*plVar2 + 0x5d8))(plVar2,param_1,param_2,0);
    if ((iVar1 != 0) && (iVar1 = (**(code **)(*plVar2 + 0x360))(plVar2,param_1), iVar1 != 0)) {
      uVar3 = (**(code **)(*plVar2 + 0x2b0))(plVar2,param_1);
      if ((uVar3 & 1) != 0) {
        *param_5 = (long)plVar2;
        return 0;
      }
      (**(code **)(*plVar2 + 0x368))(plVar2,param_1);
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return 0xe00002c9;
}

