// Find the function whose body contains a full VA and decompile it.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.File;
import java.io.PrintWriter;

public class FindContaining extends GhidraScript {
    @Override
    public void run() throws Exception {
        long target = 0xfffffff0999598f8L;
        String out = System.getenv().getOrDefault("CT_DECOMP_OUT", "/tmp/containing_func.txt");
        PrintWriter pw = new PrintWriter(new File(out));
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int n = 0, hits = 0;
        while (it.hasNext()) {
            Function f = it.next(); n++;
            long s = f.getBody().getMinAddress().getOffset();
            long e = f.getBody().getMaxAddress().getOffset();
            if (s <= target && target <= e) {
                hits++;
                pw.println("//===== CONTAINS " + f.getEntryPoint() + " " + f.getName() + " body " + f.getBody().getMinAddress() + ".." + f.getBody().getMaxAddress() + " =====");
                try {
                    DecompileResults res = ifc.decompileFunction(f, 240, monitor);
                    if (res.decompileCompleted() && res.getDecompiledFunction() != null)
                        pw.println(res.getDecompiledFunction().getC());
                    else pw.println("// decompile failed: " + res.getErrorMessage());
                } catch (Exception ex) { pw.println("// exception: " + ex); }
            }
        }
        pw.println("// scanned " + n + " hits " + hits);
        pw.close();
        ifc.dispose();
        println("done " + out + " scanned=" + n + " hits=" + hits);
    }
}
