package br.ufba.mata52.prova2.q2;

public class MultiplicacaoConvencional extends Operacao {
	
	public MultiplicacaoConvencional(String n1, String n2) {
		super(n1, n2);
	}
	
	public String calcular() {
		zerarContador();
		int i, j, v = 0;
		for(i = n1.length - 1; i >=0 ; i--) {
			v = 0;
			for(j = n2.length - 1; j >=0 ; j--) {
				contar();
				resultadoSoma[i + j + 1] += n1[j] * n2[i] + v;
				if(resultadoSoma[i + j + 1] >= 10) {
					v = resultadoSoma[i + j + 1] / 10;
					resultadoSoma[i + j + 1] %= 10;
				} else {
					v = 0;
				}
			}
			if(v != 0) {
				resultadoSoma[i + j + 1] = v;
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int k : resultadoSoma) {
			sb.append(k);
		}
		return sb.toString();
	}

	public int[][] getMatrizSoma() {
		return matrizSoma;
	}

	public int[] getResultadoSoma() {
		return resultadoSoma;
	}
}
