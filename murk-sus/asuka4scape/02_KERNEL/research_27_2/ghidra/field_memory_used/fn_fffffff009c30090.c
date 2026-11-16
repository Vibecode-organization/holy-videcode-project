// FUN_fffffff009c30090 @ fffffff009c30090

undefined8 FUN_fffffff009c30090(long param_1,long param_2)

{
  undefined8 uVar1;
  
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x18));
  uVar1 = (**(code **)(**(long **)(param_1 + 0x30) + 0xb8))
                    (*(long **)(param_1 + 0x30),*(undefined8 *)(param_2 + 0x88),
                     *(undefined8 *)(param_2 + 0x90));
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x18));
  return uVar1;
}

