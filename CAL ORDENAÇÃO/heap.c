#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void heapsort( int *a, int count);

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
    heapsort(vet,n);
    /*
    printf("\n");
    for (i = 0; i < n; i++){
        printf("%d",vet[i]);
    }
    */
    return 0;
}

void heapsort(int a[], int n) {

   int i = n / 2, pai, filho, t;
   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      //Primeiro será feita a comparação com o filho da esquerda.
 
     filho = i * 2 + 1;
      while (filho < n) {
         //Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}
