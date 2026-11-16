// Decompile every function to OUT dir.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class DumpAll extends GhidraScript {
    public void run() throws Exception {
        String out = System.getenv("OUT");
        if (out == null) { println("OUT not set"); return; }
        new File(out).mkdirs();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        int n = 0, ok = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            n++;
            DecompileResults r = di.decompileFunction(f, 60, monitor);
            if (r == null || !r.decompileCompleted()) continue;
            String c = r.getDecompiledFunction().getC();
            try (PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(out + "/fn_" + f.getEntryPoint() + ".c")))) {
                w.println("// " + f.getName() + " @ " + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses());
                w.print(c);
            }
            ok++;
        }
        println("dumped " + ok + "/" + n);
    }
}
