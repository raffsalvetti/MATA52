#include "Algoritmo.h"

class QuickSort : public Algoritmo {

public: QuickSort() : Algoritmo(wxT("QuickSort Sort")) { }
public:
	virtual void ordenar(int* x, int size) {
		zerarContador();
		marcarHoraInicio();
		quickSort(x, 0, size - 1);
		marcarHoraFim();
	}

	void quickSort(int *arr, int left, int right) {
		int i = left, j = right;
		int tmp;
		int pivot = *(arr + ((left + right) / 2));
		contar(); //contador para a recursao
		while (i <= j) {
			contar();
			while (*(arr + i) < pivot) {
				contar();
				i++;
			}
			while (*(arr + j) > pivot) {
				contar();
				j--;
			}
			if (i <= j) {
				  tmp = *(arr + i);
				  *(arr + i) = *(arr + j);
				  *(arr + j) = tmp;
				  i++;
				  j--;
			}
		}

		if (left < j)
			quickSort(arr, left, j);
		if (i < right)
				quickSort(arr, i, right);
	}
};

ChartDemo *quickSortChart[] = {
		new QuickSort(),
};
int quickSortChartCount = WXSIZEOF(quickSortChart);
