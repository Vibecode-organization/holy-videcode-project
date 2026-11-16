// FUN_fffffff009c443e0 @ fffffff009c443e0 size=1656

long * FUN_fffffff009c443e0
                 (long param_1,ulong param_2,undefined8 param_3,undefined8 param_4,long *param_5,
                 int param_6)

{
  long lVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  long *plVar15;
  long *plVar16;
  uint uVar17;
  long *plVar18;
  long lVar19;
  ulong uVar20;
  undefined8 local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  puVar2 = PTR_DAT_fffffff00806c9b0;
  if (plVar5 == (long *)0x0) {
    plVar16 = (long *)0x0;
  }
  else {
    if (param_2 == 0) {
LAB_fffffff009c44558:
      uVar6 = (**(code **)(*plVar5 + 0x90))(plVar5);
      lVar1 = (uVar6 & 0xffffffff) << 3;
      uVar7 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806c470,lVar1);
      if (uVar7 == 0) goto LAB_fffffff009c44708;
      plVar16 = (long *)thunk_EXT_FUN_8011000003898a6c(plVar5);
      if (plVar16 != (long *)0x0) {
        uVar20 = 0;
        uVar12 = uVar7 + (uVar6 & 0xffffffff) * 8;
        if (((uVar7 ^ uVar12) & 0xffc0000000000000) != 0) {
          uVar12 = uVar12 & 0xffffffffffff | 0xc8a2000000000000;
        }
        lVar19 = 0x10000000;
        plVar15 = (long *)0x0;
        while( true ) {
          uVar8 = (**(code **)(*plVar16 + 0x88))(plVar16);
          plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(uVar8,&DAT_fffffff00af48458);
          if (plVar9 != (long *)0x0) {
            (**(code **)(*plVar9 + 0x20))(plVar9);
          }
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          if (plVar9 == (long *)0x0) {
            (**(code **)(*plVar16 + 0x28))(plVar16);
            goto LAB_fffffff009c447a4;
          }
          plVar15 = (long *)plVar9[3];
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar15 + 0x20))(plVar15);
          }
          if ((uVar12 - uVar7 & 0xffffffff00000000) != 0 || uVar12 < uVar7) break;
          if (lVar19 == 0) goto LAB_fffffff009c44a48;
          if (((long)uVar20 < 0) || ((uint)(uVar12 - uVar7) < (int)(uVar20 >> 0x20) + 8U))
          goto LAB_fffffff009c44a4c;
          uVar14 = (ulong)CARRY8(uVar7,uVar20 >> 0x20);
          uVar13 = -uVar14;
          if ((uVar13 != uVar14) || ((long)uVar13 < 0)) goto LAB_fffffff009c44a50;
          *(long **)(uVar7 + (uVar20 >> 0x20)) = plVar15;
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          lVar19 = lVar19 + -1;
          uVar20 = uVar20 + 0x800000000;
          plVar15 = plVar9;
        }
        FUN_fffffff009c493e4();
LAB_fffffff009c44a48:
        FUN_fffffff009c491c8();
LAB_fffffff009c44a4c:
        FUN_fffffff009c493ac();
LAB_fffffff009c44a50:
        FUN_fffffff009c493c8();
        goto LAB_fffffff009c44a54;
      }
