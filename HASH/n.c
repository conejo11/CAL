//cc -o in n.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define clearbuffer  while(getchar()!='\n');
#define constt 100000
//
typedef struct hash_temp{
    char *name;
	char *something;
	int phone;
    int number;
    struct  hash_temp *prox;
} *hash_s;

hash_s empty_list(){
    hash_s aux=(hash_s)malloc(sizeof(struct hash_temp));
    aux->prox=NULL;
    return aux;
}

hash_s start_list(hash_s head){
    return head->prox;
}

hash_s next_s(hash_s list){
    return list->prox;
}

hash_s end_list (hash_s head){
	while (head->prox != NULL)
		head = next_s (head);
	return head;
}

hash_s walks_s(hash_s head,int position){
    int i;
    for (i=0;i<position;i++){
        head=next_s(head);
    }
    return head;
}

/*
hash_s insert_next(hash_s list ,char *string1,char *string2,int num){
	int i;
	hash_s new = (hash_s)malloc(sizeof(struct hash_temp));

	new->prox = next_s(list);
	new->name = (char*) malloc (sizeof(char) * strlen(string1));
	new->something = (char*) malloc (sizeof(char) * strlen(string2));

    strcpy(new->name,string1);
    strcpy(new->something,string2);
	new->phone=num;
    new->number=1;
    list->prox=new;
}
*/
/*
strlen retorna o tamanho, em caracteres, de uma string dada. Na verdade o strlen() procura o terminador de string e calcula a distância dele ao início da string

char nome[15] = "Maria da Silva";
int s = strlen (nome);
// s conterá o valor 14

*/
int hash_position(const char *string, int tam) {
	int i, position = 0;
	for (i = 0; string[i]!='\0'; i++) {
		position += (int)string[i];
	}
	//printf("%d",position % tam);
	return position % tam;
	//return position;
}


hash_s find(char *string, hash_s head){
	while ((head = next_s(head)) != NULL){
		if (! (strcmp (head->name , string)))
			return head;
	}
	return 0;
}

void print_file(int n,hash_s head,FILE *fdp){
	while((head=next_s(head))!=NULL){
		if (head->number){
			fprintf(fdp,"\n count:%d\n name:%s\n something:%s\n phone:%d\n",n,head->name , head->something, head->phone);
			fprintf(fdp,"\n-----------------------------------------------------------\n");
		}
	}
}

void print_all(hash_s head,FILE *fdp){
	while((head=next_s(head))!=NULL){
		if (head->number){
			printf("\n name:%s\n something:%s\n phone:%d\n",head->name , head->something, head->phone);
			printf("\n-----------------------------------------------------------\n");
		}
	}
}


void find_print(char *string, hash_s head){
	while (strcmp(head->name, string) == 0){
//	printf("nothing\n");
//		if (strcmp (head->name,string) == string){
		if(strcmp(head->name, string) == 0){
			printf("\n name:%s\n something:%s\n phone:%d\n",head->name , head->something, head->phone);
			break;
		}
	}
	//printf("nothing\n");
}

void remove_s(char *string, hash_s head){
	while (strcmp(head->name, string) == 0){
//	printf("nothing\n");
//		if (strcmp (head->name,string) == string){
		if(strcmp(head->name, string) == 0){
			free(head->name);
			free(head->something);
			//free(head->phone);
			break;
		}
	}
	//printf("nothing\n");
}

//            int key = rand() % (int) (sizeof charset - 1);
//            str[n] = charset[key];


char *rand_string(){
	srand(time(NULL));
	int i;
	char *str = (char*) malloc (sizeof(char)*7);
	for(i=0;i<7;i++){
	        //rand char
		str[i] = rand()%26 + 65;
	}
        str[i] = '\0';
        	   //   printf("%s",str);
	return str;
}

int main (){

	//let's go do some shit
	int i,numb, aux = 0;
	int n=1000;
	char string1[55];
	char string2[55];
	int x=0;
	FILE *fdpi;
	hash_s *vet;
	char coisa;
        srand(time(NULL));
	//alloc vet
	vet = (hash_s*)malloc(sizeof (hash_s)*n);

	//Cria listas vazias nas posicoes da tabela
	for (i=0;i<n;i++){
		vet[i]=empty_list();
	}

//        rand_string();



		while(1){
		printf("\n----------------------------------\n");
		printf("\n----------------------------------\n");
		printf("\n--------------HASH----------------\n");
		printf("\n----------------------------------\n");
		printf("\n----------------------------------\n");
		printf("Consulta pelo nome [1],\nremover [2],\ninsertion [3],\nleave [4],\nrandss [5]\n");
		printf("\n----------------------------------\n");
		scanf("%d",&x);
		if(x==1){
				clearbuffer;
				aux=0;
				while(scanf("%c",&coisa) && coisa != '\n' && coisa != '0'){
				        string1[aux++] = coisa;
				}
				string1[aux] = '\0';
				aux=0;
//				printf("%s",string1);
				find_print(string1,end_list (vet[hash_position (string1, n)]));
		}
		if(x==2){
				clearbuffer;
				aux=0;
				while(scanf("%c",&coisa) && coisa != '\n' && coisa != '0'){
				        string1[aux++] = coisa;
				}
				string1[aux] = '\0';
				aux=0;
//				printf("%s",string1);
				remove_s(string1,end_list (vet[hash_position (string1, n)]));
		}
		if(x==3){
		clearbuffer;
			aux=0;
			printf("Nome usuario, registro key\n");
		    while(scanf("%c",&coisa) && coisa != '\n'&& coisa != '0' ){
		            string1[aux++] = coisa;
			}
		    string1[aux] = '\0';
			aux=0;

			printf("Endereco\n");
		    while(scanf("%c",&coisa) && coisa != '\n' ){
		            string2[aux++] = coisa;
			}
		    string2[aux] = '\0';
			aux=0;

			printf("Telefone\n");
			scanf("%d",&numb);

			insert_next (end_list (vet[hash_position (string1, n)]), string1 , string2,numb);
		}
		if(x==4){
			puts("bye");
			break;
		}
		if(x==5){
	                for(i=0;i<=constt;i++){
                        insert_next (end_list (vet[hash_position (rand_string(), n)]), rand_string() , rand_string(),rand()%n);
	                }

	                fdpi=fopen ("hash_trash","w");

	                //file list out
	                for(i=0;i<constt;i++){
		                print_file(i,vet[i],fdpi);
	                }
	                fclose(fdpi);
	                break;
		}
		}//end while



/*
	for(i=0;i<n;i++){
		print_all(vet[i],fdp);
	}

*/
	return 0;
}
