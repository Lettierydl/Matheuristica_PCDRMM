/*
 * Heuristicas.cpp
 *
 *  Created on: 17/03/2015
 *      Author: Leo
 */

#include "Heuristicas.h"
#include "Solucao.h"
#include "Grafico.h"
#include "AlgAux.h"
#include "CPLEX.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

Solucao* Heuristicas::construicaoGulosa(float alfa) {

	list<int> sequencia;
	sequencia.push_front(0);

	list<int> prox_candidatos;
	list<int>::iterator su = d->S[0].begin();
	for (; su != d->S[0].end(); su++) {
		prox_candidatos.push_back(*su);
	}

	bool todas_alocadas = false;
	while (!todas_alocadas) {
		/*	list<Candidato> lc = criarPossiveisCandidatos(prox_candidatos);
		 list<Candidato> lrc = criarListaRestritaDeCandidatos(lc, alfa);
		 */

	}

}
/*
 list<Candidato> Heuristicas::criarPossiveisCandidatos(list<int> prox_candidatos){
 list<Candidato> lc;
 list<int>::iterator can = prox_candidatos.begin();
 for(;can != prox_candidatos.end() ;can++){
 //criar candidato com can
 //Candidato c (can);

 //calcular custo do candidato

 //adicionar em lc
 //lc.push_back(c);
 }

 return lc;
 }

 list<Candidato> Heuristicas::criarListaRestritaDeCandidatos(list<Candidato> lc, float alfa){
 list<Candidato> lrc;

 return lrc;
 }

 */

list<Solucao*> Heuristicas::pso(int epocas) {
	int tamanhoPopulacao = 100;
	int maxVparticula = 5;
	int minVpartucula = -5;
	float w = 0.2; // inercia
	float c1 = 0.4; // esperiencia local
	float c2 = 0.4; // esperiencia global
	list<Solucao*> gbests; // gbests com a ideia da fronteira de Pareto
	vector<Solucao *> * enxame = new vector<Solucao*>(tamanhoPopulacao);
	srand (time(NULL));

	//populacao inicial
iniciarEnxame	(tamanhoPopulacao, maxVparticula, minVpartucula, enxame);
	//cout << "H " << enxame[0]->pbest << " - " << NULL << endl;

	atualizarPbestGbest(tamanhoPopulacao, enxame);

	for (int e = 0; e < epocas; e++) {
		//atualizar velecidade (pela formula)
		atualizarVelocidades(tamanhoPopulacao, enxame, w, c1, c2, maxVparticula,
				minVpartucula);

		//???o fal deve ser apenas antecessores!!!!
		atualizarPosicoes(tamanhoPopulacao, enxame);

		atualizarPbestGbest(tamanhoPopulacao, enxame);

		Solucao *gbst = (*enxame)[0]->gbest;
		vizinhancaCPLEX(gbst);
		//verificar novo gbest e pbests

	} //fim for epocas

	SolucaoCompareAG sc;
	sort((*enxame).begin(), (*enxame).end(), sc);

	for (int p = 0; p < tamanhoPopulacao; p++) {
		/*cout << (*enxame)[p]->pbest->custo << " " << (*enxame)[p]->pbest->tempo
		 << endl;
		 */
		addFronteiraDePareto((*enxame)[p]->pbest);
	}

	/*
	 list<Solucao>::iterator frot = fronteira.begin();
	 for (; frot != fronteira.end(); frot++) {
	 cout << frot->custo << " " << frot->tempo << "   |    ";
	 }

	 cout << endl;
	 cout << "Gbest: " << (*enxame)[0]->gbest->custo << " "
	 << (*enxame)[0]->gbest->tempo << endl;
	 cout << d->D << endl;
	 Grafico g;
	 */
	//g.plotarTrandOFF(fronteira);
	return gbests;

}

