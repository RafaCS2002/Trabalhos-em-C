#define n 7
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void printCamp(char camp[n][n],int choice[n][n]);

int main(){
   char camp[n][n];
   static int choice[n][n];
   int iChoice, jChoice;
   int loop = 1;


   // inicializa camp com X em td
   for(int i=0;i<n;i++) for(int j=0;j<n;j++) camp[i][j] = 'X';

   while (loop){
      
      printCamp(camp,choice);

      printf("\nEscolha uma Linha: ");
      scanf("%d",&iChoice);
      printf("Escolha uma Coluna: ");
      scanf("%d",&jChoice);

      choice[iChoice][jChoice] = 1;
      //printa matriz
      // for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(j==n-1){printf("%c \n",camp[i][j]);}else{printf("%c ",camp[i][j]);}
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
         if(choice[i][j] != 0){
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
