// FUN_fffffff00997bfa0 @ fffffff00997bfa0 size=744

/* WARNING: Removing unreachable block (ram,0xfffffff00997c098) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997c0f0) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997c044) */

void FUN_fffffff00997bfa0
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6,long param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  ulong unaff_x30;
  
  plVar2 = (long *)FUN_fffffff00997b558();
  (**(code **)(*plVar2 + 0x138))(plVar2,"IOAccelSurfaceID");
  plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(param_3,0x20);
  (**(code **)(*plVar2 + 0x100))(*plVar2 + 0x100,plVar2,"IOAccelSurfaceID",plVar3);
  plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24(param_5,0x20);
  (**(code **)(*plVar2 + 0x100))(*plVar2 + 0x100,plVar2,"IOAccelSurfaceWidth",plVar4);
  plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(param_6,0x20);
  (**(code **)(*plVar2 + 0x100))(*plVar2 + 0x100,plVar2,"IOAccelSurfaceHeight",plVar5);
  if (param_7 != 0) {
    plVar6 = (long *)thunk_EXT_FUN_80110000038ce200(param_7);
    (**(code **)(*plVar2 + 0x100))(plVar2,"IOAccelSurfacePixelFormat",plVar6);
    if (plVar6 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
  }
  plVar6 = (long *)thunk_EXT_FUN_80110000038ce200(param_4);
  (**(code **)(*plVar2 + 0x100))(plVar2,"IOAccelSurfaceBufferIndex",plVar6);
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  if (plVar3 == (long *)0x0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00997c26c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar3 + 0x28))(plVar3,(undefined8 *)(*plVar3 + 0x28));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997c264);
  (*pcVar1)();
}

