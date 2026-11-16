# Decompile selected functions by name substring.
# usage: -postScript DecompileByName.py <outfile> <substr1> <substr2> ...
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
outpath = args[0]
subs = [s for s in args[1:]]
fm = currentProgram.getFunctionManager()
dec = DecompInterface()
dec.openProgram(currentProgram)
mon = ConsoleTaskMonitor()

out = open(outpath, 'w')
count = 0
for f in fm.getFunctions(True):
    n = f.getName()
    if not any(s in n for s in subs):
        continue
    out.write('\n/* ===== %s @ %s ===== */\n' % (n, f.getEntryPoint()))
    try:
        res = dec.decompileFunction(f, 60, mon)
        if res and res.decompileCompleted():
            out.write(res.getDecompiledFunction().getC())
        else:
            out.write('/* decompile failed: %s */\n' % (res.getErrorMessage() if res else 'none'))
    except Exception as e:
        out.write('/* error: %s */\n' % e)
    count += 1
out.close()
print('DECOMPILED %d functions -> %s' % (count, outpath))
