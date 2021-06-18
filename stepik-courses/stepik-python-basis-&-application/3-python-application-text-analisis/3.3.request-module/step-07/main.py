import re
import requests

resp = requests.get(input()).text
sites = set()
for site in re.findall(r'<a.*?href=".*?:\/\/((?:\w|-)+(?:\.(?:\w|-)+)+)', resp):
    sites.add(site)

for site in sorted(sites):
    print(site)
