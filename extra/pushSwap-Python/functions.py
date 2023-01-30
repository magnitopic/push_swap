""" def swap(a):
    if len(a) > 1:
        a[0], a[1] = a[1], a[0]


def ss(a, b):
    swap(a)
    swap(b)


def push(a, b):
    if len(a) > 0:
        b.insert(0, a[0])
        a.pop(0)
    return a,b


def rotate(a):
    if len(a) > 1:
        a.append(a[0])
        a.pop(0)


def rr(a, b):
    rotate(a)
    rotate(b)


def reverse_rotate(a):
    if len(a) > 1:
        a.insert(0, a[len(a)-1])
        a.pop(len(a)-1)


def rrr(a, b):
    reverse_rotate(a)
    reverse_rotate(b)


if __name__ == "__main__":
    a, b = [1, 2, 3], []
    print(a, b)
 """


def sa(a, b):
    if len(a) > 1:
        a[0], a[1] = a[1], a[0]
    return a, b


def sb(a, b):
    if len(b) > 1:
        b[0], b[1] = b[1], b[0]
    return a, b


def ss(a, b):
    sa(a, b)
    sb(a, b)
    return a, b


def pa(a, b):
    if len(b) > 0:
        a.insert(0, b[0])
        b.pop(0)
    return a, b


def pb(a, b):
    if len(a) > 0:
        b.insert(0, a[0])
        a.pop(0)
    return a, b


def ra(a, b):
    if len(a) > 1:
        a.append(a.pop(0))
    return a, b


def rb(a, b):
    if len(b) > 1:
        b.append(b.pop(0))
    return a, b


def rr(a, b):
    ra(a, b)
    rb(a, b)
    return a, b


def rra(a, b):
    if len(a) > 1:
        a.insert(0, a.pop())
    return a, b


def rrb(a, b):
    if len(b) > 1:
        b.insert(0, b.pop())
    return a, b


def rrr(a, b):
    rra(a, b)
    rrb(a, b)
    return a, b
