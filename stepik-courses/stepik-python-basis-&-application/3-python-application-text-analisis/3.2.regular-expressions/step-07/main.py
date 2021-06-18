import sys
import re

for line in sys.stdin:
    line = line.rstrip()
    print(line) if len(re.findall('cat', line)) >= 2 else None
