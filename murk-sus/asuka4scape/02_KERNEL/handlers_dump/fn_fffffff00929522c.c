// FUN_fffffff00929522c @ fffffff00929522c size=4 depth=0
// CALLERS:
//   fffffff00afdd626 ?
//   fffffff007f053a8 ?
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff009295398) */

undefined8 FUN_fffffff00929522c(undefined8 param_1,long *param_2,long param_3)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  long *plVar6;
  long *plVar7;
  ushort *puVar8;
  
  uVar5 = 0xe00002c2;
  plVar2 = thunk_FUN_fffffff00a894f30(param_2,-0xff511ecd0);
  if (plVar2 == (long *)0x0) {
    pcVar4 = "AppleGasGaugeBeadsUpdateUserClient ERROR: no self\n";
    goto LAB_fffffff0092952d8;
  }
  uVar1 = *(uint *)(param_3 + 0x38);
  uVar3 = (ulong)uVar1;
  plVar6 = *(long **)(param_3 + 0x40);
  if (uVar1 == 0 && plVar6 == (long *)0x0) {
    pcVar4 = "AppleGasGaugeBeadsUpdateUserClient ERROR: no length or MD\n";
    goto LAB_fffffff0092952d8;
  }
  puVar8 = *(ushort **)(param_3 + 0x30);
  if (puVar8 == (ushort *)0x0 && plVar6 == (long *)0x0) {
    pcVar4 = "AppleGasGaugeBeadsUpdateUserClient ERROR: no data or MD\n";
    goto LAB_fffffff0092952d8;
  }
  if ((puVar8 == (ushort *)0x0) || (plVar6 != (long *)0x0)) {
    if ((uVar1 == 0) && (plVar6 != (long *)0x0)) {
      uVar3 = (**(code **)(*plVar6 + 0xb0))(plVar6);
      if (uVar3 < 3) {
        (**(code **)(*plVar6 + 0xb0))(plVar6);
        pcVar4 = "AppleGasGaugeBeadsUpdateUserClient ERROR: invalid length in MD input:%llu\n";
        goto LAB_fffffff0092952d8;
      }
    }
    else if (plVar6 == (long *)0x0) goto LAB_fffffff0092953c4;
    uVar3 = (**(code **)(*plVar6 + 0xb0))(plVar6);
    if (uVar3 >> 0x20 != 0) {
      (**(code **)(*plVar6 + 0xb0))(plVar6);
      pcVar4 = "AppleGasGaugeBeadsUpdateUserClient ERROR: memory descriptor too large: %llu\n";
LAB_fffffff0092952d8:
      thunk_FUN_fffffff00a9029a0((byte *)pcVar4);
      return 0xe00002c2;
    }
    plVar7 = (long *)(**(code **)(*plVar6 + 0xe8))(plVar6,0x1000);
    if (plVar7 == (long *)0x0) {
      thunk_FUN_fffffff00a9029a0
                ((byte *)"AppleGasGaugeBeadsUpdateUserClient ERROR: failed to map memory\n");
      return 0xe00002bd;
    }
    puVar8 = (ushort *)(**(code **)(*plVar7 + 0x78))();
    uVar3 = (**(code **)(*plVar6 + 0xb0))(plVar6);
  }
  else {
    if ((uVar1 < 3) || (*puVar8 == 0)) {
      pcVar4 = "AppleGasGaugeBeadsUpdateUserClient ERROR: invalid length in struct input:%u, %u\n";
      goto LAB_fffffff0092952d8;
    }
LAB_fffffff0092953c4:
    plVar7 = (long *)0x0;
  }
  if (puVar8 == (ushort *)0x0) {
    uVar5 = 0xe00002bd;
  }
  else if (uVar3 - 2 < (ulong)*puVar8) {
    thunk_FUN_fffffff00a9029a0
              ((byte *)"AppleGasGaugeBeadsUpdateUserClient ERROR: invalid payload size: %u > %llu\n"
              );
  }
  else {
    uVar5 = FUN_fffffff00928c34c(plVar2[0x1b],puVar8);
  }
  if (plVar6 != (long *)0x0) {
    if (plVar7 != (long *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
      return uVar5;
    }
    return uVar5;
  }
  return uVar5;
}

