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
