def derivative(f, x0=0, dx=1e-6):
    return round((f(x0 + dx) - f(x0)) / dx, 3)
