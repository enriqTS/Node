import sys

mygenerator = (i for i in range(10) if i % 2 == 0)
for i in mygenerator:
    print(i)

mylist = [i for i in range(10) if i % 2 == 0]
print(mylist)

mygenerator = (i for i in range(10) if i % 2 == 0)
print(list(mygenerator))

mygenerator = (i for i in range(100000) if i % 2 == 0)
print(sys.getsizeof(mygenerator))

mylist = [i for i in range(100000) if i % 2 == 0]
print(sys.getsizeof(mylist))