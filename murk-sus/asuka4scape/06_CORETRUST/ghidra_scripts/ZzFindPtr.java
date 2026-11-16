// Scan IOGPU const/data for a pointer value (exact or low-32) to a target.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import java.io.File;
import java.io.PrintWriter;

public class ZzFindPtr extends GhidraScript {
    @Override
    public void run() throws Exception {
        long target = 0xfffffff009943ea0L;
        long tlow = target & 0xffffffffL;
        PrintWriter pw = new PrintWriter(new File("/tmp/findptr.txt"));
        long[] ranges = {0xfffffff007fe8e10L, 0xfffffff007fefde8L, 0xfffffff00af21000L, 0xfffffff00af23000L, 0xfffffff00afb7000L, 0xfffffff00afb9000L};
        for (int r = 0; r < ranges.length; r += 2) {
            long start = ranges[r], end = ranges[r+1];
            pw.println("// range " + Long.toHexString(start) + ".." + Long.toHexString(end));
            for (long v = start; v + 8 <= end; v += 8) {
                Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(v);
                long q;
                try { q = getLong(a); } catch (Exception e) { continue; }
                if (q == target || (q & 0xffffffffL) == tlow) {
                    pw.println("// HIT " + Long.toHexString(v) + " q=" + Long.toHexString(q));
                    for (int k = -6; k <= 6; k++) {
                        long w = v + k*8;
                        if (w < start || w + 8 > end) continue;
                        Address wa = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(w);
                        try { pw.println("//   " + Long.toHexString(w) + " = " + Long.toHexString(getLong(wa))); } catch (Exception e) {}
                    }
                }
            }
        }
        pw.close();
        println("done");
    }
}
