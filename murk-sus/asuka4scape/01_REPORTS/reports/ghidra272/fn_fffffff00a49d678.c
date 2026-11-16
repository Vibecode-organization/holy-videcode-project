// FUN_fffffff00a49d678 @ fffffff00a49d678 size=2048

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a49d678(long param_1,long param_2,long param_3)

{
  ulong *puVar1;
  ulong uVar2;
  int iVar3;
  byte bVar4;
  undefined8 uVar5;
  code *pcVar6;
  uint uVar7;
  long *plVar8;
  long lVar9;
  undefined8 *puVar10;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  int *piVar14;
  int in_wzr;
  
  if (param_3 == 0) {
LAB_fffffff00a49d7ac:
    lVar9 = *(long *)(param_1 + 0x108);
  }
  else {
    lVar9 = tpidr_el1;
    *(int *)(lVar9 + 0x1c0) = *(int *)(lVar9 + 0x1c0) + 1;
    if (*(ulong *)(param_3 + 0x68) == 0) {
      *(ulong *)(param_3 + 0x68) = (ulong)*(uint *)(lVar9 + 0x4e8) | 0x30000000;
      uVar11 = DAT_fffffff00ad7cd2c;
    }
    else {
      FUN_fffffff00a2262d4(param_3 + 0x60,lVar9,1);
      uVar11 = DAT_fffffff00ad7cd2c;
    }
    DAT_fffffff00ad7cd2c = uVar11;
    if ((uVar11 & 1) != 0) {
      uVar7 = *(uint *)(param_3 + 0x378);
      *(uint *)(param_3 + 0x378) = uVar7 + 1;
      if ((uVar11 >> 1 & 1) != 0) {
        plVar8 = (long *)(param_3 + 0x650U) + (ulong)(uVar7 & 3) * 9;
        if ((plVar8 != (long *)0x0) &&
           ((long *)(param_3 + 0x770U) <= plVar8 || plVar8 < (long *)(param_3 + 0x650U)))
        goto LAB_fffffff00a49db6c;
        *plVar8 = lVar9;
        plVar8[4] = 0;
        plVar8[3] = 0;
        plVar8[6] = 0;
        plVar8[5] = 0;
        plVar8[8] = 0;
        plVar8[7] = 0;
        plVar8[2] = 0;
        plVar8[1] = 0;
        FUN_fffffff00a8949d8(plVar8 + 1,8);
      }
    }
    FUN_fffffff00a49b804(param_3);
    uVar11 = DAT_fffffff00ad7cd2c;
    if ((DAT_fffffff00ad7cd2c & 1) != 0) {
      uVar7 = *(uint *)(param_3 + 0x37c);
      *(uint *)(param_3 + 0x37c) = uVar7 + 1;
      if ((uVar11 >> 1 & 1) != 0) {
        plVar8 = (long *)(param_3 + 0x770U) + (ulong)(uVar7 & 3) * 9;
        if ((plVar8 != (long *)0x0) &&
           ((long *)(param_3 + 0x890U) <= plVar8 || plVar8 < (long *)(param_3 + 0x770U)))
        goto LAB_fffffff00a49db6c;
        *plVar8 = lVar9;
        plVar8[4] = 0;
        plVar8[3] = 0;
        plVar8[6] = 0;
        plVar8[5] = 0;
        plVar8[8] = 0;
        plVar8[7] = 0;
        plVar8[2] = 0;
        plVar8[1] = 0;
        FUN_fffffff00a8949d8(plVar8 + 1,8);
      }
    }
    if (*(int *)(param_3 + 0x68) == *(int *)(lVar9 + 0x4e8)) {
      *(int *)(param_3 + 0x68) = in_wzr;
      goto LAB_fffffff00a49d7ac;
    }
    FUN_fffffff00a226e08(param_3 + 0x60,lVar9);
    lVar9 = *(long *)(param_1 + 0x108);
  }
  if (lVar9 != 0) {
    if (param_1 == lVar9) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("rt != ogwrt",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/net/route.c"
                 ,0xc3f);
    }
    *(undefined8 *)(param_1 + 0x108) = 0;
    uVar11 = DAT_fffffff00ad7cd2c;
    if ((DAT_fffffff00ad7cd2c & 1) != 0) {
      uVar7 = *(uint *)(param_1 + 0x37c);
      *(uint *)(param_1 + 0x37c) = uVar7 + 1;
      if ((uVar11 >> 1 & 1) != 0) {
        puVar10 = (undefined8 *)(param_1 + 0x770U) + (ulong)(uVar7 & 3) * 9;
        if ((puVar10 != (undefined8 *)0x0) &&
           ((undefined8 *)(param_1 + 0x890U) <= puVar10 ||
            puVar10 < (undefined8 *)(param_1 + 0x770U))) goto LAB_fffffff00a49db6c;
        uVar5 = tpidr_el1;
        *puVar10 = uVar5;
        puVar10[4] = 0;
        puVar10[3] = 0;
        puVar10[6] = 0;
        puVar10[5] = 0;
        puVar10[8] = 0;
        puVar10[7] = 0;
        puVar10[2] = 0;
        puVar10[1] = 0;
        FUN_fffffff00a8949d8(puVar10 + 1,8);
      }
    }
    lVar12 = tpidr_el1;
    puVar1 = (ulong *)(param_1 + 0x68);
    if (*(int *)puVar1 == *(int *)(lVar12 + 0x4e8)) {
      *(int *)puVar1 = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(param_1 + 0x60,lVar12);
    }
    FUN_fffffff00a498684(lVar9,1);
    if (*puVar1 == 0) {
      *puVar1 = (ulong)*(uint *)(lVar12 + 0x4e8);
      uVar11 = DAT_fffffff00ad7cd2c;
    }
    else {
      FUN_fffffff00a2262d4(param_1 + 0x60,lVar12,0);
      uVar11 = DAT_fffffff00ad7cd2c;
    }
    DAT_fffffff00ad7cd2c = uVar11;
    if ((uVar11 & 1) != 0) {
      uVar7 = *(uint *)(param_1 + 0x378);
      *(uint *)(param_1 + 0x378) = uVar7 + 1;
      if ((uVar11 >> 1 & 1) != 0) {
        plVar8 = (long *)(param_1 + 0x650U) + (ulong)(uVar7 & 3) * 9;
        if ((plVar8 != (long *)0x0) &&
           (((long *)(param_1 + 0x770U) <= plVar8 || (plVar8 < (long *)(param_1 + 0x650U)))))
        goto LAB_fffffff00a49db6c;
        *plVar8 = lVar12;
        plVar8[4] = 0;
        plVar8[3] = 0;
        plVar8[6] = 0;
        plVar8[5] = 0;
        plVar8[8] = 0;
        plVar8[7] = 0;
        plVar8[2] = 0;
        plVar8[1] = 0;
        FUN_fffffff00a8949d8(plVar8 + 1,8);
      }
    }
    if (*(long *)(param_1 + 0x108) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa5d948
                ("rt->rt_gwroute == NULL",
                 "/Library/Caches/com.apple.xbs/FBE73862-C372-4A76-BC3C-8E79BBE064EA/TemporaryDirectory.14N5mt/Sources/xnu/bsd/net/route.c"
                 ,0xc44);
    }
  }
  *(long *)(param_1 + 0x108) = param_3;
  if (param_3 == 0) {
    return;
  }
  lVar9 = tpidr_el1;
  *(int *)(lVar9 + 0x1c0) = *(int *)(lVar9 + 0x1c0) + 1;
  if (*(ulong *)(param_3 + 0x68) == 0) {
    *(ulong *)(param_3 + 0x68) = (ulong)*(uint *)(lVar9 + 0x4e8) | 0x30000000;
    uVar11 = DAT_fffffff00ad7cd2c;
  }
  else {
    FUN_fffffff00a2262d4(param_3 + 0x60,lVar9,1);
    uVar11 = DAT_fffffff00ad7cd2c;
  }
  DAT_fffffff00ad7cd2c = uVar11;
  if ((uVar11 & 1) != 0) {
    uVar7 = *(uint *)(param_3 + 0x378);
    *(uint *)(param_3 + 0x378) = uVar7 + 1;
    if ((uVar11 >> 1 & 1) != 0) {
      plVar8 = (long *)(param_3 + 0x650U) + (ulong)(uVar7 & 3) * 9;
      if ((plVar8 != (long *)0x0) &&
         ((long *)(param_3 + 0x770U) <= plVar8 || plVar8 < (long *)(param_3 + 0x650U)))
      goto LAB_fffffff00a49db6c;
      *plVar8 = lVar9;
      plVar8[4] = 0;
      plVar8[3] = 0;
      plVar8[6] = 0;
      plVar8[5] = 0;
      plVar8[8] = 0;
      plVar8[7] = 0;
      plVar8[2] = 0;
      plVar8[1] = 0;
      FUN_fffffff00a8949d8(plVar8 + 1,8);
    }
  }
  FUN_fffffff00a49b804(param_3);
  uVar11 = DAT_fffffff00ad7cd2c;
  if ((DAT_fffffff00ad7cd2c & 1) != 0) {
    uVar7 = *(uint *)(param_3 + 0x37c);
    *(uint *)(param_3 + 0x37c) = uVar7 + 1;
    if ((uVar11 >> 1 & 1) != 0) {
      plVar8 = (long *)(param_3 + 0x770U) + (ulong)(uVar7 & 3) * 9;
      if ((plVar8 != (long *)0x0) &&
         ((long *)(param_3 + 0x890U) <= plVar8 || plVar8 < (long *)(param_3 + 0x770U)))
      goto LAB_fffffff00a49db6c;
      *plVar8 = lVar9;
      plVar8[4] = 0;
      plVar8[3] = 0;
      plVar8[6] = 0;
      plVar8[5] = 0;
      plVar8[8] = 0;
      plVar8[7] = 0;
      plVar8[2] = 0;
      plVar8[1] = 0;
      FUN_fffffff00a8949d8(plVar8 + 1,8);
    }
  }
  if (*(int *)(param_3 + 0x68) == *(int *)(lVar9 + 0x4e8)) {
    *(int *)(param_3 + 0x68) = in_wzr;
    uVar11 = *(uint *)(param_1 + 0x74);
    if ((uVar11 >> 0x11 & 1) == 0) goto LAB_fffffff00a49d9dc;
LAB_fffffff00a49daec:
    lVar12 = *(long *)(param_1 + 0x110);
    if (lVar12 != 0) {
      uVar13 = *(ulong *)(lVar12 + 0x18);
      bVar4 = *(byte *)(lVar12 + 0x14);
      uVar2 = uVar13 + bVar4;
      if (uVar13 == 0) {
        if (cRam0000000000000001 == '\x02') {
LAB_fffffff00a49db54:
          if (*(int *)(uVar13 + 4) == 0) {
LAB_fffffff00a49dbb0:
            if ((*(uint *)(lVar12 + 0x74) >> 2 & 1) == 0) goto LAB_fffffff00a49dbb8;
          }
          else if ((bVar4 < 2) || (uVar2 < uVar13)) goto LAB_fffffff00a49db6c;
        }
        else if (cRam0000000000000001 == '\x1e') {
          piVar14 = (int *)&DAT_00000008;
          iVar3 = _DAT_00000008;
joined_r0xfffffff00a49db78:
          if (iVar3 == 0) {
            if ((int *)(uVar13 + 0xc) < piVar14) goto LAB_fffffff00a49db6c;
            if (*(int *)(uVar13 + 0xc) == 0) {
              if ((bVar4 < 2) || (uVar2 < uVar13)) goto LAB_fffffff00a49db6c;
              if ((*(int *)(uVar13 + 0x10) == 0) && (*(int *)(uVar13 + 0x14) == 0))
              goto LAB_fffffff00a49dbb0;
            }
          }
        }
      }
      else {
        if ((bVar4 < 2) || (uVar2 < uVar13)) goto LAB_fffffff00a49db6c;
        if (*(char *)(uVar13 + 1) == '\x1e') {
          piVar14 = (int *)(uVar13 + 8);
          iVar3 = *piVar14;
          goto joined_r0xfffffff00a49db78;
        }
        if (*(char *)(uVar13 + 1) == '\x02') goto LAB_fffffff00a49db54;
      }
    }
    goto LAB_fffffff00a49dd08;
  }
  FUN_fffffff00a226e08(param_3 + 0x60,lVar9);
  uVar11 = *(uint *)(param_1 + 0x74);
  if ((uVar11 >> 0x11 & 1) != 0) goto LAB_fffffff00a49daec;
