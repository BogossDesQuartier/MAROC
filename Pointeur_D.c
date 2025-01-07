#include <stdio.h>
                                       
void addition(int a, int b, int *resultat) {
    *resultat = a + b;
}
void soustraction(int a, int b, int *resultat) {
    *resultat = a - b;
}
void multiplication(int a, int b, int *resultat) {
    *resultat = a * b;
}
void division(int a, int b, int *resultat) {
    if (b!= 0) {
        *resultat = a / b;
    } else {
        printf("Erreur : Division par zéro.\n");
    }
}
int main() {
    int i;
    int n;
    int resultat = 0;

    printf("Entrez un nombre : ");
    scanf("%d", &i);
    printf("Entrez un autre nombre : ");
    scanf("%d", &n);

    addition(i, n, &resultat);

    printf("La somme des nombres est : %d\n",resultat);

    soustraction(i, n, &resultat);
    printf("La différence des nombres est : %d\n", resultat);

    multiplication(i, n, &resultat);
    printf("Le produit des nombres est : %d\n", resultat);

    division(i, n, &resultat);
    printf("Le quotient des nombres est : %d\n", resultat);

    return 0;
}
