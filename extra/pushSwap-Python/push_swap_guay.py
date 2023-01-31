# FUNCIONES

def sa(stackA, stackB):
    if len(stackA) > 1:
        stackA[0], stackA[1] = stackA[1], stackA[0]
    return stackA, stackB


def sb(stackA, stackB):
    if len(stackB) > 1:
        stackB[0], stackB[1] = stackB[1], stackB[0]
    return stackA, stackB


def ss(stackA, stackB):
    sa(stackA, stackB)
    sb(stackA, stackB)
    return stackA, stackB


def pa(stackA, stackB):
    if len(stackB) > 0:
        stackA.insert(0, stackB[0])
        stackB.pop(0)
    return stackA, stackB


def pb(stackA, stackB):
    if len(stackA) > 0:
        stackB.insert(0, stackA[0])
        stackA.pop(0)
    return stackA, stackB


def ra(stackA, stackB):
    if len(stackA) > 1:
        stackA.append(stackA.pop(0))
    return stackA, stackB


def rb(stackA, stackB):
    if len(stackB) > 1:
        stackB.append(stackB.pop(0))
    return stackA, stackB


def rr(stackA, stackB):
    ra(stackA, stackB)
    rb(stackA, stackB)
    return stackA, stackB


def rra(stackA, stackB):
    if len(stackA) > 1:
        stackA.insert(0, stackA.pop())
    return stackA, stackB


def rrb(stackA, stackB):
    if len(stackB) > 1:
        stackB.insert(0, stackB.pop())
    return stackA, stackB


def rrr(stackA, stackB):
    rra(stackA, stackB)
    rrb(stackA, stackB)
    return stackA, stackB


def checkSorted(stackA, stackB):
    if len(stackB) > 0:
        return False
    for i in range(len(stackA)-1):
        if stackA[i] > stackA[i+1]:
            return False
    return True


def decide(a, b, count=0):
    moves = ["sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"]
    if checkSorted(a, b): return []
    if count > 1: return None
    shortestCombination = None
    aCopy, bCopy = None, None
    for i in moves:
        if (i == "sa"): aCopy, bCopy = sa(a[:], b[:])
        elif (i == "sb"):aCopy, bCopy = sb(a[:], b[:])
        elif (i == "ss"):aCopy, bCopy = ss(a[:], b[:])
        elif (i == "pa"):aCopy, bCopy = pa(a[:], b[:])
        elif (i == "pb"):aCopy, bCopy = pb(a[:], b[:])
        elif (i == "ra"):aCopy, bCopy = ra(a[:], b[:])
        elif (i == "rb"):aCopy, bCopy = rb(a[:], b[:])
        elif (i == "rr"):aCopy, bCopy = rr(a[:], b[:])
        elif (i == "rra"):aCopy, bCopy = rra(a[:], b[:])
        elif (i == "rrb"):aCopy, bCopy = rrb(a[:], b[:])
        elif (i == "rrr"):aCopy, bCopy = rrr(a[:], b[:])
        if a != aCopy or b != bCopy:
            sonCombination = decide(aCopy, bCopy, count +1)
            if sonCombination is not None:
                combination = [*sonCombination, i]
                if shortestCombination is None or len(combination) < len(shortestCombination):
                    shortestCombination = combination
                    return shortestCombination



if __name__ == "__main__":
    a_inicial = [3, 2, 1]
    b_inicial = []
    print(decide(a_inicial, b_inicial))
