# Basic algorithm
""" def canSum(target, numbers=[]):
    if target == 0:
        return True
    if target < 0:
        return False
    for i in numbers:
        if canSum(target - i, numbers):
            return True
    return False """


# Optimized algorithm
def canSum(target, numbers=[], memo={}):
    if target in memo:
        return memo[target]
    if target == 0:
        return True
    if target < 0:
        return False
    for i in numbers:
        if canSum(target - i, numbers, memo):
            memo[target] = True
            return True
    memo[target] = False
    return False


if __name__ == "__main__":
    print(canSum(300, [7, 14]))
