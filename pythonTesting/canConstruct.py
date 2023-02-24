# Basic algorithm
""" def canConstruct(string, letters):
    if string == "":
        return True
    for i in letters:
        if (not string.find(i)):
            newString = string[len(i):len(string)]
            if (canConstruct(newString, letters)):
                return True

    return False """


# Optimized algorithm
def canConstruct(string, letters, memo={}):
    if string in memo:
        return memo[string]
    if string == "":
        return True
    for i in letters:
        if (not string.find(i)):
            newString = string[len(i):len(string)]
            if (canConstruct(newString, letters)):
                memo[string] = True
                return True
    memo[string] = False
    return False


if __name__ == "__main__":
    print(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeef", [
          "e", "ee", "eee", "eeee", "eeeee", "eeeeee", "eeeeeee"]))
