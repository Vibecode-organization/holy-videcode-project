// FUN_fffffff00994bf50 @ fffffff00994bf50 size=4

ulong FUN_fffffff00994bf50(long param_1,ulong param_2,uint param_3)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 uStack_48;
  
  do {
    if (0 < (int)param_3) {
      uVar3 = 0;
      do {
        uVar2 = param_2 + uVar3 * 0x40;
        if (((param_2 ^ uVar2) & 0xffc0000000000000) != 0) {
          uVar2 = uVar2 & 0xffffffffffff | 0xc8a2000000000000;
        }
        uVar2 = FUN_fffffff00994b4ec(param_1,uVar2);
        if (((uVar2 & 1) != 0) || (*(int *)(*(long *)(param_1 + 0x10) + 0x2d0) != 0)) {
          thunk_EXT_FUN_8011000003246024(param_1,0,0);
          return uVar3;
        }
        uVar3 = uVar3 + 1;
      } while (param_3 != uVar3);
    }
    uStack_48 = 0;
    thunk_EXT_FUN_8011000003204ed8(1,1000000000,&uStack_48);
    iVar1 = thunk_EXT_FUN_8011000003243438(param_1,0,uStack_48);
    if (iVar1 == -1) {
      thunk_EXT_FUN_8011000003247bfc(0);
    }
  } while( true );
}

