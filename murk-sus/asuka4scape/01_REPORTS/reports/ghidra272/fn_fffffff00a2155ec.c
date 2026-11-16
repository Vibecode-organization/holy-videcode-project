// FUN_fffffff00a2155ec @ fffffff00a2155ec size=216

undefined8 FUN_fffffff00a2155ec(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  uVar2 = 4;
  if ((param_1 != 0) && (0xffffffe2 < (int)param_2 - 0x25U)) {
    uVar2 = tpidr_el1;
    lVar3 = FUN_fffffff00a29bafc(uVar2);
    lVar4 = lVar3;
    if ((((lVar3 == DAT_fffffff007c68058) ||
         (lVar4 = FUN_fffffff00a29b0b4(), lVar4 == DAT_fffffff00ad95888)) ||
        (((int)param_2 == 0x14 &&
         (lVar4 = FUN_fffffff00a9dee48(lVar3,"com.apple.private.xpc.launchd.event-monitor"),
         (int)lVar4 != 0)))) && (iVar1 = FUN_fffffff00aa3aab8(lVar4,param_2,param_3), iVar1 == 0)) {
      uVar2 = FUN_fffffff00a2153dc(param_1,param_2,param_3);
      return uVar2;
    }
    uVar2 = 8;
  }
  return uVar2;
}

