// FUN_fffffff00818bf08 @ fffffff00818bf08 size=456

/* WARNING: Removing unreachable block (ram,0xfffffff00818c06c) */

void FUN_fffffff00818bf08(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 uVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  long *plVar7;
  ulong unaff_x30;
  
  uVar4 = thunk_EXT_FUN_80110000029474ec
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498);
  if ((uVar4 & 1) != 0) {
    return;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x7f0);
  plVar7 = *(long **)(param_1 + 0x530);
  if ((*(byte *)((long)plVar7 + 0x1ac44) >> 3 & 1) != 0) {
    uVar3 = thunk_EXT_FUN_8011000002c13530(param_2);
    uVar5 = thunk_EXT_FUN_8011000002c13500(param_2);
    thunk_EXT_FUN_80110000032222a8(plVar7[0x3589]);
    thunk_EXT_FUN_80110000036da494(0x85930cc4,uVar3,param_3,uVar5,uVar1,0);
    thunk_EXT_FUN_8011000003222de0(plVar7[0x3589]);
    plVar7 = *(long **)(param_1 + 0x530);
  }
  thunk_EXT_FUN_80110000032222a8(plVar7[0x234c]);
  (**(code **)(*plVar7 + 0x710))(plVar7,"",0);
  plVar7 = *(long **)(*(long *)(param_1 + 0x530) + 0x310);
  puVar6 = (undefined8 *)(*plVar7 + 0xe8);
  (*(code *)*puVar6)(puVar6,plVar7,FUN_fffffff00817dfe8,uVar1,0,*(int *)(param_1 + 0x7ec) == 5,0);
  plVar7 = *(long **)(param_1 + 0x530);
  (**(code **)(*plVar7 + 0x718))(*plVar7 + 0x718,plVar7,"",0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(plVar7[0x234c]);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818c0b8);
  (*pcVar2)();
}

