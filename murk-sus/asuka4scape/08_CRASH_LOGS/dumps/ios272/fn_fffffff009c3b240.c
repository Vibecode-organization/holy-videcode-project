// FUN_fffffff009c3b240 @ fffffff009c3b240 size=364

undefined8 FUN_fffffff009c3b240(long param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  local_40 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  iVar4 = FUN_fffffff009c3f044(param_1,param_2,&local_40);
  plVar3 = local_40;
  if (iVar4 == 0) {
    uVar8 = 0xe00002c2;
LAB_fffffff009c3b360:
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
    if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
      return uVar8;
    }
    uVar8 = thunk_EXT_FUN_8011000003a48590();
    return uVar8;
  }
  (**(code **)(**(long **)(param_1 + 0x140) + 0xe8))(*(long **)(param_1 + 0x140),local_40);
  (**(code **)(*plVar3 + 0x28))(plVar3);
  uVar5 = *(ulong *)(param_1 + 0x108);
  uVar6 = uVar5 + (ulong)*(uint *)(param_1 + 0x110) * 8;
  if (((uVar5 ^ uVar6) & 0xffc0000000000000) != 0) {
    uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
  }
  if ((uVar6 < uVar5) || (uVar6 - uVar5 >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else {
    lVar2 = (param_2 & 0xffffffff) << 3;
    if (lVar2 == (int)lVar2) {
      if (((param_2 & 0x1fffffff) >> 0x1c == 0) &&
         (uVar1 = (int)param_2 * 8, uVar1 + 8 <= (uint)(uVar6 - uVar5))) {
        uVar7 = (ulong)CARRY8(uVar5,(ulong)uVar1);
        uVar6 = -uVar7;
        if ((uVar6 != uVar7) || ((long)uVar6 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar8 = 0;
        *(undefined8 *)(uVar5 + uVar1) = 0;
        goto LAB_fffffff009c3b360;
      }
      goto LAB_fffffff009c3b3a0;
    }
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c3b3a0:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

