#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//TEXTO PARA DESCOBRIR A ESCOLHA DO USUARIO
void texto_inicial(){
 printf("===============================\n");
 printf("   Calculadora Simples\n");
 printf("===============================\n");
 printf("Selecione uma operacao:\n");
 printf("1. Adicao\n2. Subtracao\n3. Multiplicacao\n4. Divisao\n5. Sair\n");
 printf("Opcao: ");
}
// FUNCÃO QUE ME RETORNA UM VALOR CHAR, PODENDO SER UM 'S' OU 'N' MAIUSCULO OU MINUSCULO
char SN(){
  char x[100];
  while(1){
  printf("\nDeseja realizar outra operacao? (s/n):");
  fgets(x,sizeof(x),stdin);
  x[strcspn(x,"\n")] = '\0';
  if(strlen(x) == 1){
    if(x[0] == 's' || x[0] == 'S' || x[0] == 'n' || x[0] == 'N'){
        break;
    }else{
    printf("\nResposta invalida. Por favor, digite 's' para sim ou 'n' para nao.\n");
    continue;
    }
  }else{
   printf("\nResposta invalida. Por favor, digite 's' para sim ou 'n' para nao.\n");
   continue;
  }
  }
  return x[0];
}
// FUNÇÃO QUE CALCULA, CASO O USUARIO ESCOLHA SOMAR 2 NÚMEROS
void Adicao(){
  float x, y;

  printf("\nDigite o primeiro numero: ");
  scanf("%f",&x);

  printf("Digite o segundo numero: ");
  scanf("%f",&y);

  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
    // ELE PEGA O 'ENTER' QUANDO VOÇÊ CONFIRMA O VALOR Y, SE NÃO TIVESSE AI, A FUNCÇÃO SN QUANDO ENTRASE ELE PEGARIA O ENTER E DAVA ERRO
  printf("Resultado: %.2f + %.2f = %.2f\n",x,y,x+y);
}
// FUNÇÃO QUE CALCULA, CASO O USUARIO ESCOLHA SUBTRAIR 2 NÚMEROS
void Subtracao(){
  float x, y;

  printf("\nDigite o primeiro numero: ");
  scanf("%f",&x);

  printf("Digite o segundo numero: ");
  scanf("%f",&y);

  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
    // ELE PEGA O 'ENTER' QUANDO VOÇÊ CONFIRMA O VALOR Y, SE NÃO TIVESSE AI, A FUNCÇÃO SN QUANDO ENTRASE ELE PEGARIA O ENTER E DAVA ERRO
  printf("Resultado: %.2f - %.2f = %.2f\n",x,y,x-y);
}
// FUNÇÃO QUE CALCULA, CASO O USUARIO ESCOLHA MULTIPLICAR 2 NÚMEROS
void Multi(){
  float x, y;

  printf("\nDigite o primeiro numero: ");
  scanf("%f",&x);

  printf("Digite o segundo numero: ");
  scanf("%f",&y);

  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
    // ELE PEGA O 'ENTER' QUANDO VOÇÊ CONFIRMA O VALOR Y, SE NÃO TIVESSE AI, A FUNCÇÃO SN QUANDO ENTRASE ELE PEGARIA O ENTER E DAVA ERRO
  printf("Resultado: %.2f * %.2f = %.2f\n",x,y,x*y);
}
// FUNÇÃO QUE CALCULA, CASO O USUARIO ESCOLHA DIVIDIR 2 NÚMEROS
void Div(){
  float x, y;

  printf("\nDigite o primeiro numero: ");
  scanf("%f",&x);

  printf("Digite o segundo numero: ");
  scanf("%f",&y);
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
  // ELE PEGA O 'ENTER' QUANDO VOÇÊ CONFIRMA O VALOR Y, SE NÃO TIVESSE AI, A FUNCÇÃO SN QUANDO ENTRASE ELE PEGARIA O ENTER E DAVA ERRO
  if(y == 0){
    printf("Erro: Divisao por zero nao e permitida.");
  }else{
   printf("Resultado: %.2f / %.2f = %.2f\n",x,y,x/y);
  }
  // O IF E ELSE ACIMA, VERIFICAM SE O VALOR Y È 0, CASO FOR ELE IMPRIMI QUE DEU ERRO
}

