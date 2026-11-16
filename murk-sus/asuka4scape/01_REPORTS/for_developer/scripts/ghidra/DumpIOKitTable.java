// Dump IOExternalMethodDispatch entries with selector numbers.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;

public class DumpIOKitTable extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        long base = Long.parseUnsignedLong(args[0].replace("0x", ""), 16);
        long stride = Long.parseUnsignedLong(args[1].replace("0x", ""), 16);
        int count = Integer.parseInt(args[2]);
        Memory mem = currentProgram.getMemory();
        for (int index = 0; index < count; index++) {
            long entry = base + index * stride;
            long function = mem.getLong(toAddr(entry), currentProgram.getLanguage().isBigEndian());
            long scalarIn = mem.getInt(toAddr(entry + 8), currentProgram.getLanguage().isBigEndian()) & 0xffffffffL;
            long structIn = mem.getInt(toAddr(entry + 0xc), currentProgram.getLanguage().isBigEndian()) & 0xffffffffL;
            long scalarOut = mem.getInt(toAddr(entry + 0x10), currentProgram.getLanguage().isBigEndian()) & 0xffffffffL;
            long structOut = mem.getInt(toAddr(entry + 0x14), currentProgram.getLanguage().isBigEndian()) & 0xffffffffL;
            Function fn = getFunctionAt(toAddr(function));
            println(String.format("SEL %03d fn=%x sIn=%x stIn=%x sOut=%x stOut=%x %s", index,
                function, scalarIn, structIn, scalarOut, structOut,
                fn == null ? "NOFN" : fn.getName()));
        }
    }
}
