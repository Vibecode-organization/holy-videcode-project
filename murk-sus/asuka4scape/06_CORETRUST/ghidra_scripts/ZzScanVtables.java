// Scan IOGPU __DATA_CONST for vtable-like tables whose +0xf8 points into IOGPU text.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.File;
import java.io.PrintWriter;

public class ZzScanVtables extends GhidraScript {
    @Override
    public void run() throws Exception {
        long start = 0xfffffff007fe8e10L;
        long end   = 0xfffffff007fefde8L;
        long lo    = 0xfffffff0099407d0L;
        long hi    = 0xfffffff0099841fcL;
        PrintWriter pw = new PrintWriter(new File("/tmp/vtables.txt"));
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        int n = 0, hits = 0;
        for (long v = start; v + 0x100 <= end; v += 8) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(v);
            long p;
            try { p = getLong(a.add(0xf8)); } catch (Exception e) { continue; }
            n++;
            if (p < lo || p > hi) continue;
            long del = 0, init = 0;
            try { del = getLong(a); init = getLong(a.add(8)); } catch (Exception e) {}
            hits++;
            pw.println("// V=" + Long.toHexString(v) + " del=" + Long.toHexString(del)
                       + " init=" + Long.toHexString(init) + " f8=" + Long.toHexString(p));
            Function f = currentProgram.getFunctionManager().getFunctionContaining(
                currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(p));
            if (f != null) {
                pw.println("//   FUN " + f.getEntryPoint() + " " + f.getName());
                try {
                    DecompileResults res = ifc.decompileFunction(f, 180, monitor);
                    if (res.decompileCompleted() && res.getDecompiledFunction() != null)
                        pw.println(res.getDecompiledFunction().getC());
                    else pw.println("// decompile failed " + res.getErrorMessage());
                } catch (Exception ex) { pw.println("// exception " + ex); }
            }
        }
        pw.println("// scanned=" + n + " hits=" + hits);
        pw.close();
        ifc.dispose();
        println("done scanned=" + n + " hits=" + hits);
    }
}
