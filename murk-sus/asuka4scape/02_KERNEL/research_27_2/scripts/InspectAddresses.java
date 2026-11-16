// Inspect blocks, data, instructions, references, and nearby pointers at supplied addresses.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;

public class InspectAddresses extends GhidraScript {
    private String refsTo(Address address) {
        StringBuilder out = new StringBuilder();
        for (Reference ref : getReferencesTo(address)) {
            Function fn = getFunctionContaining(ref.getFromAddress());
            out.append(" ").append(ref.getFromAddress()).append("/").append(ref.getReferenceType());
            out.append(fn == null ? "/no-fn" : "/" + fn.getName() + "@" + fn.getEntryPoint());
        }
        return out.toString();
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        for (String arg : getScriptArgs()) {
            long value = Long.parseUnsignedLong(arg.replace("0x", ""), 16);
            Address address = toAddr(value);
            println("=== ADDRESS " + address);
            MemoryBlock block = mem.getBlock(address);
            if (block == null) {
                println("NO_BLOCK");
                continue;
            }
            println("BLOCK " + block.getName() + " " + block.getStart() + "-" + block.getEnd()
                + " execute=" + block.isExecute() + " initialized=" + block.isInitialized());
            Function fn = getFunctionContaining(address);
            println("FUNCTION " + (fn == null ? "none" : fn.getName() + "@" + fn.getEntryPoint()));
            Data data = getDataContaining(address);
            println("DATA " + (data == null ? "none" : data.getPathName() + " len=" + data.getLength()
                + " value=" + data.getValue()));
            Instruction instruction = getInstructionContaining(address);
            println("INSTRUCTION " + (instruction == null ? "none" : instruction.toString()));
            println("XREFS" + refsTo(address));

            long startValue = value - 0x40;
            long endValue = value + 0x50;
            for (long cursor = startValue; cursor <= endValue; cursor += 8) {
                try {
                    Address slot = toAddr(cursor);
                    if (mem.getBlock(slot) != block) continue;
                    long qword = mem.getLong(slot, currentProgram.getLanguage().isBigEndian());
                    String slotRefs = refsTo(slot);
                    println(String.format("QWORD %s: %016x%s", slot, qword, slotRefs));
                }
                catch (Exception ignored) {
                }
            }
        }
    }
}
