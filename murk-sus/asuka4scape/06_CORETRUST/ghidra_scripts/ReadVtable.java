// Read a vtable slot and decompile the pointed-to function.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.File;
import java.io.PrintWriter;

public class ReadVtable extends GhidraScript {
    @Override
    public void run() throws Exception {
        long base = Long.decode(System.getenv().getOrDefault("CT_VTABLE", "0xfffffff00ad97f50"));
        long off = Long.decode(System.getenv().getOrDefault("CT_OFF", "0x88"));
        String out = System.getenv().getOrDefault("CT_DECOMP_OUT", "/tmp/vtable.txt");
        PrintWriter pw = new PrintWriter(new File(out));
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base + off);
        pw.println("// slot " + a + " rawLong=" + Long.toHexString(getLong(a)));
        Data d = getDataAt(a);
        pw.println("// data=" + d + " value=" + (d == null ? "null" : d.getValue()));
        ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesFrom(a);
        int n = 0;
        while (refs.hasNext()) {
            Reference r = refs.next();
            n++;
            pw.println("// ref -> " + r.getToAddress() + " type=" + r.getReferenceType());
            Function f = currentProgram.getFunctionManager().getFunctionAt(r.getToAddress());
            if (f == null) f = currentProgram.getFunctionManager().getFunctionContaining(r.getToAddress());
            if (f != null) {
                pw.println("//===== FUN " + f.getEntryPoint() + " " + f.getName() + " =====");
                DecompInterface ifc = new DecompInterface(); ifc.openProgram(currentProgram);
                DecompileResults res = ifc.decompileFunction(f, 240, monitor);
                if (res.decompileCompleted() && res.getDecompiledFunction() != null)
                    pw.println(res.getDecompiledFunction().getC());
                else pw.println("// decompile failed " + res.getErrorMessage());
                ifc.dispose();
            }
        }
        pw.println("// refs=" + n);
        pw.close();
        println("done " + out);
    }
}
