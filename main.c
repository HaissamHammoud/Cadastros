#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100


struct Aluno{
	int id;
	char nome[100];
	int data[3]; //dia , mes e ano no formato dd/mm/aa
	char cpf[11]; // cpf sem a presença de pontuação... apenas numeros
	//xxx.xxx.xxx-xx
	int situacao; // 1 -ativo   0 - inativo
	
};
typedef struct Aluno aluno;
struct Tabela{
	aluno cadastro[100];
	int quant ;//essa variavel sera responsavel por contar os cadastros
		
};
typedef struct Tabela tabela;

int main(){
	
	
	
	
	return 0;
}

aluno addAluno(aluno a){
	
	printf("\nEntre com o nome do aluno(a): ");
	gets(a.nome);
	printf("\nEntre com a data de nascimento:");
	printf("\ndia:");
	scanf("%d", &a.data[0]);
	printf("\nmes:");
	scanf("%d", &a.data[1]);
	printf("\nAno: ");
	scanf("%d", &a.data[2]);
	
	
		
	return a;
}
