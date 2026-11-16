// Dump a table of 0x18-byte records and decode pointers.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
public class ReadTable extends GhidraScript {
    public void run() throws Exception {
        String env = System.getenv("TBL");
        long base = Long.parseUnsignedLong(env, 16);
        int count = Integer.parseInt(System.getenv("CNT"));
        Address addr = toAddr(base);
        Memory mem = currentProgram.getMemory();
        for (int i = 0; i < count; i++) {
            Address a = addr.add((long)i * 0x18);
            StringBuilder sb = new StringBuilder();
            for (int k = 0; k < 0x18; k += 4) {
                int v = mem.getInt(a.add(k));
                sb.append(String.format("%08x ", v));
            }
            long p = mem.getLong(a.add(8));
            println(String.format("sel %2d @%s : %s  ptr=%016x", i, a, sb.toString(), p));
        }
    }
}
