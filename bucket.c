#include <stdio.h>

void Bucket_Sort(int array[], int n)
{
    int i, j;
    int count[n];

    for (i = 0; i < n; i++){
        count[i] = 0;
    }

    for (i = 0; i < n; i++){
        (count[array[i]])++;
    }

    for (i = 0, j = 0; i < n; i++){
        for(; count[i] > 0; (count[i])--){
            array[j++] = i;
        }
    }
}

int main()
{
    int array[1000001], i, num;

    printf("Entre o Tamanho do Vetor: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++){
        array[i] = i ; // modifique aqui pra algum rand() ou outra coisa para fazewr o teste. o I ali é só pra ter algo
    }

    Bucket_Sort(array, num);
    return 0;
}
