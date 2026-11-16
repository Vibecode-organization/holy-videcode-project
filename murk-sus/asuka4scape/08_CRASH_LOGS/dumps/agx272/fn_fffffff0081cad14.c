// FUN_fffffff0081cad14 @ fffffff0081cad14 size=136

bool FUN_fffffff0081cad14(long param_1,long *param_2,ulong param_3)

{
  long *plVar1;
  long lVar2;
  
  if (param_2 != (long *)0x0) {
    lVar2 = (param_3 & 0xffffffff) * 0x38;
    plVar1 = (long *)(param_1 + 0x1460 + (long)(int)lVar2);
    if (lVar2 - (int)lVar2 != 0) {
      plVar1 = (long *)(param_1 + 0x1460 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar1 = (long)param_2;
    (**(code **)(*param_2 + 0x540))(param_2,*(undefined8 *)(param_1 + 0x280),param_1);
  }
  return param_2 != (long *)0x0;
}

