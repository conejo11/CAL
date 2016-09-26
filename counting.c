#include <stdio.h>
#include <stdlib.h>

/*
void printArray(int * array, int size){

  int curr;
  for(curr = 0; curr < size; curr++){
    printf("%d, ", array[curr]);
  }
  printf("\n");
}
*/
int max(int * array, int size){

  int curr = 0;
  int max = 0;

  for(curr = 0; curr < size; curr++){
    if(array[curr] > max){ max = array[curr]; }
  }

  return max;
}

void countingSort(int * array, int size){

  int curr = 0;
  int max = max(array, size);
  int * counting_array = calloc(max, sizeof(int));

  for(curr = 0; curr < size; curr ++){
    counting_array[array[curr]]++;
  }

  int num = 0;
  curr = 0;

  while(curr <= size){
    while(counting_array[num] > 0){
      array[curr] = num;
      counting_array[num]--;
      curr++;
      if(curr > size){ break; }
    }
    num++;
  }
  //printArray(array, size);
}

int main(){

  int mat[1000001];
  int size1,i;
  printf("Entre o Tamanho do Vetor: ");
  scanf("%d", &size1);

  for (i = 0; i < size1; i++){
      mat[i] = i ; // modifique aqui pra algum rand() ou outra coisa para fazewr o teste. o I ali é só pra ter algo
  }

  countingSort(mat, size1);
  return 0;
}
