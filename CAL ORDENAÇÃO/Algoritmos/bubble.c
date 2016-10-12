#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostra(int *v, int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int main ()
{
    int vet[1000001];
    int i, j, tmp,n,r;

    clock_t ti, tf;
    srand(time(NULL));

    printf ("Entre com o tamanho do vet\n");
    scanf("%d",&n);
    srand( (unsigned)time(NULL) );

    for (i = 0; i < n; i++){
        r = rand()%n;
        vet[i] = r;
    }
    
    /*
    mostra(vet, n);
    */
    ti = clock();
    for (i = n; i > 0; i--){
        for (j = 1; j < i; j++){
            if(vet[j-1] > vet[j]){
                tmp = vet[j-1];
                vet[j-1] = vet[j];
                vet[j] = tmp;
            }
        }
    }
    printf ("%f time \n",((float)(ti))/CLOCKS_PER_SEC);
    /*
    mostra(vet, n);
    */
    return 0;
}
