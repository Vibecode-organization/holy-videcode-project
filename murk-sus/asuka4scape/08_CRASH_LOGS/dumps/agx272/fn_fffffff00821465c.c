// FUN_fffffff00821465c @ fffffff00821465c size=428

/* WARNING: Removing unreachable block (ram,0xfffffff0082146e4) */

undefined8 FUN_fffffff00821465c(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  plVar5 = *(long **)(param_1 + 0xc0);
  plVar2 = (long *)(**(code **)(*plVar5 + 0x880))(plVar5);
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  local_50 = 0;
  uStack_68 = 0;
  local_70 = 0;
  (**(code **)(*plVar5 + 0x850))(&local_70,plVar5);
  if (plVar2 != (long *)0x0) {
    uStack_98 = uStack_68;
    local_a0 = local_70;
    uStack_88 = uStack_58;
    uStack_90 = local_60;
    uStack_78 = uStack_48;
    local_80 = local_50;
    uVar3 = (**(code **)(*plVar2 + 0x80))(plVar2,plVar5,param_2,&local_a0,param_3);
    if ((uVar3 & 1) != 0) {
      *(long **)(param_1 + 0x228) = plVar2;
      lVar4 = *(long *)(param_1 + 0xc0);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 800));
      lVar1 = plVar2[0x41];
      *(int *)(plVar2 + 0x41) = (int)lVar1 + 1;
      if ((int)lVar1 == 0) {
        (**(code **)(*plVar2 + 0x20))(plVar2);
        plVar5 = *(long **)(lVar4 + 0x330);
        plVar2[0x3f] = 0;
        plVar2[0x40] = (long)plVar5;
        *plVar5 = (long)plVar2;
        *(long **)(lVar4 + 0x330) = plVar2 + 0x3f;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 800));
      return 1;
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  *(undefined8 *)(param_1 + 0x228) = 0;
  thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to create PM\n")
  ;
  return 0;
}

