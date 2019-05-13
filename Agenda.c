#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* Nome: Vinicius de Andrade Silva   -    Ra: 221170509 */

typedef struct{
	char nome[50];
	char tel[15];
	char email[50];
	char RG[16];
	char CPF[20];
	char sangue[4];
	char convenio[15];
	char religiao[10];
	char cidade[20];
	char estado[2];
	
}contato;


typedef struct{
	contato contatos[100];
	int total;
}agenda;

void apagaEnter(char *str){
	int i=0;
	while(str[i] != '\0' && str[i] != '\n' )
	    i++;
	str[i] = '\0';
}

contato criaContato(){
	contato cont;
	
	puts("Nome:");
	fflush(stdin);
	fgets(cont.nome, 50, stdin);
	apagaEnter(cont.nome);
	
	puts("Telefone:");
	fflush(stdin);
	fgets(cont.tel, 20, stdin);
	apagaEnter(cont.tel);
	
	puts("Email:");
	fflush(stdin);
	fgets(cont.email, 50, stdin);
	apagaEnter(cont.email);
		
	puts("RG:");
	fflush(stdin);
	fgets(cont.RG, 16, stdin);
	apagaEnter(cont.RG);
	
	puts("CPF:");
	fflush(stdin);
	fgets(cont.CPF, 20, stdin);
	apagaEnter(cont.CPF);
	
	puts("Tipo sanguineo:");
	fflush(stdin);
	fgets(cont.sangue, 4, stdin);
	apagaEnter(cont.sangue);
	
	puts("Convênio:");
	fflush(stdin);
	fgets(cont.convenio, 15, stdin);
	apagaEnter(cont.convenio);
	
	puts("Religião:");
	fflush(stdin);
	fgets(cont.religiao, 15, stdin);
	apagaEnter(cont.religiao);
	
	puts("Cidade:");
	fflush(stdin);
	fgets(cont.cidade, 20, stdin);
	apagaEnter(cont.cidade);
	
	puts("Estado:");
	fflush(stdin);
	fgets(cont.estado, 3, stdin);
	apagaEnter(cont.estado);
	
	return cont;
}

void insere(agenda *a, contato c){
	a->contatos[a->total] = c;
	a->total++;
}

void listaContato(contato c){
	printf("Nome:              %s\n", c.nome);
	printf("Tel:               %s\n", c.tel);
	printf("Email:             %s\n", c.email);
	printf("RG:                %s\n", c.RG);
	printf("CPF:               %s\n", c.CPF);
	printf("Tipo sanguineo:    %s\n", c.sangue);
	printf("Convênio:          %s\n", c.convenio);
	printf("Religião:          %s\n", c.religiao);
	printf("Cidade:            %s\n", c.cidade);
	printf("Estado:            %s\n", c.estado);
	puts("");
}

void alteraContato(agenda *a, int pos, int opcao){
	system("cls");
	if(opcao == 1){
		puts("Novo nome: ");
		fflush(stdin);
		fgets(a->contatos[pos].nome, 50, stdin);
		apagaEnter(a->contatos[pos].nome);
	}
	else if(opcao == 2){
		puts("Novo telefone: ");
		fflush(stdin);
		fgets(a->contatos[pos].tel, 15, stdin);
		apagaEnter(a->contatos[pos].tel);
	}
	else if(opcao == 3){
		puts("Novo convênio: ");
		fflush(stdin);
		fgets(a->contatos[pos].convenio, 15, stdin);
		apagaEnter(a->contatos[pos].convenio);
	}
	else if(opcao == 4){
		puts("Nova cidade: ");
		fflush(stdin);
		fgets(a->contatos[pos].cidade, 20, stdin);
		apagaEnter(a->contatos[pos].cidade);
	}
	else if(opcao == 5){
		puts("Novo estado: ");
		fflush(stdin);
		fgets(a->contatos[pos].estado, 2, stdin);
		apagaEnter(a->contatos[pos].estado);
	}
	else if(opcao == 6){
		puts("Novo email: ");
		fflush(stdin);
		fgets(a->contatos[pos].email, 50, stdin);
		apagaEnter(a->contatos[pos].email);
	}
	
}

void listaAgenda(const agenda *a){
	int i;
	for(i=0; i<a->total; i++){
		listaContato(a->contatos[i]);
	}		
}

void menu(){
	puts("          Agenda Eletrônica        ");
	printf("(1) Adicionar novo contato\n");
	printf("(2) Procurar contato\n");
	printf("(3) Alterar contato\n");
	printf("(4) Listar todos os contatos\n");
	printf("(5) Excluir\n");
	printf("(6) Salvar e Sair\n");
	puts("");
}

int comparaNome(contato a, char vetor[]){
	return strcmp(a.nome, vetor);
}

int comparaRG(contato a, char vetor[]){
	return strcmp(a.RG, vetor);
}

int busca(const agenda* a, char vetor[], int opc){
	int i;

	if(opc == 1){
		for(i=0; i<a->total; i++){	
			if(comparaNome(a->contatos[i], vetor) == 0){
				return i;
			}
		}
		return -1;
	}else{
		for(i=0; i<a->total; i++){	
			if(comparaRG(a->contatos[i], vetor) == 0){
			return i;
			}
		}
	return -1;	
	}

}

