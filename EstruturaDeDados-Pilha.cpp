#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 10
int cont=0;

struct prato{
	int id;
	char nome[30];
}typedef Prato;

Prato vetor[TAM];

int push(Prato vet){
	if(cont>=TAM){
		printf("Sua pilha está cheia!");
		return 0;
	}
	vetor[cont]=vet;
	//printf("id: %i\n",vetor[cont].id);
	//printf("nome:%s\n",p[cont].nome);
	cont++;
	return 1;
}
int pop(){
	if(!cont){
		printf("Sua pilha está vazia!");
		return -1;
	}
	cont--;
	return 1;
}
Prato top(){
	cont--;
	printf("id: %d \n",vetor[cont].id);
	printf("nome:%s\n",vetor[cont].nome);
	cont++;
	return vetor[cont--];
}
int main(){
	int i;
	Prato Alunos[TAM];
	Alunos[0].id=1;
	strcpy(Alunos[0].nome,"Alfred");
	push(Alunos[0]);
	Alunos[1].id=2;
	strcpy(Alunos[1].nome,"Bhaskara");
	push(Alunos[1]);
	push(Alunos[0]);
	top();
	printf("========Visao da pilha=========\n");
	for(i=0;i<=cont;i++){
		printf("id: %d \n",vetor[i].id);
		printf("nome:%s\n",vetor[i].nome);
	}
	printf("===========================\n");
	system("pause");
}

