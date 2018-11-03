#include <stdlib.h>
#include <stdio.h>
#include "headers.h"
#include <time.h>

/*
Feito por:
Guilherme Braga Pinto
Gabriel Matheus da Rocha de Oliveira
Last Update: xx/xx/2018
UnB
*/

int main(){

  char matricula_texto1[6];
  //char nome_texto1[18];
  char nome_texto1[30];
  /*
  int op_texto1[18];
  char curso_texto1[18];
  char turma_texto1[18];
  */
/*
  typedef struct dados {
  //int matricula_texto1;
  //char nome_texto1[30];  
  int OP;
  char Curso[2];
  char Turma[2];

  }Dados;
*/
  Lista *li;
  li = cria_lista();

  //Dados pessoas;

  int i = 0;
  int k = 0;
  int indice = 0;
  char linha[65];
  char linha_aux[30];

  FILE *fp;
  fp = fopen ("lista1.txt", "r");

  // provavelmente tem que ler os 2 documentos, né...?

  if (fp == NULL){
    printf("Problemas na leitura da lista1.txt\n");
    return 0;
  }
/*
int cont = 1;
  while(fgets(linha, 65, fp) != NULL){ 
  //fgets(linha,65,fp);
    for(i = 1; i < 7; i++){
    matricula_texto1[i] = linha[i];  
    }  
  printf("%s", linha);
  cont++;
}
  printf("\n");
*/
  fgets(linha, 65, fp);
  for(i = 0; i < 6; i++){
    matricula_texto1[i] = linha[i];  
    } 
    //matricula_texto1[7] = '\0';
printf("%s", linha);
printf("%s \n", matricula_texto1);  
    for(i = 0; i < 30; i++){
    nome_texto1[i] = linha[i+7];  
    } 
   // matricula_texto1[i] = '\0';
printf("%s \n", nome_texto1);  

  fgets(linha, 65, fp);
  for(i = 0; i < 6; i++){
    matricula_texto1[i] = linha[i];  
    } 
    //matricula_texto1[7] = '\0';
printf("%s", linha);
printf("%s \n", matricula_texto1);  
    for(i = 0; i < 30; i++){
    nome_texto1[i] = linha[i+7];  
    } 
   // matricula_texto1[] = '\0';
printf("%s \n", nome_texto1);  

  /*

  for(k = 0; k<19; k++){   //ler todas as linhas...

    for(i = 0; i < 7; i++){
      fscanf(fp, "%d", &matricula_texto1[indice]);
      indice++;
    }
    indice = 0;

    for(i = 0; i < 41; i++){
      fscanf(fp, "%c", &nome_texto1[indice]);
      indice++;
    }
    indice = 0;

    //fazer isso pro resto do arquivo, ai poderemos criar indicelista1.ind e indicelista2.ind

  }

*/
  libera_lista(li);
  fclose(fp);
  return 0;
}