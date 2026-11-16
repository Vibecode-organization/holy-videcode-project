// Dump decompilation of functions whose names contain any token in CT_TOKENS.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.File;
import java.io.PrintWriter;

public class DumpNamed extends GhidraScript {
    @Override
    public void run() throws Exception {
        String tokens = System.getenv().getOrDefault("CT_TOKENS", "Manifest,ProfileStub,HoldingTank,MCProfile");
        String[] parts = tokens.split(",");
        String out = System.getenv().getOrDefault("CT_DECOMP_OUT", "/home/femboychik/asuka4scape/06_CORETRUST/named_decomp.txt");
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        PrintWriter pw = new PrintWriter(new File(out));
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int n = 0;
        while (it.hasNext()) {
            Function f = it.next();
            String name = f.getName();
            boolean match = false;
            for (String p : parts) if (name.toLowerCase().contains(p.trim().toLowerCase())) { match = true; break; }
            if (!match) continue;
            pw.println("//===== FUN " + f.getEntryPoint() + " " + name + " =====");
            try {
                DecompileResults res = ifc.decompileFunction(f, 90, monitor);
                if (res.decompileCompleted() && res.getDecompiledFunction() != null) {
                    pw.println(res.getDecompiledFunction().getC());
                } else {
                    pw.println("// decompile failed: " + res.getErrorMessage());
                }
            } catch (Exception e) {
                pw.println("// exception: " + e);
            }
            pw.println();
            n++;
        }
        pw.close();
        println("dumped " + n + " named functions to " + out);
    }
}
