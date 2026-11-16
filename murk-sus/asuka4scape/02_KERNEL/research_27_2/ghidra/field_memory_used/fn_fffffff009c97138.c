// FUN_fffffff009c97138 @ fffffff009c97138

/* WARNING: Removing unreachable block (ram,0xfffffff009c97f10) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c973f0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c9736c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c972dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c97c00) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c97988) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c978dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c97b54) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c97fdc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c97324) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c98090) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c97448) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c977ac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c97674) */

long * FUN_fffffff009c97138
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
                 undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7)

{
  bool bVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  char *pcVar11;
  short *psVar12;
  undefined1 auVar13 [16];
  
  plVar2 = (long *)(**(code **)(*param_7 + 0x118))(param_7,"DeviceDescription");
  plVar2 = thunk_FUN_fffffff00a894f30(plVar2,*(long *)PTR_PTR_fffffff00807fa70);
  if (plVar2 == (long *)0x0) {
    if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
      return (long *)0x0;
    }
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
      psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar12,0,
                 (byte *)"%s@%s: %s::%s: Failed to get current device description\n");
      return (long *)0x0;
    }
    (**(code **)(*param_7 + 0x1e8))(param_7,0);
    (**(code **)(*param_7 + 0x218))(param_7,0);
    pcVar11 = "%s@%s: %s::%s: Failed to get current device description\n";
