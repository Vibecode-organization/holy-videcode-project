// Batch decompile functions listed in a file (one hex address per line).
// usage: DumpBatch.java <outdir> <listfile>
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class DumpBatch extends GhidraScript {
    public void run() throws Exception {
        String[] a = getScriptArgs();
        File dir = new File(a[0]);
        dir.mkdirs();
        List<String> lines = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(a[1]))) {
            String l;
            while ((l = br.readLine()) != null) {
                l = l.trim();
                if (!l.isEmpty()) lines.add(l);
            }
        }
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        for (String arg : lines) {
            long value = Long.parseUnsignedLong(arg.replace("0x", ""), 16);
            Address address = toAddr(value);
            Function function = getFunctionAt(address);
            if (function == null) function = getFunctionContaining(address);
            if (function == null) { println("NO_FUNCTION " + address); continue; }
            StringBuilder out = new StringBuilder();
            out.append("// ").append(function.getName()).append(" @ ").append(function.getEntryPoint());
            out.append(" size=").append(function.getBody().getNumAddresses()).append("\n");
            DecompileResults result = decompiler.decompileFunction(function, 180, monitor);
            if (result != null && result.decompileCompleted()) {
                out.append(result.getDecompiledFunction().getC());
            } else {
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
