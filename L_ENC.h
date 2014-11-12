# ifndef L_ENC_H
# define L_ENC_H

//Estrutura do Nó
typedef struct no{
	int conteudo;
	struct no *proximo; 
}tNo;

typedef struct listaEnc{
	struct no *cabeca;
	int tamanho; 
}tListaEnc;

extern void cria(tListaEnc *lista);
extern int getTamanho(tListaEnc lista);
extern int isVazia(tListaEnc lista);
extern int isCheia(tListaEnc lista);
extern tNo getElemento(tListaEnc lista, int posicao);
extern int getPosicao(tListaEnc lista, int dado);
extern int addElemento(tListaEnc *lista, int posicao, int dado);
extern int removeElemento(tListaEnc *lista, int posicao);
extern int removeElementoDado(tListaEnc *lista, int dado);
extern void toString(tListaEnc ista);
extern int alteraValor(tListaEnc *lista, int posicao, int novoValor);
extern int divideListaParImpar(tListaEnc lista, tListaEnc *listaPar, tListaEnc *listaImpar);
extern int concatenaLista(tListaEnc lista1, tListaEnc lista2, tListaEnc *listaFinal);

# endif


void cria(tListaEnc *lista){
	lista->cabeca = NULL;
	lista->tamanho = 0;
}

int getTamanho(tListaEnc lista){
	return lista.tamanho;
}

int isVazia(tListaEnc lista){
	if(getTamanho(lista) == 0)
		return 1;
	return 0;
}

int isCheia(tListaEnc lista){
	if(getTamanho(lista) == 0)
		return 1;
	return 0;
}

tNo getElemento(tListaEnc lista, int posicao){
	tNo *no = lista.cabeca;
	tNo vazio;
	vazio.proximo = NULL;
	vazio.conteudo = 0;
	int cont = 1;
	
	if(getTamanho(lista) == 0 || posicao <= 0) //Posição passadda é inválida
		return vazio;

	while(no != NULL && cont < posicao){
		no = no->proximo;
		cont++;
	}
	if(no == NULL) //Posição inválida
		return vazio;

	return *no;

}

int getPosicao(tListaEnc lista, int dado){
	tNo *no = lista.cabeca;
	int cont = 1;
	
	if(getTamanho(lista) == 0) //Posição passadda é inválida
		return 0;
	
	while(no != NULL){
		if(no->conteudo == dado)
			return cont;
			
		no = no->proximo;
		cont++;
	}
	
	if( no == NULL)
		return 0;
	
	return 1;
}

int addElemento(tListaEnc *lista, int posicao, int dado){
	tNo *novoNo;
	
	 // Insere em lista vazia     
	 if (isVazia(*lista)) {
		 if (posicao != 1) {
		 	return 0;
	 	}
		  
		novoNo = (tNo *) malloc(sizeof(tNo));
		if (novoNo == NULL) { // Caso não tenha memória suficiente
			return 0;
		}
		
		novoNo->proximo = NULL;
		novoNo->conteudo = dado; 
	 	
	 	lista->cabeca = novoNo;
	 	lista->tamanho++;
	 	
	 	return 1;
	
	// Inserir no início da lista
	}else if (posicao == 1){
		novoNo = (tNo *) malloc(sizeof(tNo));
		if (novoNo == NULL) { // Caso não tenha memória suficiente
			return 0;
		}
		
		novoNo->conteudo = dado;
		novoNo->proximo = lista->cabeca;
		
		lista->cabeca = novoNo;
		lista->tamanho++;

		return 1;  
	
	
	
	// Inserir no fim da lista 
	}else if (posicao-1 == getTamanho(*lista)){
		novoNo = (tNo *) malloc(sizeof(tNo));
		if (novoNo == NULL) { // Caso não tenha memória suficiente
			return 0;
		}
		
		novoNo->conteudo = dado;
		novoNo->proximo = NULL;
		
		tNo *cauda = lista->cabeca;
		while(cauda->proximo != NULL){
			cauda = cauda->proximo;
		}
		
		cauda->proximo = novoNo;
		
		lista->tamanho++;
		
		return 1;
	
	// Inderir no meio da lista    	
	}else{      
		novoNo = (tNo *) malloc(sizeof(tNo));
		if (novoNo == NULL) { // Caso não tenha memória suficiente
			return 0;
		}
		
		tNo *p = lista->cabeca;
		int cont = 1;
		
		if(posicao != 1)
			while(p->proximo != NULL && cont+1 < posicao){
				p = p->proximo;
				cont++;
			}
		
		if(p == NULL) //Posição Inválida
			return 0;
			
		novoNo->conteudo = dado;
		novoNo->proximo = p->proximo;
		
		p->proximo = novoNo;
		
		lista->tamanho++;
		
		return 1;
	}	
}

