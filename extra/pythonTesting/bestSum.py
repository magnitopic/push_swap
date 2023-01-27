# Basic algorithm
def bestSum(target, numbers):
    if target == 0:
        return []
    if target < 0:
        return None
    shortestCombination = None
    for i in numbers:
        result = bestSum(target - i, numbers)
        if result != None:
            result.append(i)
            if shortestCombination == None or len(result) < len(shortestCombination):
                shortestCombination = result

    return shortestCombination


# Optimized algorithm
""" def bestSum(target, numbers, memo={}):
    if target in memo:
        return memo[target]
    if target == 0:
        return []
    if target < 0:
        return None
    shortestCombination = None
    for i in numbers:
        result = bestSum(target - i, numbers)
        if result != None:
            result.append(i)
            if shortestCombination == None or len(result) < len(shortestCombination):
                shortestCombination = result
    memo[target] = shortestCombination
    return shortestCombination """


if __name__ == "__main__":
    print(bestSum(8, [1, 4, 5]))
