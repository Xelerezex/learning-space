import re
import sys

pattern = "^(0|(1(01*0)*1))*$"
pattern = re.compile(pattern)
for line in sys.stdin:
    line = line.rstrip()
    if pattern.match(line):
        print(line)

# For Idiots
#
#import sys
#import re
#
# for line in sys.stdin:
#    try:
#        line = line.rstrip()
#        print(line) if int(line, base = 2) % 3 == 0 else None
#    except ValueError:
#        pass
