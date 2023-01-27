import copy

from functions import *


def checkSorted(a, b):
    if len(b) > 0:
        return False
    for i in range(len(a)-1):
        if a[i] > a[i+1]:
            return False
    return True


def decide(a, b, moves=["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "r"], count=0):
    if checkSorted(a, b):
        return []
    if count > 4:
        return None
    shortestCombination = None
    for i in moves:
        aCopy = copy.deepcopy(a)
        bCopy = copy.deepcopy(b)
        if (i == "sa"):
            swap(aCopy)
        elif (i == "sb"):
            swap(bCopy)
        elif (i == "ss"):
            ss(aCopy, bCopy)
        elif (i == "pa"):
            push(aCopy, bCopy)
        elif (i == "pb"):
            push(bCopy, aCopy)
        elif (i == "ra"):
            rotate(aCopy)
        elif (i == "rb"):
            rotate(bCopy)
        elif (i == "rr"):
            rr(aCopy, bCopy)
        elif (i == "rra"):
            reverse_rotate(aCopy)
        elif (i == "rrb"):
            reverse_rotate(bCopy)
        elif (i == "rrr"):
            rrr(aCopy, bCopy)
        result = decide(aCopy, bCopy, moves, count + 1)
        if result != None:
            result.append(i)
            if shortestCombination == None or len(result) < len(shortestCombination):
                shortestCombination = result
    return shortestCombination


def push_swap():
    a = [1, 0, -1]
    b = []
    print(decide(a, b))


if __name__ == "__main__":
    push_swap()
