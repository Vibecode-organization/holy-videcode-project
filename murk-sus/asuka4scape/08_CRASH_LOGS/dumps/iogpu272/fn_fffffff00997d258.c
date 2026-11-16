// FUN_fffffff00997d258 @ fffffff00997d258 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff00997d584) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997d5f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997d424) */

void FUN_fffffff00997d258(long param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  undefined8 uVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  long lStack_58;
  
  lStack_58 = *(long *)PTR_DAT_fffffff007ff2800;
  if (*(long *)(param_1 + 0x418) == 0) {
    uVar1 = thunk_EXT_FUN_80110000038961f4(1);
    *(undefined8 *)(param_1 + 0x418) = uVar1;
  }
  plVar2 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  plVar3 = (long *)thunk_EXT_FUN_80110000038d02e4("SysMem");
  (**(code **)(*plVar2 + 0x100))(plVar2,"MemoryPool",plVar3);
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(param_2,0x40);
  (**(code **)(*plVar2 + 0x100))(plVar2,"Size",plVar3);
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_b8 = 0;
  uStack_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  uStack_d8 = 0;
  uStack_e0 = 0;
  uStack_c8 = 0;
  uStack_d0 = 0;
  uStack_f8 = 0;
  uStack_100 = 0;
  uStack_e8 = 0;
  uStack_f0 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  thunk_EXT_FUN_80110000037693ec(&uStack_160,0x100,"%s");
  plVar3 = (long *)thunk_EXT_FUN_80110000038d02e4(&uStack_160);
  plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  (**(code **)(*plVar4 + 0xe8))(plVar4,plVar3);
  (**(code **)(*plVar2 + 0x100))(*plVar2 + 0x100,plVar2,"Devices",plVar4);
  (**(code **)(*plVar4 + 0x28))(plVar4);
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  plVar3 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  (**(code **)(*plVar2 + 0x100))(plVar2,"Descriptions",plVar3);
  plVar4 = (long *)thunk_EXT_FUN_80110000038ce200(param_4);
  (**(code **)(*plVar3 + 0xe8))(plVar3,plVar4);
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  (**(code **)(*plVar3 + 0x28))(plVar3);
  if (param_3 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
    plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24((long)param_3,0x20);
    (**(code **)(*plVar3 + 0x100))(*plVar3 + 0x100,plVar3,"PID",plVar4);
    plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(1);
    (**(code **)(*plVar5 + 0xe8))(plVar5,plVar3);
    (**(code **)(*plVar2 + 0x100))(*plVar2 + 0x100,plVar2,"Processes",plVar5);
    (**(code **)(*plVar5 + 0x28))(plVar5);
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  (**(code **)(**(long **)(param_1 + 0x418) + 0xe8))(*(long **)(param_1 + 0x418),plVar2);
  (**(code **)(*plVar2 + 0x28))(plVar2);
  if (*(long *)PTR_DAT_fffffff007ff2800 != lStack_58) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

