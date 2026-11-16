// FUN_fffffff00996caf4 @ fffffff00996caf4 size=88

void FUN_fffffff00996caf4(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = 0;
  lVar2 = 5;
  do {
    thunk_EXT_FUN_80110000039b41ec
              (*(undefined8 *)(param_1 + 0x28),(&DAT_fffffff007fed740)[lVar1 * 2],
               (&DAT_fffffff007fed748)[lVar1 * 2]);
    lVar1 = lVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}

