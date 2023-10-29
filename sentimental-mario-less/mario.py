# TODO


while True:
    height = int(input("Height: "))
    if height < 0 and height < 9:
        break
    return height


for i in range(height):
    for j in range(height):
        if i + j < height - 1:
            print(" ", end="")
        else:
            print("#", end="")
    print()
