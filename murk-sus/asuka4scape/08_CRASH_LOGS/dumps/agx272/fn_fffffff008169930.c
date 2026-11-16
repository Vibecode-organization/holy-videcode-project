// FUN_fffffff008169930 @ fffffff008169930 size=56

float FUN_fffffff008169930(long param_1,long param_2)

{
  return *(float *)(param_1 + 0x1ac00) *
         (float)((*(uint *)((ulong)*(uint *)(param_1 + 0x1ac0c) + param_2) >>
                  (ulong)(*(uint *)(param_1 + 0x1ac14) & 0x1f) & *(uint *)(param_1 + 0x1ac20)) + 1);
}

