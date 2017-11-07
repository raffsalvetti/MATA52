package br.ufba.mata52.prova2.q1;

public class FuncaoMonotonicaDecrescente {
	private F f;

	public FuncaoMonotonicaDecrescente(F f) {
		this.f = f;
	}

	public int primeiroNegativo() {
		if(f.calcular(0) <= 0)
			return 0;

		int i = 1;
		while (f.calcular(i) >= 0) {
			i *= 2;
		}

		System.out.println("menor valor: " + i);
		
		return buscaBinaria(i/2, i);
	}

	private int buscaBinaria(int a, int b) {
		if (b >= a) {
			int m = a + (b - a) / 2;

			if (f.calcular(m) <= 0 && f.calcular(m - 1) > 0) {
				return m;
			}

			if (f.calcular(m) <= 0) {
				return buscaBinaria(a, (m - 1));
			} else {
				return buscaBinaria((m + 1), b);
			}
		}
		return -666;
	}
}
