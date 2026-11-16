// FUN_fffffff00a232c9c @ fffffff00a232c9c size=152

void FUN_fffffff00a232c9c(ushort *param_1)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 2);
  *(uint *)(param_1 + 2) = uVar2 & 0xfffffff7;
  if (((uVar2 ^ 0xffffffff) & 10) != 0) {
    return;
  }
  uVar1 = *param_1;
  if (uVar1 - 2 < 2) {
    FUN_fffffff00a24b5a0(param_1,*(undefined8 *)(param_1 + 8));
    return;
  }
  if (uVar1 == 4) {
    FUN_fffffff00a27b76c(*(undefined8 *)(param_1 + 8),0);
    return;
  }
  if (uVar1 == 1) {
    FUN_fffffff00a232c28(*(undefined8 *)(param_1 + 8),param_1 + 0x14);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114("mpsc_queue[%p]: invalid kind (%d) @%s:%d");
}

