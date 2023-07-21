#include <stdio.h>
#include <cs50.h>

void print_grind(int n);

int main(void){
    //Size of brick wall
    int size = 0;
    size = get_int("Size: ");
    print_grid(size);

}

void print_grid(int n) {

    for (int i=0; i<size; i++)
     {
        for (int j=0; j<size; j++){
        printf("o");
       }
        printf("\n");
    }

}