// Pre-analysis pass: create functions/labels from an external Apple dyld-cache symbol dump.
// @category PDF
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.listing.Function;
import java.io.BufferedReader;
import java.io.FileReader;

public class NameSymbols extends GhidraScript {
    @Override
    public void run() throws Exception {
        String path = System.getenv("SYMS_FILE");
        if (path == null) { println("SYMS_FILE not set"); return; }
        int made = 0, named = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line;
            while ((line = br.readLine()) != null) {
                int sp = line.indexOf(' ');
                if (sp < 0) continue;
                String addr = line.substring(0, sp);
                String name = line.substring(sp + 1).trim();
                if (name.startsWith("__ZTS") || name.startsWith("_OBJC_") ||
                    name.startsWith("__objc_") || name.startsWith("___block_literal") ||
                    name.startsWith("__ZTV") || name.startsWith("__ZTI")) continue;
                Address a;
                try { a = toAddr("0x" + addr.replaceFirst("^0+", "")); } catch (Exception e) { continue; }
                if (a == null) continue;
                try {
                    if (getInstructionAt(a) == null) disassemble(a);
                    Function f = getFunctionAt(a);
                    if (f == null) f = createFunction(a, name);
                    if (f != null) { f.setName(name, SourceType.USER_DEFINED); named++; }
                } catch (Exception e) { /* keep going */ }
                made++;
            }
        }
        println("NameSymbols: processed=" + made + " named=" + named);
    }
}
