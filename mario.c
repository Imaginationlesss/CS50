#include <stdio.h>
#include <cs50.h>



int main(void){
    //Size of brick wall
    const int size = get_int("Size: ");

    for (int i=0; i<size; i++)
     {
        for (int j=0; j<size; j++){
        printf("o");
       }
        printf("\n");
    }
}

void print_grid(int n) {
    
}