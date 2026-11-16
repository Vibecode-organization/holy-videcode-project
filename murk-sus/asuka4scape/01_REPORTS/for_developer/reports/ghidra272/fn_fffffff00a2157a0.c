// FUN_fffffff00a2157a0 @ fffffff00a2157a0 size=312

undefined8 FUN_fffffff00a2157a0(long param_1,undefined8 param_2,uint param_3,undefined8 *param_4)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  int in_wzr;
  
  if (param_1 == 0) {
    return 4;
  }
  if (param_3 - 0x25 < 0xffffffdc) {
    return 4;
  }
  lVar1 = tpidr_el1;
  if (*(ulong *)(param_1 + 8) == 0) {
    *(ulong *)(param_1 + 8) = (ulong)*(uint *)(lVar1 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(param_1,lVar1,0);
  }
  lVar3 = *(long *)(&DAT_fffffff00ad34850 + (ulong)param_3 * 8);
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  if (param_3 == 3) {
    uVar2 = FUN_fffffff00a1f45e4(DAT_fffffff007c37d60);
  }
  else if (param_3 == 2) {
    uVar2 = FUN_fffffff00a217f70(lVar3,&DAT_fffffff00ad34840,0x19);
  }
  else if (param_3 == 1) {
    uVar2 = FUN_fffffff00a217f70(lVar3,&DAT_fffffff00ad34840,0x18);
  }
  else {
    uVar2 = FUN_fffffff00a1f472c();
  }
  *param_4 = uVar2;
  if (*(int *)(param_1 + 8) == *(int *)(lVar1 + 0x4e8)) {
    *(int *)(param_1 + 8) = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(param_1,lVar1);
  }
  return 0;
}

