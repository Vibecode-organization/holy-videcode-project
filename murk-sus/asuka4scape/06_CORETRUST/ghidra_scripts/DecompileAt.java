// Decompile functions at addresses listed in CT_ADDRS (comma separated).
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.File;
import java.io.PrintWriter;

public class DecompileAt extends GhidraScript {
    @Override
    public void run() throws Exception {
        String addrs = System.getenv().getOrDefault("CT_ADDRS", "");
        String out = System.getenv().getOrDefault("CT_DECOMP_OUT", "/home/femboychik/asuka4scape/06_CORETRUST/at_decomp.txt");
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        PrintWriter pw = new PrintWriter(new File(out));
        for (String s : addrs.split(",")) {
            s = s.trim();
            if (s.isEmpty()) continue;
            Address a = currentProgram.getAddressFactory().getAddress(s);
            Function f = getFunctionAt(a);
            if (f == null) f = createFunction(a, null);
            pw.println("//===== AT " + s + " -> " + (f == null ? "null" : f.getName()) + " =====");
            if (f == null) { pw.println("// no function"); continue; }
            try {
                DecompileResults res = ifc.decompileFunction(f, 120, monitor);
                if (res.decompileCompleted() && res.getDecompiledFunction() != null) {
                    pw.println(res.getDecompiledFunction().getC());
                } else {
                    pw.println("// decompile failed: " + res.getErrorMessage());
                }
            } catch (Exception e) {
                pw.println("// exception: " + e);
            }
            pw.println();
        }
        pw.close();
        println("done " + out);
    }
}
