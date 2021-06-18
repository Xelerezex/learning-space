with open(sheet) as data, open(mean) as m:
  grade = [int(i.split()[-2]) for i in data.readlines() if i.split()[-1] not in ["(неявка)", "(недопуск)"]]
  print("OK" if sum(grade) / len(grade) == float(m.readline()) else "ERROR")
