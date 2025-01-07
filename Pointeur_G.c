#include <stdio.h>

int max (int a , int b , int c){

if (a > b && a > c){
    return a;
}else if (b > a && b > c){
    return b;
}else{
    return c;
}
}
int min (int a , int b, int c){
    if (a<b && a<c){
    
        return a;
    }else if (b<a && b<c){
    return b;
    }else{
        return c;
    }    
}

int main (){
    int y , z , w ;

    printf("Entrer un nombre : \n");
    scanf("%d",&y);
    printf("Entrer un deuxieme nombre : \n");
    scanf("%d",&z);
    printf("Entrer un troisieme nombre : \n");
    scanf("%d",&w);

    printf("Le max est : %d\n",max(y,z,w));
    printf("Le min est : %d\n",min(y,z,w));
    
}