void Heuristicas::atualizarPbestGbest(int tamanhoPopulacao,
		vector<Solucao*>* enxame) {

	// ta errado por aqui, o pbest de gbest esta furgindo
	for (int p = 0; p < tamanhoPopulacao; p++) {
		if ((*enxame)[p]->pbest == NULL) {
			(*enxame)[p]->pbest = new Solucao((*enxame)[p]);
		} else if ((*enxame)[p]->custo < (*enxame)[p]->pbest->custo
				&& (*enxame)[p]->tempo < (*enxame)[p]->pbest->tempo) {
			/*cout << "Melhorou de " << (*enxame)[p]->pbest->custo << " "
			 << (*enxame)[p]->pbest->tempo << " para "
			 << (*enxame)[p]->custo << " " << (*enxame)[p]->tempo
			 << " Tempo e Custo" << endl;*/
			delete (*enxame)[p]->pbest;
			(*enxame)[p]->pbest = new Solucao((*enxame)[p]);
		} else if ((*enxame)[p]->custo < (*enxame)[p]->pbest->custo
				&& (*enxame)[p]->tempo == (*enxame)[p]->pbest->tempo) {
			/*cout << "Melhorou de " << (*enxame)[p]->pbest->custo << " "
			 << (*enxame)[p]->pbest->tempo << " para "
			 << (*enxame)[p]->custo << " " << (*enxame)[p]->tempo
			 << " So Custo" << endl;*/
			delete (*enxame)[p]->pbest;
			(*enxame)[p]->pbest = new Solucao((*enxame)[p]);
		} else if ((*enxame)[p]->custo == (*enxame)[p]->pbest->custo
				&& (*enxame)[p]->tempo < (*enxame)[p]->pbest->tempo) {
			/*cout << "Melhorou de " << (*enxame)[p]->pbest->custo << " "
			 << (*enxame)[p]->pbest->tempo << " para "
			 << (*enxame)[p]->custo << " " << (*enxame)[p]->tempo
			 << " So Tempo" << endl;*/
			delete (*enxame)[p]->pbest;
			(*enxame)[p]->pbest = new Solucao((*enxame)[p]);
		} //else if( (*enxame)[p]->custo < (*enxame)[p]->pbest->custo && (*enxame)[p]->tempo > (*enxame)[p]->pbest->tempo && (*enxame)[p]->tempo <= (*enxame)[p]->d->D){
		  //	delete (*enxame)[p]->pbest;
		  //	(*enxame)[p]->pbest = new Solucao((*enxame)[p]);
		  //}
	}

	Solucao * gbest = (*enxame)[0]->pbest;
	for (int p = 0; p < tamanhoPopulacao; p++) {
		if (gbest == NULL) {
			gbest = (*enxame)[p]->pbest;
		} else if ((*enxame)[p]->pbest != NULL
				&& (*enxame)[p]->pbest->custo < gbest->custo
				&& (*enxame)[p]->pbest->tempo < gbest->tempo) {
			gbest = (*enxame)[p]->pbest;
		} else if ((*enxame)[p]->pbest != NULL
				&& (*enxame)[p]->pbest->custo < gbest->custo
				&& gbest->tempo == (*enxame)[p]->pbest->tempo) {
			gbest = (*enxame)[p]->pbest;
		} else if ((*enxame)[p]->pbest != NULL
				&& gbest->custo == (*enxame)[p]->pbest->custo
				&& (*enxame)[p]->pbest->tempo < gbest->tempo) {
			gbest = (*enxame)[p]->pbest;
		}//else if((*enxame)[p]->pbest!=NULL && (*enxame)[p]->pbest->custo < gbest->custo && (*enxame)[p]->pbest->tempo < gbest->tempo  && gbest->tempo <= (*enxame)[p]->d->D){
		 //gbest = (*enxame)[p]->pbest;
		 //}
	}

	for (int p = 0; p < tamanhoPopulacao; p++) {
		(*enxame)[p]->gbest = gbest;
	}
	/*
	 for (int p = 0; p < tamanhoPopulacao; p++) {
	 if((*enxame)[p]->gbest == NULL || (*enxame)[p]->pbest == NULL){
	 cout <<p<<" " <<(*enxame)[p]->gbest << " ";
	 cout <<(*enxame)[p]->pbest << endl;
	 }
	 }
	 */
}

void Heuristicas::atualizarVelocidades(int tamanhoPopulacao,
		vector<Solucao*>* enxame, float w, float c1, float c2,
		int maxVparticula, int minVpartucula) {
	//atualizar posicao e velecidade (pela formula)
	for (int p = 0; p < tamanhoPopulacao; p++) {
		srand((unsigned) time(NULL));
		float r1 = (float) rand() / RAND_MAX + (rand() % 1);
		float r2 = (float) rand() / RAND_MAX + (rand() % 1);
		for (int pos = 1; pos < d->j * 2; pos++) { // atualizando velocidades
			int pbest, gbest, atual; // x é o valor do propio variavel
			if (pos == d->j || pos == d->j - 1) {
				continue;
			}

			if (pos < d->j) {

				/*cout << (*enxame)[p]->pbest<< endl;
				 cout << (*enxame)[p]->pbest->x.size()<< endl;
				 cout << (*enxame)[p]->pbest->x[pos]<< endl;*/

				Solucao *parti = (*enxame)[p];
				Solucao * pbe = (*enxame)[p]->pbest;

				pbest = (*enxame)[p]->pbest->x[pos];
				gbest = (*enxame)[p]->gbest->x[pos];
				atual = (*enxame)[p]->x[pos];
			} else {
				pbest = (*enxame)[p]->pbest->M[pos - d->j];
				gbest = (*enxame)[p]->gbest->M[pos - d->j];
				atual = (*enxame)[p]->M[pos - d->j];
			}

			int v = (*enxame)[p]->v[pos];
			(*enxame)[p]->v_new[pos] = w * v + (c1 * r1 * (pbest - atual)) + //c1 r1 (pbest - v)
					(c2 * r2 * (gbest - atual));		//c2 r2 (pbest - v)

			/*// limite de velocidade mais apertado
			 if (pos < d->j) {

			 int min = (*enxame)[p]->verificarTempoInicioCedo(pos);
			 int max = (*enxame)[p]->verificarTempoInicioTarde(pos);

			 if ((*enxame)[p]->Ti[pos] +  (*enxame)[p]->v_new[pos] > max) { // limites de velocidade
			 (*enxame)[p]->v_new[pos] = max - (*enxame)[p]->Ti[pos] ;
			 } else if ( (*enxame)[p]->Ti[pos] + (*enxame)[p]->v_new[pos] < min) {
			 (*enxame)[p]->v_new[pos] =  min - (*enxame)[p]->Ti[pos];
			 }
			 }
			 */

			if (pos > d->j) {		// limite de velocidade dos modos
				if (atual + (*enxame)[p]->v_new[pos] < 0) {
					(*enxame)[p]->v_new[pos] = 0;
				} else if (atual + (*enxame)[p]->v_new[pos]
						> d->M[pos - d->j]) {
					(*enxame)[p]->v_new[pos] = d->M[pos - d->j];
				}
			}

			if ((*enxame)[p]->v_new[pos] > maxVparticula) { // limites de velocidade
				(*enxame)[p]->v_new[pos] = maxVparticula;
			} else if ((*enxame)[p]->v_new[pos] < minVpartucula) {
				(*enxame)[p]->v_new[pos] = minVpartucula;
			}

		}

	}
}

