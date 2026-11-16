// FUN_fffffff009c201c4 @ fffffff009c201c4 size=196

undefined8 FUN_fffffff009c201c4(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  iVar2 = FUN_fffffff009c2b164(param_1,param_2,"IOSurfacePlaneComponentBitDepths",param_1 + 4);
  if ((((iVar2 != 0) &&
       (iVar2 = FUN_fffffff009c2b164
                          (param_1,param_2,"IOSurfacePlaneComponentBitOffsets",param_1 + 8),
       iVar2 != 0)) &&
      (iVar2 = FUN_fffffff009c2b164(param_1,param_2,"IOSurfacePlaneComponentNames",param_1 + 0xc),
      iVar2 != 0)) &&
     (iVar2 = FUN_fffffff009c2b164(param_1,param_2,"IOSurfacePlaneComponentTypes",param_1 + 0x10),
     iVar2 != 0)) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c20274);
      (*pcVar1)();
    }
    uVar3 = FUN_fffffff009c2b164(param_1,param_2,"IOSurfacePlaneComponentRanges",param_1 + 0x14);
    return uVar3;
  }
  return 0;
}

