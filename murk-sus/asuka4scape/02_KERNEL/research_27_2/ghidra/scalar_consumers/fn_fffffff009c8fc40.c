// FUN_fffffff009c8fc40 @ fffffff009c8fc40

/* WARNING: Removing unreachable block (ram,0xfffffff009c8fd0c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c8fcbc) */

undefined8 FUN_fffffff009c8fc40(long *param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  long *plVar2;
  
  if ((param_3 == -0x1ffffdb0 || param_3 == -0x1ffffcf0) || param_3 == -0x1ffffdab) {
    plVar2 = (long *)param_1[0x11];
    lVar1 = *(long *)(*param_1 + 0x678);
    if ((lVar1 == 0) && (lVar1 = thunk_FUN_fffffff00a894f04(param_1,-0xff6370298), lVar1 == 0)) {
      lVar1 = 0;
    }
    (**(code **)(*plVar2 + 0xe8))(plVar2,lVar1,0,0,0,0);
  }
  return 0;
}

