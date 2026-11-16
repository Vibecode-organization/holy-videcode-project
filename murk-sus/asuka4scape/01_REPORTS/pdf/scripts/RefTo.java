// List direct references to an address (function or data).
// @category PDF
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;

public class RefTo extends GhidraScript {
    @Override
    public void run() throws Exception {
        String a = System.getenv("REF_ADDR");
        if (a == null) { println("REF_ADDR not set"); return; }
        Address t = toAddr("0x" + a.replaceFirst("^0+", ""));
        println("refs to " + t);
        for (Reference r : currentProgram.getReferenceManager().getReferencesTo(t)) {
            Function f = getFunctionContaining(r.getFromAddress());
            println("  " + r.getFromAddress() + " " + r.getReferenceType() + " in " + (f == null ? "(none)" : f.getName() + " @ " + f.getEntryPoint()));
        }
    }
}
