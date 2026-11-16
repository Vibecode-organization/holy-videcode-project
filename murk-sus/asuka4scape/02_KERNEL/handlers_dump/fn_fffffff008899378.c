// FUN_fffffff008899378 @ fffffff008899378 size=4 depth=0
// CALLERS:
//   fffffff00afca91e ?
//   fffffff007d96780 ?
// CALLS:

undefined8 FUN_fffffff008899378(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  byte bVar2;
  long *plVar3;
  undefined8 *puVar4;
  char *pcVar5;
  undefined8 uVar6;
  long lVar7;
  undefined1 in_q0 [16];
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  
  if ((param_1 == 0) || (param_3 == 0)) {
    if (DAT_fffffff00ae3add0 == 0) {
      return 0xe00002c2;
    }
    pcVar5 = "TouchEEPROMDriver::%s: Null pointer: target = %p reference = %p arguments = %p\n";
  }
  else {
    if (*(int *)(param_3 + 0x28) == 1) {
      bVar2 = **(byte **)(param_3 + 0x20);
      plVar3 = *(long **)(param_3 + 0x68);
      if (plVar3 == (long *)0x0) {
        plVar3 = (long *)0x0;
        puVar4 = *(undefined8 **)(param_3 + 0x58);
        lVar7 = 0x60;
      }
      else {
        plVar3 = (long *)(**(code **)(*plVar3 + 0xe8))(plVar3,0);
        if (plVar3 == (long *)0x0) {
          if (DAT_fffffff00ae3add0 == 0) {
            return 0xe00002c2;
          }
          pcVar5 = "TouchEEPROMDriver::%s: map is null.\n";
          goto LAB_fffffff008899474;
        }
        puVar4 = (undefined8 *)(**(code **)(*plVar3 + 0x78))();
        lVar7 = 0x70;
        in_q0 = extraout_q0;
      }
      uVar1 = *(uint *)(param_3 + lVar7);
      if ((puVar4 == (undefined8 *)0x0) || (uVar1 == 0)) {
        uVar6 = 0xe00002c2;
        if (DAT_fffffff00ae3add0 != 0) {
          thunk_FUN_fffffff00a9029a0
                    ((byte *)"TouchEEPROMDriver::%s: Invalid buffer: buffer = %p, size = %u\n");
        }
      }
      else {
        uVar6 = FUN_fffffff00889ba18
                          (in_q0,in_q1,in_q2,in_q3,in_s4,in_s5,param_1,(uint)bVar2,puVar4,uVar1);
        if ((int)uVar6 == 0) {
          *(undefined1 *)((long)puVar4 + (ulong)(uVar1 - 1)) = 0;
          lVar7 = thunk_FUN_fffffff00a1d14a0((ulong)puVar4,(ulong)uVar1);
          if (*(long *)(param_3 + 0x68) == 0) {
            uVar6 = 0;
            *(int *)(param_3 + 0x60) = (int)lVar7;
          }
          else {
            uVar6 = 0;
            *(int *)(param_3 + 0x70) = (int)lVar7;
          }
        }
      }
      if (plVar3 == (long *)0x0) {
        return uVar6;
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
      return uVar6;
    }
    if (DAT_fffffff00ae3add0 == 0) {
      return 0xe00002c2;
    }
    pcVar5 = "TouchEEPROMDriver::%s: Bad input count: %u\n\n";
  }
LAB_fffffff008899474:
  thunk_FUN_fffffff00a9029a0((byte *)pcVar5);
  return 0xe00002c2;
}

