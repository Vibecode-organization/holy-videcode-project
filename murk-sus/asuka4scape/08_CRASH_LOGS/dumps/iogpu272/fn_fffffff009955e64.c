// FUN_fffffff009955e64 @ fffffff009955e64 size=704

void FUN_fffffff009955e64(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 local_50;
  undefined8 local_48;
  
  if (*(byte *)(param_1 + 0x10) == 0x82) {
    uVar11 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x30) + 0x30) + 0x10);
    uVar1 = thunk_EXT_FUN_8011000002c1e35c(uVar11);
    uVar12 = *(undefined8 *)(param_1 + 0x78);
    uVar2 = thunk_EXT_FUN_8011000002c1e350(uVar11);
    iVar3 = thunk_EXT_FUN_8011000002c1e368(uVar11);
    uVar4 = thunk_EXT_FUN_8011000002c1e374(uVar11);
    thunk_EXT_FUN_80110000036da494(0x850900f4,uVar1,uVar12,uVar2,uVar4 & 0xffff | iVar3 << 0x10,0);
    lVar5 = thunk_EXT_FUN_8011000002c1e350(uVar11);
    iVar3 = thunk_EXT_FUN_8011000002c1e368(uVar11);
    uVar4 = thunk_EXT_FUN_8011000002c1e374(uVar11);
    local_50 = 0;
    local_48 = (ulong)local_48._4_4_ << 0x20;
    plVar6 = (long *)thunk_EXT_FUN_8011000002c24424
                               (uVar11,*(undefined8 *)PTR_DAT_fffffff007ff2810,&local_48);
    if (plVar6 != (long *)0x0) {
      plVar7 = (long *)thunk_EXT_FUN_8011000003890f30
                                 (plVar6,*(undefined8 *)PTR_DAT_fffffff007ff27b8);
      if (plVar7 != (long *)0x0) {
        (**(code **)(*plVar7 + 0x20))(plVar7);
      }
      uVar12 = (**(code **)(*plVar7 + 0xa8))(plVar7);
      thunk_EXT_FUN_80110000036dc388(0x85090128,&local_50,uVar12);
      (**(code **)(*plVar7 + 0x28))(plVar7);
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
    uVar1 = thunk_EXT_FUN_8011000002c1e35c(uVar11);
    uVar12 = thunk_EXT_FUN_8011000002c1e264(uVar11);
    local_48 = 0;
    thunk_EXT_FUN_80110000032db760(uVar12,&local_48);
    uVar12 = local_48;
    uVar8 = thunk_EXT_FUN_8011000002c1b1a8(uVar11);
    thunk_EXT_FUN_80110000036da494
              (0x8509011c,uVar1,uVar12,uVar8,(ulong)(uVar4 & 0xffff | iVar3 << 0x10) | lVar5 << 0x20
               ,0);
    uVar9 = thunk_EXT_FUN_8011000002c1e35c(uVar11);
    uVar9 = uVar9 & 0xffffffff;
    uVar11 = thunk_EXT_FUN_8011000002c1e264(uVar11);
    local_48 = 0;
    thunk_EXT_FUN_80110000032db760(uVar11,&local_48);
    uVar1 = 0x8509012c;
    uVar10 = 0;
    uVar11 = local_50;
  }
  else {
    if ((*(byte *)(param_1 + 0x10) & 0xf) != 0) {
      return;
    }
    thunk_EXT_FUN_80110000036da494
              (0x850900f0,*(undefined8 *)(param_1 + 0x70),*(undefined8 *)(param_1 + 0x78),
               *(undefined1 *)(param_1 + 0x84),
               (long)(int)((uint)*(ushort *)(param_1 + 0x80) << 0x10) |
               (ulong)*(ushort *)(param_1 + 0x82),0);
    uVar9 = *(ulong *)(param_1 + 0x70);
    uVar11 = (**(code **)(**(long **)(param_1 + 0x28) + 0xe0))();
    local_48 = 0;
    thunk_EXT_FUN_80110000032db760(uVar11,&local_48);
    uVar11 = *(undefined8 *)(param_1 + 0x78);
    uVar10 = (long)(int)((uint)*(ushort *)(param_1 + 0x80) << 0x10) |
             (ulong)*(ushort *)(param_1 + 0x82) | (ulong)*(byte *)(param_1 + 0x84) << 0x20;
    uVar1 = 0x85090130;
  }
  thunk_EXT_FUN_80110000036da494(uVar1,uVar9,local_48,uVar11,uVar10,0);
  return;
}

