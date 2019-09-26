#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Estrutura
typedef struct str_no {
	char dado;
	int esquerda;
	int direita;
	int pai;
} str_no;

//Constantes
#define tamanho 100
#define E 0
#define D 1
#define R -1

//Variáveis
struct str_no arvore[tamanho];
int lado,indice=0;
int opt=-1;
char pai, no;

//Protítipos das funções
void arvore_insere(int pai, char dado, int lado);
int arvore_procura(char dado);

//Procura nó
int arvore_procura(char dado){
	int i;
	if (indice != 0){
		for (i = 0; i<indice; i++){
			if (arvore[i].dado == dado) {
				return (i);
			}
		}
	}
	else {
		return (0);
	}
}

//Inserir nó
void arvore_insere(int pai, char dado, int lado){
	switch (lado){
		case E:
			arvore[pai].esquerda = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
			break;
		case D:
			arvore[pai].direita = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
			break;
		case R:
			arvore[indice].dado = dado;
			arvore[indice].pai = -1;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
			break; 
	}
}
int emOrdem(int n){
    if (n != -1){
    emOrdem(arvore[n].esquerda);
    printf(" |%d|", arvore[n].dado); //visita o nó atual
    emOrdem(arvore[n].direita);
    return (1);
    }
 return (0);
}



void menu(){
	
	
	printf("#################################################\n\n");
	printf("\tAluno: Ronildo Ferreira da Silva\n");
	printf("\tRA: 1963193-5\n");
	printf("\tProfessor: Pietro Martins de Oliveira\n");
	printf("\tDisciplina: Estrutura de Dados II\n\n");
	printf("#################################################\n\n");
}
//Função principal
int main(void){
	setlocale(LC_ALL, "portuguese");
	menu();
	
	printf("RA Normal -> |1| |9| |6| |3| |1| |9| |3| |5|\n\n");
	
	arvore_insere(-1,1,-1); //posicao 0 Pai
	arvore_insere(0,9,1); //posicao 1 filho do pai na posicao 0
	arvore_insere(1,6,0); // prosicao 2 filho do pai na posicao 1
	arvore_insere(2,3,0); //posicao 3 filho do pai na posicao 2
	arvore_insere(3,1,0); //posicao 4 filho do pai na posicao 3
	arvore_insere(1,9,1); //posicao 5 filho do pai na posicao 1
	arvore_insere(3,3,1); //posicao 6 filho do pai na posicao 1
	arvore_insere(6,5,1); //posicao 7 filho do pai na posicao 6
	
	printf("Em Ordem -> ");
	emOrdem(0);
	printf("\n\n#################################################\n\n");
	return(0);
	
	system("pause");
}


