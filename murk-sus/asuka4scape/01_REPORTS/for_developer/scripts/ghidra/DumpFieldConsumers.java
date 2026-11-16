// Decompile IOSurface-range functions referencing a supplied field offset.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class DumpFieldConsumers extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        long needle = Long.parseUnsignedLong(args[0].replace("0x", ""), 16);
        String tag = args.length > 1 ? args[1] : String.format("%x", needle);
        Map<Address, Function> functions = new TreeMap<>();
        InstructionIterator instructions = currentProgram.getListing().getInstructions(true);
        while (instructions.hasNext()) {
            Instruction instruction = instructions.next();
            long addressValue = instruction.getAddress().getOffset();
            if (addressValue < 0xfffffff009c00000L || addressValue >= 0xfffffff009d00000L) continue;
            boolean matched = false;
            outer:
            for (int operand = 0; operand < instruction.getNumOperands(); operand++) {
                for (Object object : instruction.getOpObjects(operand)) {
                    if (object instanceof Scalar && ((Scalar)object).getUnsignedValue() == needle) {
                        matched = true;
                        break outer;
                    }
                }
            }
            if (!matched) continue;
            Function function = getFunctionContaining(instruction.getAddress());
            if (function != null && !function.getName().startsWith("thunk_")) {
                functions.put(function.getEntryPoint(), function);
            }
        }

        File dir = new File("/home/femboychik/claude_code/research_27_2/ghidra/field_" + tag);
        dir.mkdirs();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try (PrintWriter index = new PrintWriter(new File(dir, "index.txt"))) {
            for (Function function : functions.values()) {
                index.println(function.getEntryPoint() + " " + function.getName()
                    + " size=" + function.getBody().getNumAddresses());
                DecompileResults result = decompiler.decompileFunction(function, 90, monitor);
                StringBuilder out = new StringBuilder();
                out.append("// ").append(function.getName()).append(" @ ").append(function.getEntryPoint()).append("\n");
                if (result != null && result.decompileCompleted()) {
                    out.append(result.getDecompiledFunction().getC());
                }
                else {
                    InstructionIterator body = currentProgram.getListing().getInstructions(function.getBody(), true);
                    while (body.hasNext()) out.append(body.next().toString()).append("\n");
                }
                try (PrintWriter writer = new PrintWriter(new File(dir, "fn_" + function.getEntryPoint() + ".c"))) {
                    writer.print(out);
                }
            }
        }
        println("FIELD_FUNCTIONS " + tag + " " + functions.size());
    }
}
