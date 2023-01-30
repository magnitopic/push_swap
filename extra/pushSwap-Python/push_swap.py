import copy

from functions import *


def checkSorted(a, b):
    if len(b) > 0:
        return False
    for i in range(len(a)-1):
        if a[i] > a[i+1]:
            return False
    return True


def decide(a, b, count=0, memo={}):
    moves=["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "r"]
    #if str(a) in memo:print(memo[a])
    if checkSorted(a, b):return []
    if count > 6:return None
    shortestCombination = None
    for i in moves:
        aCopy = a[:]
        bCopy = b[:]
        if (i == "sa"):sa(aCopy,bCopy)
        elif (i == "sb"):sb(aCopy,bCopy)
        elif (i == "ss"):ss(aCopy,bCopy)
        elif (i == "pa"):pa(aCopy,bCopy)
        elif (i == "pb"):pb(aCopy,bCopy)
        elif (i == "ra"):ra(aCopy,bCopy)
        elif (i == "rb"):rb(aCopy,bCopy)
        elif (i == "rr"):rr(aCopy, bCopy)
        elif (i == "rra"):rra(aCopy,bCopy)
        elif (i == "rrb"):rrb(aCopy,bCopy)
        elif (i == "rrr"):rrr(aCopy,bCopy)
        if not(a == aCopy and b == bCopy):
            remainderCombination = decide(aCopy, bCopy, count + 1)
            if remainderCombination is not None:
                combination = [*remainderCombination, i]
                if shortestCombination is None or len(combination) < len(shortestCombination):
                    shortestCombination = combination
    #memo[str(a)] = str(shortestCombination)
    return shortestCombination



def push_swap():
    a = [2, 0, -1]
    b = []
    for i in decide(a, b):
        print(i)


if __name__ == "__main__":
    push_swap()
