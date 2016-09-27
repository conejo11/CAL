#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int vet[1000001];
    int i, j, tmp,n,r;
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
    for (i = n; i > 0; i--){
        for (j = 1; j < i; j++){
            if(vet[j-1] > vet[j]){
                tmp = vet[j-1];
                vet[j-1] = vet[j];
                vet[j] = tmp;
            }
        }
    }
    /*
    printf("\n");
    for (i = 0; i < n; i++){
        printf("%d",vet[i]);
    }
    */
    return 0;
}
