from functions import *

# LIS algorithm


def algoritmo_LIS(arr):
    n = len(arr)
    lis = [1]*n
    prev = list(range(n))  # una lista con los index

    # Compute optimized LIS values in bottom up manner
    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j]+1
                prev[i] = j

    # Initialize maximum to 0 to get the maximum of all
    # LIS
    maximum = 0
    idx = 0

    # Pick maximum of all LIS values
    for i in range(n):
        if maximum < lis[i]:
            maximum = lis[i]
            idx = i

    seq = [arr[idx]]
    while idx != prev[idx]:
        idx = prev[idx]
        seq.append(arr[idx])

    return list(reversed(seq))

def getValorA(a, b):
    values = []
    value = None
    for i in a:
        values.append(getSymbol(a.index(i), len(a)))
    return value


def getValorB(a, b):
    values = []
    count = 0
    for i in b:
        while b[count] < a[0] and b[count-1] < a[0]:
            count += 1
        values.append(getSymbol(count, len(b)))
    return values


def getSymbol(value, len):
    if value < len / 2:
        return value
    else:
        return value - len

def sendLis(a, b, lis):
    for i in lis:
        if a.index(i) < len(a)/2:
            for j in range(a.index(i)):
                print("ra")
                ra(a, b)
        else:
            for j in range(len(a)-a.index(i)):
                print("rra")
                rra(a, b)
        print("pb")
        pb(a,b)

def push_swap(a):
    b = []
    # get lis elements
    while len(a) > 0:
        lis = algoritmo_LIS(a)
        # send lis values to stack b
        sendLis(a, b, lis)
        print(a, b)

if __name__ == "__main__":
    """ a = [1, 2, 3, 4, 5, 6]
    b = []
    getValorB(a, b) """
    push_swap([35, 90, 6, 15, 7, 40, 85, 63, 50, 13, 45, 8, 76, 33, 25, 27, 42, 20, 94, 48, 91, 29, 95, 77, 82, 98, 86, 69, 60, 58, 79,
                55, 24, 12, 28, 93, 73, 54, 84, 44, 10, 75, 3, 32, 89, 52, 51, 16, 56, 70, 22, 11, 59, 68, 100, 96, 71, 21, 26, 38, 1,
                46, 92, 36, 88, 31, 66, 34, 74, 23, 5, 9, 43, 49, 37, 80, 18, 17, 67, 83, 78, 61, 47, 57, 64, 81, 97, 53, 65, 30, 2,
                99, 14, 87, 39, 19, 72, 4, 62, 41])
