// Read a fixed vtable slot.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.Data;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.File;
import java.io.PrintWriter;

public class ReadSlot extends GhidraScript {
    @Override
    public void run() throws Exception {
        String out = "/tmp/slot.txt";
        PrintWriter pw = new PrintWriter(new File(out));
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0xfffffff00ad97fd8L);
        pw.println("addr=" + a + " inMem=" + currentProgram.getMemory().contains(a));
        pw.println("rawLong=" + Long.toHexString(getLong(a)));
        Data d = getDataAt(a);
        pw.println("data=" + d);
        if (d != null) pw.println("value=" + d.getValue());
        ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesFrom(a);
        int n = 0;
        while (refs.hasNext()) { Reference r = refs.next(); n++; pw.println("ref->" + r.getToAddress() + " " + r.getReferenceType()); }
        pw.println("refs=" + n);
        pw.close();
        println("done " + out);
    }
}
