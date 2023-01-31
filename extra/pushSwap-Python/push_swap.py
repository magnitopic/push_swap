from functions import *


def checkSorted(stackA, stackB):
    if len(stackB) > 0:
        return False
    for i in range(len(stackA)-1):
        if stackA[i] > stackA[i+1]:
            return False
    return True

def decide(a, b, count=0):
    moves = ["sa", "sb", "ss", "pa", "pb",
             "ra", "rb", "rr", "rra", "rrb", "rrr"]
    if checkSorted(a, b): return []
    if count > 6: return None
    shortestCombination = None
    aCopy, bCopy = None, None
    for i in moves:
        if (i == "sa"): aCopy, bCopy = sa(a[:], b[:])
        elif (i == "sb"): aCopy, bCopy = sb(a[:], b[:])
        elif (i == "ss"): aCopy, bCopy = ss(a[:], b[:])
        elif (i == "pa"): aCopy, bCopy = pa(a[:], b[:])
        elif (i == "pb"): aCopy, bCopy = pb(a[:], b[:])
        elif (i == "ra"): aCopy, bCopy = ra(a[:], b[:])
        elif (i == "rb"): aCopy, bCopy = rb(a[:], b[:])
        elif (i == "rr"): aCopy, bCopy = rr(a[:], b[:])
        elif (i == "rra"): aCopy, bCopy = rra(a[:], b[:])
        elif (i == "rrb"): aCopy, bCopy = rrb(a[:], b[:])
        elif (i == "rrr"): aCopy, bCopy = rrr(a[:], b[:])
        if a != aCopy or b != bCopy:
            sonCombination = decide(aCopy, bCopy, count + 1)
            if sonCombination is not None:
                combination = [i, *sonCombination]
                if shortestCombination is None or len(combination) < len(shortestCombination):
                    shortestCombination = combination
                    return shortestCombination


if __name__ == "__main__":
    a_inicial = [2, 6, 1, 8, 7, 10]
    b_inicial = []
    resultado = decide(a_inicial, b_inicial)
    if resultado == None:
        print(None)
    else:
        for i in resultado:
            print(i)
