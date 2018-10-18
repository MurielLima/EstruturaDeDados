#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N_ALFABETO 26
#define MAPEAMENTO(c) ((int)c-(int)'a')
#define true 1
#define false 0
typedef int bool;

struct No{
	struct No *filhos[N_ALFABETO];
	bool tipoRetornoTorF;
};

struct No *criaNo(){
	struct No *pNo	=	NULL;
	pNo=(struct No *) malloc(sizeof(struct No));
	if(pNo){
		int i;
		pNo->tipoRetornoTorF=false;
		for(i=0;i<N_ALFABETO;i++)
		pNo->filhos[i]=NULL;
	}
	return pNo;
}
 int mapearIndice (char c){
 return (( int ) c - ( int ) 'a');
} 
void inserir(struct No *raiz,const char *chave){
	int nivel;
	int comprimento	=	strlen(chave);
	int i;
	struct No *ponteiro	=	raiz;
	for(nivel= 0;nivel<comprimento;nivel++){
		i=mapearIndice(chave[nivel]);
		if(!ponteiro->filhos[i])
			ponteiro->filhos[i]=criaNo();
		ponteiro=ponteiro->filhos[i];
	}
	ponteiro->tipoRetornoTorF=true;
}
bool busca(struct No *raiz,const char *chave){
	int nivel;
	int comprimento	=	strlen(chave);
	int index;
	struct No *ponteiro = raiz;
	for(nivel=0;nivel<comprimento;nivel++){
		index=mapearIndice(chave[nivel]);
		if(!ponteiro->filhos[index])
			return false;
		ponteiro	=	ponteiro->filhos[index];
	}
	return (ponteiro!=NULL && ponteiro->tipoRetornoTorF);
}


void delete(struct No *raiz,const char *chave){
	int nivel;
	int comprimento	=	strlen(chave);
	int i;
	struct No *ponteiro	=	raiz;
	for(nivel= 0;nivel<comprimento;nivel++){
		i=mapearIndice(chave[nivel]);
		if(!ponteiro->filhos[i])
			return ;
		ponteiro=ponteiro->filhos[i];
	}
	ponteiro->tipoRetornoTorF=false;
}
int main(){
	char frase[]="o rato roeu a roupa do rei de roma e a rainha de raiva roeu o resto o rei entao ficou furioso e brigou com a rainha";
	int i,j,k,ant=0;
	
	struct No *raiz=criaNo();
	
	
	for(i=0;i<strlen(frase);i++){
		if(frase[i]==' '|| frase[i]=='\0'){
			char palavra[30];			
			for(j=ant,k=0;j<(i-1),k<(i-ant);j++,k++)
					palavra[k]=frase[j];	
			
			palavra[k]='\0';	
			inserir(raiz,palavra);
			ant=i+1;
			
		}
	}
	
	if(busca(raiz,"rato"))
		printf("\nDeu certo!");
		
	(delete(raiz,"rei"));
		(delete(raiz,"rainha"));
			(delete(raiz,"rato"));
				(delete(raiz,"entao"));
					(delete(raiz,"roeu"));
		
	if(!busca(raiz,"rato"))
	printf("\nExcluiu!");
	
}
