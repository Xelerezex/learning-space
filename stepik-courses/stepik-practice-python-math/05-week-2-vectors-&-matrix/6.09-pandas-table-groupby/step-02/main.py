import pandas as pd

df = pd.read_csv('torg.csv', sep=';')
df_group = df[['IP_PROP30', 'CP_QUANTITY']].groupby('IP_PROP30')
print(df_group.sum().idxmax())
