//Fazer uma aplicação em C que leia os dados de um arquivo contendo as informações sobre pratos culinários 
//( nome, numero de calorias e dificuldade de preparo{fácil, médio e difícil} )
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Prato{
	char nome[50];
	char dificuldade[10];
	int numCalorias;
	struct Prato *proximo;
};

void salvarPrato(struct Prato prato,  FILE* file){	
	if(file!= NULL){
		fprintf(file, "%s\n %d\n %s\n", prato.nome,prato.numCalorias, prato.dificuldade);
	}
}

pratoCalorico(FILE *file){
	struct Prato prato;
	struct Prato *maior;
	
	maior = malloc(sizeof(struct Prato));
	
	strcpy(maior->nome,prato.nome);
	maior->numCalorias = prato.numCalorias;
	strcpy(maior->dificuldade, prato.dificuldade);
	
	if(file != NULL){
		while(fscanf(file,"%s",prato.nome)!=EOF){
			
			fscanf(file,"%d",&prato.numCalorias);
			fscanf(file,"%s", prato.dificuldade);
			
			while((maior != NULL) && (maior->numCalorias < prato.numCalorias)){
				strcpy(maior->nome,prato.nome);
				maior->numCalorias = prato.numCalorias;
				strcpy(maior->dificuldade,prato.dificuldade);
			}
			printf("arquivo copiado");
		}
	}
	else{
		printf("\nArquivo nulo!");
	}
	
	while(maior != NULL){
		printf("Prato: %s\n Calorias: %d\n Dificuldade: %s\n\n", maior->nome, maior->numCalorias, maior->dificuldade);
	}
}	

int main(){
	FILE *file = NULL;
	struct Prato prato;
	int op;
	
	do{
		printf("\n======== Menu =======\n");
		printf("1-Cadastrar Prato \n");
		printf("2-Listar o mais calorico \n");
		printf("0-Sair \n");
		printf("Escolha:");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("Nome do prato:");
				scanf("%s", prato.nome);
				
				printf("Informe o numero de calorias:");
				scanf("%d", &prato.numCalorias);
				
				printf("Informe a dificuldade (facil, medio e dificil):");
				scanf("%s", prato.dificuldade);
				
				file = fopen("pratos.txt","a");
				salvarPrato(prato, file);
				fclose(file);
				break;
			case 2:
				file = fopen("pratos.txt", "r");
				pratoCalorico(file);
				fclose(file);
				break;
			case 0:
				break;
		}
	}while(op!=0);
}
