// FUN_fffffff00a8d812c @ fffffff00a8d812c size=268
// CALLERS:
//   fffffff00a8d7460 FUN_fffffff00a8d5ea4@fffffff00a8d5ea4

void FUN_fffffff00a8d812c(long param_1)

{
  long *plVar1;
  ulong uVar2;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  long local_28;
  
  local_28 = DAT_fffffff00ad30000;
  if (*(long *)(param_1 + 0x28) != 0) {
    uStack_48 = 0;
    local_50 = 0;
    uStack_38 = 0;
    uStack_40 = 0;
    uStack_68 = 0;
    local_70 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    uStack_88 = 0;
    local_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_a8 = 0;
    local_b0 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    FUN_fffffff00a76d3ec(&local_b0,0x80,"OSUnserializeXML: %s near line %d\n");
    plVar1 = (long *)(**(code **)(DAT_fffffff00ad95ee0 + 0x68))();
    if ((plVar1 != (long *)0x0) &&
       (uVar2 = (**(code **)(*plVar1 + 0x80))(plVar1,&local_b0), (uVar2 & 1) == 0)) {
      (**(code **)(*plVar1 + 0x28))(plVar1);
      plVar1 = (long *)0x0;
    }
    **(long **)(param_1 + 0x28) = (long)plVar1;
  }
  if (DAT_fffffff00ad30000 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

