// FUN_fffffff0081de07c @ fffffff0081de07c size=324

void FUN_fffffff0081de07c(long param_1,ulong *param_2)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  
  lVar1 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-sochot-temp");
  if ((lVar1 != 0) &&
     (plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(lVar1,*(undefined8 *)PTR_DAT_fffffff007ca6090)
     , plVar2 != (long *)0x0)) {
    (**(code **)(*plVar2 + 0xd8))();
  }
  uVar3 = *(ulong *)(param_1 + 0x105f8);
  *(undefined8 *)((long)param_2 + 0x14) = 0;
  *(undefined8 *)((long)param_2 + 0xc) = 0;
  *(undefined8 *)((long)param_2 + 0x24) = 0;
  *(undefined8 *)((long)param_2 + 0x1c) = 0;
  *(undefined8 *)((long)param_2 + 0x104) = 0;
  *(undefined8 *)((long)param_2 + 0xfc) = 0;
  *(undefined8 *)((long)param_2 + 0xf4) = 0;
  *(undefined8 *)((long)param_2 + 0xec) = 0;
  *(undefined8 *)((long)param_2 + 0xe4) = 0;
  *(undefined8 *)((long)param_2 + 0xdc) = 0;
  *(undefined8 *)((long)param_2 + 0xd4) = 0;
  *(undefined8 *)((long)param_2 + 0xcc) = 0;
  *(undefined8 *)((long)param_2 + 0xc4) = 0;
  *(undefined8 *)((long)param_2 + 0xbc) = 0;
  *(undefined8 *)((long)param_2 + 0xb4) = 0;
  *(undefined8 *)((long)param_2 + 0xac) = 0;
  *(undefined8 *)((long)param_2 + 0xa4) = 0;
  *(undefined8 *)((long)param_2 + 0x9c) = 0;
  *(undefined8 *)((long)param_2 + 0x94) = 0;
  *(undefined8 *)((long)param_2 + 0x8c) = 0;
  *(undefined8 *)((long)param_2 + 0x84) = 0;
  *(undefined8 *)((long)param_2 + 0x7c) = 0;
  *(undefined8 *)((long)param_2 + 0x74) = 0;
  *(undefined8 *)((long)param_2 + 0x6c) = 0;
  *(undefined8 *)((long)param_2 + 100) = 0;
  *(undefined8 *)((long)param_2 + 0x5c) = 0;
  *(undefined8 *)((long)param_2 + 0x54) = 0;
  *(undefined8 *)((long)param_2 + 0x4c) = 0;
  *(undefined8 *)((long)param_2 + 0x44) = 0;
  *(undefined8 *)((long)param_2 + 0x3c) = 0;
  *(undefined8 *)((long)param_2 + 0x34) = 0;
  *(undefined8 *)((long)param_2 + 0x2c) = 0;
  uVar3 = uVar3 & 0x1a;
  *param_2 = uVar3;
  *(undefined4 *)(param_2 + 1) = 0x7d;
  *(undefined4 *)(param_2 + 2) = 0x41100000;
  uVar4 = NEON_fmov(0x41100000,4);
  param_2[3] = uVar4;
  if ((*(ulong *)(param_1 + 0x105f8) != 0) && (uVar3 != 0x1a)) {
    thunk_EXT_FUN_8011000003a49114
              (
              "AGXk: %s:%d:%s: !!! Not all MTR Sensors required for SoCHoT are enabled (en: %.16llx exp: %.16llx)\n"
              );
    return;
  }
  return;
}

