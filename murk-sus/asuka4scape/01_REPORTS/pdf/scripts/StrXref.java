// Find a string in memory and print functions that reference it.
// @category PDF
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.nio.charset.StandardCharsets;

public class StrXref extends GhidraScript {
    @Override
    public void run() throws Exception {
        String needle = System.getenv("NEEDLE");
        if (needle == null) { println("NEEDLE not set"); return; }
        byte[] pat = needle.getBytes(StandardCharsets.UTF_8);
        Memory mem = currentProgram.getMemory();
        Address found = mem.findBytes(currentProgram.getMinAddress(), pat, null, true, monitor);
        if (found == null) { println("string not found: " + needle); return; }
        println("STRING @ " + found + " : " + needle);
        ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(found);
        int n = 0;
        for (Reference r : refs) {
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            println("  ref from " + from + " func=" + (f == null ? "(none)" : f.getName() + " @ " + f.getEntryPoint()));
            n++;
        }
        if (n == 0) {
            // search nearby: some code loads address with adrp/add several insns earlier
            println("no direct refs; scanning for address materialization");
            long target = found.getOffset();
            Address a = currentProgram.getMinAddress();
            InstructionIterator it = currentProgram.getListing().getInstructions(true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                String s = ins.toString();
                if (s.contains(Long.toHexString(target))) {
                    Function f = getFunctionContaining(ins.getAddress());
                    println("  imm-ref " + ins.getAddress() + " " + s + " func=" + (f==null?"(none)":f.getName()));
                }
            }
        }
    }
}
