// FUN_fffffff009c211dc @ fffffff009c211dc size=372

undefined8 FUN_fffffff009c211dc(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int iVar4;
  ulong unaff_x30;
  long local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  if (param_2 == 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
    local_40 = 0;
    if (*(int *)(param_1 + 0x220) != 0) {
      iVar4 = *(int *)(param_1 + 0x224) + 1;
      do {
        *(int *)(param_1 + 0x224) = iVar4;
        thunk_EXT_FUN_80110000038ff064(*(undefined8 *)(param_1 + 0x50),param_1,0);
        iVar4 = *(int *)(param_1 + 0x224);
        *(int *)(param_1 + 0x224) = iVar4 + -1;
      } while (*(int *)(param_1 + 0x220) != 0);
    }
    FUN_fffffff009c16670(&local_40,*(undefined8 *)(param_1 + 0x38));
    lVar1 = local_40;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    if (lVar1 == 0) {
      FUN_fffffff009c16744(param_3,param_4);
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_fffffff009c2dbe0(lVar1,0,param_3,param_4);
      FUN_fffffff009c2da10(lVar1);
    }
  }
  else {
    if (param_2 == 2) {
      if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c21278);
          (*pcVar2)();
        }
        uVar3 = FUN_fffffff009c21350(param_1,param_4,param_3,FUN_fffffff009c21184);
        return uVar3;
      }
      goto LAB_fffffff009c2134c;
    }
    uVar3 = 0xe00002c7;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar3;
  }
LAB_fffffff009c2134c:
  uVar3 = thunk_EXT_FUN_8011000003a48590();
  return uVar3;
}

