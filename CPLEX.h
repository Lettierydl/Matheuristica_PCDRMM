/*
 * CPLEX.h
 *
 *  Created on: 11/11/2015
 *      Author: Lettiery
 */

#include "Dados.h"
#include "Arquivo.h"
#include "Solucao.h"
#include "Grafico.h"
#include "Teste.h"

#include <iostream>

#include <iostream>
#include <iomanip>

#include <ilcplex/ilocplex.h>

using std::cout;
using std::cin;
using std::ios;
using std::cerr;
using std::endl;
using std::setprecision;

#include <fstream>
#include <list>
#include <vector>

using std::ifstream;

#include <stdlib.h>

#include <climits>
#include <string.h>

#include <math.h>

using namespace std ;

class CPLEX {
public:



	Solucao* OptimizeCplex(Dados *d);
	void restricaoCusto(int T, IloEnv env, IloArray<IloArray<IloBoolVarArray> > x,
			const IloModel& modelo, const IloNumVarArray& a, Dados* d) ;
	void restricaoJanelaDeTempoDeJ(IloEnv env,
			IloArray<IloArray<IloBoolVarArray> > x, const IloModel& modelo,
			Dados* d, int T);
	void restricaoDePrecedencia(IloEnv env, int T,
			IloArray<IloArray<IloBoolVarArray> > x, const IloModel& modelo,
			Dados* d);

	Solucao* construirSolucaoParcial(Solucao * s, list<int> atividades_fixas );

	Solucao* construirModosSolucaoParcial(Solucao * s);

	CPLEX();
	virtual ~CPLEX();
};

