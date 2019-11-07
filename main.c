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
int remover(aluno a[], int pos);
/////////////////////////////////////////////

int main(){

	aluno registros[MAX];
	int pos = 0 , logico = 1, opc;

	while(logico){

		printf("\nCadastro de Pessoas\n1 - Cadastrar\n2 - Listar\n3 - Pesquisar\n4 - Atualizar \n5 - Remover \n6 - Sair\n\n");


		scanf("%d", &opc);
		if(opc == 1){
			if(pos<= MAX){
			
			cadastrar(registros, pos);
			print_aluno(registros ,pos);
		pos++;
			}
			else{
				printf("\nLimite de alunos cadastrados atingido!!");
			}
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
				remover(registros, pos);
		}
		else if(opc ==6){
			logico = 0; // sai do programa
		}
		else{
			printf("Operação invalida\n");
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

	printf("\n\nEntre com a data de nascimento:");
	printf("\nDia:");
	scanf("%d", &a[pos].data[0]);
	//printf("%d", a[pos].data[0]);
	printf("\nMes:");
	scanf("%d", &a[pos].data[1]);
	printf("Ano: ");
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

			printf("  id: %4d  nome: %30s  cpf : %15s \n", a[i].id,a[i].nome, a[i].cpf);
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
		if(strcmp(nome,a[i].nome)==0 && a[i].situacao ==1){
				print_aluno(a,i);
		}
	}
}

//verifica se o cpf é ou não é um cpf
int iscpf(char cpf[]){
	//retorna 1 se for um cpf e 0 caso nao seja
	if(strlen(cpf) == 11 ){
		return 1;
	}
	else{
	printf("\nCPF invalido , verifique se digitou o cpf corretamente\n");
	return 0;
	}
}

//atualiza o cadastro feito pelo aluno Ou reativar contas removidas
void atualizar(aluno a[], int pos){
		int id;
		int Decisao;

	printf("Entre com o id que desejas atualizar: ");
	scanf("%d", &id);

	if(id < pos && a[id].situacao ==1){
		cadastrar(a, id);
	}
	// Verifica se a conta já estava removida
	else if(id < pos && a[id].situacao == 0){
		printf("Desejas Reativar essa conta?\n");
		printf("(1) SIM \t (2) Nao\n");
		scanf("%d", &Decisao);

		switch(Decisao){

			case 1:
				printf("A conta de %s foi reativada com sucesso \n\n", a[id].nome);
				a[id].situacao = 1;
			break;

			case 2:

			break;

			default:
				printf("\nOpcao invalida");
			break;
		}
	}
	else{
		printf("conta Inexistente");
	}
}
int remover(aluno a[], int pos){
	int id;

	printf("Entre com o id que desejas remover: ");
	scanf("%d", &id);

	printf("\n");
	if(id < pos){
		printf("A conta de %s foi removida com sucesso \n\n", a[id].nome);
		return a[id].situacao = 0;
	}
	else{
		printf("conta inexestente...\n\n");
		return 1;
	}
}
