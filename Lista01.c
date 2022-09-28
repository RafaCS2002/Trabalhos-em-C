#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();
void ex07();
void ex08();
void ex09();

int main(){
   int opc;
   int loop=0;

   while (loop==0){
      
      opc=0;

      printf("\nColoque o num do ex: ");
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
         case 7:
            ex07();
            break;
         case 8:
            ex08();
            break;
         case 9:
            ex09();
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

/*Elabore um algoritmo que leia um conjunto de números inteiros e somente termine 
a leitura quando for fornecida uma sequência de três números em ordem crescente.
Mostre então qual a média deste conjunto de três números. */
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

/*Crie um algoritmo que leia 10 números inteiros. Quando o número fornecido for positivo,
mostre uma contagem regressiva até 0; quando ele for negativo, uma contagem normal até 0;
quando for nulo mostre “não atendido pelo programa”. */
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

/*Escreva um algoritmo para calcular o valor do número harmônico H dado que o número n 
será fornecido pelo usuário. Exemplo, se o usuário digitar 5, calcular 
H = 1 + 1/2 + 1/3 + 1/4 + 1/5 */
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

/*Elabore um algoritmo que calcule o valor da série S abaixo,
sendo que o valor inteiro de n é fornecido pelo usuário. */
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

/*Elabore um algoritmo que calcule e mostre o valor de π com base em uma série S de 50 termos.*/
void ex07(){
   double S=0,pi;
   int qntTerm,proxImp;

   printf("Insira a quantidade de termos: ");
   scanf("%d",&qntTerm);

   for(int i=1;i<=qntTerm;i++){
      if(i%2==1){
         S += (1.0/pow(((i*2.0)-1),3.0));
      }else{
         S -= (1.0/pow(((i*2.0)-1),3.0));
      }
   }
   S = S*32.0;
   pi = pow(S,1.0/3.0);

   printf("O número pi foi calculado como: %f\n",pi);

}

/*Escreva um programa que leia um conjunto de números inteiros até que o usuário forneça 
o valor 0 (zero).  
Para cada número par, some-o com a soma dos anteriores, para cada número ímpar, subtraia-o 
da soma dos anteriores. 
Exemplo: para a entrada: 2 + 4 - 3 + 2 -1 0, o resultado é 4.  
Mostre então o resultado desta soma, a quantidade total de números fornecidos assim como 
a porcentagem de números ímpares e de números pares (desconsiderando o finalizador 0). */
void ex08(){
   int nums,sum=0;

   printf("Insira os valores: \n");
   for(int i=1;i==1;){
      
      scanf("%d",&nums);

      if(nums==0){
         i=0;
      }else{
         if(nums%2==1){
            sum -= nums;
         }else{
            sum += nums;
         }
      }
   }

   printf("A soma foi de %d\n",sum);

}

/*Elabore um algoritmo que sorteie 100 números entre 1 e 100. Ao final mostre quantos 
estão dentro dos seguintes intervalos: 1 ≤ d ≤ 25; 25 < d ≤ 50; 50 < d ≤ 75; 75 < d ≤ 100. */
void ex09(){
   int nums[100],qnt;

   for(int i=0;i<100;i++){
      nums[i] = rand()%100+1;
   }
   for(int i=1;i<5;i++){
      qnt = 0;
      for(int j=0;j<100;j++){
         if((nums[j]>(25*i)-25)&&(nums[j]<=25*i)){
            qnt++;
         }
      }
      printf("%d estão no intervalo %d < NÚMERO <= %d\n",qnt,((25*i)-25),(25*i));
   }

}

/*Um número na forma n3 é igual a soma de n ímpares consecutivos. 
Exemplo: 13= 1, 23= 3+5, 33= 7+9+11, 43= 13+15+17+19 etc. 
Dado um limite superior ls fornecido pelo usuário, mostre os ímpares consecutivos cuja
soma é igual a n3 para n variando de 1 até ls. */
void ex10(){
   int numEsq=0,numDir=0,ls;

   printf("Insira o limite superior: ");
   scanf("%d",&ls);

   // for(int i=1;i<=ls;i++){
   //    numEsq = pow(i,3.0);
   //    for (int j=1; j<=i; j++){
   //       numDir += (2*j)-1;
   //    }

   //    printf("%d = ");
   // }
}
