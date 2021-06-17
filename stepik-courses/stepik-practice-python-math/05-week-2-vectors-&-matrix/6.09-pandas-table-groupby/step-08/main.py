df = pd.read_csv('dataset_345422_8.txt', sep=';', index_col=0)
df['cost'] = df.CP_QUANTITY * df.CR_PRICE_1_USD
print(df.groupby(['IP_PROP30', 'IP_PROP32']).cost.sum().loc['pink', 'XL'])
