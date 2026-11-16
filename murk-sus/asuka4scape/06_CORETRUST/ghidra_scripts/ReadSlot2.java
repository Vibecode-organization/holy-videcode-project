// Minimal fixed vtable slot reader.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import java.io.File;
import java.io.PrintWriter;

public class ReadSlot2 extends GhidraScript {
    @Override
    public void run() throws Exception {
        PrintWriter pw = new PrintWriter(new File("/tmp/slot2.txt"));
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0xfffffff00ad97fd8L);
        pw.println("addr=" + a);
        pw.println("raw=" + Long.toHexString(getLong(a)));
        pw.close();
        println("done");
    }
}
