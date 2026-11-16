// FUN_fffffff009cc463c @ fffffff009cc463c

/* WARNING: Removing unreachable block (ram,0xfffffff009cc4920) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cc49f8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cc47e8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cc4870) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cc46dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cc4c20) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cc47a0) */

undefined8
FUN_fffffff009cc463c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,int param_8,int param_9)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  byte bVar6;
  ushort uVar7;
  long lVar8;
  undefined8 uVar9;
  short *psVar10;
  undefined1 auVar11 [16];
  
  uVar9 = 0xe00002c7;
  if (param_8 < 3) {
    if (param_9 != 1) goto LAB_fffffff009cc4ae4;
    if ((*(byte *)((long)param_7 + 0x43c) & 1) == 0) {
      (**(code **)(*param_7 + 0x810))(param_7,0x700,0x16,0x400000,0);
    }
    else {
      (**(code **)(*param_7 + 0x810))(param_7,0x704,0x14,0xf00000,6);
      (**(code **)(*param_7 + 0x810))(*param_7 + 0x810,param_7,0x11c,0x18,0x1000000,1);
      (**(code **)(*param_7 + 0x810))(*param_7 + 0x810,param_7,0x700,0x16,0x400000,1);
    }
  }
  else if (param_9 == 2) {
    lVar4 = (**(code **)(*(long *)param_7[0x17] + 0x118))((long *)param_7[0x17],"u2-init-disable");
    lVar8 = *param_7;
    if (lVar4 != 0) {
      (**(code **)(lVar8 + 0x808))(lVar8 + 0x808,param_7,0x704,0xfffff7ff);
      (**(code **)(*param_7 + 0x808))(param_7,0x704,0xffffefff);
      *(undefined1 *)((long)param_7 + 0x43b) = 0;
      return 0xe00002c7;
    }
    (**(code **)(lVar8 + 0x800))(lVar8 + 0x800,param_7,0x704,0x800);
    (**(code **)(*param_7 + 0x808))(*param_7 + 0x808,param_7,0x704,0xffffefff);
    if ((*(byte *)((long)param_7 + 0x43b) & 1) != 0) {
      if ((*(short *)((long)param_7 + 0x436) == 0) ||
         (uVar7 = *(ushort *)(param_7 + 0x87), uVar7 == 0)) {
        pcVar5 = *(code **)(*param_7 + 0x808);
        uVar9 = 0xffffefff;
LAB_fffffff009cc4ad8:
        (*pcVar5)(param_7,0x704,uVar9);
      }
      else {
        if (0x7c < uVar7) {
          uVar7 = 0x7d;
        }
        iVar3 = (**(code **)(*param_7 + 0x7e8))(param_7,2,uVar7);
        if (iVar3 == 0) {
          pcVar5 = *(code **)(*param_7 + 0x800);
          uVar9 = 0x1000;
          goto LAB_fffffff009cc4a88;
        }
      }
    }
  }
  else {
    if (param_9 != 1) goto LAB_fffffff009cc4ae4;
    lVar4 = (**(code **)(*(long *)param_7[0x17] + 0x118))((long *)param_7[0x17],"u1-init-disable");
    lVar8 = *param_7;
    if (lVar4 != 0) {
      (**(code **)(lVar8 + 0x808))(lVar8 + 0x808,param_7,0x704,0xfffffdff);
      (**(code **)(*param_7 + 0x808))(param_7,0x704,0xfffffbff);
      *(undefined1 *)((long)param_7 + 0x43a) = 0;
      return 0xe00002c7;
    }
    (**(code **)(lVar8 + 0x800))(lVar8 + 0x800,param_7,0x704,0x200);
    (**(code **)(*param_7 + 0x808))(*param_7 + 0x808,param_7,0x704,0xfffffbff);
    if ((*(byte *)((long)param_7 + 0x43a) & 1) != 0) {
      if ((*(char *)((long)param_7 + 0x434) == '\0') ||
         (bVar6 = *(byte *)((long)param_7 + 0x435), bVar6 == 0)) {
        pcVar5 = *(code **)(*param_7 + 0x808);
        uVar9 = 0xfffffbff;
        goto LAB_fffffff009cc4ad8;
      }
      if ((*(byte *)((long)param_7 + 0x43b) & 1) == 0) {
        if (0x7c < bVar6) {
          bVar6 = 0x7d;
        }
        iVar3 = (**(code **)(*param_7 + 0x7e8))(param_7,2,bVar6);
        if (iVar3 != 0) goto LAB_fffffff009cc4ae0;
      }
      pcVar5 = *(code **)(*param_7 + 0x800);
      uVar9 = 0x400;
LAB_fffffff009cc4a88:
      (*pcVar5)(param_7,0x704,uVar9);
    }
  }
LAB_fffffff009cc4ae0:
  uVar9 = 0;
LAB_fffffff009cc4ae4:
  uVar1 = *(uint *)((long)param_7 + 500);
  if ((int)param_7[0x4c7] == 0) {
    if ((uVar1 >> 3 & 1) != 0) {
      if (((uVar1 >> 0x1e & 1) == 0) || (bVar2 = thunk_FUN_fffffff00a394140(), !bVar2)) {
        psVar10 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar11 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar11,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar10,0,
                   (byte *)"%s@%s: %s::%s: speed %d linkState %d return status 0x%08x\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"%s@%s: %s::%s: speed %d linkState %d return status 0x%08x\n");
      }
    }
  }
  else if ((uVar1 >> 3 & 1) != 0) {
    FUN_fffffff009cacb28
              ((ulong)param_7,
               (byte *)"AppleUSBXDCI::%s:speed %d linkState %d return status 0x%08x\n");
  }
  return uVar9;
}