LAB_fffffff009c97608:
    thunk_FUN_fffffff00a9029a0((byte *)pcVar11);
    return (long *)0x0;
  }
  plVar2 = thunk_FUN_fffffff00a8a12fc(plVar2,0);
  if (plVar2 == (long *)0x0) {
    if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
      return (long *)0x0;
    }
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
      psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar12,0,
                 (byte *)"%s@%s: %s::%s: Failed to copy device description\n");
      return (long *)0x0;
    }
    (**(code **)(*param_7 + 0x1e8))(param_7,0);
    (**(code **)(*param_7 + 0x218))(param_7,0);
    pcVar11 = "%s@%s: %s::%s: Failed to copy device description\n";
    goto LAB_fffffff009c97608;
  }
  plVar3 = thunk_FUN_fffffff00a89a1f4(2);
  if (plVar3 == (long *)0x0) {
    if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar12,0,
                   (byte *)"%s@%s: %s::%s: Failed to allocate interfaces array\n");
        plVar10 = (long *)0x0;
        goto LAB_fffffff009c97dec;
      }
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: Failed to allocate interfaces array\n");
    }
    plVar10 = (long *)0x0;
    goto LAB_fffffff009c97dec;
  }
  plVar4 = thunk_FUN_fffffff00a8d2200("AppleUSBNCMControlAux");
  plVar5 = thunk_FUN_fffffff00a8d2200("AppleUSBNCMDataAux");
  if ((plVar4 == (long *)0x0) || (plVar5 == (long *)0x0)) {
    if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
        psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar12,0,
                   (byte *)"%s@%s: %s::%s: Failed to create interface name strings\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"%s@%s: %s::%s: Failed to create interface name strings\n");
      }
    }
    plVar10 = (long *)0x0;
    if (plVar5 != (long *)0x0) goto LAB_fffffff009c97d84;
  }
  else {
    (**(code **)(*plVar3 + 0xe8))(plVar3,plVar4);
    (**(code **)(*plVar3 + 0xe8))(plVar3,plVar5);
    plVar6 = thunk_FUN_fffffff00a8a10d8(4);
    if (plVar6 == (long *)0x0) {
      if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
          psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar12,0,
                     (byte *)"%s@%s: %s::%s: Failed to allocate config dictionary\n");
          plVar10 = (long *)0x0;
          goto LAB_fffffff009c97d84;
        }
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: Failed to allocate config dictionary\n");
      }
      plVar10 = (long *)0x0;
    }
    else {
      plVar7 = thunk_FUN_fffffff00a8cae24(0xc0,0x20);
      plVar8 = thunk_FUN_fffffff00a8cae24(0,0x20);
      if ((plVar7 == (long *)0x0) || (plVar8 == (long *)0x0)) {
        if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
          if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
             (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
            psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
            thunk_FUN_fffffff00a8df19c
                      (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar12,0,
                       (byte *)"%s@%s: %s::%s: Failed to create config attributes\n");
            plVar9 = (long *)0x0;
            goto LAB_fffffff009c97cf0;
          }
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          pcVar11 = "%s@%s: %s::%s: Failed to create config attributes\n";
LAB_fffffff009c97ce4:
          thunk_FUN_fffffff00a9029a0((byte *)pcVar11);
        }
LAB_fffffff009c97ce8:
        plVar9 = (long *)0x0;
LAB_fffffff009c97cf0:
        plVar10 = (long *)0x0;
      }
      else {
        plVar9 = thunk_FUN_fffffff00a8d2200("Fallback Configuration - ncmAux");
        if (plVar9 == (long *)0x0) {
          if ((*(uint *)((long)param_7 + 500) & 1) == 0) goto LAB_fffffff009c97ce8;
          if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) != 0) &&
             (bVar1 = thunk_FUN_fffffff00a394140(), bVar1)) {
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(param_7,0);
            pcVar11 = "%s@%s: %s::%s: Failed to create config description\n";
            goto LAB_fffffff009c97ce4;
          }
          psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar12,0,
                     (byte *)"%s@%s: %s::%s: Failed to create config description\n");
          plVar9 = (long *)0x0;
          goto LAB_fffffff009c97cf0;
        }
        (**(code **)(*plVar6 + 0x100))(plVar6,"Attributes",plVar7);
        (**(code **)(*plVar6 + 0x100))(*plVar6 + 0x100,plVar6,"MaxPower",plVar8);
        (**(code **)(*plVar6 + 0x100))(*plVar6 + 0x100,plVar6,"Interfaces",plVar3);
        (**(code **)(*plVar6 + 0x100))(*plVar6 + 0x100,plVar6,"Description",plVar9);
        plVar10 = thunk_FUN_fffffff00a89a1f4(1);
        if (plVar10 == (long *)0x0) {
          if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
            if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
               (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
              psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
              thunk_FUN_fffffff00a8df19c
                        (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar12,0,
                         (byte *)"%s@%s: %s::%s: Failed to allocate configurations array\n");
            }
            else {
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              (**(code **)(*param_7 + 0x218))(param_7,0);
              thunk_FUN_fffffff00a9029a0
                        ((byte *)"%s@%s: %s::%s: Failed to allocate configurations array\n");
            }
          }
          goto LAB_fffffff009c97cf0;
        }
        (**(code **)(*plVar10 + 0xe8))(plVar10,plVar6);
        (**(code **)(*plVar2 + 0x100))(*plVar2 + 0x100,plVar2,"ConfigurationDescriptors",plVar10);
        (**(code **)(*plVar2 + 0x100))
                  (*plVar2 + 0x100,plVar2,"AllowMultipleCreates",
                   **(undefined8 **)PTR_PTR_fffffff00807fb18);
        if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
          if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
             (bVar1 = thunk_FUN_fffffff00a394140(), !bVar1)) {
            psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
            thunk_FUN_fffffff00a8df19c
                      (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar12,0,
                       (byte *)"%s@%s: %s::%s: Successfully built fallback device description\n");
          }
          else {
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(param_7,0);
            thunk_FUN_fffffff00a9029a0
                      ((byte *)"%s@%s: %s::%s: Successfully built fallback device description\n");
          }
        }
        (**(code **)(*plVar10 + 0x28))(plVar10);
        plVar10 = plVar2;
        plVar2 = (long *)0x0;
      }
      (**(code **)(*plVar6 + 0x28))(plVar6);
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0x28))(plVar9);
      }
      if (plVar8 != (long *)0x0) {
        (**(code **)(*plVar8 + 0x28))();
      }
      if (plVar7 != (long *)0x0) {
        (**(code **)(*plVar7 + 0x28))(plVar7);
      }
    }
LAB_fffffff009c97d84:
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  (**(code **)(*plVar3 + 0x28))(plVar3);
  if (plVar2 == (long *)0x0) {
    return plVar10;
  }
LAB_fffffff009c97dec:
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return plVar10;
}

