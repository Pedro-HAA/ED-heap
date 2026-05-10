#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

extern int totalElementos;

int indiceFilhoDir(int x);

int indiceFilhoEsq(int x);

int indicePai(int x);

void AjustarSubindo(int *heap, int pos);

void inserir(int *heap, int x);

void AjustarDescendo(int *heap, int pos);

int Remover(int *heap);

void imprimirHeap1(int *heap);

void imprimirHeap2(int *heap, int x);

#endif