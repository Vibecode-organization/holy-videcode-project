// Find a string in memory, then decompile functions referencing it.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.File;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;

public class FindString extends GhidraScript {
    @Override
    public void run() throws Exception {
        String needle = System.getenv().getOrDefault("CT_STRING", "Invalid command list header");
        String out = System.getenv().getOrDefault("CT_DECOMP_OUT", "/tmp/string_xref.txt");
        PrintWriter pw = new PrintWriter(new File(out));
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        byte[] bytes = needle.getBytes(StandardCharsets.US_ASCII);
        Address found = currentProgram.getMemory().findBytes(
            currentProgram.getMemory().getMinAddress(),
            currentProgram.getMemory().getMaxAddress(),
            bytes, null, true, monitor);
        if (found == null) { pw.println("// string not found: " + needle); pw.close(); return; }
        pw.println("// string at " + found + " : " + needle);
        ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(found);
        int n = 0;
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            pw.println("// ref from " + from + " type " + r.getReferenceType());
            Function f = currentProgram.getFunctionManager().getFunctionContaining(from);
            if (f == null) { pw.println("// no containing function"); continue; }
            pw.println("//===== FUN " + f.getEntryPoint() + " " + f.getName() + " =====");
            try {
                DecompileResults res = ifc.decompileFunction(f, 240, monitor);
                if (res.decompileCompleted() && res.getDecompiledFunction() != null)
                    pw.println(res.getDecompiledFunction().getC());
                else pw.println("// decompile failed: " + res.getErrorMessage());
            } catch (Exception e) { pw.println("// exception " + e); }
            n++;
        }
        pw.println("// refs " + n);
        pw.close();
        ifc.dispose();
        println("done " + out + " refs=" + n);
    }
}
