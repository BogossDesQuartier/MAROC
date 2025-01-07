#include <stdio.h>

void conversionsecondes(int total_seconde, int *heures, int *minutes, int *secondes) {
    *heures = total_seconde / 3600;
    total_seconde %= 3600;
    *minutes = total_seconde / 60;
    *secondes = total_seconde % 60;
}

int main() {
    int total_seconde;
    printf("Entrez le nombre de secondes : ");
    scanf("%d", &total_seconde);
    int heures, minutes, secondes;

    conversionsecondes(total_seconde, &heures, &minutes, &secondes);

    printf("%d secondes sont egal a  : %d heures ; %d minutes ; %d secondes \n", total_seconde, heures, minutes, secondes);
}