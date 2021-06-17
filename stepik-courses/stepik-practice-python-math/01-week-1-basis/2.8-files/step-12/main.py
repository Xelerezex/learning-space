try:
  with open(input(), mode="r", encoding="utf-8") as file:
    print("CONTENT:")
    print(file.read())
except FileNotFoundError:
  print("ERROR:")
  print("Файл не существует")
except IsADirectoryError:
  print("ERROR:")
  print("Это каталог, а не файл")
