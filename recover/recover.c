#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Incorect usage!\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    fread(buffer, 1, )

}