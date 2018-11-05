/**
 * @file main.c
 *
 * @brief Arquivo com a manipulação das Listas 
 *
 * @author Guilherme Braga e Gabriel Matheus.
 *
 */

//--------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------

int main(){

  int cont_total = 0;
  int opt;

  Escreve_Menu(3);

  scanf("%d", &opt);
  int cont;

  if( (opt == 0) || (opt == 1)){
  printf("O arquivo desejado possui quantos registros?\n");                                // definimos os registros do arquivo
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
  char linha_1[65];
  char linha_aux[30];

  int cont1, cont2;
  char indice_prim_aux[cont][30];
  
  char *indice_prim_F[cont];

  FILE *fp;
  FILE *fp1;
  FILE *fp2;  
  FILE *result;
  FILE *Primary_Index;
  FILE *Secondary_Index;
  FILE *Secondary_Index_List;
  Primary_Index = fopen("P_Index", "w");
  Secondary_Index = fopen("S_Index", "w");
  Secondary_Index_List = fopen("S_L_Index", "w");

 //-----------------------------------------------------Escolhendo qual arquivo abrir-----------------------------------------
 printf("\033[1;34m");
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
  printf("\033[0m");


  if((opt == 0) || (opt == 1)) {

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

      strcpy(pessoas[k].chave, indice_prim_aux[k]); 
      
      pessoas[k].Adress = k+1;                              //definimos seu endereço 

      for(i = 0; i < 2; i++){
        OP[i] = linha[i+48];            // ler OP
      }
      OP[2] = '\0';
      strcpy(pessoas[k].OP, OP); 
      Turma = linha[61];
      strcpy(pessoas[k].Turma, &Turma); 
      for(i = 0; i < 2 ; i++){
        Curso[i] = linha[i+52];                            //definimos o curso 
      }
      Curso[2] = '\0';
      strcpy(pessoas[k].Curso, Curso); 

      if (strcmp(Curso, "EC") == 0) 
      {
        insere_lista_ordenada(lEC, pessoas[k]);            // inserimos na lista de EC, caso o registro seja EC
      } 

      else if (strcmp(Curso, "EM") == 0)
      { 
        insere_lista_ordenada(lEM, pessoas[k]);                  // inserimos na lista de EM, caso o registro seja EM
      }

      else if (strcmp(Curso, "CC") == 0)
      {
        insere_lista_ordenada(lCC, pessoas[k]);           // inserimos na lista de CC, caso o registro seja CC
      }

      insere_lista_ordenada(li, pessoas[k]);                      // insere o resto
      cont_total++;
    }
      
//--------------------------------------------------LOOP LISTAS (FIM)----------------------------------------------------

    
    
    int tam1 = tamanho(lEC);         // definimos tamanhos
    int tam2 = tamanho(lEM);
    int tam3 = tamanho(lCC);
    int tam4 = tamanho(li);

 
      // ainda dentro do loop, temos que salvar o indice primario para o arquivo de indice.
      // indice primario é pra se se guardar no arquivo, senão o programa fica bem pesado
   
  }

  
//--------------------------------------------------INTERCALANDO----------------------------------------------------

  
  if(opt == 2){

    printf("\033[1;34m");
    printf("Quantas linhas tem respectivamente a lista 1 e a lista 2?\n");
    scanf("%d %d", &cont1, &cont2);
    printf("Intercalando...\n");
    printf("\033[0m");
    fp1 = fopen ("lista1.txt", "r");
    fp2 = fopen ("lista2.txt", "r");
    result = fopen("lista12.txt", "w");
    int j;
    j = (cont1 + cont2);
    int comparador[j][6];
    int array_matriculas[j];
    int array_matriculas_aux[j];
    char indice_prim_aux_L1[cont1][30];
    char indice_prim_aux_L2[cont2][30];
    char info_nome[j][41];
    char info_add[j][16];
    //int repetido;


    memset( comparador, ' ', sizeof(comparador) );
    memset( nome_texto1, ' ', sizeof(nome_texto1) );             // limpamos o buffer
    memset( linha_1, ' ', sizeof(linha_1) );
    memset( info_add, ' ', sizeof(info_add));


//--------------------------------------------------file 1----------------------------------------------------

    memset( indice_prim_aux_L1, ' ', sizeof(indice_prim_aux_L1) );       // limpamos o buffer
    memset( indice_prim_aux_L2, ' ', sizeof(indice_prim_aux_L2) );


    //gera chaves FILE 1
    printf("\n\n\n\n");
    printf("Chaves da Lista 1:\n\n");
    printf("Número de Linhas no Arquivo 1: %d\n\n", cont1);

    k = 0;
    while(k<cont1){                                   // vamos ler o arquivo 1 inteiro e retirar as informações que queremos
      memset( linha_1, ' ', sizeof(linha_1) );
      fgets(linha_1, 65, fp1);
      for(i = 0; i < 6; i++){
        indice_prim_aux_L1[k][i] = linha_1[i];                                // aqui nos referimos à matricula
        comparador[k][i] = indice_prim_aux_L1[k][i] - 48;
      }
      for(i=0; i<16; i++){
        info_add[k][i] = linha_1[i+47];             // chamamos isso de informação adicional, relacionaremos isso a cada matricula para organiza-la
      }

      l = 6;
      for(i = 0; i < 41; i++){
        nome_texto1[i] = linha_1[i+7];               // retiramos o nome
        if((nome_texto1[i] != ' ') && (l < 30)) {           // se o nome nao tem espaço vazio, preenchemos ate 30 espacos
          indice_prim_aux_L1[k][l] = nome_texto1[i];        // é o indice primario
          l++;
        }
        info_nome[k][i] = linha_1[i+7];            // informação de nome armazenada a longo prazo
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

    for(k = 0; k<cont2; k++){                    // vamos ler o arquivo 2 inteiro e retirar as informações que queremos
      memset( linha_1, ' ', sizeof(linha_1) ); 
      fgets(linha_1, 65, fp2);
      for(i = 0; i < 6; i++){
        indice_prim_aux_L2[k][i] = linha_1[i];                 // aqui nos referimos à matricula
        j = (k + cont1);
        comparador[j][i] = ((linha_1[i]) - 48);
      }

      for(i=0; i<16; i++){
        info_add[k+cont1][i] = linha_1[i+47];                 // chamamos isso de informação adicional, relacionaremos isso a cada matricula para organiza-la
      }

      l = 6;
      for(i = 0; i < 41; i++){
        nome_texto1[i] = linha_1[i+7];
        if((nome_texto1[i] != ' ') && (l < 30)) {           // se o nome nao tem espaço vazio, preenchemos ate 30 espacos
          indice_prim_aux_L2[k][l] = nome_texto1[i];
          l++;
        }
        m = (k+cont1);
        info_nome[m][i] = linha_1[i+7];                
      }
      indice_prim_aux_L2[k][30] = '\0';

      for(i=0; i<30; i++){
        printf("%c", indice_prim_aux_L2[k][i]);              // mostra indice
      }
      printf("\n");
    }


    // prints de teste, que mostraram estas informações ao longo do desenvolvimento 

/*    
    printf("\n\n\n");
    printf("Matriz do nome\n");
    for(i=0 ; i<j; i++){
      for(k=0; k<41; k++){
        printf("%c", info_nome[i][k]);
      }
      printf("\n");
    }
    printf("\n\n\n");
    printf("Matriz da indo_add\n");
    for(i=0 ; i<j; i++){
      for(k=0; k<16; k++){
        printf("%c", info_add[i][k]);
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
    */

    printf("Array dos comparadores!\n\n");
    for(i=0; i<(j+1); i++){                    // convertemos para inteiro, facilitar a organização 
      array_matriculas[i] =  (comparador[i][5] * 1) + (comparador[i][4] * 10) + (comparador[i][3] * 100) + (comparador[i][2] * 1000) + (comparador[i][1] * 10000);
    
      printf("%d", array_matriculas[i]);
      printf("\n");
    }

    insertionSort(array_matriculas, (j+1) );           // organizamos as matrículas
    
    printf("Array organizado!\n\n");


    for(i=0; i<(j+1); i++){
      
      for (k = 0; k < j; k++){ 

        if(array_matriculas[i] == ((comparador[k][5] * 1) + (comparador[k][4] * 10) + (comparador[k][3] * 100) + (comparador[k][2] * 1000) + (comparador[k][1] * 10000))){
          if(array_matriculas[i-1] != ((comparador[k][5] * 1) + (comparador[k][4] * 10) + (comparador[k][3] * 100) + (comparador[k][2] * 1000) + (comparador[k][1] * 10000))){
            fprintf(result, "0%d ", array_matriculas[i]);
            for(m=0; m<41; m++){
              fprintf(result, "%c", info_nome[k][m]);     // mostramos o resto da informação (nome)
            }
            for(m=0; m<16; m++){
              fprintf(result, "%c", info_add[k][m]);     // mostramos o resto da informação (info add)
            }
          

          fprintf(result, "\n");          // damos um espaço entre a informação 
          }
        }

      }

    }    

    fclose(fp1);
    fclose(fp2);                    //fechamos arquivos
    fclose(result);
    return 0;   // fim do programa
  }


  //--------------------------------------------------MENU----------------------------------------------------

  FILE *fpF;
  fclose(fp); 
  if(opt == 0){                               // abrimos o arquivo desejado
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

  Escreve_Menu(1);                                  // mostramos as opções 

  while(1){
    memset( nome_aux, ' ', sizeof(nome_aux) ); 

    for(i = 0; i<30; i++){
      pessoas_aux_F.chave[i] = ' ';
    }

    Escreve_Menu(2);

    scanf("%d", &opF);
    getchar();

//--------------------------------------------OP1------------------------------------------------

    if(opF == 1){
      printf("Por favor, digite os seguintes dados:\n");  //adicionaremos um registro
      printf("Matricula\n");
      scanf("%[^\n]", matricula_aux);            // coletamos informaões e a atribuimos à uma estrutura auxiliar
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
          pessoas_aux_F.chave[aux_cont_valid] = nome_aux[i];                   // atribuimos nome
          aux_cont_valid++;
        }
      }
      pessoas_aux_F.chave[30] = '\0';
      printf("chave = %s\n", pessoas_aux_F.chave);
      printf("Opção\n");                                    // atribuimos o resto dos valores, levando em conta estruturas de auxilio
      scanf("%s", pessoas_aux_F.OP);
      getchar();
      pessoas_aux_F.OP[2] = '\0';
      printf("%s\n", pessoas_aux_F.OP);
      printf("Turma\n");
      scanf("%s", pessoas_aux_F.Turma);
      getchar();
      pessoas_aux_F.Turma[1] = '\0';
      printf("%s\n", pessoas_aux_F.Turma);
      printf("Curso\n");
      scanf("%s", pessoas_aux_F.Curso);
      getchar();
      pessoas_aux_F.Curso[2] = '\0';
      printf("%s\n", pessoas_aux_F.Curso);
      pessoas_aux_F.Adress = cont_total+1;

      printf("\n\nAntes da inserção:\n\n");                         // mostramos os indices antes da inserção 
      printf("Indice Primário:\n\n");
      Escrever_Terminal_Primary(li, cont_total);
      printf("\n\nIndice Secundário:\n\n");
      Escrever_Terminal_Secondary(lEC, lEM, lCC, cont_total);

       
      if (strcmp(pessoas_aux_F.Curso, "EC") == 0) 
      {
        insere_lista_ordenada(lEC, pessoas_aux_F);                 // inserimos na lista que se encaixa
      } 
      else if (strcmp(pessoas_aux_F.Curso, "EM") == 0)
      {
        insere_lista_ordenada(lEM, pessoas_aux_F); 
      }
      else if (strcmp(pessoas_aux_F.Curso, "CC") == 0)
      {
        insere_lista_ordenada(lCC, pessoas_aux_F); 
      }

      insere_lista_ordenada(li, pessoas_aux_F);
      cont_total++; 
    
      printf("%d\n",cont_total);


      printf("\n\nDepois da inserção:\n\n");
      printf("Indice Primário:\n\n");
      Escrever_Terminal_Primary(li, cont_total);                   // mostramos como o arquivo fica após inserção 
      printf("\n\nIndice Secundário:\n\n");
      Escrever_Terminal_Secondary(lEC, lEM, lCC, cont_total);

      fprintf(fpF, "\n%s %s", matricula_aux, nome_aux);
      fprintf(fpF, "%s  %s\t\t %s", pessoas_aux_F.OP, pessoas_aux_F.Curso, pessoas_aux_F.Turma);
    }
//--------------------------------------------OPF 2-----------------------------------------------

    if(opF == 2){
  
      char rem_chave[30];
      for(i = 0; i<30; i++){
        rem_chave[i] = ' ';                                       // excluiremos um registro a partir de sua chave
      }
      printf("\nPor favor insira a chave do registro que deseja remover\n");
      scanf("%s", rem_chave);
      getchar();
      rem_chave[strlen(rem_chave)] = ' ';
      rem_chave[30] = '\0';

      printf("\n\nAntes da Remoção:\n\n");
      printf("Indice Primário:\n\n");                         // mostramos como esta antes da inserção 
      Escrever_Terminal_Primary(li, cont_total);
      printf("\n\nIndice Secundário:\n\n");
      Escrever_Terminal_Secondary(lEC, lEM, lCC, cont_total);

      int x = remove_lista(li, rem_chave);                   // removemos da lista, mostramos se não dá certo
      if(x == 0){
        printf("Chave não encontrada\n");
      }
      if(x == 1){
        printf("Registro excluido com sucesso!\n");
      }
      remove_lista(lEC, rem_chave);                          // levamos em considerãção os outros cenários 
      remove_lista(lEM, rem_chave);
      remove_lista(lCC, rem_chave);
      cont_total--;

      printf("\n\nDepois da Remoção:\n\n");              // mostramos após a exclusão 
      printf("Indice Primário:\n\n");
      Escrever_Terminal_Primary(li, cont_total);
      printf("\n\nIndice Secundário:\n\n");
      Escrever_Terminal_Secondary(lEC, lEM, lCC, cont_total);
    } 
//------------------------------------------- OPF 3----------------------------------------------- 

    if(opF == 3){                       // atualização de registro

      int opA;
      int pos;
      printf("O que deseja modificar?\n");
      printf("1 - Matricula\n");
      printf("2 - Nome\n");
      printf("3 - Opção\n");
      printf("4 - Turma\n");
      printf("5 - Curso\n");
      scanf("%d", &opA);
      getchar();

      char At_chave[30];
      for(i = 0; i<30; i++){
        At_chave[i] = ' ';
      }
      printf("\nPor favor insira a chave do registro que deseja atualizar\n");
      scanf("%s", At_chave);
      getchar();
      At_chave[strlen(At_chave)] = ' ';
      At_chave[30] = '\0';


      if(opA == 1 || opA == 2){

        copy(li, At_chave, &pessoas_aux_F2);
        remove_lista(li, At_chave);
        char At_chaveF[30];
        for(i = 0; i < 30; i++){
          At_chaveF[i] = ' ';
        }
        int aux_cont_valid = 6;

        if(opA == 1){
        printf("\nPor favor insira a nova Matricula\n");  
        for(i = 6; i<30; i++){
          At_chaveF[i] = At_chave[i];
        }
        scanf("%s", matricula_aux);
        getchar();
        matricula_aux[strlen(matricula_aux)] = ' ';
        At_chaveF[30] = '\0';
        for(i = 0; i < 6; i++){
          At_chaveF[i] = matricula_aux[i];
        }

      } 

      else if(opA == 2){
        printf("\nPor favor insira o novo Nome\n");  
        for(i = 0; i < 6; i++){
          At_chaveF[i] = At_chave[i];
        }
        scanf("%[^\n]", nome_aux);
        getchar();
        nome_aux[strlen(nome_aux)] = ' ';
        printf("%s\n",nome_aux );
        for(i = 0; i < 41; i++){
          if((nome_aux[i] != ' ') && (aux_cont_valid < 30)){
            At_chaveF[aux_cont_valid] = nome_aux[i];
            aux_cont_valid++;
          }
        }
        At_chaveF[30] = '\0';
      }

      printf("\n\nAntes da Atualização:\n\n");               // mostramos no terminal tudo antes das operações 
      printf("Indice Primário:\n\n");
      Escrever_Terminal_Primary(li, cont_total);
      printf("\n\nIndice Secundário:\n\n");
      Escrever_Terminal_Secondary(lEC, lEM, lCC, cont_total);

      strcpy(pessoas_aux_F2.chave, At_chaveF);
      insere_lista_ordenada(li, pessoas_aux_F2);

      if (strcmp(pessoas_aux_F2.Curso, "EC") == 0)               // fazemos comparações e retiramos elementos de sua respectiva lista
        {
        remove_lista(lEC, At_chave);
        insere_lista_ordenada(lEC, pessoas_aux_F2); 
        } 
      else if (strcmp(pessoas_aux_F2.Curso, "EM") == 0)
        {
        remove_lista(lEM, At_chave);
        insere_lista_ordenada(lEM, pessoas_aux_F2); 
        }
      else if (strcmp(pessoas_aux_F2.Curso, "CC") == 0)
        {
        remove_lista(lCC, At_chave);
        insere_lista_ordenada(lCC, pessoas_aux_F2); 
        }

      printf("\n\nDepois da Atualização:\n\n");                    // mostramos no terminal como tudo fica no final (indice primario e secundario)
      printf("Indice Primário:\n\n");
      Escrever_Terminal_Primary(li, cont_total);
      printf("\n\nIndice Secundário:\n\n");
      Escrever_Terminal_Secondary(lEC, lEM, lCC, cont_total);
      
      }

    }

//------------------------------------------- OPF 4------------------------------------------------

    if(opF == 4){

     //mostramos tudo no terminal e encerramos o programa

      Escrever_Arquivos_Primary(li, cont_total, Primary_Index); 
      Escrever_Arquivos_Secondary(lEC, lEM, lCC, cont_total, Secondary_Index, Secondary_Index_List);

      fclose(fpF);  
      break;
    }

  }

  
//--------------------------------------------FIM--------------------------------------------------  

  libera_lista(li);
  libera_lista(lEC);
  libera_lista(lEM);
  libera_lista(lCC);                       // liberamos listas e fechamos arquivos
  fclose(Primary_Index);
  fclose(Secondary_Index);
  fclose(Secondary_Index_List);
  return 0;
}