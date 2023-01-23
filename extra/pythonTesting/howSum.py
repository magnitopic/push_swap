# Basic algorithm
""" def howSum(target, numbers):
    if target == 0:
        return []
    if target < 0:
        return None

    for i in numbers:
        result = howSum(target - i, numbers)
        if result != None:
            result.append(i)
            return result

    return None """


# Optimized algorithm
def howSum(target, numbers, memo={}):
    if target in memo:
        return memo[target]
    if target == 0:
        return []
    if target < 0:
        return None

    for i in numbers:
        result = howSum(target - i, numbers, memo)
        if result != None:
            result.append(i)
            memo[target] = result
            return result
    memo[target] = None
    return None


if __name__ == "__main__":
    print(howSum(300, [7, 14]))
