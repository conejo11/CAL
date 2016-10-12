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

void Bucket_Sort(int array[], int n){
    int i, j;
    int count[n]; // Cria n buckets

    for (i = 0; i < n; i++){
        count[i] = 0; // Inicializa buckets
    }

    for (i = 0; i < n; i++){
        (count[array[i]])++; // Particiona buckets
    }

    for (i = 0, j = 0; i < n; i++){
        for(; count[i] > 0; (count[i])--){
            array[j++] = i; // Concatena buckets
        }
    }
}

int main(){
    int vet[1000001];
    int i, n,r, k, l;
    int vet_tam[]={25000, 50000, 75000, 100000, 1000000};
    float aux;
    clock_t ti, tf;
    
    for(l=0; l<5; l++){
        n = vet_tam[l];
        printf("Tam Vetor: %i\n", n);
        aux=0;
        for(k=0; k<5; k++){
            srand( (unsigned)time(NULL) );

            for (i = 0; i < n; i++){
                r = rand()%n;
                vet[i] = r;
            }
            //mostra(vet, n);
            ti = clock();
            	printf("\tOrdenando...\n\t\tt_inicial: %f\n", (float)ti/CLOCKS_PER_SEC);
            	Bucket_Sort(vet, n);
            tf = clock();
            printf("\t\tt_final: %f", (float)tf/CLOCKS_PER_SEC);
            printf ("\t%iº: %f tempo\n", k+1, ((float)(tf-ti))/CLOCKS_PER_SEC);
            aux = aux+((float)(tf-ti))/CLOCKS_PER_SEC;
            //mostra(vet, n);
        }
        printf("\tMedia: %f\n", aux/5);
    }
    /*
    mostra(vet, n);
    */
    return 0;
}
