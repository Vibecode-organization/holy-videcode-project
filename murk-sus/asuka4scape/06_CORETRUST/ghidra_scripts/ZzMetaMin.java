// Minimal metaclass global reader, no Data import.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import java.io.File;
import java.io.PrintWriter;

public class ZzMetaMin extends GhidraScript {
    @Override
    public void run() throws Exception {
        PrintWriter pw = new PrintWriter(new File("/tmp/meta3.txt"));
        Address v = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0xfffffff00ad97f50L);
        long raw = getLong(v);
        pw.println("global=" + v + " raw=" + Long.toHexString(raw));
        if ((raw >>> 48) == 0xffffL) {
            Address slot = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(raw + 0x88L);
            pw.println("slot=" + slot + " raw=" + Long.toHexString(getLong(slot)));
        } else {
            pw.println("not canonical");
        }
        pw.close();
        println("done");
    }
}
