/*
 * arquivo.h
 *
 *  Created on: 18/11/2014
 *      Author: Leo
 */

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Dados.h"
#include "Solucao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;

class Arquivo {

public:
	ifstream dados;
	ifstream funcao;
	string nomeArquivo;
	int numeroInstacia;

	Dados * lerInstancia();

	Dados * lerInstanciaPSPLIB();

	void gravarTabelaDeResultados(int instacia, float custo, int makespan);
	void gravarSolucao(int instancia, Solucao * s);
	void salvarResposta(int index_instance, float custo, int tempo,
			float tempo_de_execucao);
	void clouse();

	Arquivo(string nomeArquivo, int numero);
	Arquivo(string nomeArquivo);
	~Arquivo();

private:
	void instancia_denise(int numero, const string& nomeArquivo);
	void instancia_PSPLIB(int indice, vector<string> arq, const string& nomeArquivo);

	void instancia_denise(const string& nomeArquivo);
	void instancia_PSPLIB(const string& nomeArquivo);

	vector<string> arquivosInstancias(string *url);
};

#endif /* ARQUIVO_H */