//Exibe todos os Elementos da lista com seus conteúdos
void toString(tListaEnc lista){
	int i =1;
	if(isVazia(lista)){
		printf("Lista Vazia");
	}
		
	tNo *p = lista.cabeca;
	while(p != NULL){
		printf("Posicao: %d \nDado: %d\n\n", i, p->conteudo);
		p = p->proximo;
		i++;
	}
	
	printf("Tamanho da Lista: %d",getTamanho(lista));
}

//Remove elemento da lista indicado pelo conteúdo
int removeElemento(tListaEnc *lista, int posicao){
	if (isVazia(*lista) || posicao == 0)
		return 0;
		
		//Remove do Início da Lista
		if (posicao == 1){
			tNo *cabeca = lista->cabeca;
			lista->cabeca = cabeca->proximo;
			lista->tamanho--;
			
			free(cabeca);
			return 1;
			
		// Remove do meio da lista   
		} else{ 
			tNo *antRemovido;
			tNo *removido = lista->cabeca;
			int cont = 1;
			while(cont < posicao){
				antRemovido = removido;
				removido = removido->proximo;
				cont++;
			}
			
			antRemovido->proximo = removido->proximo;
			free(removido);
			
			lista->tamanho--;
			return 1;
		}
}

//Remove elemento da lista indicado pelo conteúdo
int removeElementoDado(tListaEnc *lista, int dado){
	int posicao = getPosicao(*lista, dado);
	
	removeElemento(lista, posicao);
	return 0;
}

//Altera o valor do elemento da posição escolhida
int alteraValor(tListaEnc *lista, int posicao, int novoValor){
	tNo *no = lista->cabeca;
	int cont = 1;
	while(cont < posicao && no != NULL){
		no = no->proximo;
		cont++;
	}
	
	*no = getElemento(*lista, posicao);
	
	no->conteudo = novoValor;
	return 1;
	
}

//Divide a lista escolhida em duas:
//Uma com elementos pares
//Outra com elementos ímpares
int divideListaParImpar(tListaEnc lista, tListaEnc *listaPar, tListaEnc *listaImpar){
	if(isVazia(lista))
		return 0;
		
	tNo *no = lista.cabeca;
	int cont = 1;
	while(no != NULL){
		if((no->conteudo % 2) == 0 ){
			addElemento(listaPar, cont, no->conteudo);
		}else{
			addElemento(listaImpar, cont, no->conteudo);
		}
		no = no->proximo;
	}
	
	return 1;
}

//Concatena duas listas
int concatenaLista(tListaEnc lista1, tListaEnc lista2, tListaEnc *listaFinal){
	int i = 0;
	int cont = 1;
	
	if(isVazia(lista1) || isVazia(lista2)){
		printf("Lista Vazia.");
		return 0;
	}
	
	tNo *no1 = lista1.cabeca;
	while(no1 != NULL){
		addElemento(listaFinal, cont, no1->conteudo);
		no1 = no1->proximo;
		cont++;
	}
	
	tNo *no2 = lista2.cabeca;
	cont = 0;
	while(no2 != NULL){
		addElemento(listaFinal, cont, no2->conteudo);
		no2 = no2->proximo;
		cont++;
	}

	return 1;
}























































