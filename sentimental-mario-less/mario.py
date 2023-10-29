# TODO

import sys

if len(sys.argv) != 2:
    print("Invalid Usage")
    sys.exit(1)

while True:
    height = int(sys.argv[1])
    if height >= 1 and height <= 8:
        break
    else:
        print("Please write correct height between 1 and 8!")


for i in range(height):
    for j in range(height):
        if i + j < height - 1:
            print(" ", end="")
        else:
            print("#", end="")
    print()