void Heuristicas::atualizarPosicoes(int tamanhoPopulacao,
		vector<Solucao*>* enxame) {
	// atualiza solucao verificando se precedencia é respeirada

	for (int p = 0; p < tamanhoPopulacao; p++) {
		//Grafico g;
		//g.plotarGraficoDaSolucao((*enxame)[p]);
		for (int pos = 1; pos < d->j - 1; pos++) {

			int ti_min_old = (*enxame)[p]->verificarTempoInicioCedo(pos); // no modo antigo
			int tf_max_old = (*enxame)[p]->verificarTempoFimMaisTardeDentroDeD(
					pos); // no modo antigo
			// janela antiga

			int x_new = (*enxame)[p]->v_new[pos] + (*enxame)[p]->x[pos];
			int ti_atual = (*enxame)[p]->Ti[pos];
			int fal_new = (*enxame)[p]->possiveis_qi[pos][x_new];
			int fal_atual = (*enxame)[p]->fal[pos];
			int tf_new_fal = (*enxame)[p]->Ti[fal_new]
					+ (*enxame)[p]->D[fal_new];
			int new_ti = -1;

			//atualizar modos e duracoes
			int antigo_modo = (*enxame)[p]->M[pos];

			(*enxame)[p]->M[pos] = (*enxame)[p]->M[pos]
					+ (*enxame)[p]->v_new[pos + d->j];
			(*enxame)[p]->D[pos] = d->d[pos][(*enxame)[p]->M[pos]];
			if ((*enxame)[p]->D[pos] == 0 && pos != d->j - 1) {
				cout << pos + d->j << " . " << (*enxame)[p]->v_new[pos + d->j]
						<< " , " << (*enxame)[p]->M[pos] << endl;
				cout << (*enxame)[p]->M[pos] << endl;
			}

			//ao alterar o modo, verificar se nao vai prejudicar os sussesores

			if (tf_max_old - ti_min_old < (*enxame)[p]->D[pos]) {// modo nao pode ser alocado
				// altera para o menor modo possivel
				(*enxame)[p]->M[pos] =
						(*enxame)[p]->verificarMelhorModoPeloTempo(pos);
				(*enxame)[p]->D[pos] = d->d[pos][(*enxame)[p]->M[pos]];
				new_ti = tf_new_fal;
			} else if (tf_max_old - ti_min_old == (*enxame)[p]->D[pos]) {
				new_ti = ti_min_old;
				(*enxame)[p]->v_new[pos] = 0;
				(*enxame)[p]->preencherFalXComAntecessores(pos);

			} else {// caso onde existe uma folga para a atividade ser alocada
				new_ti = tf_new_fal;
			}

			// depois desses passo, ou o espaço para alocar a atividade foi feito
			// ou sua velocidade foi reduzida
			(*enxame)[p]->alocarAtividade(pos, new_ti, (*enxame)[p]->M[pos]);
		}

	}

	for (int p = 0; p < tamanhoPopulacao; p++) {
		for (int pos = 1; pos < d->j * 2; pos++) {
			(*enxame)[p]->v[pos] = (*enxame)[p]->v_new[pos];
			(*enxame)[p]->v_new[pos] = 0;

		}

		int t_oud = (*enxame)[p]->tempo;
		int c_oud = (*enxame)[p]->custo;

		(*enxame)[p]->calcular_tempo();
		(*enxame)[p]->atualizarTodaDemanda();
		(*enxame)[p]->calcular_custo();

		/*(if ((*enxame)[p]->tempo < 11) {
		 cout << "mudou o tempo da particula " << p << " de " << t_oud << " para " << (*enxame)[p]->tempo << endl;
		 // Grafico g;
		 //g.plotarGraficoDaSolucao((*enxame)[p]);
		 }

		 if ((*enxame)[p]->tempo != t_oud) {
		 //cout << "mudou o custo da particula " << p << " de " << c_oud << " para " << (*enxame)[p]->custo << endl;
		 }*/

	}
}

void Heuristicas::addFronteiraDeParetoPSO(vector<Solucao*> *enxame,
		list<Solucao*> *gbests) {
	for (int p = 0; p < enxame->size(); p++) {
		bool inGbest = false;
		list<Solucao*>::iterator gb = gbests->begin();
		for (; gb != gbests->end(); gb++) {

			if ((*enxame)[p]->pbest->tempo < (*gb)->tempo
					&& (*enxame)[p]->pbest->custo < (*gb)->custo) {

				gb = gbests->erase(gb);
				gbests->insert(gb, (*enxame)[p]->pbest);

				inGbest = true;

				//gb = gbests->begin();// reinicia
				for (; gb != gbests->end(); gb++) {
					if ((*enxame)[p]->pbest->tempo < (*gb)->tempo
							&& (*enxame)[p]->pbest->custo < (*gb)->custo) {
						gb = gbests->erase(gb);
					}
				}
				break;

			} else if ((*gb)->tempo < (*enxame)[p]->pbest->tempo
					&& (*gb)->custo < (*enxame)[p]->pbest->custo) {
				break;
			} else if ((*gb)->tempo == (*enxame)[p]->pbest->tempo
					&& (*gb)->custo == (*enxame)[p]->pbest->custo) {
				inGbest = true;
				//break;
			} else if ((*gb)->tempo == (*enxame)[p]->pbest->tempo
					&& (*gb)->custo < (*enxame)[p]->pbest->custo) {
				inGbest = true;
			}

		}

		if (gb == gbests->end() && !inGbest) { // nao foi adicionado e nem foi dominado por ninquem
			gbests->push_back((*enxame)[p]);
		}

	}

	SolucaoCompareAG sc;
	gbests->sort(sc);

}

