#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

lista :: ~lista()
{
	elo *p = prim;
	while (prim != NULL)
	{
		p = prim->prox;
		delete prim;
		prim = p;
	}
}

//Insere elemento no fim da lista
bool  lista::insere(string word)
{
	if (buscaPalavra(word))
		return false;

	elo *p = NULL;
	elo *ant = NULL;
	for (p = prim; p != NULL; p = p->prox)
		ant = p;

	p = new elo(word);
	n++;

	if (prim == NULL)
		prim = p;
	else {
		ant->prox = p;
	}

	return true;
}

//Porcura pelo elo que tenha a palavra "word"
//Procura na outra lista o elo que tenha a palavra "palavra_trad"
//Faz com que cada palavra se aponte, indicando que uma é traducao da outra
void lista::insere_trad(lista &lista_trad, string word, string palavra_trad)
{
	elo *p = NULL;
	elo* q = NULL;

	for (p = prim; ((p != NULL) && (p->palavra != word)); p = p->prox);
	for (q = lista_trad.prim; ((q != NULL) && (q->palavra != palavra_trad)); q = q->prox);

	if (p == NULL || q == NULL)
		return;

	p->palavra_traduzida = q;
	q->palavra_traduzida = p;

}

//Busca palavra na lista
bool lista::buscaPalavra(string word)
{
	elo *p;

	for (p = prim; ((p != NULL) && (p->palavra != word)); p = p->prox);

	if (p == NULL)
		return false;

	return true;
}

//Busca a palavra na lista
//Passa com referencia na variavel "word" a palavra traduzida, pertencente a outra lista
void lista::buscarTraducao(string &word)
{
	elo *p;

	for (p = prim; ((p != NULL) && (p->palavra != word)); p = p->prox);

	if (p != NULL)
		word = p->palavra_traduzida->palavra;

}
