/**
 * @file funcoes.c
 *
 * @brief Arquivo com as funções auxiliares da manipulação das Listas 
 *
 * @author Guilherme Braga e Gabriel Matheus
 *
 */


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

//--------------------------------------------------------------------------------------------

struct elemento{
    struct elemento *ant;
    struct dados pessoas;                      // struct de elementos para a lista
    struct elemento *prox;
  };
typedef struct elemento Elem;

//--------------------------------------------------------------------------------------------

Lista* cria_lista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;        //checa se a lista foi criada com sucesso
	}
	return li;
}

//--------------------------------------------------------------------------------------------

void libera_lista(Lista* li){
	if(li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;            //liberamos todos os nos da lista
			free(no);
		}
		free(li);
	}
}

//--------------------------------------------------------------------------------------------

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
	if((*li) == NULL){               //checamos se a lista já está vazia
		no->ant = NULL;                               
		*li = no;
	}else{ 
		Elem *aux = *li;                      // se não, devemos pesquisar até chegar ao final
		while(aux->prox != NULL){
			aux = aux->prox;                         
		}
		aux->prox = no;
		no->ant = aux;
	}
	return 1;
}

//--------------------------------------------------------------------------------------------

int remove_lista(Lista *li, char *string){
	if(li == NULL){
		return 0;
	}
	int pos = 1;
	Elem *no = *li;
	//mudar aqui
	while(no != NULL && compara_string(no->pessoas.chave, string) != 0){
		no = no->prox;               // pesquisamos o que deve ser retirado
		pos++;
	}
	if(no == NULL){
		return 0;
	}
	if(no->ant == NULL){            // ao se encontramos, atribuimos novos valores aos vizinhos do elemento
		*li = no->prox;              // logo, o retiranodo 
	}else{
		no->ant->prox = no->prox;
	}
	if(no->prox != NULL){
		no->prox->ant = no->ant;
	}
	free(no);
	return pos;
}

//--------------------------------------------------------------------------------------------

int consulta_lista_pos(Lista* li, int pos, struct dados *pessoas){
	if(li == NULL || pos <= 0){
		return 0;
	}
	Elem *no = *li;
	int i = 1;
	while(no != NULL && i < pos){
		no = no->prox;
		i++;                         // vamos até dada posiçao 
	}
	if(no == NULL){
		return 0;
	}else{
		*pessoas = no->pessoas;         // encontramos a informação 
	}
	return 1;
}

//--------------------------------------------------------------------------------------------

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
  
//--------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------

int tamanho(Lista *li){
	if(li == NULL){
		return 0;
	}
	int cont = 0;
	Elem* no = *li;
	while(no != NULL){
		cont++;                      // contamos enquanto não encontramos uma posição nula
		no = no->prox;
	}
	return cont;
}

//--------------------------------------------------------------------------------------------

int Proximo(Lista *li, int pos){
	int result;
	if(li == NULL){
		return 0;
	}
	int aux = 1;
	Elem *no = *li;
	while(no != NULL && aux < pos){              // pesquisamos até chegarmos em dada posição
		no = no->prox;
		aux++;
	}
	if(no->prox == NULL){ 
		result = no->pessoas.Adress;
		return result;                   // com base no endereço, vemos o elemento que vem adiante
	}
		no = no->prox;
		result = no->pessoas.Adress;        // retornamos o endereço encontrado
	
	return result;
}

//--------------------------------------------------------------------------------------------

int Anterior(Lista *li, int pos){
	int result;
	if(li == NULL){
		return 0;
	}
	int aux = 1;
	Elem *no = *li;
	while(no != NULL && aux < pos){
		no = no->prox;
		aux++;                     // pesquisamos até chegarmos em dada posição
	}
	if(no->ant == NULL){
		result = no->pessoas.Adress;              // com base no endereço, vemos o elemento que vem atras
		return result;
	}
		no = no->ant;
		result = no->pessoas.Adress;                 // retornamos o endereço encontrado
	
	return result;
}

//--------------------------------------------------------------------------------------------

