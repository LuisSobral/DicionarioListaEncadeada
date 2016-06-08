#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

class elo
{
public:
	string palavra;
	elo *prox;
	elo *palavra_traduzida; //Ponteiro para o elo da outra lista, indicando essa ser a traducao da palavra atribuda a "palavra"

	elo() :prox(NULL), palavra_traduzida(NULL) {};
	elo(string palavra_dici, elo *prox_elo = NULL, elo *palavra_trad = NULL) :
		palavra(palavra_dici), prox(prox_elo), palavra_traduzida(palavra_trad) {};
};

class lista
{

private:
	elo *prim;
	int n;

public:

	lista() : prim(NULL), n(0) {};
	~lista();
	bool insere(string word);
	void insere_trad(lista &lista_trad, string word, string palavra_trad);
	bool buscaPalavra(string word);
	void buscarTraducao(string &word);
};
#endif

