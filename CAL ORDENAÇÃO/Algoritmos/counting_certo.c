#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void counting_sort_mm(int *array, int n, int min, int max)
{
  int i, j, z;
 
  int range = max - min + 1;
  int *count = malloc(range * sizeof(*array));
 
  for(i = 0; i < range; i++) count[i] = 0;
  for(i = 0; i < n; i++) count[ array[i] - min ]++;
 
  for(i = min, z = 0; i <= max; i++) {
    for(j = 0; j < count[i - min]; j++) {
      array[z++] = i;
    }
  } 
 
  free(count);
}
 
void counting_sort(int *array, int n)
{
  int i, min, max;
 
  min = max = array[0];
  for(i=1; i < n; i++) {
    if ( array[i] < min ) {
      min = array[i];
    } else if ( array[i] > max ) {
      max = array[i];
    }
  }
}
int main ()
{
    int vet[1000001];
    int i, j, tmp,n,r, k, l;
    int vet_tam[]={25000, 50000, 75000, 100000,1000000};
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

            /*
            mas com um elemento 100.000.000 (em qualquer posição).
            */
            r = rand()%n;
            vet[r] = 100000000;
            /*
            mostra(vet, n);
            */
            
            ti = clock();
            printf("\tOrdenando...\n\t\tt_inicial: %f\n", (float)ti/CLOCKS_PER_SEC);
			counting_sort(vet,n);
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
