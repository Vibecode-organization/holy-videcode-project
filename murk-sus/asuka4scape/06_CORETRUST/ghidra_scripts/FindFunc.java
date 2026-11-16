// Find functions by low 32-bit offset and print memory blocks.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.mem.MemoryBlock;
import java.io.File;
import java.io.PrintWriter;

public class FindFunc extends GhidraScript {
    @Override
    public void run() throws Exception {
        String out = System.getenv().getOrDefault("CT_DECOMP_OUT", "/tmp/findfunc.txt");
        PrintWriter pw = new PrintWriter(new File(out));
        pw.println("// program: " + currentProgram.getName());
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            pw.println("// block " + b.getName() + " " + b.getStart() + " - " + b.getEnd() + " exec=" + b.isExecute());
        }
        long[] targets = {0x999598f8L};
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int n = 0, hits = 0;
        while (it.hasNext()) {
            Function f = it.next();
            n++;
            long off = f.getEntryPoint().getOffset();
            long low = off & 0xffffffffL;
            for (long t : targets) {
                if (low == t) {
                    hits++;
                    pw.println("//===== MATCH " + f.getEntryPoint() + " " + f.getName() + " =====");
                    try {
                        DecompInterface ifc = new DecompInterface();
                        ifc.openProgram(currentProgram);
                        DecompileResults res = ifc.decompileFunction(f, 120, monitor);
                        if (res.decompileCompleted() && res.getDecompiledFunction() != null)
                            pw.println(res.getDecompiledFunction().getC());
                        else pw.println("// decompile failed: " + res.getErrorMessage());
                        ifc.dispose();
                    } catch (Exception e) { pw.println("// exception: " + e); }
                }
            }
        }
        pw.println("// scanned " + n + " functions, hits " + hits);
        pw.close();
        println("done " + out + " scanned=" + n + " hits=" + hits);
    }
}
