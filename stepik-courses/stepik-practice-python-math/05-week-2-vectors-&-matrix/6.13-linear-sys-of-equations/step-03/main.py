import numpy

args = [list(map(float, input().split())) for _ in range(2)]

m = numpy.array([i[:-1] for i in args])
v = numpy.array(list(i[-1] for i in args))

print(*numpy.linalg.solve(m, v))
