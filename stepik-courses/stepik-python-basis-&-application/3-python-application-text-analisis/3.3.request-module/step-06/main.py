import re
import requests

start_url = input()
end_url = input()

found = False

link_pattern = re.compile(r'<a[^>]*?href="(.*?)"[^>]*?>')

resp = requests.get(start_url).text
for url in link_pattern.findall(resp):
    cur_resp = requests.get(url).text
    if end_url in link_pattern.findall(cur_resp):
        found = True
        break

print("Yes" if found else "No")
