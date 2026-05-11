#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "heap.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao, valor;
    int *minheap;

    printf("|Você executou uma minheap|\n");
    
    minheap = malloc(100*sizeof(int));

    while(1){
        printf("\n(1) Inserir um elemento.\n");
        printf("(2) Remover um elemento.\n");
        printf("(3) Imprimir a minheap.\n");
        printf("(4) Sair\n");
        printf("Escolha uma opção: ");


        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(minheap, valor);
                break;
            
            case 2:
                if(totalElementos != 0){
                    Remover(minheap);
                    printf("\n");
                }
                else{
                    printf("\nA minheap está vazia, insira um elemento primeiro!\n");
                }
                break;

            case 3:
                printf("\nMinheap (vetor): ");
                imprimirHeap1(minheap);
                printf("\n\nMinheap (árvore): ");
                imprimirHeap2(minheap, 0);
                printf("\n");
                break;

            case 4:
                printf("\nSaindo do programa...\n");
                free(minheap);
                Sleep(1000);
                return 0;
        }
    }
}