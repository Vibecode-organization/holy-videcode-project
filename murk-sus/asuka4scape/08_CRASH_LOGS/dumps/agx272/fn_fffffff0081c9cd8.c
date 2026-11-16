// FUN_fffffff0081c9cd8 @ fffffff0081c9cd8 size=308

void FUN_fffffff0081c9cd8
               (long *param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,
               undefined1 param_5,undefined1 param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 local_90;
  undefined1 uStack_88;
  undefined1 uStack_87;
  undefined1 uStack_86;
  undefined1 uStack_85;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined4 local_48;
  undefined4 local_44;
  
  uStack_68 = 0;
  local_70 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  uStack_88 = 0;
  uStack_87 = 0;
  uStack_86 = 0;
  uStack_85 = 0;
  uStack_84 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  local_90 = 0x13;
  uVar2 = (**(code **)(*param_1 + 0x208))(param_1,param_2,0);
  uStack_84 = (undefined4)uVar2;
  uStack_80 = (undefined4)((ulong)uVar2 >> 0x20);
  local_44 = 2;
  uStack_88 = param_6;
  uStack_87 = param_3;
  uStack_86 = param_4;
  uStack_85 = param_5;
  uVar2 = (**(code **)(param_1[0x109] + 0x30))(param_1 + 0x109);
  local_48 = 0;
  puVar3 = (undefined8 *)(**(long **)(param_1[0x50] + 0x310) + 0xe8);
  iVar1 = (*(code *)*puVar3)(puVar3,*(long **)(param_1[0x50] + 0x310),FUN_fffffff00817ea94,&local_90
                             ,&local_44,&local_48,0);
  if ((iVar1 == 0) && (((byte)local_44 >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(param_1,uVar2,local_48);
  }
  return;
}