void Heuristicas::iniciarEnxame(int tamanhoPopulacao, int maxVparticula,
		int minVpartucula, vector<Solucao*>* enxame) {

	//populacao inicial

	for (int tam = 0; tam < 5; tam++) {
		(*enxame)[tam] = new Solucao(d);
		//(*enxame)[tam]->iniciarSolucaoComModosAleatoriosDentroDaDataLimite();
	}

	//(*enxame)[0]->iniciarSolucaoComMelhorMakespan();

	//(*enxame)[0]->iniciarSolucaoComMelhorCusto();
	(*enxame)[0]->iniciarSolucaoComModosAleatoriosDentroDaDataLimite();
	(*enxame)[1]->iniciarSolucaoComMelhorMakespan();
	//(*enxame)[1]->iniciarSolucaoComModosAleatoriosDentroDaDataLimite();

	//(*enxame)[2]->iniciarSolucaoComMenorUtilizacao();
	(*enxame)[2]->iniciarSolucaoComModosAleatoriosDentroDaDataLimite();
	//(*enxame)[3]->iniciarSolucaoComMenorUtilizacaoBalanceadaDeRecursos();
	(*enxame)[3]->iniciarSolucaoComModosAleatoriosDentroDaDataLimite();
	(*enxame)[4]->iniciarSolucaoComModosAleatoriosDentroDaDataLimite();

	for (int tam = 5; tam < tamanhoPopulacao; tam++) {
		(*enxame)[tam] = new Solucao(d);
		(*enxame)[tam]->iniciarSolucaoComModosAleatoriosDentroDaDataLimite();
	}

	for (int p = 0; p < tamanhoPopulacao; p++) {
		(*enxame)[p]->v = vector<int>(d->j * 2);
		(*enxame)[p]->v_new = vector<int>(d->j * 2, 0); // nova velocidade

		(*enxame)[p]->fal = vector<int>(d->j * 2, -1);

		(*enxame)[p]->v[0] = 0;
		(*enxame)[p]->v[d->j] = 0;
		(*enxame)[p]->v[d->j - 1] = 0;
		(*enxame)[p]->v[(d->j - 1) * 2] = 0;

		(*enxame)[p]->x = vector<int>(d->j, 0);

		// tem que ser um vetor de listas de inteiro
		(*enxame)[p]->possiveis_qi = vector < vector<int>
				> (d->j, vector<int>(0));
		(*enxame)[p]->preencherPossiveisQi();

		(*enxame)[p]->contruirFal();

		for (int pos = 1; pos < d->j; pos++) {
			// velocidades iniciais aleatorias
			int max, min, mmax, mmin, vpos, vmod;

			min = 0 - (*enxame)[p]->x[pos];
			max = (*enxame)[p]->possiveis_qi[pos].size() - (*enxame)[p]->x[pos];

			vpos = rand() % ((max - min) + 1) + min;

			if (d->M[pos] > 1) {
				mmin = 0 - (*enxame)[p]->M[pos];
				mmax = (d->M[pos] - 1) - (*enxame)[p]->M[pos];
				vmod = rand() % ((mmax - mmin) + 1) + mmin;
			} else {
				vmod = 0;
			}

			if (vpos > maxVparticula) {
				// limites de velocidade
				vpos = maxVparticula;
			} else if (vpos < minVpartucula) {
				vpos = minVpartucula;
			}

			(*enxame)[p]->v[pos] = vpos;
			(*enxame)[p]->v[pos + d->j] = vmod;
		}
	}
}

Solucao * Heuristicas::geneticAlgorithms(int geracoes) {
	vector<Solucao> populacao; //populacao sempre deve ter um numero par de individuos
	int tamanhoPopulacao = 20;

	//populacao inicial
	for (int tam = 0; tam < tamanhoPopulacao; tam++) {
		populacao.push_back(new Solucao(d));
	}

	populacao[0].iniciarSolucaoComMelhorCusto();
	populacao[1].iniciarSolucaoComMelhorMakespan();
	populacao[2].iniciarSolucaoComMenorUtilizacao();
	populacao[3].iniciarSolucaoComMenorUtilizacaoBalanceadaDeRecursos();
	populacao[4].iniciarSolucaoComModosAleatoriosDentroDaDataLimite();

	for (int tam = 5; tam < tamanhoPopulacao; tam++) {
		populacao[tam].iniciarSolucaoComModosAleatoriosDentroDaDataLimite();
		//populacao[tam].iniciarSolucaoComModosAleatorios();
	}

	for (int g = 0; g < geracoes; g++) {

		/*avaliacao da populacao*/
		SolucaoCompareAG sAG;
		SolucaoComparePorcentagem scp;

		sort(populacao.begin(), populacao.end(), sAG);

		/*selecao e cruzamento*/
		vector<Solucao> gerados = selecaoECruzamento(populacao);

		for (int i = 0; i < gerados.size(); i++) {
			populacao.push_back(gerados[i]);
		}

		sort(populacao.begin(), populacao.end(), sAG);

		//populcao  com tamanho fixo tamanhoPopulacao
		for (int ruin = populacao.size() - 1;
				populacao.size() != tamanhoPopulacao; ruin--) {
			populacao.erase(--populacao.end());
		}

		if ((populacao.size() % 2) != 0) { //populacao impar
			populacao.erase(--populacao.end());
		}

		srand((unsigned) time(NULL));
		int rad = rand() % populacao.size();
		vizinhancaCPLEX(&populacao[0]);
		vizinhancaCPLEX(&populacao[rad]);

		sort(populacao.begin(), populacao.end(), sAG);

		for (int i = 0; i < populacao.size(); i++) {
			addFronteiraDePareto(&populacao[i]);
		}
	}

	for (int i = 0; i < populacao.size(); i++) {
		addFronteiraDePareto(&populacao[i]);
	}

	Solucao * best = new Solucao(populacao[0]);
	vizinhancaCPLEX(best);
	return best;

}

