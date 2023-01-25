def swap(a):
    if len(a) > 1:
        a[0] = a[1]


def ss(a, b):
    swap(a)
    swap(b)


def push(a, b):
    if len(a) > 0:
        b.insert(0, a[0])
        a.pop(0)


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


if __name__ == "__main__":
    a, b = [1, 2, 3], []
    print(a, b)
