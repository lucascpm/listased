#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "L_SEQ.h"



int main(){
	int i = 0;
	tLista lista;
	tLista listaPar;
	tLista listaImpar;
	tLista listaConcatenada;
	cria(&lista);
	cria(&listaPar);
	cria(&listaImpar);
	cria(&listaConcatenada);
	
	//Salvando Elementos na Lista
	for(i = 1; i <= 7 ; i++) {
		addElemento(&lista, i, (i+100));
	}
	

	//remove o elemento da posição desejada
	removeElemento(&lista, 3);
	
	//Remove o elemento com o conteúdo escolhido
	removeElementoDado(&lista, 101);

	//Altera o valor do elemento na posição escolhida
	alteraValor(&lista, 4, 777);
	
	//Divide a lista em duas
	divideListaParImpar(lista, &listaPar, &listaImpar);
	
	//Concatena duas listas
	concatenaLista(listaPar, listaImpar, &listaConcatenada);
	
		printf("Lista criada:\n");
	toString(lista);
	printf("\n--------------------\n\n");
	printf("Lista de Elementos Pares:\n");
	toString(listaPar);
	printf("\n--------------------\n\n");
	printf("Lista de Elementos Impares:\n");
	toString(listaImpar);
	printf("\n--------------------\n\n");
	printf("Lista Concatenada:\n");
	toString(listaConcatenada);
	
	return 0;
}
