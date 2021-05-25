import datetime as dt

data = list(map(int, str(input()).split(" ")))
plusdata = dt.timedelta(int(input()))
firstdata = dt.date(data[0], data[1], data[2])
output = (plusdata + firstdata)
print(output.year, output.month, output.day)