void insertionSort(int *arr, size_t size)
{
    for (int i = 1; i < size; i++)
    {
        int value = arr[i];
        int j;
        for (j = i; j > 0 && value < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = value;
    }
}

//--------------------------------------------------------------------------------------------

int insere_lista_ordenada(Lista *li, struct dados registro){
	if(li == NULL){
		return 0;
	}
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;                       // invalido se nulo
	}
	no->pessoas = registro;
	if(lista_vazia(li)){
		no->prox = NULL;
		no->ant = NULL;
		*li = no;              // se lista esta vazia, apenas inserimos
		return 1;
	}
	else{
		Elem *ante, *atual = *li;
		while(atual != NULL && compara_string(atual->pessoas.chave, registro.chave) == 2){
			ante = atual;
			atual = atual->prox;       // se não esta vazia, temos que procurar onde inserir
		}           // este while pesquisa no arquivo até satisfazer a condição de parada
		if(atual == *li){
			no->ant = NULL;
			(*li)->ant = no;
			no->prox = (*li);
			*li = no;
		}else{
			no->prox = ante->prox;
			no->ant = ante;
			ante->prox = no;
			if(atual != NULL){
				atual->ant = no;
			}
		}
	}
return 1;
}

//--------------------------------------------------------------------------------------------

int lista_vazia(Lista *li){
	if(li == NULL){
		return 1;
	}
	if(*li == NULL){                  // verificamos se lista é nula, determinando assim se está vazia 
		return 1; 
	}
	return 0;
}
//--------------------------------------------------------------------------------------------

int compara_string(char *string1, char* string2){
int result;

if (strcmp(string1, string2) == 0){
	return 0;                   //~inválido caso as duas strings sejam iguais
}

for(int i = 0; i < 30; i++){

	if(string1[i] > string2[i]){                  // comparamos  as strings por posição, se são diferentes a função para
		result = 1;                          // para cada caso, há um retorno diferente 
		break;
		//return 1;
	}if(string1[i] < string2[i]){
		result = 2;
		break;
		//return 2;
	}
	
}

return result;
}

