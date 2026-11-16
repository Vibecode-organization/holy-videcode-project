// FUN_fffffff00a6e3df8 @ fffffff00a6e3df8 size=1192
// CALLERS:
//   fffffff00afbc4db ?
//   fffffff00a6e3bfc FUN_fffffff00a6e3bd0@fffffff00a6e3bd0
//   fffffff00a6e5484 FUN_fffffff00a6e5270@fffffff00a6e5270
// CALLS:
//   fffffff00a389b14 FUN_fffffff00a389b14
//   fffffff00a2216c4 FUN_fffffff00a2216c4
//   fffffff00a6e22f8 FUN_fffffff00a6e22f8
//   fffffff00a6f8880 FUN_fffffff00a6f8880
//   fffffff00a275374 FUN_fffffff00a275374
//   fffffff00aa61ed0 FUN_fffffff00aa61ed0
//   fffffff00a28305c FUN_fffffff00a28305c
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a6ef900 FUN_fffffff00a6ef900
//   fffffff00a29762c FUN_fffffff00a29762c
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a2e6ce4 FUN_fffffff00a2e6ce4
//   fffffff00a29b24c FUN_fffffff00a29b24c
//   fffffff00a6e9a80 FUN_fffffff00a6e9a80

undefined8
FUN_fffffff00a6e3df8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 *param_8,undefined4 param_9,ulong *param_10,ulong param_11)

