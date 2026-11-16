"""Step 2/3: dispatch tables (all segments) + per-entry handler analysis."""
import sys, json, struct, bisect
sys.path.insert(0, "/home/femboychik/work/parse_varout3")
from tools import *

TABLES = find_tables()
json.dump(TABLES, open("/home/femboychik/work/parse_varout3/tables.json", "w"))
print("tables:", len(TABLES), "entries:", sum(t['count'] for t in TABLES))
from collections import Counter
print("stride:", Counter(t['stride'] for t in TABLES))
print("kexts:", len(set(t['kext'] for t in TABLES)))
print(Counter(t['kext'] for t in TABLES).most_common(8))
