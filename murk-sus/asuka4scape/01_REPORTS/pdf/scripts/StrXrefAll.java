// Find ALL occurrences of a string and print any references to each.
// @category PDF
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.nio.charset.StandardCharsets;

public class StrXrefAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        String needle = System.getenv("NEEDLE");
        byte[] pat = needle.getBytes(StandardCharsets.UTF_8);
        Memory mem = currentProgram.getMemory();
        Address a = currentProgram.getMinAddress();
        int total = 0, refs = 0;
        while (true) {
            Address found = mem.findBytes(a, pat, null, true, monitor);
            if (found == null) break;
            total++;
            for (Reference r : currentProgram.getReferenceManager().getReferencesTo(found)) {
                Function f = getFunctionContaining(r.getFromAddress());
                println("STR " + found + " ref " + r.getFromAddress() + " in " + (f==null?"(none)":f.getName()+" @"+f.getEntryPoint()));
                refs++;
            }
            a = found.add(1);
        }
        println("occurrences=" + total + " refs=" + refs);
    }
}
