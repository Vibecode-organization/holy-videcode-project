// FUN_fffffff00a1e9ba4 @ fffffff00a1e9ba4 size=1472

uint FUN_fffffff00a1e9ba4(ulong *param_1,int param_2,undefined8 param_3,long param_4,uint param_5)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  long *plVar10;
  int iVar11;
  ulong uVar12;
  undefined4 *puVar13;
  long lVar14;
  undefined4 uVar15;
  ulong uVar16;
  uint uVar17;
  ulong local_78;
  ulong local_70;
  ulong local_68;
  
  iVar11 = 0;
  uVar17 = 0;
  do {
    uVar6 = (uint)param_1[1];
    uVar4 = uVar6 >> 0x18;
    if (1 < uVar4) {
      if (uVar4 == 2) {
        uVar8 = *param_1;
        if (uVar8 == 0) {
          uVar16 = 0;
          uVar4 = 0;
        }
        else {
          uVar4 = 0;
          uVar16 = 0;
          uVar5 = (ulong)*(uint *)((long)param_1 + 0xc);
          local_68 = 0;
          if ((*(uint *)((long)param_1 + 0xc) != 0) && (uVar8 != 0)) {
            if (*(undefined8 **)(param_4 + 0x58) == (undefined8 *)0x0) {
              uVar2 = 0x14000000;
            }
            else {
              uVar2 = 0x7000000;
              if (*(undefined8 **)(param_4 + 0x58) != &DAT_fffffff00ad6cc50) {
                uVar2 = 0x14000000;
              }
            }
            iVar1 = FUN_fffffff00a2ddeb0(param_4,&local_68,uVar5 << 2,uVar2);
            if (iVar1 == 0) {
              lVar14 = 0;
              uVar4 = 0;
              uVar12 = uVar5;
              do {
                plVar10 = (long *)(uVar8 + lVar14 * 8);
                if (((uVar8 ^ (ulong)plVar10) & 0xffc0000000000000) != 0) {
                  plVar10 = (long *)((ulong)plVar10 & 0xffffffffffff | 0xc8a2000000000000);
                }
                lVar9 = *plVar10;
                if (lVar9 == 0) {
                  lVar9 = 0;
                }
                puVar13 = (undefined4 *)(uVar8 + lVar14 * 4);
                if (((uVar8 ^ (ulong)puVar13) & 0xffc0000000000000) != 0) {
                  puVar13 = (undefined4 *)((ulong)puVar13 & 0xffffffffffff | 0xc8a2000000000000);
                }
                if (lVar9 + 1U < 2) {
                  uVar3 = 0;
                  *puVar13 = (int)lVar9;
                }
                else {
                  iVar1 = FUN_fffffff00a1ee0f0(param_3,lVar9,uVar6 >> 0x10 & 0xff,2,0,puVar13);
                  uVar3 = 0;
                  if (iVar1 != 0) {
                    if (iVar1 == 0x14) {
                      uVar3 = 0;
                      *puVar13 = 0xffffffff;
                    }
                    else {
                      *puVar13 = 0;
                      uVar3 = 0x800;
                      if (iVar1 != 6) {
                        uVar3 = 0x2000;
                      }
                    }
                  }
                }
                uVar16 = local_68;
                uVar4 = uVar3 | uVar4;
                lVar14 = lVar14 + 1;
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
              iVar1 = FUN_fffffff00a2df35c(param_4,uVar8,local_68,uVar5 << 2,1);
              if (iVar1 != 0) {
                uVar4 = uVar4 | 0x1000;
              }
              FUN_fffffff00a2212a8(&DAT_fffffff007c81471,uVar8,uVar5 << 3);
            }
            else {
              FUN_fffffff00a1e70c4(param_1,1);
              uVar16 = 0;
              uVar4 = 0x400;
              if (iVar1 != 6) {
                uVar4 = 0x1000;
              }
            }
          }
        }
        *param_1 = uVar16;
      }
      else {
        if (uVar4 == 3) goto LAB_fffffff00a1e9ca4;
        if (uVar4 != 4) goto LAB_fffffff00a1ea130;
        uVar8 = *param_1;
        uVar6 = uVar6 >> 0x10 & 0xff;
        lVar14 = tpidr_el1;
        if (((param_5 >> 0xc & 1) == 0) && (*(long *)(lVar14 + 0x570) != 0xdeadbeef)) {
          if (1 < uVar8 + 1) {
            FUN_fffffff00a1edec8(uVar8,uVar6);
          }
          uVar4 = 0;
          *param_1 = 0;
          *(undefined4 *)((long)param_1 + 0xc) = 0;
        }
        else {
          puVar13 = (undefined4 *)((long)param_1 + 0xc);
          *param_1 = 0;
          if (uVar8 + 1 < 2) {
            uVar4 = 0;
            *puVar13 = (int)uVar8;
          }
          else {
            iVar1 = FUN_fffffff00a1ee0f0(param_3,uVar8,uVar6,2,param_1,puVar13);
            if (iVar1 == 0) {
              uVar4 = 0;
            }
            else if (iVar1 == 0x14) {
              uVar4 = 0;
              *puVar13 = 0xffffffff;
            }
            else {
              *puVar13 = 0;
              uVar4 = 0x800;
              if (iVar1 != 6) {
                uVar4 = 0x2000;
              }
            }
          }
        }
      }
      goto LAB_fffffff00a1e9bfc;
    }
    if (uVar4 == 0) {
      uVar8 = *param_1;
      if (uVar8 + 1 < 2) {
LAB_fffffff00a1e9db4:
        uVar4 = 0;
        uVar16 = uVar8 & 0xffffffff;
        if ((int)uVar8 == -1) {
          uVar16 = 0xffffffffffffffff;
        }
        *param_1 = uVar16;
      }
      else {
        local_68 = local_68 & 0xffffffff00000000;
        iVar1 = FUN_fffffff00a1ee0f0(param_3,uVar8,uVar6 >> 0x10 & 0xff,2,0,&local_68);
        if (iVar1 == 0x14) {
          uVar4 = 0;
          *param_1 = 0xffffffffffffffff;
        }
        else {
          if (iVar1 == 0) {
            uVar8 = local_68 & 0xffffffff;
            goto LAB_fffffff00a1e9db4;
          }
          uVar4 = 0x800;
          if (iVar1 != 6) {
            uVar4 = 0x2000;
          }
          *param_1 = 0;
        }
      }
    }
    else {
      if (uVar4 != 1) {
LAB_fffffff00a1ea130:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4c814(param_1);
      }
LAB_fffffff00a1e9ca4:
      uVar8 = *param_1;
      if ((uVar8 == 0) || (local_68 = (ulong)*(uint *)((long)param_1 + 0xc), uVar8 == 0)) {
        uVar15 = 0;
        uVar4 = 0;
        uVar8 = 0;
      }
      else {
        local_70 = 0;
        iVar1 = FUN_fffffff00a2ed218(param_4,uVar8,&local_68);
        uVar16 = local_68;
        if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa4d114
                    ("Inconsistent OOL/copyout size on %p: expected %d, got %lld @%p @%s:%d");
        }
        if ((*(char *)(uVar8 + 0x2d) == '\x02') &&
           ((uVar5 = *(ulong *)(uVar8 + 0x10), (uVar5 & 0x3fff) != 0 ||
            (((ulong)*(uint *)((long)param_1 + 0xc) + 0x3fff & 0x1ffffc000) !=
             (ulong)*(uint *)((long)param_1 + 0xc))))) {
          local_78 = 0;
          if (param_4 == 0) {
            uVar6 = 0xe;
          }
          else {
            uVar6 = (uint)*(byte *)(param_4 + 0x2c);
          }
          uVar6 = -1 << (ulong)(uVar6 & 0x1f);
          uVar12 = (ulong)~uVar6;
          lVar14 = (uVar5 + uVar12 + local_68 & (long)(int)uVar6) - (uVar5 & (long)(int)uVar6);
          iVar1 = FUN_fffffff00a2ddeb0(param_4,&local_78,lVar14,0x14000000);
          uVar5 = local_78;
          if (iVar1 == 0) {
            uVar7 = *(ulong *)(uVar8 + 0x10) & uVar12;
            local_70 = 0;
            if ((local_78 & uVar12) != uVar7) {
              local_70 = uVar7;
            }
            local_70 = local_78 + local_70;
            iVar1 = FUN_fffffff00a2ec338(param_4,local_70,uVar8,uVar16,0);
            if (iVar1 != 0) {
              FUN_fffffff00a2de0a4(param_4,uVar5,lVar14);
            }
          }
        }
        else {
          iVar1 = FUN_fffffff00a2e7458(param_4,&local_70,uVar8,local_68,1);
        }
        uVar15 = (undefined4)uVar16;
        if (iVar1 == 6) {
          uVar4 = 0x400;
        }
        else {
          if (iVar1 == 0) {
            uVar4 = 0;
            uVar8 = local_70;
            goto LAB_fffffff00a1e9bf4;
          }
          uVar4 = 0x1000;
        }
        FUN_fffffff00a2e2474(uVar8);
        uVar15 = 0;
        uVar8 = 0;
      }
LAB_fffffff00a1e9bf4:
      *param_1 = uVar8;
      *(undefined4 *)((long)param_1 + 0xc) = uVar15;
    }
LAB_fffffff00a1e9bfc:
    uVar17 = uVar4 | uVar17;
    iVar11 = iVar11 + 1;
    param_1 = param_1 + 2;
    if (iVar11 == param_2) {
      uVar6 = 0;
      if (uVar17 != 0) {
        uVar6 = uVar17 | 0x1000400c;
      }
      return uVar6;
    }
  } while( true );
}

