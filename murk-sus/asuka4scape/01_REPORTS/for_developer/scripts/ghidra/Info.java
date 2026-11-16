// Print program info and function names at supplied addresses.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;

public class Info extends GhidraScript {
    public void run() throws Exception {
        println("PROGRAM " + currentProgram.getName());
        println("EXECPATH " + currentProgram.getExecutablePath());
        println("IMAGEBASE " + currentProgram.getImageBase());
        for (String arg : getScriptArgs()) {
            long value = Long.parseUnsignedLong(arg.replace("0x", ""), 16);
            Address address = toAddr(value);
            Function function = getFunctionAt(address);
            if (function == null) function = getFunctionContaining(address);
            if (function == null) { println("NO_FUNCTION " + address); continue; }
            println("FUNC " + function.getEntryPoint() + " " + function.getName() + " size=" + function.getBody().getNumAddresses());
        }
    }
}
