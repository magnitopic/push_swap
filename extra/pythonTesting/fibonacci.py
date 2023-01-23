def fib(n, values={}):
    if n in values: return values[n]
    if n <= 2: return 1
    values[n] = (fib(n - 1, values) + fib(n - 2, values))
    return values[n]


""" def fib(n):
    if n <= 2: return 1
    return fib(n-1) + fib(n -2)
"""
if __name__ == "__main__":
    print(fib(50))
