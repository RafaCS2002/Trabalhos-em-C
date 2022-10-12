#define n 7
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void printCamp(char camp[n][n],int choice[n][n]);
void criaCamp(char camp[n][n],int choice[n][n]);

int main(){
   char camp[n][n]; // Vai receber o Campo gerado
   static int choice[n][n]; // 0 - Não escolhido | 1 - Escolhido
   int iChoice, jChoice; // Escolha linha e coluna
   int loop = 1;
   int first = 1;


   // inicializa camp com '' em td
   for(int i=0;i<n;i++) for(int j=0;j<n;j++) camp[i][j] = '.';

   while (loop){
      
      printCamp(camp,choice);

      printf("\nEscolha uma Linha: ");
      scanf("%d",&iChoice);
      printf("Escolha uma Coluna: ");
      scanf("%d",&jChoice);

      choice[iChoice][jChoice] = 1;

      // Checa se é a primeira vez que está sendo escolhido
      if (first){
         criaCamp(camp,choice);
         first=0;
      }

      //printa matriz
      for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(j==n-1){printf("%c \n",camp[i][j]);}else{printf("%c ",camp[i][j]);}
      // for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(j==n-1){printf("%d \n",choice[i][j]);}else{printf("%d ",choice[i][j]);}
   }
}

void printCamp(char camp[n][n],int choice[n][n]){
   char line[n+1];
   line[n] = '\n';
   
   printf(" ");
   for(int i=0;i<n;i++){
      printf("   %d",i);
   }
   printf("\n");

   for(int i=0;i<n;i++){
      //Checar se há escolha
      for(int j=0;j<n;j++){
         if(choice[i][j]){
            line[j] = camp[i][j];
         }else{
            line[j] = '-';
         }
      }

      //print linha
      printf("%d |",i);
      for(int j=0;j<n;j++){
         printf(" %c |",line[j]);
      }
      printf("%c",line[n]);
   }
}

void criaCamp(char camp[n][n],int choice[n][n]){
   int bomb[2];
   int choiceIndex[2];
   int bombInZone,bombInBomb;

   // Recebe os indices da escolha
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if (choice[i][j]){
            choiceIndex[0] = i;
            choiceIndex[1] = j;
         }
      }
   }

   // Num de bombas == tamanho n da matriz
   for(int i=0;i<n;i++){ 
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
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if(camp[i][j]=='X'){
            for(int k=-1;k<=1;k++){
               for(int l=-1;l<=1;l++){
                  if((i+k>=0 && i+k<n) && (j+l>=0 && j+l<n)){
                     if(camp[i+k][j+l] == '.'){
                        camp[i+k][j+l] = '1';
                     }else if(camp[i+k][j+l] != 'X'){
                        camp[i+k][j+l]+=1;
                     }
                  }
               }
            }
         }
      }
   }
}
