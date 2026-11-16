// Unique-name metaclass reader.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.Data;
import java.io.File;
import java.io.PrintWriter;

public class ZzMetaReader123 extends GhidraScript {
    @Override
    public void run() throws Exception {
        PrintWriter pw = new PrintWriter(new File("/tmp/meta2.txt"));
        Address v = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0xfffffff00ad97f50L);
        long raw = getLong(v);
        pw.println("global=" + v + " raw=" + Long.toHexString(raw));
        Data d = getDataAt(v);
        pw.println("data=" + d + " value=" + (d == null ? "null" : d.getValue()));
        if ((raw >>> 48) == 0xffffL) {
            Address slot = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(raw + 0x88L);
            pw.println("slot=" + slot + " raw=" + Long.toHexString(getLong(slot)));
            Data s = getDataAt(slot);
            pw.println("slotdata=" + s + " value=" + (s == null ? "null" : s.getValue()));
        }
        pw.close();
        println("done");
    }
}
