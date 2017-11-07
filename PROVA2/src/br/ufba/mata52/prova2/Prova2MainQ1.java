package br.ufba.mata52.prova2;

import br.ufba.mata52.prova2.q1.F;
import br.ufba.mata52.prova2.q1.FuncaoMonotonicaDecrescente;

public class Prova2MainQ1 {

	public Prova2MainQ1() {
		FuncaoMonotonicaDecrescente fd = new FuncaoMonotonicaDecrescente(new F() {
			@Override
			public int calcular(int i) {
				int valor = (int)(-Math.exp(i-1) + 30);
				//int valor = (int)(-i + 30);
				return valor;
			}
		});
		System.out.println("O primeiro numero que torna a funcao negativa é : " + fd.primeiroNegativo());
	}
	
	public static void main(String[] args) {
		new Prova2MainQ1();
	}

}
