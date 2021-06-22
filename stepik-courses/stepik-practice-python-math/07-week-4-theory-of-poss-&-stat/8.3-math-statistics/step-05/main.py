import pandas as pd
import numpy as np

VAR = list(map(int, str(input()).split(" ")))
#mode = list(map(int, "".join(list(map(str, pd.Series(VAR).mode().tolist())))))
mode = list(map(int, (" ".join(list(map(str, pd.Series(VAR).mode().tolist())))).split(" ")))
mean = np.mean(VAR)
median = np.median(VAR)

dictionary = {"Ме<Ср": True if (median < mean) else False,
              "Ме>Ср": True if (median > mean) else False,
              "Ме=Ср": True if (median == mean) else False,
              "Мо<Ср": True if ([mean > i for i in mode].count(True) > 0) else False,
              "Мо>Ср": True if ([mean < i for i in mode].count(True) > 0) else False,
              "Мо=Ср": True if ([mean == i for i in mode].count(True) > 0) else False,
              "Мо>Ме": True if ([median < i for i in mode].count(True) > 0) else False,
              "Мо<Ме": True if ([median > i for i in mode].count(True) > 0) else False,
              "Мо=Ме": True if ([median == i for i in mode].count(True) > 0) else False, }

true_dict = [i + "\n" for i in list(dictionary.keys()) if dictionary[i] == True]
#*list(map( lambda x: x + " ", map(str, mode)))

print("Среднее: ", round(mean, 1), "\n",
      "Медиана: ", round(median, 1), "\n",
      ("Мода: " if len(mode) == 1 else "Моды: "), *list(map(lambda x: x + " ", map(str, mode))), "\n",
      *true_dict, sep='')
