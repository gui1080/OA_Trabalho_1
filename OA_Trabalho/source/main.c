#include <stdlib.h>
#include <stdio.h>
#include "headers.h"
#include <time.h>
#include <string.h>

/*
Feito por:
Gabriel Matheus da Rocha de Oliveira, 17/0103498
Guilherme Braga Pinto, 17/0162290
Last Update: 03/11/2018
UnB- CIC
*/

int main(){

  int cont_total;
  int opt;


  printf("Para ler a Lista 1, digite 0\n");
  printf("Para ler a Lista 2, digite 1\n");              // menu
  printf("Para intercalar Listas, digite 2\n");

  scanf("%d", &opt);
  int cont;

  if( (opt == 0) || (opt == 1)){
  printf("O arquivo desejado possui quantos registros?\n");         // para a manipulção de registros
  scanf("%d", &cont);
  }

  char matricula_texto1[6];
  int matricula_texto1_convertido[cont][6];
  char nome_texto1[41];
  char OP[2];
  char Curso[2];
  char Turma;
  int l, m;

  Lista *li;
  Lista *lEC;
  Lista *lEM;
  Lista *lCC;
  li = cria_lista();
  lEC = cria_lista();
  lEM = cria_lista();
  lCC = cria_lista();

  Dados pessoas[cont];

  int i = 0;
  int k = 0;
  int indice = 0;
  char linha[65];
  char linha_aux[30];

  int cont1, cont2;
  char indice_prim_aux[cont][30];
  
  char *indice_prim_F[cont];
  // int opt = 9;

  FILE *fp;
  FILE *fp1;
  FILE *fp2;  //intercalação 
  FILE *result;
  FILE *Primary_Index;
  FILE *Secondary_Index;
  FILE *Secondary_Index_List;
//  fp = fopen ("lista2.txt", "r");
  Primary_Index = fopen("P_Index", "w");
  Secondary_Index = fopen("S_Index", "w");
  Secondary_Index_List = fopen("S_L_Index", "w");

//-------------------------------------------Escolhendo qual arquivo abrir-----------------------------------------
  if(opt == 0){
    printf("Lendo o arquivo 1!\n");
    fp = fopen ("lista1.txt", "r");
    if (fp == NULL){
      printf("Problemas na leitura da lista1.txt\n");
      return 0;
    }
  }

  if(opt == 1){
    printf("Lendo o arquivo 1!\n");
    fp = fopen ("lista2.txt", "r");
    if (fp == NULL){
      printf("Problemas na leitura da lista1.txt\n");
      return 0;
    }
  }

  if((opt == 0) || (opt == 1)){

//--------------------------------------------------LOOP LISTAS----------------------------------------------------
    for(k = 0; k<cont; k++){
      for(i = 0; i<41; i++){
          nome_texto1[i]= ' ';           //limpar buffer
      }
      for(i = 0; i<30; i++){
        indice_prim_aux[k][i] = ' ';     
          //indice_prim_F[k][i] = ' ';        //limpar buffer
      }

      fgets(linha, 65, fp);
      for(i = 0; i < 6; i++){
        matricula_texto1[i] = linha[i];               //lemos a matricula

        matricula_texto1_convertido[k][i] = (matricula_texto1[i] - 48);

        indice_prim_aux[k][i] = linha[i];
            //indice_prim_F[k][i] = linha[i];
      }

      printf("\n");
      printf("Linha: \n");
      printf("%s \n", linha);
      printf("Matricula: \n");
      for( i = 0; i < 6; i++){
        printf("%c", matricula_texto1[i]);          // os primeiros 6 caracteres do indice primario sao a matricula
      }
      l = 6;
      for(i = 0; i < 41; i++){
        nome_texto1[i] = linha[i+7];
        if((nome_texto1[i] != ' ') && (l < 30)) {           // se o nome nao tem espaço vazio, preenchemos ate 30 espacos
          indice_prim_aux[k][l] = nome_texto1[i];
              //indice_prim_F[k][l] = nome_texto1[i];
          l++;
        }
      }

      indice_prim_aux[k][30] = '\0';
        //indice_prim_F[k][30] = '\0';
      strcpy(pessoas[k].chave, indice_prim_aux[k]);               // copia para "pessoas"
      pessoas[k].Adress = k+1;
          //strcpy(indice_prim_F[k], indice_prim_aux[k]); 

      printf("\nNome: \n");
      for(i = 0; i < 41; i++){                     // mostramos o nome
        printf("%c", nome_texto1[i]);        
      }

      printf("\n\n\n");
      printf("Índice primário: ");           //mostramos o indice primario
      for(i=0; i<30; i++){
        printf("%c", indice_prim_aux[k][i]);              // mostra indice
      }
      printf("\n\n\n");
      printf("\n");
      for(i = 0; i < 2; i++){
        OP[i] = linha[i+48];            // ler OP
      }
      OP[2] = '\0';
      printf("OP: %s \n", OP);
      Turma = linha[61];
      printf("Turma: %c \n", Turma);        //print de turma
      for(i = 0; i < 2 ; i++){
        Curso[i] = linha[i+52];
      }
      Curso[2] = '\0';
      printf("Curso: ");
      for(i = 0; i < 2 ; i++){              //print de curso
        printf("%c", Curso[i]);
      }
      printf("\n");
                                               // operações de inserir no final da lista as informações desejadas
      if (strcmp(Curso, "EC") == 0) 
      {
        insere_lista_final(lEC, pessoas[k]); 
      } 
      else if (strcmp(Curso, "EM") == 0)
      {
        insere_lista_final(lEM, pessoas[k]); 
      }
      else if (strcmp(Curso, "CC") == 0)
      {
        insere_lista_final(lCC, pessoas[k]); 
      }

      insere_lista_final(li, pessoas[k]);
      printf("%s \n", indice_prim_aux[k]);
      indice_prim_F[k] = indice_prim_aux[k];
          //indice_prim_F[k][30] = '\0';
      printf("Chave: %s Arquivo: lista.1 \n", indice_prim_F[k]);
      printf("testando> %s \n", pessoas[k].chave);                         

      printf("\n---------------------------------------\n");
    }
      
//--------------------------------------------------LOOP LISTAS (fim)----------------------------------------------------

        //printf("Chave: %s \n Arquivo: lista.1 ", indice_prim_F[1]);
     
    int tam1 = tamanho(lEC);
    printf("%d \n", tam1);
    int tam2 = tamanho(lEM);
    printf("%d \n", tam2);
    int tam3 = tamanho(lCC);                      // contador/lista de cursos
    printf("%d \n", tam3);
    int tam4 = tamanho(li);
    printf("%d \n", tam4);

    int cont_aux = 1;
    int prox;
    int ant;
    struct dados pessoas_aux;
    fprintf(Secondary_Index, "1 Curso: EC Número de itens: %d\n", tam1);    // indice secundário
    for(i = 0; i < tam1; i++){
      consulta_lista_pos(lEC, i + 1, &pessoas_aux);            // consultamos quem devemos salvar
          //printf("%s \n\n", pessoas_aux.chave);
      prox = Proximo(lEC, i + 1);         // define-se quem vem antes e depois de tal registro
      ant = Anterior(lEC, i + 1);
      fprintf(Secondary_Index_List, "%d %s \t\tEndereço: %d \tAnterior: %d \tProximo: %d \n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress, ant, prox);
      cont_aux++;
    }
        //printf("\n");
    fprintf(Secondary_Index, "2 Curso: EM Número de itens: %d\n", tam2);      // indice secundário
    for(i = 0; i < tam2; i++){
      consulta_lista_pos(lEM, i + 1, &pessoas_aux);        // consultamos quem devemos salvar
          //printf("%s \n\n", pessoas_aux.chave);
      prox = Proximo(lEM, i + 1);                              // define-se quem vem antes e depois de tal registro
      ant = Anterior(lEM, i + 1);
      fprintf(Secondary_Index_List, "%d %s \t\tEndereço: %d \tAnterior: %d \tProximo: %d \n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress, ant, prox);
      cont_aux++;
    }
        //printf("\n");
    fprintf(Secondary_Index, "3 Curso: CC Número de itens: %d\n", tam3);          // indice secundário
    for(i = 0; i < tam3; i++){
      consulta_lista_pos(lCC, i + 1, &pessoas_aux);              // consultamos quem devemos salvar
          //printf("%s \n\n", pessoas_aux.chave);
      prox = Proximo(lCC, i + 1);          // define-se quem vem antes e depois de tal registro
      ant = Anterior(lCC, i + 1);
      fprintf(Secondary_Index_List, "%d %s \t\tEndereço: %d \tAnterior: %d \tProximo: %d \n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress, ant, prox);
      cont_aux++;
      cont_total = cont_aux;
    }

    cont_aux = 1;
    for(i = 0; i < cont; i++){
      consulta_lista_pos(li, i + 1, &pessoas_aux);
      fprintf(Primary_Index, "%d %s \t\tEndereço: %d\n", cont_aux, pessoas_aux.chave, pessoas_aux.Adress);        // salvamos indices primarios
      cont_aux++;
    }

  }
  //printf("ponteiro: %s \n", indice_prim_F[2]);

  //heapSort(indice_prim_F, cont);

   // for(i = 0; i < 19; i++){
   //    printf("Chave: %s Arquivo: lista.1 \n", indice_prim_F[i]);
   // }

   // for(i = 0; i < 19; i++){
   //           fprintf(Primary_Index, "Chave: %s Arquivo: lista.1 Linha: %d \n", indice_prim_F[k], i + 1);
   //           }

            //printf("Chave: %s Arquivo: lista.1 \n", indice_prim_F[k]);
            

      // ainda dentro do loop, temos que salvar o indice primario para o arquivo de indice.
      //indice primario é pra se se guardar no arquivo, senão o programa fica bem pesado

//--------------------------------------------------LOOP LISTA2----------------------------------------------------
//                             opdate 11h de 2/11 -> agora o loop de cima le as duas listas
//--------------------------------------------------LOOP LISTA2----------------------------------------------------


//--------------------------------------------------INTERCALANDO----------------------------------------------------

  if(opt == 2){

    printf("Quantas linhas tem respectivamente a lista 1 e a lista 2?\n");
    scanf("%d %d", &cont1, &cont2);
    printf("Intercalando...\n");
    fp1 = fopen ("lista1.txt", "r");
    fp2 = fopen ("lista2.txt", "r");
    result = fopen("result.txt", "w");
    int j;
    j = (cont1 + cont2);
    int comparador[j][6];
    int array_matriculas[j];
    int array_matriculas_aux[j];
    char indice_prim_aux_L1[cont1][30];
    char indice_prim_aux_L2[cont2][30];
    char info_nome[j][41];
    char info_add[j][14];
    int repetido;


    memset( comparador, ' ', sizeof(comparador) );
    memset( nome_texto1, ' ', sizeof(nome_texto1) );             // limpamos o buffer
    memset( linha, ' ', sizeof(linha) );
    memset( info_add, ' ', sizeof(info_add));

    //memset( array_matriculas, ' ', sizeof(array_matriculas) );

//--------------------------------------------------file 1----------------------------------------------------

    memset( indice_prim_aux_L1, ' ', sizeof(indice_prim_aux_L1) );       // limpamos o buffer
    memset( indice_prim_aux_L2, ' ', sizeof(indice_prim_aux_L2) );


    //gera chaves FILE 1
    printf("\n\n\n\n");
    printf("Chaves da Lista 1:\n\n");
    printf("Número de Linhas no Arquivo 1: %d\n\n", cont1);

    k = 0;
    while(k<cont1){
      memset( linha, ' ', sizeof(linha) );
      fgets(linha, 65, fp1);
      for(i = 0; i < 6; i++){
        indice_prim_aux_L1[k][i] = linha[i];
        comparador[k][i] = indice_prim_aux_L1[k][i] - 48;
        
      }
      for(i=0; i<14; i++){
        info_add[k][i] = linha[i+50];
      }

      l = 6;
      for(i = 0; i < 41; i++){
        nome_texto1[i] = linha[i+7];
        if((nome_texto1[i] != ' ') && (l < 30)) {           // se o nome nao tem espaço vazio, preenchemos ate 30 espacos
          indice_prim_aux_L1[k][l] = nome_texto1[i];
          l++;
        }
        info_nome[k][i] = linha[i+7];
      }
      indice_prim_aux_L1[k][30] = '\0';

      for(i=0; i<30; i++){
        printf("%c", indice_prim_aux_L1[k][i]);              // mostra indice
      }
      printf("\n");
      k++;
    }


//--------------------------------------------------file 2----------------------------------------------------

    //gera chaves FILE 2
    printf("\n\n\n\n");
    
    printf("Chaves da Lista 2:\n\n");
    printf("Número de Linhas no Arquivo 2: %d\n\n", cont2);

    memset( nome_texto1, ' ', sizeof(nome_texto1) );        // limpamos o buffer

    for(k = 0; k<cont2; k++){
      memset( linha, ' ', sizeof(linha) );
      fgets(linha, 65, fp2);
      for(i = 0; i < 6; i++){
        indice_prim_aux_L2[k][i] = linha[i];
        j = (k + cont1);
        comparador[j][i] = ((linha[i]) - 48);
      }

      for(i=0; i<14; i++){
        info_add[k][i] = linha[i+50];
      }

      l = 6;
      for(i = 0; i < 41; i++){
        nome_texto1[i] = linha[i+7];
        if((nome_texto1[i] != ' ') && (l < 30)) {           // se o nome nao tem espaço vazio, preenchemos ate 30 espacos
          indice_prim_aux_L2[k][l] = nome_texto1[i];
          l++;
        }
        m = (k+cont1);
        info_nome[m][i] = linha[i+7];
      }
      indice_prim_aux_L2[k][30] = '\0';

      for(i=0; i<30; i++){
        printf("%c", indice_prim_aux_L2[k][i]);              // mostra indice
      }
      printf("\n");
    }

    printf("\n\n\n");
    printf("Matriz da info add\n");
    for(i=0 ; i<j; i++){
      for(k=0; k<41; k++){
        printf("%c", info_nome[i][k]);
      }
      printf("\n");
    }


    printf("\n\n\n");
    printf("Matriz dos comparadores!\n\n");
    for(i=0; i<(j+1); i++){
      for(k=0; k<6; k++){
        printf("%d ", comparador[i][k]);    
      }
      printf("\n");
    }

    printf("Array dos comparadores!\n\n");
    for(i=0; i<(j+1); i++){
      array_matriculas[i] =  (comparador[i][5] * 1) + (comparador[i][4] * 10) + (comparador[i][3] * 100) + (comparador[i][2] * 1000) + (comparador[i][1] * 10000);
    
      printf("%d", array_matriculas[i]);
      printf("\n");
    }

    insertionSort(array_matriculas, (j+1) );           // organizamos as matrículas
    
    printf("Array organizado!\n\n");

    for(i=0; i<(j+1); i++){
      
     // printf("0%d ->", array_matriculas[i]);
      //printf("\n");
      fprintf(result, "0%d ", array_matriculas[i]);
      for (k = 0; k < j; k++){ 

        if(array_matriculas[i] == ((comparador[k][5] * 1) + (comparador[k][4] * 10) + (comparador[k][3] * 100) + (comparador[k][2] * 1000) + (comparador[k][1] * 10000))){
          for(m=0; m<41; m++){
            fprintf(result, "%c", info_nome[k][m]);     // mostramos o resto da informação 
          }
          for(m=0; m<14; m++){
            fprintf(result, "%c", info_add[k][m]);     // mostramos o resto da informação 
          }
          

          fprintf(result, "\n");
        }
      }
    }    

  //--------------------------------------------------compara----------------------------------------------------

    /* codigo para quando termos o tamanho dos dois arquivos (cont1 e cont2)



      for(i = 0; i<cont1; i++){
        int comparador1[i] = ((indice_prim_aux[i][0] - 48) + ((indice_prim_aux[i][1] - 48)*10) + ((indice_prim_aux[i][2] - 48)*100) + ((indice_prim_aux[i][3] - 48)*1000) + ((indice_prim_aux[i][4] - 48)*10000) + ((indice_prim_aux[i][5] - 48)*100000));
      }
      for(i=0; i<cont2; i++){
        int comparador2[i] = ((indice_prim_aux_L2[i][0] - 48) + ((indice_prim_aux_L2[i][1] - 48)*10) + ((indice_prim_aux_L2[i][2] - 48)*100) + ((indice_prim_aux_L2[i][3] - 48)*1000) + ((indice_prim_aux_L2[i][4] - 48)*10000) + ((indice_prim_aux_L2[i][5] - 48)*100000));
      }

    int flag = 1;
    i = 0;
    k = 0;

    while(flag == 1){

      if(comparador1[i] > comparador2[k]){
        for(l = 0; l<45; l++){
          fprintf(result, "%c", indice_prim_aux[i][l]);
        }
        fprintf(result, "\n");
        i++;
      }
      if(comparador1[i] > comparador2[k]){
        for(l = 0; l<45; l++){
          fprintf(result, "%c", indice_prim_aux[k][l]);
        }
        fprintf(result, "\n");
        k++;
      }
      
      if(i == cont1){
        for( ; k<cont2; k++){
          for(l = 0; l<45; l++){
            fprintf(result, "%c", indice_prim_aux[k][l]);
          }
        fprintf(result, "\n");
        }
        flag = 0;  
      }

      if(k == cont2){
        for( ; i<cont1; i++){
          for(l = 0; l<45; l++){
            fprintf(result, "%c", indice_prim_aux_L2[k][l]); 
          }
        fprintf(result, "\n");
        }
        flag = 0;
      }
    }

      
    */
    //fclose(fp);
    printf("Intercalação pronta!\n\n");
    fclose(fp2);
    fclose(fp1);
    fclose(result);
    return 0;
  }

  //--------------------------------------------------INTERCALANDO----------------------------------------------------


  FILE *fpF;
  fclose(fp); 
  if(opt == 0){
  fpF = fopen ("lista1.txt", "a+");

  }
  if(opt == 1){
  fpF = fopen ("lista2.txt", "a+");

  }
  
  int opF;
  int aux_cont_valid = 6;
  struct dados pessoas_aux_F;
  struct dados pessoas_aux_F2;
  char matricula_aux[6];
  char nome_aux[41]; 
  char Curso_aux[2];

  printf("\n\n");
  printf("Lista criada com sucesso!\n");
  printf("O que deseja fazer agora?\n\n");

  while(1){

  for(i = 0; i<41; i++){
    nome_aux[i] = ' ';
  }
  for(i = 0; i<30; i++){
    pessoas_aux_F.chave[i] = ' ';
  }

  printf("1 - Adicionar Registro\n");
  printf("2 - Excluir registro\n");
  printf("3 - sair do programa\n");
  scanf("%d", &opF);
  getchar();

  if(opF == 1){
    printf("Por favor, digite os seguintes dados:\n");
    printf("Matricula\n");
    scanf("%[^\n]", matricula_aux);
    getchar();
    printf("%s\n", matricula_aux);
    printf("Nome completo\n");
    scanf("%[^\n]", nome_aux);
    getchar();
    nome_aux[strlen(nome_aux)] = ' ';
    nome_aux[41] = '\0';
    printf("%s\n", nome_aux);
    for(i = 0; i < 6; i++){
      pessoas_aux_F.chave[i] = matricula_aux[i];
    }
    aux_cont_valid = 6;  
    for(i = 0; i < 41; i++){
      if((nome_aux[i] != ' ') && (aux_cont_valid < 30)){
      pessoas_aux_F.chave[aux_cont_valid] = nome_aux[i];
      aux_cont_valid++;
      }
    }
    pessoas_aux_F.chave[30] = '\0';
    printf("chave = %s\n", pessoas_aux_F.chave);
    printf("Opção\n");
    scanf("%s", pessoas_aux_F.OP);
    getchar();
    pessoas_aux_F.OP[2] = '\0';
    printf("%s\n", pessoas_aux_F.OP);
    printf("Turma\n");
    scanf("%s", pessoas_aux_F.Turma);
    getchar();
    printf("%s\n", pessoas_aux_F.Turma);
    printf("Curso\n");
    scanf("%s", pessoas_aux_F.Curso);
    getchar();
    pessoas_aux_F.Curso[2] = '\0';
    printf("%s\n", pessoas_aux_F.Curso);
    pessoas_aux_F.Adress = cont_total;
       
    if (strcmp(pessoas_aux_F.Curso, "EC") == 0) 
    {
      insere_lista_final(lEC, pessoas_aux_F); 
    } 
    else if (strcmp(pessoas_aux_F.Curso, "EM") == 0)
    {
      insere_lista_final(lEM, pessoas_aux_F); 
    }
    else if (strcmp(pessoas_aux_F.Curso, "CC") == 0)
    {
      insere_lista_final(lCC, pessoas_aux_F); 
    }

    insere_lista_final(li, pessoas_aux_F);

    consulta_lista_pos(li, cont_total, &pessoas_aux_F2);
    fprintf(Primary_Index, "%d %s \t\tEndereço: %d\n", cont_total, pessoas_aux_F2.chave, pessoas_aux_F2.Adress);
    cont_total++;

    fprintf(fpF, "\n%s %s", matricula_aux, nome_aux);
    fprintf(fpF, "%s  %s\t\t %s", pessoas_aux_F2.OP, pessoas_aux_F2.Curso, pessoas_aux_F2.Turma);

    }

    if(opF == 3){
      return 0;
    // fclose(fpF);
    // fclose(fpF2);
    }
  }

  libera_lista(li);
  libera_lista(lEC);
  libera_lista(lEM);
  libera_lista(lCC);
  fclose(fpF);
  fclose(Primary_Index);
  fclose(Secondary_Index);
  fclose(Secondary_Index_List);
  return 0;
}