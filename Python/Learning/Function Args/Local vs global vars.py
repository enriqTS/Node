def foo():
    global number
    x = number
    number = 3
    print('number is this function', x)

def foo2():
    number = 3

number = 0
foo()
print(number)


