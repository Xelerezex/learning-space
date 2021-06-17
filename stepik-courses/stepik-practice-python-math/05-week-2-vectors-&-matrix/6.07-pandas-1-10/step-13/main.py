print(df.filter(df.index[[0, 2, 3]], axis="index").filter(["name", "age"], axis="columns"))
