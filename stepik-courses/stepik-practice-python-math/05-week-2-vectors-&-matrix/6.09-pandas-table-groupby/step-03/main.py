df = pd.read_csv('torg.csv', sep=';')

df_group = df[['IP_PROP32', 'CP_QUANTITY']].groupby('IP_PROP32')
print(df_group.sum().sort_values('CP_QUANTITY'))
