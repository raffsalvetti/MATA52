package br.ufba.mata52.prova2.q2;

public abstract class Operacao {
	protected int[][] matrizSoma;
	protected int[] resultadoSoma;
	
	protected int[] n1, n2;
	
	private long contador;
	
	public Operacao(String n1, String n2) {
		
		while(n1.length() > n2.length()) {
			n2 = "0" + n2;
		}
		
		while(n2.length() > n1.length()) {
			n1 = "0" + n1;
		}
		
		matrizSoma = new int[n1.length()][n1.length() + n2.length()];
		resultadoSoma = new int[n1.length() + n2.length()];
		this.n1 = new int[n1.length()];
		this.n2 = new int[n2.length()];
		for (int i = 0 ; i < n1.length() ; i++) {
			this.n1[i] = Integer.parseInt(String.valueOf(n1.charAt(i)));
		}
		for (int i = 0 ; i < n2.length() ; i++) {
			this.n2[i] = Integer.parseInt(String.valueOf(n2.charAt(i)));
		}
	}
	
	protected void zerarContador() {
		contador = 0;
	}
	
	protected void contar() {
		contador++;
	}
	
	protected void addSomador(long valor) {
		contador += valor;
	}
	
	public long getContador(){
		return contador;
	}
	
	public abstract String calcular();
}
