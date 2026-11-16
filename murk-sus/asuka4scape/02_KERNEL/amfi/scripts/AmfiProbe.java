// AMFI range probe: blocks, function inventory, symbols
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.mem.*;
import java.util.*;

public class AmfiProbe extends GhidraScript {
    public void run() throws Exception {
        long lo = Long.parseUnsignedLong("fffffff008eb9690", 16);
        long hi = Long.parseUnsignedLong("fffffff008ee5690", 16);
        Address aLo = toAddr(lo), aHi = toAddr(hi);
        println("AMFI_TEXT " + aLo + " - " + aHi);
        Memory mem = currentProgram.getMemory();
        for (MemoryBlock b : mem.getBlocks()) {
            long s = b.getStart().getUnsignedOffset();
            if (s >= lo - 0x40000 && s <= hi + 0x40000)
                println("BLK " + b.getName() + " " + b.getStart() + " size=0x" + Long.toHexString(b.getSize()) + " exec=" + b.isExecute() + " init=" + b.isInitialized());
        }
        int total = 0, named = 0;
        List<String> namedFns = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(aLo, true)) {
            if (f.getEntryPoint().getUnsignedOffset() >= hi) break;
            total++;
            String nm = f.getName();
            if (!nm.startsWith("sub_") && !nm.startsWith("FUN_") && !nm.startsWith("thunk_")) {
                named++;
                namedFns.add(f.getEntryPoint() + " " + nm);
            }
        }
        println("FUNCS_IN_RANGE total=" + total + " named=" + named);
        for (String s : namedFns) println("NAMED " + s);
        // any symbol referencing AMFI namespace
        int n = 0;
        for (Symbol sym : currentProgram.getSymbolTable().getAllSymbols(true)) {
            String nm = sym.getName();
            if (nm.contains("AppleMobileFileIntegrity") || nm.contains("amfi") || nm.contains("AMFI")) {
                if (n++ < 500) println("SYM " + sym.getAddress() + " " + nm);
            }
        }
        println("SYMCOUNT " + n);
        println("BLOCKS_TOTAL " + mem.getNumAddressRanges());
    }
}
