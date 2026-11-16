// Dump printable strings in an address range
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.*;
import ghidra.program.model.address.*;

public class DumpRange extends GhidraScript {
    public void run() throws Exception {
        String[] a = getScriptArgs();
        long start = Long.parseUnsignedLong(a[0].replace("0x",""), 16);
        long len = Long.parseUnsignedLong(a[1].replace("0x",""), 16);
        Memory mem = currentProgram.getMemory();
        byte[] buf = new byte[(int)len];
        mem.getBytes(toAddr(start), buf);
        int i = 0;
        while (i < buf.length) {
            if (buf[i] >= 32 && buf[i] < 127) {
                int j = i;
                StringBuilder sb = new StringBuilder();
                while (j < buf.length && buf[j] >= 32 && buf[j] < 127) { sb.append((char)buf[j]); j++; }
                if (sb.length() >= 6) println(String.format("%x :: %s", start+i, sb));
                i = j;
            } else i++;
        }
    }
}
