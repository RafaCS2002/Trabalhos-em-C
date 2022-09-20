#define cpfSize 14
#include <stdio.h>

int validation(char cpf[cpfSize]);
void takeOutSpecial(char cpf[cpfSize]);
char Digit01(char cpf[11]);
char Digit02(char cpf[11],char digit01);

int main(){
   // 073.679.229-55
   char cpf[cpfSize]={NULL};
   char digit01,digit02;
   int loop=1;

   while(loop==1){  
      while(loop==1){
         printf("Insira o CPF:");
         gets(cpf);
         loop = validation(cpf);
      }

      loop=1;

      takeOutSpecial(cpf);
      // printf("String: %s\n",cpf);

      digit01 = Digit01(cpf);
      printf("Digit01: %c\n",digit01);

      digit02 = Digit02(cpf,digit01);
      printf("Digit02: %c\n",digit02);

      if(cpf[cpfSize-5]==digit01 && cpf[cpfSize-4]==digit02){
         printf("O CPF inserido é Válido\n\nFechando o programa...\n\n");
         loop=0;
      }else printf("O CPF inserido é Inválido\n\n");
      
   }

   return 0;
}

int validation(char cpf[cpfSize]){
   int foo=0;
   for(int i=0; i<cpfSize;i++){
      if(cpf[i]==46 || cpf[i]==45){
         foo++;
      }else{
         for(int j=48;j<=57;j++){
            if(cpf[i]==j)foo++;
         }
      }
   }
   // printf("Foo: %d\n",foo);

   if((foo==11 && cpf[cpfSize-2]==NULL) || foo==14){
      return 0;
   }else{
      printf("Insira o CPF corretamente, sendo nos padrões:\n XXXXXXXXXXX\n XXX.XXX.XXX-XX\n");
      return 1;
   }
}

void takeOutSpecial(char cpf[cpfSize]){
   for(int i=0;i<cpfSize;i++){
      if(cpf[i]==46 || cpf[i]==45){
         for(int j=i;j<cpfSize;j++) {
            cpf[j]=cpf[j+1];
         }
      }
   }
}

char Digit01(char cpf[11]){
   char digit01;
   int sumAll=0;
   for(int i=0;i<9;i++){
      sumAll += (cpf[i]-48)*(10-i);
   }

   if(sumAll%11<2){
      digit01 = 48;
   }else{
      digit01 = (11-(sumAll%11)) + 48;
   }
   return digit01;
}

char Digit02(char cpf[11],char digit01){
   int sumAll=0;
   char digit02;

   for(int i=0;i<9;i++){
      sumAll += (cpf[i]-48)*(11-i);
   }
   sumAll += (digit01-48)*2;

   if(sumAll%11<2){
      digit02 = 48;
   }else{
      digit02 = (11-(sumAll%11))+48;
   }

   return digit02;
}
