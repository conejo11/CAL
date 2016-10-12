#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quick_sort (int *a, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[1];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quick_sort(a, i);
    quick_sort(a + i, n - i);
}
int main ()
{
    int *vet;
    int i, r, n;
    printf ("Entre com o tamanho do vet\n");
    scanf("%d",&n);
    vet = (int*)malloc(n*sizeof (int));
    for (i = 0; i < n; i++){
        r = i;
        vet[i] = r;
    }
    
    /*
    for (i = 0; i < n; i++){
        printf("%d",vet[i]);
    }
    */
    quick_sort(vet,n);
    /*
    printf("\n");
    for (i = 0; i < n; i++){
        printf("%d",vet[i]);
    }
    */
    return 0;
}
