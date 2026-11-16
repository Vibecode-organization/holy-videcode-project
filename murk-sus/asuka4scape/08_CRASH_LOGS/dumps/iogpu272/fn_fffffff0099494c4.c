// FUN_fffffff0099494c4 @ fffffff0099494c4 size=80

void FUN_fffffff0099494c4(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined8 local_28;
  
  local_28 = 0;
  iVar1 = FUN_fffffff0099681d8
                    (*(undefined8 *)(param_1 + 0x120),**(undefined8 **)(param_3 + 0x20),
                     (*(undefined8 **)(param_3 + 0x20))[1],&local_28);
  if (iVar1 == 0) {
    **(undefined8 **)(param_3 + 0x48) = local_28;
  }
  return;
}

