# ifndef L_SEQ_H
# define L_SEQ_H
# define MAX 100  /* tamanho Máximo da Lista */

//Estrutura da Lista Sequencial
typedef struct lista{
	int dados[MAX];
	int qtdElementos;
}tLista;

extern void cria (tLista *lista);
extern int isVazia(tLista lista);
extern int isCheia(tLista lista);
extern int getTamanho(tLista lista);
extern int getElemento(tLista lista, int posicao);
extern int getPosicao(tLista lista, int dado);
extern int addElemento(tLista *lista, int posicao, int dado);
extern int removeElemento(tLista *lista, int posicao);
extern int removeElementoDado(tLista *lista, int dado);
extern void toString(tLista ista);
extern int alteraValor(tLista *lista, int posicao, int novoValor);
extern int divideListaParImpar(tLista lista, tLista *listaPar, tLista *listaImpar);
extern int concatenaLista(tLista lista1, tLista lista2, tLista *listaFinal);

# endif

//Cria uma Lista
void cria(tLista *lista){
	lista->qtdElementos = 0;
}

//Retorna o tamanho da lista
int getTamanho(tLista lista){
	return lista.qtdElementos;
}

//True para Vazia, false para o contrário
int isVazia(tLista lista){
	if(getTamanho(lista) == 0)
		return 1;
	return 0;
}

//True para Cheia, false para o contrário
int isCheia(tLista lista){
	if(getTamanho(lista) == MAX)
		return 1;
	return 0;
}

//Retorna o Dado do elemento na posição escolhida, 0 caso a posição seja inválida
int getElemento(tLista lista, int posicao){
	if(posicao <= 0 || posicao > getTamanho(lista)){
		printf("Posicao invlida.");
		return 0;
	}

	return lista.dados[posicao-1];
}

//Retorna a posição do elemento com o dado passado como parâmetro, 0 caso o elemento não exista na lista
int getPosicao(tLista lista, int dado){
	int i;
	for(i=0; i < getTamanho(lista) ; i++) {
		if(dado == lista.dados[i])
			return (i+1);
	}
	return 0;
}

//Adiciona Elemento n lista
int addElemento(tLista *lista, int posicao, int dado){
	int i = 0;
	if(isCheia(*lista) ||  posicao > (getTamanho(*lista)+1) || posicao < 0){
		printf("Erro.");
		return 0;
	}

	//Move todos os elementos uma casa pra frente para poder encaixar o novo elmento na posição desejada
	for(i = getTamanho(*lista) ; i >= posicao ; i--) {
		lista->dados[i] = lista->dados[i-1];
	}

	lista->dados[posicao - 1] = dado;
	(lista->qtdElementos)++;
	return 1;
}

//Remove elemento da lista indicado pela posição
int removeElemento(tLista *lista, int posicao){
	int i = 0;
	if(isVazia(*lista) ||  posicao > getTamanho(*lista) || posicao <= 0){
		return 0;
	}

	for(i = (posicao -1) ; i < getTamanho(*lista)-1 ; i++) {
		lista->dados[i] = lista->dados[i+1];
	}
	
	lista->qtdElementos = lista->qtdElementos-1;
	return 1;
}

//Remove elemento da lista indicado pelo conteúdo
int removeElementoDado(tLista *lista, int dado){
	
	int posicao = getPosicao(*lista, dado);
	
	return removeElemento(lista, posicao);
}

//Exibe todos os Elementos da lista com seus conteúdos
void toString(tLista lista){
	int i =0;
	if(isVazia(lista)){
		printf("Lista Vazia");
	}
		
	for(i = 1 ; i <= getTamanho(lista) ; i++) {
		printf("Posicao: %d \nDado: %d\n\n", getPosicao(lista, getElemento(lista, i)), getElemento(lista, i));
	}
	printf("Tamanho da Lista: %d",getTamanho(lista));
}

//Altera o valor do elemento da posição escolhida
int alteraValor(tLista *lista, int posicao, int novoValor){
	if(isVazia(*lista) ||  posicao > getTamanho(*lista) || posicao <= 0)
		return 0;
			
	lista->dados[posicao-1] = novoValor;
	return 1;	
}

//Divide a lista escolhida em duas:
//Uma com elementos pares
//Outra com elementos ímpares
int divideListaParImpar(tLista lista, tLista *listaPar, tLista *listaImpar){
	int i = 1;
	int contPar = 1;
	int contImpar = 1;
	
	if(isVazia(lista))
		return 0;
		
	for(i = 1 ; i <= getTamanho(lista) ; i++) {
		int elemento = getElemento(lista, i);
		
		if(elemento%2 == 0){
			addElemento(listaPar,contPar, elemento);
			//listaPar->dados[contPar] = elemento;
			contPar++;
		}else{
			addElemento(listaImpar,contImpar, elemento);
			//listaImpar->dados[contPar] = elemento;
			contImpar++;	
		}
	}
	
	return 1;
}

//Concatena duas listas
int concatenaLista(tLista lista1, tLista lista2, tLista *listaFinal){
	int i = 0;
	int cont = 1;
	
	if(isVazia(lista1) || isVazia(lista2)){
		printf("Lista Vazia.");
		return 0;
	}
	
	for(i = 1 ; i <= getTamanho(lista1) ; i++) {
		int elemento = getElemento(lista1, i);
		addElemento(listaFinal, cont, elemento);
	}
	
	for(i = 1 ; i <= getTamanho(lista2) ; i++) {
		int elemento = getElemento(lista2, i);
		addElemento(listaFinal, cont, elemento);
	}
	
	return 1;
}


































