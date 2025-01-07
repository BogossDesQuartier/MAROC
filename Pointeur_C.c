#include <stdio.h>

void pointeur12(int*********nbr){
    *********nbr = 12;
}

int main() {
    int val = 0;
    int *p1 = &val;
    int **p2 = &p1;
    int ***p3 = &p2;
    int ****p4 = &p3;
    int *****p5 = &p4;
    int ******p6 = &p5;
    int *******p7 = &p6;
    int ********p8 = &p7;

    pointeur12(&p8);
    printf(" Valeur : %d\n", val);
    printf(" Modification tp GITHUB");
    printf("Nouvelle modife");
}
