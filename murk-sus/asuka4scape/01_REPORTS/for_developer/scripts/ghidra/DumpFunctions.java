// Decompile supplied function addresses into the research directory with callers and callees.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class DumpFunctions extends GhidraScript {
    public void run() throws Exception {
        File dir = new File("/home/femboychik/claude_code/research_27_2/ghidra/dumps");
        dir.mkdirs();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        for (String arg : getScriptArgs()) {
            long value = Long.parseUnsignedLong(arg.replace("0x", ""), 16);
            Address address = toAddr(value);
            Function function = getFunctionAt(address);
            if (function == null) function = getFunctionContaining(address);
            if (function == null) {
                println("NO_FUNCTION " + address);
                continue;
            }
            StringBuilder out = new StringBuilder();
            out.append("// ").append(function.getName()).append(" @ ").append(function.getEntryPoint());
            out.append(" size=").append(function.getBody().getNumAddresses()).append("\n// CALLERS:\n");
            for (Reference ref : getReferencesTo(function.getEntryPoint())) {
                Function caller = getFunctionContaining(ref.getFromAddress());
                out.append("//   ").append(ref.getFromAddress()).append(" ");
                out.append(caller == null ? "no-fn" : caller.getName() + "@" + caller.getEntryPoint());
                out.append("\n");
            }
            out.append("// CALLEES:\n");
            for (Function callee : function.getCalledFunctions(monitor)) {
                out.append("//   ").append(callee.getEntryPoint()).append(" ").append(callee.getName()).append("\n");
            }
            DecompileResults result = decompiler.decompileFunction(function, 180, monitor);
            if (result != null && result.decompileCompleted()) {
                out.append(result.getDecompiledFunction().getC());
            }
            else {
                out.append("// DECOMPILE_FAILED\n");
                InstructionIterator instructions = currentProgram.getListing().getInstructions(function.getBody(), true);
                while (instructions.hasNext()) out.append(instructions.next().toString()).append("\n");
            }
            String name = String.format("fn_%s.c", function.getEntryPoint().toString());
            try (PrintWriter writer = new PrintWriter(new File(dir, name))) {
                writer.print(out);
            }
            println("WROTE " + name + " bytes=" + out.length());
        }
    }
}
