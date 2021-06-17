for x in df.describe():
    print(x + ":" + str(df[x].sum()))
