// FUN_fffffff0081fdc28 @ fffffff0081fdc28 size=776

bool FUN_fffffff0081fdc28
               (long *param_1,long *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5
               ,undefined8 param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  ulong uVar6;
  long lVar7;
  char cVar8;
  
  if (((*(byte *)(param_1 + 0x5e) & 1) == 0) && (*(int *)((long)param_1 + 0x274) == 0)) {
    cVar8 = '\x02';
  }
  else {
    uVar2 = (**(code **)(*param_1 + 0x160))(param_1);
    cVar8 = '\x02';
    if ((uint)param_6 != uVar2) {
      cVar8 = ((uint)param_6 & (uVar2 ^ 0xffffffff)) == 0;
    }
    if ((*(byte *)(param_1 + 0x5e) & 1) != 0) {
      plVar5 = (long *)param_1[0x5b];
      if ((plVar5 != (long *)0x0) &&
         (iVar3 = (**(code **)(*plVar5 + 0xd0))(plVar5,param_2,param_3,param_4,param_5,param_6),
         iVar3 == 0)) {
        return false;
      }
      plVar5 = (long *)param_1[0x5c];
      if ((plVar5 != (long *)0x0) &&
         (iVar3 = (**(code **)(*plVar5 + 0xd0))(plVar5,param_2,param_3,param_4,param_5,param_6),
         iVar3 == 0)) {
        bVar1 = false;
        lVar7 = 1;
LAB_fffffff0081fdeb4:
        (**(code **)(*(long *)param_1[lVar7 + 0x5a] + 0xd8))
                  ((long *)param_1[lVar7 + 0x5a],param_2,param_3,param_4,param_6);
        if (bVar1) {
          (**(code **)(*(long *)param_1[lVar7 + 0x59] + 0xd8))
                    ((long *)param_1[lVar7 + 0x59],param_2,param_3,param_4,param_6);
        }
        return false;
      }
      plVar5 = (long *)param_1[0x5d];
      if ((plVar5 != (long *)0x0) &&
         (uVar6 = (**(code **)(*plVar5 + 0xd0))(plVar5,param_2,param_3,param_4,param_5,param_6),
         (uVar6 & 1) == 0)) {
        bVar1 = true;
        lVar7 = 2;
        goto LAB_fffffff0081fdeb4;
      }
    }
    if (cVar8 == '\0') {
      return true;
    }
  }
  uVar4 = (**(code **)(*param_1 + 0x1a8))(param_1,param_3,param_5,0,0,0,0);
  iVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  uVar2 = uVar4 & 0xfffffdfd;
  if (iVar3 != 2) {
    uVar2 = uVar4;
  }
  uVar4 = uVar2 & 0xfffffdff;
  if (cVar8 != '\x01') {
    uVar4 = uVar2;
  }
  lVar7 = param_1[2];
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar7 + 0x11a70));
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar7 + 0x11a78));
  if ((DAT_fffffff00ae25928 & 1) == 0) {
    FUN_fffffff0082105b8(*(undefined8 *)(param_1[0x5a] + 0x18),param_2,param_3,param_4,uVar4);
    bVar1 = true;
  }
  else {
    iVar3 = thunk_EXT_FUN_80110000039ea318
                      (*(undefined8 *)(param_1[0x5a] + 0x10),param_2,param_3,param_4,uVar4);
    bVar1 = iVar3 == 0;
  }
  lVar7 = param_1[2];
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar7 + 0x11a78));
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar7 + 0x11a70));
  return bVar1;
}

