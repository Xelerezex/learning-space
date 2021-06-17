df_group = df.groupby('Club')
dmean = df_group.mean()['Wage']
dmed = df_group.median()['Wage']
print(sum(dmean == dmed))
