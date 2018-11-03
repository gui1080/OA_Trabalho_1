#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "headers.h"

/*
Feito por:
Guilherme Braga Pinto
Gabriel Matheus da Rocha de Oliveira
Last Update: xx/xx/2018
UnB
*/

struct elemento{
    struct elemento *ant;
    struct dados pessoas;
    struct elemento *prox;
  };
typedef struct elemento Elem;

Lista* cria_lista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	}
	return li;
}

void libera_lista(Lista* li){
	if(li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
	}
}

int insere_lista_final(Lista *li, struct dados pessoas){
	if(li == NULL){
		return 0;
	}
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->pessoas = pessoas;
	no->prox = NULL;
	if((*li) == NULL){
		no->ant = NULL;
		*li = no;
	}else{
		Elem *aux = *li;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
		no->ant = aux;
	}
	return 1;
}

int remove_lista(Lista *li, int mat){
	if(li == NULL){
		return 0;
	}
	Elem *no = *li;
	//mudar aqui
	while(no != NULL && no->pessoas.OP){
		no = no->prox;
	}
	if(no == NULL){
		return 0;
	}
	if(no->ant == NULL){
		*li = no->prox;
	}else{
		no->ant->prox = no->prox;
	}
	if(no->prox != NULL){
		no->prox->ant = no->ant;
	}
	free(no);
	return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct dados *pessoas){
	if(li == NULL || pos <= 0){
		return 0;
	}
	Elem *no = *li;
	int i = 1;
	while(no != NULL && i < pos){
		no = no->prox;
		i++;
	}
	if(no == NULL){
		return 0;
	}else{
		*pessoas = no->pessoas;
	}
	return 1;
}

/*
int counter(FILE *fp) {
  int c = 0, numCod = 1, cont = 0;

  char texto[(sizeof(fp) * 1024)];
//--------------------------------------------------
  if(fp !=NULL){        // se conseguimos abrir o arquivo
      do{
        c = fgetc(fp);    //pegamos sempre o seguinte simbolo
        if(c=='\n'){   //se chegamos no final da linha
          numCod++;     //atualizamos o numero de linhas
        }
        texto[cont] = c;  //armazenamos o texto
        cont++;      // contamos o processo
      }while(c!= EOF);
  }else {
    printf("Impossivel abrir o arquivo\n");  // erro!
  }
  return numCod;
}
*/

/*
int heap_sort(char *vetor, int tamanho){
   
   int pai_direita, pai_esquerda, aux, contador;

   
   for(contador = tamanho-1;  contador >= 0;  contador-- ){
      
      //descobrindo o a raiz de cada galho
      pai_direita  = (contador / 2) - 1;
      pai_esquerda = (contador - 2) / 2;
      
      //trocando caso a raiz seja manor que o galho da direita
       if(vetor[contador] > vetor[pai_direita]){
         
         aux = vetor[contador];
         vetor[contador] = vetor[pai_direita];
         vetor[pai_direita] = aux;         
         
      }
      
      //trocando caso a raiz seja menor que o galhp da esquerda
      else if (vetor[contador-1] > vetor[pai_esquerda] ){

         aux = vetor[contador-1];
         vetor[contador-1] = vetor[pai_esquerda];
         vetor[pai_esquerda] = aux;
         
      }

   }
}
*/

void heapSort(char *strs[], int array_size)
{
  int i;
  char *temp[1];
  
  for (i = (array_size / 2); i >= 0; i--)
    siftDown(strs, i, array_size - 1);
  
  for (i = array_size-1; i >= 1; i--)
  {
    temp[0] = strs[0];
    strs[0] = strs[i];
    strs[i] = temp[0];
    siftDown(strs, 0, i-1);
  }
}
  
  
void siftDown(char *strs[], int root, int bottom)
{
  int done, maxChild;
  char *temp[1];
  
  done = 0;
  while ((root*2 <= bottom) && (!done))
  {
    if (root*2 == bottom)
      maxChild = root * 2;
    else if (strcmp(strs[root * 2], strs[root * 2 + 1]) > 0)
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
  
    if (strcmp(strs[root], strs[maxChild]) < 0)
    {
      temp[0] = strs[root];
      strs[root] = strs[maxChild];
      strs[maxChild] = temp[0];
      root = maxChild;
    }
    else
      done = 1;
  }
}

int tamanho(Lista *li){
	if(li == NULL){
		return 0;
	}
	int cont = 0;
	Elem* no = *li;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}


int Proximo(Lista *li, int pos){
	int result;
	if(li == NULL){
		return 0;
	}
	int aux = 1;
	Elem *no = *li;
	while(no != NULL && aux < pos){
		no = no->prox;
		aux++;
	}
	if(no->prox == NULL){
		result = no->pessoas.Adress;
		return result;
	}
		no = no->prox;
		result = no->pessoas.Adress;
	
	return result;
}

int Anterior(Lista *li, int pos){
	int result;
	if(li == NULL){
		return 0;
	}
	int aux = 1;
	Elem *no = *li;
	while(no != NULL && aux < pos){
		no = no->prox;
		aux++;
	}
	if(no->ant == NULL){
		result = no->pessoas.Adress;
		return result;
	}
		no = no->ant;
		result = no->pessoas.Adress;
	
	return result;
}

void insertionSort(int *arr, size_t size)
{
    for (int i = 1; i < size; i++)
    {
        int value = arr[i];
        int j;
        /* Shift elements over by one slot to make way for the insertion */
        for (j = i; j > 0 && value < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = value;
    }
}