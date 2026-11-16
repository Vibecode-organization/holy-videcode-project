// FUN_fffffff0099664e4 @ fffffff0099664e4 size=208

undefined8 FUN_fffffff0099664e4(long param_1,undefined8 param_2,uint param_3)

{
  ulong uVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  
  uVar4 = 0xe00002c2;
  if ((param_3 < 2) &&
     (plVar3 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x10)), plVar3 != (long *)0x0)
     ) {
    uStack_48 = 0;
    local_50 = 0;
    uStack_38 = 0;
    uStack_40 = 0;
    uStack_68 = 0;
    local_70 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x48) + 0x148);
    FUN_fffffff00994af14(&local_70);
    lVar2 = (ulong)param_3 * 0x40;
    uVar1 = plVar3[3] + (long)(int)lVar2;
    if (lVar2 != (int)lVar2) {
      uVar1 = plVar3[3] + lVar2 & 0xffffffffffffU | 0x2bad000000000000;
    }
    FUN_fffffff00994c49c(uVar4,uVar1,&local_70);
    (**(code **)(*plVar3 + 0x28))(plVar3);
    FUN_fffffff00994b870(uVar4,&local_70);
    uVar4 = 0;
  }
  return uVar4;
}

