// FUN_fffffff00819ec60 @ fffffff00819ec60 size=4

undefined8 FUN_fffffff00819ec60(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uStack_48;
  ulong uStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)PTR_DAT_fffffff007ca61a0;
  uVar2 = 0xe00002c2;
  puVar4 = *(undefined8 **)(param_3 + 0x10);
  if (puVar4 != (undefined8 *)0x0) {
    lVar3 = *(long *)(param_1 + 0x120);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x168));
    if ((*(byte *)(lVar3 + 0x170) & 1) == 0) {
      thunk_EXT_FUN_80110000039a2344(lVar3 + 0x128,*puVar4,puVar4[1],puVar4[2]);
      *(undefined1 *)(lVar3 + 0x170) = 1;
      uVar1 = *(uint *)(*(long *)(lVar3 + 0x48) + 0x111a0);
      if (uVar1 != 0) {
        uStack_48 = 0;
        uStack_40 = (ulong)uVar1;
        thunk_EXT_FUN_80110000039a40ec(lVar3 + 0x128,0,&uStack_48,2);
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x168));
      uVar2 = 0;
    }
    else {
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x168));
      uVar2 = 0xe00002c9;
    }
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 == lStack_38) {
    return uVar2;
  }
  uVar2 = thunk_EXT_FUN_8011000003a48590();
  return uVar2;
}

