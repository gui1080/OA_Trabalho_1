/**
 * @file headers.h
 *
 * @brief Arquivo com as declarações das funções auxiliares da manipulação das Listas 
 *
 * @author Guilherme Braga e Gabriel Matheus
 *
 */


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

typedef struct elemento * Lista;

//--------------------------------------------------------------------------------------------

/**
 * @brief Cria a Lista.
 * 
 * @param Não há.
 */
Lista* cria_lista();

//--------------------------------------------------------------------------------------------

/**
 * @brief Libera a Lista.
 *
 * @param Lista* li - a Lista que se deseja liberar.
 */
void libera_lista(Lista* li);

//--------------------------------------------------------------------------------------------

/**
 * @brief Insere na Lista.
 *
 * @param Lista* li - a Lista que se deseja adicionar um elemento.
 */
int insere_lista_final(Lista *li, struct dados pessoas);

//--------------------------------------------------------------------------------------------

/**
 * @brief Remove da Lista.
 *
 * @param Lista* li - a Lista que se deseja retirar um elemento.
 */
int remove_lista(Lista *li, char *string);

//--------------------------------------------------------------------------------------------

/**
 * @brief Consulta determinado elemento da Lista.
 *
 * @param Lista* li - a Lista que se deseja liberar.
 */
int consulta_lista_pos(Lista* li, int pos, struct dados *pessoas);

//--------------------------------------------------------------------------------------------

/**
 * @brief Retorna o tamanho da Lista.
 *
 * @param FILE Lista* li - a Lista que se deseja liberar.
 */
int tamanho(Lista *li);

//--------------------------------------------------------------------------------------------

/**
 * @brief Função auxiliar de Heapsort (faz trocas).
 *
 * @param int bottom - Final do "heap".
 *
 * @param int root - Raiz do "heap".
 *
 * @param char *strs[] - String a se organizar.
 */
void siftDown(char *strs[], int root, int bottom);

//--------------------------------------------------------------------------------------------

/**
 * @brief Heapsort em si.
 *
 * @param char *strs[] - String a se organizar.
 *
 * @param int array_size - Tamanho do Array.
 */
void heapSort(char *strs[], int array_size);

//--------------------------------------------------------------------------------------------

/**
 * @brief Retorna o "próximo" de determinado elemento da Lista.
 *
 * @param Lista* li - A Lista que se deseja liberar.
 *
 * @param int pos - Posição de referência na Lista.
 */
int Proximo(Lista *li, int pos);

//--------------------------------------------------------------------------------------------

/**
 * @brief Retorna o "anterior" de determinado elemento da Lista.
 *
 * @param Lista* li - A Lista que se deseja liberar.
 *
 * @param int pos - Posição de referência na Lista.
 */
int Anterior(Lista *li, int pos);

//--------------------------------------------------------------------------------------------

/**
 * @brief Retorna o "anterior" de determinado elemento da Lista.
 *
 * @param int *arr - Array que se quer organizar.
 *
 * @param size_t size - Tamanho do Array que se quer organizar.
 */
void insertionSort(int *arr, size_t size);

//--------------------------------------------------------------------------------------------

int insere_lista_ordenada(Lista *li, struct dados pessoas);

/**
 * @brief Sabe-se a Lista está vazia.
 * 
 * @param Lista* li - A Lista que se deseja obter informações.
 */
int lista_vazia(Lista *li);

//--------------------------------------------------------------------------------------------

/**
 * @brief Retorna o "anterior" de determinado elemento da Lista.
 *
 * @param char *string1 - String a se comparar..
 *
 * @param char *string2 - String a se comparar.
 */
int compara_string(char *string1, char* string2);

//--------------------------------------------------------------------------------------------

/**
 * @brief Escreve no arquivo secundário.
 *
 * @param Lista *lEC - Lista do curso de EC.
 *
 * @param Lista *lEM - Lista do curso de EM.
 *	
 * @param Lista *lCC - Lista do curso de CC.
 *
 * @param int count_total - Linhas totais.
 *
 * @param FILE *Secondary_Index - Indice Secundário.
 *
 * @param FILE *Secondary_Index_List - Lista de indice Secundário.
 */
void Escrever_Arquivos_Secondary(Lista *lEC, Lista *lEM, Lista *lCC, int cont_total, FILE *Secondary_Index, FILE *Secondary_Index_List);

//--------------------------------------------------------------------------------------------

/**
 * @brief Escreve no arquivo primário.
 *
 * @param Lista* li - A Lista que se deseja obter informações.
 *
 * @param int count_total - Linhas totais.
 *
 * @param FILE *Primary_Index - Indice Primário.
 */
void Escrever_Arquivos_Primary(Lista *li, int cont_total, FILE *Primary_Index);

//--------------------------------------------------------------------------------------------

/**
 * @brief Escreve o arquivo primário no terminal.
 *
 * @param Lista* li - A Lista que se deseja obter informações.
 *
 * @param int count_total - Linhas totais.
 *
 */
void Escrever_Terminal_Primary(Lista *li, int cont_total);

//--------------------------------------------------------------------------------------------

/**
 * @brief Escreve o arquivo secundário no terminal.
 *
 * @param Lista *lEC - Lista do curso de EC.
 *
 * @param Lista *lEM - Lista do curso de EM.
 *
 * @param Lista *lCC - Lista do curso de CC.
 *
 * @param int count_total - Linhas totais.
 *
 */
void Escrever_Terminal_Secondary(Lista *lEC, Lista *lEM, Lista *lCC, int cont_total);

//--------------------------------------------------------------------------------------------

/**
 * @brief Copia uma string na Lista.
 *
 * @param Lista* li - A Lista que se deseja obter informações.
 *
 * @param char *string - String de informações auxiliares.
 *
 * @param struct dados *pessoas - Struct representativa de um determinado aluno.
 *
 */
int copy(Lista* li, char *string, struct dados *pessoas);

//--------------------------------------------------------------------------------------------

/**
 * @brief Mostra menus, um atalho de prints.
 * 
 * @param int opt - Descreve qual menu se mostrará.
 */
void Escreve_Menu(int opt);