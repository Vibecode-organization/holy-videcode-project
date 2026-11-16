// FUN_fffffff0081c5278 @ fffffff0081c5278 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081c5bc4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c5b28) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c5a84) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c5a04) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c59c4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c5a44) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c5ae4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c5b6c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c5c08) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c5984) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c6690) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081c6774) */

long * FUN_fffffff0081c5278(long *param_1,int param_2,uint param_3)

{
  ulong uVar1;
  undefined4 *puVar2;
  long lVar3;
  uint uVar4;
  undefined4 uVar5;
  long *plVar6;
  long *plVar7;
  float *pfVar8;
  code *pcVar9;
  long lVar10;
  int iVar11;
  long *plVar12;
  long lVar13;
  int iVar14;
  long lVar15;
  float fVar16;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  float fStack_94;
  undefined4 uStack_90;
  float fStack_8c;
  float fStack_88;
  uint uStack_84;
  int iStack_80;
  int iStack_7c;
  long *plStack_78;
  long *plStack_70;
  undefined8 uStack_68;
  uint uStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  
  lVar13 = param_1[0x50];
  if (param_2 < 0xe) {
    if (param_2 < 4) {
      if (param_2 == 0) {
        plVar12 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
        plVar7 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
        uVar5 = (**(code **)(*param_1 + 0x848))(*param_1 + 0x848,param_1);
        plStack_78 = (long *)CONCAT44(plStack_78._4_4_,uVar5);
        fStack_54 = (float)(**(code **)(*param_1 + 0x850))(*param_1 + 0x850,param_1);
        fStack_58 = (float)(**(code **)(*param_1 + 0x858))(*param_1 + 0x858,param_1);
        fStack_5c = (float)(**(code **)(*param_1 + 0x860))(*param_1 + 0x860,param_1);
        uStack_60 = (**(code **)(*param_1 + 0x840))(*param_1 + 0x840,param_1,0);
        fVar16 = (float)uStack_60;
        uStack_68 = CONCAT44((fVar16 + -1.0) / fVar16,1.0 / fVar16);
        iStack_7c = (**(code **)(*param_1 + 0x838))(*param_1 + 0x838,param_1,0);
        iStack_80 = (**(code **)(*param_1 + 0x830))(*param_1 + 0x830,param_1,0);
        uStack_84 = (**(code **)(*param_1 + 0x840))(*param_1 + 0x840,param_1,1);
        fStack_8c = (float)uStack_84;
        fStack_88 = (fStack_8c + -1.0) / fStack_8c;
        fStack_8c = 1.0 / fStack_8c;
        uStack_90 = (**(code **)(*param_1 + 0x838))(*param_1 + 0x838,param_1,1);
        fStack_94 = (float)(**(code **)(*param_1 + 0x830))(*param_1 + 0x830,param_1,1);
        (**(code **)(*plVar7 + 200))(plVar7,&fStack_58,4);
        (**(code **)(*plVar7 + 200))(plVar7,&fStack_5c,4);
        (**(code **)(*plVar7 + 200))(plVar7,&fStack_54,4);
        (**(code **)(*plVar7 + 200))(plVar7,&plStack_78,4);
        (**(code **)(*plVar7 + 200))(plVar7,&uStack_60,4);
        (**(code **)(*plVar7 + 200))(plVar7,(long)&uStack_68 + 4,4);
        (**(code **)(*plVar7 + 200))(plVar7,&uStack_68,4);
        (**(code **)(*plVar7 + 200))(plVar7,&iStack_7c,4);
        (**(code **)(*plVar7 + 200))(plVar7,&iStack_80,4);
        (**(code **)(*plVar7 + 200))(plVar7,&uStack_84,4);
        (**(code **)(*plVar7 + 200))(plVar7,&fStack_88,4);
        (**(code **)(*plVar7 + 200))(plVar7,&fStack_8c,4);
        (**(code **)(*plVar7 + 200))(plVar7,&uStack_90,4);
        pcVar9 = *(code **)(*plVar7 + 200);
        pfVar8 = &fStack_94;
        goto LAB_fffffff0081c68f4;
      }
      if (param_2 != 3) {
        return (long *)0x0;
      }
      lVar15 = (ulong)param_3 * 0x278;
      iVar14 = (int)lVar15;
      uVar1 = lVar13 + 0x10ab8 + (long)iVar14;
      if (lVar15 - iVar14 != 0) {
        uVar1 = lVar13 + 0x10ab8 + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
      }
      plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
      plVar7 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
      plStack_70 = (long *)(param_1[0x50] + 0x10ab8 + (long)iVar14);
      if (lVar15 - iVar14 != 0) {
        plStack_70 = (long *)(param_1[0x50] + 0x10ab8 + lVar15 & 0xffffffffffffU |
                             0x2bad000000000000);
      }
      fStack_54 = *(float *)((long)plStack_70 + 0xc);
      if (*(float *)(plStack_70 + 10) != 0.0) {
        fStack_54 = *(float *)(plStack_70 + 10);
      }
      fStack_58 = *(float *)((long)plStack_70 + 100);
      if (*(float *)((long)plStack_70 + 100) == 0.0) {
        fStack_58 = *(float *)(plStack_70 + 6);
      }
      fStack_5c = *(float *)(plStack_70 + 0xd);
      if (*(float *)(plStack_70 + 0xd) == 0.0) {
        fStack_5c = *(float *)((long)plStack_70 + 0x34);
      }
      uStack_60 = *(uint *)(plStack_70 + 2);
      if (*(uint *)((long)plStack_70 + 0x54) != 0) {
        uStack_60 = *(uint *)((long)plStack_70 + 0x54);
      }
      lVar13 = 0x20;
      if (*(int *)((long)plStack_70 + 0x5c) != 0) {
        lVar13 = 0x58;
      }
      puVar2 = (undefined4 *)((long)plStack_70 + (long)(int)lVar13);
      if (lVar13 != (int)lVar13) {
        puVar2 = (undefined4 *)((long)plStack_70 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
      }
      iVar14 = (int)plStack_70[3];
      if ((int)plStack_70[0xc] != 0) {
        iVar14 = (int)plStack_70[0xc];
      }
      uStack_68 = CONCAT44(*puVar2,iVar14);
      plStack_70 = (long *)*plStack_70;
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_54,4);
      (**(code **)(*plVar7 + 200))(plVar7,uVar1 + 0x24,4);
      (**(code **)(*plVar7 + 200))(plVar7,uVar1 + 0x28,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_58,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_5c,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_60,4);
      (**(code **)(*plVar7 + 200))(plVar7,(long)&uStack_68 + 4,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_68,4);
      (**(code **)(*plVar7 + 200))(plVar7,&plStack_70,8);
      plStack_78 = plVar7;
      (**(code **)(*plVar7 + 0x20))(plVar7);
      thunk_EXT_FUN_801100000389d40c(plVar6,"ConfigData",&plStack_78);
      plVar12 = plStack_78;
    }
    else {
      if (param_2 != 4) {
        if (param_2 != 8) {
          return (long *)0x0;
        }
        plVar12 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
        plVar7 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
        lVar13 = param_1[0x50];
        iVar14 = *(int *)(lVar13 + 0x10d54);
        if (*(int *)(lVar13 + 0x10d7c) != 0) {
          iVar14 = *(int *)(lVar13 + 0x10d7c);
        }
        uVar4 = 0;
        if (*(uint *)(lVar13 + 0x10d30) != 0) {
          uVar4 = (uint)(iVar14 * 100) / *(uint *)(lVar13 + 0x10d30);
        }
        if (99 < uVar4) {
          uVar4 = 100;
        }
        thunk_EXT_FUN_80110000039b78d4
                  (*(undefined8 *)(*(long *)(lVar13 + 0x1ac50) + 0x130),0,
                   (ulong)uVar4 * 0x1999999a >> 0x20);
        plStack_78 = (long *)CONCAT44(plStack_78._4_4_,iVar14);
        lVar13 = param_1[0x50];
        fStack_54 = *(float *)(lVar13 + 0x10d80);
        if (*(float *)(lVar13 + 0x10d80) == 0.0) {
          fStack_54 = *(float *)(lVar13 + 0x10d68);
        }
        fStack_58 = *(float *)(lVar13 + 0x10d84);
        if (*(float *)(lVar13 + 0x10d84) == 0.0) {
          fStack_58 = *(float *)(lVar13 + 0x10d5c);
        }
        fStack_5c = *(float *)(lVar13 + 0x10d38);
        if (*(float *)(lVar13 + 0x10d90) != 0.0) {
          fStack_5c = *(float *)(lVar13 + 0x10d90);
        }
        (**(code **)(*plVar7 + 200))(plVar7,&plStack_78,4);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x50] + 0x10d4c,4);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x50] + 0x10d50,4);
        (**(code **)(*plVar7 + 200))(plVar7,&fStack_54,4);
        (**(code **)(*plVar7 + 200))(plVar7,&fStack_58,4);
        pcVar9 = *(code **)(*plVar7 + 200);
        pfVar8 = &fStack_5c;
        goto LAB_fffffff0081c68f4;
      }
      plVar12 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
      plVar7 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
      plStack_78 = (long *)CONCAT44(plStack_78._4_4_,1);
      (**(code **)(*plVar7 + 200))(plVar7,&plStack_78,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x1c0,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x1c4,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x1d0,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x1d4,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x1c8,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x1cc,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x1d8,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x1dc,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x1e0,4);
