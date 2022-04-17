mylist = [5, True, "apple", "apple", "banana"]
print(mylist)

item = mylist[0]
print(item)

print(mylist[-1])

for x in mylist:
    print(x)

if "banana" in mylist:
    print("yes")
else:
    print("no")

print(len(mylist))

mylist.append("lemon")
print(mylist)

mylist.insert(1, " blueberry")
print(mylist)

item = mylist.pop()
print(mylist)

item = mylist.remove("apple")
print(mylist)

item = mylist.reverse()
print(mylist)

#item = mylist.sort() 
#print(mylist)
#Organiza a lista(Funciona com numeros)

#new_list = sorted(mylist)
#print(new_list)

new_list = [0] *  5
print(new_list)

mylist2 = [1, 2, 3, 4]

new_list = mylist + mylist2
print(new_list)

mylist2 = [1, 2, 3, 4, 5, 6, 7, 8, 9]
a = mylist2[1:5] #"corta" a lista em partes, varias maneiras de usar
print(a)

list_org = ["banana", "cherry", "apple"]
list_cpy = list_org
list_cpy.append("lemon")
print(list_cpy)
print(list_org)
# Esse codigo copia uma lista a outra, porem as duas sao modificadas por "ocuparem o mesmo espaco na memoria"
# para copiar sem modifcar outra usar list_cpy = list_org.copy(), ou list_cpy = list(list_org), ou list_cpy = list_org[:]

mylist = [1, 2, 3, 4, 5, 6]
b = [i*i for i in mylist]
print(mylist)
print(b)
