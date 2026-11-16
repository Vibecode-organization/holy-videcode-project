// FUN_fffffff0081fb1d0 @ fffffff0081fb1d0 size=452

undefined8 FUN_fffffff0081fb1d0(long *param_1,ulong param_2,long *param_3,long *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  
  uVar4 = *(ushort *)(param_1 + 2);
  bVar3 = (&DAT_fffffff007115158)[(ulong)*(byte *)((long)param_1 + 0x59) * 0x20];
  uVar1 = *(undefined4 *)(param_1[3] + 0x78);
  uVar5 = (**(code **)(*param_1 + 0x100))();
  if ((uVar5 & 1) == 0) {
    lVar7 = thunk_EXT_FUN_8011000003890f30(param_1[3],*(undefined8 *)PTR_DAT_fffffff007ca6050);
    uVar6 = 0;
    if (lVar7 != 0) {
      uVar2 = *(uint *)(lVar7 + 0x90);
      lVar7 = (**(code **)(*param_1 + 0x98))(param_1);
      lVar7 = lVar7 + (ulong)uVar2 * (param_2 & 0xffffffff);
      if (param_3 != (long *)0x0) {
        lVar8 = (**(code **)(*param_3 + 0xb0))(param_3);
        uVar6 = (**(code **)(*(long *)param_1[4] + 0xd8))
                          ((long *)param_1[4],param_3,lVar7,lVar8,uVar1);
        if ((int)uVar6 == 0) {
          return uVar6;
        }
        *(long *)(param_1[4] + 0x1c8) = *(long *)(param_1[4] + 0x1c8) - lVar8;
      }
      if (param_4 != (long *)0x0) {
        lVar8 = (**(code **)(*param_4 + 0xb0))(param_4);
        uVar6 = (**(code **)(*(long *)param_1[4] + 0xd0))
                          ((long *)param_1[4],param_4,lVar7,lVar8,bVar3 | (uVar4 & 4) == 0,uVar1);
        if ((int)uVar6 == 0) {
          return uVar6;
        }
        *(long *)(param_1[4] + 0x1c8) = *(long *)(param_1[4] + 0x1c8) + lVar8;
      }
      uVar6 = 1;
    }
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}

