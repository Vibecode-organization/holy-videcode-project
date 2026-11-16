// Search strings, resolve xrefs to containing functions, optionally decompile them
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.app.decompiler.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.io.*;

public class FindStrings extends GhidraScript {
    public void run() throws Exception {
        String[] needles = getScriptArgs().length > 0 ? getScriptArgs() : new String[]{"uncached", "prewire", "max allowed", "memoryMapRequest"};
        Memory mem = currentProgram.getMemory();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        Set<Address> fns = new LinkedHashSet<>();
        for (String nd : needles) {
            byte[] pat = nd.getBytes(StandardCharsets.US_ASCII);
            int hits = 0;
            for (MemoryBlock b : mem.getBlocks()) {
                if (!b.isInitialized() || b.isExecute()) continue;
                long len = b.getSize();
                if (len > 0x2000000L) continue;
                byte[] buf = new byte[(int)len];
                try { mem.getBytes(b.getStart(), buf); } catch (Exception e) { continue; }
                outer:
                for (int i = 0; i + pat.length < buf.length; i++) {
                    for (int k = 0; k < pat.length; k++) if (buf[i+k] != pat[k]) continue outer;
                    Address sa = b.getStart().add(i);
                    StringBuilder s = new StringBuilder();
                    for (int k = 0; k < 160; k++) {
                        try { byte c = buf[i+k]; if (c == 0) break; s.append(c >= 32 && c < 127 ? (char)c : '.'); }
                        catch (Exception e) { break; }
                    }
                    println("STR " + sa + " :: " + s);
                    hits++;
                    for (Reference r : getReferencesTo(sa)) {
                        Function f = getFunctionContaining(r.getFromAddress());
                        println("   XREF " + r.getFromAddress() + (f == null ? "" : " in " + f.getName() + "@" + f.getEntryPoint()));
                        if (f != null) fns.add(f.getEntryPoint());
                    }
                }
            }
            println("HITS " + nd + " = " + hits);
        }
        int n = 0;
        for (Address a : fns) {
            if (n++ >= 8) break;
            Function f = getFunctionAt(a);
            if (f == null) continue;
            DecompileResults res = di.decompileFunction(f, 90, monitor);
            println("=== FN " + a + " " + f.getName());
            if (res != null && res.decompileCompleted()) println(res.getDecompiledFunction().getC());
        }
    }
}