LAB_fffffff0081c6904:
      plStack_70 = plVar7;
      (**(code **)(*plVar7 + 0x20))(plVar7);
      thunk_EXT_FUN_801100000389d40c(plVar12,"ConfigData",&plStack_70);
      plVar6 = plVar12;
      plVar12 = plStack_70;
    }
    if (plVar12 != (long *)0x0) {
      (**(code **)(*plVar12 + 0x28))();
    }
    plVar12 = (long *)0x0;
  }
  else {
    if (0xf < param_2) {
      if (param_2 != 0x10) {
        if (param_2 != 0x11) {
          return (long *)0x0;
        }
        plVar12 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
        plVar7 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
        plStack_78 = (long *)CONCAT44(plStack_78._4_4_,0x10);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x620,4);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x624,4);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x628,4);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x62c,4);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x634,4);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x630,4);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x640,4);
        (**(code **)(*plVar7 + 200))(plVar7,lVar13 + 0x11080,4);
        (**(code **)(*plVar7 + 200))(plVar7,&plStack_78,4);
        (**(code **)(*plVar7 + 200))(plVar7,param_1[0x58] + 0x2ee4,(int)plStack_78 << 2);
        goto LAB_fffffff0081c6904;
      }
      plVar12 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
      plVar7 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
      lVar15 = param_1[0x50];
      iVar14 = *(int *)(lVar15 + 0x11104);
      if (*(int *)(lVar15 + 0x110a0) == 1) {
        iVar11 = iVar14;
        if (iVar14 == 0) {
          iVar11 = *(int *)(param_1[0x58] + 0x277a);
        }
      }
      else {
        iVar11 = *(int *)(lVar15 + 0x110a4);
        if (iVar14 != 0) {
          iVar11 = iVar14;
        }
      }
      plStack_78 = (long *)CONCAT44(plStack_78._4_4_,iVar11);
      fStack_54 = *(float *)(lVar15 + 0x110f8);
      if (*(float *)(lVar15 + 0x110f8) == 0.0) {
        fStack_54 = *(float *)(lVar15 + 0x110c4);
      }
      fStack_58 = *(float *)(lVar15 + 0x110fc);
      if (*(float *)(lVar15 + 0x110fc) == 0.0) {
        fStack_58 = *(float *)(lVar15 + 0x110c8);
      }
      fStack_5c = *(float *)(lVar15 + 0x110d0);
      if (*(float *)(lVar15 + 0x11100) != 0.0) {
        fStack_5c = *(float *)(lVar15 + 0x11100);
      }
      uStack_60 = *(uint *)(lVar15 + 0x110a8);
      if (*(uint *)(lVar15 + 0x1110c) != 0) {
        uStack_60 = *(uint *)(lVar15 + 0x1110c);
      }
      fVar16 = (float)(uint)fStack_5c;
      uStack_68 = CONCAT44((fVar16 + -1.0) / fVar16,1.0 / fVar16);
      (**(code **)(*plVar7 + 200))(plVar7,lVar13 + 0x1109c,4);
      (**(code **)(*plVar7 + 200))(plVar7,&plStack_78,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_60,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_54,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_58,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_5c,4);
      (**(code **)(*plVar7 + 200))(plVar7,(long)&uStack_68 + 4,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_68,4);
      pcVar9 = *(code **)(*plVar7 + 200);
      pfVar8 = (float *)(lVar13 + 0x110a0);
