package br.ufba.mata52.prova2;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.math.BigInteger;
import java.util.Random;

import javax.swing.JFrame;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

import br.ufba.mata52.prova2.q2.MultiplicacaoConvencional;
import br.ufba.mata52.prova2.q2.MultiplicacaoKaratsuba;

public class Prova2MainQ2 extends JFrame {

	private static final long serialVersionUID = -5459584443349001337L;
	
	public Prova2MainQ2() {
//		MultiplicacaoConvencional mc;
//		Random r = new Random(System.currentTimeMillis());
//		int numero;
//		String myRes, res, strNum;
//		for(int i = 0 ; i < 200 ; i++) {
//			numero = r.nextInt();
//			if(numero < 0)
//				numero *= -1;
//			strNum = String.valueOf(numero); //testes para numeros menores
//			strNum = String.valueOf(new String(new char[(i + 1) + 10]).replace('\0', '9')); //testes para numeros maiores
//			mc = new MultiplicacaoConvencional(strNum, strNum);
//			myRes = mc.calcular();
//			res = new BigInteger(strNum).multiply(new BigInteger(strNum)).toString();
//			while(myRes.length() > res.length()) {
//				res = "0" + res;
//			}
//			if(myRes.equals(res)) {
//				System.out.println(strNum + " * " + strNum + " = " + myRes + " (" + res + ")");
//			} else {
//				System.out.println(myRes + " != " + res);
//				break;
//			}
//		}
		
//		TESTE KARATSUBA
//		MultiplicacaoKaratsuba mk = new MultiplicacaoKaratsuba("99999", "99999");
//		System.out.println(mk.calcular());
		
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		getContentPane().setLayout(new BorderLayout(0, 0));
		setMinimumSize(new Dimension(800, 480));
		setPreferredSize(new Dimension(800, 480));
		Toolkit t = Toolkit.getDefaultToolkit();
		setLocation((t.getScreenSize().width / 2) - (getSize().width / 2), (t.getScreenSize().height / 2) - (getSize().height / 2));

		XYSeries dadosGraficoMultiplicacaoConvencional = new XYSeries("Multiplicação Convencional");
		XYSeries dadosGraficoMultiplicacaoKaratsuba = new XYSeries("Multiplicação de Karatsuba");
		
		String numero;
		int n = 0;
		for(int i = 1 ; i <= 20 ; i++) {
			n = i * 10;
			numero = new String(new char[n]).replace('\0', '9');
			MultiplicacaoConvencional mc = new MultiplicacaoConvencional(numero, numero);
			mc.calcular();
			MultiplicacaoKaratsuba mk = new MultiplicacaoKaratsuba(numero, numero);
			mk.calcular();
			dadosGraficoMultiplicacaoConvencional.add(n, mc.getContador());
			dadosGraficoMultiplicacaoKaratsuba.add(n, mk.getContador());
		}

		XYSeriesCollection dataset = new XYSeriesCollection();
		dataset.addSeries(dadosGraficoMultiplicacaoConvencional);
		dataset.addSeries(dadosGraficoMultiplicacaoKaratsuba);
		JFreeChart chart = ChartFactory.createXYLineChart("Algoritmos de Multiplicação", "Qtd. Elementos no Array", "Passos", dataset);
		ChartPanel chartPanel = new ChartPanel(chart);
		
		getContentPane().add(chartPanel, BorderLayout.CENTER);
		
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new Prova2MainQ2();
	}

}
