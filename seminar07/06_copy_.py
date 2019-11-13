from copy import copy, deepcopy

# there is no copy by default

a = [1, 2.0, [3, 4]]
b = a
b[0] = -1
b[2][1] = -4
print(a)
print(b)
print()

# shallow copy (copies only top-level content)

a = [1, 2.0, [3, 4]]
b = copy(a)
b[0] = -1
b[2][1] = -4
print(a)
print(b)
print()

# deep copy (copies all data (even that should not be copied))

a = [1, 2.0, [3, 4]]
b = deepcopy(a)
b[0] = -1
b[2][1] = -4
print(a)
print(b)
print()
