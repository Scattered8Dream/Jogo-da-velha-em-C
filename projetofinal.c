#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void tabuleiro (char casas2[9]){
 system("cls");
 printf ("\t %c | %c | %c \n",casas2 [0],casas2 [1],casas2[2]);
printf ("\t-----------\n");
 printf ("\t %c | %c | %c \n",casas2 [3],casas2 [4],casas2[5]);
 printf ("\t-----------\n");
 printf ("\t %c | %c | %c \n",casas2 [6],casas2 [7],casas2[8]);
}

int main(){
setlocale(LC_ALL,"portuguese");	

void menu();

	menu();
	
return 0;
}

//função menu, ela chama as outras opções do menu.
void menu(){
	
	void jogo();
	void sobre();
	void comojogar();
	
	int op;
	do{
	printf("Escolha uma opção do menu abaixo:");
	printf("\n 1.Jogar \n 2. Como jogar? \n 3. Sobre o jogo\n");
	scanf("%d",&op);
	}while(op<1 || op>3);

	switch(op){
		case 1:
		system("cls");
		jogo();
		break;
		
		case 2:
		system("cls");
		comojogar();
		break;
		
		case 3:
		system("cls");
		sobre();
		break;
	}
}

void comojogar(){
	printf("Como jogar\n");
	printf("Dois jogadores jogam alternadamente, preenchendo cada um dos espaços vazios, com um símbolo (normalmente X ou O). Vence o jogador que conseguir formar primeiro uma linha com três símbolos iguais, seja ela na horizontal, vertical ou diagonal");
	printf("\n\n Para voltar ao menu, digite enter");
	getch();
	system("cls");
	menu();
}

void sobre(){

	printf("Sobre o jogo\n");
	printf("Este jogo da velha foi desenvolvido por Edson e Julia, para a disciplina de Linguaguem e programação estrutrurada, ministrada professora Helien,do câmpus IFSP-Araraquara, no curso de ADS. ");
	printf("\n\n Para voltar ao menu, digite enter");
	getch();
	system("cls");
	menu();
	
}

void jogo(){
	char casas [9] = {'1','2','3','4','5','6','7','8','9'};
 	tabuleiro (casas);
 	char res;
 	int cont_jogadas,jogada,vez = 0,i;
 
 do{
  cont_jogadas = 1;
  for (i=0;i<=8;i++){
   casas[i] = ' ';
    }
  do{
   tabuleiro(casas);
   printf ("Digite a casa para marcar:");
   scanf("%i",&jogada);
   if (jogada < 1 || jogada > 9){
    jogada = 0;
   }else if (casas[jogada-1] != ' '){
    jogada = 0;
   }else{
    if (vez %2==0){
     casas [jogada-1]= 'X';
    }else{
     casas [jogada-1]= 'O';
    }
    cont_jogadas++;
    vez++;
   }
   if (casas[0]== 'X' && casas [1]== 'X' && casas[2]=='X') {cont_jogadas = 11;}
   if (casas[3]== 'X' && casas [4]== 'X' && casas[5]=='X') {cont_jogadas = 11;}
   if (casas[6]== 'X' && casas [7]== 'X' && casas[8]=='X') {cont_jogadas = 11;}
   if (casas[0]== 'X' && casas [3]== 'X' && casas[6]=='X') {cont_jogadas = 11;}
   if (casas[1]== 'X' && casas [4]== 'X' && casas[7]=='X') {cont_jogadas = 11;}
   if (casas[2]== 'X' && casas [5]== 'X' && casas[8]=='X') {cont_jogadas = 11;}
   if (casas[0]== 'X' && casas [4]== 'X' && casas[8]=='X') {cont_jogadas = 11;}
   if (casas[2]== 'X' && casas [4]== 'X' && casas[6]=='X') {cont_jogadas = 11;}
   
   if (casas[0]== 'O' && casas [1]== 'O' && casas[2]=='O') {cont_jogadas = 11;}
   if (casas[3]== 'O' && casas [4]== 'O' && casas[5]=='O') {cont_jogadas = 11;}
   if (casas[6]== 'O' && casas [7]== 'O' && casas[8]=='O') {cont_jogadas = 11;}
   if (casas[0]== 'O' && casas [3]== 'O' && casas[6]=='O') {cont_jogadas = 11;}
   if (casas[1]== 'O' && casas [4]== 'O' && casas[7]=='O') {cont_jogadas = 11;}
   if (casas[2]== 'O' && casas [5]== 'O' && casas[8]=='O') {cont_jogadas = 11;}
   if (casas[0]== 'O' && casas [4]== 'O' && casas[8]=='O') {cont_jogadas = 11;}
   if (casas[2]== 'O' && casas [4]== 'O' && casas[6]=='O') {cont_jogadas = 11;}
   
  }while (cont_jogadas <= 9);
  tabuleiro(casas);
  if(cont_jogadas==10){
   printf ("Jogo empatado\n");
  }if (cont_jogadas==11){
   printf ("Vencedor X\n");
  }if(cont_jogadas==12){
   printf ("Vencedor O\n");
  }
  
  printf ("Deseja jogar novamente?[S-N]\n");
  scanf ("%s",&res);
 }while(res=='s');
 
}
 
