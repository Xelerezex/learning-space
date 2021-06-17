import numpy as np
import pandas as pd

names = df[filter_names[0]] == filter_values[0]
values = df[filter_names[1]] < filter_values[1]
print(df[names & values])
