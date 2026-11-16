// FUN_fffffff009962d08 @ fffffff009962d08 size=216

void FUN_fffffff009962d08(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x160));
  for (plVar6 = *(long **)(param_1 + 0x168); plVar6 != (long *)0x0; plVar6 = (long *)plVar6[6]) {
    if (plVar6[3] == param_2) {
      (**(code **)(*plVar6 + 0x90))(plVar6);
      FUN_fffffff00995db74(plVar6,param_3);
    }
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
  lVar5 = *(long *)(param_1 + 0x48);
  lVar4 = (long)*(int *)(param_2 + 0x424) * 0x18;
  lVar1 = lVar4 + 8;
  puVar2 = (undefined4 *)(lVar5 + (int)lVar1);
  if (lVar1 != (int)lVar1) {
    puVar2 = (undefined4 *)(lVar5 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar2 = (int)param_3;
  lVar4 = lVar4 + 0x10;
  puVar3 = (undefined1 *)(lVar5 + (int)lVar4);
  if (lVar4 != (int)lVar4) {
    puVar3 = (undefined1 *)(lVar5 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar3 = 1;
  return;
}

