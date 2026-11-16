// Decompile the function containing each address (safe for interior labels).
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.File;
import java.io.PrintWriter;

public class DecompileContaining extends GhidraScript {
    @Override
    public void run() throws Exception {
        String addrs = System.getenv().getOrDefault("CT_ADDRS", "");
        String out = System.getenv().getOrDefault("CT_DECOMP_OUT", "/tmp/containing.txt");
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        PrintWriter pw = new PrintWriter(new File(out));
        for (String s : addrs.split(",")) {
            s = s.trim();
            if (s.isEmpty()) continue;
            Address a = currentProgram.getAddressFactory().getAddress(s);
            pw.println("//===== ADDR " + s + " inMemory=" + currentProgram.getMemory().contains(a) + " =====");
            Function f = null;
            try { f = currentProgram.getFunctionManager().getFunctionContaining(a); } catch (Exception e) { pw.println("// containing exception " + e); }
            if (f == null) { pw.println("// no containing function"); continue; }
            pw.println("// FUN " + f.getEntryPoint() + " " + f.getName() + " body=" + f.getBody().getMinAddress() + ".." + f.getBody().getMaxAddress());
            try {
                DecompileResults res = ifc.decompileFunction(f, 180, monitor);
                if (res.decompileCompleted() && res.getDecompiledFunction() != null)
                    pw.println(res.getDecompiledFunction().getC());
                else pw.println("// decompile failed: " + res.getErrorMessage());
            } catch (Exception e) { pw.println("// exception " + e); }
        }
        pw.close();
        println("done " + out);
    }
}
