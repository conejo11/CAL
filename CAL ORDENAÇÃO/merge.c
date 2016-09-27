#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void mergeSort(int vet[], int vetsize);
void merge(int vet[], int vetsize);

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
    mergeSort(vet,n);
    /*
    printf("\n");
    for (i = 0; i < n; i++){
        printf("%d",vet[i]);
    }
    */
    return 0;
}

/*
    o pai de um índice  f  é  f/2  
    o filho esquerdo de um índice  p  é  2p
    o filho direito de  p  é  2p+1  
    o índice 1 é a raiz da árvore. 

*/
void merge(int vet[], int vetsize) {
  int md;
  int i, j, k;
  int* tmp;

  tmp = (int*) malloc(vetsize * sizeof(int));
  if (tmp == NULL) {
    exit(1);
  }

  md = vetsize / 2;
  i = 0;
  j = md;
  k = 0;
  while (i < md && j < vetsize) {
    if (vet[i] <= vet[j]) {
      tmp[k] = vet[i++];
    }
    else {
      tmp[k] = vet[j++];
    }
    ++k;
  }

  if (i == md) {
    while (j < vetsize) {
      tmp[k++] = vet[j++];
    }
  }
  else {
    while (i < md) {
      tmp[k++] = vet[i++];

    }
  }

  for (i = 0; i < vetsize; ++i) {
    vet[i] = tmp[i];
  }

  free(tmp);
}

void mergeSort(int vet[], int vetsize) {
  int md;

  if (vetsize > 1) {
    md = vetsize / 2;
    mergeSort(vet, md);
    mergeSort(vet + md, vetsize - md);
    merge(vet, vetsize);
  }
}
