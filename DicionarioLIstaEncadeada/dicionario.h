#ifndef DICIONARIO_H
#define DICIONARIO_H
#include <iostream>
#include "lista.h"
using namespace std;

class dicionario
{

private:
	lista lista_port; //Lista com palavras do portugues
	lista lista_ingles; //Lista com palavras do ingles

public:
	dicionario() : lista_port(), lista_ingles() {};
	~dicionario();
	void executa();
	void insere_par(string a, string b);
	void traduzirPalavra(string &word);
};
#endif
