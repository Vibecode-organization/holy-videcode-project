// Decompile selected functions by name substring.
// usage: -postScript DecompileByName.java <outfile> <substr1> ...
import java.io.PrintWriter;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.util.task.ConsoleTaskMonitor;

public class DecompileByName extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outpath = args[0];
        String[] subs = new String[args.length - 1];
        System.arraycopy(args, 1, subs, 0, subs.length);
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();
        PrintWriter out = new PrintWriter(outpath, "UTF-8");
        int count = 0;
        while (fit.hasNext()) {
            Function f = fit.next();
            String n = f.getName();
            boolean match = false;
            for (String s : subs) { if (n.contains(s)) { match = true; break; } }
            if (!match) continue;
            out.println("\n/* ===== " + n + " @ " + f.getEntryPoint() + " ===== */");
            try {
                DecompileResults res = dec.decompileFunction(f, 60, mon);
                if (res != null && res.decompileCompleted()) {
                    out.println(res.getDecompiledFunction().getC());
                } else {
                    out.println("/* decompile failed */");
                }
            } catch (Exception e) {
                out.println("/* error: " + e + " */");
            }
            count++;
        }
        out.close();
        println("DECOMPILED " + count + " functions -> " + outpath);
    }
}
