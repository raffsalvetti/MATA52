/*
 * Algoritmo.cpp
 *
 *  Created on: 12/08/2016
 *      Author: raffaello.salvetti
 */

#include "Algoritmo.h"

Algoritmo::Algoritmo(const wxChar *nome) : ChartDemo(nome) {
	nanoTimeInicio = {};
	nanoTimeFim = {};
	frequencia = {};
	contador = 0;
	tempo = 0;
	srand(time(0));
	QueryPerformanceFrequency(&frequencia);
}

Algoritmo::~Algoritmo() { }

double Algoritmo::getTempoExecucao() {
	if(nanoTimeFim.QuadPart != 0 || frequencia.QuadPart != 0) {
		tempo = (double)(nanoTimeFim.QuadPart - nanoTimeInicio.QuadPart) * (1000000.0/(double)frequencia.QuadPart);
	} else {
		tempo = 0;
	}
	return tempo;
}

int* Algoritmo::gerarArrayAleatorio(int n) {
	int* x = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++) {
		*(x + i) = rand() % (n + 1);
	}
	return x;
}

int* Algoritmo::gerarArrayOrdenado(int n) {
	int* x = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++) {
		*(x + i) = i + 1;
	}
	return x;
}

int* Algoritmo::gerarArrayOrdenadoDecrescente(int n) {
	int* x = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++) {
		*(x + i) = n - i;
	}
	return x;
}