{
  undefined1 uVar1;
  undefined1 auVar2 [16];
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulong uVar7;
  long *plVar8;
  undefined **ppuVar9;
  ulong *puVar10;
  uint uVar11;
  ulong uVar12;
  uint uVar13;
  ulong uVar14;
  uint uVar15;
  uint in_wzr;
  long lVar16;
  undefined8 local_a0;
  long lStack_98;
  ulong local_90;
  undefined8 uStack_88;
  uint local_80;
  uint local_7c;
  uint uStack_78;
  uint local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  ulong local_60;
  undefined8 local_58;
  
  puVar10 = param_10;
  puVar5 = (undefined8 *)FUN_fffffff00a2216c4((undefined8 *)&DAT_fffffff007c78010,0x8004);
  puVar5[8] = param_7;
  puVar5[9] = param_8;
  *(undefined4 *)(puVar5 + 6) = param_9;
  puVar5[0x18] = 0;
  puVar5[0x19] = 0;
  uVar11 = DAT_fffffff00ad23d48;
  *(uint *)(puVar5 + 0x1a) = DAT_fffffff00ad23d48 & 0xffffff | 0x22000000;
  *(undefined4 *)((long)puVar5 + 0xd4) = 0;
  puVar5[0x1b] = 0;
  DAT_fffffff00ad23d54 = DAT_fffffff00ad23d54 + 1;
  if (((int)uVar11 < 0) &&
     (iVar3 = DAT_fffffff00ad23d44 + 1, uVar11 = DAT_fffffff00ad23d44 + 0xf0000001,
     DAT_fffffff00ad23d44 = iVar3, uVar11 < 0xf0000002)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa61ed0((uint *)&DAT_fffffff00ad23d44);
  }
  *(undefined4 *)((long)puVar5 + 0x2c) = 1;
  if ((param_7 == 0) || ((*(byte *)(param_7 + 0x444) >> 2 & 1) == 0)) {
    local_70 = 0;
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    local_74 = 0;
    local_80 = 0;
    local_7c = 0;
    lStack_98 = 0;
    local_a0 = 0;
    uVar6 = FUN_fffffff00a389b14(param_8,&local_a0,0x38,puVar10);
    if ((int)uVar6 != 0) goto LAB_fffffff00a6e3f28;
    *(undefined4 *)(puVar5 + 10) = (undefined4)local_a0;
    puVar5[0xb] = lStack_98;
    puVar5[0xc] = local_90 & 0xffffffff;
    puVar5[0xd] = local_90 >> 0x20;
    *(undefined4 *)(puVar5 + 0xe) = (undefined4)uStack_88;
    *(uint *)(puVar5 + 0x13) = (uint)local_70;
    *(uint *)(puVar5 + 0xf) = uStack_88._4_4_;
    *(uint *)((long)puVar5 + 0x7c) = local_80;
    puVar5[0x11] = (ulong)uStack_78;
    puVar5[0x10] = (ulong)local_7c;
    uVar7 = local_90 & 0xffffffff;
    uVar12 = local_90 >> 0x20;
    uVar14 = (ulong)local_74;
    uVar11 = uStack_88._4_4_;
    uVar4 = (uint)local_70;
    uVar13 = local_80;
  }
  else {
    uStack_68 = 0;
    local_70 = 0;
    local_58 = 0;
    local_60 = 0;
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    local_74 = 0;
    local_80 = 0;
    local_7c = 0;
    lStack_98 = 0;
    local_a0 = 0;
    uVar6 = FUN_fffffff00a389b14(param_8,&local_a0,0x50,puVar10);
    if ((int)uVar6 != 0) goto LAB_fffffff00a6e3f28;
    *(undefined4 *)(puVar5 + 10) = (undefined4)local_a0;
    puVar5[0xb] = lStack_98;
    puVar5[0xc] = local_90;
    puVar5[0xd] = uStack_88;
    *(uint *)(puVar5 + 0xe) = local_80;
    *(uint *)(puVar5 + 0x13) = (uint)local_58;
    *(uint *)(puVar5 + 0xf) = uStack_78;
    *(uint *)((long)puVar5 + 0x7c) = local_74;
    puVar5[0x11] = uStack_68;
    puVar5[0x10] = local_70;
    uVar7 = local_90;
    uVar12 = uStack_88;
    uVar14 = local_60;
    uVar11 = uStack_78;
    uVar4 = (uint)local_58;
    uVar13 = local_74;
  }
  puVar5[0x12] = uVar14;
  uVar15 = *(uint *)(puVar5 + 6);
  if ((uVar15 >> 4 & 1) == 0) {
LAB_fffffff00a6e3fbc:
    uVar4 = 0;
    if ((uVar15 & 0x8e) != 0) {
      uVar4 = 2;
    }
    if ((uVar15 & 0x41) != 0) {
      uVar4 = 1;
    }
    if ((((uVar15 & 3) != 0) &&
        (((uVar6 = 0x16, uVar12 >> 0x1f != 0 || (uVar7 == 0)) || (lStack_98 < 0)))) ||
       (((uVar15 & 0xc0) != 0 &&
        (((uVar6 = 0x16, uVar12 - 0x401 < 0xfffffffffffffc00 || (uVar7 == 0)) || (lStack_98 < 0)))))
       ) goto LAB_fffffff00a6e3f28;
    if (uVar11 != 0) {
      if (uVar11 == 4) {
        uVar6 = 0x16;
        if (((int)uVar13 < 1) || (DAT_fffffff00ad18808 < (int)uVar13)) goto LAB_fffffff00a6e3f28;
      }
      else if ((uVar11 != 1) || ((0x1e < uVar13 - 1 || ((uVar13 - 9 & 0xfffffff7) == 0))))
      goto LAB_fffffff00a6e4040;
    }
    lVar16 = tpidr_el1;
    if (*(ulong *)(param_7 + 0xd8) == 0) {
      *(ulong *)(param_7 + 0xd8) = (ulong)*(uint *)(lVar16 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(param_7 + 0xd0,lVar16,(undefined **)0x0);
    }
    uVar7 = FUN_fffffff00a6ef900(param_7,*(uint *)(puVar5 + 10));
    if ((uVar7 == 0) ||
       (((uVar15 & 0xcf) != 0 && ((*(uint *)(*(long *)(uVar7 + 0x10) + 0x10) & uVar4) == 0)))) {
      uVar6 = 9;
    }
    else {
      uVar11 = *(uint *)(puVar5 + 6);
      if (((uVar11 >> 1 & 1) != 0) && ((*(ushort *)(uVar7 + 10) >> 4 & 1) != 0)) {
        FUN_fffffff00a6f8880(param_7,(ulong)*(uint *)(puVar5 + 10),uVar7,0x40);
        uVar11 = *(uint *)(param_7 + 0xd8);
        if (uVar11 == *(uint *)(lVar16 + 0x4e8)) {
          *(uint *)(param_7 + 0xd8) = in_wzr;
          uVar6 = 1;
        }
        else {
          FUN_fffffff00a226e08(param_7 + 0xd0,lVar16,uVar11);
          uVar6 = 1;
        }
        goto LAB_fffffff00a6e3f28;
      }
      if (**(int **)(*(long *)(uVar7 + 0x10) + 0x28) == 1) {
        if (((uVar11 & 0x82) != 0) && ((*(byte *)(*(long *)(uVar7 + 0x10) + 0x10) >> 3 & 1) != 0)) {
          *(uint *)(puVar5 + 6) = uVar11 | 0x20000;
        }
        *(ushort *)(uVar7 + 8) = *(ushort *)(uVar7 + 8) | 8;
        uVar4 = *(uint *)(lVar16 + 0x4e8);
        uVar11 = *(uint *)(param_7 + 0xd8);
        if (uVar11 == uVar4) {
          *(uint *)(param_7 + 0xd8) = in_wzr;
        }
        ppuVar9 = (undefined **)(ulong)uVar11;
        if (uVar11 != uVar4) {
          FUN_fffffff00a226e08(param_7 + 0xd0,lVar16,uVar11);
        }
        plVar8 = FUN_fffffff00a29b24c();
        lVar16 = *plVar8;
        puVar5[0x15] = plVar8[1];
        puVar5[0x14] = lVar16;
        FUN_fffffff00a275374(puVar5[0x14]);
        auVar2 = FUN_fffffff00a6e9a80((undefined8 *)puVar5[0x15]);
        uVar4 = FUN_fffffff00a28305c
                          (auVar2,param_2,param_3,param_4,param_5,param_6,puVar5[0x14],(int *)0x0,
                           ppuVar9,(ulong)puVar10,param_11);
        uVar11 = 5;
        if (uVar4 != 6) {
          uVar11 = uVar4;
        }
        uVar1 = 4;
        if (uVar4 != 0) {
          uVar1 = (char)uVar11;
        }
        *(undefined1 *)(puVar5 + 0x16) = uVar1;
        if (DAT_fffffff007c06978 == 0) {
          lVar16 = 0;
          if ((*(byte *)(param_7 + 0x448) & 2) != 0) {
            lVar16 = param_7 + 0x768;
          }
          uVar7 = *(ulong *)(lVar16 + 0x28);
          if (uVar7 == 0) {
            uVar7 = 0;
          }
          puVar5[0x17] = uVar7;
          FUN_fffffff00a2e6ce4(uVar7);
        }
        else {
          puVar5[0x17] = 0;
          FUN_fffffff00a6e22f8(param_7);
        }
        *param_10 = (ulong)puVar5;
        return 0;
      }
      uVar6 = 0x1d;
    }
    uVar11 = *(uint *)(param_7 + 0xd8);
    if (uVar11 == *(uint *)(lVar16 + 0x4e8)) {
      *(uint *)(param_7 + 0xd8) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(param_7 + 0xd0,lVar16,uVar11);
    }
  }
  else {
    if (uVar4 < 5) {
      uVar15 = *(uint *)(&DAT_fffffff007027628 + (ulong)uVar4 * 4) | uVar15;
      *(uint *)(puVar5 + 6) = uVar15;
      goto LAB_fffffff00a6e3fbc;
    }
LAB_fffffff00a6e4040:
    uVar6 = 0x16;
  }
LAB_fffffff00a6e3f28:
  FUN_fffffff00a29762c((undefined8 *)&DAT_fffffff007c78010,puVar5);
  return uVar6;
}

