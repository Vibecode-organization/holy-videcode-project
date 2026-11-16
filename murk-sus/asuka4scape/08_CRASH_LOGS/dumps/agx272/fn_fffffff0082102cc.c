// FUN_fffffff0082102cc @ fffffff0082102cc size=284

uint FUN_fffffff0082102cc(long *param_1,ulong param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar5 = param_2 >> 0x27 & 1;
  uVar6 = param_2 >> 0x24 & 7;
  uVar2 = (**(code **)(*param_1 + 0x78))
                    (param_1,*(undefined8 *)(param_1[uVar5 * 8 + 7] + uVar6 * 8));
  if (param_3 == 2) {
    return uVar2 ^ 1;
  }
  if (((uVar2 ^ 1) & 1) != 0) {
    return 0;
  }
  lVar4 = *(long *)(param_1[uVar5 * 8 + 9] + uVar6 * 8);
  if (lVar4 != 0) {
    uVar7 = param_2 >> 0x19 & 0x7ff;
    iVar3 = (**(code **)(*param_1 + 0x80))(param_1,*(undefined8 *)(lVar4 + uVar7 * 8));
    if (iVar3 != 0) {
      if ((param_3 == 1) ||
         ((lVar4 = *(long *)(*(long *)(param_1[uVar5 * 8 + 0xc] + uVar6 * 8) + uVar7 * 8),
          lVar4 != 0 &&
          (uVar5 = (**(code **)(*param_1 + 0x88))
                             (param_1,*(undefined8 *)(lVar4 + (param_2 >> 0xe & 0x7ff) * 8)),
          (uVar5 & 1) != 0)))) {
        return 0;
      }
      bVar1 = param_3 == 0;
      goto LAB_fffffff0082103c4;
    }
  }
  bVar1 = param_3 == 1;
LAB_fffffff0082103c4:
  return (uint)bVar1;
}

