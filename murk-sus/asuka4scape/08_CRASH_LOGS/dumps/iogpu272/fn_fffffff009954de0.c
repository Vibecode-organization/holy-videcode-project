// FUN_fffffff009954de0 @ fffffff009954de0 size=328

void FUN_fffffff009954de0(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 local_58;
  
  if (*(char *)(param_1 + 0x10) == -0x7e) {
    lVar7 = *(long *)(*(long *)(*(long *)(param_1 + 0x30) + 0x30) + 0x10);
    uVar4 = thunk_EXT_FUN_8011000002c1e35c(lVar7);
    uVar4 = uVar4 & 0xffffffff;
    uVar5 = thunk_EXT_FUN_8011000002c1e368(lVar7);
    uVar2 = thunk_EXT_FUN_8011000002c1e374(lVar7);
  }
  else {
    lVar7 = 0;
    uVar4 = 0;
    uVar5 = (ulong)*(ushort *)(param_1 + 0x80);
    uVar2 = (uint)*(ushort *)(param_1 + 0x82);
  }
  if (DAT_fffffff00af227e8 != 0) {
    thunk_EXT_FUN_80110000036da494
              ((param_3 & 1) << 2 | 0x85180060,*(undefined8 *)(param_2 + 0x30),
               *(undefined8 *)(param_1 + 0x70),*(undefined8 *)(param_2 + 0x28),
               uVar5 << 0x30 | (ulong)(uVar2 & 0xffff) << 0x20 | uVar4,0);
  }
  if (lVar7 != 0) {
    uVar1 = (param_3 & 1) << 2 | 0x85090010;
    uVar8 = *(undefined8 *)(param_1 + 0x70);
    uVar6 = thunk_EXT_FUN_8011000002c1e264(lVar7);
    local_58 = 0;
    thunk_EXT_FUN_80110000032db760(uVar6,&local_58);
    thunk_EXT_FUN_80110000036da494(uVar1 + 0x110,uVar8,uVar4,local_58,0,0);
    uVar6 = *(undefined8 *)(param_2 + 0x30);
    uVar3 = thunk_EXT_FUN_8011000002c1e350(lVar7);
    thunk_EXT_FUN_80110000036da494
              (uVar1,uVar6,uVar4,uVar3,(long)(int)(uVar2 & 0xffff | (int)uVar5 << 0x10),0);
  }
  return;
}

