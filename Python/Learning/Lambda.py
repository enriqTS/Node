add10 = lambda x: x + 10
print(add10(5))
print("3\n")

mult = lambda x,y: x*y
print(mult(2, 7))
print("7\n")

points2D = [(1, 2), (15, 1), (5, -1), (10, 4)]
points2D_sorted = sorted(points2D)
print(points2D)
print(points2D_sorted)
print("13\n")

points2D_sorted = sorted(points2D, key=lambda x: x[1])
print(points2D)
print(points2D_sorted)
print("18\n")

points2D_sorted = sorted(points2D, key=lambda x: x[0] + x[1])
print(points2D)
print(points2D_sorted)
print("23\n")