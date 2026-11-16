// Dump function pointers and slot offsets from a C++ vtable.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;

public class DumpVtable extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        long base = Long.parseUnsignedLong(args[0].replace("0x", ""), 16);
        int count = Integer.parseInt(args[1]);
        Memory mem = currentProgram.getMemory();
        for (int index = 0; index < count; index++) {
            long entry = base + index * 8L;
            long value = mem.getLong(toAddr(entry), currentProgram.getLanguage().isBigEndian());
            if (value == 0) continue;
            Function function = getFunctionAt(toAddr(value));
            Instruction instruction = getInstructionAt(toAddr(value));
            if (function != null || instruction != null) {
                println(String.format("SLOT 0x%04x entry=%x value=%x %s", index * 8, entry, value,
                    function == null ? "instruction-only" : function.getName()));
            }
            else {
                println(String.format("SLOT 0x%04x entry=%x value=%x non-code", index * 8, entry, value));
            }
        }
    }
}
