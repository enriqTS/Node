from itertools import product
from itertools import permutations
from itertools import combinations
from itertools import combinations_with_replacement
from itertools import accumulate
import operator
from itertools import groupby
from itertools import count, cycle, repeat

a = [1, 2]
b = [3, 4]
prod = product(a, b)
print(list(prod))
print("7\n")

a = [1, 2]
b = [3]
prod = product(a,b, repeat=2)
print(list(prod))
print("11\n")

a = [1, 2, 3]
perm = permutations(a)
print(list(perm))
print("\n")

perm = permutations(a, 2)
print(list(perm))
print("23\n")

a = [1, 2, 3, 4]
comb = combinations(a, 2)
print(list(comb))
print("29\n")

comb_wr = combinations_with_replacement(a, 2)
print(list(comb_wr))
print("34\n")

a = [1, 2, 3, 4]
acc = accumulate(a)
print(a)
print(list(acc))
print("41\n")

acc = accumulate(a, func=operator.mul)
print(a)
print(list(acc))
print("47\n")

acc = accumulate(a, func=max)
print(a)
print(list(acc))
print("52\n")

# Tambem pode ser feito com uma funcao lambda, mas isso eh cena do proximo capitulo
def smaller_than_3(x):
    return x < 3

a = [1, 2, 3, 4]
group_obj = groupby(a, key=smaller_than_3)
print(group_obj)
for key,value in group_obj:
    print(key, list(value))
print("63\n")    

persons = [{'name': 'Tim', 'age': 25}, {'name': 'Dan', 'age': 25},
           {'name': 'Lisa', 'age': 27}, {'name': 'Claire', 'age': 28}]

group_obj = groupby(persons, key=lambda x: x['age'])
for key, value in group_obj:
    print(key, list(value))
print("73\n")

for i in count(10):
    print(i)
    if i == 12:
        break 
print("79\n")    

#loop infinito
#a = [1, 2, 3]  
#for i in cycle(a):
#    print(i)

a = [1,2,3]
for i in repeat(1, 4):
    print(i)
print("89\n")
