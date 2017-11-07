package br.ufba.mata52.prova2.q2;

public class MultiplicacaoKaratsuba extends Operacao {
	
	private String numero1, numero2;
	
	public MultiplicacaoKaratsuba(String n1, String n2) {
		super(n1, n2);
		numero1 = n1;
		numero2 = n2;
	}

	@Override
	public String calcular() {
		zerarContador();
		return karatsubasa(numero1, numero2);
	}
	
	private int charToInt(char c) {
		if((int)c > 57 || (int)c < 48) {
			return -1;
		} else {
			return (int)c - 48; 
		}
	}
	
	private String subtract(String num1, String num2) {
		String filtrado = filter(num1, num2);
		num1 = filtrado.substring(0, filtrado.length() / 2);
		num2 = filtrado.substring(filtrado.length() / 2);
		
		if(num1.compareTo(num2) < 0) {
			return "-" + subtract(num2, num1);
		}
		
		String r = "";
		int v = 0, n1 = 0, n2 = 0;
		for(int i = num1.length() - 1; i >= 0; i--) {
			n1 = charToInt(num1.charAt(i));
			n2 = charToInt(num2.charAt(i));
			if(n1 - v < n2) {
				n1 += 10 - v;
				v = 1;
			} else {
				n1 -= v;
				v = 0;
			}
			r = (n1 - n2) + r;
		}
		
		int i = 0;
		for (i = 0 ; i < r.length() ; i++) {
			if(r.charAt(i) != '0')
				break;
		}
		
		r = r.substring(i);
		
		if(r.isEmpty())
			return "0";
		
		return r;
	}
	
	private String sum(String num1, String num2) {
		String filtrado = filter(num1, num2);
		num1 = filtrado.substring(0, filtrado.length() / 2);
		num2 = filtrado.substring(filtrado.length() / 2);
		
		String r = "";
		int s = 0, v = 0, n1 = 0, n2 = 0;
		for(int i = num1.length() - 1; i >= 0; i--) {
			n1 = charToInt(num1.charAt(i));
			n2 = charToInt(num2.charAt(i));
			
			s = (n1 + n2 + v);
			
			if(s >= 10){
				v = s / 10;
				s = s % 10;
			} else {
				v = 0;
			}
			r = s + r;
		}
		if(v > 0){
			r = (v) + r;
		}
		
		return r;
	}
	
	private String padLeft(String in, int pad) {
		int size = in.length() + pad;
		while(in.length() < size) {
			in = "0" + in;
		}
		return in;
	}
	
	private String padRight(String in, int pad) {
		int size = in.length() + pad;
		while(in.length() < size) {
			in = in + "0";
		}
		return in;
	}
	
	private String filter(String numero1, String numero2) {
		int i;
		
		if(numero1.length() < numero2.length()) {
			numero1 = padLeft(numero1, numero2.length() - numero1.length());
		}
		if(numero1.length() > numero2.length()){
			numero2 = padLeft(numero2, numero1.length() - numero2.length());
		}
		
		for(i = 0; i < numero1.length() ; i++) {
			if(numero1.charAt(i) != '0' || numero2.charAt(i) != '0') {
				break;
			} 
		}
		
		String r = numero1.substring(i) + numero2.substring(i);
		
		if(r.isEmpty())
			return "00";
	
		return r;
	}
	
	private String karatsubasa(String numero1, String numero2) {
		
		String filtrado = filter(numero1, numero2);
		numero1 = filtrado.substring(0, filtrado.length() / 2);
		numero2 = filtrado.substring(filtrado.length() / 2);
		
		if(numero1.length() <= 4 || numero2.length() <= 4) {
			MultiplicacaoConvencional mc = new MultiplicacaoConvencional(numero1, numero2);
			String r = mc.calcular();
			addSomador(mc.getContador());
			return r;
		} else {
			contar();
			int len = Math.max(
					numero1.replaceAll("\\^(0*)", "").length(), 
					numero2.replaceAll("\\^(0*)", "").length()
			);
			int half = len - (len / 2);
//			int half = (len / 2);
			String a = karatsubasa(numero1.substring(0, half), numero2.substring(0, half));
			String b = karatsubasa(numero1.substring(half), numero2.substring(half));
			String tca = sum(numero1.substring(0, half), numero1.substring(half));
			String tcb = sum(numero2.substring(0, half), numero2.substring(half));
			String c = karatsubasa(
						tca, 
						tcb
					);
			String k = subtract(subtract(c, a), b);
//			System.out.println("a padleft: " + padRight(a, 2*half));
//			System.out.println("k padleft: " + padRight(k, half));
			//String r = sum(sum(padRight(a, 2*half), padRight(k, half)), b);
			String r = sum(sum(padRight(a, 2*(len - half)), padRight(k, len - half)), b);
			
			System.out.println("n1: " + numero1 + "; n2: " + numero2);
			System.out.println("p1: " + numero1.substring(0, half));
			System.out.println("p2: " + numero1.substring(half));
			System.out.println("half: " + half);
			System.out.println("a: " + a);
			System.out.println("b: " + b);
			System.out.println("tca: " + tca);
			System.out.println("tcb: " + tcb);
			System.out.println("c: " + c);
			System.out.println("k: " + k);
			System.out.println("R: " + r);
			System.out.println("---------------------");
			
			return r;
		}
	}
}
