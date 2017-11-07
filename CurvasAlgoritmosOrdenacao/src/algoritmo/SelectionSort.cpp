/*
 * SelectionSort.cpp
 *
 *  Created on: 15/08/2016
 *      Author: raffaello.salvetti
 */

#include "Algoritmo.h"

class SelectionSort : public Algoritmo {

public: SelectionSort() : Algoritmo(wxT("SelectionSort Sort")) { }
public:
	virtual void ordenar(int* x, int size) {
		int i, j, min, aux;
		zerarContador();
		marcarHoraInicio();
		for (i = 0; i < (size - 1); i++) {
			contar();
			min = i;
			for (j = (i+1); j < size; j++) {
				contar();
				if(*(x + j) < *(x + min))
					min = j;
			}
			if (i != min) {
				aux = *(x + i);
				*(x + i) = *(x + min);
				*(x + min) = aux;
			}
		}
		marcarHoraFim();
	}
};

ChartDemo *selectionSortChart[] = {
		new SelectionSort(),
};
int selectionSortChartCount = WXSIZEOF(selectionSortChart);


