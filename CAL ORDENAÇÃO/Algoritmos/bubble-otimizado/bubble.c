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
    int i, j, tmp,n,r, k, l;
    int vet_tam[]={25000, 50000, 75000, 100000};
    float aux;
    clock_t ti, tf;
    
    for(l=0; l<4; l++){
        n = vet_tam[l];
        printf("Tam Vetor: %i\n", n);
        aux=0;
        for(k=0; k<5; k++){
            srand( (unsigned)time(NULL) );

            for (i = 0; i < n; i++){
                r = rand()%n;
                vet[i] = r;
            }
            /*
            mostra(vet, n);
            */
            
            ti = clock();
            printf("\tOrdenando...\n\t\tt_inicial: %f\n", (float)ti/CLOCKS_PER_SEC);
            for (i = n; i > 0; i--){
                for (j = 1; j < i; j++){
                    if(vet[j-1] > vet[j]){
                        tmp = vet[j-1];
                        vet[j-1] = vet[j];
                        vet[j] = tmp;
                    }
                }
            }
            tf = clock();
            printf("\t\tt_final: %f", (float)tf/CLOCKS_PER_SEC);
            printf ("\t%iº: %f tempo\n", k+1, ((float)(tf-ti))/CLOCKS_PER_SEC);
            aux = aux+((float)(tf-ti))/CLOCKS_PER_SEC;
        }
        printf("\tMedia: %f\n", aux/5);
    }
    /*
    mostra(vet, n);
    */
    return 0;
}
