// FUN_fffffff0081f0710 @ fffffff0081f0710 size=1180

undefined8 FUN_fffffff0081f0710(long *param_1,int *param_2)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong unaff_x30;
  undefined4 local_34;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  iVar5 = *param_2;
  if (iVar5 < 5) {
    if (iVar5 < 3) {
      if (iVar5 == 1) {
        param_2[1] = (int)param_1[9];
      }
      else {
        if (iVar5 != 2) {
          return 0;
        }
        if (*(uint *)(param_1 + 9) <= (uint)*(byte *)(param_2 + 1)) goto LAB_fffffff0081f0b18;
        uVar8 = param_1[7];
        if (uVar8 == 0) goto LAB_fffffff0081f0ba0;
        uVar10 = uVar8 + (ulong)*(uint *)(param_1 + 8) * 0x68;
        if (((uVar8 ^ uVar10) & 0xffc0000000000000) != 0) {
          uVar10 = uVar10 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar10 < uVar8) || (uVar10 - uVar8 >> 0x20 != 0)) goto LAB_fffffff0081f0b88;
        uVar3 = (uint)*(byte *)(param_2 + 1) * 0x68;
        if ((uint)(uVar10 - uVar8) < uVar3 + 0x68) goto LAB_fffffff0081f0ba0;
        plVar1 = (long *)(uVar8 + uVar3);
        uVar10 = (ulong)CARRY8(uVar8,(ulong)uVar3);
        uVar8 = -uVar10;
        if ((uVar8 != uVar10) || ((long)uVar8 < 0)) goto LAB_fffffff0081f0b94;
        if (*(long *)(param_2 + 2) != 0) {
          if (param_2[4] == 0) {
            return 0;
          }
          local_34 = 0;
          iVar5 = thunk_EXT_FUN_80110000031cd550(*plVar1 + 8);
          uVar3 = param_2[4];
          if (iVar5 + 1U < uVar3) {
            uVar3 = iVar5 + 1;
          }
          thunk_EXT_FUN_8011000003386690(*plVar1 + 8,*(undefined8 *)(param_2 + 2),uVar3 - 1);
          thunk_EXT_FUN_8011000003386690(&local_34,(ulong)uVar3 + *(long *)(param_2 + 2) + -1,1);
        }
        puVar7 = (undefined8 *)*plVar1;
        param_2[5] = *(int *)(puVar7 + 3);
        *(undefined8 *)(param_2 + 6) = *puVar7;
      }
    }
    else {
      if (iVar5 == 3) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f0994. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
          uVar6 = (**(code **)(*param_1 + 200))(param_1,param_2,(undefined8 *)(*param_1 + 200));
          return uVar6;
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f098c);
        (*pcVar4)();
      }
      if (iVar5 != 4) {
        return 0;
      }
      if ((int)param_1[9] == 0) {
        return 0;
      }
      uVar3 = param_2[1];
      if ((uVar3 & 0xfffff983) != 0) goto LAB_fffffff0081f0b18;
      *(uint *)((long)param_1 + 0x2c) = uVar3;
      if ((uVar3 >> 5 & 1) == 0) {
        *(undefined4 *)(param_1 + 6) = 0;
      }
      else {
        *(uint *)(param_1 + 6) = (uint)*(ushort *)(param_2 + 2);
      }
    }
    uVar6 = 1;
  }
  else {
    if (6 < iVar5) {
      if (iVar5 == 7) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f09ec. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
          uVar6 = (**(code **)(*param_1 + 0x100))
                            (param_1,param_2 + 2,(char)param_2[1],(undefined8 *)(*param_1 + 0x100));
          return uVar6;
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f09e4);
        (*pcVar4)();
      }
      if (iVar5 == 8) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f0b78. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
          uVar6 = (**(code **)(*param_1 + 0x98))(param_1,(undefined8 *)(*param_1 + 0x98));
          return uVar6;
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f0b70);
        (*pcVar4)();
      }
      if (iVar5 != 9) {
        return 0;
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f07a0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar6 = (**(code **)(*param_1 + 0xa0))(param_1,(undefined8 *)(*param_1 + 0xa0));
        return uVar6;
      }
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f0798);
      (*pcVar4)();
    }
    if (iVar5 != 5) {
      if (iVar5 != 6) {
        return 0;
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f093c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar6 = (**(code **)(*param_1 + 0xf8))
                          (param_1,(char)param_2[1],(undefined8 *)(*param_1 + 0xf8));
        return uVar6;
      }
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f0934);
      (*pcVar4)();
    }
    if ((uint)*(byte *)(param_2 + 1) < *(uint *)(param_1 + 9)) {
      uVar8 = param_1[7];
      if (uVar8 == 0) {
LAB_fffffff0081f0ba0:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                  );
      }
      uVar10 = uVar8 + (ulong)*(uint *)(param_1 + 8) * 0x68;
      if (((uVar8 ^ uVar10) & 0xffc0000000000000) != 0) {
        uVar10 = uVar10 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar10 < uVar8) || (uVar10 - uVar8 >> 0x20 != 0)) {
LAB_fffffff0081f0b88:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                  );
      }
      uVar3 = (uint)*(byte *)(param_2 + 1) * 0x68;
      uVar9 = (ulong)uVar3;
      uVar3 = uVar3 + 0x68;
      if ((uint)(uVar10 - uVar8) < uVar3) goto LAB_fffffff0081f0ba0;
      plVar1 = (long *)(uVar8 + uVar9);
      uVar10 = -(ulong)CARRY8(uVar8,uVar9);
      if ((uVar10 != CARRY8(uVar8,uVar9)) || ((long)uVar10 < 0)) {
LAB_fffffff0081f0b94:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                  );
      }
      if (*(int *)(*plVar1 + 0x18) == 0) {
        return 0;
      }
      uVar2 = param_2[2];
      if (uVar2 - 0x80 < 0xffffff81) {
        return 0;
      }
      if ((uVar2 & 9) == 9) {
        return 0;
      }
      iVar5 = param_2[3];
      *(uint *)(plVar1 + 1) = uVar2;
      *(int *)((long)plVar1 + 0xc) = iVar5;
      uVar2 = param_2[4];
      if (uVar2 < 2) {
        uVar2 = 1;
      }
      *(uint *)(plVar1 + 2) = uVar2;
      if ((*(byte *)((long)param_2 + 0xd) >> 2 & 1) == 0) {
        uVar8 = param_1[7];
        if (uVar8 != 0) {
          uVar10 = uVar8 + (ulong)*(uint *)(param_1 + 8) * 0x68;
          if (((uVar8 ^ uVar10) & 0xffc0000000000000) != 0) {
            uVar10 = uVar10 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar10 < uVar8) || (uVar10 - uVar8 >> 0x20 != 0)) goto LAB_fffffff0081f0b88;
          if (uVar3 <= (uint)(uVar10 - uVar8)) {
            uVar10 = -(ulong)CARRY8(uVar8,uVar9);
            if ((uVar10 == CARRY8(uVar8,uVar9)) && (-1 < (long)uVar10)) {
              *(undefined1 *)(uVar8 + uVar9 + 0x14) = 1;
              return 1;
            }
            goto LAB_fffffff0081f0b94;
          }
        }
        goto LAB_fffffff0081f0ba0;
      }
    }
LAB_fffffff0081f0b18:
    uVar6 = 0;
  }
  return uVar6;
}

