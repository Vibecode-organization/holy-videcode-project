// FUN_fffffff00994858c @ fffffff00994858c size=4

void FUN_fffffff00994858c(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined8 uStack_28;
  
  uStack_28 = 0;
  iVar1 = FUN_fffffff00996810c
                    (*(undefined8 *)(param_1 + 0x120),*(undefined8 *)(param_3 + 0x30),&uStack_28);
  if (iVar1 == 0) {
    **(undefined8 **)(param_3 + 0x48) = uStack_28;
  }
  return;
}

