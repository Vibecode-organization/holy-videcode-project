// Find 8-byte little-endian occurrences of a target address; print slot + refs
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class PtrFind extends GhidraScript {
    public void run() throws Exception {
        long target = Long.parseUnsignedLong(getScriptArgs()[0].replace("0x",""), 16);
        byte[] pat = new byte[8];
        long v = target;
        for (int i = 0; i < 8; i++) { pat[i] = (byte)(v & 0xff); v >>>= 8; }
        Memory mem = currentProgram.getMemory();
        int hits = 0;
        for (MemoryBlock b : mem.getBlocks()) {
            if (!b.isInitialized() || b.getSize() > 0x4000000L) continue;
            Address a = b.getStart(), end = b.getEnd();
            Address f = mem.findBytes(a, end, pat, null, true, monitor);
            while (f != null) {
                hits++;
                if (hits <= 40) {
                    println("PTR " + f);
                    int n = 0;
                    for (Reference r : getReferencesTo(f)) {
                        Function fn = getFunctionContaining(r.getFromAddress());
                        println("   XREF " + r.getFromAddress() + " " + r.getReferenceType() + (fn == null ? "" : " in " + fn.getName() + "@" + fn.getEntryPoint()));
                        n++;
                    }
                    println("   refs=" + n);
                }
                Address next = f.add(1);
                if (next.compareTo(end) > 0) break;
                f = mem.findBytes(next, end, pat, null, true, monitor);
            }
        }
        println("HITS " + hits);
    }
}
