try:
    foo()
except ZeroDivisionError:
    print('ZeroDivisionError')
except ArithmeticError:
    print('ArithmeticError')
except AssertionError:
    print('AssertionError')
