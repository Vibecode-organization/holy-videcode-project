// FUN_fffffff009251ea8 @ fffffff009251ea8 size=4 depth=0
// CALLERS:
//   fffffff00afdceb6 ?
//   fffffff007eedce8 ?
// CALLS:

undefined8 FUN_fffffff009251ea8(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long *extraout_x8;
  long unaff_x19;
  long unaff_x20;
  undefined1 auVar3 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  int iStack_34;
  
  auVar3 = FUN_fffffff009229a70();
  iStack_34 = 0;
  uVar1 = *(uint *)(param_3 + 0x60);
  uVar2 = FUN_fffffff009229a50(extraout_x8,auVar3,in_q1,in_s2,in_s3,in_s4,in_s5);
  if ((int)uVar2 == 0) {
    if (*(uint *)(unaff_x19 + 0x60) % 0x34 == 0) {
      uVar2 = FUN_fffffff00921c260
                        (unaff_x20,*(undefined8 *)(unaff_x19 + 0x58),&iStack_34,uVar1 / 0x34);
      if ((int)uVar2 == 0) {
        *(int *)(unaff_x19 + 0x60) = iStack_34 * 0x34;
      }
    }
    else {
      uVar2 = 0xe00002c2;
    }
  }
  return uVar2;
}

