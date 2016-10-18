#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct vetor{
  int order;
  char *name;
	char *sobrename;
} *vet;
*/

int main (){
int i = 0,j = 0,n;
scanf("%d", &n);
char vet[n];
while((scanf("%s",&vet[i])) != EOF || i == (n-1) ){
  i++;
}
for(i=0;i<n;i++){
  printf("%s",vet);
}

return 0;
}


int pesqbin(int *v, int p, int r, int e){
int q;
if( r < p )
  return -1;
q = (p + r)/2;
if(e == v[q])
  return q;
if(e < v[q])
  return pesqbin(v, p, q-1, e);
return pesqbin(v, q+1, r, e);
}
