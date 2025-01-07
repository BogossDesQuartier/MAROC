#include <stdio.h>

void ajouter(int*a){
    *a+= 10;
}
int main(){
    int a;
    printf("Entrée votre age :\n");
    scanf("%d",&a);
    printf("Avant modification : %d\n",a);
    ajouter(&a);
    printf("After Modification : %d\n",a);
}