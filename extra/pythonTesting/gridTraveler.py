# Basic algorithm
""" def gridTraveler(x, y):
	if x == 1 and y == 1:
		return 1
	if x == 0 or y == 0:
		return 0
	return gridTraveler(x-1, y) + gridTraveler(x, y - 1) """


# Optimized algorithm
def gridTraveler(x, y, memo={}):
    key = str(x)+","+str(y)
    if key in memo:
        return memo[key]
    if x == 1 and y == 1:
        return 1
    if x == 0 or y == 0:
        return 0
    memo[key] = gridTraveler(x-1, y) + gridTraveler(x, y - 1)
    return memo[key]


if __name__ == "__main__":
    print(gridTraveler(10, 50))
