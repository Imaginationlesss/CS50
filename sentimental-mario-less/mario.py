# TODO


height = int(input("Height: "))
while(height < 1 or height > 8):
    height = int(input("Height: "))


for i in range(height):
    for j in range(height):
        if (i + j < height - 1):
            print(" ")
        else:
            print("#")
    print()




