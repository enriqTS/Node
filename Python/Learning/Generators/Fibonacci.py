def fibonacci(limit):
    a, b = 0, 1
    while a < limit:
        yield a
        a, b = b, a + b

fib = fibonacci(50)
for i in fib:
    print(i)        