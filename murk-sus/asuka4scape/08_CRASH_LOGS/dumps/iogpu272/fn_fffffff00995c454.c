// FUN_fffffff00995c454 @ fffffff00995c454 size=208

undefined8 FUN_fffffff00995c454(long param_1,long param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  iVar1 = (*DAT_fffffff007feb260)();
  uVar5 = 0;
  if ((param_2 != 0) && (iVar1 != 0)) {
    *(undefined8 *)(param_1 + 0x40) = 1;
    *(uint *)(param_1 + 0x54) = param_4;
    if (param_4 != 0) {
      lVar3 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff14f8,(ulong)param_4 << 3);
      *(long *)(param_1 + 0x58) = lVar3;
      if (lVar3 == 0) {
        return 0;
      }
    }
    *(long *)(param_1 + 0xc0) = param_2;
    *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_2 + 0x160);
    *(undefined8 *)(param_1 + 0x18) = param_3;
    uVar5 = 1;
    uVar4 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
    *(undefined8 *)(param_1 + 200) = uVar4;
    uVar2 = FUN_fffffff009944798(*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x1d8),param_1);
    *(undefined4 *)(param_1 + 0x70) = uVar2;
  }
  return uVar5;
}

