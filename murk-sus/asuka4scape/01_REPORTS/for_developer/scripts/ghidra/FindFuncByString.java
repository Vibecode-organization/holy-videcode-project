// Decompile functions and report ones whose C contains any of the needles.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
public class FindFuncByString extends GhidraScript {
    public void run() throws Exception {
        String env = System.getenv("NEEDLES");
        if (env == null) { println("NEEDLES not set"); return; }
        String[] needles = env.split("\\|");
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        int n = 0, hits = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            n++;
            DecompileResults r = di.decompileFunction(f, 30, monitor);
            if (r == null || !r.decompileCompleted()) continue;
            String c = r.getDecompiledFunction().getC();
            for (String nd : needles) {
                if (c.contains(nd)) {
                    println("MATCH " + f.getEntryPoint() + " " + f.getName() + " :: " + nd);
                    hits++;
                    break;
                }
            }
        }
        println("DONE funcs=" + n + " hits=" + hits);
    }
}
