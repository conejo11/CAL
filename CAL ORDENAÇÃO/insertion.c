//cc -o insertionsort insertionsort.c
#include <stdio.h>
#include <stdlib.h>
void insertionsort (int *number, int tam);

int main ()
{
    int vet[1000001];
    int i, r, n;
    printf ("Entre com o tamanho do vet\n");
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        r = rand()%n;
        vet[i] = r;
    }
    /*
    for (i = 0; i < n; i++){
        printf("%d",vet[i]);
    }
    */
    insertionsort(vet,n);
    /*
    printf("\n");
    for (i = 0; i < n; i++){
        printf("%d",vet[i]);
    }
    */
    return 0;
}
/*
 ele percorre um vetor de elementos da esquerda para a direita e à medida que avança vai deixando os elementos mais à esquerda ordenados
*/
void insertionsort(int *number,int tam){
    int i,j,top;
    int chosen=0;
    for(i=1;i<tam; i++){
        chosen = number[i];
        j=i-1;
        while((j>=0)&&(chosen<number[j])){
            number[j+1]=number[j];
            j--;
        }
        number[j+1]=chosen;
    }
}
