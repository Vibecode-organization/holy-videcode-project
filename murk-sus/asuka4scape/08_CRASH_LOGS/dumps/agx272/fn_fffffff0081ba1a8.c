// FUN_fffffff0081ba1a8 @ fffffff0081ba1a8 size=1096

/* WARNING: Removing unreachable block (ram,0xfffffff0081ba2a0) */

undefined8 FUN_fffffff0081ba1a8(long *param_1,long *param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulong uVar10;
  undefined8 uVar11;
  long lVar12;
  undefined8 uVar13;
  long lVar14;
  
  lVar14 = 0;
  uVar11 = *(undefined8 *)PTR_DAT_fffffff007ca60c8;
  lVar12 = 0x13;
  uVar13 = *(undefined8 *)PTR_DAT_fffffff007ca60a8;
  do {
    uVar1 = (&DAT_fffffff007c96050)[lVar14 * 3];
    pcVar2 = (code *)(&DAT_fffffff007c96058)[lVar14 * 3];
    lVar4 = (**(code **)(*param_2 + 0x138))(param_2,uVar1);
    if (lVar4 != 0) {
      lVar4 = thunk_EXT_FUN_8011000003890f30(lVar4,uVar11);
      if (lVar4 == 0) {
        return 0xe00002c2;
      }
      lVar4 = (**(code **)(*param_2 + 0x138))(param_2,"ID");
      lVar5 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"Value");
      if (lVar4 == 0 || lVar5 == 0) {
        return 0xe00002c2;
      }
      plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar4,uVar13);
      plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,uVar13);
      if (plVar6 == (long *)0x0 || plVar7 == (long *)0x0) {
        return 0xe00002c2;
      }
      uVar8 = (**(code **)(*plVar6 + 0xa0))(plVar6);
      uVar9 = (**(code **)(*plVar7 + 0xb0))(plVar7);
      uVar10 = (*pcVar2)(param_1,uVar8,uVar9);
      if ((uVar10 & 1) == 0) {
        (**(code **)(*plVar6 + 0xa0))(plVar6);
        (**(code **)(*plVar7 + 0xa0))(plVar7);
        return 0xe00002c2;
      }
    }
    iVar3 = thunk_EXT_FUN_8011000003a7051c(uVar1,"SetDPEBudget");
    if (iVar3 == 0) {
      (**(code **)(*param_1 + 0x2b8))(param_1,0xc);
    }
    lVar14 = lVar14 + 1;
    lVar12 = lVar12 + -1;
    if (lVar12 == 0) {
      uVar11 = FUN_fffffff0081b991c(param_1,param_2,"SetDPESLConfig",FUN_fffffff0081bab50,0);
      if (((((((int)uVar11 == 0) &&
             (uVar11 = FUN_fffffff0081b991c
                                 (param_1,param_2,"SetDPECSwitchBudget",FUN_fffffff0081bab38,0),
             (int)uVar11 == 0)) &&
            (uVar11 = FUN_fffffff0081b991c
                                (param_1,param_2,"SetDPETrigSteering",FUN_fffffff0081bab20,0),
            (int)uVar11 == 0)) &&
           ((uVar11 = FUN_fffffff0081b991c(param_1,param_2,"SetDPEACCtrl",FUN_fffffff0081bab08,0),
            (int)uVar11 == 0 &&
            (uVar11 = FUN_fffffff0081b991c
                                (param_1,param_2,"SetDPEImaxPredCtrl",FUN_fffffff0081baaf0,0),
            (int)uVar11 == 0)))) &&
          ((uVar11 = FUN_fffffff0081b991c
                               (param_1,param_2,"SetDPEImaxReactCtrl",FUN_fffffff0081baad8,0),
           (int)uVar11 == 0 &&
           ((uVar11 = FUN_fffffff0081ba5f0
                                (param_1,param_2,"SetDPEImaxPredTrigThresh",FUN_fffffff0081baa30,0),
            (int)uVar11 == 0 &&
            (uVar11 = FUN_fffffff0081ba5f0
                                (param_1,param_2,"SetDPEImaxReactTrigThresh",FUN_fffffff0081ba988,0)
            , (int)uVar11 == 0)))))) &&
         (uVar11 = FUN_fffffff0081ba5f0
                             (param_1,param_2,"SetDPEDCCompDshiftThresh",FUN_fffffff0081ba8e0,0),
         (int)uVar11 == 0)) {
        (**(code **)(*param_1 + 0x2b8))(param_1,0xd);
        uVar11 = 0;
      }
      return uVar11;
    }
  } while( true );
}

