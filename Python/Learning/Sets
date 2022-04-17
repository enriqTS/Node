#Desorganizado, mutavel, sem duplicados
myset = {1, 2, 3, 4, 5, 1, 2}
print(myset)
print("4\n")

myset2 = set("Hello")
print(myset2)
print("8\n")

myset3 = set([1, 2,3])
print(myset3)
print("12\n")

myset = set()
myset.add(1)
myset.add(2)
myset.add(3)
print(myset)
print("19\n")

myset.remove(3) #myset.discard faz a mesma coisa, mas se nao tiver o elemento no set nao ocorre nenhum erro
print(myset)
print("23\n")

myset.pop()
print(myset)
print("27\n")

myset = {1, 2, 3, 4, 5, 6}

for i in myset: 
    print(i)
print("33\n")

if 1 in myset:
    print("yes")
print("37\n")

odds = {1, 3, 5, 7, 9}
evens = {0, 2, 4, 6, 8}
primes = {2, 3, 5, 7}

u = odds.union(evens)
print(u)
print("45\n")

i = odds.intersection(evens)
print(i)
print("49\n")
i = odds.intersection(primes)
print(i)
print("52\n")

setA = {1, 2, 3, 4, 5, 6, 7, 8, 9}
setB = {1, 2, 3, 10, 11, 12}

diff = setA.difference(setB)
print(diff)
print("59\n")
diff = setB.difference(setA)
print(diff)
print("62\n")
diff = setA.symmetric_difference(setA) # Esse nao importa a ordem
print(diff)
print("65\n")

setA.update(setB)
print(setA)
print("69\n")

setA = {1, 2, 3, 4, 5, 6, 7, 8, 9}
setB = {1, 2, 3, 10, 11, 12}

setA.intersection_update(setB)
print(setA)
print("76\n")

setA = {1, 2, 3, 4, 5, 6, 7, 8, 9}
setB = {1, 2, 3, 10, 11, 12}

setA.difference_update(setB)
print(setA)
print("83\n")

setA = {1, 2, 3, 4, 5, 6, 7, 8, 9}
setB = {1, 2, 3, 10, 11, 12}

setA.symmetric_difference_update(setB)
print(setA)
print("90\n")

setA = {1, 2, 3, 4, 5, 6}
setB = {1, 2, 3}
setC = {7, 8, 9}

print(setA.issubset(setB))
print(setB.issubset(setA))
print("98\n")

print(setA.issuperset(setB))
print(setB.issuperset(setA))
print("102\n")

print(setA.isdisjoint(setB))
print(setB.isdisjoint(setA))
print(setA.isdisjoint(setC))
print("107\n")

setB = setA
setB.add(7)
print(setB)
print(setA)

setB = setA.copy()
setB.add(7)
print(setB)
print(setA)

setB = set(setA)
setB.add(7)
print(setB)
print(setA)

# Frozenset eh uma versao imutavel de um set normal

a = frozenset([1, 2, 3, 4])

