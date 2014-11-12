#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "windows.h"
#include "L_SEQ.h"
#include "L_ENC.h"

int main(void){
		srand(time(NULL));
		
		int n = 0;
		int i = 0;

		int continuar = 1;
		int menuSeq = 1;
		int menuEnc = 1;
		int elemento = 0;
		int posicao = 0;
		
		tLista listaSeq;
		tLista listaParSeq;
		tLista listaImparSeq;
		tLista listaConcatenadaSeq;
		cria(&listaSeq);
		cria(&listaParSeq);
		cria(&listaImparSeq);
		cria(&listaConcatenadaSeq);
		
		tListaEnc listaEnc;
		tListaEnc listaParEnc;
		tListaEnc listaImparEnc;
		tListaEnc listaConcatenadaEnc;
		cria(&listaEnc);
		cria(&listaParEnc);
		cria(&listaImparEnc);
		cria(&listaConcatenadaEnc);

		do
		{
			printf("\n\tTrabalho 1 - Listas\n\n");
			printf("1. Menu Lista Sequencial\n");
			printf("2. Menu Lista Encadeada\n");
			
			
			printf("0. Sair\n");

			scanf("%d", &continuar);
			system("cls || clear");

			switch(continuar)
			{
				case 1:
					
					do{
						printf("\n\n\tLista Sequencial\n\n");
						printf(" 1. Adicionar Elemento\n\n");
						
						printf(" Remover Elemento\n");
						printf("  2. Escolher Posicao\n");
						printf("  3. Escolher Conteudo\n\n");
						
						printf(" 4. Alterar Elemento\n\n");
						
						printf(" Pesquisar Elemento\n");
						printf("  5. Pesquisar por Posicao\n");
						printf("  6. Pesquisar por Conteudo\n\n");
						
						printf(" 7. Separar Lista em outras Duas Listas (E EXIBI-LAS):\n  -Elementos Pares\n  -Elementos Impares\n\n");
						
						printf(" 8. Concatenar as Listas de Elementos Pares e Impares (E EXIBI-LA)\n\n");
						
						printf("98. Adiciona 10 elementos aleatorios na Lista\n");
						printf("99. Exibe Conteudo da Lista\n");
						printf("0. Voltar\n");
			
						scanf("%d", &menuSeq);
						system("cls || clear");
					
						switch(menuSeq)
						{
							case 1:
								printf("Informe a Posicao: ");
								scanf("%d", &posicao);
								printf("Informe o Valor: ");
								scanf("%d", &elemento);
								system("cls || clear");
								//Adiciona um elemento na posicao desejada
								if(getTamanho(listaSeq) == 0){
									addElemento(&listaSeq, 1, elemento);
									printf("Elemento adicionaco com sucesso na posicao 1.");
									break;
								}else if(posicao > getTamanho(listaSeq)){
									printf("Elemento adicionaco com sucesso na posicao %d.", getTamanho(listaSeq)+1);
									addElemento(&listaSeq, getTamanho(listaSeq)+1, elemento);
									break;
								}
								
								printf("Elemento adicionaco com sucesso na posicao %d.", posicao);
								addElemento(&listaSeq, posicao, elemento);
								break;
								
							case 2:
								//Remove o elemento da posicao escolhida
								printf("Informe a posicao: ");
								scanf("%d", &posicao);
								system("cls || clear");
								if(getTamanho(listaSeq) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}else if(posicao > getTamanho(listaSeq)){
									removeElemento(&listaSeq, getTamanho(listaSeq));
									printf("Elemento da posicao %d removido com sucesso.\n\n", getTamanho(listaSeq));
									break;
								}
								
								removeElemento(&listaSeq, posicao);
								printf("Elemento da posicao %d removido com sucesso.\n\n", posicao);
								break;
								
							case 3:
								//Remove o elemento com o conteudo escolhido
								printf("Informe o conteudo do elemento: ");
								scanf("%d", &elemento);
								system("cls || clear");
								if(getTamanho(listaSeq) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}
								
								if(removeElementoDado(&listaSeq, elemento) == 0){
									printf("Elemento de conteudo %d nao encontrado.\n\n", elemento);
									break;
								}
								
								printf("Elemento de conteudo %d removido com sucesso.\n\n", elemento);
								break;
								
							case 4:
								//Altera o elemento da posicao escolhida
								printf("Informe a posicao: ");
								scanf("%d", &posicao);
								printf("Informe o novo Valor: ");
								scanf("%d", &elemento);
								system("cls || clear");
								if(getTamanho(listaSeq) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}else if(posicao > getTamanho(listaSeq)){
									alteraValor(&listaSeq, getTamanho(listaSeq), elemento);
									printf("Elemento da posicao %d alterado com sucesso.\n\n", getTamanho(listaSeq));
									break;
								}
								
								alteraValor(&listaSeq, posicao, elemento);
								printf("Elemento da posicao %d alterado com sucesso.\n\n", posicao);
								break;	
								
							case 5:
								//Pesquisa o elemento da posicao escolhida
								printf("Informe a posicao: ");
								scanf("%d", &posicao);
								system("cls || clear");
								if(getTamanho(listaSeq) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}else if(posicao > getTamanho(listaSeq)){
									printf("Conteudo do elemento da posicao %d: %d\n\n", getTamanho(listaSeq), getElemento(listaSeq, getTamanho(listaSeq)));
									break;
								}
								
								printf("Conteudo do elemento da posicao %d: %d\n\n", posicao, getElemento(listaSeq, posicao));
								break;	
								
							case 6:
								//Pesquisa o elemento com o conteudo escolhido
								printf("Informe o conteudo do elemento: ");
								scanf("%d", &elemento);
								system("cls || clear");
								if(getTamanho(listaSeq) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}
								
								if(getPosicao(listaSeq, elemento) == 0){
									printf("Elemento de conteudo %d nao encontrado.\n\n", elemento);
									break;
								}
								
								
								printf("Elemento de conteudo %d na posicao: %d\n\n", getElemento(listaSeq, getPosicao(listaSeq, elemento)), getPosicao(listaSeq, elemento));
								break;
								
							case 7:

								//Divide a lista em duas
								if(getTamanho(listaSeq) <= 1){
									printf("Lista com tamanho insuficiente.\nAdicione mais elementos.\n\n");
									break;
								}
								
								divideListaParImpar(listaSeq, &listaParSeq, &listaImparSeq);
								printf("Listas Criadas com Sucesso!\n\n");
								
								printf("-------------------------------\n");
								printf("Lista com elementos Pares:\n");
								toString(listaParSeq);
								printf("\n-------------------------------\n\n");
								printf("Lista com elementos Impares:\n");
								toString(listaImparSeq);
								printf("\n-------------------------------\n\n");
								break;
								
							case 8:

								//Concatena as listas de Elementos Pares e Impares
								concatenaLista(listaParSeq, listaImparSeq, &listaConcatenadaSeq);
								if(getTamanho(listaParSeq) < 1 || getTamanho(listaImparSeq) < 1){
									printf("Listas com tamanho insuficiente.\nAdicione mais elementos.\n\n");
									break;
								}
								
								printf("Listas Concatenadas com Sucesso!\n\n");
								
								printf("-------------------------------\n");
								printf("Lista Concatenada:\n");
								toString(listaConcatenadaSeq);
								printf("\n-------------------------------\n\n");
								break;
								
								
								
								
							case 98:
								for(i = 1; i <= 10 ; i++) {
									addElemento(&listaSeq, getTamanho(listaSeq)+1, rand());
								}
								
								printf("Elementos adicionados com sucesso!\n");
								printf("-------------------------------\n");
								toString(listaSeq);
								printf("\n-------------------------------\n");
								break;
								
							case 0:
								break;
								
							case 99:
								toString(listaSeq);
								printf("\n---------------------------------------------\n\n");
								break;
								
							default:
								printf("Digite uma opcao valida\n\n");			
						}
					
					}while(menuSeq);
					
					break;
					
				case 2:
					
					do{
						printf("\n\n\tLista Encadeada\n\n");
						printf(" 1. Adicionar Elemento\n\n");
						
						printf(" Remover Elemento\n");
						printf("  2. Escolher Posicao\n");
						printf("  3. Escolher Conteudo\n\n");
						
						printf(" 4. Alterar Elemento\n\n");
						
						printf(" Pesquisar Elemento\n");
						printf("  5. Pesquisar por Posicao\n");
						printf("  6. Pesquisar por Conteudo\n\n");
						
						printf(" 7. Separar Lista em outras Duas Listas (E EXIBI-LAS):\n  -Elementos Pares\n  -Elementos Impares\n\n");
						
						printf(" 8. Concatenar as Listas de Elementos Pares e Impares (E EXIBI-LA)\n\n");
						
						printf("98. Adiciona 10 elementos aleatorios na Lista\n");
						printf("99. Exibe Conteudo da Lista\n");
						printf("0. Voltar\n");
			
						scanf("%d", &menuEnc);
						system("cls || clear");
					
						switch(menuEnc)
						{
							case 1:
								printf("Informe a Posicao: ");
								scanf("%d", &posicao);
								printf("Informe o Valor: ");
								scanf("%d", &elemento);
								system("cls || clear");
								//Adiciona um elemento na posicao desejada
								if(getTamanho(listaEnc) == 0){
									addElemento(&listaEnc, 1, elemento);
									printf("Elemento adicionaco com sucesso na posicao 1.");
									break;
								}else if(posicao > getTamanho(listaEnc)){
									printf("Elemento adicionaco com sucesso na posicao %d.", getTamanho(listaEnc)+1);
									addElemento(&listaEnc, getTamanho(listaEnc)+1, elemento);
									break;
								}
								
								printf("Elemento adicionaco com sucesso na posicao %d.", posicao);
								addElemento(&listaEnc, posicao, elemento);
								break;
								
							case 2:
								//Remove o elemento da posicao escolhida
								printf("Informe a posicao: ");
								scanf("%d", &posicao);
								system("cls || clear");
								if(getTamanho(listaEnc) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}else if(posicao > getTamanho(listaEnc)){
									removeElemento(&listaEnc, getTamanho(listaEnc));
									printf("Elemento da posicao %d removido com sucesso.\n\n", getTamanho(listaEnc));
									break;
								}
								
								removeElemento(&listaEnc, posicao);
								printf("Elemento da posicao %d removido com sucesso.\n\n", posicao);
								break;
								
							case 3:
								//Remove o elemento com o conteudo escolhido
								printf("Informe o conteudo do elemento: ");
								scanf("%d", &elemento);
								system("cls || clear");
								if(getTamanho(listaEnc) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}
								
								if(removeElementoDado(&listaEnc, elemento) == 0){
									printf("Elemento de conteudo %d nao encontrado.\n\n", elemento);
									break;
								}
								
								printf("Elemento de conteudo %d removido com sucesso.\n\n", elemento);
								break;
								
							case 4:
								//Altera o elemento da posicao escolhida
								printf("Informe a posicao: ");
								scanf("%d", &posicao);
								printf("Informe o novo Valor: ");
								scanf("%d", &elemento);
								system("cls || clear");
								if(getTamanho(listaEnc) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}else if(posicao > getTamanho(listaEnc)){
									alteraValor(&listaEnc, getTamanho(listaEnc), elemento);
									printf("Elemento da posicao %d alterado com sucesso.\n\n", getTamanho(listaEnc));
									break;
								}
								
								alteraValor(&listaEnc, posicao, elemento);
								printf("Elemento da posicao %d alterado com sucesso.\n\n", posicao);
								break;	
								
							case 5:
								//Pesquisa o elemento da posicao escolhida
								printf("Informe a posicao: ");
								scanf("%d", &posicao);
								system("cls || clear");
								if(getTamanho(listaEnc) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}else if(posicao > getTamanho(listaEnc)){
									printf("Conteudo do elemento da posicao %d: %d\n\n", getTamanho(listaEnc), getElemento(listaEnc, getTamanho(listaEnc)).conteudo);
									break;
								}
								
								printf("Conteudo do elemento da posicao %d: %d\n\n", posicao, getElemento(listaEnc, posicao).conteudo);
								break;	
								
							case 6:
								//Pesquisa o elemento com o conteudo escolhido
								printf("Informe o conteudo do elemento: ");
								scanf("%d", &elemento);
								system("cls || clear");
								if(getTamanho(listaEnc) == 0){
									printf("A lista esta vazia.\n\n");
									break;
								}
								
								if(getPosicao(listaEnc, elemento) == 0){
									printf("Elemento de conteudo %d nao encontrado.\n\n", elemento);
									break;
								}
								
								
								printf("Elemento de conteudo %d na posicao: %d\n\n", getElemento(listaEnc, getPosicao(listaEnc, elemento)).conteudo, getPosicao(listaEnc, elemento));
								break;
								
							case 7:

								//Divide a lista em duas
								if(getTamanho(listaEnc) <= 1){
									printf("Lista com tamanho insuficiente.\nAdicione mais elementos.\n\n");
									break;
								}
								
								divideListaParImpar(listaEnc, &listaParEnc, &listaImparEnc);
								
								printf("Listas Criadas com Sucesso!\n\n");
								
								printf("-------------------------------\n");
								printf("Lista com elementos Pares:\n");
								toString(listaParEnc);
								printf("\n-------------------------------\n\n");
								printf("Lista com elementos Impares:\n");
								toString(listaImparEnc);
								printf("\n-------------------------------\n\n");
								break;
								
							case 8:
								//Concatena as listas de Elementos Pares e Impares
								concatenaLista(listaParEnc, listaImparEnc, &listaConcatenadaEnc);
								if(getTamanho(listaParEnc) < 1 || getTamanho(listaImparEnc) < 1){
									printf("Listas com tamanho insuficiente.\nAdicione mais elementos.\n\n");
									break;
								}
								
								printf("Listas Concatenadas com Sucesso!\n\n");
								
								printf("-------------------------------\n");
								printf("Lista Concatenada:\n");
								toString(listaConcatenadaEnc);
								printf("\n-------------------------------\n\n");
								break;
								
								
								
							case 98:
								for(i = 1; i <= 10 ; i++) {
									addElemento(&listaEnc, getTamanho(listaEnc)+1, rand());
								}
								
								printf("Elementos adicionados com sucesso!\n");
								printf("-------------------------------\n");
								toString(listaEnc);
								printf("\n-------------------------------\n");
								break;
								
							case 0:
								break;
								
							case 99:
								toString(listaEnc);
								printf("\n---------------------------------------------\n\n");
								break;
								
							default:
								printf("Digite uma opcao valida\n\n");			
						}
					
					}while(menuEnc);
					
				break;
					
					
				case 0:
					printf("Saindo...\n");
					exit(0);
					break;

				default:
					printf("Digite uma opcao valida\n");
			}
		} while(continuar);





		system("pause");
		return 0;

	}
