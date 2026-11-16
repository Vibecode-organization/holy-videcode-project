// FUN_fffffff008df6a84 @ fffffff008df6a84 size=112
// CALLERS:
//   fffffff00afbaceb no-fn
//   fffffff008d5e130 FUN_fffffff008d5e02c@fffffff008d5e02c
// CALLEES:
//   fffffff008d3ce9c FUN_fffffff008d3ce9c
//   fffffff008d3ca9c FUN_fffffff008d3ca9c
//   fffffff008cd5990 FUN_fffffff008cd5990
//   fffffff008d6029c FUN_fffffff008d6029c
//   fffffff008d600bc FUN_fffffff008d600bc
//   fffffff008d601e0 FUN_fffffff008d601e0

void FUN_fffffff008df6a84(void)

{
  undefined1 *puVar1;
  long unaff_x19;
  long unaff_x20;
  
  FUN_fffffff008d6029c();
  FUN_fffffff008d3ca9c();
  puVar1 = (undefined1 *)(unaff_x19 + (int)unaff_x20);
  if (unaff_x20 != (int)unaff_x20) {
    puVar1 = (undefined1 *)(unaff_x19 + unaff_x20 & 0xffffffffffffU | 0x2bad000000000000);
  }
  FUN_fffffff008d3ce9c(*puVar1);
  FUN_fffffff008d601e0();
  FUN_fffffff008d600bc();
  FUN_fffffff008cd5990();
  return;
}

