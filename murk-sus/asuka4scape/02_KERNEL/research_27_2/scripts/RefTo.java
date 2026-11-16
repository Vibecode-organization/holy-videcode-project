// Refs to data addresses + decompile referencing functions
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.app.decompiler.*;
import java.util.*;

public class RefTo extends GhidraScript {
    public void run() throws Exception {
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        Set<Address> fns = new LinkedHashSet<>();
        for (String s : getScriptArgs()) {
            long a = Long.parseUnsignedLong(s.replace("0x",""), 16);
            Address ad = toAddr(a);
            println("=== REFTO " + ad);
            int n = 0;
            for (Reference r : getReferencesTo(ad)) {
                println("  REF " + r.getFromAddress() + " " + r.getReferenceType());
                Function f = getFunctionContaining(r.getFromAddress());
                if (f != null) { println("     in " + f.getName() + "@" + f.getEntryPoint()); fns.add(f.getEntryPoint()); }
                n++;
            }
            println("  total=" + n);
        }
        int c = 0;
        for (Address a : fns) {
            if (c++ >= 3) break;
            Function f = getFunctionAt(a);
            DecompileResults res = di.decompileFunction(f, 90, monitor);
            println("=== FN " + a + " " + f.getName());
            if (res != null && res.decompileCompleted()) println(res.getDecompiledFunction().getC());
        }
    }
}
