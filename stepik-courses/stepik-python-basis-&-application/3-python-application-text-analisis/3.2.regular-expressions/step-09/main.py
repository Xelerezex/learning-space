import re
import sys

for line in sys.stdin:
    line = line.strip()
    pattern = re.compile(r'z...z')
    print(line) if re.search(pattern, line) is not None else None
