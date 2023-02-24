# Basic algorithm
""" def bestSum(targetSum, numbers):
    if targetSum == 0: return []
    if targetSum < 0: return None

    shortestCombination = None

    for num in numbers:
        remainder = targetSum - num
        remainderCombination = bestSum(remainder, numbers)
        if remainderCombination is not None:
            combination = [*remainderCombination, num]
            if shortestCombination is None or len(combination) < len(shortestCombination):
                shortestCombination = combination

    return shortestCombination """


# Optimized algorithm
def bestSum(targetSum, numbers, memo={}):
    if targetSum in memo: return memo[targetSum]
    if targetSum == 0: return []
    if targetSum < 0: return None

    shortestCombination = None

    for num in numbers:
        remainder = targetSum - num
        remainderCombination = bestSum(remainder, numbers, memo)
        if remainderCombination is not None:
            combination = [*remainderCombination, num]
            if shortestCombination is None or len(combination) < len(shortestCombination):
                shortestCombination = combination

    memo[targetSum] = shortestCombination
    return shortestCombination


if __name__ == "__main__":
    print(bestSum(100, [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]))
