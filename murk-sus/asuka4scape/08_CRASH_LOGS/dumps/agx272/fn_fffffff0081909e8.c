// FUN_fffffff0081909e8 @ fffffff0081909e8 size=456

undefined8
FUN_fffffff0081909e8
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  code *pcVar8;
  long *local_58;
  
  local_58 = (long *)0x0;
  uVar2 = thunk_EXT_FUN_8011000002972b90();
  iVar1 = thunk_EXT_FUN_80110000039a3b60(uVar2,param_2,&local_58);
  if ((iVar1 == 0) &&
     (lVar3 = thunk_EXT_FUN_8011000003890f30(local_58,*(undefined8 *)PTR_DAT_fffffff007ca6080),
     lVar3 != 0)) {
    thunk_EXT_FUN_8011000002c12750();
    uVar4 = thunk_EXT_FUN_8011000002c13584();
    if ((uVar4 & 1) != 0) {
      uVar2 = 0;
      goto LAB_fffffff008190a44;
    }
    iVar1 = thunk_EXT_FUN_80110000029479f8
                      (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498);
    lVar5 = thunk_EXT_FUN_8011000002c12750(lVar3);
    if (iVar1 != 0) {
      thunk_EXT_FUN_8011000002c13530(lVar5);
      uVar2 = 1;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,1,
                 "Event ID %u signal value (%llu) will use fallback path since queue is idle");
      pcVar8 = *(code **)(PTR_DAT_fffffff007ca6130 + 0x130);
      uVar6 = thunk_EXT_FUN_8011000002c12750(lVar3);
      (*pcVar8)(param_1,uVar6,param_3);
      goto LAB_fffffff008190a44;
    }
    thunk_EXT_FUN_801100000295d6bc(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x160),4);
    if (lVar5 == 0) {
LAB_fffffff008190ba8:
      uVar7 = 8;
      goto LAB_fffffff008190a3c;
    }
    if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac44) >> 3 & 1) != 0) {
      FUN_fffffff00817dc48(*(long *)(param_1 + 0x530),0x344,0,lVar5,param_3,1,param_4,0);
    }
    uVar4 = FUN_fffffff00818e21c(param_1,lVar5,param_3,param_4,param_5);
    if ((uVar4 & 1) == 0) goto LAB_fffffff008190ba8;
  }
  else {
    uVar7 = 10;
LAB_fffffff008190a3c:
    *(undefined4 *)(param_1 + 0x520) = uVar7;
  }
  uVar2 = 1;
LAB_fffffff008190a44:
  if (local_58 != (long *)0x0) {
    (**(code **)(*local_58 + 0x28))();
  }
  return uVar2;
}

