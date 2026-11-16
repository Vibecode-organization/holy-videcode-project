// FUN_fffffff009970a84 @ fffffff009970a84 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff009970ae8) */

undefined8 FUN_fffffff009970a84(long param_1,long *param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long *plVar4;
  ulong uVar5;
  undefined8 uStack_48;
  
  uStack_48 = 0;
  uVar5 = (ulong)*(ushort *)((long)param_2 + 0x12);
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x18));
  plVar4 = *(long **)(param_1 + 0x138 + uVar5 * 8);
  if ((*(ushort *)(param_2 + 2) >> 6 & 1) == 0) {
    lVar1 = (**(code **)(*param_2 + 200))(param_2);
    uVar2 = (**(code **)(*plVar4 + 0xb0))
                      (plVar4,lVar1,&uStack_48,*(undefined4 *)((long)param_2 + 0x14));
  }
  else {
    uVar3 = (**(code **)(*param_2 + 0x98))(param_2);
    uStack_48 = uVar3;
    lVar1 = (**(code **)(*param_2 + 200))(param_2);
    uVar2 = (**(code **)(*plVar4 + 0xb8))(plVar4,uVar3,lVar1);
  }
  if ((uVar2 & 1) == 0) {
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x18));
    uStack_48 = 0;
  }
  else {
    *(long *)(param_1 + 0xb8 + uVar5 * 8) = *(long *)(param_1 + 0xb8 + uVar5 * 8) + lVar1;
    param_2[7] = 0;
    plVar4 = *(long **)(param_1 + 0x1c0);
    param_2[8] = (long)plVar4;
    *plVar4 = (long)param_2;
    *(long **)(param_1 + 0x1c0) = param_2 + 7;
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x18));
  }
  return uStack_48;
}

