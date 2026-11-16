// Dump assembly instructions in an address range.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class DumpAsmRange extends GhidraScript {
    public void run() throws Exception {
        String[] a = getScriptArgs();
        long start = Long.parseUnsignedLong(a[0].replace("0x", ""), 16);
        long len = Long.parseUnsignedLong(a[1].replace("0x", ""), 16);
        Address s = toAddr(start);
        Address e = s.add(len);
        InstructionIterator it = currentProgram.getListing().getInstructions(s, true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            if (ins.getAddress().compareTo(e) >= 0) break;
            println(String.format("%s  %-8s %s", ins.getAddress(), ins.getMnemonicString(), ins.getOpObjects(0).length > 0 ? ins.getDefaultOperandRepresentation(0) + (ins.getNumOperands() > 1 ? ", " + operand(ins, 1) : "") : ""));
        }
    }
    private String operand(Instruction ins, int i) {
        if (i >= ins.getNumOperands()) return "";
        String r = ins.getDefaultOperandRepresentation(i);
        if (i + 1 < ins.getNumOperands()) r += ", " + operand(ins, i + 1);
        return r;
    }
}
