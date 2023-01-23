# Basic algorithm
def canSum(target, numbers=[]):
    if target == 0: return True
    if target < 0: return False
    for i in numbers:
        if canSum(target - i, numbers):
            return True
    return False

if __name__ == "__main__":
    print(canSum(5, [1, 2, 3, 2]))