Solucao * Heuristicas::geneticAlgorithms(int geracoes, int tamanhoPopulacao,  float mutacao) {

	vector<Solucao> populacao; //populacao sempre deve ter um numero par de individuos

	//populacao inicial
	for (int tam = 0; tam < tamanhoPopulacao; tam++) {
		populacao.push_back(new Solucao(d));
	}

	populacao[0].iniciarSolucaoComMelhorCusto();
	populacao[1].iniciarSolucaoComMelhorMakespan();
	populacao[2].iniciarSolucaoComMenorUtilizacao();
	populacao[3].iniciarSolucaoComMenorUtilizacaoBalanceadaDeRecursos();
	populacao[4].iniciarSolucaoComModosAleatoriosDentroDaDataLimite();

	for (int tam = 5; tam < tamanhoPopulacao; tam++) {
		populacao[tam].iniciarSolucaoComModosAleatoriosDentroDaDataLimite();
		//populacao[tam].iniciarSolucaoComModosAleatorios();
	}

	for (int g = 0; g < geracoes; g++) {

		/*avaliacao da populacao*/
		SolucaoCompareAG sAG;
		SolucaoComparePorcentagem scp;

		sort(populacao.begin(), populacao.end(), sAG);

		/*selecao e cruzamento*/
		vector<Solucao> gerados = selecaoECruzamento(populacao);

		for (int i = 0; i < gerados.size(); i++) {
			populacao.push_back(gerados[i]);
		}

		sort(populacao.begin(), populacao.end(), sAG);

		//populcao  com tamanho fixo tamanhoPopulacao
		for (int ruin = populacao.size() - 1;
				populacao.size() != tamanhoPopulacao; ruin--) {
			populacao.erase(--populacao.end());
		}

		if ((populacao.size() % 2) != 0) { //populacao impar
			populacao.erase(--populacao.end());
		}

		srand((unsigned) time(NULL));
		int rad = rand() % populacao.size();
		vizinhancaCPLEX(&populacao[0]);
		vizinhancaCPLEX(&populacao[rad]);

		sort(populacao.begin(), populacao.end(), sAG);

		for (int i = 0; i < populacao.size(); i++) {
			addFronteiraDePareto(&populacao[i]);
		}
	}

	for (int i = 0; i < populacao.size(); i++) {
		addFronteiraDePareto(&populacao[i]);
	}

	Solucao * best = new Solucao(populacao[0]);
	vizinhancaCPLEX(best);
	return best;

}

vector<Solucao> Heuristicas::roleta(vector<Solucao> & populacao,
		int qt_selecionados) {

	vector<Solucao> selecionados;
	vector<float> fitness(populacao.size());

	int min_time = populacao[0].tempo;
	float min_custo = populacao[0].custo;
	float max_custo = populacao[0].custo;

	for (int i = 1; i < populacao.size(); i++) { // calcula max e min custo e tempo
		if (min_time > populacao[i].tempo) {
			min_time = populacao[i].tempo;
		}
		if (min_custo > populacao[i].custo) {
			min_custo = populacao[i].custo;
		}
		if (max_custo < populacao[i].custo) {
			max_custo = populacao[i].custo;
		}
	};

	for (int qt = 0; qt < qt_selecionados; qt++) {

		SolucaoCompareAGFitness sAGF;
		sort(populacao.begin(), populacao.end(), sAGF);

		float sum_fitness = 0;
		for (int i = 0; i < populacao.size(); i++) {
			fitness[i] = populacao[i].fitness(min_time, max_custo, min_custo); // calcula o fitness de cada
			sum_fitness += fitness[i];		// somatorio total do fitness
		}

		srand((unsigned) time(0));
		float seed = fmod(rand(), sum_fitness);
		for (int i = 0; i < populacao.size(); i++) {
			if (fitness[i] >= seed) {		// encontramos o escolhido
				bool contens = false;
				do {// verificando se ele ja foi escolhido, se sim, passa para o seu proximo (i++)
					contens = false;
					for (int s = 0; s < selecionados.size(); s++) {

						if (selecionados[s].custo == populacao[i].custo
								&& selecionados[s].tempo
										== populacao[i].tempo) {

							contens = true;
							i++;
							break;
						}
					}
					if (i == populacao.size()) {
						i = 0;
					}
				} while (contens);
				// i é o selecionado
				selecionados.push_back(populacao[i]);
				break;
			} else {
				seed -= fitness[i];
			}
		}
	}

	return selecionados;
}

vector<Solucao> Heuristicas::selecaoECruzamento(vector<Solucao> & populacao) {
	/*selecao e cruzamento*/
	vector<Solucao> gerados;

	switch (1) {
	case 1: //cruzamento aleatorio
		for (int ind = 0, ind2 = populacao.size() - 1; ind < ind2;
				ind++, ind2--) {
			if (populacao[ind].tempo == populacao[ind2].tempo
					&& populacao[ind].custo == populacao[ind].custo) {
				gerados.push_back(
						cruzamento(populacao[0],
								populacao[populacao.size() - 1]));
			} else {
				gerados.push_back(cruzamento(populacao[0], populacao[ind2]));
			}
		}
		break;

	case 2: //cruzamento 2
		for (int ind2 = populacao.size() - 1; ind2 > 0; ind2--) {
			if (populacao[0].tempo == populacao[ind2].tempo
					&& populacao[0].custo == populacao[ind2].custo) {
				if (populacao[0].tempo == populacao[populacao.size() - 1].tempo
						&& populacao[0].custo
								== populacao[populacao.size() - 1].custo) {
					break; // populacao identica
				}
				vector<Solucao> filhos = cruzamento2(populacao[0],
						populacao[populacao.size() - 1]);
				gerados.push_back(filhos[0]);
				gerados.push_back(filhos[1]);
			} else {
				vector<Solucao> filhos = cruzamento2(populacao[0],
						populacao[ind2]); // o erro esta aqui
				gerados.push_back(filhos[0]);
				gerados.push_back(filhos[1]);
			}
		}
		break;
	case 3:
		int qt_selecionados = 0.5 * populacao.size(); // 50%dos indivíduos serao selecionados

		vector<Solucao> selecionados = roleta(populacao, qt_selecionados);

		int ind1 = 0;
		for (int ind2 = ind1 + 1; ind2 < selecionados.size(); ind2++, ind1++) {
			Solucao s = cruzamento(selecionados[ind1], selecionados[ind2]);
			gerados.push_back(s);
		}
		break;
	}

	return gerados;
}

