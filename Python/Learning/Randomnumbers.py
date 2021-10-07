import random # Numeros reproduziveis
import secrets # Verdadeiramente aleatorios
import numpy as np

a = random.random()
print(a)
print("5\n")

a = random.uniform(1, 10)
print(a)
print("9\n")

a = random.randint(1, 10)
print(a)
print("13\n")

a = random.randrange(1, 10)
print(a)
print("17\n")

a = random.normalvariate(0, 1)
print(a)
print("21\n")

mylist = list("ABCDEFGH")

a = random.choice(mylist)
print(a)
print("27\n")
a = random.sample(mylist, 3)
print(a)
print("30\n")
a = random.choices(mylist, k=3)
print(a)
print("33\n")
random.shuffle(mylist)
print(mylist)
print("36\n")

random.seed(1)
print(random.random())
print(random.randint(1,10))
random.seed(2)
print(random.random())
print(random.randint(1,10))
random.seed(1)
print(random.random())
print(random.randint(1,10))
random.seed(2)
print(random.random())
print(random.randint(1,10))
print("")

a = secrets.randbelow(10)
print(a)
print("55\n")

a = secrets.randbits(4)
print(a)
print("59\n")

mylist = list("ABCDEFGH")
a = secrets.choice(mylist)
print(a)
print("64\n")

a = np.random.rand(3)
print(a)
print("69\n")

a = np.random.rand(3, 3)
print(a)
print("73\n")

a = np.random.randint(0, 10, (3, 2))
print(a)
print("77\n")

arr = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print(arr)
np.random.shuffle(arr)
print(arr)

np.random.seed(1)
print(np.random.rand(3,3))
np.random.seed(1)
print(np.random.rand(3,3))
