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
}

void ex01(){
   int nums[10];
   int max,min;

   for(int i=0;i<10;i++){
      printf("Coloque um número: ");
      scanf("%d",&nums[i]);
   }

   max, min = nums[0];

   for(int j=1;j<10;j++){
      if(nums[j]>max){
         max = nums[j];
      }else if(nums[j]<min){
         min = nums[j];
      }
   }

   printf("Número Max: %d\nNúmero Mín: %d\nAmplitude: %d\n",max,min,max-min);
}

void ex02(){
   int nums[999];
   int loop=0,i=0,max=0;

   while (loop==0){
      printf("Coloque um Número: ");
      scanf("%d", &nums[i]);

      if(nums[i]==0){
         if((nums[i-1]%2)==1 && nums[i-1]>0){
            printf("Saindo do loop...\n");  
            loop=1;
         }
      }else{
         if(((nums[i]%2)==1 && nums[i]>0) && nums[i]>max){
            max = nums[i];
         }
      }
      if(loop==0)i++;
   }
   printf("Max: %d\n\n",max);
}

void ex03(){
   int nums[999];
   int i = 0;
   float media;
   int loop=0;

   while(loop==0){
      printf("Coloque o Número: ");
      scanf("%d",&nums[i]);

      if(nums[i-2]==nums[i]-2 && nums[i-1]==nums[i]-1){
         loop=1;
      }
      if(loop==0) i++;
   }

   media=(nums[i-2]+nums[i-1]+nums[i])/3;
   printf("Da sequência [%d, %d, %d], a média é: %f\n",nums[i-2],nums[i-1],nums[i],media);
}

void ex04(){
   int num;

   for(int i=0;i<10;i++){
      printf("Coloque o Número: ");
      scanf("%d",&num);

      if(num>0){
         for(int j=num;j>=0;j--){
            printf("%d\n",j);
         }
      }else if(num<0){
         for(int j=num;j<=0;j++){
            printf("%d\n",j);
         }
      }else printf("Não atendido pelo sistema");
   }
   printf("\n");
}

void ex05(){
   int num;
   float Harm=0.00,fracN;
   
   printf("Coloque o n-ésimo número: ");
   scanf("%d",&num);

   for(int i=1;i<=num;i++){
      fracN = 1.0/i;
      Harm=Harm+fracN;
      printf("Harm: %f \nCurrent: %f \n",Harm,fracN);
   }

   printf("Valor do número harmônico: %f\n",Harm);
}

void ex06(){
   int num;
   float s=0.0;

   printf("Insira o Num: ");
   scanf("%d",&num);

   num = abs(num);

   for(int i=1;i<=num;i++){
      s += (float) i/sqrt(i+2.0);
   }

   printf("S = %f\n",s);
}

