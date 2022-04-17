result = 5 * 3
print(result)

result = 2 ** 3
print(result)

zeros = [0] * 10
print(zeros)

zeros = [0, 1] * 10
print(zeros)

zeros = (0) * 10
print(zeros)

strs = "AB" * 10
print(strs)

def foo(a, b, *args, **kwargs):
    print(a)
    for arg in args:
        print(arg)
    for key in kwargs:
        print(key, kwargs[key])

foo(1, 2, 3, 4, 5, six=6, seven=7)   
# Function Args/Func.py tem mais algumas coisas

numbers = [1, 2, 3, 4, 5, 6]

*beginning, last = numbers # Sempre retorna uma lista
print(beginning)
print(last)

beginning, *last = numbers # Sempre retorna uma lista
print(beginning)
print(last)

beginning, *middle, last = numbers # Sempre retorna uma lista
print(beginning)
print(last)

beginning, *middle, secondlast, last = numbers # Sempre retorna uma lista
print(beginning)
print(last)

my_tuple = (1, 2, 3)
my_list = [4, 5, 6]
my_set = {7, 8, 9}

new_list = [*my_tuple, *my_list, *my_set]
print(new_list)

dict_a = {'a': 1, 'b': 2}
dict_b = {'c': 3, 'd': 4}
my_dict = {**dict_a, **dict_b}
print(my_dict)