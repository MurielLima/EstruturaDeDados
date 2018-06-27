/*
======================================================================
===============FUNÇÕES DE ORDENAÇÃO===================================
======================================================================
*/
void heapSort(int *vet,int tam,dado *dados){
	t0=clock();
	int i, aux;
	for(i=(tam-1)/2;i>=0;i--){
		criaheap(vet,i,tam-1);
	}
	for(i=tam-1;i>=1;i--){
		aux=vet[0];
		vet[0]=vet[i];
		vet[i]=aux;
		criaheap(vet,0,i-1);
	}
	tf=clock();
	dados[0].tempo=tf-t0;
}
void criaheapSort(int *vet,int i, int f){
	int aux= vet[i];
	int j= i*2+1;
	while(j<=f){
		if(vet[j]<vet[j+1]){
			j++;
		}
	}
	if(aux<vet[j]){
		vet[i]=j;
		i=j;
		j=2*i+1;
	}else{
		j=f+1;
	}
	vet[i]=aux;
}
/*
======================================================================
======================================================================
======================================================================
*/
int *selection(int *vet,int tam){
	int i, menor, j, aux;
	for(i=0;i<tam;i++){
		menor=i;
		for(j=i+1;j<tam;j++){
			if(v[menor]>v[j]){
				menor = j;
			}
		}
		aux=v[i];
		v[i]=v[menor];
		v[menor]=aux;
	}
	return v;
}