void Escrever_Arquivos_Secondary(Lista *lEC, Lista *lEM, Lista *lCC, int cont_total, FILE *Secondary_Index, FILE *Secondary_Index_List){
	int cont_aux = 1;
    int prox;
    int ant;
    int i;
    struct dados pessoas_aux;
    int tam1 = tamanho(lEC);
    consulta_lista_pos(lEC, 1, &pessoas_aux);            // consultamos a posição 
    fprintf(Secondary_Index, "1 Curso: EC Número de itens: %d Endereço do primeiro da lista: %d \n\n", tam1, pessoas_aux.Adress);
    for(i = 0; i < tam1; i++){
      consulta_lista_pos(lEC, i + 1, &pessoas_aux);              // consultamos a posição 
      prox = Proximo(lEC, i + 1);         // definimos os vizinhos para cada posição e printamos
      ant = Anterior(lEC, i + 1);
      fprintf(Secondary_Index_List, "%d %s \t\tEndereço: %d \tAnterior: %d \tProximo: %d \n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress, ant, prox);
      cont_aux++;
    }
    int tam2 = tamanho(lEM);
	consulta_lista_pos(lEM, 1, &pessoas_aux);            // consultamos a posição 
    fprintf(Secondary_Index, "2 Curso: EM Número de itens: %d Endereço do primeiro da lista: %d \n\n", tam2, pessoas_aux.Adress);
    for(i = 0; i < tam2; i++){
      consulta_lista_pos(lEM, i + 1, &pessoas_aux);        // consultamos a posição 
      prox = Proximo(lEM, i + 1);                          // definimos os vizinhos para cada posição e printamos
      ant = Anterior(lEM, i + 1);
      fprintf(Secondary_Index_List, "%d %s \t\tEndereço: %d \tAnterior: %d \tProximo: %d \n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress, ant, prox);
      cont_aux++;
    }
    int tam3 = tamanho(lCC);
	consulta_lista_pos(lCC, 1, &pessoas_aux);         // consultamos a posição 
    fprintf(Secondary_Index, "3 Curso: CC Número de itens: %d Endereço do primeiro da lista: %d \n\n", tam3, pessoas_aux.Adress);
    for(i = 0; i < tam3; i++){
      consulta_lista_pos(lCC, i + 1, &pessoas_aux);        // consultamos a posição 
      prox = Proximo(lCC, i + 1);
      ant = Anterior(lCC, i + 1);            // definimos os vizinhos para cada posição e printamos
      fprintf(Secondary_Index_List, "%d %s \t\tEndereço: %d \tAnterior: %d \tProximo: %d \n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress, ant, prox);
      cont_aux++;
    }
}

void Escrever_Arquivos_Primary(Lista *li, int cont_total, FILE *Primary_Index){

int i;
int cont_aux = 1;
struct dados pessoas_aux;

    for(i = 0; i < cont_total; i++){
      consulta_lista_pos(li, i + 1, &pessoas_aux);     // consultamos a posição 
      fprintf(Primary_Index, "%d %s \t\tEndereço: %d\n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress);      // printamos
      cont_aux++;
    }
}

void Escrever_Terminal_Primary(Lista *li, int cont_total){

int i;
int cont_aux = 1;
struct dados pessoas_aux;

    for(i = 0; i < cont_total; i++){
      consulta_lista_pos(li, i + 1, &pessoas_aux);            // consultamos a posição 
      printf("%d %s \t\tEndereço: %d\n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress);           // printamos
      cont_aux++;
    }
}

void Escrever_Terminal_Secondary(Lista *lEC, Lista *lEM, Lista *lCC, int cont_total){

int cont_aux = 1;
    int prox;
    int ant;
    int i;
    struct dados pessoas_aux;
    int tam1 = tamanho(lEC);
    consulta_lista_pos(lEC, 1, &pessoas_aux);       // consultamos a posição 
    printf("\n\n1 Curso: EC Número de itens: %d Endereço do primeiro da lista: %d \n\n", tam1, pessoas_aux.Adress);
    for(i = 0; i < tam1; i++){
      consulta_lista_pos(lEC, i + 1, &pessoas_aux);
      prox = Proximo(lEC, i + 1);
      ant = Anterior(lEC, i + 1);        // atribuimos valores e printamos
      printf("%d %s \t\tEndereço: %d \tAnterior: %d \tProximo: %d \n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress, ant, prox);
      cont_aux++;
    }
    int tam2 = tamanho(lEM);
    consulta_lista_pos(lEM, 1, &pessoas_aux);
    printf("\n\n2 Curso: EM Número de itens: %d Endereço do primeiro da lista: %d \n\n", tam2, pessoas_aux.Adress);
    for(i = 0; i < tam2; i++){
      consulta_lista_pos(lEM, i + 1, &pessoas_aux);           // consultamos a posição 
      prox = Proximo(lEM, i + 1);
      ant = Anterior(lEM, i + 1);             // atribuimos valores e printamos
      printf("%d %s \t\tEndereço: %d \tAnterior: %d \tProximo: %d \n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress, ant, prox);
      cont_aux++;
    }
    int tam3 = tamanho(lCC);
    consulta_lista_pos(lCC, 1, &pessoas_aux);             // consultamos a posição 
    printf("\n\n3 Curso: CC Número de itens: %d Endereço do primeiro da lista: %d \n\n", tam3, pessoas_aux.Adress);
    for(i = 0; i < tam3; i++){
      consulta_lista_pos(lCC, i + 1, &pessoas_aux);
      prox = Proximo(lCC, i + 1);
      ant = Anterior(lCC, i + 1);                    // atribuimos valores e printamos
      printf("%d %s \t\tEndereço: %d \tAnterior: %d \tProximo: %d \n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress, ant, prox);
      cont_aux++;
    }
    printf("\n\n");
}

int copy(Lista* li, char *string, struct dados *pessoas){
	if(li == NULL){
		return 0;
	}
	Elem *no = *li;
	int i = 1;
	while(no != NULL && compara_string(no->pessoas.chave, string) != 0){
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


void Escreve_Menu(int opt){
	printf("\033[1;34m");
	if(opt == 1){
		printf("\n\n");
  		printf("Lista criada com sucesso!\n");
  		printf("O que deseja fazer agora?\n\n");
	}

	if(opt == 2){
  		printf("1 - Adicionar Registro\n");
  		printf("2 - Excluir Registro\n");
  		printf("3 - Atualizar Registro\n");
  		printf("4 - Salvar e sair do programa\n");
  	}

  	if(opt == 3){
 		printf("Para ler a Lista 1, digite 0\n");
        printf("Para ler a Lista 2, digite 1\n");              // Menus!
        printf("Para intercalar Listas, digite 2\n");
	}
	if(opt == 4){
	  printf("O que deseja modificar?\n");
      printf("1 - Matricula\n");
      printf("2 - Nome\n");
      printf("3 - Opção\n");
      printf("4 - Turma\n");
      printf("5 - Curso\n");
	}
	printf("\033[0m");	
}
