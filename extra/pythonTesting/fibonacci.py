def fib(n):
    if n == 1 or n == 2:
        return 1
    values = [1, 1]
    i = 1
    while len(values) < n:
        values.append(values[i-1] + values[i])
        i += 1
    return values[i]


if __name__ == "__main__":
    print(fib(6))
