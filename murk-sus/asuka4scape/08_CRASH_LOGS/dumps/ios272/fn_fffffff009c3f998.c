// FUN_fffffff009c3f998 @ fffffff009c3f998 size=1052

/* WARNING: Removing unreachable block (ram,0xfffffff009c3fc14) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3fcf0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3fa00) */

void FUN_fffffff009c3f998(long param_1,long *param_2,int param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  undefined4 uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined *local_c8;
  undefined8 local_c0;
  code *local_b8;
  undefined *local_b0;
  undefined8 *puStack_a8;
  int local_a0;
  undefined4 uStack_9c;
  undefined8 local_98;
  undefined8 *local_90;
  undefined8 local_88;
  code *local_80;
  code *local_78;
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  lVar9 = *(long *)(param_1 + 0xf8);
  if (lVar9 == 0) {
    lVar9 = 0;
  }
  lVar9 = thunk_EXT_FUN_80110000032970b4(lVar9);
  if (lVar9 != 0) {
    thunk_EXT_FUN_8011000003722e04();
    plVar2 = (long *)thunk_EXT_FUN_80110000038ce200();
    if (plVar2 != (long *)0x0) {
      (**(code **)(*param_2 + 0x100))(param_2,"name",plVar2);
    }
    iVar1 = thunk_EXT_FUN_8011000003720f30(lVar9);
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24((long)iVar1,0x20);
    if (plVar3 != (long *)0x0) {
      (**(code **)(*param_2 + 0x100))(param_2,"pid",plVar3);
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  uVar4 = 0x100;
  if (param_3 != 0) {
    uVar4 = 0x800;
  }
  local_90 = &local_98;
  local_98 = 0;
  local_88 = DAT_fffffff0078a1298;
  local_80 = FUN_fffffff009c3fee4;
  local_78 = FUN_fffffff009c3fef8;
  local_70 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  local_70 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(param_1 + 300));
  plVar2 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(param_1 + 300));
  if (local_90[5] != 0) {
    if (plVar2 == (long *)0x0) goto LAB_fffffff009c3fd38;
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
    uVar5 = (ulong)*(uint *)(param_1 + 0x110);
    if (*(uint *)(param_1 + 0x110) != 0) {
      uVar10 = 0;
      uVar11 = 0;
      uVar12 = 0xffffffff7ffffff8;
      do {
        uVar6 = *(ulong *)(param_1 + 0x108);
        uVar7 = uVar6 + uVar5 * 8;
        if (((uVar6 ^ uVar7) & 0xffc0000000000000) != 0) {
          uVar7 = uVar7 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar7 < uVar6) || (uVar7 - uVar6 >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
LAB_fffffff009c3fda4:
          FUN_fffffff009c48f3c();
LAB_fffffff009c3fda8:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar12 = uVar12 + 8;
        if (uVar12 < 0xffffffff00000000) goto LAB_fffffff009c3fda4;
        if (((long)uVar10 < 0) || ((uint)(uVar7 - uVar6) < (int)(uVar10 >> 0x20) + 8U))
        goto LAB_fffffff009c3fda8;
        uVar8 = (ulong)CARRY8(uVar6,uVar10 >> 0x20);
        uVar7 = -uVar8;
        if ((uVar7 != uVar8) || ((long)uVar7 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        lVar9 = *(long *)(uVar6 + (uVar10 >> 0x20));
        if ((lVar9 != 0) && (lVar9 != 0)) {
          (**(code **)(*plVar2 + 0xe8))(plVar2,lVar9);
          uVar5 = (ulong)*(uint *)(param_1 + 0x110);
        }
        uVar10 = uVar10 + 0x800000000;
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar5);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
    local_c8 = PTR_DAT_fffffff00806c9b8;
    local_c0 = DAT_fffffff0078a1290;
    local_b8 = FUN_fffffff009c3ff44;
    puStack_a8 = &local_98;
    local_b0 = &DAT_fffffff00806a0c0;
    local_a0 = param_3;
    uStack_9c = uVar4;
    thunk_EXT_FUN_801100000389794c(plVar2,&local_c8);
    (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"Client Surfaces",local_90[5]);
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
LAB_fffffff009c3fd38:
  thunk_EXT_FUN_80110000038e9dac(&local_98,8);
  if (local_70 != (long *)0x0) {
    (**(code **)(*local_70 + 0x28))();
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

