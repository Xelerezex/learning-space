import pandas as pd

print(*pd.Series(input().split()).mode())
