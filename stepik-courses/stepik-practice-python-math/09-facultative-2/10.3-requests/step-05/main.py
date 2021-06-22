import requests

url = str(input())
r = requests.get(url)

print(r.text if (r.status_code == 200) else f"Упс, произошла ошибка!..\nКод ошибки - {r.status_code}", sep="")
