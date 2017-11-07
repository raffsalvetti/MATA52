/*
 * BubbleSort.cpp
 *
 *  Created on: 15/08/2016
 *      Author: raffaello.salvetti
 */

#include "Algoritmo.h"

class BubbleSort : public Algoritmo {

public: BubbleSort() : Algoritmo(wxT("Bubble Sort")) { }
public:
	virtual void ordenar(int* x, int size) {
		int i,j,aux;
		zerarContador();
		marcarHoraInicio();
		for(i = size - 1; i >= 1; i--) {
			contar();
			for(j=0; j < i ; j++) {
				contar();
				if(*(x + j) > *(x + j + 1)) {
					aux = *(x + j);
					*(x + j) = *(x + j + 1);
					*(x + j + 1) = aux;
				}
			}
		}
		marcarHoraFim();
	}
};

ChartDemo *bubbleSortChart[] = {
		new BubbleSort(),
};
int bubbleSortChartCount = WXSIZEOF(bubbleSortChart);

