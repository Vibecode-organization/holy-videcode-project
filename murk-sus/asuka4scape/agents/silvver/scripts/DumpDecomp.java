// DumpDecomp.java — Ghidra headless post-script для задачи #2 (KASLR 27.2).
//
// Зачем: программа в проекте 123.rep — это бинарная БД Ghidra (~1 ГБ, db.1.gbf),
// текстом её читать нельзя. Скрипт выгружает ровно то, что нужно агенту: версию
// ядра (чтобы понять, та ли это сборка) и декомпиляцию указанных функций.
//
// Запуск (Ghidra 12, без Jython — это Java GhidraScript):
//
//   cd /home/femboychik/asuka4scape
//   touch 10_ARTIFACTS/kernelcache/123.gpr
//   ./ghidra/support/analyzeHeadless 10_ARTIFACTS/kernelcache 123 \
//     -process kernelcache.release.iphone14b.decompressed -noanalysis \
//     -scriptPath agents/silvver/scripts \
//     -postScript DumpDecomp.java /tmp/decomp_dump.c \
//     0xfffffff00a21347c 0xfffffff00a2af7c8 0xfffffff00a2af6ac 0xfffffff00a2af568 0xfffffff009c3ab8c
//
// Аргументы: первый (необязательный) — путь к выходному файлу (иначе
// ~/decomp_dump.c), остальные — VA функций.
//
// Что печатает:
//   1. имя программы, image base, число функций;
//   2. строку "Darwin Kernel Version ..." из памяти (идентификация сборки);
//   3. для каждого VA: имя функции, её entry, размер и декомпилированный C.
// Если VA не попадает ни в одну функцию — печатает ближайшую предшествующую.

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;

import java.io.File;
import java.io.PrintWriter;

public class DumpDecomp extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outPath = System.getProperty("user.home") + "/decomp_dump.c";
        int first = 0;
        if (args.length > 0 && !args[0].startsWith("0x")) {
            outPath = args[0];
            first = 1;
        }

        PrintWriter out = new PrintWriter(new File(outPath));
        try {
            out.println("// program: " + currentProgram.getName());
            out.println("// image base: " + currentProgram.getImageBase());
            out.println("// functions: " + currentProgram.getFunctionManager().getFunctionCount());
            out.println("// exe format: " + currentProgram.getExecutableFormat());
            out.println();

            String ver = findKernelVersion();
            out.println("// DARWIN VERSION STRING: " + (ver == null ? "<not found>" : ver));
            out.println();

            DecompInterface ifc = new DecompInterface();
            ifc.toggleCCode(true);
            ifc.openProgram(currentProgram);

            for (int i = first; i < args.length; i++) {
                String s = args[i].trim();
                Address addr = toAddr(s);
                if (addr == null) {
                    out.println("// ==== " + s + " : BAD ADDRESS");
                    continue;
                }
                Function f = getFunctionContaining(addr);
                if (f == null) {
                    f = getFunctionBefore(addr);
                    out.println("// ==== " + s + " : no function containing it, using previous");
                }
                if (f == null) {
                    out.println("// ==== " + s + " : NO FUNCTION FOUND (addr mapped="
                                + currentProgram.getMemory().contains(addr) + ")");
                    continue;
                }
                out.println("// ==== " + s + " -> " + f.getName()
                            + " @ " + f.getEntryPoint()
                            + " size=" + f.getBody().getNumAddresses());
                DecompileResults res = ifc.decompileFunction(f, 90, monitor);
                if (res != null && res.decompileCompleted()) {
                    out.println(res.getDecompiledFunction().getC());
                } else {
                    out.println("// decompile FAILED: "
                                + (res == null ? "null" : res.getErrorMessage()));
                }
                out.println();
            }
            ifc.dispose();
        } finally {
            out.close();
        }
        println("DumpDecomp: written " + outPath);
    }

    private String findKernelVersion() {
        try {
            Memory mem = currentProgram.getMemory();
            byte[] needle = "Darwin Kernel Version".getBytes("US-ASCII");
            Address a = mem.findBytes(currentProgram.getMinAddress(), needle, null, true, monitor);
            if (a == null) return null;
            byte[] buf = new byte[256];
            int n = mem.getBytes(a, buf);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                int c = buf[i] & 0xff;
                if (c == 0) break;
                if (c < 0x20 || c > 0x7e) { sb.append('.'); continue; }
                sb.append((char) c);
            }
            return sb.toString();
        } catch (Exception e) {
            return "<error: " + e.getMessage() + ">";
        }
    }

    private Address toAddr(String s) {
        try {
            return currentProgram.getAddressFactory()
                    .getDefaultAddressSpace().getAddress(s);
        } catch (Exception e) {
            return null;
        }
    }
}
