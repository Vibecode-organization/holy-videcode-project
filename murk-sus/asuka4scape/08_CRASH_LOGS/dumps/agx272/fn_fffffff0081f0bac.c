// FUN_fffffff0081f0bac @ fffffff0081f0bac size=544

undefined8 FUN_fffffff0081f0bac(long param_1,long param_2,undefined8 param_3)

{
  ulong *puVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  ushort uVar7;
  ushort uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong local_40 [2];
  
  uVar5 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if ((int)uVar5 != 0) {
    *(long *)(param_1 + 0x10) = param_2;
    *(undefined8 *)(param_1 + 0x18) = param_3;
    *(undefined4 *)(param_1 + 0x48) = 0;
    if (*(long *)(param_1 + 0x38) != 0) {
      thunk_EXT_FUN_80110000038fe768
                (&DAT_fffffff007ca49b8,*(long *)(param_1 + 0x38),
                 (ulong)*(uint *)(param_1 + 0x40) * 0x68);
      param_2 = *(long *)(param_1 + 0x10);
    }
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined8 *)(param_1 + 0x4c) = 0xffffffff;
    *(undefined1 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
    lVar6 = *(long *)(*(long *)(param_2 + 0x4b0) + 0x910);
    *(char *)(lVar6 + 0x401c) = (char)*(undefined4 *)(param_2 + 0x414);
    *(char *)(lVar6 + 0x401d) = (char)*(undefined4 *)(param_2 + 0x42c);
    if ((*(byte *)(param_2 + 0x43a) & 1) == 0) {
      *(short *)(lVar6 + 0x401e) = (short)*(undefined4 *)(param_2 + 0x3e0);
      if (*(char *)(lVar6 + 0x401c) != '\0') {
        uVar9 = 0;
        do {
          *(ushort *)(lVar6 + 0x4020 + uVar9 * 2) =
               ~(ushort)(-1 << (ulong)(*(byte *)(lVar6 + 0x401d) & 0x1f));
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(byte *)(lVar6 + 0x401c));
      }
    }
    else {
      lVar3 = 0;
      if (*(long *)(param_2 + 0x3b8) == 0 && *(long *)(param_2 + 0x3b0) == 0) {
        lVar3 = 0x10;
      }
      puVar1 = (ulong *)(param_2 + 0x3b0 + lVar3);
      uVar10 = *puVar1;
      uVar9 = puVar1[1];
      *(ushort *)(lVar6 + 0x401e) =
           (ushort)(byte)(POPCOUNT((char)uVar9) + POPCOUNT((char)(uVar9 >> 8)) +
                          POPCOUNT((char)(uVar9 >> 0x10)) + POPCOUNT((char)(uVar9 >> 0x18)) +
                          POPCOUNT((char)(uVar9 >> 0x20)) + POPCOUNT((char)(uVar9 >> 0x28)) +
                          POPCOUNT((char)(uVar9 >> 0x30)) + POPCOUNT((char)(uVar9 >> 0x38))) +
           (ushort)(byte)(POPCOUNT((char)uVar10) + POPCOUNT((char)(uVar10 >> 8)) +
                          POPCOUNT((char)(uVar10 >> 0x10)) + POPCOUNT((char)(uVar10 >> 0x18)) +
                          POPCOUNT((char)(uVar10 >> 0x20)) + POPCOUNT((char)(uVar10 >> 0x28)) +
                          POPCOUNT((char)(uVar10 >> 0x30)) + POPCOUNT((char)(uVar10 >> 0x38)));
      if (*(char *)(lVar6 + 0x401c) != '\0') {
        uVar9 = 0;
        do {
          uVar4 = (int)uVar9 * (uint)*(byte *)(lVar6 + 0x401d);
          local_40[1] = puVar1[1];
          local_40[0] = *puVar1;
          uVar2 = uVar4 & 0x3f;
          if (uVar2 == 0) {
            if (uVar4 < 0x80) {
              uVar8 = (ushort)local_40[uVar4 >> 6];
            }
            else {
              uVar8 = 0;
            }
          }
          else if (uVar4 < 0x80) {
            if (uVar4 < 0x40) {
              uVar8 = (ushort)(puVar1[1] << ((ulong)(0x40 - uVar2) & 0x3f)) |
                      (ushort)(local_40[uVar4 >> 6] >> uVar2);
            }
            else {
              uVar8 = (ushort)(local_40[uVar4 >> 6] >> uVar2);
            }
          }
          else {
            uVar8 = (ushort)(0L >> uVar2);
          }
          uVar7 = 0xffff;
          if (*(byte *)(lVar6 + 0x401d) < 0x40) {
            uVar7 = ~(ushort)(-1L << ((ulong)*(byte *)(lVar6 + 0x401d) & 0x3f));
          }
          *(ushort *)(lVar6 + 0x4020 + uVar9 * 2) = uVar8 & uVar7;
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(byte *)(lVar6 + 0x401c));
      }
    }
  }
  return uVar5;
}

