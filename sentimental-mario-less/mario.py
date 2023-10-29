# TODO


while True:
    height = input("Height: ")
    try:
        height = int(height)
        if height >= 1 and height <= 8:
            break
        else:
            print("Please write correct height between 1 and 8!")
    except ValueError:
        print("Please write correct height between 1 and 8!")


for i in range(height):
    for j in range(height):
        if i + j < height - 1:
            print(" ", end="")
        else:
            print("#", end="")
    print()
