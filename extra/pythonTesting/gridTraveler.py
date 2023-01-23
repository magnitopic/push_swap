# Basic algorithm
def gridTraveler(x, y):
    if x == 1 and y == 1:
        return 1
    if x == 0 or y == 0:
        return 0
    len = gridTraveler(x-1, y) + gridTraveler(x, y - 1)
    return len


if __name__ == "__main__":
    print(gridTraveler(10, 15))
