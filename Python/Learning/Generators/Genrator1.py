# O valor depois de usado eh apagado da existencia

def mygenerator():
    yield 3
    yield 2
    yield 1

g = mygenerator()

for i in g:
   print(i)  

def mygenerator():
    yield 3
    yield 2
    yield 1 

g = mygenerator()

value = next(g)
print(value)

value = next(g)
print(value)

value = next(g)
print(value)

def mygenerator():
    yield 3
    yield 2
    yield 1

g = mygenerator()    

print(sum(g))

def mygenerator():
    yield 3
    yield 2
    yield 1

g = mygenerator()

print(sorted(g))

def countdown(num):
    print('Starting')
    while num > 0:
        yield num
        num -= 1

cd = countdown(3)
value = next(cd)
print(value)

print(next(cd))

print(next(cd))