# Basic algorithm
def countConstruct(target, strings):
    if (target == ""):
        return 1
    totalCount = 0
    for i in strings:
        if (not target.find(i)):
            newString = target[len(i):len(target)]
            result = countConstruct(newString, strings)
            if result > 0:
                totalCount += result
    return totalCount


if __name__ == "__main__":
    print(countConstruct("purple", ["purp", "p", "ur", "le", "purpl"]))
