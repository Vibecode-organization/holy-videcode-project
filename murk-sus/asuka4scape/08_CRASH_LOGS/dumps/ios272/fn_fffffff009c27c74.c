// FUN_fffffff009c27c74 @ fffffff009c27c74 size=1264

long * FUN_fffffff009c27c74(long param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  int iVar8;
  long lVar9;
  undefined8 local_f8;
  undefined8 local_f0;
  ulong uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 auStack_b8 [9];
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar1 = (long *)thunk_EXT_FUN_801100000389d0d8(3);
  if (plVar1 != (long *)0x0) {
    FUN_fffffff009c28164(plVar1,"iosurface_id",*(undefined4 *)(param_1 + 0x10));
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
    plVar2 = (long *)thunk_EXT_FUN_80110000038961f4(1);
    if (plVar2 != (long *)0x0) {
      if (*(long *)(param_1 + 0x240) != 0) {
        iVar8 = 0;
        lVar7 = *(long *)(param_1 + 0x240);
        do {
          lVar9 = *(long *)(lVar7 + 0x58);
          plVar3 = (long *)thunk_EXT_FUN_801100000389d0d8(3);
          if (plVar3 != (long *)0x0) {
            auStack_b8[7] = 0;
            auStack_b8[4] = 0;
            auStack_b8[3] = 0;
            auStack_b8[6] = 0;
            auStack_b8[5] = 0;
            auStack_b8[0] = 0;
            local_c0 = 0;
            auStack_b8[2] = 0;
            auStack_b8[1] = 0;
            uStack_d8 = 0;
            local_e0 = 0;
            uStack_c8 = 0;
            uStack_d0 = 0;
            uStack_e8 = 0;
            local_f0 = 0;
            FUN_fffffff009c413b4(lVar7,&local_f0);
            FUN_fffffff009c28164(plVar3,"iofence_acceleratorid",local_f0._4_4_);
            FUN_fffffff009c28164(plVar3,"iofence_direction",uStack_e8 & 0xffffffff);
            plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(8);
            lVar7 = 0;
            do {
              plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(auStack_b8[lVar7],0x40);
              if (plVar5 != (long *)0x0) {
                (**(code **)(*plVar4 + 0xf0))(plVar4,lVar7,plVar5);
                (**(code **)(*plVar5 + 0x28))(plVar5);
              }
              lVar7 = lVar7 + 1;
            } while (lVar7 != 8);
            if (plVar4 != (long *)0x0) {
              (**(code **)(*plVar3 + 0x100))(plVar3,"iofence_backtrace",plVar4);
            }
            (**(code **)(*plVar2 + 0xf0))(plVar2,iVar8,plVar3);
            if (plVar4 != (long *)0x0) {
              (**(code **)(*plVar4 + 0x28))(plVar4);
            }
            iVar8 = iVar8 + 1;
            (**(code **)(*plVar3 + 0x28))(plVar3);
          }
          lVar7 = lVar9;
        } while (lVar9 != 0);
      }
      (**(code **)(*plVar1 + 0x100))(plVar1,"iofence_current_queue",plVar2);
    }
    plVar3 = (long *)thunk_EXT_FUN_80110000038961f4(1);
    if (plVar3 == (long *)0x0) {
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    }
    else {
      if (*(long *)(param_1 + 0x250) != 0) {
        iVar8 = 0;
        lVar7 = *(long *)(param_1 + 0x250);
        do {
          lVar9 = *(long *)(lVar7 + 0x58);
          plVar4 = (long *)thunk_EXT_FUN_801100000389d0d8(3);
          if (plVar4 != (long *)0x0) {
            auStack_b8[7] = 0;
            auStack_b8[4] = 0;
            auStack_b8[3] = 0;
            auStack_b8[6] = 0;
            auStack_b8[5] = 0;
            auStack_b8[0] = 0;
            local_c0 = 0;
            auStack_b8[2] = 0;
            auStack_b8[1] = 0;
            uStack_d8 = 0;
            local_e0 = 0;
            uStack_c8 = 0;
            uStack_d0 = 0;
            uStack_e8 = 0;
            local_f0 = 0;
            FUN_fffffff009c413b4(lVar7,&local_f0);
            FUN_fffffff009c28164(plVar4,"iofence_acceleratorid",local_f0._4_4_);
            FUN_fffffff009c28164(plVar4,"iofence_direction",uStack_e8 & 0xffffffff);
            plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(8);
            lVar7 = 0;
            do {
              local_f8 = 0;
              thunk_EXT_FUN_80110000032db760(auStack_b8[lVar7],&local_f8);
              plVar6 = (long *)thunk_EXT_FUN_80110000038c6e24(local_f8,0x40);
              if (plVar6 != (long *)0x0) {
                (**(code **)(*plVar5 + 0xf0))(plVar5,lVar7,plVar6);
                (**(code **)(*plVar6 + 0x28))(plVar6);
              }
              lVar7 = lVar7 + 1;
            } while (lVar7 != 8);
            if (plVar5 != (long *)0x0) {
              (**(code **)(*plVar4 + 0x100))(plVar4,"iofence_backtrace",plVar5);
            }
            (**(code **)(*plVar3 + 0xf0))(plVar3,iVar8,plVar4);
            if (plVar5 != (long *)0x0) {
              (**(code **)(*plVar5 + 0x28))(plVar5);
            }
            iVar8 = iVar8 + 1;
            (**(code **)(*plVar4 + 0x28))(plVar4);
          }
          lVar7 = lVar9;
        } while (lVar9 != 0);
      }
      (**(code **)(*plVar1 + 0x100))(plVar1,"iofence_waiting_queue",plVar3);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_70) {
    return plVar1;
  }
  plVar1 = (long *)thunk_EXT_FUN_8011000003a48590();
  return plVar1;
}

