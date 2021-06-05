import re
import sys

for line in sys.stdin:
    line = line.strip()
    result = re.sub(r'human', r'computer', line)
    print(result)
