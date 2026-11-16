// FUN_fffffff00817e91c @ fffffff00817e91c size=376

/* WARNING: Removing unreachable block (ram,0xfffffff00817e9e0) */

bool FUN_fffffff00817e91c(long *param_1,long *param_2,int *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  
  if ((*(byte *)((long)param_1 + 0x57a) & 1) != 0) {
    (**(code **)(*param_1 + 0xbc0))(param_1,1);
  }
  iVar1 = *param_3;
  lVar2 = param_2[0xf];
  plVar6 = (long *)param_1[0x96];
  lVar3 = param_2[3];
  uVar4 = (**(code **)(*param_2 + 0x128))(param_2);
  lVar5 = *plVar6;
  (**(code **)(lVar5 + 400))
            (lVar5 + 400,plVar6,param_2,param_3,(int)lVar3,uVar4,(int)lVar2 != iVar1);
  if ((*(byte *)(param_1 + 0xaa) & 1) == 0) {
    *(undefined1 *)(param_1 + 0xaa) = 1;
    (**(code **)(*(long *)param_1[0xa9] + 0xf0))((long *)param_1[0xa9],1000);
  }
  if ((*(byte *)(param_1 + 0xac) & 1) == 0) {
    *(undefined1 *)(param_1 + 0xac) = 1;
    (**(code **)(*(long *)param_1[0xab] + 0xf0))((long *)param_1[0xab],1000);
  }
  return (int)lVar2 != iVar1;
}