int main(){
  // CRIO UMA VARIAVEL CHAR AUXILIAR E UMA PARA VARIAVEL INTEIRA OPÇÃO
   int opcao = 0;
   char aux[100];
  //CRIO UM WHILE INFINITO
   while(1){
    //NA OPÇÃO 0, ONDE APARECE A TELA INICAL PARA O USUARIO ESCOLHER, QUAL CONTA ELE QUER FAZER
    if(opcao == 0){
        texto_inicial();
        //CAPTURA UM VALOR STRING
        fgets(aux,sizeof(aux),stdin);
        //SUBSTIUI UM 'ENTER' PARA UM FINAL DE STRING
        aux[strcspn(aux, "\n")] = '\0';
        //VERIFICAR SE A STRING TEM MAIS DE UMA LETRA, POIS SE NÃO TIVER NÃO PODE SER UM DOS VALORES
        if(strlen(aux) == 1){
            // PEGA O VALOR DO CHAR EM VALOR NÚMERICO
            int x = aux[0] - 48;
             // VERIFICA SE ESTE VALOR ESTA ENTRE AS OPÇÕES, CASO ESTEJA, O USUARIO VAI PARA OUTRA TELA PARA RESOLVER SEU CALCULO
            if(x >= 1 && x<=5){
                opcao = x;
              //SE O VALOR NÃO TIVER ENTRE OS VALORES DESCRITOS, OCASIONA UMA OPÇÃO INVALIDA E REPETE O CICLO
            }else{
             printf("\nOpcao invalida, digite novamente\n\n");
             continue;
            }
             //SE A STRING TEM MAIS DE UMA LETRA, APARECE UMA MENSAGEM DE INVALIDO E REPETE O CICLO
        }else{
           printf("\nOpcao invalida, digite novamente\n\n");
           continue;
        }
    //ADIÇÃO
    }else if(opcao == 1){
        //FUNÇÃO ADICAO E ENTREGA UM VALOR 'S' OU 'N' PARA A VARIAVEL CHAR C
        Adicao();
        char c = SN();
        // SE C FOR IGUAL A 'S' MAIUSCULO OU MINUSCULO, VOLTA PARA A TELA INICIAL
        if(c == 'S' || c == 's'){
          //APAGA TODAS AS MENSGAENS DO TERMINAL
            system("cls");
          // VOLTA PARA A TELA INICIAL
            opcao = 0;
          //REINICIA O WHILE
            continue;
          //CASO C NÃO SEJA UM 'S' MAIUCULO OU MINUSCOLO, VAI DIRETO PARA A SAIDA DO LOOP 
        }else{
          opcao = 5;
          continue;
        }
        break;
    //SUBTRAÇÃO
    // EM BAIXO O RACIOCINIO É O MESMO DA ADIÇÃO, SENDO SO OQ DIFERE É A OPERAÇÃO MATEMATICA 
    }else if(opcao == 2){
        Subtracao();
        char c = SN();
        if(c == 'S' || c == 's'){
            system("cls");
            opcao = 0;
            continue;
        }else{
          opcao = 5;
          continue;
        }
        break;
     //MULTIPLICAÇÃO
    }else if(opcao == 3){
        Multi();
        char c = SN();
        if(c == 'S' || c == 's'){
            system("cls");
            opcao = 0;
            continue;
        }else{
          opcao = 5;
          continue;
        }
        break;
    //DIVISÃO
    }else if(opcao == 4){
        Div();
        char c = SN();
        if(c == 'S' || c == 's'){
            system("cls");
            opcao = 0;
            continue;
        }else{
          opcao = 5;
          continue;
        }
        break;
    //NA QUINTA OPÇÃO, APARECE UMA MENSAGEM DE AGRADECIMENTO POR USAR A CALCULADORA E QUEBRA O LOOP JUNTO COM O PROGRAMA
    }else if(opcao == 5){
        printf("\nObrigado por usar a calculadora! Ate a proxima.\n");
        break;
    }
   }
}
