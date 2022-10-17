#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void escolheNivel(int *n, int *qntBomb);

int main(){
   int n=0, qntBomb=0; // Tamanho da matriz e qnt de bombas
   int iChoice, jChoice; // Escolha linha e coluna
   int loop = 1,first = 1,lose=0,win=0,qntChoice=0,opt; // Variaveis de controle

   escolheNivel(&n,&qntBomb);
   
   printf("\n\nBOMBAS: %d\n",qntBomb);

   char camp[n][n]; // Vai receber o Campo gerado
   int choice[n][n]; // 0 - Não escolhido | 1 - Escolhido | 2 - Marcado

   // inicializa choice com 0 em td
   for(int i=0;i<n;i++) for(int j=0;j<n;j++) choice[i][j] = 0;
   // inicializa camp com '.' em td
   for(int i=0;i<n;i++) for(int j=0;j<n;j++) camp[i][j] = '.';

   while (loop){
      
      // printCamp(camp,choice,n);
      // PRINTA O CAMPO -----------------------------------------------------INICIO
      char line[n+1];
      line[n] = '\n';
      
      // Printa os indices das colunas
      printf("  ");
      for(int i=0;i<n;i++){
         if(i<=9){
            printf("   %d",i);
         }else{
            printf("  %d",i);
         }
      }
      printf("\n");

      for(int i=0;i<n;i++){
         //Checar se há escolha
         for(int j=0;j<n;j++){
            if(choice[i][j] == 1){
               line[j] = camp[i][j];
            }else if(choice[i][j]==2){
               line[j] = '^';
            }else{
               line[j] = '-';
            }
         }

         //print linha
         if(i<=9){
            printf("%d  |",i);
         }else{
            printf("%d |",i);
         }
         for(int j=0;j<n;j++){
            printf(" %c |",line[j]);
         }
         printf("%c",line[n]);
      }
      // PRINTA CAMPO ----------------------------------------------------------------- FIM

      // INICIA AS JOGADAS
      while (loop){
         printf("\n0 - Selecionar uma casa\n1 - Marcar Bomba\n2 - Desmarcar Bomba\nSelecionar: ");
         scanf("%d",&opt);

         switch (opt){
         case 0: // Seleciona casa
            printf("\nEscolha uma Linha: ");
            scanf("%d",&iChoice);
            printf("Escolha uma Coluna: ");
            scanf("%d",&jChoice);

            if(choice[iChoice][jChoice] == 0){
               choice[iChoice][jChoice] = 1;
            }else{
               printf("\nEsta casa não pode ser selecionada\n");
            }

            // Checa se é a primeira vez que está sendo escolhido
            if (first){
               //criaCamp(camp,choice,n); // gera o campo
               // CRIA CAMPO -----------------------------------------------------------INICIO
               int bomb[2];
               int choiceIndex[2];
               int bombInZone,bombInBomb;

               // Recebe os indices da escolha
               for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                     if (choice[i][j] == 1){
                        choiceIndex[0] = i;
                        choiceIndex[1] = j;
                     }
                  }
               }

               // Num de bombas == qntBomb
               for(int i=0;i<qntBomb;i++){ 
                  bomb[0] = (int) floorf(rand()%n); // linha
                  bomb[1] = (int) floorf(rand()%n); // coluna
                  bombInZone = 0;
                  bombInBomb = 0;

                  // checa se aleatorizou fora da zona de escolha
                  for(int j=-1;j<=1;j++){
                     for(int k=-1;k<=1;k++){
                        if ((choiceIndex[0]-j == bomb[0]) && (choiceIndex[1]-k == bomb[1])){// ([linha e coluna de escolha]+[-1,0,1]) == [linha e coluna da bomba aleatória]
                           bombInZone=1;
                        }
                     }
                  }

                  // Checa se há bomba no campo da linha e coluna aleatorizada
                  for(int j=0;j<n;j++){
                     for(int k=0;k<n;k++){
                        if (camp[j][k]=='X' && (j==bomb[0] && k==bomb[1])){
                           bombInBomb=1;
                        }
                     }
                  }

                  if(bombInZone){ // Tem bomba em zona de escolha
                     i--;    // Volta uma iteração
                  }else if(bombInBomb){ // Tem bomba já?
                     i--;    // Volta uma iteração
                  }else{
                     camp[bomb[0]][bomb[1]]='X';
                  }
               }

               // Atribuir a quantidade de bombas ao redor
               // 1 - Percorrer a matriz
               for(int i=0;i<n;i++){
                  for(int j=0;j<n;j++){
                     if(camp[i][j]=='X'){ // 2 - Eh bomba? Fixa a posicao
                        for(int k=-1;k<=1;k++){ // 3 - Analisa o perimetro ao redor da bomba
                           for(int l=-1;l<=1;l++){
                              if((i+k>=0 && i+k<n) && (j+l>=0 && j+l<n)){ // Evita lixo de memória
                                 if(camp[i+k][j+l] == '.'){ // 4 - Espaco vazio ao redor da bomba? Atribui 1
                                    camp[i+k][j+l] = '1';
                                 }else if(camp[i+k][j+l] != 'X'){ // 5 - Se ja tem num, num++
                                    camp[i+k][j+l]+=1;
                                 }
                              }
                           }
                        }
                     }
                  }
               }
               // CRIA CAMPO --------------------------------------------------------------FIM
               first=0;
            }
            
            //freePosi(camp,choice,n); // Libera os espaços ao redor
            // LIBERAR POSIÇÕES --------------------------------------------------------- INICIO
            int aux;
            for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                  if(camp[i][j]=='.' && choice[i][j] == 1){
                     for(int k=-1;k<=1;k++){
                        for(int l=-1;l<=1;l++){
                           if((i+k>=0 && i+k<n) && (j+l>=0 && j+l<n)){
                              if((camp[i+k][j+l] == '.' || (camp[i+k][j+l]>=48 && camp[i+k][j+l]<58)) && (choice[i+k][j+l]==0)){
                                 choice[i+k][j+l] = 1;
                                 aux = 1;
                              }
                           }
                           if((k==1 && l==1) && aux==1){
                              i--;
                              j--;
                              aux=0;
                           }
                        }
                     }
                  }
               }
            }
            // LIBERAR POSIÇÕES ------------------------------------------------------------ FIM
            loop = 0;
            break;
         case 1: // Marca Bomba
            printf("\nEscolha uma Linha: ");
            scanf("%d",&iChoice);
            printf("Escolha uma Coluna: ");
            scanf("%d",&jChoice);

            if(choice[iChoice][jChoice] == 0){
               choice[iChoice][jChoice] = 2;
            }else{
               printf("\nEsta casa não pode ser marcada\n");
            }
            
            loop = 0;
            break;
         case 2: // Desmarca Bomba
            printf("\nEscolha uma Linha: ");
            scanf("%d",&iChoice);
            printf("Escolha uma Coluna: ");
            scanf("%d",&jChoice);

            if(choice[iChoice][jChoice]==2){
               choice[iChoice][jChoice] = 0;
            }else{
               printf("\nNão pode ser desmarcado\n");
            }
            
            loop = 0;
            break;
         default:
            printf("\nComando não reconhecido\n");
            break;
         }
      }

      loop = 1;

      // Perdeu ou ganhou?
      qntChoice=0;
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            if(camp[i][j]=='X' && choice[i][j]==1){ // Checa se perdeu
               lose = 1;
               loop = 0;
            }
            if(camp[i][j]!='X' && choice[i][j]==1){
               qntChoice++;
               if(qntChoice == ((n*n)-qntBomb)){
                  win = 1;
                  loop = 0;
               }
            }
         }
      }
   }
   
   // PRINTA O CAMPO FINAL -----------------------------------------------------------------INICIO
   char line[n+1];
      line[n] = '\n';
      
      // Printa os indices das colunas
      printf("  ");
      for(int i=0;i<n;i++){
         if(i<=9){
            printf("   %d",i);
         }else{
            printf("  %d",i);
         }
      }
      printf("\n");

      for(int i=0;i<n;i++){
         //Checar se há escolha
         for(int j=0;j<n;j++){
            if(choice[i][j] == 1){
               line[j] = camp[i][j];
            }else if(choice[i][j]==2){
               line[j] = '^';
            }else{
               line[j] = '-';
            }
         }

         //print linha
         if(i<=9){
            printf("%d  |",i);
         }else{
            printf("%d |",i);
         }
         for(int j=0;j<n;j++){
            printf(" %c |",line[j]);
         }
         printf("%c",line[n]);
      }
   // PRINTA O CAMPO FINAL ---------------------------------------------------------------FINAL

   if(lose){
      printf("\n\nVOCÊ PERDEU\n\n");
   }else if(win){
      printf("\n\nVOCÊ GANHOU\n\n");
   }else{
      printf("\n\nERRO\n\n");
   }

   return 0;

}

