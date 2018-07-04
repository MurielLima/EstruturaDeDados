#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QTD 8

struct dado{
	char nome[30];
	double tempo;
};

//Aloca o vetor de numeros
int  *alocvet(long int tam);
/*
   Recebe um Vetor e um número n.
   Gera n números pseudo aleatórios e insere cada um no Vetor.
*/
void incluiElementos(int* vetor,int* vetor1,int* vetor2,int* vetor3,int* vetor4,int* vetor5,int* vetor6,int* vetor7,  long int n);
// Salva a em disco. Somente entradas preenchidas.
/*
Nome do ordenador: teste
Tempo demorado: XX
*/
int salvar(char *filename, dado *v,int n);


void heapSort(int v[], long int n,dado *dados);
void criaheap(int *v,long int m);
void peneira (int m, int *v);

void selectionSort(int vet[], long int tam,dado *dados);

void mergeSort(int vet[], int tam, dado *dados);
void mergeDiv(int *V, long int inicio, long int fim);
void merge(int *V, long int inicio, long int meio, long int fim);

void radixSort(int *V, long int tam, dado *dados);

int main(){
	srand(time(NULL));

	int *Vet0,*Vet1,*Vet2,*Vet3,*Vet4,*Vet5,*Vet6,*Vet7;
	long int i;
	long int n,tam=0;
	struct dado dados[QTD];
	strcpy(dados[0].nome,"Insertion");
	strcpy(dados[1].nome,"Shel");
	strcpy(dados[2].nome,"Selection");
	strcpy(dados[3].nome,"Heap");

	strcpy(dados[4].nome,"Quick");
	strcpy(dados[5].nome,"Bubble");
	strcpy(dados[6].nome,"Merge");
	strcpy(dados[7].nome,"Radix");
	for(i=0;i<QTD;i++){
		dados[i].tempo=0;
	}

/*Selecione o temanho do vetor*/
   printf ("*** Ordenacao ***\n\n");
      printf ("Selecione o tamanho do vetor(100000-1)(100000-2)(1000000-3): ");
      scanf ("%d", &n);
      switch(n){
      	case 1:tam=10000;break;
      	case 2:tam=100000;break;
      	case 3:tam=1000000;break;
      	case 4:tam=10;break;
      	default: printf ("Nao foi possivel criar vetor\n");break;
	  }
	  Vet0 = alocvet(tam);
	  Vet1 = alocvet(tam);
	  Vet2 = alocvet(tam);
	  Vet3 = alocvet(tam);
	  Vet4 = alocvet(tam);
	  Vet5 = alocvet(tam);
	  Vet6 = alocvet(tam);
	  Vet7 = alocvet(tam);
	  
	  
	  
	  
	  
	  incluiElementos(Vet0,Vet1,Vet2,Vet3,Vet4,Vet5,Vet6,Vet7,tam);
	  
	  heapSort(Vet0,tam,dados);
	  selectionSort(Vet1,tam,dados);
	  mergeSort(Vet6, tam, dados);
    	  radixSort(Vet7, tam, dados);

	  
	salvar("C:\\Engenharia-de-Software\\Ordenacao3.txt",dados,n);
}
/*
======================================================================
===============FUNÇÕES DE ORDENAÇÃO===================================
======================================================================
*/
void peneira (int m, int *v)
{ 
   int p = 1, f = 2, t = v[1];
   while (f <= m) {
      if (f < m && v[f] < v[f+1])  ++f;
      if (t >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = t;
}
void heapSort(int v[], long int n,dado *dados){
	printf("\nIniciando HeapSort - Aguarde...\n");
	clock_t t0,tf;
	t0=clock();
   long int m,aux;
   criaheap (v, n);
   for (m = n; m >= 2; --m) {
      
       aux=v[1];
         v[1]=v[m];
         v[m]=aux;
      peneira (m-1, v);
   }

	tf=clock();
	dados[3].tempo=((tf-t0)/(CLOCKS_PER_SEC/1000));
	printf("%f\n",dados[3].tempo);
	
}
void criaheap(int *v,long int m){
	
long int k,aux; 
   for (k = 1; k < m; ++k) {                   
      // v[1..k] é um heap
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
                // 6
         aux=v[f/2];
         v[f/2]=v[f];
         v[f]=aux;
         f /= 2; 
}
}
}
void selectionSort(int vet[],long int tam,dado *dados){
	printf("\nIniciando SelectionSort - Aguarde...\n");
	clock_t t0,tf;
	t0=clock();
	long int i,
		j,
		menor,
		aux;
	
	for(i=0;i<tam;i++){
		menor = i;
		for(j=i+1;j<tam;j++){
			if(vet[menor]>vet[j]){
				menor=j;
			}
		}
		aux=vet[i];
		vet[i]=vet[menor];
		vet[menor]=aux;
	}
	tf=clock();
	dados[2].tempo=((tf-t0)/(CLOCKS_PER_SEC/1000));
	printf("%f\n",dados[2].tempo);
	
}
/*==============Inicio MergeSort=============================*/

void mergeSort(int vet[], int tam, dado *dados) {
    printf("\nIniciando MergeSort - Aguarde...\n");
    clock_t t0, tf;
    t0 = clock();
    mergeDiv(vet, 0, tam - 1);
    tf = clock();
    dados[6].tempo = ((tf - t0) / (CLOCKS_PER_SEC / 1000));
    printf("%f\n", dados[6].tempo);
}

void mergeDiv(int *V, long int inicio, long int fim) {
    long int meio;
    if (inicio < fim) {
        meio = floor((inicio + fim) / 2);
        mergeDiv(V, inicio, meio);
        mergeDiv(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
}

void merge(int *V, long int inicio, long int meio, long int fim) {
    int *temp;
    long int p1, p2, tamanho, i, j, k;
    long int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc(tamanho * sizeof (int));
    if (temp != NULL) {
        for (int i = 0; i < tamanho; i++) {
            if (!fim1 && fim2) {
                if (V[p1] < V[p2]) {
                    temp[i] = V[p1++];
                } else {
                    temp[i] = V[p2++];
                }
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            } else {
                if (!fim1) temp[i] = V[p1++];
                else temp[i] = V[p2++];
            }
        }
        for (int j = 0; j < tamanho; j++) {
            V[k] = temp[j];
        }
        free(temp);
    }
}
/*==============Fim MergeSort=============================*/


void radixSort(int *V, long int tam, dado *dados) {
    long int i, exp = 1, m = 0;
    int bucket[tam], temp[tam];
    printf("\nIniciando radixSort - Aguarde...\n");
    clock_t t0, tf;
    t0 = clock();
    for (i = 0; i < tam; i++) {
        if (V[i] > m) {
            m = V[i];
        }
    }

    while ((m / exp) > 0) {
        for (i = 0; i < tam; i++) {
            bucket[i] = 0;
        }
        for (i = 0; i < tam; i++) {
            bucket[(V[i] / exp) % 10]++;
        }
        for (i = 1; i < tam; i++) {
            bucket[i] += bucket[i - 1];
        }
        for (i = (tam - 1); i >= 0; i--) {
            temp[--bucket[(V[i] / exp) % 10]] = V[i];
        }
        for (i = 0; i < tam; i++) {
            V[i] = temp[i];
        }
        exp *= 10;
    }
    tf = clock();
    dados[7].tempo = ((tf - t0) / (CLOCKS_PER_SEC / 1000));
    printf("%f\n", dados[7].tempo);
}

/*
======================================================================
======================================================================
======================================================================
*/

/*
======================================================================
===============FUNÇÕES DE ORGANIZAÇÃO=================================
======================================================================
*/
//Aloca o vetor de numeros
int  *alocvet( long int tam){
    int *v;
    v=(int *)malloc(tam*sizeof(int));
    if(v==NULL){
    	return NULL;
	}
    return v;
}
/*
   Recebe um Vetor e um número n.
   Gera n números pseudo aleatórios e insere cada um no Vetor.
*/
void incluiElementos(int* vetor,int* vetor1,int* vetor2,int* vetor3,int* vetor4,int* vetor5,int* vetor6,int* vetor7,  long int n) {
    long int i;
   
   for (i = 0; i < n; i++) {
      vetor[i] = vetor1[i] = vetor2[i] = vetor2[i] = vetor3[i] = vetor4[i] = vetor5[i] = vetor6[i] = vetor7[i] = rand() % 999;
      
   }
}

// Salva a em disco. Somente entradas preenchidas.
/*
Nome do ordenador: teste
Tempo demorado: XX
*/
int salvar(char *filename, dado *v,int n) {
   FILE *fp;
   int i;
   fp=fopen(filename, "w");
   fprintf(fp, "Tipo de ordenacao: %d\n",n);
   if (fp==NULL) return -1;
   
   for(i=0; i<QTD; i++) 

     fprintf(fp, "Nome do ordenador: %s\n Tempo demorado: %lf\n",v[i].nome,v[i].tempo);

   fclose(fp);
   return 0;    
}

