#include "dicionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

//Destrutor
dicionario :: ~dicionario()
{
	lista_port.~lista();
	lista_ingles.~lista();
}

//Função que chama todas as outras funções da classe dicionario
void dicionario::executa()
{
	//A variavael "a" guarda a palavra em portugues lida.
	//A variavel b guarda a palavra em ingles lida
	//A variavel lixo guarda o "-" lido.
	//A variavel linha guarda as palavras lidas em cada linha do texto.
	char a[20], b[20], lixo, linha[100];

	//Guarda cada palavra da linha
	string palavra;
	int r;
	FILE *f, *arq;

	//Le o arquivo com as palavras em portugues e ingles
	f = fopen("entrada.txt", "rt");

	if (f == NULL)
	{
		printf("ERRO!\n");
		exit(1);
	}

	//Enquanto ler a palavra em portuges - palavra em ingles, insere cada uma em uma das suas respectivas filas
	while ((r = fscanf(f, "%s %c %s", a, &lixo, b)) == 3)
	{
		insere_par(a, b);
	}

	fclose(f);

	arq = fopen("entrada2.txt", "rt");

	if (arq == NULL)
	{
		printf("ERRO!\n");
		exit(1);
	}

	//Le linha a linha do arquivo
	while (fgets(linha, 100, arq))
	{
		istringstream iss(linha); // Separa as palavras da linha

		while (iss >> palavra)
		{
			traduzirPalavra(palavra); //Procura se palavra está em uma das listas e procura sua traducao
			cout << palavra << " "; //imprime a palavra
		}

		cout << endl;

	}

	fclose(arq);
}

//Insere cada uma das palavras na sua respectiva fila
//Se uma palavra em portugues, insere em lista_port
//Se uma palavra em ingles, insere em lista_ingles
//Em seguida faz com que cada palavra aponte para a sua traducao pertencente a outra fila
void dicionario::insere_par(string a, string b)
{
	if (lista_port.insere(a))
		if (lista_ingles.insere(b))
			lista_port.insere_trad(lista_ingles, a, b);
}

//Procura se palavra pertence ao lista com palavras em portugues ou as palavras em ingles
//Se pertencer procura na outra fila sua traducao
void dicionario::traduzirPalavra(string &word)
{
	if (!lista_port.buscaPalavra(word))
		if (!lista_ingles.buscaPalavra(word))
			return;
		else
			lista_ingles.buscarTraducao(word);
	else
		lista_port.buscarTraducao(word);
}
