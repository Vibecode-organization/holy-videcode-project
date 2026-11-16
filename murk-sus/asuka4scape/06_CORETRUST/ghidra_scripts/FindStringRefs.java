// Find functions that reference a string page/address by scanning instructions.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.File;
import java.io.PrintWriter;

public class FindStringRefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        long str = 0xfffffff0078324b9L;
        long page = str & ~0xfffL;
        String out = System.getenv().getOrDefault("CT_DECOMP_OUT", "/tmp/string_refs.txt");
        PrintWriter pw = new PrintWriter(new File(out));
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        Address pageAddr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(page);
        pw.println("// string=" + Long.toHexString(str) + " page=" + Long.toHexString(page) + " pageAddr=" + pageAddr);
        ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(pageAddr);
        int rn = 0;
        while (refs.hasNext()) { Reference r = refs.next(); rn++; pw.println("// pageref " + r.getFromAddress()); }
        pw.println("// pagerefs=" + rn);

        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int hits = 0;
        while (it.hasNext()) {
            Function f = it.next();
            long e = f.getEntryPoint().getOffset();
            if (e < 0xfffffff007800000L || e > 0xfffffff007900000L) continue;
            boolean hit = false;
            InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (ii.hasNext()) {
                Instruction ins = ii.next();
                for (int op = 0; op < ins.getNumOperands(); op++) {
                    Object[] objs = ins.getOpObjects(op);
                    if (objs == null) continue;
                    for (Object o : objs) {
                        if (!(o instanceof Scalar)) continue;
                        long v = ((Scalar)o).getUnsignedValue();
                        if (v == str || v == page || (v & ~0xfffL) == page) { hit = true; break; }
                    }
                    if (hit) break;
                }
                if (hit) break;
            }
            if (!hit) {
                // also check raw instruction text for the hex address
                InstructionIterator ii2 = currentProgram.getListing().getInstructions(f.getBody(), true);
                while (ii2.hasNext()) {
                    Instruction ins = ii2.next();
                    String t = ins.toString().toLowerCase();
                    if (t.contains("78324b9") || t.contains("7832000")) { hit = true; break; }
                }
            }
            if (!hit) continue;
            hits++;
            pw.println("//===== HIT " + f.getEntryPoint() + " " + f.getName() + " =====");
            try {
                DecompileResults res = ifc.decompileFunction(f, 240, monitor);
                if (res.decompileCompleted() && res.getDecompiledFunction() != null)
                    pw.println(res.getDecompiledFunction().getC());
                else pw.println("// decompile failed: " + res.getErrorMessage());
            } catch (Exception ex) { pw.println("// exception " + ex); }
        }
        pw.println("// hits=" + hits);
        pw.close();
        ifc.dispose();
        println("done " + out + " hits=" + hits);
    }
}
