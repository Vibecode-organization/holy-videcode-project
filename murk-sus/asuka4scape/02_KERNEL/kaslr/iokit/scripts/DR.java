// Decompile functions at given hex addresses -> $OUT/fn_<addr>.c
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.app.decompiler.*;
import java.io.*;

public class DR extends GhidraScript {
    public void run() throws Exception {
        String outdir = System.getenv("KASLR_OUT");
        if (outdir == null) outdir = "/home/femboychik/work/kaslr/iokit/decomp";
        File dir = new File(outdir);
        dir.mkdirs();
        DecompInterface di = new DecompInterface();
        di.toggleCCode(true);
        di.toggleSyntaxTree(true);
        di.openProgram(currentProgram);
        for (String s : getScriptArgs()) {
            long a = Long.parseUnsignedLong(s.replace("0x",""), 16);
            Address ad = toAddr(a);
            Function fn = getFunctionAt(ad);
            if (fn == null) {
                fn = getFunctionContaining(ad);
                if (fn != null) println("CONTAINED " + ad + " in " + fn.getEntryPoint());
            }
            if (fn == null) { println("NOFN " + ad); continue; }
            StringBuilder out = new StringBuilder();
            out.append("// ").append(fn.getName()).append(" @ ").append(fn.getEntryPoint())
               .append(" size=").append(fn.getBody().getNumAddresses()).append("\n");
            out.append("// CALLED FROM:\n");
            for (Reference r : getReferencesTo(fn.getEntryPoint())) {
                Function cf = getFunctionContaining(r.getFromAddress());
                out.append("//   ").append(r.getFromAddress()).append(" ")
                   .append(cf == null ? "?" : cf.getName() + "@" + cf.getEntryPoint()).append("\n");
            }
            DecompileResults res = di.decompileFunction(fn, 180, monitor);
            out.append(res != null && res.decompileCompleted()
                       ? res.getDecompiledFunction().getC() : "// decompile failed\n");
            String nm = String.format("fn_%x.c", fn.getEntryPoint().getOffset());
            try (PrintWriter pw = new PrintWriter(new File(dir, nm))) { pw.print(out); }
            println("WROTE " + nm + " len=" + out.length());
        }
    }
}
