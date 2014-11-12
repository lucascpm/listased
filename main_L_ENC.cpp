#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "windows.h"
#include "L_ENC.h"
#include <cstddef>



int main(){
	int i = 0;
	tListaEnc lista;
	tListaEnc listaPar;
	tListaEnc listaImpar;
	tListaEnc listaConcatenada;
	cria(&lista);
	cria(&listaPar);
	cria(&listaImpar);
	cria(&listaConcatenada);
	
	//Salvando Elementos na Lista
	for(i = 1; i <= 7 ; i++) {
		addElemento(&lista, i, (i+100));
	}
	
	//Adiciona um elemento no meio da lista
	addElemento(&lista, 3, 999);
	
	//Altera o valor do elemento da posição escolhida
	alteraValor(&lista, 2, 918);
	
	//Remove o elemento com o conteúdo escolhido
	removeElementoDado(&lista, 106);
	
	//Remove o elemento da posição desejada
	removeElemento(&lista, 1);
	
	//Divide a lista em duas
	divideListaParImpar(lista, &listaPar, &listaImpar);
	
	//Concatena duas liastas
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

	
	
	
	
	
	
	

	/*
	removeElemento(&lista, 3);
	removeElementoDado(&lista, 101);

	alteraValor(&lista, 4, 777);
	
	divideListaParImpar(lista, &listaPar, &listaImpar);
	toString(listaPar);
	printf("\n\n\n");
	toString(listaImpar);
	printf("\n\n\n");
	
	concatenaLista(listaPar, listaImpar, &listaConcatenada);
	toString(listaConcatenada);
	*/
	
	return 0;
}
