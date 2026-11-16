// Locate instructions containing exact scalar operands and print owning functions.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.util.*;

public class ScanScalarUses extends GhidraScript {
    public void run() throws Exception {
        Set<Long> needles = new HashSet<>();
        for (String arg : getScriptArgs()) {
            needles.add(Long.parseUnsignedLong(arg.replace("0x", ""), 16));
        }
        InstructionIterator instructions = currentProgram.getListing().getInstructions(true);
        int matches = 0;
        while (instructions.hasNext()) {
            Instruction instruction = instructions.next();
            long found = -1;
            outer:
            for (int operand = 0; operand < instruction.getNumOperands(); operand++) {
                for (Object object : instruction.getOpObjects(operand)) {
                    if (object instanceof Scalar) {
                        long value = ((Scalar)object).getUnsignedValue();
                        if (needles.contains(value)) {
                            found = value;
                            break outer;
                        }
                    }
                }
            }
            if (found < 0) continue;
            Function function = getFunctionContaining(instruction.getAddress());
            println(String.format("SCALAR 0x%x %s %s FUNCTION %s", found,
                instruction.getAddress(), instruction,
                function == null ? "none" : function.getName() + "@" + function.getEntryPoint()));
            matches++;
        }
        println("MATCHES " + matches);
    }
}
