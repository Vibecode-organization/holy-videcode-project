// FUN_fffffff00a798e5c @ fffffff00a798e5c size=148

undefined2 FUN_fffffff00a798e5c(long *param_1,ulong param_2,ulong param_3)

{
  undefined2 uVar1;
  ulong uVar2;
  long *plVar3;
  
  uVar2 = 0;
  plVar3 = param_1;
  do {
    if (plVar3 == (long *)0x0) break;
    uVar2 = (ulong)(uint)((int)plVar3[3] + (int)uVar2);
    plVar3 = (long *)*plVar3;
  } while (plVar3 != (long *)0x0);
  if ((param_3 & 0xffffffff) + (param_2 & 0xffffffff) <= uVar2) {
    uVar1 = FUN_fffffff00a1d23a0(param_1,param_3,param_2,0);
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114("%s: mbuf %p len (%u) < off+len (%u+%u) @%s:%d");
}