void escolheNivel(int *n, int *qntBomb){
  int nivel;
  int loop=1;
  
  printf("Selecione o nível:\n0 - Aprendiz\n1 - Intermediário\n2 - Especialista\n3 - Custom\nNível: ");
  scanf("%d",&nivel);

   switch (nivel){
   case 0:// aprend
      *n=9;
      *qntBomb = 10;
      break;
   case 1:// inter
      *n=16;
      *qntBomb = 40;
      break;
   case 2:// espec
      *n=24;
      *qntBomb = 99;
      break;
   case 3:
      // custom
      while(loop){
         // ESCOLHA TAMANHO DE CAMPO
         while(loop){
            printf("Insira o tamanho do campo (Max 25;Min 3): ");
            scanf("%d",n);
            if(*n<=25 && *n>=3){
               loop=0;
            }else{
               printf("Digito Inválido\n");
            }
         }
         loop=1;
         // ESCOLHA BOMBAS
         while (loop){
            printf("Insira a quantidade de bombas (Max [(n*n)-9]): ");
            scanf("%d",qntBomb);
            if(*qntBomb<=((*n)*(*n))-9){
               loop=0;
            }else{
               printf("Digito Inválido\n");
            }
         }
      }
      break;
   default:
      printf("Comando não encontrado\n");
      break;
   }
}