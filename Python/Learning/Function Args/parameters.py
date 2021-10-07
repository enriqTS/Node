def foo(a_list):
    a_list.append(4)

my_list = [1, 2, 3]
foo(my_list)
print(my_list)

def foo2(a_list2):
    a_list2 = [200, 300, 400]
    a_list2.append(4)
    a_list2[0] = -100

my_list2 = [1, 2, 3]
foo2(my_list2)
print(my_list2)