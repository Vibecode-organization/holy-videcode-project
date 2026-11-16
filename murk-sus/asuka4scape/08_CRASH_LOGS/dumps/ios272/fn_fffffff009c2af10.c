// FUN_fffffff009c2af10 @ fffffff009c2af10 size=500

void FUN_fffffff009c2af10(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined1 *local_60;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  FUN_fffffff009c2adb0(param_1);
  uVar4 = (**(code **)(**(long **)(param_1 + 0x3c8) + 0x90))();
  plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(uVar4 >> 1 & 0x7fffffff);
  if ((int)uVar4 != 0) {
    iVar2 = 0;
    do {
      uVar6 = (**(code **)(**(long **)(param_1 + 0x3c8) + 0x118))(*(long **)(param_1 + 0x3c8),iVar2)
      ;
      if ((param_2 == 0) || (iVar1 = FUN_fffffff009c48d20(uVar6), iVar1 != 0)) {
        (**(code **)(*plVar5 + 0xe8))(plVar5,uVar6);
      }
      iVar2 = iVar2 + 1;
    } while ((int)uVar4 != iVar2);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  iVar2 = (**(code **)(*plVar5 + 0x90))(plVar5);
  if (iVar2 != 0) {
    iVar1 = 0;
    do {
      uVar6 = (**(code **)(*plVar5 + 0x118))(plVar5,iVar1);
      uVar7 = FUN_fffffff009c48cfc();
      do {
        local_60 = &DAT_aaaaaaaaaaaaaaaa;
        thunk_EXT_FUN_8011000003204ed8(5,1000000000,&local_60);
        uVar8 = FUN_fffffff009c48d14(uVar6);
        iVar3 = FUN_fffffff009c172ec(uVar7,uVar8,local_60);
      } while (iVar3 == 0);
      iVar1 = iVar1 + 1;
    } while (iVar1 != iVar2);
  }
  (**(code **)(*plVar5 + 0x28))(plVar5);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

