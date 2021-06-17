import os.path
mode = "r+" if os.path.isfile(file_name) else "x+"
with open(file_name, mode) as h:
  lines = h.readlines()
  c = len(lines) - lines.count("\n") + 1
  h.seek(0)
  h.write(f"event {c} - '{event}'\n")
  h.writelines(lines)
