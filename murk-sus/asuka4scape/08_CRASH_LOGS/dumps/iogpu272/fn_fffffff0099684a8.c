// FUN_fffffff0099684a8 @ fffffff0099684a8 size=256

undefined4
FUN_fffffff0099684a8(long param_1,int *param_2,undefined1 *param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int local_44;
  
  uVar1 = 0xe00002c1;
  lVar4 = *(long *)(*(long *)(param_1 + 0x48) + 0x108);
  iVar5 = param_5;
  if (lVar4 == 0) {
    iVar3 = thunk_EXT_FUN_80110000039a23f4(*(undefined8 *)(param_1 + 0x50),"foreground");
    bVar2 = iVar3 == -0x1ffffd3f;
    if (!bVar2) {
      iVar5 = param_4;
    }
    *param_2 = iVar5;
  }
  else {
    local_44 = 0;
    thunk_EXT_FUN_80110000039e11ac
              (lVar4,*(undefined8 *)(*(long *)(param_1 + 0x48) + 0x138),
               *(undefined8 *)(param_1 + 0x50),&local_44);
    *param_3 = 0;
    if (local_44 == 2) {
      *param_2 = param_5;
      bVar2 = true;
    }
    else if (local_44 == 3) {
      bVar2 = false;
      *param_2 = 2;
      *param_3 = 1;
      iVar5 = 2;
    }
    else {
      bVar2 = false;
      iVar5 = *param_2;
    }
  }
  if (iVar5 == 3) {
    *param_2 = 2;
  }
  if (!(bool)(param_5 == 3 & bVar2)) {
    uVar1 = 0;
  }
  return uVar1;
}

