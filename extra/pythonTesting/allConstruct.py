# Basic algorithm
""" def allConstruct(target, strings):
    if target == '':
        return [[]]
    totalOptions = []

    for i in strings:
        if (not target.find(i)):
            newString = target[len(i):len(target)]
            suffixWays = allConstruct(newString, strings)
            [way.insert(0, i) for way in suffixWays]
            totalOptions += suffixWays
    return totalOptions """


# Optimized algorithm
def allConstruct(target, strings, memo={}):
    if target in memo:
        return memo[target]
    if target == '':
        return [[]]
    totalOptions = []

    for i in strings:
        if (not target.find(i)):
            newString = target[len(i):len(target)]
            suffixWays = allConstruct(newString, strings)
            [way.insert(0, i) for way in suffixWays]
            totalOptions += suffixWays
    memo[target] = totalOptions
    return totalOptions


if __name__ == "__main__":
    print(allConstruct("aaaaaaaaaaaaaaaaaaaaaaaaaaz",
          ["a", "aa", "aaa", "aaaa", "aaaaa"]))
