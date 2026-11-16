// FUN_fffffff00997b640 @ fffffff00997b640 size=416

/* WARNING: Removing unreachable block (ram,0xfffffff00997b740) */

long * FUN_fffffff00997b640(undefined8 param_1,long *param_2)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007ff2800;
  plVar1 = (long *)thunk_EXT_FUN_801100000389d0d8(8);
  (**(code **)(*param_2 + 0xc0))(param_2,plVar1);
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  uStack_c8 = 0;
  uStack_d0 = 0;
  uStack_f8 = 0;
  local_100 = 0;
  uStack_e8 = 0;
  uStack_f0 = 0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  thunk_EXT_FUN_80110000037693ec(&local_140,0x100,"%s");
  plVar2 = (long *)thunk_EXT_FUN_80110000038d02e4(&local_140);
  plVar3 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  (**(code **)(*plVar3 + 0xe8))(plVar3,plVar2);
  (**(code **)(*plVar1 + 0x100))(*plVar1 + 0x100,plVar1,"Devices",plVar3);
  (**(code **)(*plVar3 + 0x28))(plVar3);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (*(long *)PTR_DAT_fffffff007ff2800 != local_38) {
    plVar1 = (long *)thunk_EXT_FUN_8011000003a48590();
    return plVar1;
  }
  return plVar1;
}

