/*
 * MergeSort.cpp
 *
 *  Created on: 15/08/2016
 *      Author: raffaello.salvetti
 */

#include "Algoritmo.h"

class MergeSort : public Algoritmo {

public: MergeSort() : Algoritmo(wxT("Merge Sort")) { }
public:
	virtual void ordenar(int* x, int size) {
		zerarContador();
		marcarHoraInicio();
		mergeSort(x, 0, size - 1);
		marcarHoraFim();
	}

	void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
	    int i, j, k, metadeTamanho, *vetorTemp;

	    if(posicaoInicio == posicaoFim) return;

	    contar();//contagem recursiva
	    // ordenacao recursiva das duas metades
	    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
	    mergeSort(vetor, posicaoInicio, metadeTamanho);
	    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

	    // intercalacao no vetor temporario t
	    i = posicaoInicio;
	    j = metadeTamanho + 1;
	    k = 0;
	    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

	    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
	    	contar();
	        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
	            *(vetorTemp + k) = *(vetor + j);
	            j++;
	            k++;
	        } else {
	            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
	                *(vetorTemp + k) = *(vetor + i);
	                i++;
	                k++;
	            } else {
	                if (*(vetor + i) < *(vetor + j)) {
	                    *(vetorTemp + k) = *(vetor + i);
	                    i++;
	                    k++;
	                } else {
	                    *(vetorTemp + k) = *(vetor + j);
	                    j++;
	                    k++;
	                }
	            }
	        }
	    }
	    // copia vetor intercalado para o vetor original
	    for(i = posicaoInicio; i <= posicaoFim; i++) {
	    	contar();
	        *(vetor + i) = *(vetorTemp + (i - posicaoInicio));
	    }
	    free(vetorTemp);
	}
};

ChartDemo *mergeSortChart[] = {
		new MergeSort(),
};
int mergeSortChartCount = WXSIZEOF(mergeSortChart);


