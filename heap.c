#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int totalElementos = 0;

int indiceFilhoDir(int x) {
	int indice = (2* x) + 2;
	if (x>=totalElementos || indice>=totalElementos)
		return -1;
	else
		return indice;
}

int indiceFilhoEsq(int x) {
	int indice = (2* x) + 1;
	if (x>=totalElementos || indice>=totalElementos)
		return -1;
	else
		return indice;
}

int indicePai(int x) {
	int indice = (x-1)/2;
	if (indice < 0 || x >= totalElementos)
		return -1;
	else
		return indice;
}

void AjustarSubindo(int *heap, int pos) {
	if (pos != -1) { //NULL
		int pai = indicePai(pos);
		if (pai != -1) {
			if (heap[pos] < heap[pai]) { //nó menor que pai?
				int aux = heap[pos];
				heap[pos] = heap[pai];
				heap[pai] = aux;
				AjustarSubindo(heap, pai);
			}
		}
	}
}

void inserir(int *heap, int x) {
	heap[totalElementos] = x;
	totalElementos++;
	AjustarSubindo (heap, totalElementos - 1);
}

void AjustarDescendo(int *heap, int pos) {
	if (pos != -1 && indiceFilhoEsq(pos) != -1) { //Descobrido o menor filho
		int indiceMenorFilho = indiceFilhoEsq(pos);
		if (indiceFilhoDir(pos) != -1 && heap[indiceFilhoDir(pos)] < heap[indiceMenorFilho]) 
			indiceMenorFilho = indiceFilhoDir(pos);
		if (heap[indiceMenorFilho] < heap[pos]) { //Verificando se existe filho menor que o nó atual
			int aux = heap[pos];
			heap[pos] = heap[indiceMenorFilho];
			heap[indiceMenorFilho] = aux;
			AjustarDescendo(heap, indiceMenorFilho);
		}
	}
}

int Remover(int *heap) {
	if (totalElementos == 0)
		return -1;
	else {
			int retorno = heap[0];
			heap[0] = heap[totalElementos - 1];
			totalElementos--;
			AjustarDescendo(heap, 0);
			printf("\nElemento removido: %d", retorno);
			return retorno;
	}
}

void imprimirHeap1(int *heap) {
	for(int i = 0; i < totalElementos; i++) {
		printf("%d ", heap[i]);
	}
}

void imprimirHeap2(int *heap, int x) {
	if(totalElementos == 0 || x == -1 || x >=totalElementos) {
		printf("(-1)");
		return;
	}
	
	printf("(%d", heap[x]);
	
	imprimirHeap2(heap, indiceFilhoEsq(x));
	imprimirHeap2(heap, indiceFilhoDir(x));
	
	printf(")");
}