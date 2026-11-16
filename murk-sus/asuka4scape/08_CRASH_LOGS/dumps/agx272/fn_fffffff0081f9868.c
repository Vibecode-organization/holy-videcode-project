// FUN_fffffff0081f9868 @ fffffff0081f9868 size=596

void FUN_fffffff0081f9868(undefined8 param_1,long param_2,undefined1 param_3)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  long lVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  uint uVar14;
  uint uVar15;
  ulong uVar16;
  byte bVar17;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 local_78;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff007ca61a0;
  uVar10 = thunk_EXT_FUN_801100000295198c();
  lVar11 = thunk_EXT_FUN_8011000003890f30(uVar10,&DAT_fffffff00ae238d8);
  uVar10 = 0;
  if (lVar11 != 0) {
    lVar11 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(lVar11 + 0x28),&DAT_fffffff00ae21bd0);
    uVar10 = 0;
    if (lVar11 != 0) {
      bVar1 = *(byte *)(param_2 + 0x10);
      uVar2 = *(ushort *)(param_2 + 0xc);
      uVar3 = *(undefined2 *)(param_2 + 8);
      uVar4 = *(undefined2 *)(param_2 + 10);
      uStack_88 = 0;
      local_90 = 0;
      local_78 = 0;
      uStack_80 = 0;
      uStack_98 = 0;
      local_a0 = 0;
      uVar16 = *(ulong *)(param_2 + 0x58);
      uVar15 = (uint)uVar16;
      uVar6 = uVar15 >> 0xf & 0xf;
      uVar7 = uVar15 >> 0x13 & 0xf;
      uVar8 = uVar15 >> 0x17 & 0xf;
      uVar14 = (uint)bVar1;
      if ((1 < uVar2 && bVar1 != 0) && (1 >= uVar2 || bVar1 != 1)) {
        uVar14 = 1;
      }
      if ((uVar15 >> 7 & 1) == 0) {
        iVar5 = (uint)*(byte *)(param_2 + 0x13) << (ulong)(uVar15 >> 1 & 7);
        bVar1 = (byte)(uVar15 >> 4) & 0xf;
        bVar17 = (byte)(uVar16 >> 0x1f) & 7;
        puVar12 = &local_a0;
      }
      else {
        uVar9 = uVar15 >> 1 & 7;
        bVar1 = (byte)(uVar15 >> 4) & 7;
        bVar17 = (byte)(uVar16 >> 0x1f) & 7;
        FUN_fffffff0081f9b00
                  (&local_a0,uVar3,uVar4,uVar6,uVar7,uVar14 * uVar2,
                   (uVar15 >> 8 & 3) + 1 << (ulong)uVar9,uVar8,bVar1,bVar17);
        iVar5 = (uVar15 >> 10 & 3) + 1 << (ulong)uVar9;
        puVar12 = &uStack_88;
      }
      FUN_fffffff0081f9b00(puVar12,uVar3,uVar4,uVar6,uVar7,uVar14 * uVar2,iVar5,uVar8,bVar1,bVar17);
      if ((uVar16 >> 0x22 & 1) == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = *(undefined8 *)(param_2 + 0x60);
      }
      *(undefined1 *)(lVar11 + 0xe8) = 2;
      *(undefined8 *)(lVar11 + 0xf8) = uStack_98;
      *(undefined8 *)(lVar11 + 0xf0) = local_a0;
      *(undefined8 *)(lVar11 + 0x100) = local_90;
      *(undefined8 *)(lVar11 + 0x118) = local_78;
      *(undefined8 *)(lVar11 + 0x110) = uStack_80;
      *(undefined8 *)(lVar11 + 0x108) = uStack_88;
      *(byte *)(lVar11 + 0x120) = (byte)(uVar15 >> 7) & 1;
      *(undefined1 *)(lVar11 + 0x121) = param_3;
      uVar10 = 1;
      *(undefined8 *)(lVar11 + 0x128) = uVar13;
    }
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_68) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar10);
  return;
}

