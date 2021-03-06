//============================================================================
// Name        : PCDRMM.cpp
// Author      : Lettiery DLamare
// Version     :
// Copyright   : UFPB
// Description : Problema de Custo de Disponibilidade de Recruso com Multiplos Modos
//============================================================================

#include "Arquivo.h"
#include "Solucao.h"
#include "Grafico.h"
#include "Heuristicas.h"
#include "AlgAux.h"
#include "Teste.h"
#include <iostream>
#include <string>
#include "stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <time.h>

#include <vector>

using namespace std;

void bateriaDeTestesComValores();

void teste_irace(int argc, char* argv[]) {
	int tam_pop, geracao, indice;
	float busca;
	int iteracoes = 10;

	string instancia(argv[1]);
	if (argc > 1) {
		geracao = atoi(argv[2]);
		tam_pop = atoi(argv[3]);
		//busca = atof(argv[4]);
		busca = 0;
	}else{
		cerr << "Não existe parametros"<< endl;
		return;
	}

	vector<float> execucao(iteracoes, 0);
	vector<float> valores(iteracoes, 0);

	cerr<< instancia << endl;
	Arquivo arq(instancia);
	Dados* d = arq.lerInstanciaPSPLIB();
	Solucao* cus = new Solucao(d);
	cus->iniciarSolucaoComMelhorCusto();
	d->D = cus->tempo - 1;

	for (int i = 0; i < iteracoes; i++) {
		Heuristicas h(d);

		clock_t start_time;
		start_time = clock();

		Solucao* s = h.geneticAlgorithms(geracao, tam_pop, busca);

		float time_in_seconds = (clock() - start_time) / (double) (CLOCKS_PER_SEC);
		cerr << "Finishi " << i << endl;
		execucao[i] = time_in_seconds;
		valores[i] = s->custo;
	}


	float e_best = execucao[0];
	for (int i = 0; i < iteracoes; i++) {
		if (e_best > execucao[i]) {
			e_best = execucao[i];
		}
	}

	float c_best = valores[0];
	for (int i = 0; i < iteracoes; i++) {
		if (c_best > valores[i]) {
			c_best = valores[i];
		}
	}
	cout << "Best " << c_best << endl;
}

//indice inicia do 0
void teste_instance(string instance, int indice) {
	int iteracoes = 50;
	int geracoes = 22;
	vector<float> execucao(iteracoes, 0);
	vector<float> tempos(iteracoes, 0);
	vector<float> valores(iteracoes, 0);

	Arquivo arq(instance, indice);
	Dados *d = arq.lerInstanciaPSPLIB();
	bool parametros = false;


	Solucao* cus = new Solucao(d);
	cus->iniciarSolucaoComMelhorCusto();
	d->D = cus->tempo - 1;
	for (int i = 0; i < iteracoes; i++) {
		Heuristicas h(d);
		clock_t start_time;
		start_time = clock();

		Solucao* s = h.geneticAlgorithms(geracoes);

		float time_in_seconds = (clock() - start_time) / (double) (CLOCKS_PER_SEC);

		execucao[i] = time_in_seconds;
		valores[i] = s->custo;
		tempos[i] = s->tempo;
	}
	float c_best = valores[0];
	for (int i = 0; i < iteracoes; i++) {
		if (c_best > valores[i]) {
			c_best = valores[i];
		}
	}

	float e_best = execucao[0];
	for (int i = 0; i < iteracoes; i++) {
		if (e_best > execucao[i]) {
			e_best = execucao[i];
		}
	}

	cout << "Best: " << c_best << " in " << e_best << " s" << endl;
}

/*instancia, geracao, tam_pop*/
int main(int argc, char *argv[]) {
	//bateriaDeTestesComValores();
	//return 0;
	if(argc > 1){
		teste_irace(argc, argv);
	}else{
		teste_instance("PSPLIB/j10" , 0 );
	}
	return 0;
}

void bateriaDeTestesComValores() {

	int repeticoes = 50;
	int qt_inst = 2;

	vector<float> bestCusto(qt_inst, INT_MAX);
	vector<float> mediaCusto(qt_inst, 0);
	vector<float> piorCusto(qt_inst, 0);

	vector<float> bestTempo(qt_inst, INT_MAX);
	vector<float> mediaTempo(qt_inst, 0);
	vector<float> piorTempo(qt_inst, 0);

	vector < map<float, int> > modaCusto(qt_inst);
	vector < map<float, int> > modaTempo(qt_inst);

	cout << "PSPLIB/j30" << endl;

	for (int i = 0; i < qt_inst; i++) {
		cout << "\t" << i << " " << endl;

		string instancia = "PSPLIB/j30";
		Arquivo arq(instancia, i);
		cout <<arq.nomeArquivo << endl;
		Dados *d = arq.lerInstanciaPSPLIB();
		/*
		 string instancia = "Instancias_Denise";
		 Arquivo arq(instancia, i);
		 Dados *d = arq.lerInstancia();
		 */

		Solucao *cus = new Solucao(d);
		cus->iniciarSolucaoComMelhorCusto();
		d->D = cus->tempo - 1;

		//cout << cus->tempo << endl;

		for (int rep = 0; rep < repeticoes; rep++) {
			cout << rep << endl;

			Heuristicas h(d);

			clock_t start_time;
			start_time = clock();

			Solucao *s = h.geneticAlgorithms(22);

			float time_in_seconds = (clock() - start_time)/ (double) CLOCKS_PER_SEC;

			arq.salvarResposta(i, s->custo, s->tempo, time_in_seconds);

			if (i == qt_inst - 1) {
				arq.salvarResposta(0, 0, 0, 0);
			}

			if (s->custo < bestCusto[i]) {
				bestCusto[i] = s->custo;
			}
			if (s->custo > piorCusto[i]) {
				piorCusto[i] = s->custo;
			}

			if (time_in_seconds < bestTempo[i]) {
				bestTempo[i] = time_in_seconds;
			}
			if (time_in_seconds > piorTempo[i]) {
				piorTempo[i] = time_in_seconds;
			}

			mediaCusto[i] += s->custo;
			mediaTempo[i] += time_in_seconds;

			modaCusto[i][s->custo]++;
			modaTempo[i][time_in_seconds]++;
		}

	}

	printf("\n<<<<<<<<<<RESULTADOS>>>>>>>>>>\n\n");
	printf(
			"BestCusto\tMedioCusto\tPiorCusto\tBestTempo\tMedioTempo\tPiorTempo\n");
	for (int i = 0; i < qt_inst; i++) {
		mediaCusto[i] /= repeticoes;
		mediaTempo[i] /= repeticoes;

		printf("%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", bestCusto[i],
				mediaCusto[i], piorCusto[i], bestTempo[i], mediaTempo[i],
				piorTempo[i]);
	}

	cout << "Moda" << endl << endl;
	for (int i = 0; i < qt_inst; i++) {
		map<float, int>::iterator it = modaCusto[i].begin();
		float moda = modaCusto[i].begin()->first;
		for (; it != modaCusto[i].end(); it++) {
			if (modaCusto[i][it->first] > modaCusto[i][moda]) {
				moda = it->first;
			}
		}
		cout << moda << endl;

	}
	cout << endl;

	printf("\n<<<<<<<<<<Bestes>>>>>>>>>>\n\n");
	for (int i = 0; i < qt_inst; i++) {
		mediaCusto[i] /= repeticoes;
		mediaTempo[i] /= repeticoes;

		printf("%.2f\t%.2f\n", bestCusto[i], bestTempo[i]);
	}
}

