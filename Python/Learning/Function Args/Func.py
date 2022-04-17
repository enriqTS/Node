def foo(a, b, c):
    print(a, b, c)

my_list = [1, 2, 3]
my_tuple = (1, 2, 3)
my_dict = {'a': 1, 'b': 2, 'c': 3}
foo(*my_list)    
foo(*my_tuple)
foo(**my_dict)