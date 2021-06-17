import numpy as np
try:
    Z = A @ B
except ValueError:
    Z = 'Упс! Что-то пошло не так...'
