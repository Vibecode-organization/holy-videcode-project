// Export function entry, size, name.
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;
public class ExportFuncs extends GhidraScript {
    public void run() throws Exception {
        String out = System.getenv("OUT");
        if (out == null) { println("OUT not set"); return; }
        try (PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter(out)))) {
            int n = 0;
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                w.println(f.getEntryPoint() + " " + f.getBody().getNumAddresses() + " " + f.getName());
                n++;
            }
            println("exported " + n);
        }
    }
}
