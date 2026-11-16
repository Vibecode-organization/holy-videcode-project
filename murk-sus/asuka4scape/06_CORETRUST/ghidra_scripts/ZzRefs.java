// Find references to a fixed IOGPU function and decompile callers.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.File;
import java.io.PrintWriter;

public class ZzRefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        long target = 0xfffffff009943ea0L;
        PrintWriter pw = new PrintWriter(new File("/tmp/refs_updatepte.txt"));
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(target);
        ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(a);
        pw.println("target=" + a);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        int n = 0;
        while (refs.hasNext()) {
            Reference r = refs.next(); n++;
            Address from = r.getFromAddress();
            Function f = currentProgram.getFunctionManager().getFunctionContaining(from);
            pw.println("// ref from " + from + " type=" + r.getReferenceType() + " fun=" + (f == null ? "null" : f.getEntryPoint() + " " + f.getName()));
            if (f == null) continue;
            try {
                DecompileResults res = ifc.decompileFunction(f, 240, monitor);
                if (res.decompileCompleted() && res.getDecompiledFunction() != null)
                    pw.println(res.getDecompiledFunction().getC());
                else pw.println("// decompile failed " + res.getErrorMessage());
            } catch (Exception e) { pw.println("// exception " + e); }
        }
        pw.close();
        ifc.dispose();
        println("done refs=" + n);
    }
}