void Heuristicas::mutar(Solucao s) {
	//usar vizinhancas para tentar melhorar a solucao
	Solucao * vizinha = vnd(&s);
	if (vizinha->tempo <= s.tempo && vizinha->custo < s.custo) { // vizinha melhorou
	//delete &s;
		cout << "mutou de " << s.tempo << " | " << s.custo;
		cout << ", para " << vizinha->tempo << " | " << vizinha->custo << endl
				<< endl;
		s = new Solucao(vizinha);

	} else {
		delete vizinha;
	}
}

Solucao* Heuristicas::vnd(Solucao* inicial) {
	SolucaoCompareAG sAG;
	Solucao * best = new Solucao(inicial);
	Solucao * v;
	while (true) {
		v = this->vizinhacaBalancearUtilizacaoDeRecursos(inicial);
		if (v->tempo > best->tempo || v->custo >= best->custo) {
			v = this->vizinhacaDeModos(inicial);
			if (v->tempo > best->tempo || v->custo >= best->custo) {
				v = this->vizinhacaDeslocamentoTemporal(inicial);
				if (v->tempo > best->tempo || v->custo >= best->custo) {
					v = this->vizinhacaDeslocarParaDireita(inicial);
					if (v->tempo > best->tempo || v->custo >= best->custo) {
						delete v;
						break;
					} else {
						delete best;
						best = v;
						continue;
					}
				} else {
					delete best;
					best = v;
					continue;
				}
			} else {
				delete best;
				best = v;
				continue;
			}
		} else {
			delete best;
			best = v;
			continue;
		}

	}

	return best;

}

Solucao Heuristicas::cruzamento(Solucao s1, Solucao s2) {
	Solucao s(d);
	//bool acessoS1 = rand() % 2;
	for (int j = 0; j < d->j - 1; j++) {
		bool acessoS1 = rand() % 2;
		if (acessoS1) {	// o cromossomo da atividade j sera herdado de s1
			int tic = calcularTempoDeInicioMaisCedoDeJ(&s, j);
			if (s1.Ti[j] >= tic) {	//pode alocar
				s.alocarAtividade(j, s1.Ti[j], s1.M[j]);
			} else {// nao pode alocar j em Ti por que vai quebrar a precedencia de j, por isso aloca no menor tempo possivel tic
				s.alocarAtividade(j, tic, s1.M[j]);
			}
		} else {	// o cromossomo da atividade j sera herdado de s2
			int tic = calcularTempoDeInicioMaisCedoDeJ(&s, j);
			if (s2.Ti[j] >= tic) {	//pode alocar
				s.alocarAtividade(j, s2.Ti[j], s2.M[j]);
			} else {// nao pode alocar j em Ti por que vai quebrar a precedencia de j, por isso aloca no menor tempo possivel tic
				s.alocarAtividade(j, tic, s2.M[j]);
			}
		}
	}
	s.alocarAtividade(d->j - 1, s.calcular_tempo(), 0);
	s.calcular_custo();

	return s;
}

vector<Solucao> Heuristicas::cruzamento2(Solucao s1, Solucao s2) {
	Solucao f1(d);
	Solucao f2(d);

	bool acessoS1 = rand() % 2;
	for (int j = 0; j < d->j - 1; j++) {

		if (acessoS1) {	// o cromossomo da atividade j sera herdado de s1
			int ticF1 = calcularTempoDeInicioMaisCedoDeJ(&f1, j);
			int ticF2 = calcularTempoDeInicioMaisCedoDeJ(&f2, j);
			if (s1.Ti[j] >= ticF1) {	//F1 receberar cromossomo de S1
				f1.alocarAtividade(j, s1.Ti[j], s1.M[j]);
			} else {// nao pode alocar j em Ti por que vai quebrar a precedencia de j, por isso aloca no menor tempo possivel tic
				f1.alocarAtividade(j, ticF1, s1.M[j]);
			}

			if (s2.Ti[j] >= ticF2) {	//F2 receberar cromossomo de S2
				f2.alocarAtividade(j, s2.Ti[j], s2.M[j]);
			} else {// nao pode alocar j em Ti por que vai quebrar a precedencia de j, por isso aloca no menor tempo possivel tic
				f2.alocarAtividade(j, ticF2, s2.M[j]);
			}

		} else {	// o cromossomo da atividade j sera herdado de s2

			int ticF1 = calcularTempoDeInicioMaisCedoDeJ(&f1, j);
			int ticF2 = calcularTempoDeInicioMaisCedoDeJ(&f2, j);
			if (s2.Ti[j] >= ticF1) {	//F1 receberar cromossomo de S2
				f1.alocarAtividade(j, s2.Ti[j], s2.M[j]);
			} else {// nao pode alocar j em Ti por que vai quebrar a precedencia de j, por isso aloca no menor tempo possivel tic
				f1.alocarAtividade(j, ticF1, s2.M[j]);
			}

			if (s1.Ti[j] >= ticF2) {	//F2 receberar cromossomo de S1
				f2.alocarAtividade(j, s1.Ti[j], s1.M[j]);
			} else {// nao pode alocar j em Ti por que vai quebrar a precedencia de j, por isso aloca no menor tempo possivel tic
				f2.alocarAtividade(j, ticF2, s1.M[j]);
			}
		}
		acessoS1 = !acessoS1;
	}
	f1.alocarAtividade(d->j - 1, f1.calcular_tempo(), 0);
	f2.alocarAtividade(d->j - 1, f2.calcular_tempo(), 0);

	f1.calcular_custo();
	f2.calcular_custo();

	vector<Solucao> filhos;
	filhos.push_back(f1);
	filhos.push_back(f2);

	return filhos;
}

