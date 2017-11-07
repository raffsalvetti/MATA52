/*
 * Algoritmo.h
 *
 *  Created on: 12/08/2016
 *      Author: raffaello.salvetti
 */

#ifndef SRC_ALGORITMO_H_
#define SRC_ALGORITMO_H_

#include "../democollection.h"
#include <stdio.h>
#include <windows.h>

#include <wx/xy/xyplot.h>
#include <wx/xy/xylinerenderer.h>
#include <wx/xy/xysimpledataset.h>
#include <wx/multiplot.h>

#define QUANTIDADE_DE_PONTOS_NO_GRAFICO 20
#define MULTIPLICADOR_ARRAY 10

#define ENUM_SIZE 3
enum Tipo {
	CRESCENTE = 1,
	DECRESCENTE,
	ALEATORIO
};

class Algoritmo : public ChartDemo {
private:
	LARGE_INTEGER nanoTimeInicio, nanoTimeFim, frequencia;
	long unsigned int contador;
	double tempo;

protected:
	int* gerarArrayAleatorio(int n);
	int* gerarArrayOrdenado(int n);
	int* gerarArrayOrdenadoDecrescente(int n);

public:
	Algoritmo(const wxChar *nome);
	virtual ~Algoritmo();

	LARGE_INTEGER getHoraInicio() {return nanoTimeInicio;}
	void marcarHoraInicio() {QueryPerformanceCounter(&nanoTimeInicio);}

	LARGE_INTEGER getHoraFim() {return nanoTimeFim;}
	void marcarHoraFim() {QueryPerformanceCounter(&nanoTimeFim);}

	void zerarContador(){contador = 0;}

	void contar(){contador++;}

	double getTempoExecucao();
	long unsigned int getContador(){return contador;}

	virtual void ordenar(int* x, int size) = 0;
	virtual Chart *Create() override;
};

#endif /* SRC_ALGORITMO_H_ */
