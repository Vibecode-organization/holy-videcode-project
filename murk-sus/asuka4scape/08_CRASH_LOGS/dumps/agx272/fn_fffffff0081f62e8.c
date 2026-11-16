// FUN_fffffff0081f62e8 @ fffffff0081f62e8 size=724

/* WARNING: Removing unreachable block (ram,0xfffffff0081f63c0) */

bool FUN_fffffff0081f62e8(long param_1,long param_2,long *param_3)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  ulong uVar9;
  undefined4 local_88;
  long local_84;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_44;
  
  if (param_3 != (long *)0x0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x420));
    if (*(long *)(param_1 + 0x418) != 0) {
      lVar7 = 0;
      uVar1 = param_1 + 0x18;
      do {
        if (*(long *)(uVar1 + lVar7 * 0x40) == param_2) {
          uVar9 = uVar1 + lVar7 * 0x40;
          if (((uVar1 ^ uVar9) & 0xffc0000000000000) != 0) {
            uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if (*(long *)(uVar9 + 0x18) == 0) {
            (**(code **)(*param_3 + 0x20))(param_3);
            *(long **)(uVar9 + 0x18) = param_3;
            uVar4 = (**(code **)(*param_3 + 0x438))
                              (*param_3 + 0x438,param_3,*(undefined8 *)PTR_DAT_fffffff007ca61b8,
                               FUN_fffffff0081f65bc,param_1,0);
            if (*(long **)(uVar9 + 0x10) != (long *)0x0) {
              (**(code **)(**(long **)(uVar9 + 0x10) + 0x28))();
            }
            *(undefined8 *)(uVar9 + 0x10) = uVar4;
            plVar5 = (long *)(**(code **)(*param_3 + 0x148))
                                       (param_3,"SharedEventAgentSignalEnabled");
            plVar6 = (long *)thunk_EXT_FUN_8011000003890f30
                                       (plVar5,*(undefined8 *)PTR_DAT_fffffff007ca60c8);
            uVar2 = 0;
            if (plVar6 != (long *)0x0) {
              uVar2 = (**(code **)(*plVar6 + 0x88))();
            }
            *(char *)(uVar9 + 0x38) = (char)uVar2;
            if (*(long *)(param_1 + 0x10) != 0) {
              uStack_50 = 0;
              local_58 = 0;
              uStack_60 = 0;
              local_68 = 0;
              uStack_70 = 0;
              local_78 = 0;
              local_88 = 0x3b;
              lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
              local_44 = 3;
              local_84 = param_2;
              local_7c = uVar2;
              uVar4 = (**(code **)(*(long *)(lVar7 + 0x848) + 0x30))(lVar7 + 0x848);
              local_48 = 0;
              plVar6 = *(long **)(*(long *)(lVar7 + 0x280) + 0x310);
              puVar8 = (undefined8 *)(*plVar6 + 0xe8);
              iVar3 = (*(code *)*puVar8)(puVar8,plVar6,FUN_fffffff00817ea94,&local_88,&local_44,
                                         &local_48,0);
              if ((iVar3 == 0) && (((byte)local_44 >> 1 & 1) != 0)) {
                FUN_fffffff0081a43cc(lVar7,uVar4,local_48);
              }
            }
            (**(code **)(*param_3 + 0x1e8))(param_3,0);
            if (plVar5 != (long *)0x0) {
              (**(code **)(*plVar5 + 0x28))(plVar5);
            }
          }
          break;
        }
        lVar7 = lVar7 + 1;
      } while (*(long *)(param_1 + 0x418) != lVar7);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x420));
  }
  return param_3 != (long *)0x0;
}

