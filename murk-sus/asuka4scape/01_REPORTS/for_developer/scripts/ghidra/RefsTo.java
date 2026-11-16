// List references to an address (string/data), with containing functions.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class RefsTo extends GhidraScript {
    public void run() throws Exception {
        for (String arg : getScriptArgs()) {
            long value = Long.parseUnsignedLong(arg.replace("0x", ""), 16);
            Address a = toAddr(value);
            println("REFS " + a);
            ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(a);
            int n=0;
            while (it.hasNext()) {
                Reference r = it.next();
                Function f = getFunctionContaining(r.getFromAddress());
                println("  from " + r.getFromAddress() + " type=" + r.getReferenceType() + " fn=" + (f==null?"none":f.getEntryPoint()+" "+f.getName()));
                n++;
            }
            println("  count=" + n);
        }
    }
}
