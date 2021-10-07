import copy

org = [0,1,2,3,4]
cpy = copy.copy(org)
cpy[0] = -10
print(cpy)
print(org)

org = [0,1,2,3,4]
cpy = org.copy()
cpy[0] = -10
print(cpy)
print(org)

org = [0,1,2,3,4]
cpy = list(org)
cpy[0] = -10
print(cpy)
print(org)

org = [0,1,2,3,4]
cpy = org[:]
cpy[0] = -10
print(cpy)
print(org)