bool Heuristicas::addFronteiraDePareto(Solucao *s) {

	list<Solucao>::iterator it = fronteira.begin();
	for (; it != fronteira.end(); it++) {
		if (s->tempo < it->tempo && s->custo < it->custo) { // s domina it
		// coloca s e retira it
			it = fronteira.erase(it);
			fronteira.insert(it, s);

			for (fronteira.begin(); it != fronteira.end(); it++) {//retirar as outras solucao que s domina
				if (s->tempo < it->tempo && s->custo < it->custo) {
					it = fronteira.erase(it);
				}
			}

			SolucaoCompareAG sc;
			fronteira.sort(sc);
			return true;
		}
		if (s->tempo > it->tempo && s->custo > it->custo) {		// it domina s
		// s e descartada, pois ja tem uma melhor do que s em tempo e em custo na fronteira
			return false;
		}

	}
	// caso nao ocoreu nenhuma dominacao entao s deve ser colocado na fronteira
	fronteira.push_back(s);
	SolucaoCompare sc;
	fronteira.sort(sc);

	return true;
}

Solucao * Heuristicas::vizinhancaCPLEX(Solucao *s) {
	int n_atividades = d->j * 0.5;
	CPLEX cp;
	list<int> atividades_fixas;

	/*
	 list<int>::iterator su = d->S[0].begin();		//sucessores de 0
	 for (; su != d->S[0].end(); su++) {
	 atividades_fixas.push_back(*su);
	 }
	 list<int>::iterator pre = d->H[d->j-1].begin();		//predecessores de j-1
	 for (; pre != d->H[d->j-1].end(); pre++) {
	 atividades_fixas.push_back(*pre);
	 }
	 */

	/*

	 //aleatorio respeitando o n_atividades
	 while (atividades_fixas.size() != n_atividades) {
	 int randomica = rand() % (d->j - 1);
	 bool ja_add = false;
	 list<int>::iterator fi = atividades_fixas.begin();
	 for (; fi != atividades_fixas.end(); fi++) {
	 if (*fi == randomica) {
	 ja_add = true;
	 }
	 }
	 if (!ja_add) {
	 atividades_fixas.push_back(randomica);
	 }
	 }*/

	for (int j = 1; j < d->j - 1; j++) {
		bool top = false;
		int ti_j = s->Ti[j];
		for (int k = 0; k < d->tipos; k++) {
			if (s->tr[ti_j][k] >= s->demanda[k]) {
				top = true;
				break;
			}
		}
		if (!top) {
			atividades_fixas.push_back(j);
		}
	}

	if (atividades_fixas.size() < (d->j - 1) * 0.3) {
		for (int j = 1; j < d->j - 1; j++) {
			if (s->Ti[j] <= s->tempo / 2) {
				atividades_fixas.push_back(j);
			}
		}
	}

	if (atividades_fixas.size() < (d->j - 1) * 0.3) {
		for (int j = 1; j < d->j - 1; j++) {
			if (s->Ti[j] > s->tempo / 2) {
				atividades_fixas.push_back(j);
			}
		}
	}

	//cout << "fixou " << atividades_fixas.size() << " atividades" << endl;
	cp.construirSolucaoParcial(s, atividades_fixas);
	//cp.construirModosSolucaoParcial(s);

}

Solucao * Heuristicas::vizinhacaBalancearUtilizacaoDeRecursos(Solucao * s) {
	s->calcular_valores();
	Solucao * s1 = new Solucao(s);	//copia a solucao atual
	Solucao * best = new Solucao(s);	//melhor solucao encontrada

	vector<int> recursosMaisCaros = s->ordenarRecursosPorPrecos();
	for (int k = 0; k < recursosMaisCaros.size(); k++) {
		int recAtual = recursosMaisCaros[k];

		for (int t = 0; t <= s1->tempo; t++) {
			if (s1->tr[t][recAtual] == s->demanda[recAtual]) {// ponto de maior utilizacao desse recurso
				for (int j = 0; j < d->j; j++) {
					if (s1->Ti[j] == t) {// a atividade j inicia no ponto crito, ela deve ser melhorada
						int tic = calcularTempoDeInicioMaisCedoDeJ(s1, j);
						int tft = calcularTempoFimMaisTardeDeJ(s1, j);
						int m_old = s->M[j];

						int timt = tft - d->d[j][m_old];
						for (int m = 0; m < d->M[j]; m++) {	//testa se variando o modo funciona
							for (int new_t = tic; new_t <= timt; new_t++) {

								s1->alocarAtividade(j, new_t, m);
								if (s1->calcular_custo() < best->custo) {//melhorou
									delete best;
									//cout << "Melhorou" << endl;
									best = s1;	//melhorou
								} else {	// volta a alocacao como estava
									s1->alocarAtividade(j, t, m_old);
								}

							}

						}

					}

				}
			}
		}

	}

	if (s1 != best) {
		delete s1;
	}
	if (s->custo == best->custo) {
		delete best;
		return s;
	}
	return best;
}

