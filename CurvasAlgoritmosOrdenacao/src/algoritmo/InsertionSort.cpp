#include "Algoritmo.h"

class InsertionSort : public Algoritmo {

public: InsertionSort() : Algoritmo(wxT("Insertion Sort")) { }
public:
	virtual void ordenar(int* x, int size) {
		int i, j, v;
		zerarContador();
		marcarHoraInicio();
		for (j = 1; j < size; j++) {
			v = *(x + j);
			i = j - 1;
			contar();
			while (i >= 0 && *(x + i) > v) {
				*(x + i + 1) = *(x + i);
				i = i - 1;
				contar();
			}
			*(x + i + 1) = v;
		}
		marcarHoraFim();
	}
};

ChartDemo *insertionSortChart[] = {
		new InsertionSort(),
};
int insertionSortChartCount = WXSIZEOF(insertionSortChart);
