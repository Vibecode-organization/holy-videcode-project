// FUN_fffffff0081c9444 @ fffffff0081c9444 size=16

void FUN_fffffff0081c9444(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined8 *puVar4;
  ulong auStack_70 [9];
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if ((*(byte *)(*(long *)(param_1 + 0x280) + 0x5ca) >> 1 & 1) != 0) {
    auStack_70[5] = 0;
    auStack_70[4] = 0;
    auStack_70[7] = 0;
    auStack_70[6] = 0;
    auStack_70[1] = 0;
    auStack_70[3] = 0;
    auStack_70[2] = 0;
    auStack_70[0] = (ulong)param_2;
    uStack_24 = 1;
    uVar2 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
    uStack_28 = 0;
    plVar3 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
    puVar4 = (undefined8 *)(*plVar3 + 0xe8);
    iVar1 = (*(code *)*puVar4)(puVar4,plVar3,FUN_fffffff00817ea94,auStack_70,&uStack_24,&uStack_28,0
                              );
    if ((iVar1 == 0) && (((byte)uStack_24 >> 1 & 1) != 0)) {
      FUN_fffffff0081a43cc(param_1,uVar2,uStack_28);
    }
  }
  return;
}