Chart *Algoritmo::Create() {
	int *x, i, tipo, n;

//	int nCM = 0, nCm = 0, nTM = 0, nTm = 0;
//	unsigned long int maiorContador = 0, menorContador = 99999999;
//	double maiorTempo = 0, menorTempo = 99999999;

	double
		dadosGraficoDecrescente[QUANTIDADE_DE_PONTOS_NO_GRAFICO][2] = {},
		dadosGraficoCrescente[QUANTIDADE_DE_PONTOS_NO_GRAFICO][2] = {},
		dadosGraficoAleatorio[QUANTIDADE_DE_PONTOS_NO_GRAFICO][2] = {},
		dadosGraficoDecrescenteTempo[QUANTIDADE_DE_PONTOS_NO_GRAFICO][2] = {},
		dadosGraficoCrescenteTempo[QUANTIDADE_DE_PONTOS_NO_GRAFICO][2] = {},
		dadosGraficoAleatorioTempo[QUANTIDADE_DE_PONTOS_NO_GRAFICO][2] = {};

	for (i = 0; i < QUANTIDADE_DE_PONTOS_NO_GRAFICO; i++) {
		n = ((i + 1) * MULTIPLICADOR_ARRAY);
		for (tipo = 1; tipo <= ENUM_SIZE; tipo++) {
			if (tipo == DECRESCENTE) {
				x = gerarArrayOrdenadoDecrescente(n);
			} else if (tipo == CRESCENTE) {
				x = gerarArrayOrdenado(n);
			} else {
				x = gerarArrayAleatorio(n);
			}

			ordenar(x, n);

			if (tipo == DECRESCENTE) {
				dadosGraficoDecrescente[i][0] = n;
				dadosGraficoDecrescente[i][1] = getContador();
				dadosGraficoDecrescenteTempo[i][0] = n;
				dadosGraficoDecrescenteTempo[i][1] = getTempoExecucao();
			} else if (tipo == CRESCENTE) {
				dadosGraficoCrescente[i][0] = n;
				dadosGraficoCrescente[i][1] = getContador();
				dadosGraficoCrescenteTempo[i][0] = n;
				dadosGraficoCrescenteTempo[i][1] = getTempoExecucao();
			} else {
				dadosGraficoAleatorio[i][0] = n;
				dadosGraficoAleatorio[i][1] = getContador();
				dadosGraficoAleatorioTempo[i][0] = n;
				dadosGraficoAleatorioTempo[i][1] = getTempoExecucao();
			}

//			if(getContador() >= maiorContador){
//				nCM = n;
//				maiorContador = getContador();
//			}
//
//			if(getContador() < menorContador){
//				nCm = n;
//				menorContador = getContador();
//			}
//
//			if(getTempoExecucao() >= maiorTempo){
//				nTM = n;
//				maiorTempo = getTempoExecucao();
//			}
//
//			if(getTempoExecucao() < maiorTempo){
//				nTm = n;
//				menorTempo = getTempoExecucao();
//			}

			free(x);
		}
	}

//	printf("maiorContador[%d]: %ul\n", nCM, maiorContador);
//	printf("menorContador[%d]: %ul\n", nCm, menorContador);
//	printf("maiorTempo[%d]: %f\n", nTM, maiorTempo);
//	printf("menorTempo[%d]: %f\n", nTm, menorTempo);

	const wxString labelPiorCaso = wxT("Pior Caso");
	const wxString labelMelhorCaso = wxT("Melhor Caso");
	const wxString labelAleatorio = wxT("Aleatório");

	//
	// objetos compartilhados
	//
	MultiPlot *multiPlot = new MultiPlot(0, 1, 5, 5);
	NumberAxis *eixoItensArray = new NumberAxis(AXIS_BOTTOM);
	eixoItensArray->SetTitle(wxT("Número de elementos no array"));
	AxisShare *bottomAxis1 = new AxisShare(eixoItensArray);

	//
	// plotagem de contadores
	//
	XYPlot *plotagemContador = new XYPlot();
	XYSimpleDataset *datasetPlotagemContador = new XYSimpleDataset();
	datasetPlotagemContador->AddSerie((double *) dadosGraficoDecrescente, WXSIZEOF(dadosGraficoDecrescente));
	datasetPlotagemContador->AddSerie((double *) dadosGraficoCrescente, WXSIZEOF(dadosGraficoCrescente));
	datasetPlotagemContador->AddSerie((double *) dadosGraficoAleatorio, WXSIZEOF(dadosGraficoAleatorio));
	datasetPlotagemContador->SetSerieName(0, labelPiorCaso);
	datasetPlotagemContador->SetSerieName(1, labelMelhorCaso);
	datasetPlotagemContador->SetSerieName(2, labelAleatorio);
	datasetPlotagemContador->SetRenderer(new XYLineRenderer());
	plotagemContador->AddDataset(datasetPlotagemContador);
	NumberAxis *leftAxis1 = new NumberAxis(AXIS_LEFT);
	leftAxis1->SetTitle(wxT("Número de Iterações (while + for)"));
	plotagemContador->AddAxis(leftAxis1);
	plotagemContador->AddAxis(bottomAxis1);
	plotagemContador->LinkDataVerticalAxis(0, 0);
	plotagemContador->LinkDataHorizontalAxis(0, 0);
	plotagemContador->SetLegend(new Legend(wxCENTER, wxRIGHT));

	//
	// plotagem de tempo
	//
	XYPlot *plotagemTempo = new XYPlot();
	XYSimpleDataset *datasetPlotagemTempo = new XYSimpleDataset();
	datasetPlotagemTempo->AddSerie((double *) dadosGraficoDecrescenteTempo, WXSIZEOF(dadosGraficoDecrescenteTempo));
	datasetPlotagemTempo->AddSerie((double *) dadosGraficoCrescenteTempo, WXSIZEOF(dadosGraficoCrescenteTempo));
	datasetPlotagemTempo->AddSerie((double *) dadosGraficoAleatorioTempo, WXSIZEOF(dadosGraficoAleatorioTempo));
	datasetPlotagemTempo->SetSerieName(0, labelPiorCaso);
	datasetPlotagemTempo->SetSerieName(1, labelMelhorCaso);
	datasetPlotagemTempo->SetSerieName(2, labelAleatorio);
	datasetPlotagemTempo->SetRenderer(new XYLineRenderer());
	plotagemTempo->AddDataset(datasetPlotagemTempo);

	NumberAxis *leftAxis2 = new NumberAxis(AXIS_LEFT);
	leftAxis2->SetTitle(wxT("Tempo de Execução (ms)"));
	AxisShare *bottomAxis2 = new AxisShare(eixoItensArray);
	bottomAxis2->SetShareVisible(true);
	plotagemTempo->AddAxis(leftAxis2);
	plotagemTempo->AddAxis(bottomAxis2);
	plotagemTempo->LinkDataVerticalAxis(0, 0);
	plotagemTempo->LinkDataHorizontalAxis(0, 0);
	plotagemTempo->SetLegend(new Legend(wxCENTER, wxRIGHT));

	multiPlot->AddPlot(plotagemContador);
	multiPlot->AddPlot(plotagemTempo);

	return new Chart(multiPlot, GetName());
}
