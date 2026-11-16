// FUN_fffffff0081fe790 @ fffffff0081fe790 size=4

undefined8 FUN_fffffff0081fe790(long param_1,long *param_2)

{
  char cVar1;
  byte bVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  long *plVar6;
  
  cVar1 = *(char *)((long)param_2 + 0x59);
  thunk_EXT_FUN_801100000296c9fc();
  if ((1 << (ulong)(*(ushort *)((long)param_2 + 0x12) & 0x1f) & 0x5f80U) != 0) {
    thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
    *(undefined1 *)(param_1 + 0x2a0) = 1;
  }
  if (cVar1 == '\x0e') {
    lVar4 = thunk_EXT_FUN_80110000039ea018();
    if (lVar4 == 1) {
      uVar5 = 0;
      bVar2 = *(byte *)(param_1 + 0x2a0);
      goto joined_r0xfffffff0081fe8e4;
    }
LAB_fffffff0081fe8ec:
    uVar5 = FUN_fffffff0081e8430(param_1,param_2);
  }
  else {
    if (cVar1 != '\x02') goto LAB_fffffff0081fe8ec;
    uVar3 = (**(code **)(*param_2 + 0x98))(param_2);
    if ((((uVar3 >> 0x20 < 0x13) ||
         (uVar3 = (**(code **)(*param_2 + 0x98))(param_2), (uVar3 & 0x3ffffff) != 0)) ||
        (lVar4 = (**(code **)(*param_2 + 200))(param_2), lVar4 == 0)) ||
       (uVar3 = (**(code **)(*param_2 + 200))(param_2), (uVar3 & 0x3ffffff) != 0)) {
      (**(code **)(*param_2 + 0x98))(param_2);
      (**(code **)(*param_2 + 200))(param_2);
      (**(code **)(*param_2 + 0x98))(param_2);
      (**(code **)(*param_2 + 200))(param_2);
      uVar5 = thunk_EXT_FUN_8011000003a49114
                        (
                        "AGXk: %s:%d:%s: !!! %s Trying to map a VA outside the AGX_GART_RANGE_GPU_KICK or unaligned address! (0x%llx) size (%llx)\n"
                        );
      return uVar5;
    }
    param_2[7] = 0;
    plVar6 = *(long **)(param_1 + 0x1c0);
    param_2[8] = (long)plVar6;
    *plVar6 = (long)param_2;
    *(long **)(param_1 + 0x1c0) = param_2 + 7;
    lVar4 = thunk_EXT_FUN_801100000297b378(param_2);
    *(long *)(param_1 + 200) = *(long *)(param_1 + 200) + lVar4;
    uVar5 = (**(code **)(*param_2 + 0x98))(param_2);
  }
  bVar2 = *(byte *)(param_1 + 0x2a0);
joined_r0xfffffff0081fe8e4:
  if ((bVar2 & 1) != 0) {
    *(undefined1 *)(param_1 + 0x2a0) = 0;
    thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
  }
  thunk_EXT_FUN_801100000296ca08(param_1);
  return uVar5;
}

