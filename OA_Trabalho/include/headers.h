#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Feito por:
Gabriel Matheus da Rocha de Oliveira, 17/0103498
Guilherme Braga Pinto, 17/0162290
Last Update: 03/11/2018
UnB- CIC
*/

//--------------------------------------------------------------------------------------------

typedef struct dados {
  int Adress;
  char chave[31];  
  char OP[3];
  char Curso[3];
  char Turma[2];

  }Dados;

//--------------------------------------------------------------------------------------------  

typedef struct elemento * Lista;

//--------------------------------------------------------------------------------------------

Lista* cria_lista();

//--------------------------------------------------------------------------------------------

void libera_lista(Lista* li);

//--------------------------------------------------------------------------------------------

int insere_lista_final(Lista *li, struct dados pessoas);

//--------------------------------------------------------------------------------------------

int remove_lista(Lista *li, int mat);

//--------------------------------------------------------------------------------------------

int consulta_lista_pos(Lista* li, int pos, struct dados *pessoas);

//--------------------------------------------------------------------------------------------

int tamanho(Lista *li);

//--------------------------------------------------------------------------------------------

void siftDown(char *strs[], int root, int bottom);

//--------------------------------------------------------------------------------------------

void heapSort(char *strs[], int array_size);

//--------------------------------------------------------------------------------------------

int Proximo(Lista *li, int pos);

//--------------------------------------------------------------------------------------------

int Anterior(Lista *li, int pos);

//--------------------------------------------------------------------------------------------

void insertionSort(int *arr, size_t size);

//--------------------------------------------------------------------------------------------