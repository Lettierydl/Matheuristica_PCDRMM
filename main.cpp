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

/*geracao, tam_pop, mutacao, instancia*/
int main(int argc, char *argv[]) {
//	cout << "PCDRMM_MATHEURISTICA" << endl;

	int tam_pop, geracao,indice;
	float mutacao;
	bool parametros = false;
	if (argc > 1) {
		geracao = atoi(argv[1]);
		tam_pop = atoi(argv[2]);
		mutacao = atof(argv[3]);
		indice = atoi(argv[4]);
		parametros = true;
	}

	//bateriaDeTestesComValores();
	//return 0;
	int qt = 1;

	vector<float> execucao(qt, 0);
	vector<float> tempos(qt, 0);
	vector<float> valores(qt, 0);
	vector < string > instancia_name(qt);

	for (int i = 0; i < qt; i++) {

//		cout << "instancia " << i << endl;

		string instancia = "PSPLIB/j10";
		if(parametros){
			i = indice;
		}
		Arquivo arq(instancia, i);

		Dados *d = arq.lerInstanciaPSPLIB();

		Solucao *cus = new Solucao(d);
		cus->iniciarSolucaoComMelhorCusto();
		d->D = cus->tempo - 1;

		//cout << cus->tempo << endl;

		Heuristicas h(d);

		clock_t start_time;
		start_time = clock();

		Solucao *s;
		if (parametros) {
			s = h.geneticAlgorithms(geracao, tam_pop, mutacao);
		} else {
			s = h.geneticAlgorithms(20);
		}

		float time_in_seconds = (clock() - start_time)
				/ (double) CLOCKS_PER_SEC;
		//cout << s->custo << " X " << s->tempo << " -> " << time_in_seconds << endl;

		execucao[i] = time_in_seconds;
		valores[i] = s->custo;
		tempos[i] = s->tempo;

	}

	for (int i = 0; i < qt; i++) {
		cout << valores[i] << "\t" << execucao[i] << endl;
	}
	return 0;
}

void bateriaDeTestesComValores() {

	int repeticoes = 10;
	int qt_inst = 1;

	vector<float> bestCusto(qt_inst, INT_MAX);
	vector<float> mediaCusto(qt_inst, 0);
	vector<float> piorCusto(qt_inst, 0);

	vector<float> bestTempo(qt_inst, INT_MAX);
	vector<float> mediaTempo(qt_inst, 0);
	vector<float> piorTempo(qt_inst, 0);

	vector < map<float, int> > modaCusto(qt_inst);
	vector < map<float, int> > modaTempo(qt_inst);

	cout << "PSPLIB/j10" << endl;

	for (int i = 0; i < qt_inst; i++) {
		cout << "\t" << i << " " << endl;

		string instancia = "PSPLIB/j10";
		Arquivo arq(instancia, i);

		Dados *d = arq.lerInstanciaPSPLIB();
		/*
		 string instancia = "Instancias_Denise";
		 Arquivo arq(instancia, i);
		 Dados *d = arq.lerInstancia();
		 */

		Solucao *cus = new Solucao(d);
		cus->iniciarSolucaoComMelhorCusto();
		d->D = cus->tempo - 1;

		cout << cus->tempo << endl;

		for (int rep = 0; rep < repeticoes; rep++) {
			cout << rep << endl;

			Heuristicas h(d);

			clock_t start_time;
			start_time = clock();

			//h.pso(50);

			//Solucao *s = &(*h.fronteira.begin()); // new Solucao(d);//

			Solucao *s = h.geneticAlgorithms(20);

			float time_in_seconds = (clock() - start_time)
					/ (double) CLOCKS_PER_SEC;
			cout << s->custo << endl;
			arq.salvarResposta(i, s->custo, s->tempo, time_in_seconds);

			if (i == qt_inst - 1) {
				arq.salvarResposta(0, 0, 0, 0);
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

