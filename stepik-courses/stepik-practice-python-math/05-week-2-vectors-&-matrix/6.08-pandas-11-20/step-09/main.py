df.loc[new_index] = new_data
df.drop(del_index, inplace=True)
print(df)
