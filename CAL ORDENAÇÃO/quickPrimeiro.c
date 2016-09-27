#include <stdlib.h>
#include <stdio.h>

void quickSort (int *a, int n);
void swap(int *a, int *b);

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
    quickSort(vet,n);
    /*
    printf("\n");
    for (i = 0; i < n; i++){
        printf("%d",vet[i]);
    }
    */
    return 0;
}

/*
    Escolha um elemento da lista, denominado pivô;
    Rearranje a lista de forma que todos os elementos anteriores ao pivô sejam menores que ele, e todos os elementos posteriores ao pivô sejam maiores que ele. Ao fim do processo o pivô estará em sua posição final e haverá duas sublistas não ordenadas. Essa operação é denominada partição;
    Recursivamente ordene a sublista dos elementos menores e a sublista dos elementos maiores
*/
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort (int *a, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[1];//escolha do pivo
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)//enquanto pivo for maior
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
		swap(&a[i], &a[j]);//troca pos
    }
    quickSort(a, i);//sublista dos elementos menores
    quickSort(a + i, n - i);//sublista dos elementos maiores
}