LAB_fffffff00a49d9dc:
  if (*(char *)(param_2 + 1) == '\x1e') {
    if (((*(int *)(param_2 + 8) == 0) && (*(int *)(param_2 + 0xc) == 0)) &&
       (*(int *)(param_2 + 0x10) == 0)) {
      iVar3 = *(int *)(param_2 + 0x14);
      goto joined_r0xfffffff00a49da1c;
    }
  }
  else {
    if (*(char *)(param_2 + 1) != '\x02') goto LAB_fffffff00a49dd08;
    iVar3 = *(int *)(param_2 + 4);
joined_r0xfffffff00a49da1c:
    if ((iVar3 != 0) || ((uVar11 >> 2 & 1) != 0)) goto LAB_fffffff00a49dd08;
LAB_fffffff00a49dbb8:
    if ((*(uint *)(param_3 + 0x74) & 0x10000004) == 4) {
      if (*(ulong *)(param_3 + 0x68) == 0) {
        *(ulong *)(param_3 + 0x68) = (ulong)*(uint *)(lVar9 + 0x4e8);
        if ((DAT_fffffff00ad7cd2c & 1) == 0) goto LAB_fffffff00a49dbec;
LAB_fffffff00a49dc14:
        uVar11 = DAT_fffffff00ad7cd2c;
        uVar7 = *(uint *)(param_3 + 0x378);
        *(uint *)(param_3 + 0x378) = uVar7 + 1;
        if ((uVar11 >> 1 & 1) == 0) {
          *(uint *)(param_3 + 0x74) = *(uint *)(param_3 + 0x74) | 0x10000000;
          *(int *)(param_3 + 0x37c) = *(int *)(param_3 + 0x37c) + 1;
        }
        else {
          plVar8 = (long *)(param_3 + 0x650U) + (ulong)(uVar7 & 3) * 9;
          if ((plVar8 != (long *)0x0) &&
             (((long *)(param_3 + 0x770U) <= plVar8 || (plVar8 < (long *)(param_3 + 0x650U)))))
          goto LAB_fffffff00a49db6c;
          *plVar8 = lVar9;
          plVar8[4] = 0;
          plVar8[3] = 0;
          plVar8[6] = 0;
          plVar8[5] = 0;
          plVar8[8] = 0;
          plVar8[7] = 0;
          plVar8[2] = 0;
          plVar8[1] = 0;
          FUN_fffffff00a8949d8(plVar8 + 1,8);
          uVar11 = DAT_fffffff00ad7cd2c;
          *(uint *)(param_3 + 0x74) = *(uint *)(param_3 + 0x74) | 0x10000000;
          if ((uVar11 & 1) != 0) {
            uVar7 = *(uint *)(param_3 + 0x37c);
            *(uint *)(param_3 + 0x37c) = uVar7 + 1;
            if ((uVar11 >> 1 & 1) != 0) {
              plVar8 = (long *)(param_3 + 0x770U) + (ulong)(uVar7 & 3) * 9;
              if ((plVar8 != (long *)0x0) &&
                 (((long *)(param_3 + 0x890U) <= plVar8 || (plVar8 < (long *)(param_3 + 0x770U)))))
              goto LAB_fffffff00a49db6c;
              *plVar8 = lVar9;
              plVar8[4] = 0;
              plVar8[3] = 0;
              plVar8[6] = 0;
              plVar8[5] = 0;
              plVar8[8] = 0;
              plVar8[7] = 0;
              plVar8[2] = 0;
              plVar8[1] = 0;
              FUN_fffffff00a8949d8(plVar8 + 1,8);
            }
          }
        }
      }
      else {
        FUN_fffffff00a2262d4(param_3 + 0x60,lVar9,0);
        if ((DAT_fffffff00ad7cd2c & 1) != 0) goto LAB_fffffff00a49dc14;
LAB_fffffff00a49dbec:
        *(uint *)(param_3 + 0x74) = *(uint *)(param_3 + 0x74) | 0x10000000;
      }
      if (*(int *)(param_3 + 0x68) == *(int *)(lVar9 + 0x4e8)) {
        *(int *)(param_3 + 0x68) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_3 + 0x60,lVar9);
      }
    }
  }
