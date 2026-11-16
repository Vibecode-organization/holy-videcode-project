// FUN_fffffff009c1a914 @ fffffff009c1a914 size=1536
// CALLERS:
//   fffffff009c33cac FUN_fffffff009c33c34@fffffff009c33c34
//   fffffff009c1a910 FUN_fffffff009c1a908@fffffff009c1a908

/* WARNING: Removing unreachable block (ram,0xfffffff009c1ad18) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_fffffff009c1a914(long param_1,undefined8 param_2,long param_3,long *param_4,long param_5)

{
  undefined8 *puVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  undefined1 *puVar9;
  ulong uVar10;
  undefined1 *puVar11;
  ulong uVar12;
  ulong uVar13;
  uint uVar14;
  undefined8 local_68;
  undefined1 *local_60;
  undefined1 *local_58;
  undefined8 local_50;
  long local_48;
  
  local_48 = *_DAT_fffffff00806ca40;
  FUN_fffffff009c46f98(param_1 + 0xc,1);
  uVar5 = FUN_fffffff009c372c4();
  *(undefined8 *)(param_1 + 0x380) = uVar5;
  if (param_5 != 0) {
    if (*(long *)(param_5 + 0x378) != 0) {
      FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff00789dd81);
      bVar2 = false;
      goto LAB_fffffff009c1ac5c;
    }
    FUN_fffffff009c16670(param_1 + 0x378,param_5);
  }
  uVar6 = FUN_fffffff009c35bd8(_DAT_fffffff00af483b0,param_1 + 0x10);
  if ((uVar6 & 1) == 0) {
    FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff00789ddad);
    bVar2 = false;
  }
  else {
    uVar5 = (**(code **)(*param_4 + 0x138))(param_4,0xfffffff00789b419);
    lVar7 = FUN_fffffff009c498d4(uVar5,*_DAT_fffffff00806ca20);
    if (lVar7 == 0) {
      iVar3 = FUN_fffffff009c31488(2);
      puVar1 = _DAT_fffffff00806ca60;
      if (iVar3 != 0) {
        puVar1 = _DAT_fffffff00806ca58;
      }
      (**(code **)(*param_4 + 0x100))(param_4,0xfffffff00789b419,*(undefined8 *)*puVar1);
    }
    FUN_fffffff009c16670(param_1 + 0x268,param_4);
    if (param_3 != 0) {
      *(long *)(param_1 + 0x170) = param_3;
    }
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xffffef33;
    *(undefined8 *)(param_1 + 0x98) = 0;
    *(undefined4 *)(param_1 + 400) = 0;
    if (*(long **)(param_1 + 0x1a8) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x1a8) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x1a8) = 0;
    if (*(long **)(param_1 + 0x210) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x210) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(undefined8 *)(param_1 + 0x218) = 0;
    *(undefined8 *)(param_1 + 0x210) = 0;
    *(undefined8 **)(param_1 + 0x48) = (undefined8 *)(param_1 + 0x40);
    *(undefined8 *)(param_1 + 0x2f0) = 0;
    *(long *)(param_1 + 0x2f8) = param_1 + 0x2f0;
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0x1010001;
    *(undefined8 *)(param_1 + 0x150) = 0;
    *(undefined4 *)(param_1 + 0x368) = 3;
    *(undefined4 *)(param_1 + 0x22c) = 0;
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xffedb3fd | 0x800;
    lVar7 = FUN_fffffff009c49594();
    *(long *)(param_1 + 0x50) = lVar7;
    if (lVar7 != 0) {
      lVar7 = FUN_fffffff009c49594();
      *(long *)(param_1 + 0x398) = lVar7;
      if (lVar7 != 0) {
        lVar7 = FUN_fffffff009c49a54(1);
        if (*(long **)(param_1 + 0x3d8) != (long *)0x0) {
          (**(code **)(**(long **)(param_1 + 0x3d8) + 0x28))();
        }
        *(long *)(param_1 + 0x3d8) = lVar7;
        if (lVar7 != 0) {
          *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x10);
          *(undefined8 *)(param_1 + 0x178) = 0;
          *(undefined8 *)(param_1 + 0x300) = 0;
          *(undefined4 *)(param_1 + 0x220) = 0;
          *(undefined8 *)(param_1 + 0x240) = 0;
          *(long *)(param_1 + 0x248) = param_1 + 0x240;
          *(undefined8 *)(param_1 + 0x250) = 0;
          *(long *)(param_1 + 600) = param_1 + 0x250;
          *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xffff5fcf | 0x8000;
          *(undefined4 *)(param_1 + 0x228) = 2;
          local_60 = &DAT_aaaaaaaaaaaaaaaa;
          local_58 = &DAT_aaaaaaaaaaaaaaaa;
          uVar6 = FUN_fffffff009c36818
                            (_DAT_fffffff00af483b0,*(undefined4 *)(param_1 + 0x10),&local_58,
                             &local_60);
          if ((uVar6 & 1) == 0) {
            FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff00789ddd4);
            bVar2 = false;
          }
          else {
            puVar9 = local_58;
            if (local_58 == (undefined1 *)0x0) {
              puVar9 = (undefined1 *)0x0;
            }
            *(undefined1 **)(param_1 + 0x178) = puVar9;
            puVar11 = local_60;
            if (local_60 == (undefined1 *)0x0) {
              puVar11 = (undefined1 *)0x0;
            }
            *(undefined1 **)(param_1 + 0x300) = puVar11;
            *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x10000;
            puVar9[0x2c] = 1;
            *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x40000;
            puVar9[0x2e] = 1;
            uVar5 = FUN_fffffff009c49a54(0x10);
            if (*(long **)(param_1 + 0x3c8) != (long *)0x0) {
              (**(code **)(**(long **)(param_1 + 0x3c8) + 0x28))();
            }
            *(undefined8 *)(param_1 + 0x3c8) = uVar5;
            uVar6 = FUN_fffffff009c1af14(param_1,param_4);
            if ((uVar6 & 1) == 0) {
              FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff00789ddf6)
              ;
              bVar2 = false;
            }
            else {
              uVar4 = FUN_fffffff009c49d54();
              *(undefined4 *)(param_1 + 0x3d4) = uVar4;
              uVar6 = *(ulong *)(param_1 + 0x150);
              if (uVar6 == 0) {
                lVar7 = *(long *)(param_1 + 0x90);
              }
              else {
                uVar12 = -*_DAT_fffffff00806ca78;
                uVar10 = *_DAT_fffffff00806ca78 - 1;
                uVar13 = uVar10 & uVar6;
                lVar7 = *(long *)(param_1 + 0x90);
                *(ulong *)(param_1 + 0x158) = uVar6 & uVar12;
                *(ulong *)(param_1 + 0x160) = uVar13 + uVar10 + lVar7 & uVar12;
                *(ulong *)(param_1 + 0x168) = uVar13;
              }
              uVar14 = 0x100;
              if (lVar7 == 0) {
                bVar2 = true;
              }
              else {
                iVar3 = FUN_fffffff009c1e624(param_1);
                bVar2 = iVar3 == 0;
                uVar14 = 0x100;
                if (!bVar2) {
                  uVar14 = 0;
                }
              }
              *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffeff | uVar14;
              local_68 = 0;
              plVar8 = *(long **)(param_1 + 0x1a8);
              if (plVar8 != (long *)0x0) {
                uVar5 = (**(code **)(*plVar8 + 0x138))(plVar8,0xfffffff00789b3e2);
                plVar8 = (long *)FUN_fffffff009c498d4(uVar5,*_DAT_fffffff00806ca10);
                if (plVar8 != (long *)0x0) {
                  uVar5 = (**(code **)(*plVar8 + 0xa8))();
                  FUN_fffffff009c49c34(0x85210040,&local_68,uVar5);
                }
              }
              local_50 = 0;
              FUN_fffffff009c49e74(*(undefined8 *)(param_1 + 0x30),&local_50);
              FUN_fffffff009c49c14
                        (0x85210018,local_50,*(undefined4 *)(param_1 + 0x10),
                         *(undefined4 *)(param_1 + 0x80),
                         *(ulong *)(param_1 + 0x58) | *(long *)(param_1 + 0x60) << 0x20,0);
              local_50 = 0;
              FUN_fffffff009c49e74(*(undefined8 *)(param_1 + 0x30),&local_50);
              FUN_fffffff009c49c14
                        (0x8521003c,local_50,*(undefined4 *)(param_1 + 0x10),
                         *(undefined8 *)(param_1 + 0x90),local_68,0);
            }
          }
          goto LAB_fffffff009c1ac5c;
        }
      }
    }
    bVar2 = false;
  }
LAB_fffffff009c1ac5c:
  if (*_DAT_fffffff00806ca40 == local_48) {
    return bVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c49b64();
}

