import re
import sys

for line in sys.stdin:
    line = line.strip()
    pattern = re.compile(r'\b(\w+)\1\b')
    print(line) if re.search(pattern, line) is not None else None
