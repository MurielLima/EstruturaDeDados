#include<stdio.h>
int buscaSeq(int tamanho,int *vet,int p){
	int i;
	for(i=0;i<tamanho;i++){
		if(vet[i]==p){
			return vet[i];
		}else if(vet[i]>p){
			return -1;
		}
	}
	return -1;
}
