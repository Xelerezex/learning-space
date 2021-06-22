from numpy import std, mean

data = [gen() for i in range(50_000)]
print("Mean: ", round(mean(data), 2), "\n",
      "Sd: ", round(std(data), 2), sep="")
