// FUN_fffffff009c08894 @ fffffff009c08894

ulong FUN_fffffff009c08894(long *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  int local_64;
  
  puVar2 = PTR_DAT_fffffff008062398;
  puVar1 = PTR_DAT_fffffff00805fdd8;
  if (param_1 == (long *)0x0) {
LAB_fffffff009c08c14:
    uVar13 = 0;
  }
  else {
    lVar12 = *(long *)PTR_PTR_fffffff008064ba0;
    do {
      plVar6 = thunk_FUN_fffffff00a90bd60(param_1,*(long *)PTR_DAT_fffffff008064c08,2);
      if (plVar6 == (long *)0x0) goto LAB_fffffff009c08c14;
      plVar7 = (long *)(**(code **)(*plVar6 + 0x98))();
      if (plVar7 == (long *)0x0) {
        uVar13 = 0;
        bVar3 = true;
      }
      else {
        local_64 = 0;
        uVar13 = 0;
        do {
          plVar8 = thunk_FUN_fffffff00a894f30(plVar7,(long)puVar1);
          if (plVar8 != (long *)0x0) {
            plVar8 = thunk_FUN_fffffff00a90bd60(plVar7,*(long *)PTR_DAT_fffffff008064c08,0);
            if (plVar8 != (long *)0x0) {
              plVar9 = (long *)(**(code **)(*plVar8 + 0x98))();
              while (plVar9 != (long *)0x0) {
                plVar10 = thunk_FUN_fffffff00a894f30(plVar9,(long)puVar2);
                if (plVar10 != (long *)0x0) {
                  plVar9 = (long *)(**(code **)(*plVar9 + 0x118))(plVar9,"BSD Unit");
                  plVar9 = thunk_FUN_fffffff00a894f30(plVar9,lVar12);
                  if (plVar9 != (long *)0x0) {
                    uVar4 = (**(code **)(*plVar9 + 0xa8))();
                    uVar13 = uVar13 | (long)(1 << (ulong)(uVar4 & 0x1f));
                  }
                }
                plVar9 = (long *)(**(code **)(*plVar8 + 0x98))(plVar8);
              }
              iVar5 = (**(code **)(*plVar8 + 0x80))(plVar8);
              if (iVar5 == 0) {
                local_64 = 0x23;
              }
              (**(code **)(*plVar8 + 0x28))(plVar8);
            }
            plVar7 = (long *)(**(code **)(*plVar7 + 0x118))(plVar7,"throttle-unit");
            plVar7 = thunk_FUN_fffffff00a894f30(plVar7,lVar12);
            if ((plVar7 != (long *)0x0) &&
               (plVar8 = thunk_FUN_fffffff00a932f4c((byte *)"IOMedia",(long *)0x0),
               plVar8 != (long *)0x0)) {
              (**(code **)(*plVar8 + 0x100))(plVar8,"BSD Unit",plVar7);
              plVar7 = thunk_FUN_fffffff00a9326e0(plVar8);
              if (plVar7 != (long *)0x0) {
                plVar9 = (long *)(**(code **)(*plVar7 + 0x88))();
                if (plVar9 != (long *)0x0) {
                  uVar11 = FUN_fffffff009c08894(plVar9);
                  uVar13 = uVar11 | uVar13;
                }
                (**(code **)(*plVar7 + 0x28))(plVar7);
              }
              (**(code **)(*plVar8 + 0x28))(plVar8);
            }
            (**(code **)(*plVar6 + 0xb8))(plVar6);
          }
          plVar7 = (long *)(**(code **)(*plVar6 + 0x98))(plVar6);
        } while (plVar7 != (long *)0x0);
        bVar3 = local_64 == 0;
      }
      iVar5 = (**(code **)(*plVar6 + 0x80))(plVar6);
      (**(code **)(*plVar6 + 0x28))(plVar6);
    } while (iVar5 == 0 || !bVar3);
  }
  return uVar13;
}

