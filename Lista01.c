#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();

int main(){
   int opc;
   int loop=0;

   while (loop==0){
      
      opc=0;

      printf("Coloque o num do ex: ");
      scanf("%d", &opc);

      switch (opc){
         case 1:
            ex01();
            break;
         case 2:
            ex02();
            break;
         case 3:
            ex03();
            break;
         case 4:
            ex04();
            break;
         case 5:
            ex05();
            break;
         case 6:
            ex06();
            break;
         default:
            loop=1;
            break;
      }
   }
   return 0;
}
/*A Amplitude amostral é uma médida de dispersão, ela é calculada como
a diferença entre o valor máximo e o valor mínimo de uma amostra.
Elabore um programa que leia um conjunto de 10 valores inteiros e então
mostre o valor máximo, o valor mínimo e a amplitude amostral do conjunto
fornecido. */
void ex01(){
   int nums01[10];
   int max,min;

   for(int i=0;i<10;i++){
      printf("Coloque um número: ");
      scanf("%d",&nums01[i]);
   }

   max = nums01[0];
   min = nums01[0];

   for(int j=1;j<10;j++){
      if(nums01[j]>max){
         max = nums01[j];
      }else if(nums01[j]<min){
         min = nums01[j];
      }
   }

   printf("Número Max: %d\nNúmero Mín: %d\nAmplitude: %d\n",max,min,max-min);
}

/*Escreva um algoritmo que leia um conjunto de números inteiros e que somente 
termine a leitura quando for fornecido um valor 0 (zero) imediatamente após 
um número ímpar positivo. Informe então qual foi o maior número ímpar fornecido. */
void ex02(){
   int nums02[999];
   int loop=0,i=0,max=0;

   while (loop==0){
      printf("Coloque um Número: ");
      scanf("%d", &nums02[i]);

      if(nums02[i]==0){
         if((nums02[i-1]%2)==1 && nums02[i-1]>0){
            printf("Saindo do loop...\n");  
            loop=1;
         }
      }else{
         if(((nums02[i]%2)==1 && nums02[i]>0) && nums02[i]>max){
            max = nums02[i];
         }
      }
      if(loop==0)i++;
   }
   printf("Max: %d\n\n",max);
}


void ex03(){
   int nums03[999];
   int i = 0;
   float media;
   int loop=0;

   while(loop==0){
      printf("Coloque o Número: ");
      scanf("%d",&nums03[i]);

      if(nums03[i-2]==nums03[i]-2 && nums03[i-1]==nums03[i]-1){
         loop=1;
      }
      if(loop==0) i++;
   }

   media=(nums03[i-2]+nums03[i-1]+nums03[i])/3;
   printf("Da sequência [%d, %d, %d], a média é: %f\n",nums03[i-2],nums03[i-1],nums03[i],media);
}

void ex04(){
   int num04;

   for(int i=0;i<10;i++){
      printf("Coloque o Número: ");
      scanf("%d",&num04);

      if(num04>0){
         for(int j=num04;j>=0;j--){
            printf("%d\n",j);
         }
      }else if(num04<0){
         for(int j=num04;j<=0;j++){
            printf("%d\n",j);
         }
      }else printf("Não atendido pelo sistema");
   }
   printf("\n");
}

void ex05(){
   int num05;
   float Harm=0.00,fracN;
   
   printf("Coloque o n-ésimo número: ");
   scanf("%d",&num05);

   for(int i=1;i<=num05;i++){
      fracN = 1.0/i;
      Harm=Harm+fracN;
      printf("Harm: %f \nCurrent: %f \n",Harm,fracN);
   }

   printf("Valor do número harmônico: %f\n",Harm);
}

void ex06(){
   int num06;
   float s=0.0;

   printf("Insira o número: ");
   scanf("%d",&num06);

   num06 = abs(num06);

   for(int i=1;i<=num06;i++){
      s += (float) i/sqrt(i+2.0);
   }

   printf("S = %f\n",s);
}


