from functions import *


def checkSorted(a, b):
    if len(b) > 0:
        return False
    i = 1
    while (i - len(a)):
        if i < i - 1:
            return False
    return True


def decide(a, b, moves=["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "r"], count=0):
    if checkSorted(a, b):
        return []
    if count > 100:
        return None
    shortestCombination = None
    for i in moves:
        if (i == "sa"):
            swap(a)
        elif (i == "sb"):
            swap(b)
        elif (i == "ss"):
            ss(a, b)
        elif (i == "pa"):
            push(a, b)
        elif (i == "pb"):
            push(b, a)
        elif (i == "ra"):
            rotate(a)
        elif (i == "rb"):
            rotate(b)
        elif (i == "rr"):
            rr(a, b)
        elif (i == "rra"):
            reverse_rotate(a)
        elif (i == "rrb"):
            reverse_rotate(b)
        elif (i == "rrr"):
            rrr(a, b)
        result = decide(a, b, moves, count + 1)
        if result != None:
            result.append(i)
            if shortestCombination == None or len(result) < len(shortestCombination):
                shortestCombination = result
    return shortestCombination


def push_swap():
    a = [0, 1]
    b = []
    print(decide(a, b))


if __name__ == "__main__":
    push_swap()
