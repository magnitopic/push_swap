# Basic algorithm
def howSum(target, numbers):
    if target == 0:
        return []
    if target < 0:
        return None

    for i in numbers:
        result = howSum(target - i, numbers)
        if result != None:
            result.append(i)
            return result

    return None


if __name__ == "__main__":
    print(howSum(5, [5, 3, 2]))