LAB_fffffff009c447a4:
      plVar15 = (long *)thunk_EXT_FUN_8011000003979b9c(uVar7,uVar6 & 0xffffffff,(uint)param_3 & 7,0)
      ;
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806c4c0,uVar7,lVar1);
      local_70 = thunk_EXT_FUN_8011000003890f30(plVar15,*(undefined8 *)PTR_DAT_fffffff00806c9e0);
      plVar16 = (long *)thunk_EXT_FUN_8011000003979b9c(&local_70,1,(uint)param_3 & 7,0);
      plVar9 = (long *)(**(code **)(DAT_fffffff00af48430 + 0x68))();
      (**(code **)(*plVar5 + 0x20))(plVar5);
      uVar8 = *(undefined8 *)(param_1 + 0x28);
      if (param_5 != (long *)0x0) {
        (**(code **)(*param_5 + 0x20))(param_5);
      }
      FUN_fffffff009c42434(plVar9,plVar16,plVar5,uVar8,param_5);
      uVar8 = thunk_EXT_FUN_8011000003890f30(plVar9,*(undefined8 *)PTR_DAT_fffffff00806ca08);
      thunk_EXT_FUN_8011000003977a94(plVar15,uVar8);
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0x20))(plVar9);
      }
      FUN_fffffff009c43f40(param_5,plVar9);
      plVar10 = (long *)thunk_EXT_FUN_8011000003898a6c(plVar5);
      if (plVar10 != (long *)0x0) {
        plVar18 = (long *)0x0;
        while( true ) {
          uVar8 = (**(code **)(*plVar10 + 0x88))(plVar10);
          plVar11 = (long *)thunk_EXT_FUN_8011000003890f30(uVar8,&DAT_fffffff00af48458);
          if (plVar11 != (long *)0x0) {
            (**(code **)(*plVar11 + 0x20))(plVar11);
          }
          if (plVar18 != (long *)0x0) {
            (**(code **)(*plVar18 + 0x28))(plVar18);
          }
          if (plVar11 == (long *)0x0) break;
          if (param_6 != 0) {
            FUN_fffffff009c4346c(plVar11);
          }
          FUN_fffffff009c43340(plVar11,param_3);
          plVar18 = plVar11;
        }
        (**(code **)(*plVar10 + 0x28))(plVar10);
      }
      if (plVar16 != (long *)0x0) {
        (**(code **)(*plVar16 + 0x20))(plVar16);
      }
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0x28))(plVar9);
      }
      if (plVar16 != (long *)0x0) {
        (**(code **)(*plVar16 + 0x28))(plVar16);
      }
      if (plVar15 != (long *)0x0) {
        (**(code **)(*plVar15 + 0x28))(plVar15);
      }
    }
    else {
      uVar17 = 9;
      do {
        iVar4 = (1 << (ulong)(*(uint *)puVar2 & 0x1f)) << (ulong)(uVar17 & 0x1f);
        if ((ulong)(long)iVar4 <= param_2) {
          do {
            (**(code **)(*plVar5 + 0x20))(plVar5);
            iVar3 = FUN_fffffff009c462d8(param_1,uVar17,param_3,plVar5,1);
            if (iVar3 == 0) goto LAB_fffffff009c44708;
            param_2 = param_2 - (long)iVar4;
          } while ((ulong)(long)iVar4 <= param_2);
        }
      } while ((uVar17 != 0) && (uVar17 = uVar17 - 1, param_2 != 0));
      if (param_2 <= (ulong)(long)(1 << (ulong)(*(uint *)puVar2 & 0x1f))) {
        if (param_2 != 0) {
          thunk_EXT_FUN_80110000038fe9a0
                    ("====> %s:%d Descriptor length isn\'t rounded to bucket size\n");
          (**(code **)(*plVar5 + 0x20))(plVar5);
          iVar4 = FUN_fffffff009c462d8(param_1,0,param_3,plVar5,1);
          if (iVar4 == 0) goto LAB_fffffff009c44708;
        }
        goto LAB_fffffff009c44558;
      }
      thunk_EXT_FUN_80110000038fe9a0
                ("====> %s:%d Unable to assemble descriptor of the correct length\n");
LAB_fffffff009c44708:
      plVar16 = (long *)0x0;
    }
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (param_5 != (long *)0x0) {
    (**(code **)(*param_5 + 0x28))(param_5);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return plVar16;
  }
LAB_fffffff009c44a54:
  plVar5 = (long *)thunk_EXT_FUN_8011000003a48590();
  return plVar5;
}

