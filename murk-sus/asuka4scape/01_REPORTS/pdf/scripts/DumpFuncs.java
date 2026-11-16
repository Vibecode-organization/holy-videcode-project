// Decompile functions matching a Java regex and write C to a file.
// env: DUMP_FILTER (regex), DUMP_OUT (path), DUMP_MAX (max functions)
// @category PDF
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.regex.Pattern;

public class DumpFuncs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String filter = System.getenv("DUMP_FILTER");
        String outPath = System.getenv("DUMP_OUT");
        String maxS = System.getenv("DUMP_MAX");
        int max = maxS == null ? 200 : Integer.parseInt(maxS);
        if (filter == null || outPath == null) { println("need DUMP_FILTER/DUMP_OUT"); return; }
        Pattern pat = Pattern.compile(filter);
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        DecompileOptions opts = new DecompileOptions();
        di.setOptions(opts);
        int n = 0;
        try (PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(outPath)))) {
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (n >= max) break;
                if (!pat.matcher(f.getName()).find()) continue;
                DecompileResults r = di.decompileFunction(f, 120, monitor);
                if (r == null || !r.decompileCompleted()) continue;
                w.println("/* ==== " + f.getName() + " @ " + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses() + " ==== */");
                w.println(r.getDecompiledFunction().getC());
                w.println();
                n++;
            }
        }
        println("DumpFuncs wrote " + n + " functions to " + outPath);
    }
}