LAB_fffffff00a49dd08:
  *(int *)(lVar9 + 0x1c0) = *(int *)(lVar9 + 0x1c0) + 1;
  if (*(ulong *)(param_3 + 0x68) == 0) {
    *(ulong *)(param_3 + 0x68) = (ulong)*(uint *)(lVar9 + 0x4e8) | 0x30000000;
    uVar11 = DAT_fffffff00ad7cd2c;
  }
  else {
    FUN_fffffff00a2262d4(param_3 + 0x60,lVar9,1);
    uVar11 = DAT_fffffff00ad7cd2c;
  }
  DAT_fffffff00ad7cd2c = uVar11;
  if ((uVar11 & 1) != 0) {
    uVar7 = *(uint *)(param_3 + 0x378);
    *(uint *)(param_3 + 0x378) = uVar7 + 1;
    if ((uVar11 >> 1 & 1) != 0) {
      plVar8 = (long *)(param_3 + 0x650U) + (ulong)(uVar7 & 3) * 9;
      if ((plVar8 != (long *)0x0) &&
         (((long *)(param_3 + 0x770U) <= plVar8 || (plVar8 < (long *)(param_3 + 0x650U)))))
      goto LAB_fffffff00a49db6c;
      *plVar8 = lVar9;
      plVar8[4] = 0;
      plVar8[3] = 0;
      plVar8[6] = 0;
      plVar8[5] = 0;
      plVar8[8] = 0;
      plVar8[7] = 0;
      plVar8[2] = 0;
      plVar8[1] = 0;
      FUN_fffffff00a8949d8(plVar8 + 1,8);
    }
  }
  FUN_fffffff00a49e4c4(param_3);
  uVar11 = DAT_fffffff00ad7cd2c;
  if ((DAT_fffffff00ad7cd2c & 1) != 0) {
    uVar7 = *(uint *)(param_3 + 0x37c);
    *(uint *)(param_3 + 0x37c) = uVar7 + 1;
    if ((uVar11 >> 1 & 1) != 0) {
      plVar8 = (long *)(param_3 + 0x770U) + (ulong)(uVar7 & 3) * 9;
      if ((plVar8 != (long *)0x0) &&
         (((long *)(param_3 + 0x890U) <= plVar8 || (plVar8 < (long *)(param_3 + 0x770U))))) {
LAB_fffffff00a49db6c:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a49db70);
        (*pcVar6)();
      }
      *plVar8 = lVar9;
      plVar8[4] = 0;
      plVar8[3] = 0;
      plVar8[6] = 0;
      plVar8[5] = 0;
      plVar8[8] = 0;
      plVar8[7] = 0;
      plVar8[2] = 0;
      plVar8[1] = 0;
      FUN_fffffff00a8949d8(plVar8 + 1,8);
    }
  }
  if (*(int *)(param_3 + 0x68) != *(int *)(lVar9 + 0x4e8)) {
    FUN_fffffff00a226e08(param_3 + 0x60,lVar9);
    return;
  }
  *(int *)(param_3 + 0x68) = in_wzr;
  return;
}

