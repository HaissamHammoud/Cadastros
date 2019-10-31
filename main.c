#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100
#define TAM 50

struct Aluno{
	int id;
	char nome[TAM];
	int data[3]; //dia , mes e ano no formato dd/mm/aa
	char cpf[11]; // cpf sem a presença de pontuação... apenas numeros
	//xxx.xxx.xxx-xx
	int situacao; // 1 -ativo   0 - inativo

};
typedef struct Aluno aluno;

// declarando as funções

void cadastrar(aluno a[],int pos);
void print_aluno(aluno a[], int pos);
void listar(aluno a[], int pos);
void pesquisa(aluno a[], int pos);
void atualizar(aluno a[], int pos);
/////////////////////////////////////////////

int main(){

	aluno registros[MAX];
	int pos = 0 , logico = 1, opc;

	while(logico){

		printf("Cadastro de Pessoas\n1 - Cadastrar\n2 - Listar\n3 - Pesquisar\n4 - Atualizar \n5 - Remover \n6 - Sair\n");


		scanf("%d", &opc);
		if(opc == 1){
			cadastrar(registros, pos);
			print_aluno(registros ,pos);
		pos++;
		}
		else if(opc ==2){
			listar(registros, pos);
		}
		else if(opc ==3){
			pesquisa(registros, pos);
		}
		else if(opc ==4){
				atualizar(registros, pos);

		}
		else if(opc ==5){

		}
		else if(opc ==6){
			logico = 0; // sai do programa
		}
		else{
			printf("Operação invalida");
			break;
		}
	}
	return 0;
}


//funcao que adiciopna um aluno na tabela
void cadastrar(aluno a[],int pos){
		char str[TAM];

	printf("Entre com o nome do aluno(a):");
	fgets(a[pos].nome, TAM , stdin);
	gets(a[pos].nome);
	printf("\n%s", a[pos].nome);

	printf("\nEntre com a data de nascimento:");
	printf("\nDia:");
	scanf("%d", &a[pos].data[0]);
	printf("%d", a[pos].data[0]);
	printf("\nMes:");
	scanf("%d", &a[pos].data[1]);
	printf("\nAno: ");
	scanf("%d", &a[pos].data[2]);



	do{
		printf("\nEntre com o cpf do aluno:");
		scanf("%s", a[pos].cpf);
		if(iscpf(a[pos].cpf)){

		}
		else{
			printf("\nEntre com o cpf do aluno:");
			scanf("%s", a[pos].cpf);
		}
	}while((iscpf(a[pos].cpf)) == 0);

	a[pos].id = pos;
	a[pos].situacao = 1;


}

void print_aluno(aluno a[], int pos){

	printf("\nNome: %s     id: %d ", a[pos].nome, a[pos].id);
	printf("\ndata de nasimento : %d/", a[pos].data[0]);
	printf("%d/", a[pos].data[1]);
	printf("%d\n", a[pos].data[2]);

	printf("CPF:%s\n\n", a[pos].cpf);
	getch;


}

//lista todos os alunos com cadastro ativo
void listar(aluno a[], int pos){
	int i  = 0;
	for(i = 0 ; i<pos; i++){
		if(a[i].situacao ==1 ){
			printf("aluno: %s , id: %d\n", a[i].nome, a[i].id);
		}
	}

}

//funcao que busca por um aluno especifico
void pesquisa(aluno a[], int pos){
	char nome[50];
	int i ;
	printf("\nEntre com o nome do usuario: ");
	fgets(nome, TAM , stdin);
	gets(nome);

	for(i = 0 ; i<pos ; i++){
		if(strcmp(nome,a[i].nome)==0){
			print_aluno(a,i);
		}
	}
}

//verifica se o cpf é ou não é um cpf
int iscpf(char cpf[]){
	//retorna 1 se for um cpf e 0 caso nao seja
	return 1;
}

//atualiza o cadastro feito pelo aluno
void atualizar(aluno a[], int pos){
	int id;

	printf("entre com o id");
	scanf("%d", &id);

	if(id < pos){
		cadastrar(a, id);
	}
	else{
		printf("Conta inexestente...");
	}
}
