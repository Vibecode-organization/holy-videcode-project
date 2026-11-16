// FUN_fffffff0081f5ee4 @ fffffff0081f5ee4 size=1024

long * FUN_fffffff0081f5ee4(long *param_1)

{
  ulong uVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined8 *puVar5;
  undefined *puVar6;
  bool bVar7;
  int iVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  long *plVar12;
  long *plVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  ulong uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  ulong local_58;
  
  if (param_1 == (long *)0x0) {
    return (long *)0x0;
  }
  plVar9 = (long *)(**(code **)(DAT_fffffff00ae236f0 + 0x68))();
  if (plVar9 == (long *)0x0) {
    return (long *)0x0;
  }
  iVar8 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))(plVar9);
  if (iVar8 == 0) {
LAB_fffffff0081f6000:
    (**(code **)(*plVar9 + 0x28))(plVar9);
    return (long *)0x0;
  }
  plVar9[2] = (long)param_1;
  lVar10 = thunk_EXT_FUN_80110000038ff010();
  plVar9[0x84] = lVar10;
  if (lVar10 == 0) goto LAB_fffffff0081f6000;
  local_58 = 0;
  lVar10 = (**(code **)(*param_1 + 0x6d8))(param_1,&local_58);
  if (lVar10 == 0 || local_58 == 0) {
    plVar9[0x83] = 0;
    *(undefined1 *)((long)plVar9 + 0x51) = 0;
    *(undefined1 *)((long)plVar9 + 0x91) = 0;
    *(undefined1 *)((long)plVar9 + 0xd1) = 0;
    *(undefined1 *)((long)plVar9 + 0x111) = 0;
    *(undefined1 *)((long)plVar9 + 0x151) = 0;
    *(undefined1 *)((long)plVar9 + 0x191) = 0;
    *(undefined1 *)((long)plVar9 + 0x1d1) = 0;
    *(undefined1 *)((long)plVar9 + 0x211) = 0;
    *(undefined1 *)((long)plVar9 + 0x251) = 0;
    *(undefined1 *)((long)plVar9 + 0x291) = 0;
    *(undefined1 *)((long)plVar9 + 0x2d1) = 0;
    *(undefined1 *)((long)plVar9 + 0x311) = 0;
    *(undefined1 *)((long)plVar9 + 0x351) = 0;
    *(undefined1 *)((long)plVar9 + 0x391) = 0;
    *(undefined1 *)((long)plVar9 + 0x3d1) = 0;
    *(undefined1 *)((long)plVar9 + 0x411) = 0;
    return plVar9;
  }
  plVar9[0x83] = local_58;
  if (0x10 < local_58) goto LAB_fffffff0081f6000;
  uVar18 = 0;
  do {
    lVar15 = uVar18 * 0x20;
    puVar5 = (undefined8 *)(lVar10 + (int)lVar15);
    if (lVar15 - (int)lVar15 != 0) {
      puVar5 = (undefined8 *)(lVar10 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    iVar8 = (int)(uVar18 * 0x40);
    puVar2 = (undefined8 *)((long)plVar9 + (long)iVar8 + 0x18);
    if (uVar18 * 0x40 - (long)iVar8 != 0) {
      puVar2 = (undefined8 *)
               ((ulong)(plVar9 + uVar18 * 8 + 3) & 0xffffffffffff | 0x2bad000000000000);
    }
    uVar21 = puVar5[2];
    uVar20 = puVar5[1];
    uVar19 = puVar5[3];
    *puVar2 = *puVar5;
    puVar2[1] = 0;
    if ((long *)puVar2[2] != (long *)0x0) {
      (**(code **)(*(long *)puVar2[2] + 0x28))();
    }
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[5] = uVar21;
    puVar2[4] = uVar20;
    puVar2[6] = uVar19;
    *(undefined2 *)(puVar2 + 7) = 0x100;
    uVar18 = uVar18 + 1;
    uVar14 = plVar9[0x83];
  } while (uVar18 < uVar14);
  if (0xf < uVar14) goto LAB_fffffff0081f61a4;
  if (uVar14 == 0xf) {
    lVar10 = 0xf;
LAB_fffffff0081f6170:
    lVar15 = lVar10 + -0x10;
    do {
      uVar18 = lVar10 << 6 | 0x39;
      puVar4 = (undefined1 *)((long)plVar9 + (long)(int)uVar18 + 0x18);
      if (uVar18 != (long)(int)uVar18) {
        puVar4 = (undefined1 *)((long)plVar9 + uVar18 + 0x18 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar4 = 0;
      lVar10 = lVar10 + 1;
      bVar7 = lVar15 != -1;
      lVar15 = lVar15 + 1;
    } while (bVar7);
  }
  else {
    lVar10 = 0;
    uVar16 = 0x10 - uVar14 & 0x1e;
    uVar18 = uVar16;
    do {
      uVar1 = (uVar14 + lVar10 & 0x1ffffffffffffff) << 6 | 0x39;
      puVar4 = (undefined1 *)((long)plVar9 + (long)(int)uVar1 + 0x18);
      if (uVar1 != (long)(int)uVar1) {
        puVar4 = (undefined1 *)((long)plVar9 + uVar1 + 0x18 & 0xffffffffffff | 0x2bad000000000000);
      }
      lVar17 = (uVar14 + lVar10) * 0x40;
      lVar15 = lVar17 + 0x79;
      iVar8 = (int)lVar15;
      puVar3 = (undefined1 *)((long)plVar9 + (long)iVar8 + 0x18);
      if (lVar15 != iVar8) {
        puVar3 = (undefined1 *)((long)plVar9 + lVar17 + 0x91 & 0xffffffffffffU | 0x2bad000000000000)
        ;
      }
      *puVar4 = 0;
      *puVar3 = 0;
      lVar10 = lVar10 + 2;
      uVar18 = uVar18 - 2;
    } while (uVar18 != 0);
    if (0x10 - uVar14 != uVar16) {
      lVar10 = uVar14 + uVar16;
      goto LAB_fffffff0081f6170;
    }
  }
  if (uVar14 == 0) {
    return plVar9;
  }
LAB_fffffff0081f61a4:
  puVar6 = PTR_DAT_fffffff007ca61b0;
  uVar18 = 0;
  do {
    iVar8 = (int)(uVar18 * 0x40);
    puVar5 = (undefined8 *)((long)plVar9 + (long)iVar8 + 0x18);
    if (uVar18 * 0x40 - (long)iVar8 != 0) {
      puVar5 = (undefined8 *)
               ((ulong)(plVar9 + uVar18 * 8 + 3) & 0xffffffffffff | 0x2bad000000000000);
    }
    if ((*(byte *)((long)puVar5 + 0x39) & 1) != 0) {
      if (puVar5[5] == 0) {
        plVar13 = (long *)thunk_EXT_FUN_801100000392ef4c(puVar5[4],0);
      }
      else {
        plVar11 = (long *)thunk_EXT_FUN_80110000038d02e4();
        plVar12 = (long *)thunk_EXT_FUN_80110000038c6e24(puVar5[6],0x40);
        if (plVar11 == (long *)0x0) {
          if (plVar12 == (long *)0x0) goto LAB_fffffff0081f61b4;
          plVar13 = (long *)0x0;
LAB_fffffff0081f6240:
          (**(code **)(*plVar12 + 0x28))(plVar12);
          if (plVar11 == (long *)0x0) goto LAB_fffffff0081f628c;
        }
        else {
          if (plVar12 != (long *)0x0) {
            plVar13 = (long *)thunk_EXT_FUN_801100000392f8d4(plVar11,plVar12,0);
            goto LAB_fffffff0081f6240;
          }
          plVar13 = (long *)0x0;
        }
        (**(code **)(*plVar11 + 0x28))(plVar11);
      }
LAB_fffffff0081f628c:
      if (plVar13 != (long *)0x0) {
        uVar19 = thunk_EXT_FUN_801100000392eb04
                           (*(undefined8 *)puVar6,plVar13,FUN_fffffff0081f62e4,plVar9,*puVar5,0);
        puVar5[1] = uVar19;
        (**(code **)(*plVar13 + 0x28))(plVar13);
      }
    }
LAB_fffffff0081f61b4:
    uVar18 = uVar18 + 1;
    if ((ulong)plVar9[0x83] <= uVar18) {
      return plVar9;
    }
  } while( true );
}

