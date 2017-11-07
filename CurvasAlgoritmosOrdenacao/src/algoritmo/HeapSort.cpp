/*
 * HeapSort.cpp
 *
 *  Created on: 15/08/2016
 *      Author: raffaello.salvetti
 */

#include "Algoritmo.h"

class HeapSort : public Algoritmo {

public: HeapSort() : Algoritmo(wxT("Heap Sort")) { }
public:
	virtual void ordenar(int* x, int size) {
		int i = size / 2, pai, filho, t;
		marcarHoraInicio();
		for (;;) {
			contar();
			if (i > 0) {
				i--;
				t = *(x + i);
			} else {
				size--;
				if (size == 0) return;
				t = *(x + size);
				*(x + size) = *x;
			}
			pai = i;
			filho = i * 2 + 1;
			while (filho < size) {
				contar();
				if ((filho + 1 < size)  &&  (*(x + filho + 1) > *(x + filho)))
					filho++;
				if (*(x + filho) > t) {
					*(x + pai) = *(x + filho);
					pai = filho;
					filho = pai * 2 + 1;
				} else {
					break;
				}
			}
			*(x + pai) = t;
		}
		marcarHoraFim();
	}
};

ChartDemo *heapSortChart[] = {
		new HeapSort(),
};
int heapSortChartCount = WXSIZEOF(heapSortChart);