LAB_fffffff0081c68f4:
      (*pcVar9)(plVar7,pfVar8,4);
      goto LAB_fffffff0081c6904;
    }
    if (param_2 == 0xe) {
      plVar12 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
      plVar7 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
      lVar15 = param_1[0x50];
      iVar14 = *(int *)(lVar15 + 0x10de0);
      if (*(int *)(lVar15 + 0x10e48) != 0) {
        iVar14 = *(int *)(lVar15 + 0x10e48);
      }
      plStack_78 = (long *)CONCAT44(plStack_78._4_4_,iVar14);
      fStack_54 = *(float *)(lVar15 + 0x10de4);
      if (*(float *)(lVar15 + 0x10e4c) != 0.0) {
        fStack_54 = *(float *)(lVar15 + 0x10e4c);
      }
      lVar10 = lVar15 + 0x10ddc;
      lVar3 = 0x30;
      if (*(int *)(lVar15 + 0x10e70) != 0) {
        lVar3 = 0x8c;
      }
      fStack_58 = *(float *)(lVar10 + lVar3);
      lVar3 = 0x38;
      if (*(int *)(lVar15 + 0x10e80) != 0) {
        lVar3 = 0x9c;
      }
      fStack_5c = *(float *)(lVar10 + lVar3);
      lVar3 = 0x30;
      if (*(int *)(lVar15 + 0x10e74) != 0) {
        lVar3 = 0x8c;
      }
      uStack_60 = *(uint *)(lVar10 + lVar3 + 4);
      lVar3 = 0x38;
      if (*(int *)(lVar15 + 0x10e84) != 0) {
        lVar3 = 0x9c;
      }
      uStack_68 = CONCAT44(*(undefined4 *)(lVar10 + lVar3 + 4),*(undefined4 *)(lVar15 + 0x10e90));
      iStack_7c = *(int *)(lVar15 + 0x10e30);
      if (*(int *)(lVar15 + 0x10e94) != 0) {
        iStack_7c = *(int *)(lVar15 + 0x10e94);
      }
      iStack_80 = *(int *)(lVar15 + 0x10e34);
      if (*(int *)(lVar15 + 0x10e98) != 0) {
        iStack_80 = *(int *)(lVar15 + 0x10e98);
      }
      uStack_84 = *(uint *)(lVar15 + 0x10e38);
      if (*(uint *)(lVar15 + 0x10e9c) != 0) {
        uStack_84 = *(uint *)(lVar15 + 0x10e9c);
      }
      fStack_88 = *(float *)(lVar15 + 0x10e3c);
      if (*(float *)(lVar15 + 0x10ea0) != 0.0) {
        fStack_88 = *(float *)(lVar15 + 0x10ea0);
      }
      fStack_8c = *(float *)(lVar15 + 0x10e40);
      if (*(float *)(lVar15 + 0x10ea4) != 0.0) {
        fStack_8c = *(float *)(lVar15 + 0x10ea4);
      }
      uStack_90 = *(undefined4 *)(lVar15 + 0x10ea8);
      lVar3 = 0x10df0;
      if (*(int *)(lVar15 + 0x10e54) != 0) {
        lVar3 = 0x10e50;
      }
      fStack_94 = (float)(uint)(*(int *)(lVar15 + lVar3) != 0);
      lVar3 = 0x18;
      if (*(int *)(lVar15 + 0x10e60) != 0) {
        lVar3 = 0x7c;
      }
      uStack_98 = *(undefined4 *)(lVar10 + lVar3);
      lVar3 = 0x18;
      if (*(int *)(lVar15 + 0x10e64) != 0) {
        lVar3 = 0x7c;
      }
      uStack_9c = *(undefined4 *)(lVar10 + lVar3 + 4);
      (**(code **)(*plVar7 + 200))(plVar7,&plStack_78,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_54,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_94,4);
      (**(code **)(*plVar7 + 200))(plVar7,lVar13 + 0x10e54,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_98,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_9c,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_58,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_5c,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_60,4);
      (**(code **)(*plVar7 + 200))(plVar7,(long)&uStack_68 + 4,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_68,4);
      (**(code **)(*plVar7 + 200))(plVar7,&iStack_7c,4);
      (**(code **)(*plVar7 + 200))(plVar7,&iStack_80,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_8c,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_90,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_84,4);
      pcVar9 = *(code **)(*plVar7 + 200);
      pfVar8 = &fStack_88;
      goto LAB_fffffff0081c68f4;
    }
    if (param_2 != 0xf) {
      return (long *)0x0;
    }
    plVar12 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
    plVar7 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
    lVar13 = param_1[0x58];
    uStack_68 = 0;
    if (param_3 == 0) {
      plStack_78 = (long *)CONCAT44(plStack_78._4_4_,*(undefined4 *)(lVar13 + 0x2d58));
      lVar10 = param_1[0x123];
      lVar15 = 0x5ac;
      if (*(int *)(lVar10 + 0x57c) != 0) {
        lVar15 = 0x57c;
      }
      fStack_54 = *(float *)(lVar10 + lVar15);
      lVar15 = 0x5b0;
      if (*(int *)(lVar10 + 0x580) != 0) {
        lVar15 = 0x580;
      }
      fStack_58 = *(float *)(lVar10 + lVar15);
      lVar15 = 0x5b4;
      if (*(int *)(lVar10 + 0x584) != 0) {
        lVar15 = 0x584;
      }
      fStack_5c = *(float *)(lVar10 + lVar15);
      lVar15 = 0x5b8;
      if (*(int *)(lVar10 + 0x588) != 0) {
        lVar15 = 0x588;
      }
      uStack_60 = *(uint *)(lVar10 + lVar15);
      lVar15 = 0x5a4;
      if (*(int *)(lVar10 + 0x590) != 0) {
        lVar15 = 0x590;
      }
      iStack_7c = *(int *)(lVar10 + lVar15);
      (**(code **)(*plVar7 + 200))(plVar7,lVar10 + 0x5a0,4);
      (**(code **)(*plVar7 + 200))(plVar7,param_1[0x123] + 0x560,4);
      (**(code **)(*plVar7 + 200))(plVar7,&plStack_78,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_54,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_58,4);
      (**(code **)(*plVar7 + 200))(plVar7,&fStack_5c,4);
      (**(code **)(*plVar7 + 200))(plVar7,&uStack_60,4);
      (**(code **)(*plVar7 + 200))(plVar7,lVar13 + 0x2e28,4);
      (**(code **)(*plVar7 + 200))(plVar7,&iStack_7c,4);
      (**(code **)(*plVar7 + 200))(plVar7,(long)&uStack_68 + 4,4);
      pcVar9 = *(code **)(*plVar7 + 200);
      pfVar8 = (float *)&uStack_68;
      goto LAB_fffffff0081c68f4;
    }
    plVar6 = (long *)0x0;
    if (plVar7 == (long *)0x0) goto LAB_fffffff0081c6984;
  }
  (**(code **)(*plVar7 + 0x28))(plVar7);
LAB_fffffff0081c6984:
  if (plVar12 != (long *)0x0) {
    (**(code **)(*plVar12 + 0x28))(plVar12);
  }
  return plVar6;
}

