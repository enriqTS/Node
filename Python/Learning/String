# Strings sao imutaveis
from timeit import default_timer as timer

mystr = 'I\'m a programmer'
print(mystr)
print("")

mystr = """Hello
World"""
print(mystr)
print("")

mystr = """Hello \
World"""
print(mystr)
print("")

mystr = "Hello World"
char = mystr[-2]
print(char)
print("")

substring = mystr[1:5]
print(substring)
print("")

substring = mystr[:2]
print(substring)
print("")

substring = mystr[::2]
print(substring)
print("")

substring = mystr[::-1]
print(substring)
print("")

greeting = "Hello"
name = "Name"

sentence = greeting + "" + name
print(sentence)
print("")

for i in greeting:
    print(i)
print("")

if 'e' in greeting:
    print("Yes")
else:
    print("No")
print("")    

my_string = '     Hello World'
print(my_string)
print("")

my_string = my_string.strip()
print(my_string)
print("")

my_string = "Hello World"
print(my_string.upper())
print(my_string.lower())
print(my_string.startswith('H'))
print(my_string.endswith('World'))
print(my_string.find('o')) # Retorna o primeiro indice com essa letra, se nao achar retorna -1
print(my_string.count('l'))
print(my_string.replace('World', 'Universe'))

my_string = 'how are you doing'
my_list = my_string.split()
print(my_list)
print("")
new_string = ''.join(my_list)
print(new_string)
print("")

my_list = ['a'] * 6
print(my_list)
print("")

#bad
start = timer()
my_string = ''
for i in my_list:
    my_string += i
stop = timer()
print(stop-start)    
print(my_string)
print("")

#good
start = timer()
my_string = ''.join(my_list)
stop = timer()
print(stop-start)
print(my_string)
print("")

var = "Tom"
my_str = "the variable is %s" % var
print(my_str)
print("")

var = 3
my_str = "the variable is %d" % var
print(my_str)
print("")

var = 3.1232141
my_str = "the variable is %2f" % var
print(my_str)
print("")

var = 3.1134124
my_str = "the variable is {:.2f}".format(var)
print(my_str)
print("")

var = 3.412353215
var2 = 6
my_str = f"the variable is {var*2} and {var2}"
print(my_str)