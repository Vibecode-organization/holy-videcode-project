// FUN_fffffff009974a94 @ fffffff009974a94 size=224

long FUN_fffffff009974a94(long param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  
  plVar2 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x1c8));
  if (plVar2 == (long *)0x0) {
    lVar4 = 0;
  }
  else {
    iVar1 = (**(code **)(*plVar2 + 0x90))();
    if (iVar1 != 0) {
      iVar5 = 0;
      do {
        uVar3 = (**(code **)(*plVar2 + 0x118))(plVar2,iVar5);
        lVar4 = FUN_fffffff00996552c(uVar3,param_2);
        if (lVar4 != 0) goto LAB_fffffff009974b44;
        iVar5 = iVar5 + 1;
      } while (iVar1 != iVar5);
    }
    lVar4 = 0;
LAB_fffffff009974b44:
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return lVar4;
}

