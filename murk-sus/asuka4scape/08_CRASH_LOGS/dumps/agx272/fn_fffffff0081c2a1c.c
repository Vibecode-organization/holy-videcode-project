// FUN_fffffff0081c2a1c @ fffffff0081c2a1c size=4

void FUN_fffffff0081c2a1c(long param_1,uint param_2)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uStack_78;
  uint uStack_74;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_68 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  uStack_40 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0x1a;
  uStack_70 = 2;
  uStack_34 = 2;
  uStack_74 = param_2;
  uVar4 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  uStack_38 = 0;
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar7 = (undefined8 *)(*plVar5 + 0xe8);
  iVar3 = (*(code *)*puVar7)(puVar7,plVar5,FUN_fffffff00817ea94,&uStack_78,&uStack_34,&uStack_38,0);
  if ((iVar3 == 0) && (((byte)uStack_34 >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(param_1,uVar4,uStack_38);
  }
  lVar6 = (ulong)param_2 * 0x30;
  iVar3 = (int)lVar6;
  puVar7 = (undefined8 *)(param_1 + 0x17c8 + (long)iVar3);
  if (lVar6 - iVar3 != 0) {
    puVar7 = (undefined8 *)(param_1 + 0x17c8 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
  }
  lVar1 = *(long *)(param_1 + 0x808) + 0x3e5;
  puVar2 = (undefined8 *)(lVar1 + iVar3);
  if (lVar6 - iVar3 != 0) {
    puVar2 = (undefined8 *)(lVar1 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar8 = puVar2[1];
  uVar4 = *puVar2;
  uVar9 = puVar2[2];
  uVar11 = puVar2[5];
  uVar10 = puVar2[4];
  puVar7[3] = puVar2[3];
  puVar7[2] = uVar9;
  puVar7[5] = uVar11;
  puVar7[4] = uVar10;
  puVar7[1] = uVar8;
  *puVar7 = uVar4;
  return;
}

