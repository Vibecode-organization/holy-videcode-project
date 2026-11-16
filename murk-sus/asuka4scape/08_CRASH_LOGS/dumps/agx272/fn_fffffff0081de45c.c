// FUN_fffffff0081de45c @ fffffff0081de45c size=56

float FUN_fffffff0081de45c(long param_1,long param_2)

{
  return *(float *)(param_1 + 0x1ac00) *
         (float)((*(ulong *)((ulong)*(uint *)(param_1 + 0x1ac0c) + param_2) >>
                  ((ulong)*(uint *)(param_1 + 0x1ac14) & 0x3f) & (ulong)*(uint *)(param_1 + 0x1ac20)
                 ) + 1);
}