Solucao* Heuristicas::vizinhacaDeslocarParaDireita(Solucao *s) {
	s->calcular_valores();
	Solucao * s1 = new Solucao(s);		//copia a solucao atual

	for (int j = d->j - 1; j > 0; j--) {

		int tic = calcularTempoDeInicioMaisCedoDeJ(s1, j);

		int tft = calcularTempoFimMaisTardeDeJ(s1, j);

		if (tic + s->D[j] == tft) {	//a atividade nao pode ser deslocada, sua janela temporal ja esta preencida por ela
			continue;
		}

		int timt = tft - s1->D[j];	//tempo de inicio mais tarde nesse modo

		int ti_old = s1->Ti[j];
		s1->alocarAtividade(j, timt, s1->M[j]);
		if (s1->calcular_custo() > s->custo) {
			s1->alocarAtividade(j, ti_old, s1->M[j]);
		}

	}
	return s1;
}

/*tentativa de melhorar o custo sem alterar o tempo*/
Solucao* Heuristicas::vizinhacaDeslocamentoTemporal(Solucao*s) {
	s->calcular_valores();
	Solucao * s1 = new Solucao(s);		//copia a solucao atual
	Solucao * best = new Solucao(s);

	for (int j = 0; j < d->j - 1; j++) {

		int tic = calcularTempoDeInicioMaisCedoDeJ(s1, j);

		int tft = calcularTempoFimMaisTardeDeJ(s1, j);

		if (tic + s->D[j] == tft) {	//a atividade nao pode ser deslocada, sua janela temporal ja esta preencida por ela
			continue;
			/*int m_old = d->M[j];
			 for (int m = 0; m < d->M[j]; m++) {
			 if (m_old != m) {
			 s1->alocarAtividade(j, tic, m);
			 tic = calcularTempoDeInicioMaisCedoDeJ(s1, j);
			 tft = calcularTempoFimMaisTardeDeJ(s1, j);
			 if(tic + s->D[j] != tft){
			 break;
			 }
			 }
			 }*/
		}

		for (int m = 0; m < d->M[j]; m++) {
			int timt = tft - s1->D[j];	//tempo de inicio mais tarde nesse modo
			int ti_old = s1->Ti[j];
			int m_old = d->M[j];
			for (int t = tic; t <= timt; t++) {

				s1->alocarAtividade(j, t, m);
				if (s1->calcular_custo() < best->custo) {
					cout << "\n\n\n\n melhorou de " << s1->custo << " para "
							<< best->custo << endl;
					delete best;
					best = s1;
				} else {
					s1->alocarAtividade(j, ti_old, s->M[j]);
				}

			}

		}

	}
	if (s1 != best) {
		delete s1;
	}
	if (s->custo == best->custo) {
		delete best;
		return s;
	}
	return best;
}

Solucao* Heuristicas::vizinhacaDeModos(Solucao *s) {

	Solucao * s2 = new Solucao(s);
	Solucao * melhorTempo = new Solucao(s2); //melhor solucao por tempo
	Solucao * melhorCusto = new Solucao(s2); //melhor solucao por custo

	for (int j = 1; j < d->j; j++) {
		int m_aux = s2->M[j];
		for (int m = 0; m < d->M[j]; m++) {
			if (m == m_aux) { //desconsidera o modo atual
				continue;
			}

			s2->alocarAtividade(j, s2->Ti[j], m);
			s2->realocarAtividadesApartirDaAtividade(j);
			s2->calcular_valores();
			if (s2->custo < melhorCusto->custo) {
				delete melhorCusto;
				melhorCusto = s2;
			}
			if (s2->tempo < melhorTempo->tempo) {
				delete melhorTempo;
				melhorTempo = s2;
			}
		}

	}
	if (s2 != melhorCusto && s2 != melhorTempo) {
		delete s2;
	}
	if (melhorTempo->tempo < s->tempo || melhorCusto->custo < s->custo) {

		if (melhorTempo->tempo == melhorCusto->tempo) {
			delete melhorTempo;
			return melhorCusto;
		} else if (melhorCusto->custo == melhorTempo->custo) {
			delete melhorCusto;
			return melhorTempo;
		} else { //salvar a solucao que sera descartada em um array de boas solucoes!!!
			float reducaoDeCusto = ((s->custo - melhorCusto->custo) * 100)
					/ s->custo; //porcentagem de reducao de custo
			float reducaoDeTempo = ((s->tempo - melhorTempo->tempo) * 100)
					/ s->tempo; //porcentagem de reducao de tempo

			if (reducaoDeCusto > reducaoDeTempo) {
				delete melhorTempo;
				return melhorCusto;
			} else {
				delete melhorCusto;
				return melhorTempo;
			}
		}
	} else {
		delete melhorTempo;
		delete melhorCusto;
		if (s2 == NULL) {
			delete s2;
		}
		return new Solucao(*s);
	}
}

/*Cauculos*/
int Heuristicas::calcularTempoDeInicioMaisCedoDeJ(Solucao *s, int j) {
	int tic = 0;		//tempo de inicio mais cedo de j
	list<int>::iterator pr = d->H[j].begin();		//predecessores de j
	for (; pr != d->H[j].end(); pr++) {
		if ((s->Ti[*pr] + s->D[*pr]) > tic) {
			tic = (s->Ti[*pr] + s->D[*pr]);
		}
	}
	return tic;
}

int Heuristicas::calcularTempoFimMaisTardeDeJ(Solucao *s, int j) {
	int tft = s->tempo;		//tempo de fim mais tarde de j
	list<int>::iterator su = d->S[j].begin();		//sucessores de j
	for (; su != d->S[j].end(); su++) {
		if (s->Ti[*su] < tft) {
			tft = s->Ti[*su];
		}
	}
	return tft;
}

Heuristicas::Heuristicas(Dados *d) :
		fronteira() {
	this->d = d;
}

Heuristicas::~Heuristicas() {
	//fronteira.clear();
}

