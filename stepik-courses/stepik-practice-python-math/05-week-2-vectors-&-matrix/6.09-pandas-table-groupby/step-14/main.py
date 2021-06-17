df['Date'] = pd.to_datetime(df['Date'])
df = df.assign(weekday=df['Date'].dt.day_name())

df_mean = df.groupby(by=['weekday']).mean()

df_sum = df_mean.sum(axis="columns")
df_sum.idxmax()