void gravaTexto(agenda *a){
	FILE *fp;
	fp = fopen("contatos.txt", "w");
	
	int i;
	for(i=0; i<a->total; i++){
		fprintf(fp, "%d\n", a->total);
		fprintf(fp, "%s\n", a->contatos[i].nome);
		fprintf(fp, "%s\n", a->contatos[i].tel);
		fprintf(fp, "%s\n", a->contatos[i].email);
		fprintf(fp, "%s\n", a->contatos[i].RG);
		fprintf(fp, "%s\n", a->contatos[i].CPF);
		fprintf(fp, "%s\n", a->contatos[i].sangue);
		fprintf(fp, "%s\n", a->contatos[i].convenio);
		fprintf(fp, "%s\n", a->contatos[i].religiao);
		fprintf(fp, "%s\n", a->contatos[i].cidade);
		fprintf(fp, "%s\n", a->contatos[i].estado);
	}	
	fclose(fp);
}

void leTexto(const char* arq, agenda *a){
	int i = 0;
	char bug;
	int id;
	
	FILE *fp2 = fopen(arq, "r");
		for(i=0; i<2; i++){
			fscanf(fp2, "%d\n", &a->total);		
			fgets(a->contatos[i].nome, 50, fp2);
			a->contatos[i].nome[strlen(a->contatos[i].nome)-1] = 0;
			fscanf(fp2, "%s\n", a->contatos[i].tel);
			fscanf(fp2, "%s\n", a->contatos[i].email);
			fscanf(fp2, "%s\n", a->contatos[i].RG);
			fscanf(fp2, "%s\n", a->contatos[i].CPF);
			fscanf(fp2, "%s\n", a->contatos[i].sangue);
			fscanf(fp2, "%s\n", a->contatos[i].convenio);
			fscanf(fp2, "%s\n", a->contatos[i].religiao);
			fscanf(fp2, "%s\n", a->contatos[i].cidade);
			fscanf(fp2, "%s\n", a->contatos[i].estado);
			i++;
		}
	fclose(fp2);
	puts("Leitura feita e armazenada!");
}

void excluiContato(agenda *a, int i){
	contato contVazio;
	a->contatos[i].nome[0] = '\0';
	a->contatos[i].tel[0] = '\0';
	a->contatos[i].email[0] = '\0';
	a->contatos[i].RG[0] ='\0';
	a->contatos[i].CPF[0] = '\0';
	a->contatos[i].sangue[0] ='\0';
	a->contatos[i].convenio[0] = '\0';
	a->contatos[i].religiao[0] = '\0';
	a->contatos[i].cidade[0] = '\0';
	a->contatos[i].estado[0] = '\0';
	a->contatos[i] = a->contatos[i+1];
	a->contatos[i+1] = contVazio;
	a->total--;
}


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	agenda a;
	a.total = 0;
	int i, op, op2, qtd, tel, idc;
	char vetor[50];
	char nomedoarq[50];

	do{
	menu();
	scanf("%d", &op);
		switch(op){
			case 1:
				system("cls");
				puts("Quantos contatos deseja adicionar?");
				scanf("%d", &qtd);
				fflush(stdin);
				for(i=0; i<qtd; i++){
					system("cls");	
					insere(&a, criaContato());
				}
				gravaTexto(&a);
				system("cls");	
				break;
				
			case 2:
				system("cls");
				puts("Procurar por (1) nome ou (2) RG?");
				scanf("%d", &op2);
				
				if( op2 == 1){
					puts("Nome a ser procurado: ");
					fflush(stdin);
					fgets(vetor, 50, stdin);
					apagaEnter(vetor);
					system("cls");
					idc = busca(&a, vetor, 1);	
				}else{
					puts("RG a ser procurado: ");
					fflush(stdin);
					fgets(vetor, 50, stdin);
					apagaEnter(vetor);
					idc = busca(&a, vetor, 2);
				}
			
				if(idc == -1){
					puts("Não encontrado!");
					puts("");
				}else{
					puts("Encontrado!");
					puts("");
					listaContato(a.contatos[idc]);
				}
				break;
			
			case 3:
				system("cls");
				puts("============Alteração de contato============");
				puts("");
				puts("Nome do contato a ser alterado");
				fflush(stdin);
				fgets(vetor, 50, stdin);
				apagaEnter(vetor);
				idc = busca(&a, vetor, 1);
				puts("");
				listaContato(a.contatos[idc]);
				printf("O que deseja alterar? \n (1) Nome \n (2) Telefone \n (3) Convênio \n (4) Cidade \n (5) Estado \n (6) Email \n");
				scanf("%d", &op2);
				alteraContato(&a, idc, op2);	
				puts("");
				puts("");
				system("cls");
				puts("Contato alterado!");
				puts("");
				listaContato(a.contatos[idc]);
				break;
	
			case 4:
				system("cls");
				puts("=============Lista de contatos=============");
				puts("");
				listaAgenda(&a);	
				printf("Total de contatos: %d\n\n", a.total);
				break;
					
			case 5:
				system("cls");
				puts("Nome do contato a ser excluído");
				fflush(stdin);
				fgets(vetor, 50, stdin);
				apagaEnter(vetor);
				idc = busca(&a, vetor, 1);
				excluiContato(&a, idc);
				system("cls");
				break;
				
			case 6:
				gravaTexto(&a);
				exit(0);
				break;
			default:
				system("cls");
				break;
		}
	}while(op!=6);

	return 0;
}
