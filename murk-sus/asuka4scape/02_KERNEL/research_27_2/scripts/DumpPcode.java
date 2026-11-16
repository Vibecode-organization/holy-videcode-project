// Dump high p-code and assembly for supplied functions to verify expression widths.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import java.io.*;
import java.util.*;

public class DumpPcode extends GhidraScript {
    private String varnode(Varnode node) {
        if (node == null) return "null";
        return String.format("%s(size=%d)", node.toString(), node.getSize());
    }

    public void run() throws Exception {
        File dir = new File("/home/femboychik/claude_code/research_27_2/ghidra/pcode");
        dir.mkdirs();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        for (String arg : getScriptArgs()) {
            long value = Long.parseUnsignedLong(arg.replace("0x", ""), 16);
            Function function = getFunctionAt(toAddr(value));
            if (function == null) {
                println("NO_FUNCTION " + toAddr(value));
                continue;
            }
            String base = function.getEntryPoint().toString();
            DecompileResults result = decompiler.decompileFunction(function, 240, monitor);
            if (result != null && result.decompileCompleted()) {
                HighFunction high = result.getHighFunction();
                try (PrintWriter out = new PrintWriter(new File(dir, base + ".pcode.txt"))) {
                    Iterator<PcodeOpAST> ops = high.getPcodeOps();
                    while (ops.hasNext()) {
                        PcodeOpAST op = ops.next();
                        StringBuilder line = new StringBuilder();
                        line.append(op.getSeqnum().getTarget()).append(" ").append(op.getMnemonic());
                        line.append(" OUT=").append(varnode(op.getOutput()));
                        for (int i = 0; i < op.getNumInputs(); i++) {
                            line.append(" IN").append(i).append("=").append(varnode(op.getInput(i)));
                        }
                        out.println(line);
                    }
                }
            }
            try (PrintWriter out = new PrintWriter(new File(dir, base + ".asm.txt"))) {
                InstructionIterator instructions = currentProgram.getListing().getInstructions(function.getBody(), true);
                while (instructions.hasNext()) {
                    Instruction instruction = instructions.next();
                    out.println(instruction.getAddress() + " " + instruction);
                }
            }
            println("WROTE_PCODE " + base + " decompiled=" + (result != null && result.decompileCompleted()));
        }
    }
}
