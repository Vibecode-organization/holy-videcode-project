// FUN_fffffff008210f0c @ fffffff008210f0c size=380

void FUN_fffffff008210f0c(long param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0xc0));
  uVar7 = *(uint *)(param_1 + 0x3d8);
  if (uVar7 == 0x20) {
    FUN_fffffff00820f890(param_1);
    uVar7 = *(uint *)(param_1 + 0x3d8);
  }
  if (0x1f < uVar7) {
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! queueing too many unmaps (possbile failure to commit)!\n");
    return;
  }
  (**(code **)(*param_2 + 0x20))(param_2);
  iVar6 = (**(code **)(*param_2 + 0xd8))(param_2,0);
  if (iVar6 != 0) {
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! failed to prepare a descriptor in AGXUAT::unmap()!\n");
    return;
  }
  lVar1 = param_1 + 0xd8;
  uVar7 = *(uint *)(param_1 + 0x3d8);
  lVar8 = (ulong)uVar7 * 0x18;
  puVar4 = (undefined8 *)(lVar1 + (int)lVar8);
  if (lVar8 - (int)lVar8 != 0) {
    puVar4 = (undefined8 *)(lVar1 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
  }
  lVar2 = lVar8 + 8;
  puVar3 = (undefined8 *)(lVar1 + (int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar3 = (undefined8 *)(lVar1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar4 = param_2;
  lVar8 = lVar8 + 0x10;
  puVar4 = (undefined8 *)(lVar1 + (int)lVar8);
  if (lVar8 != (int)lVar8) {
    puVar4 = (undefined8 *)(lVar1 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar3 = param_3;
  *puVar4 = param_4;
  *(uint *)(param_1 + 0x3d8) = uVar7 + 1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008211034);
    (*pcVar5)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0xc0));
  return;
}

