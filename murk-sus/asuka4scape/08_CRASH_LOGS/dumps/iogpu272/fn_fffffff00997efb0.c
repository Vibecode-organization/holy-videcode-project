// FUN_fffffff00997efb0 @ fffffff00997efb0 size=240

undefined8
FUN_fffffff00997efb0
          (long param_1,long param_2,long *param_3,long *param_4,uint param_5,undefined4 param_6)

{
  undefined8 uVar1;
  
  uVar1 = (*DAT_fffffff007feb260)();
  if (((((int)uVar1 != 0) && (uVar1 = 0, param_3 != (long *)0x0)) && (param_2 != 0)) &&
     (param_4 != (long *)0x0)) {
    *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xfff7;
    *(long **)(param_1 + 0x20) = param_3;
    (**(code **)(*param_3 + 0x20))(param_3);
    *(long **)(param_1 + 0x18) = param_4;
    (**(code **)(*param_4 + 0x20))(param_4);
    *(undefined4 *)(param_1 + 0x14) = param_6;
    *(ushort *)(param_1 + 0x10) =
         *(ushort *)(param_1 + 0x10) |
         (ushort)((param_5 & 3) << 1) | (ushort)((param_5 & 0x10) << 3) | 8;
    uVar1 = 1;
  }
  return uVar1;
}

