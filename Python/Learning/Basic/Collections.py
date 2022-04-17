from collections import Counter
from collections import namedtuple
from collections import OrderedDict
from collections import defaultdict
from collections import deque

a = "aaaaaaaaabbbbbbbcccc"
mycounter = Counter(a)
print(mycounter)
print("6\n")

print(mycounter.items())
print("9\n")

print(mycounter.keys())
print("12\n")

print(mycounter.values())
print("15\n")

print(mycounter.most_common(1))
print("18\n")

print(mycounter.most_common(1)[0][0])
print("21\n")

print(list(mycounter.elements()))
print("24\n")

Point = namedtuple('Point', 'x, y')
pt = Point(1, -4)
print(pt)
print("30\n")

print(pt.x, pt.y)
print("33\n")

Ordered_dict = OrderedDict() # A partir do python 3.7 um dicionario normal ja salva a ordem sozinho, mas existe isso ai
Ordered_dict['b'] = 2
Ordered_dict['c'] = 3
Ordered_dict['d'] = 4
Ordered_dict['a'] = 1
print(Ordered_dict)
print("42\n")

#d = defaultdict(int) # Deu erro em tudo aq n sei pq
#d[1] = 1
#d[2] = 2
#print(d[1])
#print(d[2])
#print(d[3])
#print("51\n")

#d = defaultdict(float)
#a[1] = 1
#d[2] = 2
#print(d[1])
#print(d[2])
#print(d[3])
#print("59\n")

#d = defaultdict(list)
#d[1] = 1
#d[2] = 2
#print(d[3])
#print("67\n")

d = deque()
# Todos os .clear .pop .popleft funciona
d.append(1)
d.append(2)
print(d)
print("73\n")

d.appendleft(3)
print(d)
print("77\n")

d.extend([4, 5, 6])
print(d)
print("81\n")

d.rotate(1)
print(d)
print("85\n") #Para rotacionar pela esquera tem que colocar numero negativo d.rotate(-1)

