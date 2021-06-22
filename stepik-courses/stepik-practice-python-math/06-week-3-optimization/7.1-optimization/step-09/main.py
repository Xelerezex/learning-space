from scipy.optimize import golden

print(golden(lambda x: (x + a)**2 - b), golden(lambda x: abs((x + a)**2 - b)))
