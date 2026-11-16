// FUN_fffffff009c29ee4 @ fffffff009c29ee4 size=1248

/* WARNING: Removing unreachable block (ram,0xfffffff009c29f74) */

undefined8 FUN_fffffff009c29ee4(long param_1,undefined8 param_2)

{
  ulong *puVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  
  uVar5 = FUN_fffffff009c2e900(param_2);
  *(undefined4 *)(param_1 + 0x80) = uVar5;
  uVar5 = FUN_fffffff009c2e9a8(param_2);
  *(undefined4 *)(param_1 + 0x98) = uVar5;
  iVar6 = FUN_fffffff009c2e960(param_2);
  uVar11 = 0x200;
  if (iVar6 == 0) {
    uVar11 = 0;
  }
  *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffdff | uVar11;
  uVar3 = FUN_fffffff009c2e960(param_2);
  *(undefined1 *)(*(long *)(param_1 + 0x178) + 0x14) = uVar3;
  iVar6 = FUN_fffffff009c2e974(param_2);
  uVar11 = 0x400000;
  if (iVar6 == 0) {
    uVar11 = 0;
  }
  *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xffbfffff | uVar11;
  uVar7 = FUN_fffffff009c2e950(param_2);
  *(ulong *)(param_1 + 0x90) = uVar7 & 0xffffffff;
  uVar7 = FUN_fffffff009c2e910(param_2);
  *(ulong *)(param_1 + 0x58) = uVar7 & 0xffffffff;
  uVar7 = FUN_fffffff009c2e920(param_2);
  *(ulong *)(param_1 + 0x60) = uVar7 & 0xffffffff;
  uVar7 = FUN_fffffff009c2e9b8(param_2);
  *(ulong *)(param_1 + 0x78) = uVar7 & 0xffffffff;
  uVar3 = FUN_fffffff009c2e930(param_2);
  *(undefined1 *)(param_1 + 0x72) = uVar3;
  uVar3 = FUN_fffffff009c2e940(param_2);
  *(undefined1 *)(param_1 + 0x73) = uVar3;
  uVar7 = FUN_fffffff009c2e988(param_2);
  *(ulong *)(param_1 + 0x68) = uVar7 & 0xffffffff;
  uVar4 = FUN_fffffff009c2e998(param_2);
  *(undefined2 *)(param_1 + 0x70) = uVar4;
  uVar5 = FUN_fffffff009c2efa4(param_2);
  *(undefined4 *)(param_1 + 0x3b8) = uVar5;
  uVar11 = 0;
  if (*(uint *)(param_1 + 0x98) != 0) {
    if (3 < *(uint *)(param_1 + 0x98)) {
      return 0;
    }
    *(long *)(param_1 + 0x180) = param_1 + 0xa8;
    *(undefined4 *)(param_1 + 0x188) = 3;
    iVar6 = FUN_fffffff009c2ec70(param_2,0);
    uVar9 = *(uint *)(param_1 + 0x98);
    if (iVar6 != 0) {
      lVar8 = thunk_EXT_FUN_80110000038fe5cc((ulong)uVar9 * 0x3c);
      uVar9 = *(uint *)(param_1 + 0x98);
      *(long *)(param_1 + 0x308) = lVar8;
      *(uint *)(param_1 + 0x310) = uVar9;
      if (lVar8 == 0) {
        return 0;
      }
    }
    uVar11 = 0;
    if (uVar9 != 0) {
      lVar8 = 0;
      uVar13 = 0;
      uVar7 = 0;
      lVar14 = 0;
      uVar11 = 0;
      do {
        uVar10 = *(ulong *)(param_1 + 0x180);
        uVar12 = uVar10 + (ulong)*(uint *)(param_1 + 0x188) * 0x38;
        if (((uVar10 ^ uVar12) & 0xffc0000000000000) != 0) {
          uVar12 = uVar12 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar12 < uVar10) || (uVar12 - uVar10 >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
LAB_fffffff009c2a3a8:
          FUN_fffffff009c48f3c();
LAB_fffffff009c2a3ac:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (lVar8 != (int)lVar8) goto LAB_fffffff009c2a3a8;
        if (((long)uVar13 < 0) || ((uint)(uVar12 - uVar10) < (int)(uVar13 >> 0x20) + 0x38U))
        goto LAB_fffffff009c2a3ac;
        puVar1 = (ulong *)(uVar10 + (uVar13 >> 0x20));
        uVar10 = (ulong)CARRY8(uVar10,uVar13 >> 0x20);
        uVar12 = -uVar10;
        if ((uVar12 != uVar10) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar12 = FUN_fffffff009c2e9c8(param_2,uVar11);
        *puVar1 = uVar12 & 0xffffffff;
        uVar12 = FUN_fffffff009c2ea08(param_2,uVar11);
        puVar1[1] = uVar12 & 0xffffffff;
        uVar3 = FUN_fffffff009c2ea4c(param_2,uVar11);
        *(undefined1 *)((long)puVar1 + 0x34) = uVar3;
        uVar3 = FUN_fffffff009c2ea90(param_2,uVar11);
        *(undefined1 *)((long)puVar1 + 0x35) = uVar3;
        uVar12 = FUN_fffffff009c2ead4(param_2,uVar11);
        puVar1[2] = uVar12 & 0xffffffff;
        uVar12 = FUN_fffffff009c2eb18(param_2,uVar11);
        puVar1[3] = uVar12 & 0xffffffff;
        uVar12 = FUN_fffffff009c2ebe8(param_2,uVar11);
        puVar1[5] = uVar12 & 0xffffffff;
        uVar12 = FUN_fffffff009c2eb60(param_2,uVar11);
        puVar1[4] = uVar12 & 0xffffffff;
        uVar4 = FUN_fffffff009c2eba4(param_2,uVar11);
        *(undefined2 *)(puVar1 + 6) = uVar4;
        uVar3 = FUN_fffffff009c2ec2c(param_2,uVar11);
        *(undefined1 *)((long)puVar1 + 0x36) = uVar3;
        uVar12 = *(ulong *)(param_1 + 0x308);
        if (uVar12 != 0) {
          uVar10 = uVar12 + (ulong)*(uint *)(param_1 + 0x310) * 0x3c;
          if (((uVar12 ^ uVar10) & 0xffc0000000000000) != 0) {
            uVar10 = uVar10 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar10 < uVar12) || (uVar10 - uVar12 >> 0x20 != 0)) {
            FUN_fffffff009c48f64();
          }
          else if (uVar7 == (long)(int)uVar7) {
            if ((lVar14 < 0) || ((uint)(uVar10 - uVar12) < (int)uVar7 + 0x3cU))
            goto LAB_fffffff009c2a3bc;
            puVar2 = (undefined4 *)(uVar12 + uVar7);
            uVar10 = -(ulong)CARRY8(uVar12,uVar7);
            if ((uVar10 != CARRY8(uVar12,uVar7)) || ((long)uVar10 < 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f50();
            }
            uVar5 = FUN_fffffff009c2ee0c(param_2,uVar11);
            puVar2[5] = uVar5;
            uVar5 = FUN_fffffff009c2ee50(param_2,uVar11);
            puVar2[6] = uVar5;
            uVar5 = FUN_fffffff009c2ed84(param_2,uVar11);
            *puVar2 = uVar5;
            uVar5 = FUN_fffffff009c2edc8(param_2,uVar11);
            puVar2[1] = uVar5;
            uVar3 = FUN_fffffff009c2ec70(param_2,uVar11);
            *(undefined1 *)(puVar2 + 8) = uVar3;
            uVar3 = FUN_fffffff009c2ecb4(param_2,uVar11);
            *(undefined1 *)(puVar2 + 10) = uVar3;
            uVar5 = FUN_fffffff009c2ecfc(param_2,uVar11);
            puVar2[3] = uVar5;
            uVar5 = FUN_fffffff009c2ed40(param_2,uVar11);
            puVar2[2] = uVar5;
            uVar5 = FUN_fffffff009c2ee94(param_2,uVar11);
            puVar2[4] = uVar5;
            uVar5 = FUN_fffffff009c2eed8(param_2,uVar11);
            puVar2[0xb] = uVar5;
            uVar5 = FUN_fffffff009c2ef1c(param_2,uVar11);
            puVar2[0xc] = uVar5;
            uVar5 = FUN_fffffff009c2ef60(param_2,uVar11);
            puVar2[7] = uVar5;
            uVar5 = FUN_fffffff009c2efbc(param_2,uVar11);
            puVar2[0xd] = uVar5;
            uVar5 = FUN_fffffff009c2f000(param_2,uVar11);
            puVar2[0xe] = uVar5;
            goto LAB_fffffff009c2a300;
          }
          FUN_fffffff009c48f3c();
LAB_fffffff009c2a3bc:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
LAB_fffffff009c2a300:
        lVar14 = lVar14 + 0x3c00000000;
        uVar7 = uVar7 + 0x3c;
        uVar13 = uVar13 + 0x3800000000;
        lVar8 = lVar8 + 0x38;
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)(param_1 + 0x98));
      uVar11 = *(uint *)(param_1 + 0x98) << 8;
    }
  }
  thunk_EXT_FUN_80110000036da494
            (0x5400010,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x80),
             *(undefined8 *)(param_1 + 0x90),*(uint *)(param_1 + 0x3d0) >> 9 & 1 | uVar11,0);
  thunk_EXT_FUN_80110000036da494
            (0x5400014,*(undefined4 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x58),
             *(undefined8 *)(param_1 + 0x60),
             (long)(int)((uint)*(byte *)(param_1 + 0x72) << 0x18) |
             (ulong)*(byte *)(param_1 + 0x73) << 0x10 | (ulong)*(ushort *)(param_1 + 0x70),0);
  return 1;
}

