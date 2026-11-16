// Verify program identity against known AMFI kext bases
// @category iOS
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;

public class Probe extends GhidraScript {
    public void run() throws Exception {
        println("PROGRAM " + currentProgram.getName());
        println("EXECPATH " + currentProgram.getExecutablePath());
        println("IMGBASE " + currentProgram.getImageBase());
        println("LANG " + currentProgram.getLanguage().getLanguageID());
        String[] addrs = {"fffffff007634200","fffffff00762cd70","fffffff00758fae0","fffffff007638bd9"};
        Memory mem = currentProgram.getMemory();
        for (String s : addrs) {
            Address a = toAddr(Long.parseUnsignedLong(s, 16));
            StringBuilder hex = new StringBuilder();
            StringBuilder asc = new StringBuilder();
            for (int i = 0; i < 32; i++) {
                try {
                    byte b = mem.getByte(a.add(i));
                    hex.append(String.format("%02x", b));
                    asc.append(b >= 32 && b < 127 ? (char) b : '.');
                } catch (Exception e) { hex.append("??"); }
            }
            println("MEM " + s + " " + hex + " | " + asc);
        }
        // dump the kext list-ish: functions whose name mentions AMFI-ish
        int n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            String nm = f.getName();
            if (nm.startsWith("sub_") ) continue;
            if (nm.contains("trustCache") || nm.contains("TrustCache") || nm.contains("amfi") || nm.contains("AMFI") || nm.contains("cdhash") || nm.contains("CodeSign") || nm.contains("codesign")) {
                if (n++ < 400) println("FN " + f.getEntryPoint() + " " + nm);
            }
        }
        println("FNCOUNT " + n);
    }
}
