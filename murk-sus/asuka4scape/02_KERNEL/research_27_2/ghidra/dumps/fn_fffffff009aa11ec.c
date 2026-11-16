// FUN_fffffff009aa11ec @ fffffff009aa11ec size=312
// CALLERS:
//   fffffff00afb8174 no-fn
//   fffffff009aa14bc FUN_fffffff009aa1460@fffffff009aa1460
// CALLEES:
//   fffffff009abd2fc thunk_EXT_FUN_80110000039a2b94
//   fffffff009abdbcc thunk_EXT_FUN_8011000003a7051c
//   fffffff009abdb3c thunk_EXT_FUN_80110000032032e4
//   fffffff009abd3dc thunk_EXT_FUN_8011000003890f30

undefined4 FUN_fffffff009aa11ec(undefined8 param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined4 uVar7;
  long lVar8;
  
  plVar3 = (long *)thunk_EXT_FUN_80110000039a2b94
                             (param_1,"com.apple.private.iomfb.set-block-client-profile");
  if (plVar3 == (long *)0x0) {
    uVar7 = 0;
  }
  else {
    plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(plVar3,*(undefined8 *)PTR_DAT_fffffff00802a3f0);
    lVar8 = 0;
    do {
      uVar5 = (**(code **)(*plVar4 + 0xa8))(plVar4);
      iVar2 = thunk_EXT_FUN_8011000003a7051c(uVar5,(&DAT_fffffff008023a48)[lVar8]);
      if (iVar2 == 0) {
        *param_2 = (int)lVar8;
        uVar7 = 1;
        goto LAB_fffffff009aa12ec;
      }
      lVar8 = lVar8 + 1;
    } while (lVar8 != 5);
    iVar2 = thunk_EXT_FUN_80110000032032e4();
    if (iVar2 == 0) {
      uVar7 = 0;
    }
    else {
      lVar8 = 0;
      bVar6 = false;
      do {
        uVar5 = (**(code **)(*plVar4 + 0xa8))(plVar4);
        iVar2 = thunk_EXT_FUN_8011000003a7051c(uVar5,(&DAT_fffffff008023a70)[lVar8]);
        if (iVar2 == 0) break;
        lVar8 = 1;
        bVar1 = !bVar6;
        bVar6 = true;
      } while (bVar1);
      uVar7 = 2;
      if (iVar2 != 0) {
        uVar7 = 0;
      }
    }
LAB_fffffff009aa12ec:
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return uVar7;
}

